/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2002

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

Patrick M. Martin may be reached by email at patrickmmartin@freenet.co.uk.
*/

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
