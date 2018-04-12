#include <iostream>
#include "../LED_Strip.h"


using namespace std;


int main() {

	LEDStrip leds( 0x552244 );

	uint8_t x = leds.ledArray[0];

	cout.setf( ios::hex, ios::basefield );

	cout << "Value should be 552244";

	cout << x << endl;


}