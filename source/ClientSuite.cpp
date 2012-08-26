#include "WinampClientBase.h"
#include "ClientBinder.h"
#include "ContextInfo.h"
#include <string.h>
#include "RPCFuncsU.h"
#include "catch.hpp"

namespace WinampRemote
{
namespace UnitTest
{

/**
 * class to wrap up setting the global context consistently for the Client tests
 */
struct TestContext
{
	// TODO : member construction order
    // blink and you might miss the fact that declaration order matters for the members
	WinampRemote::Context::ContextInfo ci;
	WinampRemote::Client::ClientBinder binder;
	TestContext() : ci(), binder(ci.computername().c_str(), "\\pipe\\winampremote")
	{
	}

};

} // end namespace UnitTest
} // end namespace WinampRemote


/**
 * test obtaining the server version
 */
TEST_CASE("Client/Version", "test server version")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	CHECK(client.winampVersion() >= 0);

}

/**
 * tests the server status returned is in range
 */
TEST_CASE("Client/Status", "test server status")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	WAPlaybackStatus status = client.getPlaybackStatus();
	CHECK( ((status == WA_NOT_PLAYING) || (status == WA_PLAYING) || (status == WA_PAUSED)) );

}

/**
 * tests that play is received and honoured
 */
TEST_CASE("Client/Play", "test play")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	INFO("initiate play request");
	client.playSong();
	INFO("the process is not synchronous and takes a while");
	Sleep(500);
	INFO("test playback state");
	CHECK( client.getPlaybackStatus() == WA_PLAYING );

}

/**
 * tests that pause is received and honoured
 */
TEST_CASE("Client/Pause", "test pause")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	INFO("initiate play request");
	client.playSong();
	INFO("the process is not synchronous and takes a while");
	Sleep(500);
	CHECK( client.getPlaybackStatus() == WA_PLAYING );
	INFO("state is playing - initiate pause request");
	client.pause();
	INFO("the process is not synchronous and takes a while");
	Sleep(500);
	INFO("test playback state");
	CHECK( client.getPlaybackStatus() == WA_PAUSED );

}

/**
 * tests that stop is received and honoured
 */
TEST_CASE("Client/Stop", "test stop")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	INFO("initiate play request");
	client.playSong();
	INFO("the process is not synchronous and takes a while");
	Sleep(500);
	CHECK( client.getPlaybackStatus() == WA_PLAYING );
	INFO("state is playing - initiate stop request");
	client.stopSong();
	INFO("the process is not synchronous and takes a while");
	Sleep(500);
	CHECK( client.getPlaybackStatus() == WA_NOT_PLAYING );

}

/**
 * tests that the playlist item is returned
 */
TEST_CASE("Client/PlaylistItem", "test playlist item")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	string playlistItem = client.getPlayListItem(0);
	CAPTURE(playlistItem);

}

/**
 * tests that the current playlist item is returned
 */
TEST_CASE("Client/PlaylistCurrentItem", "test playlist current item")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	string current = client.getPlayListItem(1);
	client.setPlaylistIndex(1);
	Sleep(1000);
	int index = client.getCurrentPlayPosition();
	CHECK(index == 1);
	string playlistItem = client.getCurrentPlayListItem(index);
	CHECK(current == playlistItem);

}

/**
 * tests that the playlist is returned
 */
TEST_CASE("Client/Playlist", "test playlist")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	std::auto_ptr <vector<string> > playList (client.getPlayList() );
	CHECK( playList->size() ==  (unsigned int) client.getPlaylistLength() );

}

/**
 * tests that string is sent
 */
TEST_CASE("Client/SendString", "test sendString")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.sendString();
}

/**
 * tests advancing song works
 */
TEST_CASE("Client/NextSong", "test nextSong")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setPlaylistIndex(1);
	Sleep(1000);
	CHECK(client.getCurrentPlayPosition() == 1);
	client.nextSong();
	Sleep(1000);
	CHECK(client.getCurrentPlayPosition() == 2);
}

/**
 * tests rewinding one song works
 */
TEST_CASE("Client/PreviousSong", "test previousSong")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setPlaylistIndex(2);
	Sleep(1000);
	CHECK(client.getCurrentPlayPosition() == 2);
	client.previousSong();
	Sleep(1000);
	CHECK(client.getCurrentPlayPosition() == 1);

}

/**
 * tests move to start of playlist
 */
TEST_CASE("Client/PlaylistStart", "test playlistStart")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setPlaylistIndex(2);
	Sleep(1000);
	CHECK(client.getCurrentPlayPosition() == 2);
	client.playlistStart();
	Sleep(1000);
	CHECK(client.getCurrentPlayPosition() == 0);
}

/**
 * tests move to end of playlist
 */
TEST_CASE("Client/PlaylistEnd", "test playlistEnd")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.playlistEnd();
	Sleep(1000);
	CHECK( client.getCurrentPlayPosition() ==  client.getPlaylistLength() - 1);
}

/**
 * tests setting the playlist index works
 */
TEST_CASE("Client/SetPlaylistIndex", "test setPlaylistIndex")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setPlaylistIndex(0);
	CHECK(client.getCurrentPlayPosition() == 0);
}

/**
 * tests starting playback
 */
TEST_CASE("Client/StartPlaylist", "test startPlaylist")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.stopSong();
	client.startPlaylist();
	CHECK(client.getPlaybackStatus() == WA_PLAYING);
}

/**
 * test delete of playlist
 */
//TEST_CASE("Client/DeletePlaylist", "test deletePlaylist")
//{
//	WinampRemote::UnitTest::TestContext tc;
//	WinampRemote::Client::WinampClientBase client;
//
//	client.deletePlaylist();
//}

/**
 * tests stop song with fade effect
 */
TEST_CASE("Client/StopWithFade", "test stopWithFade")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.startPlaylist();
	client.stopWithFade();
	Sleep(500);
	CHECK(client.getPlaybackStatus() == WA_NOT_PLAYING);
}

/**
 * tests stop after current command
 */
TEST_CASE("Client/StopAfterCurrent", "test stopAfterCurrent")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	// TODO - #95 complete test coverage for this
	client.stopAfterCurrent();
	FAIL("no test implemented");
}

/**
 * tests set time works
 */
TEST_CASE("Client/SetTime", "test setTime")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.stopSong();
	client.setTime(3000);
	CHECK(client.getTime() == 3000 );
}

/**
 * tests forward 5 works
 */
TEST_CASE("Client/Forward5", "test forward5")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.stopSong();
	client.setTime(0);
	client.forward5();
	CHECK(client.getTime() == 5000 );
}

/**
 * tests back 5 works
 */
TEST_CASE("Client/Back5", "test back5")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.stopSong();
	client.setTime(10000);
	client.back5();
	CHECK(client.getTime() == 5000 );
}

/**
 * tests volume up works
 */
TEST_CASE("Client/VolumeUp", "test volumeUp")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int volume = client.getVolume();
	if (volume == 255)
	{
		client.setVolume(254);
		volume = client.getVolume();
	}
	client.volumeUp();
	CHECK(client.getVolume() == volume + 1);
}

/**
 * tests volume down works
 */
TEST_CASE("Client/VolumeDown", "test volumeDown")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int volume = client.getVolume();
	if (volume == 0)
	{
		client.setVolume(1);
		volume = client.getVolume();
	}
	client.volumeDown();
	CHECK(client.getVolume() == volume - 1);
}

/**
 * tests set volume works
 */
TEST_CASE("Client/setVolume", "test setVolume")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setVolume(50);
	CHECK(client.getVolume() == 50);
}

/**
 * tests that shuffle toggle works
 */
TEST_CASE("Client/ToggleShuffle", "test toggleShuffle")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	// TODO - #95 complete test coverage for this
	client.toggleShuffle();
	FAIL("no test implemented");
}

/**
 * tests that repeat works
 */
TEST_CASE("Client/ToggleRepeat", "test toggleRepeat")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	// TODO - #95 complete test coverage for this
	client.toggleRepeat();
	FAIL("no test implemented");
}

/**
 * tests that autoload toggle works
 */
TEST_CASE("Client/ToggleAutoload", "test toggleAutoload")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	// TODO - #95 complete test coverage for this
	client.toggleAutoload();
	FAIL("no test implemented");
}

/**
 * tests that getting the output times works
 */
TEST_CASE("Client/GetTimes", "test getTimes")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	// TODO - #95 complete test coverage for this
	int songLength, songPos;
	client.getTimes(songLength, songPos);
	FAIL("no test implemented");
}

/**
 * tests exception handling
 */
TEST_CASE_NORETURN( "./exception/ERPCException", "ERPCException can handled" )
{
    throw ERPCException(RPC_S_UNKNOWN_PRINCIPAL);
}
