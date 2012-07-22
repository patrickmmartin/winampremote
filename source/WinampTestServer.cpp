
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
	throw std::runtime_error("WinampTestServer::ExecuteCommand not implemented");
}

void WinampTestServer::ExecuteStringCommand(char * CommandString, WinampCommand Command)
{
	throw std::runtime_error("WinampTestServer::ExecuteStringCommand not implemented");
}

int WinampTestServer::QueryInt(WinampCommand Command, int Data)
{
	throw std::runtime_error("WinampTestServer::QueryInt not implemented");
}

string WinampTestServer::QueryString(WinampCommand Command, int Data)
{
	throw std::runtime_error("WinampTestServer::QueryString not implemented");
}

} /* namespace Server */
} /* namespace WinampRemote */
