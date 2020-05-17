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
 armservo.attach(9);
 clawservo.attach(10);// attaches the servo on pin 9 to the servo object
}
void loop() 
{
 if (irrecv.decode(&results)) 
   {
     irrecv.resume();   // Receive the next value
   }
  if (results.value == 16738455)  // change according to your IR remote button number
    {
      armservo.write(5);
      delay(100);
    }
    if (results.value == 16756815)  // change according  to your IR remote button number
    {
      armservo.write(80);
    delay(100);
    }
     if (results.value == 16720605)  // change according  to your IR remote button number
    {
      clawservo.write(90);
    delay(100);
    }
     if (results.value == 16761405)  // change according  to your IR remote button number
    {
      clawservo.write(0);
    delay(100);
    }
    
}     
        
