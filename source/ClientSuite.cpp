#include <string.h>
#include "WinampClientBase.h"
#include "ClientBinder.h"
#include "ContextInfo.h"
#include "RPCException.h"
#include "StringVectorPrinter.h"
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
	/**
	 * create a scoped context
	 */
	WinampRemote::Context::ContextInfo ci;
	/**
	 * create a scoped binder dependent upon the context
	 */
	WinampRemote::Client::ClientBinder binder;
    // NOTA BENE: declaration order guarantees the correct initialisation order
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
	CHECK(playlistItem == client.getPlayListItem(0));

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
TEST_CASE("Client/PlaylistSize", "test getPlaylistLength")
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
	// this returns void: what is a valid test?
	CHECK(true);
}

/**
 * tests advancing song works
 */
TEST_CASE("Client/SongNext", "test nextSong")
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
TEST_CASE("Client/SongPrevious", "test previousSong")
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
TEST_CASE("Client/PlaylistStart", "test playlistStart position")
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
TEST_CASE("Client/PlaylistIndexSet", "test setPlaylistIndex")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setPlaylistIndex(0);
	CHECK(client.getCurrentPlayPosition() == 0);
}

/**
 * tests starting playback
 */
TEST_CASE("Client/PlaylistStartBegins", "test startPlaylist begins play")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.stopSong();
	client.startPlaylist();
	CHECK(client.getPlaybackStatus() == WA_PLAYING);
}

TEST_CASE("Client/SetPlaylist", "test setPlaylist")
{

	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	std::auto_ptr <vector<string> > originalPlayList (client.getPlayList(false) );

	WinampRemote::Utils::StringVectorPrinter original(*originalPlayList);
	CAPTURE(original);

	client.setPlayList(*originalPlayList);

	WinampRemote::Utils::StringVectorPrinter current(*originalPlayList);
	CAPTURE(current);

	CHECK(original.sstr.str() == current.sstr.str());

}
/**
 * test delete of playlist
 */
TEST_CASE("Client/DeletePlaylist", "test deletePlaylist")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	std::auto_ptr <vector<string> > originalPlayList (client.getPlayList(false) );


	CAPTURE(WinampRemote::Utils::StringVectorPrinter(*originalPlayList));

	CHECK( originalPlayList->size() ==  (unsigned int) client.getPlaylistLength() );
	client.deletePlaylist();

	CHECK( 0 == client.getPlaylistLength() );

	client.setPlayList(*originalPlayList);

	std::auto_ptr <vector<string> > playList (client.getPlayList(false) );

	CAPTURE(WinampRemote::Utils::StringVectorPrinter(*playList));

	CHECK( originalPlayList->size() ==  playList->size() );
}

/**
 * test insert into playlist
 */
TEST_CASE("Client/InsertPlaylist", "test insertPlaylist")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	std::auto_ptr <vector<string> > originalPlayList (client.getPlayList(false) );

	WinampRemote::Utils::StringVectorPrinter original (*originalPlayList);
	CAPTURE(original);

	client.insertPlayList(*originalPlayList, 10);

	std::auto_ptr <vector<string> > newPlayList (client.getPlayList(false) );

	WinampRemote::Utils::StringVectorPrinter current (*newPlayList);
	CAPTURE(current);

	unsigned int newListLength = client.getPlaylistLength();
	client.setPlayList(*originalPlayList);

	CHECK( (newPlayList->size()) == newListLength );

	CHECK( (2 * originalPlayList->size()) == newListLength );


}


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

	client.startPlaylist();
	client.stopAfterCurrent();
	CHECK(client.getPlaybackStatus() == WA_PLAYING);

	int songLength = 0, songPos = 0;
	client.getTimes(songLength, songPos);
	CAPTURE(songLength);
	CAPTURE(songPos);
	client.setTime((songLength * 1000) - 500);
	Sleep(1000);
	CHECK(client.getPlaybackStatus() == WA_NOT_PLAYING);

}

/**
 * tests set time works
 */
TEST_CASE("Client/TimeSet", "test setTime")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.startPlaylist();
	client.pause();
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

	client.playSong();
	client.setTime(7000);
	Sleep(50);
	client.forward5();
	Sleep(50);
	CHECK( abs ( client.getTime() - 12000) < 1000 );
}

/**
 * tests back 5 works
 */
TEST_CASE("Client/Back5", "test back5")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.playSong();
	client.setTime(13000);
	Sleep(50);
	client.back5();
	Sleep(50);
	CHECK( abs ( client.getTime() - 8000) < 1000 );
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
TEST_CASE("Client/VolumeSet", "test setVolume")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setVolume(50);
	CHECK(client.getVolume() == 50);
}

/**
 * tests set volume works
 */
TEST_CASE("Client/PanningSet", "test setPanning")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setPanning(0);
	CHECK(client.getPanning() == 0);
}


/**
 * tests set volume works
 */
TEST_CASE("Client/PanningGet", "test getPanning")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int panning = client.getPanning();
	CHECK(client.getPanning() == panning);
}

/**
 * tests that shuffle toggle works
 */
TEST_CASE("Client/ShuffleToggle", "test toggleShuffle")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int shuffle = client.getShuffle();
	client.toggleShuffle();
	CHECK(client.getShuffle() != shuffle);
}

/**
 * tests that set Shuffle works
 */
TEST_CASE("Client/ShuffleSet", "test setShuffle")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setShuffle(0);
	CHECK(0 == client.getShuffle());
	client.setShuffle(1);
	CHECK(1 == client.getShuffle());

}

/**
 * tests that get Shuffle works
 */
TEST_CASE("Client/ShuffleGet", "test getShuffle")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int shuffle = client.getShuffle();
	CHECK(shuffle == client.getShuffle());
}

/**
 * tests that toggle repeat works
 */
TEST_CASE("Client/RepeatToggle", "test toggleRepeat")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int repeat = client.getRepeat();
	client.toggleRepeat();
	CHECK(client.getRepeat() != repeat);
}

/**
 * tests that set Repeat works
 */
TEST_CASE("Client/RepeatSet", "test setRepeat")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setRepeat(1);
	CHECK(client.getRepeat() == 1);
	client.setRepeat(0);
	CHECK(client.getRepeat() == 0);



}

/**
 * tests that get repeat works
 */
TEST_CASE("Client/RepeatGet", "test getRepeat")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int repeat = client.getRepeat();
	CHECK(repeat == client.getRepeat());

}

/**
 * tests that autoload toggle works
 */
TEST_CASE("Client/AutoloadToggle", "test toggleAutoload")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int autoload = client.getAutoload();
	client.toggleAutoload();
	CHECK(client.getAutoload() != autoload);
}

/**
 * tests that set autoload works
 */
TEST_CASE("Client/AutoloadSet", "test setAutoload")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setAutoload(0);
	CHECK(client.getAutoload() == 0);
	client.setAutoload(1);
	CHECK(client.getAutoload() == 1);
}

/**
 * tests that get autoload works
 */
TEST_CASE("Client/AutoloadGet", "test getAutoload")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int current = client.getAutoload();
	CHECK(current == client.getAutoload());
}

/**
 * tests that EQ toggle works
 */
TEST_CASE("Client/EQOnToggle", "test toggleEQ")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int previous = client.getEQOn();
	client.toggleEQOn();
	CHECK(client.getEQOn() != previous);
}

/**
 * tests that set EQ On works
 */
TEST_CASE("Client/EQOnSet", "test setEQOn")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	client.setEQOn(0);
	CHECK(client.getEQOn() == 0);
	client.setEQOn(1);
	CHECK(client.getEQOn() == 1);
}

/**
 * tests that get EQOn works
 */
TEST_CASE("Client/EQOnGet", "test getAutoload")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int current = client.getEQOn();
	CHECK(current == client.getEQOn());
}

/**
 * tests that getting the output times works
 */
TEST_CASE("Client/TimesGet", "test getTimes")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;

	int songLength, songPos;
	client.startPlaylist();
	client.getTimes(songLength, songPos);
	CHECK(songPos > 0);
	CHECK(songLength > 0);
}

/**
 * tests getting and setting EQ
 */
TEST_CASE("Client/EQGet", "test getEQ")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	for (int eqindex = 0 ; eqindex < 11 ; eqindex++)
	{
		byte eqvalue = client.getEQData(eqindex);
		CHECK(eqvalue == (byte) client.getEQData(eqindex));
	}
}

/**
 * tests getting and setting EQ
 */
TEST_CASE("Client/EQSet", "test setEQ")
{
	WinampRemote::UnitTest::TestContext tc;
	WinampRemote::Client::WinampClientBase client;
	int eqvalues[11] = {0};
	for (int eqindex = 0 ; eqindex < 11 ; eqindex++)
	{
		eqvalues[eqindex] = client.getEQData(eqindex);
		client.setEQData(eqindex, eqvalues[eqindex] + 1);
	}

	for (int eqindex = 0 ; eqindex < 11 ; eqindex++)
	{
		CHECK(client.getEQData(eqindex) == eqvalues[eqindex] + 1);
	}

}

/**
 * tests exception handling
 */
TEST_CASE_NORETURN( "./exception/ERPCException", "ERPCException can handled" )
{
    throw ERPCException(RPC_S_UNKNOWN_PRINCIPAL);
}
