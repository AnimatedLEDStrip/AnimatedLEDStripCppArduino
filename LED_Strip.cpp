#include "LED_Strip.h"
//#include <cinttypes>

using namespace std;


/**	Set Method for the LEDStrip class
	Sets the color of a single pixel to the color stored in a ColorContainer object
	@param pixel The index of the pixel to be changed
	@param colorValues The ColorContainer containing the desired color */

void LEDStrip::setPixelColor( int pixel, ColorContainer colorValues ) {

	Adafruit_NeoPixel::setPixelColor( pixel, colorValues.getr(), colorValues.getg(), colorValues.getb() );

	return;

}


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

	for (int i = 0; i < getPixelCount(); i++)
		Adafruit_NeoPixel::setPixelColor( i, colorValues.getr(), colorValues.getg(), colorValues.getb() );

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

int LEDStrip::getPixelRed( int pixelIn ) { return Adafruit_NeoPixel::getPixelColor( pixelIn ) & 0x0000FF; }


/**	Get Method for the green value in an Adafruit_NeoPixel pixel
	Returns the green value of the specified pixel
	@param pixelIn The specified pixel
	@return The green value of the specified pixel */

int LEDStrip::getPixelGreen( int pixelIn ) { return (Adafruit_NeoPixel::getPixelColor( pixelIn ) & 0x00FF00) >> 8; }


/**	Get Method for the blue value in an Adafruit_NeoPixel pixel
	Returns the blue value of the specified pixel
	@param pixelIn The specified pixel
	@return The blue value of the specified pixel */

int LEDStrip::getPixelBlue( int pixelIn ) { return (Adafruit_NeoPixel::getPixelColor( pixelIn ) & 0xFF0000) >> 16; }


/**	Method to run a chase animation
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


/**	Method to run a chase animation
	Calls chase(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void LEDStrip::chase( int spacing, direction chaseDirection, int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	chase( spacing, chaseDirection, temp );
	/*
	ColorContainer black;

	if (chaseDirection == forward) {

		for (int q = 0; q < spacing; q++) {

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), rIn, gIn, bIn );

			}

			show();
			delay(50);

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), black );

			}

		}

	}

	if (chaseDirection == backward) {

		for (int q = spacing - 1; q >= 0; q--) {

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), rIn, gIn, bIn );

			}

			show();
			delay(50);

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), black );

			}

		}

	}
	*/

	return;

}

/*
void LEDStrip::specialChase( int spacing, direction chaseDirection, ColorContainer colorValues ) {

	ColorContainer black;

	if (chaseDirection = forward) {

		for (int q = 0; q < spacing; q++) {

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), colorValues );

			}

			show();
			delay( 50 );

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), black );

			}

		}

	}

	if (chaseDirection = backward) {

		for (int q = spacing - 1; q >= 0; q--) {

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), colorValues );

			}

			show();
			delay( 50 );

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), black );

			}

		}

	}

}*/