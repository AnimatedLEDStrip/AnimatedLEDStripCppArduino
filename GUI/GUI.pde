import controlP5.*;
import java.util.*;
import javax.swing.*;


class colorContainer {

  public int r;
  public int g;
  public int b;
};

enum direction {
  forward, 
    backward
};

enum animation {
  Alternate, 
    Fade_Pixel_Red, 
    Fade_Pixel_Green, 
    Fade_Pixel_Blue, 
    Fade_Pixel_All, 
    //Fade_Strip_Red, 
    //Fade_Strip_Green, 
    //Fade_Strip_Blue, 
    //Fade_Strip_All, 
    Multi_Pixel_Run, 
    Pixel_Run, 
    Pixel_Run_With_Trail, 
    Smooth_Chase, 
    Sparkle_To_Color, 
    Wipe
};

class dataValues {

  public int staticColor1;
  public int staticColor2;
  public int staticColor3;
  public int staticColor4;
  public int color1;
  public int color2;

  public direction movementDirection;

  public animation currentAnimation;
};

List animations = Arrays.asList(
  "Alternate", 
  "Fade Pixel Red", 
  "Fade Pixel Green", 
  "Fade Pixel Blue", 
  "Fade Pixel All", 
  //"Fade Strip Red", 
  //"Fade Strip Green", 
  //"Fade Strip Blue", 
  //"Fade Strip All", 
  "Multi-Pixel Run", 
  "Pixel Run", 
  "Pixel Run with Trail", 
  "Smooth Chase", 
  "Sparkle to Color", 
  "Wipe");

List colors = Arrays.asList( "Color 1", "Color 2" );

List tabNames = Arrays.asList( "Static Color", "Animation" );


ControlP5 cp5;
ControlFont largeFont;
ControlFont mediumFont;
dataValues data;
ScrollableList animationList;
ColorWheel animationColorWheelLeft;
ColorWheel animationColorWheelRight;
ColorWheel staticColorWheelLeft;
ColorWheel staticColorWheelMiddleLeft;
ColorWheel staticColorWheelMiddleRight;
ColorWheel staticColorWheelRight;
Button submitButton1;
Button submitButton2;
ButtonBar tabSelection;
Textfield animationTimeField;
Textfield animationSpacingField;
int currentSelectingColor = 1;
int currentTab = -1;
int labelColor = color(0, 0, 0);

void settings() {

  //String widthIn = JOptionPane.showInputDialog(null, "Enter Width", "1000");

  //String heightIn = JOptionPane.showInputDialog(null, "Enter Height", "800");

  //size(int(widthIn), int(heightIn));

  fullScreen();
}


void setup() {

  data = new dataValues();

  cp5 = new ControlP5(this);  

  largeFont = new ControlFont(createFont("Roboto-Regular.ttf", int(height * 0.032), true), int(height * 0.032));

  mediumFont = new ControlFont(createFont("Roboto-Regular.ttf", int(height * 0.02), true), int(height * 0.02));

  tabSelection = cp5.addButtonBar("tabSelectionBar")
    .setPosition(0, 0)
    .setSize(width, int(height * 0.05))
    .addItems(tabNames)
    .setFont(largeFont)
    .setColorValueLabel(labelColor)
    .setColorBackground(color(255, 0, 0));

  animationList = cp5.addScrollableList("animationSelection")
    .setPosition(0, height * 0.1)
    .setSize(int(width * 0.267), int(height * 0.75))
    .setBarHeight(int(height * 0.05))
    .setItemHeight(int(height * 0.05))
    .addItems(animations)
    .setFont(largeFont)
    .setOpen(false)
    .setLabel("Choose Animation")
    .setColorValueLabel(labelColor)
    .setColorLabel(labelColor)
    .setColorBackground(color(255, 0, 0))
    .setLock(true)
    .setVisible(false);

  submitButton1 = cp5.addButton("SendAnimation")
    .setPosition(width * 0.5, height * 0.875)
    .setSize(int(width * 0.2), int(height * 0.05))
    .setFont(largeFont)
    .setColorLabel(labelColor)
    .setColorBackground(color(255, 0, 0))
    .setLabel("Send Animation")
    .setLock(true)
    .setVisible(false);

  submitButton2 = cp5.addButton("SendColor")
    .setPosition(width * 0.5, height * 0.875)
    .setSize(int(width * 0.2), int(height * 0.05))
    .setFont(largeFont)
    .setColorValueLabel(labelColor)
    .setLabel("Send Color")
    .setLock(true)
    .setVisible(false);


  animationTimeField = cp5.addTextfield("Duration")
    .setPosition(int(width * 0.6), int(height * 0.1))
    .setSize(int(width * 0.05), int(height * 0.05))
    .setFont(mediumFont)
    .setColorLabel(labelColor)
    .setValue("50")
    .setLock(true)
    .setVisible(false);

  animationTimeField.getCaptionLabel()
    .align(ControlP5.CENTER, ControlP5.TOP_OUTSIDE)
    .setPaddingX(0);

  animationColorWheelLeft = cp5.addColorWheel("Choose Main Color", int(width * 0.525), int(height * 0.3), int(width * 0.15))
    .setFont(largeFont)
    .setColorLabel(labelColor)
    .setLock(true)
    .setVisible(false);

  animationColorWheelRight = cp5.addColorWheel("Choose Alternate Color", int(width * 0.775), int(height * 0.3), int(width * 0.15))
    .setFont(largeFont)
    .setColorLabel(labelColor)
    .setLock(true)
    .setVisible(false);

  animationSpacingField = cp5.addTextfield("Spacing")
    .setPosition(int(width * 0.35), int(height * 0.1))
    .setSize(int(width * 0.05), int(height * 0.05))
    .setFont(mediumFont)
    .setColorLabel(labelColor)
    .setValue("3")
    .setLock(true)
    .setVisible(false);

  staticColorWheelRight = cp5.addColorWheel("Choose Color 4", int(width * 0.8), int(height * 0.3), int(width * 0.15)).setFont(largeFont).setColorLabel(labelColor).setLock(true).setVisible(false);

  staticColorWheelMiddleRight = cp5.addColorWheel("Choose Color 3", int(width * 0.55), int(height * 0.3), int(width * 0.15)).setFont(largeFont).setColorLabel(labelColor).setLock(true).setVisible(false);

  staticColorWheelMiddleLeft = cp5.addColorWheel("Choose Color 2", int(width * 0.3), int(height * 0.3), int(width * 0.15)).setFont(largeFont).setColorLabel(labelColor).setLock(true).setVisible(false);

  staticColorWheelLeft = cp5.addColorWheel("Choose Color 1", int(width * 0.05), int(height * 0.3), int(width * 0.15)).setFont(largeFont).setColorLabel(labelColor).setLock(true).setVisible(false);


  animationSpacingField.getCaptionLabel()
    .align(ControlP5.CENTER, ControlP5.TOP_OUTSIDE)
    .setPaddingX(0);
}

void draw() {
  background(255);

  data.staticColor1 = staticColorWheelLeft.getRGB();
  data.staticColor2 = staticColorWheelMiddleLeft.getRGB();
  data.staticColor3 = staticColorWheelMiddleRight.getRGB();
  data.staticColor4 = staticColorWheelRight.getRGB();
  data.color1 = animationColorWheelLeft.getRGB();
  data.color2 = animationColorWheelRight.getRGB();
}


void createAlternateTab() {

  animationColorWheelLeft.setLock(false).setVisible(true);
  animationColorWheelRight.setLock(false).setVisible(true);
  animationTimeField.setLock(false).setVisible(true);
}

void destroyAlternateTab() {

  animationColorWheelLeft.setLock(true).setVisible(false);
  animationColorWheelRight.setLock(true).setVisible(false);
  animationTimeField.setLock(true).setVisible(false);
}

void createFadePixelRedTab() {
}

void destroyFadePixelRedTab() {
}

void createFadePixelGreenTab() {
}

void destroyFadePixelGreenTab() {
}

void createFadePixelBlueTab() {
}

void destroyFadePixelBlueTab() {
}

void createFadePixelAllTab() {
}

void destroyFadePixelAllTab() {
}

//void createFadeStripRedTab() {



//}


//void createFadeStripGreenTab() {



//}


//void createFadeStripBlueTab() {



//}


//void createFadeStripAllTab() {



//}


void createMultiPixelRunTab() {
  animationColorWheelLeft.setLock(false).setVisible(true);
  animationColorWheelRight.setLock(false).setVisible(true);
  animationSpacingField.setLock(false).setVisible(true);
}

void destroyMultiPixelRunTab() {
}

void createSmoothChaseTab() {
}

void destroySmoothChaseTab() {
}

void createSparkleToColorTab() {
}

void destroySparkleToColorTab() {
}

void createWipeTab() {
}

void destroyWipeTab() {
}

void createAnimationPage() {
  animationList.setLock(false).setVisible(true);
  submitButton1.setLock(false).setVisible(true);
}

void destroyAnimationPage() {
  animationList.setLock(true).setVisible(false);
  submitButton1.setLock(true).setVisible(false);
}

void createStaticColorPage() {

  staticColorWheelRight.setLock(false).setVisible(true);
  staticColorWheelMiddleRight.setLock(false).setVisible(true);
  staticColorWheelMiddleLeft.setLock(false).setVisible(true);
  staticColorWheelLeft.setLock(false).setVisible(true);
  submitButton2.setLock(false).setVisible(true);
}


void destroyStaticColorPage() {

  staticColorWheelRight.setLock(true).setVisible(false);
  staticColorWheelMiddleRight.setLock(true).setVisible(false);
  staticColorWheelMiddleLeft.setLock(true).setVisible(false);
  staticColorWheelLeft.setLock(true).setVisible(false);
  submitButton2.setLock(true).setVisible(false);
}


void SendAnimation () {

  println(data.currentAnimation + "  " + hex(data.color1 & 0xFFFFFF) + "  " + hex(data.color2 & 0xFFFFFF));
}

void SendColor () {

  println(hex(data.color1 & 0xFFFFFF));
}


void tabSelectionBar(int n) {

  if (n == 0) {
    if (currentTab == 1) {
      destroyAnimationPage(); 
      createStaticColorPage();
    } else if (currentTab == -1) {
      createStaticColorPage();
    }
    currentTab = 0;
  } else if (n == 1) {
    if (currentTab == 0) {
      destroyStaticColorPage();
      createAnimationPage();
    } else if (currentTab == -1) {
      createAnimationPage();
    }
    currentTab = 1;
  }
}


void animationSelection(int n) {

  println(animationList.getItem(n).get("name") + " Animation Selected");


  if (data.currentAnimation == animation.Alternate) {
    destroyAlternateTab();
  } else if (data.currentAnimation == animation.Fade_Pixel_Red) {
    destroyFadePixelRedTab();
  } else if (data.currentAnimation == animation.Fade_Pixel_Green) {
    destroyFadePixelGreenTab();
  } else if (data.currentAnimation == animation.Fade_Pixel_Blue) {
    destroyFadePixelBlueTab();
  } else if (data.currentAnimation == animation.Fade_Pixel_All) {
    destroyFadePixelAllTab();
    //} else if (data.currentAnimation == animation.Fade_Strip_Red) {
    //  destroyFadeStripRedTab();
    //} else if (data.currentAnimation == animation.Fade_Strip_Green) {
    //  destroyFadeStripGreenTab();
    //} else if (data.currentAnimation == animation.Fade_Strip_Blue) {
    //  destroyFadeStripBlueTab();
    //} else if (data.currentAnimation == animation.Fade_Strip_All) {
    //  destroyFadeStripAllTab();
  } else if (data.currentAnimation == animation.Multi_Pixel_Run) {
    destroyMultiPixelRunTab();
  } else if (data.currentAnimation == animation.Smooth_Chase) {
    destroySmoothChaseTab();
  } else if (data.currentAnimation == animation.Wipe) {
    destroyWipeTab();
  }


  if (animationList.getItem(n).get("name") == "Alternate") {
    data.currentAnimation = animation.Alternate;
    createAlternateTab();
  } else if (animationList.getItem(n).get("name") == "Fade Pixel Red") {
    data.currentAnimation = animation.Fade_Pixel_Red;
    createFadePixelRedTab();
  } else if (animationList.getItem(n).get("name") == "Fade Pixel Green") {
    data.currentAnimation = animation.Fade_Pixel_Green;
    createFadePixelGreenTab();
  } else if (animationList.getItem(n).get("name") == "Fade Pixel Blue") {
    data.currentAnimation = animation.Fade_Pixel_Blue;
    createFadePixelBlueTab();
  } else if (animationList.getItem(n).get("name") == "Fade Pixel All") {
    data.currentAnimation = animation.Fade_Pixel_All;
    createFadePixelAllTab();
    //} else if (animationList.getItem(n).get("name") == "Fade Strip Red") {
    //  data.currentAnimation = animation.Fade_Strip_Red;
    //} else if (animationList.getItem(n).get("name") == "Fade Strip Green") {
    //  data.currentAnimation = animation.Fade_Strip_Green;
    //} else if (animationList.getItem(n).get("name") == "Fade Strip Blue") {
    //  data.currentAnimation = animation.Fade_Strip_Blue;
    //} else if (animationList.getItem(n).get("name") == "Fade Strip All") {
    //  data.currentAnimation = animation.Fade_Strip_All;
  } else if (animationList.getItem(n).get("name") == "Multi-Pixel Run") {
    data.currentAnimation = animation.Multi_Pixel_Run;
    createMultiPixelRunTab();
  } else if (animationList.getItem(n).get("name") == "Smooth Chase") {
    data.currentAnimation = animation.Smooth_Chase;
    createSmoothChaseTab();
  } else if (animationList.getItem(n).get("name") == "Sparkle to Color") {
    data.currentAnimation = animation.Sparkle_To_Color;
    createSparkleToColorTab();
  } else if (animationList.getItem(n).get("name") == "Wipe") {
    data.currentAnimation = animation.Wipe;
    createWipeTab();
  }
}
