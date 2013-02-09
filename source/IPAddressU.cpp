/*
winamp remote control suite �Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000,2001,2002  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/

#include <vcl.h>
#pragma hdrstop
#include <winsock.h>
#include "IPAddressU.h"

// TODO remove the VCL style

#pragma package(smart_init)

void __fastcall GetIPAddress(char * HostName, AnsiString &ResolvedName, TStringList * Addresses, TStringList * Aliases)
{

  // must NOT attempt to modify this
  const hostent * hent = NULL;
  WSADATA wsaData;
  WORD wVersionRequested = MAKEWORD(2, 2);
  int err;

  err = WSAStartup(wVersionRequested, &wsaData);
  if (err == 0)
  {
    hent = gethostbyname(HostName);
    WSACleanup();
  }

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
  }
}
