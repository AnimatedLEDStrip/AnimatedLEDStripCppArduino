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
	CRGB * ledArray;								/**< Pointer to the array of structures holding the pixel values */
	int pin;

public:

	LEDStrip( int numLEDs, int pinIn );
	LEDStrip( const LEDStrip& );
	~LEDStrip();
	LEDStrip& operator=( const LEDStrip& );

	void
		setPixelColor( int pixel, ColorContainer colorValues ),	// Sets the color of one pixel to the color stored in a ColorContainer object
		setPixelColor( int pixel, int rIn, int gIn, int bIn ),	// Overload for setPixelColor()
		setPixelRed( int pixel, int rIn ),	// Sets the red intensity in the specified pixel
		setPixelGreen( int pixel, int gIn ),	// Sets the green intensity in the specified pixel
		setPixelBlue( int pixel, int bIn ),	// Sets the blue intensity in the specified pixel
		setStripColor( ColorContainer colorValues ),	// Sets the color of the whole strip to the color stored in a ColorContainer object
		setStripColor( int rIn, int gIn, int bIn );	// Overload for setStripColor()

	template <class paletteType> void fillLEDsFromPalette( const paletteType& palette, uint8_t startIndex, TBlendType blend, uint8_t brightness ); // Fills a LED strip with the colors from a FastLED Color Palette -- based on FastLED example code

	void
		fillLEDsFromPalette( const TProgmemRGBPalette16& palette, uint8_t startIndex, TBlendType blend, uint8_t brightness ),	// Works with TProgmemRGBPalette32, TProgmemHSVPalette16 and TProgmemHSVPalette32 too
		fillLEDsFromPalette( const CRGBPalette16& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ),
		fillLEDsFromPalette( const CRGBPalette32& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ),
		fillLEDsFromPalette( const CRGBPalette256& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ),
		fillLEDsFromPalette( const CHSVPalette16& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ),
		fillLEDsFromPalette( const CHSVPalette32& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ),
		fillLEDsFromPalette( const CHSVPalette256& palette, uint8_t startIndex, TBlendType blend = LINEARBLEND, uint8_t brightness = 255 ),
		fillLEDsWithGradient( ColorContainer colorValues1, ColorContainer colorValues2 ),
		fillLEDsWithGradient( ColorContainer colorValues1, ColorContainer colorValues2, ColorContainer colorValues3 ),
		fillLEDsWithGradient( ColorContainer colorValues1, ColorContainer colorValues2, ColorContainer colorValues3, ColorContainer colorValues4 );

	int
		getPixelCount(),	// Returns pixelCount
		getPixelRed( int pixelIn ),	// Returns intensity of red in the specified pixel
		getPixelGreen( int pixelIn ),	// Returns intensity of green in the specified pixel
		getPixelBlue( int pixelIn );	// Returns intensity of blue in the specified pixel

	ColorContainer
		getPixelColor( int pixelIn );	// Returns a ColorContainer with the red, green and blue intensities of the pixel

	CRGB * getLEDArray() { return ledArray; }	// Returns a pointer to the first element in ledArray

	CRGB & operator[]( int indexIn ) { return ledArray[indexIn]; }	// Index Operator method

};


#endif  // _LED_STRIP_H_
