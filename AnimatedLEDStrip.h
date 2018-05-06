#ifndef ANIMATED_LED_STRIP
#define ANIMATED_LED_STRIP

#include "LED_Strip.h"
#include <time.h>


enum fadeDirection {
	fadeUp,
	fadeDown
};


class AnimatedLEDStrip : public LEDStrip {

	int * shuffleArray;


public:
	//AnimatedLEDStrip();
	AnimatedLEDStrip( int numLEDs, int pin ) : LEDStrip( numLEDs, pin ) {

		shuffleArray = new int[numLEDs];

		for (int i = 0; i < numLEDs; i++) shuffleArray[i] = i;

	}
	~AnimatedLEDStrip() {}


	void
		alternate( ColorContainer colorValues1, ColorContainer colorValues2, int delayTime ),	// Runs a single alternate animation (alternates between two colors at the specified rate (amount of time between change))
		alternate( int r1In, int g1In, int b1In, int r2In, int g2In, int b2In, int delayTime ),	// Overload for alternate()
		fadePixelRed( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ),	// Runs a fade red animation (fades red in a pixel from specified intensity to another specified intensity)
		fadePixelGreen( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ),	// Runs a fade green animation (fades green in a pixel from specified intensity to another specified intensity)
		fadePixelBlue( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ),	// Runs a fade blue animation (fades blue in a pixel from specified intensity to another specified intensity)
		fadePixelAll( int pixel, int startRedIntensity, int startGreenIntensity, int startBlueIntensity, int endRedIntensity, int endGreenIntensity, int endBlueIntensity, bool revertAtCompletion = false ),	// Runs a fade all animation (fades all pixels from specified intensities to other specified intensities)
		fadeStripRed( int startIntensity, int endIntensity, bool revertAtCompletion = false ),
		fadeStripGreen( int startIntensity, int endIntensity, bool revertAtCompletion = false ),
		fadeStripBlue( int startIntensity, int endIntensity, bool revertAtCompletion = false ),
		fadeStripAll( int startRedIntensity, int startGreenIntensity, int startBlueIntensity, int endRedIntensity, int endGreenIntensity, int endBlueIntensity, bool revertAtCompletion = false ),
		multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues, ColorContainer altColorValues = CRGB::Black ), // Runs a single multi-pixel run animation (similar to pixelRun() but with multiple LEDs at a specified spacing)
		multiPixelRun( int spacing, direction chaseDirection, int rIn1, int gIn1, int bIn1, int rIn2 = 0, int gIn2 = 0, int bIn2 = 0 ),	// Overload for multiPixelRun()
		pixelRun( direction movementDirection, ColorContainer colorValues, ColorContainer altColorValues = CRGB::Black ),	// Runs a single pixel run animation (the strip is set to one color and then (in order) each pixel is set to the main color while all other pixels are set to the alternate color - similar to multiPixelRun() but with only one pixel)
		pixelRun( direction movementDirection, int r1In, int g1In, int b1In, int r2In = 0, int g2In = 0, int b2In = 0 ),	// Overload for pixelRun()
		pixelRunWithTrail( direction movementDirection, ColorContainer colorValues, ColorContainer altColorValues = CRGB::Black ),	// Very similar to the sinelon() function in the DemoReel100 example for the FastLED library
		pixelRunWithTrail( direction movementDirection, int r1In, int g1In, int b1In, int r2In = 0, int g2In = 0, int b2In = 0 ),	// Overload for pixelRunWithTrail()
		ripple( int startPixel, ColorContainer colorValues ),	// Runs a single ripple animation (similar to chase but in both directions from a starting point and subsequent LEDs are dimmer)
		sparkle( ColorContainer flickerColor ),	// Runs a single sparkle animation (random LEDs are set to a different color/brightness for a very short time before returning to the pixel's original color)
		sparkleToColor( ColorContainer destinationColor ),
		sparkleToColor( int rIn, int gIn, int bIn ),	// Overload for sparkleToColor()
		wipe( ColorContainer colorValues, direction wipeDirection ),	// Runs a single wipe animation (similar to pixelRun() but the values do not switch to a second color)
		wipe( int rIn, int gIn, int bIn, direction wipeDirection ),	// Overload for wipe()
		chase( int, direction, ColorContainer ),	// Deprecated - use multiPixelRun( int, direction, ColorContainer )
		chase( int, direction, int, int, int );	// Deprecated - use multiPixelRun( int, direction, int, int, int )

	template<class paletteType> void smoothChase( const paletteType& palette, direction movementDirection, uint8_t brightness );

	void		// Runs a single smoothChase animation (Uses the ColorFromPalette feature of FastLED)
		smoothChase( const CRGBPalette16 & palette, direction movementDirection, uint8_t brightness = 255 ),
		smoothChase( const CRGBPalette32 & palette, direction movementDirection, uint8_t brightness = 255 ),
		smoothChase( const CRGBPalette256 & palette, direction movementDirection, uint8_t brightness = 255 ),
		smoothChase( const TProgmemRGBPalette16 & palette, direction movementDirection, uint8_t brightness = 255 ),
		smoothChase( const CHSVPalette16 & palette, direction movementDirection, uint8_t brightness = 255 ),
		smoothChase( const CHSVPalette32 & palette, direction movementDirection, uint8_t brightness = 255 ),
		smoothChase( const CHSVPalette256 & palette, direction movementDirection, uint8_t brightness = 255 );


	/** Helper Function that shuffles the values in the shuffleArray 
		Slightly modified version of code originally from https://ideone.com/qU00S4 */

	void shuffle() {

		if (getPixelCount() > 1) {

			size_t i;
			srand( time( NULL ) );

			for (i = 0; i < getPixelCount() - 1; i++) {

				size_t j = i + rand() / (RAND_MAX / (getPixelCount() - i) + 1);
				int t = shuffleArray[j];
				shuffleArray[j] = shuffleArray[i];
				shuffleArray[i] = t;

			}

		}

	}

};


#endif // !ANIMATED_LED_STRIP
