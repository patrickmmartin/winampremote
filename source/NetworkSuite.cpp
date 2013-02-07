/*
 * NetworkSuite.cpp
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#include "catch.hpp"

#include "NetworkTest.h"

/* FIXME: this class needs thorough refactoring
 * test cases should be unrolled more into the ...Suite class from ..Test
 */

/*
 * FIXME: remove the VCL only style
 */


/**
 * tests network enumeration
 */
TEST_CASE("Network/Enumeration", "local Network enumeration")
{
	NetworkTest ns;
	// test network enumeration
	CHECK(ns.testEnumeration());
}

/**
 * tests the network interface on the running local server
 */
TEST_CASE("Network/Local", "test interface")
{
	NetworkTest ns;
	// test local server properties
	CHECK(ns.testLocalServer());
	// test abort
}

// disabling for now, as it burns time and such a test should only be run
// for the right prerequisites
TEST_CASE("Network/Servers", "test local servers")
{
	NetworkTest ns;
	// test network enumeration
	CHECK(ns.testEnumeration());
	CHECK(ns.testServerTest());
}

/**
 * tests that aborting network enumeration works
 */
TEST_CASE("Network/Abort", "test abort")
{
	NetworkTest ns;
	// test abort
	CHECK(ns.testServerTestAbort());
}

/**
 * tests attempting to connect with an invalid server is handled appropriately
 */
TEST_CASE("Network/Invalid", "test communication with invalid server")
{
	NetworkTest ns;
	// test invalid
	CHECK(ns.testServerInvalid());
}



