import controlP5.*;
import java.util.*;


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



ControlP5 cp5;
ControlFont cf1;
dataValues data;
int currentSelectingColor = 1;

void setup() {
  size(3000, 2000);

  data = new dataValues();

  cp5 = new ControlP5(this);  

  cf1 = new ControlFont(createFont("Roboto-Regular.ttf", 48, true), 48);

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

  cp5.addScrollableList("animationSelection")
    .setPosition(100, 100)
    .setSize(800, 1500)
    .setBarHeight(100)
    .setItemHeight(100)
    .addItems(animations)
    .setFont(cf1)
    .setOpen(false)
    .setLabel("Choose Animation");


  cp5.addScrollableList("colorSelection")
    .setPosition(1000, 100)
    .setSize(800, 400)
    .setBarHeight(100)
    .setItemHeight(100)
    .addItems(colors)
    .setFont(cf1)
    .setOpen(false)
    ;

  cp5.addButton("Print")
    .setPosition(1500, 1750)
    .setSize(400, 100)
    .setFont(cf1)
    ;


  cp5.addColorWheel("Choose Color", 1500, 400, 800).setFont(cf1);
}

void draw() {
  background(100);

  if (currentSelectingColor == 1) {

    data.color1 = cp5.get(ColorWheel.class, "Choose Color").r();
  } else if (currentSelectingColor == 2) {

    data.color2 = cp5.get(ColorWheel.class, "Choose Color").r();

  }
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


void animationSelection(int n) {

  println(cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") + " Animation Selected");

  if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Alternate") {
    data.currentAnimation = animation.Alternate;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Pixel Red") {
    data.currentAnimation = animation.Fade_Pixel_Red;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Pixel Green") {
    data.currentAnimation = animation.Fade_Pixel_Green;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Pixel Blue") {
    data.currentAnimation = animation.Fade_Pixel_Blue;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Pixel All") {
    data.currentAnimation = animation.Fade_Pixel_All;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Pixel Red") {
    data.currentAnimation = animation.Fade_Strip_Red;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Pixel Green") {
    data.currentAnimation = animation.Fade_Strip_Green;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Pixel Blue") {
    data.currentAnimation = animation.Fade_Strip_Blue;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Pixel All") {
    data.currentAnimation = animation.Fade_Strip_All;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Multi-Pixel Run") {
    data.currentAnimation = animation.Multi_Pixel_Run;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Smooth Chase") {
    data.currentAnimation = animation.Smooth_Chase;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Wipe") {
    data.currentAnimation = animation.Wipe;
  }
}
