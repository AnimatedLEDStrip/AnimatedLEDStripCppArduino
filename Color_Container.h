#ifndef _COLOR_CONTAINER_H_
#define _COLOR_CONTAINER_H_


using namespace std;


/** ColorContainer class - holds three color values (r,g,b) used for a LED strip */

class ColorContainer {

	//int r, g, b;					// r, g and b variables that store the value for the red, green and blue LEDs, respectively
	int
		r,							/**< Variable to store the red value for the LED */
		g,							/**< Variable to store the green value for the LED */
		b;							/**< Variable to store the blue value for the LED */

public:
	ColorContainer();				// Default Constructor for ColorContainer (sets r, g, b to 0)
	ColorContainer( int );			// Constructor for ColorContainer (sets r, g, b based on number recieved (usually 6-digit hexadecimal))
	ColorContainer(int, int, int);	// Constructor for ColorContainer (sets r, g, b to parameters received)
									// TODO: Create Copy Constructor and Destructor

	void
		setr(int),					// Sets the r value of a ColorContainer object
		setg(int),					// Sets the g value of a ColorContainer object
		setb(int),					// Sets the b value of a ColorContainer object
		setrgb(int, int, int),		// Sets the r, g and b values of a ColorContainer object
		blackout();					// Sets the r, g and b values of a ColorContainer object to 0
	int 
		getr(),						// Returns the r value of a ColorContainer object
		getg(),						// Returns the g value of a ColorContainer object
		getb();						// Returns the b value of a ColorContainer object

};

// The following default colors are based on the colors recognized by default in HTML
/*
ColorContainer AliceBlue		{ 0xF0F8FF };	// 0xF0F8FF
ColorContainer AntiqueWhite		{ 0xFAEBD7 };	// 0xFAEBD7
ColorContainer Aqua				{ 0x00FFFF };	// 0x00FFFF
ColorContainer Aquamarine		{ 0x7FFFD4 };	// 0x7FFFD4
ColorContainer Azure			{ 0xF0FFFF };	// 0xF0FFFF
ColorContainer Beige			{ 0xF5F5DC };	// 0xF5F5DC
ColorContainer Bisque			{ 0xFFE4C4 };	// 0xFFE4C4
ColorContainer Black			{ 0x000000 };	// 0x000000
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
*/


#endif // _COLOR_CONTAINER_H_