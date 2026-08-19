#include "SoftPWM.h"
//#define 

/*D0 to D13 are native pwm channels
D0 and D1 should probably avoid if we want to have serial control with a computer during protocols
D44, D45, D46 are also PWM channels


REDS:
D2, D6, D10, D19, D22, 
D26, D30, D34, D38, D42 

GREENS:
D3, D7, D11, D18, D23,
D27, D31, D35, D39, D43

BLUES:
D4, D8, D12, D16, D24,
D28, D32, D36, D40, D44

Indicator RED:
D5, D9, D13, D17, D25,
D29, D33, D37, D41, D45
*/
//Hard PWM (triplets)
/*
2, 3, 4
6, 7, 8
10, 11, 12
X, X, 44
*/

//Soft PWM (triplets)
/*
19, 18, 16 
22, 23, 24
26, 27, 28
30, 31, 32
34, 35, 36
38, 39, 40
42, 43, //44 is hardPWM

sRED = [19, 22, 26, 30, 34, 38, 42];
sGREEN = [18, 23, 27, 31, 35, 39, 43];
sBLUE = [16, 24, 28, 32, 36, 40];
sIndicator = [17, 25, 29, 33, 37, 41];

hRED = [2, 6, 10];
hGREEN = [3, 7, 11];
hBLUE = [4, 8, 12, 44];
hIndicator = [5, 9, 13, 45];
*/
int allPinsSoft[] = {19, 22, 26, 30, 34, 38, 42, 
                 18, 23, 27, 31, 35, 39, 43,
                 16, 24, 28, 32, 36, 40
                 };// end all pins

int allPinsHard[] = {2,6,10,
                 3,7,11,
                 4,8,12,44
                 };//end all pins

int allPinsIndi[]={5,9,13,17,25, 29,33, 35, 37, 41, 45};

int nPinsIndi = sizeof(allPinsIndi) / sizeof(allPinsIndi[0]);
int nPinsSoft = sizeof(allPinsSoft) / sizeof(allPinsSoft[0]);
int nPinsHard = sizeof(allPinsHard) / sizeof(allPinsHard[0]);

int sRED[] = {19, 22, 26, 30, 34, 38, 42};
int sGREEN[] = {18, 23, 27, 31, 35, 39, 43};
int sBLUE[] = {16, 24, 28, 32, 36, 40};
//int sIndi[] = {17, 35, 29, 33, 37, 41};
int nPinssBLUE = sizeof(sBLUE) / sizeof(sBLUE[0]);


int hRED[] = {2,6,10};
int hGREEN[] = {3,7,11};
int hBLUE[] = {4,8,12,44};
//int hIndi[] = {5,9,13,45};
int nPinshBLUE = sizeof(hBLUE) / sizeof(hBLUE[0]);

void setup(){
  // Initialize
  SoftPWMBegin();
  //Serial.begin(9600);
  for (int i = 0; i < nPinsSoft; i++) {
    pinMode(allPinsSoft[i], OUTPUT);
  }//end for
  
  for (int i = 0; i < nPinsHard; i++) {
    //Serial.println(i);
    pinMode(allPinsHard[i], OUTPUT);
  }//end for

  for (int i = 0; i < nPinsIndi; i++) {
    //Serial.println(i);
    pinMode(allPinsIndi[i], OUTPUT);
  }//end for
  //set all softred to a channel and to 0
  for (int i=0;i<nPinsSoft;i++){
    SoftPWMSet(allPinsSoft[i], 0);
  }//end for

  //set all hardred to a channel and to 0
  for (int i=0;i<nPinsHard;i++){
    analogWrite(allPinsHard[i], 0);
  }//end for
    //set all hardred to a channel and to 0
  for (int i=0;i<nPinsIndi;i++){
    digitalWrite(allPinsIndi[i], 0);
  }//end for

}//end setup

void loop(){
  //Serial.println("loop");
    //set all softred to a channel and to 0
  for (int i=0;i<nPinsSoft;i++){
    SoftPWMSet(allPinsSoft[i], 0);
  }//end for

  //set all hard coded pins to a channel and to 0
  for (int i=0;i<nPinsHard;i++){
    analogWrite(allPinsHard[i], 0);
  }//end for
  for (int i=0;i<nPinsIndi;i++){
    digitalWrite(allPinsIndi[i], 0);
  }//end for
delay(100);
  //set all soft coded pins to a channel and to 0
  for (int i=0;i<nPinsSoft;i++){
    SoftPWMSet(allPinsSoft[i], 100);
  }//end for

  //set all hard blue 255
  for (int i=0;i<nPinshBLUE;i++){
    analogWrite(hBLUE[i], 255);
  }//end for

  for (int i=0;i<nPinsIndi;i++){
    digitalWrite(allPinsIndi[i], 1);
  }//end for
delay(500);

}//end loop

