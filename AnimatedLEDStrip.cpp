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


/** Runs a chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<TProgmemRGBPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The TProgmemRGBPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forwards' or 'backwards'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase( const TProgmemRGBPalette16& palette, direction movementDirection, uint8_t brightness = 255 ) {

	smoothChase<TProgmemRGBPalette16>( palette, movementDirection, brightness );

	return;

}


/**	Method to run a multiPixelRun animation
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection A direction (forward or backward) of type direction
	@param colorValues A ColorContainer containing the desired color */

void AnimatedLEDStrip::multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues ) {

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

void AnimatedLEDStrip::multiPixelRun( int spacing, direction chaseDirection, int rIn, int gIn, int bIn ) {

	ColorContainer temp( rIn, gIn, bIn );

	multiPixelRun( spacing, chaseDirection, temp );

	return;

}

void AnimatedLEDStrip::multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues, ColorContainer altColorValues ) {

	if (chaseDirection == forward) {

		for (int q = 0; q < spacing; q++) {

			setStripColor( altColorValues );

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

			setStripColor( altColorValues );

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
