#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "NetworkSuite.h"
#include "WinampClientBase.h"
#include "ClientBinder.h"

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

TEST_CASE("Client/Version", "test server version")
{
	WinampRemote::Client::ClientBinder binder("localhost", "\\pipe\\winampremote");
	WinampRemote::Client::WinampClientBase client;
	CHECK(client.winampVersion() >= 0);

}

TEST_CASE("Client/Status", "test server status")
{
	WinampRemote::Client::ClientBinder binder("localhost", "\\pipe\\winampremote");
	WinampRemote::Client::WinampClientBase client;
	WAPlaybackStatus status = client.getPlaybackStatus();
	CHECK( ((status == WA_NOT_PLAYING) || (status == WA_PLAYING) || (status == WA_PAUSED)) );

}

TEST_CASE("Client/Stop", "test stop")
{
	WinampRemote::Client::ClientBinder binder("localhost", "\\pipe\\winampremote");
	WinampRemote::Client::WinampClientBase client;
	client.stopSong();
	CHECK( client.getPlaybackStatus() == WA_NOT_PLAYING );

}

TEST_CASE("Client/Play", "test play")
{
	WinampRemote::Client::ClientBinder binder("localhost", "\\pipe\\winampremote");
	WinampRemote::Client::WinampClientBase client;
	client.playSong();
	CHECK( client.getPlaybackStatus() == WA_PLAYING );

}

TEST_CASE("Client/Pause", "test pause")
{
	WinampRemote::Client::ClientBinder binder("localhost", "\\pipe\\winampremote");
	WinampRemote::Client::WinampClientBase client;
	client.playSong();
	client.pause();
	CHECK( client.getPlaybackStatus() == WA_PAUSED );

}

TEST_CASE("Client/Playlist", "test playlist")
{
	WinampRemote::Client::ClientBinder binder("localhost", "\\pipe\\winampremote");
	WinampRemote::Client::WinampClientBase client;

    std::auto_ptr <vector<string> > playList (client.getPlayList() );
    CHECK( playList.get() );
    CHECK( playList->size() > (unsigned int) 0 );

}




