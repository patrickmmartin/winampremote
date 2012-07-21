#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "NetworkSuite.h"
#include "WinampClientBase.h"
#include "ClientBinder.h"
#include "RPCFuncsU.h"
#include "ContextInfo.h"
#include <string.h>


namespace WinampRemote
{
namespace UnitTest
{

struct TestContext
{
	// blink and you might miss the declaration order matters
	WinampRemote::Context::ContextInfo ci;
	WinampRemote::Client::ClientBinder binder;
	TestContext() : ci(), binder(ci.computername().c_str(), "\\pipe\\winampremote")
	{
	}


};

} // end namespace UnitTest
} // end namespace WinampRemote


/**
 * extracts the text from an ERPCException
 */
/*
CATCH_TRANSLATE_EXCEPTION( ERPCException& ex )
{
    return ex.what();
}
*/

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

// disabling for now, as it burns time and such a test should only be run
// for the right prerequisites
/*
TEST_CASE("Network/Servers", "test local servers")
{
	NetworkSuite ns;
	// test network enumeration
	CHECK(ns.testEnumeration());
	CHECK(ns.testServerTest());
}
*/

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
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	CHECK(client.winampVersion() >= 0);

}

TEST_CASE("Client/Status", "test server status")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	WAPlaybackStatus status = client.getPlaybackStatus();
	CHECK( ((status == WA_NOT_PLAYING) || (status == WA_PLAYING) || (status == WA_PAUSED)) );

}

TEST_CASE("Client/Stop", "test stop")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	client.stopSong();
	CHECK( client.getPlaybackStatus() == WA_NOT_PLAYING );

}

TEST_CASE("Client/Play", "test play")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	client.playSong();
	CHECK( client.getPlaybackStatus() == WA_PLAYING );

}

TEST_CASE("Client/Pause", "test pause")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	client.playSong();
	client.pause();
	CHECK( client.getPlaybackStatus() == WA_PAUSED );

}

TEST_CASE("Client/Playlist", "test playlist")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	std::auto_ptr <vector<string> > playList (client.getPlayList() );
	CHECK( playList.get() );
	CHECK( playList->size() > (unsigned int) 0 );

}

TEST_CASE("Client/SendString", "test sendString")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.sendString("");
}

TEST_CASE("Client/NextSong", "test nextSong")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.nextSong();
}

TEST_CASE("Client/PreviousSong", "test previousSong")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.previousSong();
}

TEST_CASE("Client/PlaylistStart", "test playlistStart")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.playlistStart();
}

TEST_CASE("Client/PlaylistEnd", "test playlistEnd")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.playlistEnd();
}

TEST_CASE("Client/SetPlaylistIndex", "test setPlaylistIndex")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setPlaylistIndex(0);
}

TEST_CASE("Client/StartPlaylist", "test startPlaylist")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.startPlaylist();
}

TEST_CASE("Client/DeletePlaylist", "test deletePlaylist")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.deletePlaylist();
}

TEST_CASE("Client/StopWithFade", "test stopWithFade")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.stopWithFade();
}

TEST_CASE("Client/StopAfterCurrent", "test stopAfterCurrent")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.stopAfterCurrent();
}

TEST_CASE("Client/Forward5", "test forward5")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.forward5();
}

TEST_CASE("Client/Back5", "test back5")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.back5();
}

TEST_CASE("Client/VolumeUp", "test volumeUp")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.volumeUp();
}

TEST_CASE("Client/VolumeDown", "test volumeDown")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.volumeDown();
}


TEST_CASE("Client/setVolume", "test setVolume")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setVolume(50);
}

TEST_CASE("Client/ToggleShuffle", "test toggleShuffle")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.toggleShuffle();
}

TEST_CASE("Client/ToggleRepeat", "test toggleRepeat")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.toggleRepeat();
}

TEST_CASE("Client/ToggleAutoload", "test toggleAutoload")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.toggleAutoload();
}

TEST_CASE("Client/GetTimes", "test getTimes")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int songLength, songPos;
	client.getTimes(songLength, songPos);
}

TEST_CASE_NORETURN( "./exception/ERPCException", "ERPCException can be translated" )
{
    throw ERPCException(RPC_S_UNKNOWN_PRINCIPAL);
}


