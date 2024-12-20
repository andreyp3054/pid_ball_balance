#include <Arduino.h>
#include <Servo.h>
#include <PID_v1.h> // Include the PID library

#define trigPin 4    // Trigger pin for ultrasonic sensor
#define echoPin 6    // Echo pin for ultrasonic sensor
#define servoPin 5   // Servo pin

Servo myServo;  // Create a Servo object

// PID variables
double setPoint = 17.0; // Desired distance in cm
double input;           // Current distance from the sensor
double output;          // PID output for the servo


// PID constants 
double kp = 15.0; //15.0
double ki = 0.2;  //0.2
double kd = 5;  //5
double alpha = 0.9;

// Create the PID object
PID myPID(&input, &output, &setPoint, kp, ki, kd, DIRECT);

// Function declaration
long getDistance();

float exponentialFilter(float newValue, float previousValue, float alpha) {
  return alpha * newValue + (1 - alpha) * previousValue;
}

void setup() {
  pinMode(trigPin, OUTPUT);  // Set the trigger pin as output
  pinMode(echoPin, INPUT);   // Set the echo pin as input
  myServo.attach(servoPin);  // Attach the servo to the pin
  Serial.begin(9600);        // Start serial communication at 9600 baud rate

  // Initialize the PID controller
  myPID.SetMode(AUTOMATIC); // Set the PID controller to automatic mode
  myPID.SetOutputLimits(-255, 255); // Limit output to servo range (0-180 degrees)
}

void loop() {
  // input = getDistance(); // Get the distance from the sensor
  input = exponentialFilter(getDistance(), input, alpha );

  Serial.print("Distance: ");
  Serial.print(input);   // Print the distance in cm
  Serial.print(" cm");

  // Compute the PID output
  myPID.Compute();
  double angle = map(output, -255, 255, 0, 180);
  // Write the PID output to the servo
  myServo.write(angle);

  // Print the PID output for debugging
  Serial.print(" | Servo Position: ");
  Serial.print(angle);
  Serial.print(" pid: ");
  Serial.println(output);
  delay(10); // Small delay before the next loop iteration orig: 50
}

// Function to get the distance from the ultrasonic sensor
long getDistance() {
  digitalWrite(trigPin, LOW);  // Clear the trigger pin
  delayMicroseconds(2);        // Wait for a short time

  digitalWrite(trigPin, HIGH); // Send the trigger pulse
  delayMicroseconds(10);       // 10-microsecond pulse
  digitalWrite(trigPin, LOW);  // Stop sending the trigger pulse

  long duration = pulseIn(echoPin, HIGH);  // Measure the pulse duration

  // Calculate the distance in cm
  long distance = (duration / 2) / 29.1;

  // Return the calculated distance
  return distance;
}

