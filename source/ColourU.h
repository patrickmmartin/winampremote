
#ifndef ColourUH
#define ColourUH


/**
 * Returns a periodic (cos ^2) function from any real input
 * the periodicity is 1
 * @param percent
 * @return the result
 */
double periodic(double percent);

/**
 * Yields a 32 bit RGB colour value from the input value
 * @param value
 * @return the colour
 */
TColor rainbowColour(int value);

#endif
