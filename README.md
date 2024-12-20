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
![Circuit Diagram](https://github.com/user-attachments/assets/059a2ed4-4d6d-4df2-9a4b-67c9986eaf9d)
