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
    Fade_Strip_Red, 
    Fade_Strip_Green, 
    Fade_Strip_Blue, 
    Fade_Strip_All, 
    Multi_Pixel_Run, 
    Smooth_Chase, 
    Wipe
};

class dataValues {

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
  "Fade Strip Red", 
  "Fade Strip Green", 
  "Fade Strip Blue", 
  "Fade Strip All", 
  "Multi-Pixel Run", 
  "Smooth Chase", 
  "Wipe");

List colors = Arrays.asList( "Color 1", "Color 2" );

List tabNames = Arrays.asList( "Solid Color", "Animation" );


ControlP5 cp5;
ControlFont largeFont;
ControlFont mediumFont;
dataValues data;
ScrollableList animationList;
ScrollableList colorList;
ColorWheel colorWheel1;
ColorWheel colorWheel2;
ColorWheel animationColorWheelLeft;
ColorWheel animationColorWheelRight;
Button submitButton1;
Button submitButton2;
ButtonBar tabSelection;
Textfield animationTimeField;
int currentSelectingColor = 1;
int currentTab = -1;
int labelColor = color(0, 0, 0);

void settings() {

  //String widthIn = JOptionPane.showInputDialog("Enter Width");

  //String heightIn = JOptionPane.showInputDialog("Enter Height");

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
    .setDefaultValue(1.0)
    .setColorBackground(color(255, 0, 0));

  //createTab1();

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


  colorList = cp5.addScrollableList("colorSelection")
    .setPosition(width - (width * 0.2), height * 0.1)
    .setSize(int(width * 0.2), int(height * 0.2))
    .setBarHeight(int(height * 0.05))
    .setItemHeight(int(height * 0.05))
    .addItems(colors)
    .setFont(largeFont)
    .setOpen(false)
    .setColorValueLabel(labelColor)
    .setColorLabel(labelColor)
    .setColorBackground(color(255, 0, 0))
    .setLock(true)
    .setVisible(false)
    ;

  submitButton1 = cp5.addButton("Print")
    .setPosition(width * 0.5, height * 0.875)
    .setSize(int(width * 0.2), int(height * 0.05))
    .setFont(largeFont)
    .setColorLabel(labelColor)
    .setColorBackground(color(255, 0, 0))
    .setLock(true)
    .setVisible(false)
    ;

  submitButton2 = cp5.addButton("PrintSolid")
    .setPosition(width * 0.5, height * 0.875)
    .setSize(int(width * 0.2), int(height * 0.05))
    .setFont(largeFont)
    .setColorValueLabel(labelColor)
    .setLock(true)
    .setVisible(false)
    ;


  animationTimeField = cp5.addTextfield("Duration")
    .setPosition(int(width * 0.6), int(height * 0.1))
    .setSize(int(width * 0.075), int(height * 0.075))
    .setFont(mediumFont)
    .setColorLabel(labelColor)
    .setLock(true)
    .setVisible(false);
    
    animationTimeField.getCaptionLabel().align(ControlP5.CENTER, ControlP5.TOP_OUTSIDE).setPaddingX(0);

  colorWheel1 = cp5.addColorWheel("Choose Color A", int(width * 0.5), int(height * 0.2), int(width * 0.2)).setFont(largeFont).setColorLabel(labelColor).setLock(true).setVisible(false);

  colorWheel2 = cp5.addColorWheel("Choose Color", int(width * 0.375), int(height * 0.15), int(width * 0.375)).setFont(largeFont).setColorLabel(labelColor).setLock(true).setVisible(false);

  animationColorWheelLeft = cp5.addColorWheel("Choose Main Color", int(width * 0.35), int(height * 0.3), int(width * 0.2)).setFont(largeFont).setColorLabel(labelColor).setLock(true).setVisible(false);

  animationColorWheelRight = cp5.addColorWheel("Choose Alternate Color", int(width * 0.6), int(height * 0.3), int(width * 0.2)).setFont(largeFont).setColorLabel(labelColor).setLock(true).setVisible(false);
}

void draw() {
  background(255);

  if (currentTab == 1) {
    if (currentSelectingColor == 1) {

      data.color1 = colorWheel1.getRGB();
    } else if (currentSelectingColor == 2) {

      data.color2 = colorWheel1.getRGB();
    }
  } else if (currentTab == 0) {
    data.color1 = colorWheel2.getRGB();
  }
}


void createTab1() {
  animationList.setLock(false).setVisible(true);
  //colorList.setLock(false).setVisible(true);
  submitButton1.setLock(false).setVisible(true);
  //colorWheel1.setLock(false).setVisible(true);
}


void createAlternateTab() {

  animationColorWheelLeft.setLock(false).setVisible(true);
  animationColorWheelRight.setLock(false).setVisible(true);
  animationTimeField.setLock(false).setVisible(true);
}


void createFadePixelRedTab() {
  
  
  
}


void createFadePixelGreenTab() {
  
  
  
}


void createFadePixelBlueTab() {
  
  
  
}


void createFadePixelAllTab() {
  
  
  
}


void createFadeStripRedTab() {
  
  
  
}


void createFadeStripGreenTab() {
  
  
  
}


void createFadeStripBlueTab() {
  
  
  
}


void createFadeStripAllTab() {
  
  
  
}


void createMultiPixelRunTab() {
  
 
  
}


void createSmoothChaseTab() {
  
  
  
}


void createWipeTab() {
  
  
  
}


void destroyTab1() {

  animationList.setLock(true).setVisible(false);
  colorList.setLock(true).setVisible(false);
  submitButton1.setLock(true).setVisible(false);
  colorWheel1.setLock(true).setVisible(false);
}

void createTab0() {

  colorWheel2.setLock(false).setVisible(true);
  submitButton2.setLock(false).setVisible(true);
}


void destroyTab0() {

  colorWheel2.setLock(true).setVisible(false);
  submitButton2.setLock(true).setVisible(false);
}

void colorSelection (int n) {

  if (n == 0) {

    currentSelectingColor = 1;
  } else if (n == 1) {

    currentSelectingColor = 2;
  }
}


void Print () {

  println(data.currentAnimation + "  " + hex(data.color1 & 0xFFFFFF) + "  " + hex(data.color2 & 0xFFFFFF));
}


void tabSelectionBar(int n) {

  if (n == 0) {
    if (currentTab == 1) {
      destroyTab1(); 
      createTab0();
    } else if (currentTab == -1) {
      createTab0();
    }
    currentTab = 0;
  } else if (n == 1) {
    if (currentTab == 0) {
      destroyTab0();
      createTab1();
    } else if (currentTab == -1) {
      createTab1();
    }
    currentTab = 1;
  }
}


void animationSelection(int n) {

  println(animationList.getItem(n).get("name") + " Animation Selected");

  if (animationList.getItem(n).get("name") == "Alternate") {
    data.currentAnimation = animation.Alternate;
    createAlternateTab();
  } else if (animationList.getItem(n).get("name") == "Fade Pixel Red") {
    data.currentAnimation = animation.Fade_Pixel_Red;
  } else if (animationList.getItem(n).get("name") == "Fade Pixel Green") {
    data.currentAnimation = animation.Fade_Pixel_Green;
  } else if (animationList.getItem(n).get("name") == "Fade Pixel Blue") {
    data.currentAnimation = animation.Fade_Pixel_Blue;
  } else if (animationList.getItem(n).get("name") == "Fade Pixel All") {
    data.currentAnimation = animation.Fade_Pixel_All;
  } else if (animationList.getItem(n).get("name") == "Fade Strip Red") {
    data.currentAnimation = animation.Fade_Strip_Red;
  } else if (animationList.getItem(n).get("name") == "Fade Strip Green") {
    data.currentAnimation = animation.Fade_Strip_Green;
  } else if (animationList.getItem(n).get("name") == "Fade Strip Blue") {
    data.currentAnimation = animation.Fade_Strip_Blue;
  } else if (animationList.getItem(n).get("name") == "Fade Strip All") {
    data.currentAnimation = animation.Fade_Strip_All;
  } else if (animationList.getItem(n).get("name") == "Multi-Pixel Run") {
    data.currentAnimation = animation.Multi_Pixel_Run;
  } else if (animationList.getItem(n).get("name") == "Smooth Chase") {
    data.currentAnimation = animation.Smooth_Chase;
  } else if (animationList.getItem(n).get("name") == "Wipe") {
    data.currentAnimation = animation.Wipe;
  }
}
