#include "AnimatedLEDStrip.h"


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	@param palette The palette to be used (can be CRGBPalette16, CRGBPalette32, CRGBPalette256, CHSVPalette16, CHSVPalette32, CHSVPalette256, TProgmemRGBPalette16, TProgmemRGBPalette32, TProgmemHSVPalette16 or TProgmemHSVPalette32)
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

template<class paletteType>
void AnimatedLEDStrip::smoothChase( const paletteType & palette, direction movementDirection, uint8_t brightness ) {

	if (movementDirection == forward) {

		for (uint8_t startIndex = 255; startIndex > 0; startIndex--) {				// Run through one cycle

			fillLEDsFromPalette( palette, startIndex, LINEARBLEND, brightness );	// Fill in colors from the specified palette

			show();																	// Send color data to LEDs

		}

	} else if (movementDirection == backward) {

		for (uint8_t startIndex = 0; startIndex < 255; startIndex++) {				// Run through one cycle

			fillLEDsFromPalette( palette, startIndex, LINEARBLEND, brightness );	// Fill in colors from the specified palette

			show();																	// Send color data to LEDs

		}

	}

	return;																		// Return

}


/** Method to run an Alternate animation
	@param colorValues1 The first color to be displayed
	@param colorValues2 The second color to be displayed
	@param delayTime The time (in milliseconds) that each color is displayed for */

void AnimatedLEDStrip::alternate( ColorContainer colorValues1, ColorContainer colorValues2, int delayTime ) {	// TODO: Test
	setStripColor( colorValues1 );
	delay( delayTime );
	setStripColor( colorValues2 );
	delay( delayTime );
	return;
}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<TProgmemRGBPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The TProgmemRGBPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const TProgmemRGBPalette16& palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<TProgmemRGBPalette16>( palette, movementDirection, brightness );

	return;

}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CRGBPalette16 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CRGBPalette16>( palette, movementDirection, brightness );

	return;

}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette32>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette32 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CRGBPalette32 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CRGBPalette32>( palette, movementDirection, brightness );

	return;

}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette256>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette256 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CRGBPalette256 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CRGBPalette256>( palette, movementDirection, brightness );

	return;

}


/** Method to run a Smooth Chase animation using a HSV color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CHSVPalette16 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CHSVPalette16>( palette, movementDirection, brightness );

	return;

}


/** Method to run a Smooth Chase animation using a HSV color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette32>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette32 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CHSVPalette32 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CHSVPalette32>( palette, movementDirection, brightness );

	return;

}


/** Method to run a Smooth Chase animation using a HSV color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette256>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette256 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CHSVPalette256 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CHSVPalette256>( palette, movementDirection, brightness );

	return;

}


/** Method to run a Wipe animation
	Changes the strip to the specified color, but one pixel at a time. Looks and works similar to a Pixel Run animation.
	@param colorValues The color that the strip will be at the end of the animation
	@param wipeDirection Specifies if the direction should run 'forwards' or 'backwards' */

void AnimatedLEDStrip::wipe( ColorContainer colorValues, direction wipeDirection ) {

	if (wipeDirection == backward) {

		for (int i = 0; i < getPixelCount(); i++) {

			setPixelColor( i, colorValues );
			show();

		}

	}

	if (wipeDirection == forward) {

		for (int i = getPixelCount() - 1; i >= 0; i--) {

			setPixelColor( i, colorValues );
			show();

		}

	}

}


/** Method to run a Pixel Run animation
	@param movementDirection A direction (forward or backward) of type direction
	@param colorValues The color of the 'running' pixel
	@param altColorValues The color of the remaining pixels */

void AnimatedLEDStrip::pixelRun( direction movementDirection, ColorContainer colorValues, ColorContainer altColorValues = CRGB::Black ) {

	setStripColor( altColorValues );

	if (chaseDirection == forward) {

		for (int q = 0; q < getPixelCount(); q++) {

			setPixelColor( q, colorValues );

			delay( 50 );

			setPixelColor( q, altColorValues );

		}

	}

	if (chaseDirection == backward) {

		for (int q = spacing - 1; q >= 0; q--) {

			setPixelColor( q, colorValues );

			delay( 50 );

			setPixelColor( q, altColorValues );

		}

	}

	return;

}


void AnimatedLEDStrip::pixelRunWithTrail( ColorContainer colorValues, ColorContainer altColorValues = CRGB::Black ) {	// TODO: Test

	setStripColor( altColorValues );


	if (chaseDirection == forward) {

		for (int q = 0; q < getPixelCount(); q++) {

			for (int i = 0; i < getPixelCount(); i++) {

				ledArray[i].blend( ledArray[i], altColorValues, 30 );

			}

			setPixelColor( q, colorValues );

			delay( 50 );

		}

	}

	if (chaseDirection == backward) {

		for (int q = spacing - 1; q >= 0; q--) {

			for (int i = 0; i < getPixelCount(); i++) {

				ledArray[i].blend( ledArray[i], altColorValues, 30 );

			}

			setPixelColor( q, colorValues );

			delay( 50 );

		}

	}

	return;

}


/**	Method to run a Multi-Pixel Run animation
	Calls multiPixelRun(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void AnimatedLEDStrip::multiPixelRun( int spacing, direction chaseDirection, int rIn1, int gIn1, int bIn1, int rIn2 = 0, int gIn2 = 0, int bIn2 = 0 ) {

	ColorContainer temp1( rIn1, gIn1, bIn1 );
	ColorContainer temp2( rIn2, gIn2, bIn2 );

	multiPixelRun( spacing, chaseDirection, temp1, temp2 );

	return;

}


/**	Method to run a Multi-Pixel Run animation
	Calls multiPixelRun(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction 
	@param colorValues The color of the 'running' pixels
	@param altColorValues The color of the remaining pixels */

void AnimatedLEDStrip::multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues, ColorContainer altColorValues = CRGB::Black ) {

	if (chaseDirection == backward) {

		for (int q = 0; q < spacing; q++) {

			setStripColor( altColorValues );

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), colorValues );

			}

			show();
			delay( 50 );

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), altColorValues );

			}

		}

	}

	if (chaseDirection == forward) {

		for (int q = spacing - 1; q >= 0; q--) {

			setStripColor( altColorValues );

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), colorValues );

			}

			show();
			delay( 50 );

			for (int i = 0; i < getPixelCount(); i += spacing) {

				setPixelColor( i + (-(q - (spacing - 1))), altColorValues );

			}

		}

	}

	return;

}


/** Method to fade a pixel's red value from one intensity to another
	@param pixel The pixel that will be changed
	@param startIntensity The intensity that the pixel will begin at
	@param endIntensity The intensity that the pixel will end at
	@param revertAtCompletion Specifies if the pixel should revert to the color it had prior to the animation (default false) */

void AnimatedLEDStrip::fadePixelRed( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ) {

	fadeDirection fade;

	if (startIntensity > endIntensity) fade = fadeDown;
	if (startIntensity < endIntensity) fade = fadeUp;
	if (startIntensity == endIntensity) return;

	ColorContainer originalValues = getPixelColor( pixel );

	switch (fade) {
	case fadeUp:
		for (int i = startIntensity; i <= endIntensity; i++) {

			setPixelRed( pixel, i );
			show();

		}

		break;

	case fadeDown:
		for (int i = startIntensity; i >= endIntensity; i--) {

			setPixelRed( pixel, i );
			show();

		}

		break;

	}

	if (revertAtCompletion) setPixelColor( pixel, originalValues );

}


/** Method to fade a pixel's green value from one intensity to another
	@param pixel The pixel that will be changed
	@param startIntensity The intensity that the pixel will begin at
	@param endIntensity The intensity that the pixel will end at
	@param revertAtCompletion Specifies if the pixel should revert to the color it had prior to the animation (default false) */

void AnimatedLEDStrip::fadePixelGreen( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ) {

	fadeDirection fade;

	if (startIntensity > endIntensity) fade = fadeDown;
	if (startIntensity < endIntensity) fade = fadeUp;
	if (startIntensity == endIntensity) return;

	ColorContainer originalValues = getPixelColor( pixel );

	switch (fade) {
	case fadeUp:
		for (int i = startIntensity; i <= endIntensity; i++) {

			setPixelGreen( pixel, i );
			show();

		}

		break;

	case fadeDown:
		for (int i = startIntensity; i >= endIntensity; i--) {

			setPixelGreen( pixel, i );
			show();

		}

		break;

	}

	if (revertAtCompletion) setPixelColor( pixel, originalValues );

}


/** Method to fade a pixel's blue value from one intensity to another
	@param pixel The pixel that will be changed
	@param startIntensity The intensity that the pixel will begin at
	@param endIntensity The intensity that the pixel will end at
	@param revertAtCompletion Specifies if the pixel should revert to the color it had prior to the animation (default false) */

void AnimatedLEDStrip::fadePixelBlue( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ) {

	fadeDirection fade;

	if (startIntensity > endIntensity) fade = fadeDown;
	if (startIntensity < endIntensity) fade = fadeUp;
	if (startIntensity == endIntensity) return;

	ColorContainer originalValues = getPixelColor( pixel );

	switch (fade) {
	case fadeUp:
		for (int i = startIntensity; i <= endIntensity; i++) {

			setPixelBlue( pixel, i );
			show();

		}

		break;

	case fadeDown:
		for (int i = startIntensity; i >= endIntensity; i--) {

			setPixelBlue( pixel, i );
			show();

		}

		break;

	}

	if (revertAtCompletion) setPixelColor( pixel, originalValues );

}


/** Method to fade a pixel's red, green and blue values from one set of intensities to another
	@param pixel The pixel that will be changed
	@param startRedIntensity The intensity that the pixel's red value will begin at
	@param startGreenIntensity The intensity that the pixel's green value will begin at
	@param startBlueIntensity The intensity that the pixel's blue value will begin at
	@param endRedIntensity The intensity that the pixel's red value will end at
	@param endGreenIntensity The intensity that the pixel's green value will end at
	@param endBlueIntensity The intensity that the pixel's blue value will end at
	@param revertAtCompletion Specifies if the pixel should revert to the color it had prior to the animation (default false) */

void AnimatedLEDStrip::fadePixelAll( int pixel, int startRedIntensity, int startGreenIntensity, int startBlueIntensity, int endRedIntensity, int endGreenIntensity, int endBlueIntensity, bool revertAtCompletion = false ) {

	ColorContainer originalValues = getPixelColor( pixel );

	setPixelRed( pixel, startRedIntensity );
	setPixelGreen( pixel, startGreenIntensity );
	setPixelBlue( pixel, startBlueIntensity );

	bool redComplete = false;
	bool greenComplete = false;
	bool blueComplete = false;

	while (!redComplete || !greenComplete || !blueComplete) {

		if (!blueComplete) {

			if (getPixelRed( pixel ) < endRedIntensity) {

				setPixelRed( pixel, getPixelRed( pixel ) + 1 );

			} else if (getPixelRed( pixel ) > endRedIntensity) {

				setPixelRed( pixel, getPixelRed( pixel ) - 1 );

			} else {

				redComplete = true;

			}

		}

		if (!greenComplete) {

			if (getPixelGreen( pixel ) < endGreenIntensity) {

				setPixelGreen( pixel, getPixelGreen( pixel ) + 1 );

			} else if (getPixelGreen( pixel ) > endGreenIntensity) {

				setPixelGreen( pixel, getPixelGreen( pixel ) - 1 );

			} else {

				greenComplete = true;

			}

		}

		if (!blueComplete) {

			if (getPixelBlue( pixel ) < endBlueIntensity) {

				setPixelBlue( pixel, getPixelBlue( pixel ) + 1 );

			} else if (getPixelBlue( pixel ) > endRedIntensity) {

				setPixelBlue( pixel, getPixelBlue( pixel ) - 1 );

			} else {

				blueComplete = true;

			}

		}

		show();

	}

	if (revertAtCompletion) setPixelColor( pixel, originalValues );

	return;

}


void AnimatedLEDStrip::fadeStripRed( int startIntensity, int endIntensity, bool revertAtCompletion = false ) {	// TODO: Test

	fadeDirection fade;

	if (startIntensity > endIntensity) fade = fadeDown;
	if (startIntensity < endIntensity) fade = fadeUp;
	if (startIntensity == endIntensity) return;

	AnimatedLEDStrip originalValues = *this;

	switch (fade) {
	case fadeUp:
		for (int i = startIntensity; i <= endIntensity; i++) {

			setStripRed( i );
			Serial.print( "Incrementing " );
			Serial.print( i );
			Serial.print( "\n" );
			show();

		}

		break;

	case fadeDown:
		for (int i = startIntensity; i >= endIntensity; i--) {

			setStripRed( i );
			Serial.print( "Incrementing " );
			Serial.print( i );
			Serial.print( "\n" );
			show();

		}

		break;

	}

	if (revertAtCompletion) *this = originalValues;

}


void AnimatedLEDStrip::fadeStripGreen( int startIntensity, int endIntensity, bool revertAtCompletion = false ) {



}


void AnimatedLEDStrip::fadeStripBlue( int startIntensity, int endIntensity, bool revertAtCompletion = false ) {



}


void AnimatedLEDStrip::fadeStripAll( int startRedIntensity, int startGreenIntensity, int startBlueIntensity, int endRedIntensity, int endGreenIntensity, int endBlueIntensity, bool revertAtCompletion = false ) {



}


/**	@deprecated Use multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues) instead
	Method to run a chase animation
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param colorValues A ColorContainer containing the desired color */

void AnimatedLEDStrip::chase( int spacing, direction chaseDirection, ColorContainer colorValues ) {

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


/**	@deprecated Use multiPixelRun( int spacing, direction chaseDirection, int rIn, int gIn, int bIn) instead
	Method to run a chase animation
	Calls chase(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void AnimatedLEDStrip::chase( int spacing, direction chaseDirection, int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	chase( spacing, chaseDirection, temp );

	return;

}
