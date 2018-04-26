PixelColorTest:	PixelColorTest.o LED_Strip.o
	g++ -std=c++17 -o PixelColorTest PixelColorTest.o LED_Strip.o
	rm *.o

PixelColorTest.o:	PixelColorTest.cpp ../LED_Strip.h
	g++ -std=c++17 -c PixelColorTest.cpp

LED_Strip.o:	LED_Strip.cpp ../LED_Strip.h
	g++ -std=c++17 -c LED_Strip.cpp