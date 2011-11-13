// winamp remote control suite ©Patrick Michael Martin 2000
//
// IPAddressU.cpp
//
// gets IP Address(es)
//

#include <vcl.h>
#pragma hdrstop
#include <winsock.h>
#include "IPAddressU.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall GetIPAddress(char * HostName, AnsiString &ResolvedName, TStringList * Addresses, TStringList * Aliases)
{

  // must NOT attempt to modify this
  const hostent * hent;
  hent = gethostbyname(HostName);
  if (hent)
  {
    in_addr addr;
    Addresses->Clear();
    Aliases->Clear();
    int i = 0;

    while ( (LPIN_ADDR)hent->h_addr_list[i] != NULL)
    {
      addr.S_un.S_addr = ( (LPIN_ADDR)hent->h_addr_list[i] )->s_addr;
      Addresses->Add(inet_ntoa( addr ));
      i++;
    }

    i = 0;

    while ( (char *)hent->h_aliases[i] != NULL)
    {
      Aliases->Add(hent->h_aliases[i]);
      i++;
    }

    ResolvedName = hent->h_name;
  }
  else
  {
    switch(WSAGetLastError())
    {
      case WSANOTINITIALISED : throw EIPException("A successful WSAStartup must occur before using this function.");;
      case WSAENETDOWN  : throw EIPException("The network subsystem has failed.");
      case WSAHOST_NOT_FOUND  : throw EIPException("Authoritative Answer Host not found.");
      case WSATRY_AGAIN  : throw EIPException("Non-Authoritative Host not found, or server failure.");
      case WSANO_RECOVERY  : throw EIPException("Nonrecoverable error occurred.");
      case WSANO_DATA  : throw EIPException("Valid name, no data record of requested type.");
      case WSAEINPROGRESS  : throw EIPException("A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");
      case WSAEFAULT  : throw EIPException("The name argument is not a valid part of the user address space.");
      case WSAEINTR  : throw EIPException("The (blocking) call was canceled through WSACancelBlockingCall.");
      default : throw EIPException("Unknown Socket Error");
    }
  }
}
