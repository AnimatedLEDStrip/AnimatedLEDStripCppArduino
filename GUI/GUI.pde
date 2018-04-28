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
  size(2000, 1500);

  data = new dataValues();

  cp5 = new ControlP5(this);  

  cf1 = new ControlFont(createFont("Roboto-Regular.ttf", int(height * 0.032), true), int(height * 0.032));

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
    .setPosition(width * 0.033, height * 0.05)
    .setSize(int(width * 0.267), int(height * 0.75))
    .setBarHeight(int(height * 0.05))
    .setItemHeight(int(height * 0.05))
    .addItems(animations)
    .setFont(cf1)
    .setOpen(false)
    .setLabel("Choose Animation");


  cp5.addScrollableList("colorSelection")
    .setPosition(width * 0.333, height * 0.05)
    .setSize(int(width * 0.267), int(height * 0.2))
    .setBarHeight(int(height * 0.05))
    .setItemHeight(int(height * 0.05))
    .addItems(colors)
    .setFont(cf1)
    .setOpen(false)
    ;

  cp5.addButton("Print")
    .setPosition(width * 0.5, height * 0.875)
    .setSize(int(width * 0.2), int(height * 0.05))
    .setFont(cf1)
    ;


  cp5.addColorWheel("Choose Color", int(width * 0.5), int (height * 0.2), int(width * 0.2)).setFont(cf1);
}

void draw() {
  background(100);

  if (currentSelectingColor == 1) {

    data.color1 = cp5.get(ColorWheel.class, "Choose Color").getRGB();
  } else if (currentSelectingColor == 2) {

    data.color2 = cp5.get(ColorWheel.class, "Choose Color").getRGB();
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
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Strip Red") {
    data.currentAnimation = animation.Fade_Strip_Red;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Strip Green") {
    data.currentAnimation = animation.Fade_Strip_Green;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Strip Blue") {
    data.currentAnimation = animation.Fade_Strip_Blue;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Fade Strip All") {
    data.currentAnimation = animation.Fade_Strip_All;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Multi-Pixel Run") {
    data.currentAnimation = animation.Multi_Pixel_Run;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Smooth Chase") {
    data.currentAnimation = animation.Smooth_Chase;
  } else if (cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") == "Wipe") {
    data.currentAnimation = animation.Wipe;
  }
}
