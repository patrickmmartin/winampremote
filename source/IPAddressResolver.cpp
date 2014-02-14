/*
 * IPAddressResolver.cpp
 *
 *  Created on: 9 Feb 2013
 *      Author: Patrick
 */

#include "IPAddressResolver.h"

#include <winsock.h>


namespace WinampRemote
{
namespace Net
{


bool GetIPAddress(std::string& const HostName, std::string &ResolvedName,
							 vector<std::string> &Addresses,
							 vector<std::string> &Aliases)
{

  // must NOT attempt to modify this
  const hostent * hent = NULL;
  WSADATA wsaData;
  WORD wVersionRequested = MAKEWORD(2, 2);
  int err;

  err = WSAStartup(wVersionRequested, &wsaData);
  if (err == 0)
  {
    hent = gethostbyname(HostName.c_str());
    WSACleanup();
  }

  if (hent)
  {
    in_addr addr;
    Addresses.clear();
    Aliases.clear();
    int i = 0;

    while ( (LPIN_ADDR)hent->h_addr_list[i] != NULL)
    {
      addr.S_un.S_addr = ( (LPIN_ADDR)hent->h_addr_list[i] )->s_addr;
      Addresses.push_back(inet_ntoa( addr ));
      i++;
    }

    i = 0;

    while ( (char *)hent->h_aliases[i] != NULL)
    {
      Aliases.push_back(hent->h_aliases[i]);
      i++;
    }

    ResolvedName = hent->h_name;
    return true;
  }
  else
  {
	/*
	int WSAError = WSAGetLastError();
    switch(WSAError)
    {
      case WSANOTINITIALISED : throw new EIPException("A successful WSAStartup must occur before using this function."); // no break
      case WSAENETDOWN  : throw new EIPException("The network subsystem has failed."); // no break
      case WSAHOST_NOT_FOUND  : throw new EIPException("Authoritative Answer Host not found."); // no break
      case WSATRY_AGAIN  : throw new EIPException("Non-Authoritative Host not found, or server failure."); // no break
      case WSANO_RECOVERY  : throw new EIPException("Non-recoverable error occurred."); // no break
      case WSANO_DATA  : throw new EIPException("Valid name, no data record of requested type."); // no break
      case WSAEINPROGRESS  : throw new EIPException("A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function."); // no break
      case WSAEFAULT  : throw new EIPException("The name argument is not a valid part of the user address space."); // no break
      case WSAEINTR  : throw new EIPException("The (blocking) call was canceled through WSACancelBlockingCall."); // no break
      default : throw new EIPException(AnsiString().sprintf("Unknown WSA Error %d", WSAError));
    }
    */
	return false;
  }
}



IPAddressResolver::IPAddressResolver(std::string& const hostname):
                                        m_hostname(hostname), m_resolved(),
                                        m_addresses(), m_aliases()

{

	GetIPAddress(m_hostname, m_resolved, m_addresses, m_aliases);

}

IPAddressResolver::~IPAddressResolver()
{
}

const std::vector<std::string> & IPAddressResolver::getAddresses() const
{
	return m_addresses;
}

const std::vector<std::string> & IPAddressResolver::getAliases() const
{
	return m_aliases;
}
const std::string & IPAddressResolver::hostname() const
{
	return m_hostname;
}

const std::string & IPAddressResolver::resolvedName() const
{
	return m_resolved;
}

} /* namespace Net */
} /* namespace WinampRemote */
