
#include <Messenger.h>
#include <AnimatedLEDStrip.h>

Messenger input;

char c[50];

String str;

void messageReady() {

  if (input.checkString("S")) {
    if (input.checkString("COL1")) {          // S COL1 0x######\n
      staticColor1();
    } else if (input.checkString("COL2")) {   // S COL2 0x###### 0x######\n
      staticColor2();
    } else if (input.checkString("COL3")) {   // S COL3 0x###### 0x###### 0x######\n
      staticColor3();
    } else if (input.checkString("COL4")) {   // S COL4 0x###### 0x###### 0x###### 0x######\n
      staticColor4();
    }
  } else if (input.checkString("A")) {

    if (input.checkString("ALT")) {           // A ALT 0x###### 0x###### #\n
      callAlternate();
    } else if (input.checkString("FDP")) {    // A FDP [RED/GRN/BLU/ALL] # # (# #) # (# #) [R/N]\n
      callFadePixel();
    } else if (input.checkString("MPR")) {    // A MPR 0x###### 0x###### # [F/B]\n
      callMultiPixelRun();
    } else if (input.checkString("PXR")) {    // A PXR 0x###### 0x###### # [F/B] [T/N]\n
      callPixelRun();
    } else if (input.checkString("SCH")) {    // A SCH [CLC/FTC/HTC/LVC/OCC/PTC/RBC/RSC] # [F/B] [B/N]\n
      callSmoothChase();
    } else if (input.checkString("STC")) {    // A STC 0x######\n
      callSparkleToColor();
    } else if (input.checkString("WIP")) {    // A WIP 0x###### [F/B]\n
      callWipe();
    }
  }
}


void setup()
{

  // The following command initiates the serial port at 9600 baud. Please note this is VERY SLOW!!!!!!
  // I suggest you use higher speeds in your own code. You can go up to 115200 with the USB version, that's 12x faster
  Serial.begin(9600); //Baud set at 9600 for compatibility, CHANGE!

  input.attach(messageReady);

}

void loop()
{

  while (Serial.available()) {
    Serial.print("Reading\n");
    input.process(Serial.read());
  }

}


void staticColor1() {

  char colorString[9];

  input.copyString(colorString, 9);

  Serial.print(colorString + '\n');

}

void staticColor2() {

  char colorString1[9];
  char colorString2[9];

  input.copyString(colorString1, 9);
  input.copyString(colorString2, 9);

  Serial.print(colorString1 + '\t');
  Serial.print(colorString2 + '\n');

}

void staticColor3() {

  char colorString1[9];
  char colorString2[9];
  char colorString3[9];

  input.copyString(colorString1, 9);
  input.copyString(colorString2, 9);
  input.copyString(colorString3, 9);

  Serial.print(colorString1 + '\t');
  Serial.print(colorString2 + '\t');
  Serial.print(colorString3 + '\n');

}

void staticColor4() {

  char colorString1[9];
  char colorString2[9];
  char colorString3[9];
  char colorString4[9];

  input.copyString(colorString1, 9);
  input.copyString(colorString2, 9);
  input.copyString(colorString3, 9);
  input.copyString(colorString4, 9);

  Serial.print(colorString1 + '\t');
  Serial.print(colorString2 + '\t');
  Serial.print(colorString3 + '\t');
  Serial.print(colorString4 + '\n');

}

void callAlternate() {

  char colorString1[9];
  char colorString2[9];
  int duration;

  input.copyString(colorString1, 9);
  input.copyString(colorString2, 9);
  duration = input.readInt();

  Serial.print(colorString1 + '\t');
  Serial.print(colorString2 + '\t' + duration + '\n');

}

void callFadePixel() {

  if (input.checkString("RED")) {
    int pixel;
    int startIntensity;
    int endIntensity;
    char revert[2];

    pixel = input.readInt();
    startIntensity = input.readInt();
    endIntensity = input.readInt();
    input.copyString(revert, 2);

    Serial.print(pixel + '\t' + startIntensity + '\t' + endIntensity + '\t');
    Serial.print(revert + '\n');

  } else if (input.checkString("GRN")) {
    int pixel;
    int startIntensity;
    int endIntensity;
    char revert[2];

    pixel = input.readInt();
    startIntensity = input.readInt();
    endIntensity = input.readInt();
    input.copyString(revert, 2);

    Serial.print(pixel + '\t' + startIntensity + '\t' + endIntensity + '\t');
    Serial.print(revert + '\n');

  } else if (input.checkString("BLU")) {
    int pixel;
    int startIntensity;
    int endIntensity;
    char revert[2];

    pixel = input.readInt();
    startIntensity = input.readInt();
    endIntensity = input.readInt();
    input.copyString(revert, 2);

    Serial.print(pixel + '\t' + startIntensity + '\t' + endIntensity + '\t');
    Serial.print(revert + '\n');

  } else if (input.checkString("ALL")) {
    int pixel;
    int startRedIntensity;
    int startGreenIntensity;
    int startBlueIntensity;
    int endRedIntensity;
    int endGreenIntensity;
    int endBlueIntensity;
    char revert[2];

    pixel = input.readInt();
    startRedIntensity = input.readInt();
    startGreenIntensity = input.readInt();
    startBlueIntensity = input.readInt();
    endRedIntensity = input.readInt();
    endGreenIntensity = input.readInt();
    endBlueIntensity = input.readInt();
    input.copyString(revert, 2);

    Serial.print(pixel + '\t' + startRedIntensity + '\t' + startGreenIntensity + '\t' + startBlueIntensity + '\t' + endRedIntensity + '\t' + endGreenIntensity + '\t' + endBlueIntensity + '\t');
    Serial.print(revert + '\n');
  }
}

void callMultiPixelRun() {

}

void callPixelRun() {

}

void callSmoothChase() {

}

void callSparkleToColor() {

}

void callWipe() {

}

