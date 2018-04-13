#ifndef _LED_STRIP_H_
#define _LED_STRIP_H_

#include "FastLED/FastLED.h"
#include "Color_Container.h"
#include "Pin_Defs.h"


/**	Enum direction that is used to determine if the strip chase animation runs 'forward' or 'backward' */

enum direction {

	forward,	/**< With direction of power/signal flow */
	backward	/**< Against direction of power/signal flow */

};


/**	Class LEDStrip that is used to represent a NeoPixel LED strip
	@extends CFastLED */

class LEDStrip : public CFastLED {

	int pixelCount;									/**< Number of pixels in strip - set in constructor */
	CRGB* ledArray;									/**< Pointer to the array of structures holding the pixel values */

public:

	LEDStrip( int, int ); // TODO: Figure out how to take a pin as a parameter
	LEDStrip( const LEDStrip& );
	~LEDStrip() {};
																							// TODO: Add Copy Constructor and Destructor

	void
		setPixelColor( int, ColorContainer ),												// Sets the color of one pixel to the color stored in a ColorContainer object
		setPixelColor( int, int, int, int ),												// Calls setPixelColor(int, ColorContainer) with a ColorContainer created from the inputted rgb values
		setStripColor( ColorContainer ),													// Sets the color of the whole strip to the color stored in a ColorContainer object
		setStripColor( int, int, int ),														// Calls setStripColor(ColorContainer) with a ColorContainer created from the inputted rgb values
		chase( int, direction, ColorContainer ),											// Deprecated - use multiPixelRun( int, direction, ColorContainer )
		chase( int, direction, int, int, int ),												// Deprecated - use multiPixelRun( int, direction, int, int, int )
		ripple(),																			// Runs a single ripple animation (similar to chase but in both directions from a starting point and subsequent LEDs are dimmer)
		flicker(),																			// Runs a single flicker animation (strip is at a color/brightness and random LEDs are set to a different color/brightness for a very short time before returning to the strip's color)
		alternate(),																		// Runs a single alternate animation (alternates between two colors at the specified rate (amount of time between change)) -- Based on code from FRC 3130
		fadeRed(),																			// Runs a fade red animation (fades red in a pixel from specified intensity to another specified intensity over the specified amount of time) -- Based on code from FRC 3130
		fadeGreen(),																		// Runs a fade green animation (fades green in a pixel from specified intensity to another specified intensity over the specified amount of time) -- Based on code from FRC 3130
		fadeBlue(),																			// Runs a fade blue animation (fades blue in a pixel from specified intensity to another specified intensity over the specified amount of time) -- Based on code from FRC 3130
		fadeAll(),																			// Runs a fade all animation (fades all pixels from specified intensities to other specified intensities over the specified amount of time) -- Based on code from FRC 3130
		wave(),																				// Runs a single wave animation (runs through different colors for each pixel) -- Based on code from FRC 3130
		blind(),																			// Runs a single blind animation (quickly alternates between full and off) -- Based on code from FRC 3130
		pixelRun(),																			// Runs a single pixel run animation (the strip is set to one color and then (in order) each pixel is set to a different color - similar to chase but with only one pixel)
		multiPixelRun( int, direction, ColorContainer ),									// Runs a single multi-pixel run animation (similar to pixelRun() but with multiple LEDs at a specified spacing)
		multiPixelRun( int, direction, int, int, int ),										// Runs a single multi-pixel run animation (similar to pixelRun() but with multiple LEDs at a specified spacing)
		smoothChase( const TProgmemRGBPalette16&, direction, uint8_t ),						// Runs a single smoothChase animation (Uses the ColorFromPalette feature of FastLED)
		fillLEDsFromPalette( const TProgmemRGBPalette16&, uint8_t, TBlendType, uint8_t );	// Fills a LED strip with the colors from a FastLED Color Palette -- based on FastLED example code
													
																							// Also look through the FastLED library to see what else is possible

	int
		getPixelCount(),							// Returns pixelCount
		getPixelRed( int ),							// Returns intensity of red in the specified pixel
		getPixelGreen( int ),						// Returns intensity of green in the specified pixel
		getPixelBlue( int );						// Returns intensity of blue in the specified pixel

	ColorContainer
		getPixelColor( int );						// Returns a ColorContainer with the red, green and blue intensities of the pixel

	CRGB
		* getLEDArray() { return ledArray; }

													// TODO: Add assignment operator method
	CRGB & operator[]( int indexIn ) { return ledArray[indexIn]; }							// Index Operator method

};


#endif  // _LED_STRIP_H_