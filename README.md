# **Acebu-Pacaña Ball-Balancing Robot with Integrated PID Controller**

---

### **Materials Used**
- **Ultrasonic Sensor**
- **Micro Servo Motor**
- **Breadboard**
- **Arduino Uno R3**
- **Ping Pong Ball**
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


