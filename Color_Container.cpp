#include "Color_Container.h"


using namespace std;


/**	Default Constructor for the ColorContainer class
	Initializes r, g, b to 0 */

ColorContainer::ColorContainer() { r = 0; g = 0; b = 0; }


/**	Constructor for the ColorContainer class
	@param hexIn The (usually) hexadecimal value that will be split into r, g and b values */

ColorContainer::ColorContainer( long hexIn ) {

	r = (hexIn & 0xFF0000) >> 16;
	g = (hexIn & 0x00FF00) >> 8;
	b = (hexIn & 0x0000FF);

}


/**	Constructor for the ColorContainer class
	@param rIn The value to be set to r
	@param gIn The value to be set to g
	@param bIn The value to be set to b */

ColorContainer::ColorContainer( int rIn, int gIn, int bIn ) { r = rIn; g = gIn; b = bIn; }


/**	Constructor for the ColorContainer class
	@param CRGBIn A reference to a CRGB instance that will be copied into the ColorContainer */

ColorContainer::ColorContainer( const CRGB & CRGBIn ) {

	r = CRGBIn.r;
	g = CRGBIn.g;
	b = CRGBIn.b;

}


/**	Set Method for the r variable in the ColorContainer class (if intensity over 255, set to 255; if intensity below 0, set to 0)
	@param intensity The value to save to r */

void ColorContainer::setr( int intensity ) {

	if (intensity < 0) r = 0;
	if (intensity > 255) r = 255;
	if (intensity >= 0 and intensity <= 255) r = intensity;

}


/**	Set Method for the g variable in the ColorContainer class (if intensity over 255, set to 255; if intensity below 0, set to 0)
	@param intensity The value to save to g */

void ColorContainer::setg( int intensity ) {

	if (intensity < 0) g = 0;
	if (intensity > 255) g = 255;
	if (intensity >= 0 and intensity <= 255) g = intensity;

}


/**	Set Method for the b variable in the ColorContainer class (if intensity over 255, set to 255; if intensity below 0, set to 0)
	@param intensity The value to save to b */

void ColorContainer::setb( int intensity ) {

	if (intensity < 0) b = 0;
	if (intensity > 255) b = 255;
	if (intensity >= 0 and intensity <= 255) b = intensity;

}


/**	Set Method for the r, g and b variables in the ColorContainer class (if intensity over 255, set to 255; if intensity below 0, set to 0)
	@param rIntensity The value to save to r
	@param gIntensity The value to save to g
	@param bIntensity The value to save to b */

void ColorContainer::setrgb( int rIntensity, int gIntensity, int bIntensity ) {

	setr( rIntensity );
	setg( gIntensity );
	setb( bIntensity );

	return;

}


/**	Set Method for the r, g and b variables in the ColorContainer class using long hexadecimal input
	@param hexIn The value containing r, g, and b values */

void ColorContainer::setrgb( long hexIn ) {

	r = (hexIn & 0xFF0000) >> 16;
	g = (hexIn & 0x00FF00) >> 8;
	b = (hexIn & 0x0000FF);

	return;
}


/**	Set Method for the r, g and b variables in the ColorContainer class using CRGB input
	@param CRGBIn A reference to a CRGB instance that will be copied into the ColorContainer */

void ColorContainer::setrgb( const CRGB & CRGBIn ) {

	r = CRGBIn.r;
	g = CRGBIn.g;
	b = CRGBIn.b;

}


/**	Special Set Method for the ColorContainer class
	Sets r, g, b to 0 */

void ColorContainer::blackout() { r = 0; g = 0; b = 0; }


/**	Get Method for the r variable in the ColorContainer class
	@return The value of r in the invoking instance */

int ColorContainer::getr() { return r; }


/**	Get Method for the g variable in the ColorContainer class
	@return The value of g in the invoking instance */

int ColorContainer::getg() { return g; }


/**	Get Method for the b variable in the ColorContainer class
	@return The value of b in the invoking instance */

int ColorContainer::getb() { return b; }


/** Get Method for the r, g and b variables in the ColorContainer class
	@return The r, g and b values, formatted into a 6-digit hexadecimal long integer */

long ColorContainer::getColorHex() {

	long temp;

	temp = r;
	temp <<= 8;
	temp |= g;
	temp <<= 8;
	temp |= b;

	return temp;

}
