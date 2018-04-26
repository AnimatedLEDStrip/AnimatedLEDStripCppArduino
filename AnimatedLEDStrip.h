#ifndef ANIMATED_LED_STRIP
#define ANIMATED_LED_STRIP

#include "LED_Strip.h"
#include <time.h>


enum fadeDirection {
	fadeUp,
	fadeDown
};


class AnimatedLEDStrip : public LEDStrip {

	

public:
	//AnimatedLEDStrip();
	AnimatedLEDStrip( int numLEDs, int pin ) : LEDStrip( numLEDs, pin ) {}
	~AnimatedLEDStrip() {};


	void
		ripple(),	// Runs a single ripple animation (similar to chase but in both directions from a starting point and subsequent LEDs are dimmer)
		flicker(),	// Runs a single flicker animation (strip is at a color/brightness and random LEDs are set to a different color/brightness for a very short time before returning to the strip's color)
		alternate( ColorContainer colorValues1, ColorContainer colorValues2, int delayTime ),	// Runs a single alternate animation (alternates between two colors at the specified rate (amount of time between change))
		fadePixelRed( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ),	// Runs a fade red animation (fades red in a pixel from specified intensity to another specified intensity)
		fadePixelGreen( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ),	// Runs a fade green animation (fades green in a pixel from specified intensity to another specified intensity)
		fadePixelBlue( int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false ),	// Runs a fade blue animation (fades blue in a pixel from specified intensity to another specified intensity)
		fadePixelAll( int pixel, int startRedIntensity, int startGreenIntensity, int startBlueIntensity, int endRedIntensity, int endGreenIntensity, int endBlueIntensity, bool revertAtCompletion = false ),	// Runs a fade all animation (fades all pixels from specified intensities to other specified intensities)
		fadeStripRed( int startIntensity, int endIntensity, bool revertAtCompletion = false ),
		fadeStripGreen( int startIntensity, int endIntensity, bool revertAtCompletion = false ),
		fadeStripBlue( int startIntensity, int endIntensity, bool revertAtCompletion = false ),
		fadeStripAll( int startRedIntensity, int startGreenIntensity, int startBlueIntensity, int endRedIntensity, int endGreenIntensity, int endBlueIntensity, bool revertAtCompletion = false ),
		wave(),	// Runs a single wave animation (runs through different colors for each pixel) -- Based on code from FRC 3130
		blind(),	// Runs a single blind animation (quickly alternates between full and off) -- Based on code from FRC 3130
		pixelRun(),	// Runs a single pixel run animation (the strip is set to one color and then (in order) each pixel is set to a different color - similar to multiPixelRun() but with only one pixel)
		multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues, ColorContainer altColorValues = CRGB::Black ), // Runs a single multi-pixel run animation (similar to pixelRun() but with multiple LEDs at a specified spacing)
		multiPixelRun( int spacing, direction chaseDirection, int rIn1, int gIn1, int bIn1, int rIn2 = 0, int gIn2 = 0, int bIn2 = 0 ),	// Runs a single multi-pixel run animation (similar to pixelRun() but with multiple LEDs at a specified spacing)
		wipe( ColorContainer colorValues, direction wipeDirection ),
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


};

#endif // !ANIMATED_LED_STRIP
