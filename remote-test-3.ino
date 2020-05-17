#include <IRremote.h>
#include <Servo.h>
int IRpin = 2;  // pin for the IR sensor
IRrecv irrecv(IRpin);
decode_results results;
Servo armservo;
Servo clawservo;

void setup(){
 Serial.begin(9600);
 irrecv.enableIRIn(); // Start the receiver
 armservo.attach(9); //Servo assigned to control the arm height
 clawservo.attach(10);// Servo assigned to control the claw
}
void loop() 
{
 if (irrecv.decode(&results)) 
   {
     irrecv.resume();   // Receive the next value
   }
  if (results.value == 16738455)  // Arm control down
    {
      armservo.write(5);
      delay(100);
    }
    if (results.value == 16756815)  // Arm control up
    {
      armservo.write(80);
    delay(100);
    }
     if (results.value == 16720605)  // Claw open
    {
      clawservo.write(90);
    delay(100);
    }
     if (results.value == 16761405)  // Claw close
    {
      clawservo.write(0);
    delay(100);
    }
    
}     
        
