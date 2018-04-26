#ifndef _COLOR_CONTAINER_H_
#define _COLOR_CONTAINER_H_

using namespace std;

#include "FastLED\FastLED.h"

/** ColorContainer class - holds three color values (r,g,b) used for a LED strip LED */

class ColorContainer {

	int
		r,											/**< Variable to store the red value for the LED */
		g,											/**< Variable to store the green value for the LED */
		b;											/**< Variable to store the blue value for the LED */

public:
	ColorContainer();								// Default Constructor for ColorContainer (sets r, g, b to 0)
	ColorContainer( long hexIn );					// Constructor for ColorContainer (sets r, g, b based on number recieved (usually 6-digit hexadecimal))
	ColorContainer( int rIn, int gIn, int bIn );	// Constructor for ColorContainer (sets r, g, b to parameters received)
	ColorContainer( const CRGB & CRGBIn );			// Constructor for ColorContainer (sets r, g, b based on values in the CRGB received)


	void
		setr( int ),								// Sets the r value of a ColorContainer object
		setg( int ),								// Sets the g value of a ColorContainer object
		setb( int ),								// Sets the b value of a ColorContainer object
		setrgb( int rIn, int gIn, int bIn ),		// Sets the r, g and b values of a ColorContainer object
	  setrgb( long hexIn),// Sets the r, g, and b values of ColorContainer objects using hexadecimal input
		blackout();									// Sets the r, g and b values of a ColorContainer object to 0

	int
		getr(),										// Returns the r value of a ColorContainer object
		getg(),										// Returns the g value of a ColorContainer object
		getb();										// Returns the b value of a ColorContainer object

	long
		getColorHex();								// Returns the r, g and b values as a 6-digit hexadecimal number

};


#endif // _COLOR_CONTAINER_H_
