#include "AnimatedLEDStrip.h"


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
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

void AnimatedLEDStrip::alternate( ColorContainer colorValues1, ColorContainer colorValues2, int delayTime ) {
	setStripColor( colorValues1 );
	delay( delayTime );
	setStripColor( colorValues2 );
	delay( delayTime );
	return;
}


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<TProgmemRGBPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The TProgmemRGBPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const TProgmemRGBPalette16& palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<TProgmemRGBPalette16>( palette, movementDirection, brightness );

	return;

}


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CRGBPalette16 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CRGBPalette16>( palette, movementDirection, brightness );

	return;

}


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette32>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette32 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CRGBPalette32 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CRGBPalette32>( palette, movementDirection, brightness );

	return;

}


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette256>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette256 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CRGBPalette256 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CRGBPalette256>( palette, movementDirection, brightness );

	return;

}


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CHSVPalette16 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CHSVPalette16>( palette, movementDirection, brightness );

	return;

}


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette32>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette32 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CHSVPalette32 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CHSVPalette32>( palette, movementDirection, brightness );

	return;

}


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette256>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette256 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const CHSVPalette256 & palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<CHSVPalette256>( palette, movementDirection, brightness );

	return;

}


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


/**	Method to run a multiPixelRun animation
	Calls chase(int, direction, ColorContainer) with inputted parameters
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


void AnimatedLEDStrip::fadeStripRed( int startIntensity, int endIntensity, bool revertAtCompletion = false ) {

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
