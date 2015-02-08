#include <Servo.h>
#include <avr/pgmspace.h>
#include <Wire.h>
#include <SeeedOLED.h>


Servo servo_pin_2;
String inputString = "";
String commandString = "";
int hand_positionX=0;
int hand_positionY=0;
int hand_positionZ=0;
int handRotX=0;
int handRotY=0;
int handRotZ=0;
int angle_pouce=0;
int angle_index=0;
int angle_majeur=0;
int angle_annulaire=0;
int angle_auriculaire=0;
boolean stringComplete = false;



//***********************************************************************
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    
    // add it to the inputString:
    inputString += inChar;
    
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      
      //return;
    } 
  }
}



void setup(){
  Serial.begin(9600);
  servo_pin_2.attach(2);

  SeeedOled.brancher();
  SeeedOled.reglerLuminositeA(255);
  
}



//////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
   
  if (stringComplete) {
    
    inputString.trim();
    

    int index = inputString.indexOf("leapmotion");
    if(index!=0){
      return;
    }
    //leapmotion:400,000:300,000
    // On retire le motif "leapmotion:"
      int pos0 =inputString.indexOf(':');
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     hand_positionX=inputString.substring(0,pos0).toInt();    
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     hand_positionY=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     hand_positionZ=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     handRotX=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     handRotY=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     handRotZ=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     angle_pouce=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     angle_index=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     angle_majeur=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     angle_annulaire=inputString.substring(0,pos0).toInt();
     
     inputString=inputString.substring(pos0+1);
     pos0 = inputString.indexOf(':');
     angle_auriculaire=inputString.substring(0,pos0).toInt();
      
   SeeedOled.placerCurseurEn(0);
   SeeedOled.ecrire(angle_auriculaire );

    
      // clear the string:
    inputString = "";
    commandString = "";
    stringComplete = false;
  }
  
   
  
   
  
  servo_pin_2.write( map(handRotZ,0,1000,0,180) );
}
