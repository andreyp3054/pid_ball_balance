# **Acebu-Pacaña Ball-Balancing Robot with Integrated PID Controller**

---

### **Materials Used**
- **Ultrasonic Sensor**
- **Micro Servo Motor**
- **Breadboard**
- **Arduino Uno R3**
- **Ping Pong Ball**
- **Iron Sticks**
- **Sintra Board** (as the building platform)

---

### **About the Project**
A ball balancing system uses a sintra board controlled by a servo motor. An ultrasonic sensor measures the ball's distance, which is compared to a preset distance setpoint. The PID controller processes any difference between these values and adjusts the servo motor angle. This tilts the sintra board to maintain the ball at the desired position. The system continuously monitors and corrects the ball's position through this feedback loop.

---

### **Block Diagram**

![block_diagram](https://github.com/user-attachments/assets/9229a620-1da9-4bc3-a9f6-65543e404f2f)

### **How It Works**

1. **Distance Measurement**  
   The ultrasonic sensor continuously measures the distance between the ball and the sensor. The sensor emits a pulse, and by calculating the time it takes for the pulse to return, it determines the distance to the ball.

2. **Target Distance**  
   The system is set with a target distance, such as **17 cm**, which is the desired position to maintain the ball.

3. **PID Control**  
   A **PID (Proportional-Integral-Derivative)** controller adjusts the servo motor's position based on the error, calculated as the difference between the target distance (**17 cm**) and the actual distance measured by the ultrasonic sensor.

4. **Servo Adjustment**  
   The PID controller moves the servo motor based on the error:  
   - **If the distance is greater than 17 cm**, the servo tilts the platform to push the ball backward.  
   - **If the distance is less than 17 cm**, the servo tilts the platform forward to adjust the ball's position.

5. **Maintaining Balance**  

   The servo continuously adjusts to maintain the ball at the desired **17 cm** distance. The PID controller ensures precise adjustments, compensating for deviations to keep the ball stable.

6. **Stabilization**  
   This process runs in a continuous loop, constantly:  
   - Measuring the distance.  
   - Adjusting the servo position.  
   - Ensuring the ball remains balanced at the set point.

---

### **Circuit Diagram**

![circuit_diagram_2](https://github.com/user-attachments/assets/0777978c-af41-495d-ba10-c73f7e45e545)

### **Operation**

The ball-balancing system uses a feedback control loop with an ultrasonic sensor, a PID controller, and a servo motor to maintain the ball at a target distance (e.g., 17 cm) on a tiltable platform.

Distance Measurement with Exponential Filter

The ultrasonic sensor measures the distance to the ball by emitting sound pulses and calculating the time for their return.
To smooth out noisy readings, an exponential filter is applied using the following formula:

![filter formula](https://github.com/user-attachments/assets/c3eb3487-1ba1-4213-a7dc-90a49cb9697f)

Here, New Distance is the latest measurement from the sensor, Previous Filtered Distance is the previous filtered value, and α (alpha) is the smoothing factor (between 0 and 1). This formula blends the new reading with the previous one, resulting in a smoother and more stable distance measurement.
PID Controller and Ball Movement

The PID controller calculates the error as the difference between the target distance and the filtered distance:

Error=Target Distance−Filtered Distance
The controller uses three terms to calculate the necessary adjustment for the servo motor:
Proportional (P): The adjustment is proportional to the error. A larger error results in a bigger adjustment to move the platform and correct the ball's position.
Integral (I): The integral term accounts for accumulated past errors. It helps eliminate any persistent bias by adjusting for past deviations.
Derivative (D): The derivative term predicts future errors based on the current rate of change of the error, helping to apply smoother corrections and avoid overshooting.
The total adjustment from the PID controller is calculated as:

PID Output

![pid_formula](https://github.com/user-attachments/assets/f112a041-069e-4b20-b530-bd7226d6c8bd)
Kp, Ki, and Kd are the proportional, integral, and derivative constants, respectively, which determine the influence of each term on the output.
Servo Motor Adjustment

The servo motor tilts the platform to move the ball:
If the ball is too far from the target (> 17 cm): The PID controller commands the servo to tilt the platform backward to bring the ball closer.
If the ball is too close to the target (< 17 cm): The PID controller commands the servo to tilt the platform forward to move the ball back to the target position.
These adjustments ensure the ball stays at the target distance.
Continuous Stabilization

The system continuously loops through the process:
Measure the distance using the ultrasonic sensor.
Apply the exponential filter to smooth the reading.
Calculate the error using the target and filtered distance.
Compute the PID output to adjust the servo position.
The servo motor then moves the platform to balance the ball.
This dynamic feedback loop keeps the ball stable at the target position, continuously adjusting the platform based on real-time sensor readings and PID control.


