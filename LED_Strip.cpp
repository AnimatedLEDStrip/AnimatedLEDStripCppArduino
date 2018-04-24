#include "LED_Strip.h"
#include <inttypes.h>

using namespace std;


/** Constructor for the LEDStrip Class
	Because of the Arduino's requirement that pin numbers be defined at compile, if-else-if statements are used to permit passing of a pin as a parameter from the .ino file
	@param numLEDs Number of LEDs in the strip
	@param pin The pin connected to the strip */

LEDStrip::LEDStrip( int numLEDs, int pin ) {

	pixelCount = numLEDs;															// Save numLEDs to pixelCount
	ledArray = new CRGB[numLEDs];													// Allocate new array of CRGB (pixels)

	if		(pin == 0)	FastLED.addLeds<NEOPIXEL, PIN0>	( ledArray, numLEDs );		// If pin == #, use PIN#
	else if (pin == 1)	FastLED.addLeds<NEOPIXEL, PIN1>	( ledArray, numLEDs );
	else if (pin == 2)	FastLED.addLeds<NEOPIXEL, PIN2>	( ledArray, numLEDs );
	else if (pin == 3)	FastLED.addLeds<NEOPIXEL, PIN3>	( ledArray, numLEDs );
	else if (pin == 4)	FastLED.addLeds<NEOPIXEL, PIN4>	( ledArray, numLEDs );
	else if (pin == 5)	FastLED.addLeds<NEOPIXEL, PIN5>	( ledArray, numLEDs );
	else if (pin == 6)	FastLED.addLeds<NEOPIXEL, PIN6>	( ledArray, numLEDs );
	else if (pin == 7)	FastLED.addLeds<NEOPIXEL, PIN7>	( ledArray, numLEDs );
	else if (pin == 8)	FastLED.addLeds<NEOPIXEL, PIN8>	( ledArray, numLEDs );
	else if (pin == 9)	FastLED.addLeds<NEOPIXEL, PIN9>	( ledArray, numLEDs );
	else if (pin == 10) FastLED.addLeds<NEOPIXEL, PIN10>( ledArray, numLEDs );
	else if (pin == 11) FastLED.addLeds<NEOPIXEL, PIN11>( ledArray, numLEDs );
	else if (pin == 12) FastLED.addLeds<NEOPIXEL, PIN12>( ledArray, numLEDs );
	else if (pin == 13) FastLED.addLeds<NEOPIXEL, PIN13>( ledArray, numLEDs );
	else if (pin == 14) FastLED.addLeds<NEOPIXEL, PIN14>( ledArray, numLEDs );
	else if (pin == 15) FastLED.addLeds<NEOPIXEL, PIN15>( ledArray, numLEDs );
	else if (pin == 16) FastLED.addLeds<NEOPIXEL, PIN16>( ledArray, numLEDs );
	else if (pin == 17) FastLED.addLeds<NEOPIXEL, PIN17>( ledArray, numLEDs );
	else if (pin == 18) FastLED.addLeds<NEOPIXEL, PIN18>( ledArray, numLEDs );
	else if (pin == 19) FastLED.addLeds<NEOPIXEL, PIN19>( ledArray, numLEDs );
	else if (pin == 20) FastLED.addLeds<NEOPIXEL, PIN20>( ledArray, numLEDs );
	else if (pin == 21) FastLED.addLeds<NEOPIXEL, PIN21>( ledArray, numLEDs );
	else if (pin == 22) FastLED.addLeds<NEOPIXEL, PIN22>( ledArray, numLEDs );
	else if (pin == 23) FastLED.addLeds<NEOPIXEL, PIN23>( ledArray, numLEDs );
	else if (pin == 24) FastLED.addLeds<NEOPIXEL, PIN24>( ledArray, numLEDs );
	else if (pin == 25) FastLED.addLeds<NEOPIXEL, PIN25>( ledArray, numLEDs );
	else if (pin == 26) FastLED.addLeds<NEOPIXEL, PIN26>( ledArray, numLEDs );
	else if (pin == 27) FastLED.addLeds<NEOPIXEL, PIN27>( ledArray, numLEDs );
	else if (pin == 28) FastLED.addLeds<NEOPIXEL, PIN28>( ledArray, numLEDs );
	else if (pin == 29) FastLED.addLeds<NEOPIXEL, PIN29>( ledArray, numLEDs );
	else if (pin == 30) FastLED.addLeds<NEOPIXEL, PIN30>( ledArray, numLEDs );
	else if (pin == 31) FastLED.addLeds<NEOPIXEL, PIN31>( ledArray, numLEDs );
	else if (pin == 32) FastLED.addLeds<NEOPIXEL, PIN32>( ledArray, numLEDs );
	else if (pin == 33) FastLED.addLeds<NEOPIXEL, PIN33>( ledArray, numLEDs );
	else if (pin == 34) FastLED.addLeds<NEOPIXEL, PIN34>( ledArray, numLEDs );
	else if (pin == 35) FastLED.addLeds<NEOPIXEL, PIN35>( ledArray, numLEDs );
	else if (pin == 36) FastLED.addLeds<NEOPIXEL, PIN36>( ledArray, numLEDs );
	else if (pin == 37) FastLED.addLeds<NEOPIXEL, PIN37>( ledArray, numLEDs );
	else if (pin == 38) FastLED.addLeds<NEOPIXEL, PIN38>( ledArray, numLEDs );
	else if (pin == 39) FastLED.addLeds<NEOPIXEL, PIN39>( ledArray, numLEDs );
	else if (pin == 40) FastLED.addLeds<NEOPIXEL, PIN40>( ledArray, numLEDs );
	else if (pin == 41) FastLED.addLeds<NEOPIXEL, PIN41>( ledArray, numLEDs );
	else if (pin == 42) FastLED.addLeds<NEOPIXEL, PIN42>( ledArray, numLEDs );
	else if (pin == 43) FastLED.addLeds<NEOPIXEL, PIN43>( ledArray, numLEDs );
	else if (pin == 44) FastLED.addLeds<NEOPIXEL, PIN44>( ledArray, numLEDs );
	else if (pin == 45) FastLED.addLeds<NEOPIXEL, PIN45>( ledArray, numLEDs );
	else if (pin == 46) FastLED.addLeds<NEOPIXEL, PIN46>( ledArray, numLEDs );
	else if (pin == 47) FastLED.addLeds<NEOPIXEL, PIN47>( ledArray, numLEDs );
	else if (pin == 48) FastLED.addLeds<NEOPIXEL, PIN48>( ledArray, numLEDs );
	else if (pin == 49) FastLED.addLeds<NEOPIXEL, PIN49>( ledArray, numLEDs );
	else if (pin == 50) FastLED.addLeds<NEOPIXEL, PIN50>( ledArray, numLEDs );
	else if (pin == 51) FastLED.addLeds<NEOPIXEL, PIN51>( ledArray, numLEDs );
	else if (pin == 52) FastLED.addLeds<NEOPIXEL, PIN52>( ledArray, numLEDs );
	else if (pin == 53) FastLED.addLeds<NEOPIXEL, PIN53>( ledArray, numLEDs );

}

LEDStrip::LEDStrip(const LEDStrip& StripIn){

	pixelCount = StripIn.pixelCount;
	pin = StripIn.pin;
														// Save numLEDs to pixelCount
	ledArray = new CRGB[pixelCount];													// Allocate new array of CRGB (pixels)

	if		(pin == 0)	FastLED.addLeds<NEOPIXEL, PIN0>	( ledArray, numLEDs );		// If pin == #, use PIN#
	else if (pin == 1)	FastLED.addLeds<NEOPIXEL, PIN1>	( ledArray, numLEDs );
	else if (pin == 2)	FastLED.addLeds<NEOPIXEL, PIN2>	( ledArray, numLEDs );
	else if (pin == 3)	FastLED.addLeds<NEOPIXEL, PIN3>	( ledArray, numLEDs );
	else if (pin == 4)	FastLED.addLeds<NEOPIXEL, PIN4>	( ledArray, numLEDs );
	else if (pin == 5)	FastLED.addLeds<NEOPIXEL, PIN5>	( ledArray, numLEDs );
	else if (pin == 6)	FastLED.addLeds<NEOPIXEL, PIN6>	( ledArray, numLEDs );
	else if (pin == 7)	FastLED.addLeds<NEOPIXEL, PIN7>	( ledArray, numLEDs );
	else if (pin == 8)	FastLED.addLeds<NEOPIXEL, PIN8>	( ledArray, numLEDs );
	else if (pin == 9)	FastLED.addLeds<NEOPIXEL, PIN9>	( ledArray, numLEDs );
	else if (pin == 10) FastLED.addLeds<NEOPIXEL, PIN10>( ledArray, numLEDs );
	else if (pin == 11) FastLED.addLeds<NEOPIXEL, PIN11>( ledArray, numLEDs );
	else if (pin == 12) FastLED.addLeds<NEOPIXEL, PIN12>( ledArray, numLEDs );
	else if (pin == 13) FastLED.addLeds<NEOPIXEL, PIN13>( ledArray, numLEDs );
	else if (pin == 14) FastLED.addLeds<NEOPIXEL, PIN14>( ledArray, numLEDs );
	else if (pin == 15) FastLED.addLeds<NEOPIXEL, PIN15>( ledArray, numLEDs );
	else if (pin == 16) FastLED.addLeds<NEOPIXEL, PIN16>( ledArray, numLEDs );
	else if (pin == 17) FastLED.addLeds<NEOPIXEL, PIN17>( ledArray, numLEDs );
	else if (pin == 18) FastLED.addLeds<NEOPIXEL, PIN18>( ledArray, numLEDs );
	else if (pin == 19) FastLED.addLeds<NEOPIXEL, PIN19>( ledArray, numLEDs );
	else if (pin == 20) FastLED.addLeds<NEOPIXEL, PIN20>( ledArray, numLEDs );
	else if (pin == 21) FastLED.addLeds<NEOPIXEL, PIN21>( ledArray, numLEDs );
	else if (pin == 22) FastLED.addLeds<NEOPIXEL, PIN22>( ledArray, numLEDs );
	else if (pin == 23) FastLED.addLeds<NEOPIXEL, PIN23>( ledArray, numLEDs );
	else if (pin == 24) FastLED.addLeds<NEOPIXEL, PIN24>( ledArray, numLEDs );
	else if (pin == 25) FastLED.addLeds<NEOPIXEL, PIN25>( ledArray, numLEDs );
	else if (pin == 26) FastLED.addLeds<NEOPIXEL, PIN26>( ledArray, numLEDs );
	else if (pin == 27) FastLED.addLeds<NEOPIXEL, PIN27>( ledArray, numLEDs );
	else if (pin == 28) FastLED.addLeds<NEOPIXEL, PIN28>( ledArray, numLEDs );
	else if (pin == 29) FastLED.addLeds<NEOPIXEL, PIN29>( ledArray, numLEDs );
	else if (pin == 30) FastLED.addLeds<NEOPIXEL, PIN30>( ledArray, numLEDs );
	else if (pin == 31) FastLED.addLeds<NEOPIXEL, PIN31>( ledArray, numLEDs );
	else if (pin == 32) FastLED.addLeds<NEOPIXEL, PIN32>( ledArray, numLEDs );
	else if (pin == 33) FastLED.addLeds<NEOPIXEL, PIN33>( ledArray, numLEDs );
	else if (pin == 34) FastLED.addLeds<NEOPIXEL, PIN34>( ledArray, numLEDs );
	else if (pin == 35) FastLED.addLeds<NEOPIXEL, PIN35>( ledArray, numLEDs );
	else if (pin == 36) FastLED.addLeds<NEOPIXEL, PIN36>( ledArray, numLEDs );
	else if (pin == 37) FastLED.addLeds<NEOPIXEL, PIN37>( ledArray, numLEDs );
	else if (pin == 38) FastLED.addLeds<NEOPIXEL, PIN38>( ledArray, numLEDs );
	else if (pin == 39) FastLED.addLeds<NEOPIXEL, PIN39>( ledArray, numLEDs );
	else if (pin == 40) FastLED.addLeds<NEOPIXEL, PIN40>( ledArray, numLEDs );
	else if (pin == 41) FastLED.addLeds<NEOPIXEL, PIN41>( ledArray, numLEDs );
	else if (pin == 42) FastLED.addLeds<NEOPIXEL, PIN42>( ledArray, numLEDs );
	else if (pin == 43) FastLED.addLeds<NEOPIXEL, PIN43>( ledArray, numLEDs );
	else if (pin == 44) FastLED.addLeds<NEOPIXEL, PIN44>( ledArray, numLEDs );
	else if (pin == 45) FastLED.addLeds<NEOPIXEL, PIN45>( ledArray, numLEDs );
	else if (pin == 46) FastLED.addLeds<NEOPIXEL, PIN46>( ledArray, numLEDs );
	else if (pin == 47) FastLED.addLeds<NEOPIXEL, PIN47>( ledArray, numLEDs );
	else if (pin == 48) FastLED.addLeds<NEOPIXEL, PIN48>( ledArray, numLEDs );
	else if (pin == 49) FastLED.addLeds<NEOPIXEL, PIN49>( ledArray, numLEDs );
	else if (pin == 50) FastLED.addLeds<NEOPIXEL, PIN50>( ledArray, numLEDs );
	else if (pin == 51) FastLED.addLeds<NEOPIXEL, PIN51>( ledArray, numLEDs );
	else if (pin == 52) FastLED.addLeds<NEOPIXEL, PIN52>( ledArray, numLEDs );
	else if (pin == 53) FastLED.addLeds<NEOPIXEL, PIN53>( ledArray, numLEDs );


}

LEDStrip::~LEDStrip(){
	delete[] ledArray;
}

LEDStrip& LEDStrip::operator=(const LEDStrip& StripIn){

		delete[] ledArray;
		pixelCount = StripIn.pixelCount;
		pin = StripIn.pin;
															// Save numLEDs to pixelCount
		ledArray = new CRGB[pixelCount];													// Allocate new array of CRGB (pixels)

		if		(pin == 0)	FastLED.addLeds<NEOPIXEL, PIN0>	( ledArray, numLEDs );		// If pin == #, use PIN#
		else if (pin == 1)	FastLED.addLeds<NEOPIXEL, PIN1>	( ledArray, numLEDs );
		else if (pin == 2)	FastLED.addLeds<NEOPIXEL, PIN2>	( ledArray, numLEDs );
		else if (pin == 3)	FastLED.addLeds<NEOPIXEL, PIN3>	( ledArray, numLEDs );
		else if (pin == 4)	FastLED.addLeds<NEOPIXEL, PIN4>	( ledArray, numLEDs );
		else if (pin == 5)	FastLED.addLeds<NEOPIXEL, PIN5>	( ledArray, numLEDs );
		else if (pin == 6)	FastLED.addLeds<NEOPIXEL, PIN6>	( ledArray, numLEDs );
		else if (pin == 7)	FastLED.addLeds<NEOPIXEL, PIN7>	( ledArray, numLEDs );
		else if (pin == 8)	FastLED.addLeds<NEOPIXEL, PIN8>	( ledArray, numLEDs );
		else if (pin == 9)	FastLED.addLeds<NEOPIXEL, PIN9>	( ledArray, numLEDs );
		else if (pin == 10) FastLED.addLeds<NEOPIXEL, PIN10>( ledArray, numLEDs );
		else if (pin == 11) FastLED.addLeds<NEOPIXEL, PIN11>( ledArray, numLEDs );
		else if (pin == 12) FastLED.addLeds<NEOPIXEL, PIN12>( ledArray, numLEDs );
		else if (pin == 13) FastLED.addLeds<NEOPIXEL, PIN13>( ledArray, numLEDs );
		else if (pin == 14) FastLED.addLeds<NEOPIXEL, PIN14>( ledArray, numLEDs );
		else if (pin == 15) FastLED.addLeds<NEOPIXEL, PIN15>( ledArray, numLEDs );
		else if (pin == 16) FastLED.addLeds<NEOPIXEL, PIN16>( ledArray, numLEDs );
		else if (pin == 17) FastLED.addLeds<NEOPIXEL, PIN17>( ledArray, numLEDs );
		else if (pin == 18) FastLED.addLeds<NEOPIXEL, PIN18>( ledArray, numLEDs );
		else if (pin == 19) FastLED.addLeds<NEOPIXEL, PIN19>( ledArray, numLEDs );
		else if (pin == 20) FastLED.addLeds<NEOPIXEL, PIN20>( ledArray, numLEDs );
		else if (pin == 21) FastLED.addLeds<NEOPIXEL, PIN21>( ledArray, numLEDs );
		else if (pin == 22) FastLED.addLeds<NEOPIXEL, PIN22>( ledArray, numLEDs );
		else if (pin == 23) FastLED.addLeds<NEOPIXEL, PIN23>( ledArray, numLEDs );
		else if (pin == 24) FastLED.addLeds<NEOPIXEL, PIN24>( ledArray, numLEDs );
		else if (pin == 25) FastLED.addLeds<NEOPIXEL, PIN25>( ledArray, numLEDs );
		else if (pin == 26) FastLED.addLeds<NEOPIXEL, PIN26>( ledArray, numLEDs );
		else if (pin == 27) FastLED.addLeds<NEOPIXEL, PIN27>( ledArray, numLEDs );
		else if (pin == 28) FastLED.addLeds<NEOPIXEL, PIN28>( ledArray, numLEDs );
		else if (pin == 29) FastLED.addLeds<NEOPIXEL, PIN29>( ledArray, numLEDs );
		else if (pin == 30) FastLED.addLeds<NEOPIXEL, PIN30>( ledArray, numLEDs );
		else if (pin == 31) FastLED.addLeds<NEOPIXEL, PIN31>( ledArray, numLEDs );
		else if (pin == 32) FastLED.addLeds<NEOPIXEL, PIN32>( ledArray, numLEDs );
		else if (pin == 33) FastLED.addLeds<NEOPIXEL, PIN33>( ledArray, numLEDs );
		else if (pin == 34) FastLED.addLeds<NEOPIXEL, PIN34>( ledArray, numLEDs );
		else if (pin == 35) FastLED.addLeds<NEOPIXEL, PIN35>( ledArray, numLEDs );
		else if (pin == 36) FastLED.addLeds<NEOPIXEL, PIN36>( ledArray, numLEDs );
		else if (pin == 37) FastLED.addLeds<NEOPIXEL, PIN37>( ledArray, numLEDs );
		else if (pin == 38) FastLED.addLeds<NEOPIXEL, PIN38>( ledArray, numLEDs );
		else if (pin == 39) FastLED.addLeds<NEOPIXEL, PIN39>( ledArray, numLEDs );
		else if (pin == 40) FastLED.addLeds<NEOPIXEL, PIN40>( ledArray, numLEDs );
		else if (pin == 41) FastLED.addLeds<NEOPIXEL, PIN41>( ledArray, numLEDs );
		else if (pin == 42) FastLED.addLeds<NEOPIXEL, PIN42>( ledArray, numLEDs );
		else if (pin == 43) FastLED.addLeds<NEOPIXEL, PIN43>( ledArray, numLEDs );
		else if (pin == 44) FastLED.addLeds<NEOPIXEL, PIN44>( ledArray, numLEDs );
		else if (pin == 45) FastLED.addLeds<NEOPIXEL, PIN45>( ledArray, numLEDs );
		else if (pin == 46) FastLED.addLeds<NEOPIXEL, PIN46>( ledArray, numLEDs );
		else if (pin == 47) FastLED.addLeds<NEOPIXEL, PIN47>( ledArray, numLEDs );
		else if (pin == 48) FastLED.addLeds<NEOPIXEL, PIN48>( ledArray, numLEDs );
		else if (pin == 49) FastLED.addLeds<NEOPIXEL, PIN49>( ledArray, numLEDs );
		else if (pin == 50) FastLED.addLeds<NEOPIXEL, PIN50>( ledArray, numLEDs );
		else if (pin == 51) FastLED.addLeds<NEOPIXEL, PIN51>( ledArray, numLEDs );
		else if (pin == 52) FastLED.addLeds<NEOPIXEL, PIN52>( ledArray, numLEDs );
		else if (pin == 53) FastLED.addLeds<NEOPIXEL, PIN53>( ledArray, numLEDs );

		return *this;

}

/**	Set Method for the LEDStrip class
	Sets the color of a single pixel to the color stored in a ColorContainer object
	@param pixel The index of the pixel to be changed
	@param colorValues The ColorContainer containing the desired color */

void LEDStrip::setPixelColor( int pixel, ColorContainer colorValues ) {

	ledArray[pixel] = CRGB( colorValues.getr(), colorValues.getg(), colorValues.getb() );
	return;

}


/**	Set Method for the LEDStrip class
	Sets the color of a single pixel to the specified colors
	@param pixel The index of the pixel to be changed
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void LEDStrip::setPixelColor( int pixel, int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	setPixelColor( pixel, temp );

	return;

}

/**     Set Method for the LEDStrip class
	Sets the value of the red value of a single pixel to the specified value
	@param pixel The index of the pixel to be changed
	@param rIn The value for the red LED */

void LEDStrip::setPixelRed( int pixel, int rIn){

  ledArray[pixel].red = rIn;
  return;
}

/**     Set Method for the LEDStrip class
        Sets the value of the green value of a single pixel to the specified value
        @param pixel The index of the pixel to be changed
        @param gIn The value for the green LED */

void LEDStrip::setPixelGreen( int pixel, int gIn){

  ledArray[pixel].green = gIn;
  return;
}

/**     Set Method for the LEDStrip class
        Sets the value of the blue value of a single pixel to the specified value
        @param pixel The index of the pixel to be changed
        @param bIn The value for the blue LED */

void LEDStrip::setPixelBlue( int pixel, int bIn){
  
  ledArray[pixel].blue = bIn;
  return;
}

/**	Set Method for the LEDStrip class
	Sets the color of all pixels in a strip to the color stored in a ColorContainer object
	@param colorValues The ColorContainer containing the desired color */

void LEDStrip::setStripColor( ColorContainer colorValues ) {

	fill_solid( ledArray, getPixelCount(), CRGB( colorValues.getr(), colorValues.getg(), colorValues.getb() ) );

	return;

}


/**	Set Method for the LEDStrip class
	Sets the color of all pixels in a strip to the specified colors
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void LEDStrip::setStripColor( int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	setStripColor( temp );

	return;

}

/**     Set Method for the LEDStrip class
        Sets the color of all red values in a strip to the color stored in an int
        @param rIn*/

void LEDStrip::setStripRed( int rIn ) {

  for( int i = 0; i < getPixelCount(); i++) leds[i].red = rIn;
  return;
}

/**     Set Method for the LEDStrip class
        Sets the color of all green values in a strip to the color stored in an int
        @param gIn*/

void LEDStrip::setStripGreen( int gIn ) {

  for( int i = 0; i < getPixelCount(); i++) leds[i].green = gIn;
  return;
}

/**     Set Method for the LEDStrip class
        Sets the color of all blue values in a strip to the color stored in an int
        @param bIn*/

void LEDStrip::setStripBlue( int bIn ) {

  for( int i = 0; i < getPixelCount(); i++) leds[i].blue = bIn;
  return;
}

/**	Fills a LED strip with colors from a specified RGB color palette
	@param palette The RGB palette to be used
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const TProgmemRGBPalette16& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) { //TODO: Add support for other palette sizes

	/*for (int i = 0; i < getPixelCount(); i++) {										// Loop through all pixels

		ledArray[i] = ColorFromPalette( palette, startIndex, brightness, blend );	// Set pixel to specified colors
		startIndex += 3;															// Move to next set of colors

	}
	*/

	fillLEDsFromPalette<TProgmemRGBPalette16>( palette, startIndex, blend, brightness );

	return;																			// Return


}


template<class paletteType>
void LEDStrip::fillLEDsFromPalette( const paletteType& palette, uint8_t startIndex, TBlendType blend, uint8_t brightness ) {

	for (int i = 0; i < getPixelCount(); i++) {										// Loop through all pixels

		ledArray[i] = ColorFromPalette( palette, startIndex, brightness, blend );	// Set pixel to specified colors
		startIndex += 3;															// Move to next set of colors

	}

	return;																			// Return

}




/**	Get Method for the pixelCount variable in the LEDStrip class
	Returns the number of pixels in a strip
	@return pixelCount */

int LEDStrip::getPixelCount() { return pixelCount; }

ColorContainer LEDStrip::getPixelColor( int pixelIn ) {
	return ColorContainer( ledArray[pixelIn].r, ledArray[pixelIn].g, ledArray[pixelIn].b );
}


/**	Get Method for the red value in an Adafruit_NeoPixel pixel
	Returns the red value of the specified pixel
	@param pixelIn The specified pixel
	@return The red value of the specified pixel */

int LEDStrip::getPixelRed( int pixelIn ) { return ledArray[pixelIn].r; }


/**	Get Method for the green value in an Adafruit_NeoPixel pixel
	Returns the green value of the specified pixel
	@param pixelIn The specified pixel
	@return The green value of the specified pixel */

int LEDStrip::getPixelGreen( int pixelIn ) { return ledArray[pixelIn].g; }


/**	Get Method for the blue value in an Adafruit_NeoPixel pixel
	Returns the blue value of the specified pixel
	@param pixelIn The specified pixel
	@return The blue value of the specified pixel */

int LEDStrip::getPixelBlue( int pixelIn ) { return ledArray[pixelIn].b; }
