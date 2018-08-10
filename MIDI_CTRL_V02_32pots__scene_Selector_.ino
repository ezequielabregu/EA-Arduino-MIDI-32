#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE ();  //creo la instancia
//////////////////////////////////////////////////////////


int r0 = 0;      
int r1 = 0;  // the four digital pins for the bits     
int r2 = 0;         
int r3 = 0; 
 
int  bin [] = {0, 1 ,2, 3, 4, 5, 6, 7, 8, 9,10,11,12, 13,14,15};//list of binary values

int ctrl0[ ] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};

int potValue0 = 0;
int potValue1 = 0;
int potValue2 = 0;
int potValue3 = 0;
int potValue4 = 0;
int potValue5 = 0;
int potValue6 = 0;
int potValue7 = 0;
int potValue8 = 0;
int potValue9 = 0;
int potValue10 = 0;
int potValue11 = 0;
int potValue12 = 0;
int potValue13 = 0;
int potValue14 = 0;
int potValue15 = 0;
int potValue16 = 0;
int potValue17 = 0;
int potValue18 = 0;
int potValue19 = 0;
int potValue20 = 0;
int potValue21 = 0;
int potValue22 = 0;
int potValue23 = 0;
int potValue24 = 0;
int potValue25 = 0;
int potValue26 = 0;
int potValue27 = 0;
int potValue28 = 0;
int potValue29 = 0;
int potValue30 = 0;
int potValue31 = 0;


int lastPotValue0 = 0;
int lastPotValue1 = 0;
int lastPotValue2 = 0;
int lastPotValue3 = 0;
int lastPotValue4 = 0;
int lastPotValue5 = 0;
int lastPotValue6 = 0;
int lastPotValue7 = 0;
int lastPotValue8 = 0;
int lastPotValue9 = 0;
int lastPotValue10 = 0;
int lastPotValue11 = 0;
int lastPotValue12 = 0;
int lastPotValue13 = 0;
int lastPotValue14 = 0;
int lastPotValue15 = 0;
int lastPotValue16 = 0;
int lastPotValue17 = 0;
int lastPotValue18 = 0;
int lastPotValue19 = 0;
int lastPotValue20 = 0;
int lastPotValue21 = 0;
int lastPotValue22 = 0;
int lastPotValue23 = 0;
int lastPotValue24 = 0;
int lastPotValue25 = 0;
int lastPotValue26 = 0;
int lastPotValue27 = 0;
int lastPotValue28 = 0;
int lastPotValue29 = 0;
int lastPotValue30 = 0;
int lastPotValue31 = 0;


int Threshlod = 7;


////SCENE SEL

#include <Bounce2.h>
//int color1[] = {0,50,50}; //violeta
//int color2[] = {50,50,0}; //aqua
//int color3[] = {255,0,0}; //

int color1[] = {0,25,25}; //violeta
int color2[] = {25,50,0}; //aqua
int color3[] = {125,0,0}; //


int val= 0;
int lastVal=0;
int scene = 0;
int sceneCC=0;

Bounce debouncer = Bounce();
 
void setup(){
  
  MIDI.begin(MIDI_CHANNEL_OMNI);
 
  pinMode(8, OUTPUT);    // r0
  pinMode(9, OUTPUT);    // r1
  pinMode(10, OUTPUT);    // r2
  pinMode(11, OUTPUT);    //r3
  
  Serial.begin(31250); // fire up the serial 


 //DEBOUNCE button & LED RGB
pinMode (3, OUTPUT);
pinMode (5, OUTPUT);
pinMode (7, OUTPUT);
pinMode (4, INPUT_PULLUP);

debouncer.attach (4);
debouncer.interval (10); 
}
 
  
void loop () {
   
 for (int count=0; count < 16; count++) { //loop through each channel, checking for a signal
    
   int row = bin[count]; //channel 5 = 5th element in the bin list -> 101 etc. 
    
   r0 = bitRead(row,0); //bitRead() -> parameter 1 = binary sequence, parameter 2 = which bit to read, starting from the right most bit
   r1 = bitRead(row,1); //channel 7 = 111, 1 = 2nd bit 
   r2 = bitRead(row,2); // third bit
   r3 = bitRead(row,3); // third bit
   
   digitalWrite(8, r0); // send the bits to the digital pins 
   digitalWrite(9, r1);
   digitalWrite(10, r2);
   digitalWrite(11, r3);

if (count == 0){
int potValue0 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue0  - lastPotValue0) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 0] + sceneCC, potValue0 / 8, 1);
      lastPotValue0 = potValue0; // queda el ultimo valor del pote.
      }
    }

if (count == 1){
int potValue1 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue1  - lastPotValue1) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 1]+ sceneCC, potValue1 / 8, 1);
      lastPotValue1 = potValue1; // queda el ultimo valor del pote.
      }
    }

if (count == 2){
int potValue2 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue2  - lastPotValue2) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 2]+ sceneCC, potValue2 / 8, 1);
      lastPotValue2 = potValue2; // queda el ultimo valor del pote.
      }
    }


if (count == 3){
int potValue3 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue3  - lastPotValue3) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 3]+ sceneCC, potValue3 / 8, 1);
      lastPotValue3 = potValue3; // queda el ultimo valor del pote.
      }
    }


if (count == 4){
int potValue4 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue4  - lastPotValue4) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[4]+ sceneCC, potValue4 / 8, 1);
      lastPotValue4 = potValue4; // queda el ultimo valor del pote.
      }
    }    


if (count == 5){
int potValue5 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue5  - lastPotValue5) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[5 ]+ sceneCC, potValue5 / 8, 1);
      lastPotValue5 = potValue5; // queda el ultimo valor del pote.
      }
    }


if (count == 6){
int potValue6 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue6  - lastPotValue6) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 6]+ sceneCC, potValue6 / 8, 1);
      lastPotValue6 = potValue6; // queda el ultimo valor del pote.
      }
    }


if (count == 7){
int potValue7 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue7  - lastPotValue7) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 7]+ sceneCC, potValue7 / 8, 1);
      lastPotValue7 = potValue7; // queda el ultimo valor del pote.
      }
    }


if (count == 8){
int potValue8 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue8  - lastPotValue8) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 8]+ sceneCC, potValue8 / 8, 1);
      lastPotValue8 = potValue8; // queda el ultimo valor del pote.
      }
    }


if (count == 9){
int potValue9 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue9  - lastPotValue9) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 9]+ sceneCC, potValue9 / 8, 1);
      lastPotValue9 = potValue9; // queda el ultimo valor del pote.
      }
    }


if (count == 10){
int potValue10 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue10  - lastPotValue10) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 10]+ sceneCC, potValue10 / 8, 1);
      lastPotValue10 = potValue10; // queda el ultimo valor del pote.
      }
    }


if (count == 11){
int potValue11 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue11  - lastPotValue11) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 11]+ sceneCC, potValue11 / 8, 1);
      lastPotValue11 = potValue11; // queda el ultimo valor del pote.
      }
    }


if (count == 12){
int potValue12 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue12  - lastPotValue12) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[12 ]+ sceneCC, potValue12 / 8, 1);
      lastPotValue12 = potValue12; // queda el ultimo valor del pote.
      }
    }


if (count == 13){
int potValue13 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue13  - lastPotValue13) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 13]+ sceneCC, potValue13 / 8, 1);
      lastPotValue13 = potValue13; // queda el ultimo valor del pote.
      }
    }


if (count == 14){
int potValue14 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue14  - lastPotValue14) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 14]+ sceneCC, potValue14 / 8, 1);
      lastPotValue14 = potValue14; // queda el ultimo valor del pote.
      }
    }


if (count == 15){
int potValue15 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue15  - lastPotValue15) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 15]+ sceneCC, potValue15 / 8, 1);
      lastPotValue15 = potValue15; // queda el ultimo valor del pote.
      }
    }

if (count == 0){
int potValue16 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue16  - lastPotValue16) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 16]+ sceneCC, potValue16 / 8, 1);
      lastPotValue16 = potValue16; // queda el ultimo valor del pote.
      }
    }

if (count == 1){
int potValue17 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue17  - lastPotValue17) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 17]+ sceneCC, potValue17 / 8, 1);
      lastPotValue17 = potValue17; // queda el ultimo valor del pote.
      }
    }

if (count == 2){
int potValue18 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue18  - lastPotValue18) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 18]+ sceneCC, potValue18 / 8, 1);
      lastPotValue18 = potValue18; // queda el ultimo valor del pote.
      }
    }


if (count == 3){
int potValue19 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue19  - lastPotValue19) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 19]+ sceneCC, potValue19 / 8, 1);
      lastPotValue19 = potValue19; // queda el ultimo valor del pote.
      }
    }


if (count == 4){
int potValue20 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue20  - lastPotValue20) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 20]+ sceneCC, potValue20 / 8, 1);
      lastPotValue20 = potValue20; // queda el ultimo valor del pote.
      }
    }    


if (count == 5){
int potValue21 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue21  - lastPotValue21) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 21]+ sceneCC, potValue21 / 8, 1);
      lastPotValue21 = potValue21; // queda el ultimo valor del pote.
      }
    }


if (count == 6){
int potValue22 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue22  - lastPotValue22) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 22]+ sceneCC, potValue22 / 8, 1);
      lastPotValue22 = potValue22; // queda el ultimo valor del pote.
      }
    }


if (count == 7){
int potValue23 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue23  - lastPotValue23) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 23]+ sceneCC, potValue23 / 8, 1);
      lastPotValue23 = potValue23; // queda el ultimo valor del pote.
      }
    }


if (count == 8){
int potValue24 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue24  - lastPotValue24) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 24]+ sceneCC, potValue24 / 8, 1);
      lastPotValue24 = potValue24; // queda el ultimo valor del pote.
      }
    }


if (count == 9){
int potValue25 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue25  - lastPotValue25) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 25]+ sceneCC, potValue25 / 8, 1);
      lastPotValue25 = potValue25; // queda el ultimo valor del pote.
      }
    }


if (count == 10){
int potValue26 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue26  - lastPotValue26) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 26]+ sceneCC, potValue26 / 8, 1);
      lastPotValue26 = potValue26; // queda el ultimo valor del pote.
      }
    }


if (count == 11){
int potValue27 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue27  - lastPotValue27) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 27]+ sceneCC, potValue27 / 8, 1);
      lastPotValue27 = potValue27; // queda el ultimo valor del pote.
      }
    }


if (count == 12){
int potValue28 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue28  - lastPotValue28) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 28]+ sceneCC, potValue28 / 8, 1);
      lastPotValue28 = potValue28; // queda el ultimo valor del pote.
      }
    }


if (count == 13){
int potValue29 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue29  - lastPotValue29) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 29]+ sceneCC, potValue29 / 8, 1);
      lastPotValue29 = potValue29; // queda el ultimo valor del pote.
      }
    }


if (count == 14){
int potValue30 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue30  - lastPotValue30) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 30]+ sceneCC, potValue30 / 8, 1);
      lastPotValue30 = potValue30; // queda el ultimo valor del pote.
      }
    }


if (count == 15){
int potValue31 = analogRead (1); //escaleo el rango 0-1023
    if (abs(potValue31  - lastPotValue31) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0[ 31]+ sceneCC, potValue31 / 8, 1);
      lastPotValue31 = potValue31; // queda el ultimo valor del pote.
      }
    }




 delay (1); // time to read the values

 //}


  debouncer.update();
  
int val = debouncer.read();


if (val != lastVal){
if (val == HIGH){    
   scene++;
 
   if (scene > 2){
    scene = 0; 
    }
  }
}
 
if (scene == 0){
sceneCC = 0;  
analogWrite (3, color1[2]); //VERDE
analogWrite (5,color1[1]); //AZUL
analogWrite (6, color1[0]);  // ROJO
}

else if (scene == 1){

sceneCC = 40;
analogWrite (3, color2[2]); //VERDE
analogWrite (5,color2[1]); //AZUL
analogWrite (6, color2[0]);  // ROJO
}

else if (scene == 2){
sceneCC = 80;  
analogWrite (3, color3[2]); //VERDE
analogWrite (5,color3[1]); //AZUL
analogWrite (6, color3[0]);  // ROJO
  }

 lastVal = val;
 
}
}
 
 
