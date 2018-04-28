import controlP5.*;
import java.util.*;


ControlP5 cp5;
ControlFont cf1;



void setup() {
  size(3000, 3000);
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
  
  cp5.addScrollableList("animationSelection")
     .setPosition(100, 100)
     .setSize(800, 1500)
     .setBarHeight(100)
     .setItemHeight(100)
     .addItems(animations)
     .setFont(cf1)
     .setOpen(false)
     .setLabel("Choose Animation");
     

     
   cp5.addColorWheel("Choose Color", 1500, 400, 800).setFont(cf1);
     
}

void draw() {
  background(100);
}

void animationSelection(int n) {
  //println(n, cp5.get(ScrollableList.class, "animationSelection").getItem(n));
  println(cp5.get(ScrollableList.class, "animationSelection").getItem(n).get("name") + " Animation Selected");
  
  ///* here an item is stored as a Map  with the following key-value pairs:
  // * name, the given name of the item
  // * text, the given text of the item by default the same as name
  // * value, the given value of the item, can be changed by using .getItem(n).put("value", "abc"); a value here is of type Object therefore can be anything
  // * color, the given color of the item, how to change, see below
  // * view, a customizable view, is of type CDrawable 
  // */
  
}
