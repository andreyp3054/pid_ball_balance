##Acebu-Pacaña Ball-Balancing Robot with integrated PID Controller



How it works: 
1. Distance Measurement: The ultrasonic sensor continuously measures the distance between the ball and the sensor. The sensor sends a pulse, and by calculating the time it takes for the pulse to return, it determines the distance to the ball.

2. Target Distance: The system is set with a target distance, say 17 cm. This is the distance at which the robot aims to maintain the ball's position.

3. PID Control: A PID (Proportional-Integral-Derivative) controller is used to adjust the servo's position based on the measured distance. The error is calculated as the difference between the target distance (17 cm) and the actual distance measured by the ultrasonic sensor.

4. Servo Adjustment: The PID controller adjusts the servo motor's angle based on the error. If the distance is greater than 17 cm, the servo moves to tilt the robot and push the ball back; if the distance is smaller, the servo tilts the robot forward to adjust the position of the ball.

5. Maintaining Balance: The servo continuously adjusts to maintain the ball at the desired 17 cm distance. The PID controller fine-tunes the servo's position, ensuring the robot compensates for any changes in the ball's position and maintains the balance.

6. Stabilization: The process runs in a loop, continuously measuring the distance, adjusting the servo, and keeping the ball stable at the set distance.


![circuit_diagram](https://github.com/user-attachments/assets/059a2ed4-4d6d-4df2-9a4b-67c9986eaf9d)
