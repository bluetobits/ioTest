# Simple Arduino Test Sketch

### Steve Lomax November 2025/

## Hardware required:

LED with a 200R resistor across and a 200R in series with the anode with 2 flying leads Cathode and Anode series resistor  with dupont connectors (female for Nano male for Uno or adaptor)

## Instructions 

1. Connect the arduino to the IDE and open the serial monitor and follow the screen prompts  
2. Enter 1 into the serial monitor  to test each GPIO (except 13 \- the onboard LED and 20 and 21 \- the analog input A6 and A7 \- not available on a Uno).  
3. Connect the cathode to GND pin and the anode via the 200r resistor to each pin 2-19 (not 13\) in turn  
4. The sketch will read the pin and display the pin number then light the LED.   
5. PWM pins will fade up the LED.  hot swap the anode and Test all pins to ensure all are working as both inputs and outputs  
6. Enter 2 into the serial monitor the values for A6 and A7 will scroll Connecting the anode will cause the pin A6 or A7 to read 0  
7. Enter 3 into the serial monitor.The onboard LED will flash  
8. Pressing 1,2,or 3 at any time will change the test mode

