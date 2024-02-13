#include <AccelStepper.h>

const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

int y=0, x=0;
int j;

AccelStepper stepper2(AccelStepper::FULL4WIRE, 4,6,7,5);
AccelStepper stepper1(AccelStepper::FULL4WIRE, 11,9,8,10);

void setup()
{  
    stepper1.setMaxSpeed(1000.0);
    stepper1.setAcceleration(200.0);
    //stepper1.moveTo(j);
    
    
    stepper2.setMaxSpeed(1000.0);
    stepper2.setAcceleration(200.0);
    //stepper2.moveTo(j);
    

}
void loop()
{
    y = analogRead(X_pin);
    x = analogRead(Y_pin);
    Serial.print("X: ");
    Serial.println(x);
    Serial.print("Y: ");
    Serial.println(y);
    Serial.println();
    //delay(50);
j=650;

if(y>1020){
    stepper2.setSpeed(j);
    stepper1.setSpeed(-j); 
    stepper1.runSpeed();
    stepper2.runSpeed();
      }
        //When Joystick pushed up, move forward in j increments
      

    if(y<3){
    stepper2.setSpeed(-j);
    stepper1.setSpeed(j); 
    stepper1.runSpeed();
    stepper2.runSpeed();
        //When Joystick pushed down, move backwards in j increments
      }
    
    if(y>4){
        if(y<1019){
        Serial.print("Dont move hoe");
        Serial.println();
         //delay(50);
         //Dead Band -- When Joystick resting, do not move 
      }
    }

if(x>1020){
    stepper2.setSpeed(-j);
    stepper1.setSpeed(-j); 
    stepper1.runSpeed();
    stepper2.runSpeed();
      }
        //When Joystick pushed up, move forward in j increments
      

    if(x<3){
    stepper2.setSpeed(j);
    stepper1.setSpeed(j); 
    stepper1.runSpeed();
    stepper2.runSpeed();
        //When Joystick pushed down, move backwards in j increments
      }
    
    if(x>4){
        if(x<1019){
        Serial.print("Dont move hoe");
        Serial.println();
         //delay(50);
         //Dead Band -- When Joystick resting, do not move 
      }
    }
}
