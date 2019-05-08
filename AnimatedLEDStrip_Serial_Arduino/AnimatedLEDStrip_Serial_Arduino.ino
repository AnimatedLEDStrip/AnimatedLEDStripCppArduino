#include <Messenger.h>
#include <AnimatedLEDStrip.h>

/*  This code can be used with the AnimatedLEDStrip Library GUI when connected to the computer via a serial (USB) connection.
    This can also be used with any other device that can send serial communication in the correct format, such as:
      The Arduino Serial Monitor (if "Carriage Return" or "Both NL & CR" is selected for the line ending)
      A RoboRIO (using the SerialPort class)

    When using serial communication, follow the formats specified for each animation.
    Message conventions:
      <Color> means a hexadecimal value (usually 6 digits) WITHOUT the 0x at the beginning. Leading 0s are not mandatory, thus 000000 and 0 are both valid ways of representing black.
      (A | B) means that A or B can be used but that one and only one of them must be there.
      <Brightness>, <Start(r)intensity>, <EndgIntensity> and all others like them are integer values between 0 and 255.
      <Spacing> is an integer value. For best results, use something in the range of 3-6.
      \r is a reminder that a carriage return (0x0D or \r) is needed at the end of every message.
*/

Messenger input;          // Create a Messenger instance

#define NUMLEDS 50        // Number of pixels in the strip  !!! See Note in User Manual for Warning About Number of Pixels !!!
#define PIN 2             // Pin the strip is connected to

AnimatedLEDStrip leds = AnimatedLEDStrip(NUMLEDS, PIN);     // Create an AnimatedLEDStrip instance

enum animation {    // Enumeration to keep track of which animation is currently in use
  COL1 = 1,
  COL2,
  COL3,
  COL4,
  ALT,
  FDP,
  MPR,
  PXR,
  SCH,
  SPK,
  STC,
  WIP
} currentAnimation;

enum fadeType {     // Enumeration to keep track of which part of the pixel is being faded (in a Fade Pixel animation)
  RED,
  GRN,
  BLU,
  ALL
} currentFadeType;

enum animationDirection {   // Enumeration to keep track of the direction for the current animation
  FWD,
  BKW
} currentAnimationDirection;

enum animationTrail {       // Enumeration to keep track of if a Pixel Run animation has a trail
  TRL,
  NTRL
} currentAnimationTrail;

enum smoothChasePalette {   // Enumeration to keep track of which Smooth Chase Animation palette is in use
  CLC,
  FTC,
  HTC,
  LVC,
  OCC,
  PTC,
  RBC,
  RSC
} currentSmoothChasePalette;

enum animationRevert {      // Enumeration to keep track of if the current Fade Pixel animation should be reverted at completion
  REV,
  NREV
} currentAnimationRevert;

long
color1,         // Holds the integer value of the first color in the animation
color2,         // Holds the integer value of the first color in the animation
color3,         // Holds the integer value of the first color in the animation
color4;         // Holds the integer value of the first color in the animation

int
spacing,        // Saves the spacing used for a Multi-Pixel Run animation
pixel,          // Saves the pixel used in a Fade Pixel animation
brightness,     // Saves the brightness used in a Smooth Chase animation
duration,       // Saves the duration used in an Alternate animation
sRed,           // Saves the start red intensity in a Fade Pixel All animation
sGrn,           // Saves the start green intensity in a Fade Pixel All animation
sBlu,           // Saves the start blue intensity in a Fade Pixel All animation
eRed,           // Saves the end red intensity in a Fade Pixel All animation
eGrn,           // Saves the end green intensity in a Fade Pixel All animation
eBlu,           // Saves the end blue intensity in a Fade Pixel All animation
sInt,           // Saves the start intensity in a Fade Pixel Red/Green/Blue animation
eInt;           // Saves the end intensity in a Fade Pixel Red/Green/Blue animation

char hexIn[7];  // Holds the input characters for a color so they can be converted to a hexadecimal value

bool staticAnimation = false;


void messageReady() {

  //Serial.print("\nMessage\n");

  if (input.checkString("S")) {
    staticAnimation = true;
  } else if (input.checkString("A")) {
    staticAnimation = false;
  }
  if (input.checkString("COL1")) {          // (S | A) COL1 <Color>\r
    staticColor1();
  } else if (input.checkString("COL2")) {   // (S | A) COL2 <Color> <Color>\r
    staticColor2();
  } else if (input.checkString("COL3")) {   // (S | A) COL3 <Color> <Color> <Color>\r
    staticColor3();
  } else if (input.checkString("COL4")) {   // (S | A) COL4 <Color> <Color> <Color> <Color>\r
    staticColor4();
  } else if (input.checkString("ALT")) {    // (S | A) ALT <Color> <Color> <Duration>\r
    callAlternate();
  } else if (input.checkString("FDP")) {    // (S | A) FDP (RED | GRN | BLU | ALL) <Pixel> <Start(r)intensity> [<Startgintensity> <Startbintensity>] <End(r)intensity> [<Endgintensity> <Endbintensity>] (R | N)\r
    callFadePixel();
  } else if (input.checkString("MPR")) {    // (S | A) MPR <Spacing> <Color> <Color> (F | B)\r
    callMultiPixelRun();
  } else if (input.checkString("PXR")) {    // (S | A) PXR <Color> <Color> (F | B) (T | N)\r
    callPixelRun();
  } else if (input.checkString("SCH")) {    // (S | A) SCH (CLC | FTC | HTC | LVC | OCC | PTC | RBC | RSC) (F | B) <Brightness>\r
    callSmoothChase();
  } else if (input.checkString("SPK")) {    // (S | A) SPK <Color>\r
    callSparkle();
  } else if (input.checkString("STC")) {    // (S | A) STC <Color>\r
    callSparkleToColor();
  } else if (input.checkString("WIP")) {    // (S | A) WIP <Color> (F | B)\r
    callWipe();
  }
}

void clearVariables() {
  // Set all variables to NULL
  spacing = NULL;
  color1 = NULL;
  color2 = NULL;
  color3 = NULL;
  color4 = NULL;
  currentAnimation = NULL;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

  staticAnimation = false;
}


void setup() {

  Serial.begin(9600);                 // Start serial communication

  input.attach(messageReady);         // Attach callback function to Messenger processes


  // Set all variables to NULL at beginning
  spacing = NULL;
  color1 = NULL;
  color2 = NULL;
  color3 = NULL;
  color4 = NULL;
  currentAnimation = NULL;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}


void loop() {

  // Determine the current animation with currentAnimation and then call that animation with the specified parameters saved in other variables

  //Serial.print("Start\n");

  switch (currentAnimation) {
    case COL1:                   // (S | A) COL1 <Color>\r
      leds.setStripColor(ColorContainer(color1));
      leds.show();
      break;

    case COL2:                   // (S | A) COL2 <Color> <Color>\r
      leds.fillLEDsWithGradient(ColorContainer(color1), ColorContainer(color2));
      leds.show();
      break;

    case COL3:                   // (S | A) COL3 <Color> <Color> <Color>\r
      leds.fillLEDsWithGradient(ColorContainer(color1), ColorContainer(color2), ColorContainer(color3));
      leds.show();
      break;

    case COL4:                   // (S | A) COL4 <Color> <Color> <Color> <Color>\r
      leds.fillLEDsWithGradient(ColorContainer(color1), ColorContainer(color2), ColorContainer(color3), ColorContainer(color4));
      leds.show();
      break;

    case ALT:                    // (S | A) ALT <Color> <Color> <Duration>\r
      leds.alternate(ColorContainer(color1), ColorContainer(color2), duration);
      break;

    case FDP:                    // (S | A) FDP (RED | GRN | BLU | ALL) <Pixel> <Start(r)intensity> [<Startgintensity> <Startbintensity>] <End(r)intensity> [<Endgintensity> <Endbintensity>] (R | N)\r
      switch (currentFadeType) {
        case RED:
          switch (currentAnimationRevert) {
            case REV:
              leds.fadePixelRed(pixel, sInt, eInt, true);
              break;
            case NREV:
              leds.fadePixelRed(pixel, sInt, eInt, false);
              break;
          }
          break;

        case GRN:
          switch (currentAnimationRevert) {
            case REV:
              leds.fadePixelGreen(pixel, sInt, eInt, true);
              break;
            case NREV:
              leds.fadePixelGreen(pixel, sInt, eInt, false);
              break;
          }
          break;

        case BLU:
          switch (currentAnimationRevert) {
            case REV:
              leds.fadePixelBlue(pixel, sInt, eInt, true);
              break;
            case NREV:
              leds.fadePixelBlue(pixel, sInt, eInt, false);
              break;
          }
          break;

        case ALL:
          switch (currentAnimationRevert) {
            case REV:
              leds.fadePixelAll(pixel, sRed, sGrn, sBlu, eRed, eGrn, eBlu, true);
              break;
            case NREV:
              leds.fadePixelAll(pixel, sRed, sGrn, sBlu, eRed, eGrn, eBlu, false);
              break;
          }
          break;

      }
      break;

    case MPR:                    // (S | A) MPR <Spacing> <Color> <Color> (F | B)\r
      switch (currentAnimationDirection) {
        case FWD:
          leds.multiPixelRun(spacing, forward, ColorContainer(color1), ColorContainer(color2));
          break;
        case BKW:
          leds.multiPixelRun(spacing, backward, ColorContainer(color1), ColorContainer(color2));
          break;
      }
      break;

    case PXR:                    // (S | A) PXR <Color> <Color> (F | B) (T | N)\r
      switch (currentAnimationTrail) {
        case TRL:
          switch (currentAnimationDirection) {
            case FWD:
              leds.pixelRunWithTrail(forward, ColorContainer(color1), ColorContainer(color2));
              break;
            case BKW:
              leds.pixelRunWithTrail(backward, ColorContainer(color1), ColorContainer(color2));
              break;
          }
          break;
        case NTRL:
          switch (currentAnimationDirection) {
            case FWD:
              leds.pixelRun(forward, ColorContainer(color1), ColorContainer(color2));
              break;
            case BKW:
              leds.pixelRun(backward, ColorContainer(color1), ColorContainer(color2));
              break;
          }
          break;
      }
      break;

    case SCH:                    // (S | A) SCH (CLC | FTC | HTC | LVC | OCC | PTC | RBC | RSC) (F | B) <Brightness>\r
      switch (currentSmoothChasePalette) {
        case CLC:
          switch (currentAnimationDirection) {
            case FWD:
              leds.smoothChase(CloudColors_p, forward);
              break;
            case BKW:
              leds.smoothChase(CloudColors_p, backward);
              break;
          }
          break;

        case FTC:
          switch (currentAnimationDirection) {
            case FWD:
              leds.smoothChase(ForestColors_p, forward);
              break;
            case BKW:
              leds.smoothChase(ForestColors_p, backward);
              break;
          }
          break;

        case HTC:
          switch (currentAnimationDirection) {
            case FWD:
              leds.smoothChase(HeatColors_p, forward);
              break;
            case BKW:
              leds.smoothChase(HeatColors_p, backward);
              break;
          }
          break;

        case LVC:
          switch (currentAnimationDirection) {
            case FWD:
              leds.smoothChase(LavaColors_p, forward);
              break;
            case BKW:
              leds.smoothChase(LavaColors_p, backward);
              break;
          }
          break;

        case OCC:
          switch (currentAnimationDirection) {
            case FWD:
              leds.smoothChase(OceanColors_p, forward);
              break;
            case BKW:
              leds.smoothChase(OceanColors_p, backward);
              break;
          }
          break;

        case PTC:
          switch (currentAnimationDirection) {
            case FWD:
              leds.smoothChase(PartyColors_p, forward);
              break;
            case BKW:
              leds.smoothChase(PartyColors_p, backward);
              break;
          }
          break;

        case RBC:
          switch (currentAnimationDirection) {
            case FWD:
              leds.smoothChase(RainbowColors_p, forward);
              break;
            case BKW:
              leds.smoothChase(RainbowColors_p, backward);
              break;
          }
          break;

        case RSC:
          switch (currentAnimationDirection) {
            case FWD:
              leds.smoothChase(RainbowStripeColors_p, forward);
              break;
            case BKW:
              leds.smoothChase(RainbowStripeColors_p, backward);
              break;
          }
          break;

      }
      break;

    case SPK:                    // (S | A) SPK <Color>\r
      leds.sparkle(ColorContainer(color1));
      break;

    case STC:                    // (S | A) STC <Color>\r
      leds.sparkleToColor(ColorContainer(color1));
      break;

    case WIP:                    // (S | A) WIP <Color> (F | B)\r
      switch (currentAnimationDirection) {
        case FWD:
          leds.wipe(ColorContainer(color1), forward);
          break;
        case BKW:
          leds.wipe(ColorContainer(color1), backward);
          break;
      }
      break;

    default:
      break;

  }

  if (staticAnimation) clearVariables();

}

// If a message is received by the Arduino, process it (and call messageReady())
void serialEvent() {
  while (Serial.available()) {
    //Serial.print("Reading\n");
    input.process(Serial.read());
  }
}

// Helper function to save a hex value (stored in chars) from the serial communication
void saveColorFromHex(long & colorIn) {
  input.copyString(hexIn, 7);

  String tempString(hexIn);

  String temp = "0x" + tempString;

  colorIn = strtoul(temp.c_str(), nullptr, 16);

  return;
}


void staticColor1() {                   // (S | A) COL1 <Color>\r
  spacing = NULL;
  saveColorFromHex(color1);
  color2 = NULL;
  color3 = NULL;
  color4 = NULL;
  currentAnimation = COL1;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  pixel = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void staticColor2() {                   // (S | A) COL2 <Color> <Color>\r
  spacing = NULL;
  saveColorFromHex(color1);
  saveColorFromHex(color2);
  color3 = NULL;
  color4 = NULL;
  currentAnimation = COL2;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  pixel = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void staticColor3() {                   // (S | A) COL3 <Color> <Color> <Color>\r
  spacing = NULL;
  saveColorFromHex(color1);
  saveColorFromHex(color2);
  saveColorFromHex(color3);
  color4 = NULL;
  currentAnimation = COL3;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  pixel = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void staticColor4() {                   // (S | A) COL4 <Color> <Color> <Color> <Color>\r
  spacing = NULL;
  saveColorFromHex(color1);
  saveColorFromHex(color2);
  saveColorFromHex(color3);
  saveColorFromHex(color4);
  currentAnimation = COL4;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  pixel = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void callAlternate() {                  // (S | A) ALT <Color> <Color> <Duration>\r
  spacing = NULL;
  saveColorFromHex(color1);
  saveColorFromHex(color2);
  color3 = NULL;
  color4 = NULL;
  currentAnimation = ALT;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  pixel = NULL;
  duration = input.readInt();
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void callFadePixel() {                  // (S | A) FDP (RED | GRN | BLU | ALL) <Pixel> <Start(r)intensity> [(<Startgintensity> <Startbintensity>)] <End(r)intensity> [(<Endgintensity> <Endbintensity>)] (R | N)\r

  if (input.checkString("RED")) {
    spacing = NULL;
    color1 = NULL;
    color2 = NULL;
    color3 = NULL;
    color4 = NULL;
    currentAnimation = FDP;
    currentFadeType = RED;
    currentAnimationDirection = NULL;
    currentAnimationTrail = NULL;
    currentSmoothChasePalette = NULL;
    brightness = NULL;
    pixel = input.readInt();
    duration = NULL;
    sRed = NULL;
    sGrn = NULL;
    sBlu = NULL;
    eRed = NULL;
    eGrn = NULL;
    eBlu = NULL;
    sInt = input.readInt();
    eInt = input.readInt();
    if (input.checkString("R") || input.checkString("r"))
      currentAnimationRevert = REV;
    else if (input.checkString("N") || input.checkString("n"))
      currentAnimationRevert = NREV;

  } else if (input.checkString("GRN")) {
    spacing = NULL;
    color1 = NULL;
    color2 = NULL;
    color3 = NULL;
    color4 = NULL;
    currentAnimation = FDP;
    currentFadeType = GRN;
    currentAnimationDirection = NULL;
    currentAnimationTrail = NULL;
    currentSmoothChasePalette = NULL;
    brightness = NULL;
    pixel = input.readInt();
    duration = NULL;
    sRed = NULL;
    sGrn = NULL;
    sBlu = NULL;
    eRed = NULL;
    eGrn = NULL;
    eBlu = NULL;
    sInt = input.readInt();
    eInt = input.readInt();
    if (input.checkString("R") || input.checkString("r"))
      currentAnimationRevert = REV;
    else if (input.checkString("N") || input.checkString("n"))
      currentAnimationRevert = NREV;

  } else if (input.checkString("BLU")) {
    spacing = NULL;
    color1 = NULL;
    color2 = NULL;
    color3 = NULL;
    color4 = NULL;
    currentAnimation = FDP;
    currentFadeType = ALL;
    currentAnimationDirection = NULL;
    currentAnimationTrail = NULL;
    currentSmoothChasePalette = NULL;
    brightness = NULL;
    pixel = input.readInt();
    duration = NULL;
    sRed = NULL;
    sGrn = NULL;
    sBlu = NULL;
    eRed = NULL;
    eGrn = NULL;
    eBlu = NULL;
    sInt = input.readInt();
    eInt = input.readInt();
    if (input.checkString("R") || input.checkString("r"))
      currentAnimationRevert = REV;
    else if (input.checkString("N") || input.checkString("n"))
      currentAnimationRevert = NREV;

  } else if (input.checkString("ALL")) {
    spacing = NULL;
    color1 = NULL;
    color2 = NULL;
    color3 = NULL;
    color4 = NULL;
    currentAnimation = FDP;
    currentFadeType = ALL;
    currentAnimationDirection = NULL;
    currentAnimationTrail = NULL;
    currentSmoothChasePalette = NULL;
    brightness = NULL;
    pixel = input.readInt();
    duration = NULL;
    sRed = input.readInt();
    sGrn = input.readInt();
    sBlu = input.readInt();
    eRed = input.readInt();
    eGrn = input.readInt();
    eBlu = input.readInt();
    sInt = NULL;
    eInt = NULL;
    if (input.checkString("R") || input.checkString("r"))
      currentAnimationRevert = REV;
    else if (input.checkString("N") || input.checkString("n"))
      currentAnimationRevert = NREV;
  }

}

void callMultiPixelRun() {              // (S | A) MPR <Spacing> <Color> <Color> (F | B)\r

  spacing = input.readInt();
  saveColorFromHex(color1);
  saveColorFromHex(color2);
  color3 = NULL;
  color4 = NULL;
  currentAnimation = MPR;
  currentFadeType = NULL;
  if (input.checkString("F") || input.checkString("f"))
    currentAnimationDirection = FWD;
  else if (input.checkString("B") || input.checkString("b"))
    currentAnimationDirection = BKW;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void callPixelRun() {                   // (S | A) PXR <Color> <Color> (F | B) (T | N)\r

  spacing = NULL;
  saveColorFromHex(color1);
  saveColorFromHex(color2);
  color3 = NULL;
  color4 = NULL;
  currentAnimation = PXR;
  currentFadeType = NULL;
  if (input.checkString("F") || input.checkString("f"))
    currentAnimationDirection = FWD;
  else if (input.checkString("B") || input.checkString("b"))
    currentAnimationDirection = BKW;
  if (input.checkString("T") || input.checkString("t"))
    currentAnimationTrail = TRL;
  else if (input.checkString("N") || input.checkString("n"))
    currentAnimationTrail = NTRL;
  currentAnimationDirection = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void callSmoothChase() {                // (S | A) SCH (CLC | FTC | HTC | LVC | OCC | PTC | RBC | RSC) (F | B) <Brightness>\r

  spacing = NULL;
  color1 = NULL;
  color2 = NULL;
  color3 = NULL;
  color4 = NULL;
  currentAnimation = SCH;
  currentFadeType = NULL;
  currentSmoothChasePalette = NULL;
  if (input.checkString("CLC"))
    currentSmoothChasePalette = CLC;
  else if (input.checkString("FTC"))
    currentSmoothChasePalette = FTC;
  else if (input.checkString("HTC"))
    currentSmoothChasePalette = HTC;
  else if (input.checkString("LVC"))
    currentSmoothChasePalette = LVC;
  else if (input.checkString("OCC"))
    currentSmoothChasePalette = OCC;
  else if (input.checkString("PTC"))
    currentSmoothChasePalette = PTC;
  else if (input.checkString("RBC"))
    currentSmoothChasePalette = RBC;
  else if (input.checkString("RSC"))
    currentSmoothChasePalette = RSC;
  if (input.checkString("F") || input.checkString("f"))
    currentAnimationDirection = FWD;
  else if (input.checkString("B") || input.checkString("b"))
    currentAnimationDirection = BKW;
  currentAnimationTrail = NULL;
  brightness = input.readInt();
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void callSparkle() {                    // (S | A) SPK <Color>\r

  spacing = NULL;
  saveColorFromHex(color1);
  color2 = NULL;
  color3 = NULL;
  color4 = NULL;
  currentAnimation = SPK;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

void callSparkleToColor() {             // (S | A) STC <Color>\r

  spacing = NULL;
  saveColorFromHex(color1);
  color2 = NULL;
  color3 = NULL;
  color4 = NULL;
  currentAnimation = STC;
  currentFadeType = NULL;
  currentAnimationDirection = NULL;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;
}

void callWipe() {                       // (S | A) WIP <Color> (F | B)\r

  spacing = NULL;
  saveColorFromHex(color1);
  color2 = NULL;
  color3 = NULL;
  color4 = NULL;
  currentAnimation = WIP;
  currentFadeType = NULL;
  if (input.checkString("F") || input.checkString("f"))
    currentAnimationDirection = FWD;
  else if (input.checkString("B") || input.checkString("b"))
    currentAnimationDirection = BKW;
  currentAnimationTrail = NULL;
  currentSmoothChasePalette = NULL;
  brightness = NULL;
  duration = NULL;
  sRed = NULL;
  sGrn = NULL;
  sBlu = NULL;
  eRed = NULL;
  eGrn = NULL;
  eBlu = NULL;
  sInt = NULL;
  eInt = NULL;
  currentAnimationRevert = NULL;

}

