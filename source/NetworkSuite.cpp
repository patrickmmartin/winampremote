/*
 * NetworkSuite.cpp
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#include "catch.hpp"
#include "IPAddressResolver.h"
#include "ServerTester.h"
#include "ServerEnumerator.h"

/**
 * tests network enumeration
 */
TEST_CASE("Network/Net/Enumeration", "local Network enumeration")
{
    ServerEnumerator se;
    se.enumerateServers();
}

/**
 * tests the network interface on the running local server
 */
TEST_CASE("Network/RPC/Local", "test interface")
{
    ServerTester st;
    ServerInfo si;
    st.testServer("127.0.0.1", si);
    CHECK (si.status == SI_SUCCESS);
}

/**
 * tests attempting to connect with an invalid server is handled appropriately
 */
TEST_CASE("Network/RPC/Invalid", "test communication with invalid server")
{
    ServerTester st;
    ServerInfo si;
    st.testServer("__invalid__", si);
    CHECK_FALSE(si.status == SI_SUCCESS);
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
	CAPTURE(computerName);

	CHECK(0 == stricmp(computerName, ipr.resolvedName().c_str()));

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

