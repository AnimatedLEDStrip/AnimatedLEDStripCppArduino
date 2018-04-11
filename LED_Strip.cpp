#include "LED_Strip.h"
#include <inttypes.h>

using namespace std;


/**	Set Method for the LEDStrip class
	Sets the color of a single pixel to the color stored in a ColorContainer object
	@param pixel The index of the pixel to be changed
	@param colorValues The ColorContainer containing the desired color */

void LEDStrip::setPixelColor( int pixel, ColorContainer colorValues ) {

	ledArray[pixel] = CRGB( colorValues.getr(), colorValues.getg(), colorValues.getb() );
	return;

}

void LEDStrip::fadeRed() {}


/**	Fills a LED strip with colors from a specified RGB color palette
	@param palette The RGB palette to be used 
	@param startIndex The offset in the color palette (used to make the animation 'move')
	@param blend The blend type (LINEARBLEND or NOBLEND) to use (default LINEARBLEND)
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::fillLEDsFromPalette( const TProgmemRGBPalette16& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ) { //TODO: Add support for other palette sizes

	for (int i = 0; i < getPixelCount(); i++) {										// Loop through all pixels

		ledArray[i] = ColorFromPalette( palette , startIndex, brightness, blend );	// Set pixel to specified colors
		startIndex += 3;															// Move to next set of colors

	}

	return;																			// Return

}


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	@param palette The RGB palette to be used
	@param brightness The brightness of the LEDs (default 255) */

void LEDStrip::smoothChase( const TProgmemRGBPalette16& palette, uint8_t brightness = 255 ) {

	for (uint8_t startIndex = 0; startIndex < 255; startIndex++) {				// Run through one cycle

		fillLEDsFromPalette( palette, startIndex, LINEARBLEND, brightness );	// Fill in colors from the specified palette

		show();																	// Send color data to LEDs

	}

	return;																		// Return

}


/**	Method to run a multiPixelRun animation
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param colorValues A ColorContainer containing the desired color */

void LEDStrip::multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues ) {

	ColorContainer Black;

	if (chaseDirection == forward) {

		for (int q = 0; q < spacing; q++) {

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), colorValues );

			}

			show();
			delay( 50 );

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), Black );

			}

		}

	}

	if (chaseDirection == backward) {

		for (int q = spacing - 1; q >= 0; q--) {

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), colorValues );

			}

			show();
			delay( 50 );

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), Black );

			}

		}

	}

	return;

}

/**	Method to run a multiPixelRun animation
	Calls chase(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void LEDStrip::multiPixelRun( int spacing, direction chaseDirection, int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	multiPixelRun( spacing, chaseDirection, temp );

	return;

}


void LEDStrip::pixelRun() {}

void LEDStrip::blind() {}

void LEDStrip::wave() {}

void LEDStrip::fadeAll() {}

void LEDStrip::fadeBlue() {}

void LEDStrip::fadeGreen() {}

void LEDStrip::alternate() {}

void LEDStrip::flicker() {}

void LEDStrip::ripple() {}


/**	Set Method for the LEDStrip class
	Sets the color of a single pixel to the color stored in a ColorContainer object
	@param pixel The index of the pixel to be changed
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void LEDStrip::setPixelColor( int pixel, int rIn, int gIn, int bIn ){

	ColorContainer temp( rIn, gIn, bIn );

	setPixelColor( pixel, temp );

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
	Sets the color of all pixels in a strip to the color stored in a ColorContainer object
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void LEDStrip::setStripColor( int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	setStripColor( temp );

	return;

}


/**	Get Method for the pixelCount variable in the LEDStrip class
	Returns the number of pixels in a strip
	@return pixelCount */

int LEDStrip::getPixelCount() { return pixelCount; }


/**	Get Method for the red value in an Adafruit_NeoPixel pixel
	Returns the red value of the specified pixel
	@param pixelIn The specified pixel
	@return The red value of the specified pixel */

int LEDStrip::getPixelRed( int pixelIn ) { return 0; }


/**	Get Method for the green value in an Adafruit_NeoPixel pixel
	Returns the green value of the specified pixel
	@param pixelIn The specified pixel
	@return The green value of the specified pixel */

int LEDStrip::getPixelGreen( int pixelIn ) { return 0; }


/**	Get Method for the blue value in an Adafruit_NeoPixel pixel
	Returns the blue value of the specified pixel
	@param pixelIn The specified pixel
	@return The blue value of the specified pixel */

int LEDStrip::getPixelBlue( int pixelIn ) { return 0; }


/**	@deprecated Use multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues) instead
	Method to run a chase animation
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param colorValues A ColorContainer containing the desired color */

void LEDStrip::chase( int spacing, direction chaseDirection, ColorContainer colorValues ) {

	ColorContainer Black;

	if (chaseDirection == forward) {

		for (int q = 0; q < spacing; q++) {

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), colorValues );

			}

			show();
			delay(50);

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), Black );

			}

		}

	}

	if (chaseDirection == backward) {

		for (int q = spacing - 1; q >= 0; q--) {

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), colorValues );

			}

			show();
			delay(50);

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), Black );

			}

		}

	}

	return;

}


/**	@deprecated Use multiPixelRun( int spacing, direction chaseDirection, int rIn, int gIn, int bIn) instead
	Method to run a chase animation
	Calls chase(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void LEDStrip::chase( int spacing, direction chaseDirection, int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	chase( spacing, chaseDirection, temp );

	return;

}
