#include <Arduino.h>
#include <volt.h>
//download at https://github.com/mr-jaxstraww/volt-meter-arduino and copy to Arduino/libraries
/*	
	to convert 12v ~ 5v R1 = 13kOm R2 = 20kOm
	constant for arduino nano 
	KF 0.00488758553
	error 0.021
*/
float volt(float R1, float R2,voltPin){
  float KF = 0.00488758553;
  float error = 0.021;
  float vBat = analogRead(voltPin);
  float vEnd = KF*vBat - error;
  vEnd = vEnd*(R1 + R2) / R1;
	return vEnd;
}