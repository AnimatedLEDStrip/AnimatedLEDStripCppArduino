#include "AnimatedLEDStrip.h"


/** Method to run an Alternate animation
	@param colorValues1 The first color to be displayed
	@param colorValues2 The second color to be displayed
	@param delayTime The time (in milliseconds) that each color is displayed for */

void AnimatedLEDStrip::alternate(ColorContainer colorValues1, ColorContainer colorValues2, int delayTime) {

    setStripColor(colorValues1);    // Set strip to colorValues1
    delay(delayTime);                // Delay for delayTime milliseconds

    setStripColor(colorValues2);    // Set strip to colorValues2
    delay(delayTime);                // Delay for delayTime milliseconds

    return;                            // Return

}


/** Overloaded method to run an Alternate animation
	@param r1In The red intensity for the first color
	@param g1In The green intensity for the first color
	@param b1In The blue intensity for the first color
	@param r2In The red intensity for the second color
	@param g2In The green intensity for the second color
	@param b2In The blue intensity for the second color
	@param delayTime The time (in milliseconds) that each color is displayed for */

void AnimatedLEDStrip::alternate(int r1In, int g1In, int b1In, int r2In, int g2In, int b2In, int delayTime) {

    ColorContainer temp1 = ColorContainer(r1In, g1In, b1In);    // Create temporary ColorContainer for colorValues1
    ColorContainer temp2 = ColorContainer(r2In, g2In, b2In);    // Create temporary ColorContainer for colorValues2

    alternate(temp1, temp2, delayTime);                        // Call main alternate method

    return;                                                        // Return

}


/** Method to fade a pixel's red value from one intensity to another
	@param pixel The pixel that will be changed
	@param startIntensity The intensity that the pixel will begin at
	@param endIntensity The intensity that the pixel will end at
	@param revertAtCompletion Specifies if the pixel should revert to the color it had prior to the animation (default false) */

void AnimatedLEDStrip::fadePixelRed(int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false) {

    fadeDirection fade;                                                    // Initialize fade variable that will specify the direction the fade needs to go

    if (startIntensity > endIntensity)
        fade = fadeDown;                    // If the end intensity is lower than the start intensity, the function needs to fade down
    if (startIntensity < endIntensity)
        fade = fadeUp;                    // If the end intensity is higher than the start intensity, the function needs to fade up
    if (startIntensity == endIntensity)
        return;                            // If the start and end intensities are equal, the function has no work to do

    ColorContainer originalValues = getPixelColor(
            pixel);                // Save original color of the pixel so that the pixel can be reverted at the end if desired

    switch (fade) {                                                        // Switching on the fade variable
        case fadeUp:                                                        // If set to fadeUp:
            for (int i = startIntensity; i <=
                                         endIntensity; i++) {                // Run through each intensity from the start intensity to the end intensity...

                setPixelRed(pixel, i);                                        // ...Setting the pixel's red intensity...
                show();                                                            // ...And updating the pixel after each change

            }

            break;

        case fadeDown:                                                        // If set to fadeDown:
            for (int i = startIntensity; i >=
                                         endIntensity; i--) {                // Run through each intensity from the start intensity to the end intensity...

                setPixelRed(pixel, i);                                        // ...Setting the pixel's red intensity...
                show();                                                            // ...And updating the pixel after each change

            }

            break;

    }

    if (revertAtCompletion)
        setPixelColor(pixel,
                      originalValues);        // If the user wants the pixel to revert to its original color, revert it here

    return;                                                                // Return

}


/** Method to fade a pixel's green value from one intensity to another
	@param pixel The pixel that will be changed
	@param startIntensity The intensity that the pixel will begin at
	@param endIntensity The intensity that the pixel will end at
	@param revertAtCompletion Specifies if the pixel should revert to the color it had prior to the animation (default false) */

void
AnimatedLEDStrip::fadePixelGreen(int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false) {

    fadeDirection fade;                                                    // Initialize the fade variable that will specify the direction the fade needs to go

    if (startIntensity > endIntensity)
        fade = fadeDown;                    // If the end intensity is lower than the start intensity, the function needs to fade down
    if (startIntensity < endIntensity)
        fade = fadeUp;                    // If the end intensity is higher than the start intensity, the function needs to fade up
    if (startIntensity == endIntensity)
        return;                            // If the start and end intensities are equal, the function has no work to do

    ColorContainer originalValues = getPixelColor(
            pixel);                // Save original color of the pixel so that the pixel can be reverted at the end if desired

    switch (fade) {                                                        // Switching on the fade variable
        case fadeUp:                                                        // If set to fadeUp:
            for (int i = startIntensity; i <=
                                         endIntensity; i++) {                // Run through each intensity from the start intensity to the end intensity...

                setPixelGreen(pixel,
                              i);                                        // ...Setting the pixel's green intensity...
                show();                                                            // ...And updating the pixel after each change

            }

            break;

        case fadeDown:                                                        // If set to fadeDown:
            for (int i = startIntensity; i >=
                                         endIntensity; i--) {                // Run through each intensity from the start intensity to the end intensity...

                setPixelGreen(pixel,
                              i);                                        // ...Setting the pixel's green intensity...
                show();                                                            // ...And updating the pixel after each change

            }

            break;

    }

    if (revertAtCompletion)
        setPixelColor(pixel,
                      originalValues);        // If the user wants the pixel to revert to its original color, revert it here

    return;                                                                // Return

}


/** Method to fade a pixel's blue value from one intensity to another
	@param pixel The pixel that will be changed
	@param startIntensity The intensity that the pixel will begin at
	@param endIntensity The intensity that the pixel will end at
	@param revertAtCompletion Specifies if the pixel should revert to the color it had prior to the animation (default false) */

void AnimatedLEDStrip::fadePixelBlue(int pixel, int startIntensity, int endIntensity, bool revertAtCompletion = false) {

    fadeDirection fade;                                                    // Initialize the fade variable that will specify the direction the fade needs to go

    if (startIntensity > endIntensity)
        fade = fadeDown;                    // If the end intensity is lower than the start intensity, the function needs to fade down
    if (startIntensity < endIntensity)
        fade = fadeUp;                    // If the end intensity is higher than the start intensity, the function needs to fade up
    if (startIntensity == endIntensity)
        return;                            // If the start and end intensities are equal, the function has no work to do

    ColorContainer originalValues = getPixelColor(
            pixel);                // Save original color of the pixel so that the pixel can be reverted at the end if desired

    switch (fade) {                                                        // Switching on the fade variable
        case fadeUp:                                                        // If set to fadeUp:
            for (int i = startIntensity; i <=
                                         endIntensity; i++) {                // Run through each intensity from the start intensity to the end intensity...

                setPixelBlue(pixel,
                             i);                                        // ...Setting the pixel's blue intensity...
                show();                                                            // ...And updating the pixel after each change

            }

            break;

        case fadeDown:                                                        // If set to fadeDown:
            for (int i = startIntensity; i >=
                                         endIntensity; i--) {                // Run through each intensity from the start intensity to the end intensity...

                setPixelBlue(pixel,
                             i);                                        // ...Setting the pixel's blue intensity...
                show();                                                            // ...And updating the pixel after each change

            }

            break;

    }

    if (revertAtCompletion)
        setPixelColor(pixel,
                      originalValues);        // If the user wants the pixel to revert to its original color, revert it here

    return;                                                                // Return

}


/** Method to fade a pixel's red, green and blue values from one set of intensities to another
	@param pixel The pixel that will be changed
	@param startRedIntensity The intensity that the pixel's red value will begin at
	@param startGreenIntensity The intensity that the pixel's green value will begin at
	@param startBlueIntensity The intensity that the pixel's blue value will begin at
	@param endRedIntensity The intensity that the pixel's red value will end at
	@param endGreenIntensity The intensity that the pixel's green value will end at
	@param endBlueIntensity The intensity that the pixel's blue value will end at
	@param revertAtCompletion Specifies if the pixel should revert to the color it had prior to the animation (default false) */

void AnimatedLEDStrip::fadePixelAll(int pixel, int startRedIntensity, int startGreenIntensity, int startBlueIntensity,
                                    int endRedIntensity, int endGreenIntensity, int endBlueIntensity,
                                    bool revertAtCompletion = false) {

    ColorContainer originalValues = getPixelColor(
            pixel);                // Save the original color of the pixel so that the pixel can be reverted at the end if desired

    setPixelRed(pixel, startRedIntensity);                            // Set pixel's red intensity to startRedIntensity
    setPixelGreen(pixel,
                  startGreenIntensity);                        // Set pixel's green intensity to startGreenIntensity
    setPixelBlue(pixel,
                 startBlueIntensity);                            // Set pixel's blue intensity to startBlueIntensity

    bool redComplete = false;                                // Initialize redComplete, which will keep track of if the red intensity has reached endRedIntensity
    bool greenComplete = false;                                // Initialize greenComplete, which will keep track of if the green intensity has reached endGreenIntensity
    bool blueComplete = false;                                // Initialize blueComplete, which will keep track of if the blue intensity has reached endBlueIntensity

    while (!redComplete || !greenComplete ||
           !blueComplete) {            // While red, green and/or blue have not reached their final intensity, continue loop

        if (!redComplete) {                                                // If redComplete is still false

            if (getPixelRed(pixel) <
                endRedIntensity) {                    // If the red intensity is below endRedIntensity

                setPixelRed(pixel, getPixelRed(pixel) + 1);                    // Increase the red intensity

            } else if (getPixelRed(pixel) >
                       endRedIntensity) {            // Or if the red intensity is above endRedIntensity

                setPixelRed(pixel, getPixelRed(pixel) - 1);                    // Decrease the red intensity

            } else {                                                        // Otherwise red must be equal to endRedIntensity

                redComplete = true;                                                // So make redComplete true

            }

        }

        if (!greenComplete) {                                            // If greenComplete is still false

            if (getPixelGreen(pixel) <
                endGreenIntensity) {                // If the green intensity is below endGreenIntensity

                setPixelGreen(pixel, getPixelGreen(pixel) + 1);                // Increase the green intensity

            } else if (getPixelGreen(pixel) >
                       endGreenIntensity) {        // Or if the green intensity is above endGreenIntensity

                setPixelGreen(pixel, getPixelGreen(pixel) - 1);                // Decrease the green intensity

            } else {                                                        // Otherwise green must be equal to endGreenIntensity

                greenComplete = true;                                            // So make greenComplete true

            }

        }

        if (!blueComplete) {                                            // If blueComplete is still false

            if (getPixelBlue(pixel) <
                endBlueIntensity) {                    // If the blue intensity is below endBlueIntensity

                setPixelBlue(pixel, getPixelBlue(pixel) + 1);                // Increase the blue intensity

            } else if (getPixelBlue(pixel) >
                       endRedIntensity) {            // Or if the blue intensity is above endBlueIntensity

                setPixelBlue(pixel, getPixelBlue(pixel) - 1);                // Decrease the blue intensity

            } else {                                                        // Otherwise blue must be equal to endBlueIntensity

                blueComplete = true;                                            // So make blueComplete true

            }

        }

        show();                                                        // Send new color data to pixels

    }

    if (revertAtCompletion)
        setPixelColor(pixel,
                      originalValues);    // If the user wants the pixel to revert to its original color, revert it here

    return;                                                            // Return

}


/**	Method to run a Multi-Pixel Run animation
	Calls multiPixelRun(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection Specifies if the animation should run 'forward' or 'backward'
	@param colorValues The color of the 'running' pixels
	@param altColorValues The color of the remaining pixels */

void AnimatedLEDStrip::multiPixelRun(int spacing, direction chaseDirection, ColorContainer colorValues,
                                     ColorContainer altColorValues = CRGB::Black) {

    if (chaseDirection == backward) {

        for (int q = 0; q < spacing; q++) {

            setStripColor(altColorValues);

            for (int i = 0; i < getPixelCount(); i += spacing) {

                setPixelColor(i + (-(q - (spacing - 1))), colorValues);

            }

            show();
            delay(50);

            for (int i = 0; i < getPixelCount(); i += spacing) {

                setPixelColor(i + (-(q - (spacing - 1))), altColorValues);

            }

        }

    }

    if (chaseDirection == forward) {

        for (int q = spacing - 1; q >= 0; q--) {

            setStripColor(altColorValues);

            for (int i = 0; i < getPixelCount(); i += spacing) {

                setPixelColor(i + (-(q - (spacing - 1))), colorValues);

            }

            show();
            delay(50);

            for (int i = 0; i < getPixelCount(); i += spacing) {

                setPixelColor(i + (-(q - (spacing - 1))), altColorValues);

            }

        }

    }

    return;

}


/**	Overloaded method to run a Multi-Pixel Run animation
	Calls multiPixelRun(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection Specifies if the animation should run 'forward' or 'backward'
	@param rIn1 The red value for the 'running' pixels
	@param gIn1 The green value for the 'running' pixels
	@param bIn1 The blue value for the 'running' pixels
	@param rIn2 The red value for the remaining pixels (default 0)
	@param gIn2 The green value for the remaining pixels (default 0)
	@param bIn2 The blue value for the remaining pixels (default 0) */

void AnimatedLEDStrip::multiPixelRun(int spacing, direction chaseDirection, int rIn1, int gIn1, int bIn1, int rIn2 = 0,
                                     int gIn2 = 0, int bIn2 = 0) {

    ColorContainer temp1(rIn1, gIn1, bIn1);                    // Create temporary ColorContainer for colorValues
    ColorContainer temp2(rIn2, gIn2, bIn2);                    // Create temporary ColorContainer for altColorValues

    multiPixelRun(spacing, chaseDirection, temp1, temp2);        // Call main multiPixelRun method

    return;                                                        // Return

}


/** Method to run a Pixel Run animation
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param colorValues The color of the 'running' pixel
	@param altColorValues The color of the remaining pixels */

void AnimatedLEDStrip::pixelRun(direction movementDirection, ColorContainer colorValues,
                                ColorContainer altColorValues = CRGB::Black) {

    setStripColor(altColorValues);

    if (movementDirection == forward) {

        for (int q = 0; q < getPixelCount(); q++) {

            setPixelColor(q, colorValues);

            delay(50);

            setPixelColor(q, altColorValues);

        }

    }

    if (movementDirection == backward) {

        for (int q = getPixelCount() - 1; q >= 0; q--) {

            setPixelColor(q, colorValues);

            delay(50);

            setPixelColor(q, altColorValues);

        }

    }

    return;

}


/**	Overloaded method to run a Pixel Run animation
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param r1In The red value for the 'running' pixel
	@param g1In The green value for the 'running' pixel
	@param b1In The blue value for the 'running' pixel
	@param r2In The red value for the remaining pixels (default 0)
	@param g2In The green value for the remaining pixels (default 0)
	@param b2In The blue value for the remaining pixels (default 0) */

void AnimatedLEDStrip::pixelRun(direction movementDirection, int r1In, int g1In, int b1In, int r2In = 0, int g2In = 0,
                                int b2In = 0) {

    ColorContainer temp1 = ColorContainer(r1In, g1In, b1In);
    ColorContainer temp2 = ColorContainer(r2In, g2In, b2In);

    pixelRun(movementDirection, temp1, temp2);

    return;

}


/**	Method to run a Pixel Run with Trail animation
	Similar to a Pixel Run animation but the 'running' pixel has a trail behind it
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param colorValues The color of the 'running' pixel
	@param altColorValues The color the remaining pixels will fade to */

void AnimatedLEDStrip::pixelRunWithTrail(direction movementDirection, ColorContainer colorValues,
                                         ColorContainer altColorValues = CRGB::Black) {

    CRGB altColorCRGB = CRGB(altColorValues.getr(), altColorValues.getg(), altColorValues.getb());


    if (movementDirection == forward) {

        for (int q = 0; q < getPixelCount(); q++) {

            for (int i = 0; i < getPixelCount(); i++) {

                setPixelColor(i, blend(CRGB(getPixelColor(i).getr(), getPixelColor(i).getg(), getPixelColor(i).getb()),
                                       altColorCRGB, 60));

            }

            setPixelColor(q, colorValues);

            delay(50);

        }

    }

    if (movementDirection == backward) {

        for (int q = getPixelCount() - 1; q >= 0; q--) {

            for (int i = 0; i < getPixelCount(); i++) {

                setPixelColor(i, blend(CRGB(getPixelColor(i).getr(), getPixelColor(i).getg(), getPixelColor(i).getb()),
                                       altColorCRGB, 60));

            }

            setPixelColor(q, colorValues);

            delay(50);

        }

    }

    return;

}


/**	Overloaded method to run a Pixel Run animation
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param r1In The red value for the 'running' pixel
	@param g1In The green value for the 'running' pixel
	@param b1In The blue value for the 'running' pixel
	@param r2In The red value the remaining pixels will fade to (default 0)
	@param g2In The green value the remaining pixels will fade to (default 0)
	@param b2In The blue value the remaining pixels will fade to (default 0) */

void AnimatedLEDStrip::pixelRunWithTrail(direction movementDirection, int r1In, int g1In, int b1In, int r2In = 0,
                                         int g2In = 0, int b2In = 0) {

    ColorContainer temp1 = ColorContainer(r1In, g1In, b1In);
    ColorContainer temp2 = ColorContainer(r2In, g2In, b2In);

    pixelRunWithTrail(movementDirection, temp1, temp2);

    return;

}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Main smoothChase method
	@param palette The palette to be used (can be CRGBPalette16, CRGBPalette32, CRGBPalette256, CHSVPalette16, CHSVPalette32, CHSVPalette256, TProgmemRGBPalette16, TProgmemRGBPalette32, TProgmemHSVPalette16 or TProgmemHSVPalette32)
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param brightness The brightness of the LEDs (default 255) */

template<class paletteType>
void AnimatedLEDStrip::smoothChase(const paletteType &palette, direction movementDirection, uint8_t brightness) {

    if (movementDirection == forward) {

        for (uint8_t startIndex = 255; startIndex > 0; startIndex--) {                // Run through one cycle

            fillLEDsFromPalette(palette, startIndex, LINEARBLEND,
                                brightness);    // Fill in colors from the specified palette

            delay(10);

            show();                                                                    // Send color data to LEDs

        }

    } else if (movementDirection == backward) {

        for (uint8_t startIndex = 0; startIndex < 255; startIndex++) {                // Run through one cycle

            fillLEDsFromPalette(palette, startIndex, LINEARBLEND,
                                brightness);    // Fill in colors from the specified palette

            delay(10);

            show();                                                                    // Send color data to LEDs

        }

    }

    return;                                                                        // Return

}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<TProgmemRGBPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The TProgmemRGBPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param brightness The brightness of the LEDs (default 255) */

void AnimatedLEDStrip::smoothChase(const TProgmemRGBPalette16 &palette, direction movementDirection,
                                   uint8_t brightness = 255) {

    smoothChase<TProgmemRGBPalette16>(palette, movementDirection, brightness);    // Call main smoothChase method

    return;                                                                            // Return

}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param brightness The brightness of the LEDs (default 255) */

void
AnimatedLEDStrip::smoothChase(const CRGBPalette16 &palette, direction movementDirection, uint8_t brightness = 255) {

    smoothChase<CRGBPalette16>(palette, movementDirection, brightness);    // Call main smoothChase method

    return;                                                                    // Return

}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette32>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette32 palette to be used
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param brightness The brightness of the LEDs (default 255) */

void
AnimatedLEDStrip::smoothChase(const CRGBPalette32 &palette, direction movementDirection, uint8_t brightness = 255) {

    smoothChase<CRGBPalette32>(palette, movementDirection, brightness);    // Call main smoothChase method

    return;                                                                    // Return

}


/** Method to run a Smooth Chase animation using a RGB color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CRGBPalette256>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CRGBPalette256 palette to be used
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param brightness The brightness of the LEDs (default 255) */

void
AnimatedLEDStrip::smoothChase(const CRGBPalette256 &palette, direction movementDirection, uint8_t brightness = 255) {

    smoothChase<CRGBPalette256>(palette, movementDirection, brightness);    // Call main smoothChase method

    return;                                                                    // Return

}


/** Method to run a Smooth Chase animation using a HSV color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette16>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette16 palette to be used
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param brightness The brightness of the LEDs (default 255) */

void
AnimatedLEDStrip::smoothChase(const CHSVPalette16 &palette, direction movementDirection, uint8_t brightness = 255) {

    smoothChase<CHSVPalette16>(palette, movementDirection, brightness);    // Call main smoothChase method

    return;                                                                    // Return

}


/** Method to run a Smooth Chase animation using a HSV color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette32>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette32 palette to be used
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param brightness The brightness of the LEDs (default 255) */

void
AnimatedLEDStrip::smoothChase(const CHSVPalette32 &palette, direction movementDirection, uint8_t brightness = 255) {

    smoothChase<CHSVPalette32>(palette, movementDirection, brightness);    // Call main smoothChase method

    return;                                                                    // Return

}


/** Method to run a Smooth Chase animation using a HSV color palette that blends the colors to make smooth transitions between them
	Calls smoothChase<CHSVPalette256>(paletteType, direction, uint8_t) with inputted parameters
	@param palette The CHSVPalette256 palette to be used
	@param movementDirection Specifies if the animation should run 'forward' or 'backward'
	@param brightness The brightness of the LEDs (default 255) */

void
AnimatedLEDStrip::smoothChase(const CHSVPalette256 &palette, direction movementDirection, uint8_t brightness = 255) {

    smoothChase<CHSVPalette256>(palette, movementDirection, brightness);    // Call main smoothChase method

    return;                                                                    // Return

}


/**	Method to run a Sparkle animation
	@param sparkleColor The color that LEDs will be set to for a brief moment */

void AnimatedLEDStrip::sparkle(ColorContainer sparkleColor) {

    ColorContainer originalColor;

    shuffle();

    for (int i = 0; i < getPixelCount(); i++) {

        originalColor = getPixelColor(shuffleArray[i]);

        setPixelColor(shuffleArray[i], sparkleColor);

        show();

        delay(50);

        setPixelColor(shuffleArray[i], originalColor);

    }

}


/**	Overloaded method to run a sparkle animation
	@param rIn The red intensity for the sparkle color
	@param gIn The green intensity for the sparkle color
	@param bIn The blue intensity for the sparkle color */

void AnimatedLEDStrip::sparkle(int rIn, int gIn, int bIn) {

    ColorContainer temp(rIn, gIn, bIn);

    sparkle(temp);

    return;

}


/** Method to run a Sparkle to Color animation
	@param destinationColor The color all pixels will be set to by the end of the animation */

void AnimatedLEDStrip::sparkleToColor(ColorContainer destinationColor) {

    shuffle();

    for (int i = 0; i < getPixelCount(); i++) {

        setPixelColor(shuffleArray[i], destinationColor);

        show();

        delay(10);

    }

}


/**	Overloaded method to run a sparkle to color animation
	@param rIn The red intensity for the destination color
	@param gIn The green intensity for the destination color
	@param bIn The blue intensity for the destination color */

void AnimatedLEDStrip::sparkleToColor(int rIn, int gIn, int bIn) {

    ColorContainer temp = ColorContainer(rIn, gIn, bIn);

    sparkleToColor(temp);

    return;

}


/** Method to run a Wipe animation
	Changes the strip to the specified color, but one pixel at a time. Looks and works similar to a Pixel Run animation.
	@param colorValues The color that the strip will be at the end of the animation
	@param wipeDirection Specifies if the animation should run 'forward' or 'backward' */

void AnimatedLEDStrip::wipe(ColorContainer colorValues, direction wipeDirection) {

    if (wipeDirection == backward) {

        for (int i = getPixelCount() - 1; i >= 0; i--) {    // Run through the length of the strip

            setPixelColor(i, colorValues);                // Set pixel color to colorValues
            show();                                            // Send color data to LEDs

            delay(10);

        }

    }

    if (wipeDirection == forward) {

        for (int i = 0; i < getPixelCount(); i++) {        // Run through the length of the strip

            setPixelColor(i, colorValues);            // Set pixel color to colorValues
            show();                                        // Sendc color data to LEDs

            delay(10);

        }

    }

}


/**	Overloaded method to run a wipe animation
	@param rIn The red intensity for the destination color
	@param gIn The green intensity for the destination color
	@param bIn The blue intensity for the destination color
	@param wipeDirection Specifies if the animation should run 'forward' or 'backward' */

void AnimatedLEDStrip::wipe(int rIn, int gIn, int bIn, direction wipeDirection) {

    ColorContainer temp = ColorContainer(rIn, gIn, bIn);

    wipe(temp, wipeDirection);

    return;

}

void AnimatedLEDStrip::stack(direction stackDirection, ColorContainer colorValues) {

    if (movementDirection == forward) {

        for (int q = getPixelCount() - 1; q >= 0; q--) {

            for (int i = 0; i < q; i++) {
                setPixelColor(q, colorValues);
                delay(50);
                setPixelColor(q, altColorValues);
            }

            setPixelColor(q, colorValues)

        }

    }

    if (movementDirection == backward) {

        for (int q = 0; q < getPixelCount(); q++) {

            for (int i = getPixelCount() - 1; i > q; i--) {
                setPixelColor(i, colorValues);
                delay(50);
                setPixelColor(i, altColorValues);
            }

            setPixelColor(q, colorValues)

        }

    }

    return;

}


/**	@deprecated Use multiPixelRun( int spacing, direction chaseDirection, ColorContainer colorValues) instead
	Method to run a chase animation
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection Specifies if the animation should run 'forward' or 'backward'
	@param colorValues A ColorContainer containing the desired color */

void AnimatedLEDStrip::chase(int spacing, direction chaseDirection, ColorContainer colorValues) {

    ColorContainer Black;

    if (chaseDirection == forward) {

        for (int q = 0; q < spacing; q++) {

            for (int i = 0; i < getPixelCount(); i += spacing) {

                setPixelColor(i + (-(q - (spacing - 1))), colorValues);

            }

            show();
            delay(50);

            for (int i = 0; i < getPixelCount(); i += spacing) {

                setPixelColor(i + (-(q - (spacing - 1))), Black);

            }

        }

    }

    if (chaseDirection == backward) {

        for (int q = spacing - 1; q >= 0; q--) {

            for (int i = 0; i < getPixelCount(); i += spacing) {

                setPixelColor(i + (-(q - (spacing - 1))), colorValues);

            }

            show();
            delay(50);

            for (int i = 0; i < getPixelCount(); i += spacing) {

                setPixelColor(i + (-(q - (spacing - 1))), Black);

            }

        }

    }

    return;

}


/**	@deprecated Use multiPixelRun( int spacing, direction chaseDirection, int rIn, int gIn, int bIn) instead
	Method to run a chase animation
	Calls chase(int, direction, ColorContainer) with inputted parameters
	@param spacing The number of LEDs until the next LED to be lit is reached
	@param chaseDirection Specifies if the animation should run 'forward' or 'backward'
	@param rIn The value for the red LED
	@param gIn The value for the green LED
	@param bIn The value for the blue LED */

void AnimatedLEDStrip::chase(int spacing, direction chaseDirection, int rIn, int gIn, int bIn) {

    ColorContainer temp(rIn, gIn, bIn);

    chase(spacing, chaseDirection, temp);

    return;

}
