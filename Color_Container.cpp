#include "Color_Container.h"


using namespace std;


// The following default colors are based on the colors recognized by default in HTML
// May need to add #ifndef #define statements to fix multiple definition error

const ColorContainer AliceBlue		{ 0xF0F8FF };	// 0xF0F8FF
const ColorContainer AntiqueWhite	{ 0xFAEBD7 };	// 0xFAEBD7
const ColorContainer Aqua			{ 0x00FFFF };	// 0x00FFFF
const ColorContainer Aquamarine		{ 0x7FFFD4 };	// 0x7FFFD4
const ColorContainer Azure			{ 0xF0FFFF };	// 0xF0FFFF
const ColorContainer Beige			{ 0xF5F5DC };	// 0xF5F5DC
const ColorContainer Bisque			{ 0xFFE4C4 };	// 0xFFE4C4
const ColorContainer Black			{ 0x000000 };	// 0x000000
ColorContainer BlanchedAlmond	{ 0xFFEBCD };	// 0xFFEBCD
ColorContainer Blue				{ 0x0000FF };	// 0x0000FF
ColorContainer BlueViolet		{ 0x8A2BE2 };	// 0x8A2BE2
ColorContainer Brown			{ 0xA52A2A };	// 0xA52A2A
ColorContainer BurlyWood		{ 0xDEB887 };	// 0xDEB887
ColorContainer CadetBlue		{ 0x5F9EA0 };	// 0x5F9EA0
ColorContainer Chartreuse		{ 0x7FFF00 };	// 0x7FFF00
ColorContainer Chocolate		{ 0xD2691E };	// 0xD2691E
ColorContainer Coral			{ 0xFF7F50 };	// 0xFF7F50
ColorContainer CornflowerBlue	{ 0x6495ED };	// 0x6495ED
ColorContainer Cornsilk			{ 0xFFF8DC };	// 0xFFF8DC
ColorContainer Crimson			{ 0xDC143C };	// 0xDC143C
ColorContainer Cyan				{ 0x00FFFF };	// 0x00FFFF
ColorContainer DarkBlue			{ 0x00008B };	// 0x00008B
ColorContainer DarkCyan			{ 0x008B8B };	// 0x008B8B
ColorContainer DarkGoldenRod	{ 0xB8860B };	// 0xB8860B
ColorContainer DarkGray			{ 0xA9A9A9 };	// 0xA9A9A9
ColorContainer DarkGrey			{ 0xA9A9A9 };	// TODO: Maybe use a copy constructor // 0xA9A9A9
ColorContainer DarkGreen		{ 0x006400 };	// 0x006400
ColorContainer DarkKhaki		{ 0xBDB76B };	// 0xBDB76B
ColorContainer DarkMagenta		{ 0x8B008B };	// 0x8B008B
ColorContainer DarkOliveGreen	{ 0x556B2F };	// 0x556B2F




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

ColorContainer::ColorContainer(int rIn, int gIn, int bIn) { r = rIn; g = gIn; b = bIn; }


/**	Set Method for the r variable in the ColorContainer class (if intensity over 255, set to 255; if intensity below 0, set to 0)
	@param intensity The value to save to r */

void ColorContainer::setr(int intensity) {

	if (intensity < 0) r = 0;
	if (intensity > 255) r = 255;
	if (intensity >= 0 and intensity <= 255) r = intensity;

}


/**	Set Method for the g variable in the ColorContainer class (if intensity over 255, set to 255; if intensity below 0, set to 0)
	@param intensity The value to save to g */

void ColorContainer::setg(int intensity) {

	if (intensity < 0) g = 0;
	if (intensity > 255) g = 255;
	if (intensity >= 0 and intensity <= 255) g = intensity;

}


/**	Set Method for the b variable in the ColorContainer class (if intensity over 255, set to 255; if intensity below 0, set to 0)
	@param intensity The value to save to b */

void ColorContainer::setb(int intensity) {

	if (intensity < 0) b = 0;
	if (intensity > 255) b = 255;
	if (intensity >= 0 and intensity <= 255) b = intensity;

}


/**	Set Method for the r, g and b variables in the ColorContainer class (if intensity over 255, set to 255; if intensity below 0, set to 0)
	@param rIntensity The value to save to r
	@param gIntensity The value to save to g
	@param bIntensity The value to save to b */

void ColorContainer::setrgb(int rIntensity, int gIntensity, int bIntensity) {

	if (rIntensity < 0) r = 0;
	if (rIntensity > 255) r = 255;
	if (rIntensity >= 0 and rIntensity <= 255) r = rIntensity;
	if (gIntensity < 0) g = 0;
	if (gIntensity > 255) g = 255;
	if (gIntensity >= 0 and gIntensity <= 255) g = gIntensity;
	if (bIntensity < 0) b = 0;
	if (bIntensity > 255) b = 255;
	if (bIntensity >= 0 and bIntensity <= 255) b = bIntensity;

}


/**	Special Set Method for the ColorContainer class; sets r, g, b to 0 */

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