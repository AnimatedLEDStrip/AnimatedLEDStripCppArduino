#include "LED_Strip.h"
#include <inttypes.h>

using namespace std;


/** Constructor for the LEDStrip Class
	Because of the Arduino's requirement that pin numbers be defined at compile, if-else-if statements are used to permit passing of a pin as a parameter from the .ino file
	@param numLEDs Number of LEDs in the strip
	@param pin The pin connected to the strip */

LEDStrip::LEDStrip( int numLEDs, int pinIn ) {

	pixelCount = numLEDs;															// Save numLEDs to pixelCount
	ledArray = new CRGB[numLEDs];													// Allocate new array of CRGB (pixels)
	pin = pinIn;

	if (pin == 0)	FastLED.addLeds<NEOPIXEL, PIN0>( ledArray, numLEDs );		// If pin == #, use PIN#
	else if (pin == 1)	FastLED.addLeds<NEOPIXEL, PIN1>( ledArray, numLEDs );
	else if (pin == 2)	FastLED.addLeds<NEOPIXEL, PIN2>( ledArray, numLEDs );
	else if (pin == 3)	FastLED.addLeds<NEOPIXEL, PIN3>( ledArray, numLEDs );
	else if (pin == 4)	FastLED.addLeds<NEOPIXEL, PIN4>( ledArray, numLEDs );
	else if (pin == 5)	FastLED.addLeds<NEOPIXEL, PIN5>( ledArray, numLEDs );
	else if (pin == 6)	FastLED.addLeds<NEOPIXEL, PIN6>( ledArray, numLEDs );
	else if (pin == 7)	FastLED.addLeds<NEOPIXEL, PIN7>( ledArray, numLEDs );
	else if (pin == 8)	FastLED.addLeds<NEOPIXEL, PIN8>( ledArray, numLEDs );
	else if (pin == 9)	FastLED.addLeds<NEOPIXEL, PIN9>( ledArray, numLEDs );
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


/** Copy Constructor for the LEDStrip Class
	Because of the Arduino's requirement that pin numbers be defined at compile, if-else-if statements are used to permit passing of a pin as a parameter from the .ino file
	@param stripIn The LEDStrip instance to be copied to the new LEDStrip */

LEDStrip::LEDStrip( const LEDStrip& stripIn ) {

	pixelCount = stripIn.pixelCount;											// Save stripIn.pixelCount to pixelCount
	ledArray = new CRGB[pixelCount];											// Allocate new array of CRGB (pixels)
	pin = stripIn.pin;

	for (int i = 0; i < pixelCount; i++)
		ledArray[i] = stripIn.ledArray[i];

	if (pin == 0)	FastLED.addLeds<NEOPIXEL, PIN0>( ledArray, pixelCount );		// If pin == #, use PIN#
	else if (pin == 1)	FastLED.addLeds<NEOPIXEL, PIN1>( ledArray, pixelCount );
	else if (pin == 2)	FastLED.addLeds<NEOPIXEL, PIN2>( ledArray, pixelCount );
	else if (pin == 3)	FastLED.addLeds<NEOPIXEL, PIN3>( ledArray, pixelCount );
	else if (pin == 4)	FastLED.addLeds<NEOPIXEL, PIN4>( ledArray, pixelCount );
	else if (pin == 5)	FastLED.addLeds<NEOPIXEL, PIN5>( ledArray, pixelCount );
	else if (pin == 6)	FastLED.addLeds<NEOPIXEL, PIN6>( ledArray, pixelCount );
	else if (pin == 7)	FastLED.addLeds<NEOPIXEL, PIN7>( ledArray, pixelCount );
	else if (pin == 8)	FastLED.addLeds<NEOPIXEL, PIN8>( ledArray, pixelCount );
	else if (pin == 9)	FastLED.addLeds<NEOPIXEL, PIN9>( ledArray, pixelCount );
	else if (pin == 10) FastLED.addLeds<NEOPIXEL, PIN10>( ledArray, pixelCount );
	else if (pin == 11) FastLED.addLeds<NEOPIXEL, PIN11>( ledArray, pixelCount );
	else if (pin == 12) FastLED.addLeds<NEOPIXEL, PIN12>( ledArray, pixelCount );
	else if (pin == 13) FastLED.addLeds<NEOPIXEL, PIN13>( ledArray, pixelCount );
	else if (pin == 14) FastLED.addLeds<NEOPIXEL, PIN14>( ledArray, pixelCount );
	else if (pin == 15) FastLED.addLeds<NEOPIXEL, PIN15>( ledArray, pixelCount );
	else if (pin == 16) FastLED.addLeds<NEOPIXEL, PIN16>( ledArray, pixelCount );
	else if (pin == 17) FastLED.addLeds<NEOPIXEL, PIN17>( ledArray, pixelCount );
	else if (pin == 18) FastLED.addLeds<NEOPIXEL, PIN18>( ledArray, pixelCount );
	else if (pin == 19) FastLED.addLeds<NEOPIXEL, PIN19>( ledArray, pixelCount );
	else if (pin == 20) FastLED.addLeds<NEOPIXEL, PIN20>( ledArray, pixelCount );
	else if (pin == 21) FastLED.addLeds<NEOPIXEL, PIN21>( ledArray, pixelCount );
	else if (pin == 22) FastLED.addLeds<NEOPIXEL, PIN22>( ledArray, pixelCount );
	else if (pin == 23) FastLED.addLeds<NEOPIXEL, PIN23>( ledArray, pixelCount );
	else if (pin == 24) FastLED.addLeds<NEOPIXEL, PIN24>( ledArray, pixelCount );
	else if (pin == 25) FastLED.addLeds<NEOPIXEL, PIN25>( ledArray, pixelCount );
	else if (pin == 26) FastLED.addLeds<NEOPIXEL, PIN26>( ledArray, pixelCount );
	else if (pin == 27) FastLED.addLeds<NEOPIXEL, PIN27>( ledArray, pixelCount );
	else if (pin == 28) FastLED.addLeds<NEOPIXEL, PIN28>( ledArray, pixelCount );
	else if (pin == 29) FastLED.addLeds<NEOPIXEL, PIN29>( ledArray, pixelCount );
	else if (pin == 30) FastLED.addLeds<NEOPIXEL, PIN30>( ledArray, pixelCount );
	else if (pin == 31) FastLED.addLeds<NEOPIXEL, PIN31>( ledArray, pixelCount );
	else if (pin == 32) FastLED.addLeds<NEOPIXEL, PIN32>( ledArray, pixelCount );
	else if (pin == 33) FastLED.addLeds<NEOPIXEL, PIN33>( ledArray, pixelCount );
	else if (pin == 34) FastLED.addLeds<NEOPIXEL, PIN34>( ledArray, pixelCount );
	else if (pin == 35) FastLED.addLeds<NEOPIXEL, PIN35>( ledArray, pixelCount );
	else if (pin == 36) FastLED.addLeds<NEOPIXEL, PIN36>( ledArray, pixelCount );
	else if (pin == 37) FastLED.addLeds<NEOPIXEL, PIN37>( ledArray, pixelCount );
	else if (pin == 38) FastLED.addLeds<NEOPIXEL, PIN38>( ledArray, pixelCount );
	else if (pin == 39) FastLED.addLeds<NEOPIXEL, PIN39>( ledArray, pixelCount );
	else if (pin == 40) FastLED.addLeds<NEOPIXEL, PIN40>( ledArray, pixelCount );
	else if (pin == 41) FastLED.addLeds<NEOPIXEL, PIN41>( ledArray, pixelCount );
	else if (pin == 42) FastLED.addLeds<NEOPIXEL, PIN42>( ledArray, pixelCount );
	else if (pin == 43) FastLED.addLeds<NEOPIXEL, PIN43>( ledArray, pixelCount );
	else if (pin == 44) FastLED.addLeds<NEOPIXEL, PIN44>( ledArray, pixelCount );
	else if (pin == 45) FastLED.addLeds<NEOPIXEL, PIN45>( ledArray, pixelCount );
	else if (pin == 46) FastLED.addLeds<NEOPIXEL, PIN46>( ledArray, pixelCount );
	else if (pin == 47) FastLED.addLeds<NEOPIXEL, PIN47>( ledArray, pixelCount );
	else if (pin == 48) FastLED.addLeds<NEOPIXEL, PIN48>( ledArray, pixelCount );
	else if (pin == 49) FastLED.addLeds<NEOPIXEL, PIN49>( ledArray, pixelCount );
	else if (pin == 50) FastLED.addLeds<NEOPIXEL, PIN50>( ledArray, pixelCount );
	else if (pin == 51) FastLED.addLeds<NEOPIXEL, PIN51>( ledArray, pixelCount );
	else if (pin == 52) FastLED.addLeds<NEOPIXEL, PIN52>( ledArray, pixelCount );
	else if (pin == 53) FastLED.addLeds<NEOPIXEL, PIN53>( ledArray, pixelCount );


}


/**	Destructor for the LEDStrip Class
	Deletes ledArray */

LEDStrip::~LEDStrip() {
	clearData();
	delete[] ledArray;
}


/** Assignment Operator for the LEDStrip Class
	Because of the Arduino's requirement that pin numbers be defined at compile, if-else-if statements are used to permit passing of a pin as a parameter from the .ino file
	@param stripIn The LEDStrip instance to be copied to the invoking LEDStrip instance */

LEDStrip& LEDStrip::operator=( const LEDStrip& stripIn ) {

	delete[] ledArray;
	pixelCount = stripIn.pixelCount;											// Save numLEDs to pixelCount
	ledArray = new CRGB[pixelCount];											// Allocate new array of CRGB (pixels)
	pin = stripIn.pin;

	for (int i = 0; i < pixelCount; i++)
		ledArray[i] = stripIn.ledArray[i];

	if (pin == 0)	FastLED.addLeds<NEOPIXEL, PIN0>( ledArray, pixelCount );		// If pin == #, use PIN#
	else if (pin == 1)	FastLED.addLeds<NEOPIXEL, PIN1>( ledArray, pixelCount );
	else if (pin == 2)	FastLED.addLeds<NEOPIXEL, PIN2>( ledArray, pixelCount );
	else if (pin == 3)	FastLED.addLeds<NEOPIXEL, PIN3>( ledArray, pixelCount );
	else if (pin == 4)	FastLED.addLeds<NEOPIXEL, PIN4>( ledArray, pixelCount );
	else if (pin == 5)	FastLED.addLeds<NEOPIXEL, PIN5>( ledArray, pixelCount );
	else if (pin == 6)	FastLED.addLeds<NEOPIXEL, PIN6>( ledArray, pixelCount );
	else if (pin == 7)	FastLED.addLeds<NEOPIXEL, PIN7>( ledArray, pixelCount );
	else if (pin == 8)	FastLED.addLeds<NEOPIXEL, PIN8>( ledArray, pixelCount );
	else if (pin == 9)	FastLED.addLeds<NEOPIXEL, PIN9>( ledArray, pixelCount );
	else if (pin == 10) FastLED.addLeds<NEOPIXEL, PIN10>( ledArray, pixelCount );
	else if (pin == 11) FastLED.addLeds<NEOPIXEL, PIN11>( ledArray, pixelCount );
	else if (pin == 12) FastLED.addLeds<NEOPIXEL, PIN12>( ledArray, pixelCount );
	else if (pin == 13) FastLED.addLeds<NEOPIXEL, PIN13>( ledArray, pixelCount );
	else if (pin == 14) FastLED.addLeds<NEOPIXEL, PIN14>( ledArray, pixelCount );
	else if (pin == 15) FastLED.addLeds<NEOPIXEL, PIN15>( ledArray, pixelCount );
	else if (pin == 16) FastLED.addLeds<NEOPIXEL, PIN16>( ledArray, pixelCount );
	else if (pin == 17) FastLED.addLeds<NEOPIXEL, PIN17>( ledArray, pixelCount );
	else if (pin == 18) FastLED.addLeds<NEOPIXEL, PIN18>( ledArray, pixelCount );
	else if (pin == 19) FastLED.addLeds<NEOPIXEL, PIN19>( ledArray, pixelCount );
	else if (pin == 20) FastLED.addLeds<NEOPIXEL, PIN20>( ledArray, pixelCount );
	else if (pin == 21) FastLED.addLeds<NEOPIXEL, PIN21>( ledArray, pixelCount );
	else if (pin == 22) FastLED.addLeds<NEOPIXEL, PIN22>( ledArray, pixelCount );
	else if (pin == 23) FastLED.addLeds<NEOPIXEL, PIN23>( ledArray, pixelCount );
	else if (pin == 24) FastLED.addLeds<NEOPIXEL, PIN24>( ledArray, pixelCount );
	else if (pin == 25) FastLED.addLeds<NEOPIXEL, PIN25>( ledArray, pixelCount );
	else if (pin == 26) FastLED.addLeds<NEOPIXEL, PIN26>( ledArray, pixelCount );
	else if (pin == 27) FastLED.addLeds<NEOPIXEL, PIN27>( ledArray, pixelCount );
	else if (pin == 28) FastLED.addLeds<NEOPIXEL, PIN28>( ledArray, pixelCount );
	else if (pin == 29) FastLED.addLeds<NEOPIXEL, PIN29>( ledArray, pixelCount );
	else if (pin == 30) FastLED.addLeds<NEOPIXEL, PIN30>( ledArray, pixelCount );
	else if (pin == 31) FastLED.addLeds<NEOPIXEL, PIN31>( ledArray, pixelCount );
	else if (pin == 32) FastLED.addLeds<NEOPIXEL, PIN32>( ledArray, pixelCount );
	else if (pin == 33) FastLED.addLeds<NEOPIXEL, PIN33>( ledArray, pixelCount );
	else if (pin == 34) FastLED.addLeds<NEOPIXEL, PIN34>( ledArray, pixelCount );
	else if (pin == 35) FastLED.addLeds<NEOPIXEL, PIN35>( ledArray, pixelCount );
	else if (pin == 36) FastLED.addLeds<NEOPIXEL, PIN36>( ledArray, pixelCount );
	else if (pin == 37) FastLED.addLeds<NEOPIXEL, PIN37>( ledArray, pixelCount );
	else if (pin == 38) FastLED.addLeds<NEOPIXEL, PIN38>( ledArray, pixelCount );
	else if (pin == 39) FastLED.addLeds<NEOPIXEL, PIN39>( ledArray, pixelCount );
	else if (pin == 40) FastLED.addLeds<NEOPIXEL, PIN40>( ledArray, pixelCount );
	else if (pin == 41) FastLED.addLeds<NEOPIXEL, PIN41>( ledArray, pixelCount );
	else if (pin == 42) FastLED.addLeds<NEOPIXEL, PIN42>( ledArray, pixelCount );
	else if (pin == 43) FastLED.addLeds<NEOPIXEL, PIN43>( ledArray, pixelCount );
	else if (pin == 44) FastLED.addLeds<NEOPIXEL, PIN44>( ledArray, pixelCount );
	else if (pin == 45) FastLED.addLeds<NEOPIXEL, PIN45>( ledArray, pixelCount );
	else if (pin == 46) FastLED.addLeds<NEOPIXEL, PIN46>( ledArray, pixelCount );
	else if (pin == 47) FastLED.addLeds<NEOPIXEL, PIN47>( ledArray, pixelCount );
	else if (pin == 48) FastLED.addLeds<NEOPIXEL, PIN48>( ledArray, pixelCount );
	else if (pin == 49) FastLED.addLeds<NEOPIXEL, PIN49>( ledArray, pixelCount );
	else if (pin == 50) FastLED.addLeds<NEOPIXEL, PIN50>( ledArray, pixelCount );
	else if (pin == 51) FastLED.addLeds<NEOPIXEL, PIN51>( ledArray, pixelCount );
	else if (pin == 52) FastLED.addLeds<NEOPIXEL, PIN52>( ledArray, pixelCount );
	else if (pin == 53) FastLED.addLeds<NEOPIXEL, PIN53>( ledArray, pixelCount );

	return *this;

}


/**	Set Method for the LEDStrip Class
	Sets the r, g, b values of all pixels in a strip to the color stored in a ColorContainer object
	@param pixel The index of the pixel to be changed
	@param colorValues The ColorContainer containing the desired color */


void LEDStrip::setPixelColor( int pixel, ColorContainer colorValues ) {

	ledArray[pixel] = CRGB( colorValues.getr(), colorValues.getg(), colorValues.getb() );
	return;

}


/**	Set Method for the LEDStrip Class
	Sets the r, g, b values of a single pixel to the specified intensities
	@param pixel The index of the pixel to be changed
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void LEDStrip::setPixelColor( int pixel, int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	setPixelColor( pixel, temp );

	return;

}


/** Set Method for the LEDStrip Class
	Sets the red value of a single pixel to the specified intensity
	@param pixel The index of the pixel to be changed
	@param rIn The value for the red LED */

void LEDStrip::setPixelRed( int pixel, int rIn ) {

	ledArray[pixel].red = rIn;
	return;
}


/** Set Method for the LEDStrip Class
	Sets the green value of a single pixel to the specified intensity
	@param pixel The index of the pixel to be changed
	@param gIn The value for the green LED */

void LEDStrip::setPixelGreen( int pixel, int gIn ) {

	ledArray[pixel].green = gIn;
	return;
}


/** Set Method for the LEDStrip Class
	Sets the blue value of a single pixel to the specified intensity
	@param pixel The index of the pixel to be changed
	@param bIn The value for the blue LED */

void LEDStrip::setPixelBlue( int pixel, int bIn ) {

	ledArray[pixel].blue = bIn;
	return;
}


/**	Set Method for the LEDStrip Class
	Sets the r, g, b values of all pixels in a strip to the color stored in a ColorContainer object
	@param colorValues The ColorContainer containing the desired color */

void LEDStrip::setStripColor( ColorContainer colorValues ) {

	fill_solid( ledArray, getPixelCount(), CRGB( colorValues.getr(), colorValues.getg(), colorValues.getb() ) );

	return;

}


/**	Set Method for the LEDStrip Class
	Sets the r, g, b values of all pixels in a strip to the specified intensities
	@param rIn The intensity for the red values of the pixels
	@param gIn The intensity for the green values of the pixels
	@param bIn The intensity for the blue values of the pixels */

void LEDStrip::setStripColor( int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	setStripColor( temp );

	return;

}


/** Set Method for the LEDStrip Class
	Sets all red values in a strip to the specified intensity
	@param rIn The intensity for the red values of the pixels */

void LEDStrip::setStripRed( int rIn ) {

	for (int i = 0; i < getPixelCount(); i++) {
	
		//Serial.print( getPixelCount() );
		//Serial.print( '\n' );
		//Serial.print( "ored = " );
		//Serial.print( ledArray[i].r );
		//Serial.print( '\n' );
		setPixelRed( i, rIn );
		/*Serial.print( "red = " );
		Serial.print( ledArray[i].red );
		Serial.print( '\n' );*/

	}
	show();
	return;
}


/** Set Method for the LEDStrip Class
	Sets all green values in a strip to the specified intensity
	@param gIn The intensity for the green values of the pixels */

void LEDStrip::setStripGreen( int gIn ) {

	for (int i = 0; i < getPixelCount(); i++) ledArray[i].green = gIn;
	show();
	return;
}


/**	Set Method for the LEDStrip Class
	Sets all blue values in a strip to the specified intensity
	@param bIn The intensity for the blue values of the pixels */

void LEDStrip::setStripBlue( int bIn ) {

	for (int i = 0; i < getPixelCount(); i++) ledArray[i].blue = bIn;
	show();
	return;
}


/**	Set Method for the LEDStrip Class
	Main fillLEDsFromPalette method
	Fills a LED strip with colors from a specified color palette
	@param palette The palette to be used (can be CRGBPalette16, CRGBPalette32, CRGBPalette256, CHSVPalette16, CHSVPalette32, CHSVPalette256, TProgmemRGBPalette16, TProgmemRGBPalette32, TProgmemHSVPalette16 or TProgmemHSVPalette32)
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use
	@param brightness The brightness of the LEDs */

template<class paletteType>
void LEDStrip::fillLEDsFromPalette( const paletteType& palette, uint8_t startIndex, TBlendType blend, uint8_t brightness ) {

	for (int i = 0; i < getPixelCount(); i++) {										// Loop through all pixels

		ledArray[i] = ColorFromPalette( palette, startIndex, brightness, blend );	// Set pixel to specified colors
		startIndex += 3;															// Move to next set of colors

	}

	return;																			// Return

}


/**	Set Method for the LEDStrip Class
	Fills a LED strip with colors from a specified RGB color palette
	@param palette The CRGBPalette16 palette to be used
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const CRGBPalette16& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) {

	fillLEDsFromPalette<CRGBPalette16>( palette, startIndex, blend, brightness );	// Call main fillLEDsFromPalette method

	return;																			// Return

}


/**	Set Method for the LEDStrip Class
	Fills a LED strip with colors from a specified RGB color palette
	@param palette The CRGBPalette32 palette to be used
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const CRGBPalette32& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) {

	fillLEDsFromPalette<CRGBPalette32>( palette, startIndex, blend, brightness );	// Call main fillLEDsFromPalette method

	return;																			// Return

}


/**	Set Method for the LEDStrip Class
	Fills a LED strip with colors from a specified RGB color palette
	@param palette The CRGBPalette256 palette to be used
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const CRGBPalette256& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) {

	fillLEDsFromPalette<CRGBPalette256>( palette, startIndex, blend, brightness );	// Call main fillLEDsFromPalette method

	return;																			// Return

}


/**	Set Method for the LEDStrip Class
	Fills a LED strip with colors from a specified HSV color palette
	@param palette The CHSVPalette16 palette to be used
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const CHSVPalette16& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) {

	fillLEDsFromPalette<CHSVPalette16>( palette, startIndex, blend, brightness );	// Call main fillLEDsFromPalette method

	return;																			// Return

}


/**	Set Method for the LEDStrip Class
	Fills a LED strip with colors from a specified HSV color palette
	@param palette The CHSVPalette32 palette to be used
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const CHSVPalette32& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) {

	fillLEDsFromPalette<CHSVPalette32>( palette, startIndex, blend, brightness );	// Call main fillLEDsFromPalette method

	return;																			// Return

}


/**	Set Method for the LEDStrip Class
	Fills a LED strip with colors from a specified HSV color palette
	@param palette The CHSVPalette256 palette to be used
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const CHSVPalette256& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) {

	fillLEDsFromPalette<CHSVPalette256>( palette, startIndex, blend, brightness );	// Call main fillLEDsFromPalette method

	return;																			// Return

}


/**	Set Method for the LEDStrip Class
	Fills a LED strip with colors from a specified color palette
	@param palette The TprogmemRGBPalette16/TProgmemRGBPalette32/TProgmemHSVPalette16/TprogmemHSVPalette32 palette to be used
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const TProgmemRGBPalette16& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) {

	fillLEDsFromPalette<TProgmemRGBPalette16>( palette, startIndex, blend, brightness );	// Call main fillLEDsFromPalette method

	return;																					// Return


}


void LEDStrip::fillLEDsWithGradient( ColorContainer colorValues1, ColorContainer colorValues2 ) {

	fill_gradient_RGB( ledArray, pixelCount, CRGB( colorValues1.getr(), colorValues1.getg(), colorValues1.getb() ), CRGB( colorValues2.getr(), colorValues2.getg(), colorValues2.getb() ) );

	return;

}


void LEDStrip::fillLEDsWithGradient( ColorContainer colorValues1, ColorContainer colorValues2, ColorContainer colorValues3 ) {

	fill_gradient_RGB( ledArray, pixelCount, CRGB( colorValues1.getr(), colorValues1.getg(), colorValues1.getb() ), CRGB( colorValues2.getr(), colorValues2.getg(), colorValues2.getb() ), CRGB( colorValues3.getr(), colorValues3.getg(), colorValues3.getb() ) );

	return;

}


void LEDStrip::fillLEDsWithGradient( ColorContainer colorValues1, ColorContainer colorValues2, ColorContainer colorValues3, ColorContainer colorValues4 ) {

	fill_gradient_RGB( ledArray, pixelCount, CRGB( colorValues1.getr(), colorValues1.getg(), colorValues1.getb() ), CRGB( colorValues2.getr(), colorValues2.getg(), colorValues2.getb() ), CRGB( colorValues3.getr(), colorValues3.getg(), colorValues3.getb() ), CRGB( colorValues4.getr(), colorValues4.getg(), colorValues4.getb() ) );

	return;

}


/**	Get Method for the pixelCount variable in the LEDStrip Class
	Returns the number of pixels in a strip
	@return pixelCount */

int LEDStrip::getPixelCount() { return pixelCount; }


/**	Get Method for the color of a pixel in a LEDStrip instance
	@param pixelIn The specified pixel
	@return A ColorContainer containing the color of the specified pixel */

ColorContainer LEDStrip::getPixelColor( int pixelIn ) {	return ColorContainer( ledArray[pixelIn].r, ledArray[pixelIn].g, ledArray[pixelIn].b ); }


/**	Get Method for the red value of a pixel in a LEDStrip instance
	@param pixelIn The specified pixel
	@return The red value of the specified pixel */

int LEDStrip::getPixelRed( int pixelIn ) { return ledArray[pixelIn].r; }


/**	Get Method for the green value of a pixel in a LEDStrip instance
	@param pixelIn The specified pixel
	@return The green value of the specified pixel */

int LEDStrip::getPixelGreen( int pixelIn ) { return ledArray[pixelIn].g; }


/**	Get Method for the blue value of a pixel in a LEDStrip instance
	@param pixelIn The specified pixel
	@return The blue value of the specified pixel */

int LEDStrip::getPixelBlue( int pixelIn ) { return ledArray[pixelIn].b; }
