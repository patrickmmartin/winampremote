/*
 * UtilsSuite.cpp
 *
 *  Created on: 29 Sep 2012
 *      Author: Patrick
 */


#include "catch.hpp"

#include "ColourU.h"

TEST_CASE("Utils/ColourPeriodic", "tests the output of the periodic function")
{

	CHECK( periodic(0) == 1.0 );
	CHECK( abs(periodic(0.5)) < 1e-10 );
	CHECK( periodic(1) == 1.0 );

}

TEST_CASE("Utils/ColourRainbow", "tests the colour output")
{

	CHECK(rainbowColour(0) == 46026);
	CHECK(rainbowColour(250) == 16665396);
	CHECK(rainbowColour(500) == 46026);
}
