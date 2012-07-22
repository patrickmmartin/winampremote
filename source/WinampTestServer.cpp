
#include "WinampTestServer.h"

namespace WinampRemote
{
namespace Server
{

WinampTestServer::WinampTestServer()
{
}

WinampTestServer::~WinampTestServer()
{
	// destroy any owned resources here
}

string WinampTestServer::WinampVersion()
{
    return "test server";
}

void WinampTestServer::ExecuteCommand(WinampCommand MessageToExecute)
{

	switch (MessageToExecute)
	{

		IPC_PLAYFILE:
		IPC_DELETE:
		IPC_STARTPLAY:
		IPC_CHDIR:
		IPC_ISPLAYING:
		IPC_JUMPTOTIME:
		IPC_SETPLAYLISTPOS:
		IPC_SETVOLUME:
		IPC_SETPANNING:

		IPC_SETEQDATA:

		IPC_SETSHUFFLEOPTION:
		IPC_SETREPEATOPTION:

		WINAMP_FILE_REPEAT:
		WINAMP_FILE_SHUFFLE:
		WINAMP_HIGH_PRIORITY:
		WINAMP_FILE_PLAY:
		WINAMP_VOLUMEUP:
		WINAMP_VOLUMEDOWN:
		WINAMP_FFWD5S:
		WINAMP_REW5S:
		return;
	}

		throw std::runtime_error("WinampTestServer::ExecuteCommand not implemented");

}

void WinampTestServer::ExecuteStringCommand(char * CommandString, WinampCommand Command)
{
	//throw std::runtime_error("WinampTestServer::ExecuteStringCommand not implemented");
}

int WinampTestServer::QueryInt(WinampCommand Command, int Data)
{

	switch (Command)
	{

		IPC_GETVERSION:
		IPC_ISPLAYING:
		IPC_GETOUTPUTTIME:
		IPC_GETLISTLENGTH:

		IPC_GETLISTPOS:
		IPC_GETINFO:
		IPC_GETEQDATA:

		IPC_GETPLAYLISTFILE:
		IPC_GETPLAYLISTTITLE:
		IPC_GETSHUFFLEOPTION:
		IPC_GETREPEATOPTION:

		return 1;

	}


	throw std::runtime_error("WinampTestServer::QueryInt not implemented");
}

string WinampTestServer::QueryString(WinampCommand Command, int Data)
{
	switch (Command)
	{
		case IPC_GETPLAYLISTTITLE :
			return std::string("playlist item title ");
		case IPC_GETPLAYLISTFILE :
			return std::string("playlist item file ");
	}
	throw std::runtime_error("WinampTestServer::QueryString not implemented");
}

} /* namespace Server */
} /* namespace WinampRemote */
