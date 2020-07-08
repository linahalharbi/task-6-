#include <Servo.h>
Servo myservo;

const int FSR = A0;// Pin A0 to read analog FORCE/ PRESSUE input 
int x;
int y;

//Variables:
int pressure;                     //To store analog value
void setup(){

  Serial.begin(9600);       // Begin serial communication
  myservo.attach(9);          // ALL the servo attach to D9
 

  delay(1000);
}
void loop(){
  pressure = analogRead(FSR);         //Read and store analog value from Force Sensitive Resistance
  Serial.println(pressure);                 //Print value
  pressure = map(FSR, x, y, 0, 1);//Map value to 0,1 (1-180)  
 if (pressure==0); //if the value is 0
{ 
  myservo.write(0); //turn the servo to 0º
  delay(100);
} if  (pressure ==1); // if the value is 1
{
  myservo.write(180); //turn the servo to 180º
 delay(100);
}  { 
  myservo.write(90); // if either 0 or 1 turn the servo to 90º
  delay(100);
  }
}