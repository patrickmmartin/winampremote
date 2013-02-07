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
	NetworkTest nt;
	// test network enumeration
	CHECK(nt.testEnumeration());
}

/**
 * tests the network interface on the running local server
 */
TEST_CASE("Network/Local", "test interface")
{
	NetworkTest nt;
	// test local server properties
	CHECK(nt.testLocalServer());
	// test abort
}

// disabling for now, as it burns time and such a test should only be run
// for the right prerequisites
TEST_CASE("Network/Servers", "test local servers")
{
	NetworkTest nt;
	// test network enumeration
	CHECK(nt.testEnumeration());
	CHECK(nt.testServerTest());
}

/**
 * tests that aborting network enumeration works
 */
TEST_CASE("Network/Abort", "test abort")
{
	NetworkTest nt;
	// test abort
	CHECK(nt.testServerTestAbort());
}

/**
 * tests attempting to connect with an invalid server is handled appropriately
 */
TEST_CASE("Network/Invalid", "test communication with invalid server")
{
	NetworkTest nt;
	// test invalid
	CHECK(nt.testServerInvalid());
}



