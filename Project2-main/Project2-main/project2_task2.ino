#include <AccelStepper.h>
#include <MultiStepper.h>

MultiStepper steppers;
int a = 0, b= 0;

float c;

int turning=0;

const int ping=13;
const int echo=12;

int y=0, x=0;
int j;

AccelStepper stepper2(AccelStepper::FULL4WIRE, 4,6,7,5);
AccelStepper stepper1(AccelStepper::FULL4WIRE, 11,9,8,10);

void setup()
{  
  c=500.0;
    stepper1.setMaxSpeed(c);
    stepper1.setSpeed(c);
    stepper1.setAcceleration(100.0);
    //stepper1.moveTo(j);
    
    
    stepper2.setMaxSpeed(c);
    stepper2.setSpeed(c);
    stepper2.setAcceleration(100.0);
    //stepper2.moveTo(j);
    
    pinMode(ping, OUTPUT);   
    pinMode(echo, INPUT);
    
    steppers.addStepper(stepper1);
    steppers.addStepper(stepper2);
    
    Serial.begin(9600);
}
void loop()
{

    long duration, cm, positions[2];

    digitalWrite(ping, LOW);
    delayMicroseconds(2);
   
    digitalWrite(ping, HIGH);
    delayMicroseconds(10);
    digitalWrite(ping, LOW);
      
    duration = pulseIn(echo, HIGH);
   
    cm = duration*(0.034/2);
    Serial.println(cm);
    

    j=300;


        stepper1.setCurrentPosition(0);
        stepper2.setCurrentPosition(0);
        
    if(cm>=10){
      Serial.print("moving");
      Serial.println();

        stepper1.setCurrentPosition(0);
        stepper2.setCurrentPosition(0);
        a=350;
        b=-350;
        positions[0] = a;
        positions[1] = -a;

        
        steppers.moveTo(positions);
        steppers.runSpeedToPosition(); // Blocks until all are in position
        
    }
    
        if(cm<=9){
            turning++;
            
            stepper1.setCurrentPosition(0);
            stepper2.setCurrentPosition(0);
            
            if(turning == 1){
            a=1300;
            }
            
            if(turning == 2){
            a=-1300;
            }
            
            if(turning == 3){
            while(1){
              
            }
            }
            
            positions[0] = a;
            positions[1] = a;
            steppers.moveTo(positions);
            steppers.runSpeedToPosition(); // Blocks until all are in position
            
          
        

        }
          
        
}




            
