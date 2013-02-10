/*
 * NetworkSuite.cpp
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#include "catch.hpp"

#include "NetworkTest.h"
#include "IPAddressResolver.h"


/**
 * tests network enumeration
 */
TEST_CASE("Network/Net/Enumeration", "local Network enumeration")
{
	NetworkTest nt;
	// test network enumeration
	CHECK(nt.testEnumeration());
}

/**
 * tests the network interface on the running local server
 */
TEST_CASE("Network/RPC/Local", "test interface")
{
	NetworkTest nt;
	// test local server properties
	CHECK(nt.testLocalServer());
	// test abort
}

// disabling for now, as it burns time and such a test should only be run
// for the right prerequisites
TEST_CASE("Network/RPC/Servers", "test local servers")
{
	NetworkTest nt;
	// test network enumeration
	CHECK(nt.testEnumeration());
	CHECK(nt.testServerTest());
}

/**
 * tests that aborting network enumeration works
 */
TEST_CASE("Network/Net/Abort", "test abort")
{
	NetworkTest nt;
	// test abort
	CHECK(nt.testServerTestAbort());
}

/**
 * tests attempting to connect with an invalid server is handled appropriately
 */
TEST_CASE("Network/RPC/Invalid", "test communication with invalid server")
{
	NetworkTest nt;
	// test invalid
	CHECK(nt.testServerInvalid());
}

/**
 * tests IP resolution class
 */

TEST_CASE("Network/IP/Localhost", "tests the IP resolution for localhost")
{
	std::string host = "localhost";
	WinampRemote::Net::IPAddressResolver ipr(host);
	CAPTURE(ipr.hostname());
	CAPTURE(ipr.resolvedName());
	CHECK("" != ipr.resolvedName());

	// obtain the local machine name
	char computerName[MAX_COMPUTERNAME_LENGTH + 1] = "";
	DWORD nameLen = 15;
	GetComputerName(computerName, &nameLen);

	CHECK(computerName == ipr.resolvedName());

	CHECK(ipr.getAddresses().size());
	if (ipr.getAddresses().size())
		CHECK("127.0.0.1" == ipr.getAddresses().at(0));


}

TEST_CASE("Network/IP/Invalid", "tests the IP resolution for localhost")
{
	std::string host = "__localhost__";
	WinampRemote::Net::IPAddressResolver ipr(host);
	CAPTURE(ipr.hostname());
	CAPTURE(ipr.resolvedName());
	CHECK("" == ipr.resolvedName());

	CHECK( (unsigned int) 0 == ipr.getAddresses().size());


}

