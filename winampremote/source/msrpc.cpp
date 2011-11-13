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

#include <windows.h>
// force the RPC functions unit to use a non-VCL exception
#define NO_VCL_EXCEPTION
// get the nice wrappers in the RPC functions unit
#include "RPCFuncsU.h"
// RPC error descriptions
#include "RPCErrors.h"
// force the waint unit to unit non-VCL, non localised
#define WAINT_NO_VCL
// winamp interface declarations
#include "waint.h"
// get the import prototypes
#include "rpcimport.h"


#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}
//---------------------------------------------------------------------------
