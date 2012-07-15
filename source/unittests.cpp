#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "NetworkSuite.h"


TEST_CASE("Network/Enumeration", "local Network enumeration")
{
	NetworkSuite ns;
	// test network enumeration
	CHECK(ns.testEnumeration());
}

TEST_CASE("Network/Local", "test interface")
{
	NetworkSuite ns;
	// test local server properties
	CHECK(ns.testLocalServer());
	// test abort
}

TEST_CASE("Network/Servers", "test local servers")
{
	NetworkSuite ns;
	// test network enumeration
	CHECK(ns.testEnumeration());
	// TODO: uses the server list from the prior test
	// TODO: would be useful to have the server list controllable to validate testing
	CHECK(ns.testServerTest());
}

TEST_CASE("Network/Abort", "test abort")
{
	NetworkSuite ns;
	// test abort
	CHECK(ns.testServerTestAbort());
}

TEST_CASE("Network/Invalid", "test communication with invalid server")
{
	NetworkSuite ns;
	// test invalid
	CHECK(ns.testServerInvalid());
}
