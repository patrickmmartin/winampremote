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

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/

#include <vcl.h>
#pragma hdrstop

#include "VersionInfoU.h"

const int MaxVersionKeys = 10;
const AnsiString VersionKeyNames[MaxVersionKeys] =
       {"CompanyName", "FileDescription", "FileVersion",
        "InternalName", "LegalCopyright", "LegalTrademarks",
        "OriginalFilename", "ProductName", "ProductVersion",
        "Comments"};


__fastcall TModuleVersionInfo::TModuleVersionInfo(AnsiString ThisSourceFile)
{

  int ThisInfo;
  UINT InfoLength;
  DWORD Len;
  DWORD Handle;
  int * PCharset;


  // Get size of version info
  Len = GetFileVersionInfoSize (ThisSourceFile.c_str(), &Handle);
  // Allocate VersionInfo buffer size
   VersionInfo = new BYTE[Len];
  // Get version info
  if (GetFileVersionInfo (ThisSourceFile.c_str(), Handle, Len, VersionInfo))
  {
    // Get translation info for Language / CharSet IDs
    if (VerQueryValue ( (void *) VersionInfo, "\\VarFileInfo\\Translation", (void **) &PCharset, &InfoLength))
    {
      LangCharset = AnsiString().sprintf("%.4x%.4x", LOWORD(*PCharset), HIWORD(*PCharset));
      InfoAvailable = True;
      // Get standard version information
      for (ThisInfo = 0 ; ThisInfo < MaxVersionKeys; ThisInfo++)
        StandardKeys[ThisInfo] = GetKey (VersionKeyNames[ThisInfo]);
      }
    }
  }


__fastcall TModuleVersionInfo::~TModuleVersionInfo(void)
{

  if (VersionInfo)
    delete[] VersionInfo;
}


AnsiString __fastcall TModuleVersionInfo::GetKey (AnsiString ThisKeyName) const
{
  UINT InfoLength;
  char * buf;
  AnsiString Result;

  if (InfoAvailable)
  {
    Result.SetLength(255);
    if (VerQueryValue ( (void *) VersionInfo,
                        AnsiString().sprintf("\\StringFileInfo\\%s\\%s",
                                              LangCharset.c_str(),
                                              ThisKeyName.c_str()
                                              ).c_str(),
                         (void **) &buf, &InfoLength))


    {
      Result = buf;
    }
    else
    {
      Result = "";
    }
  }
  else
  {
    Result = "N/A";
  }
  return Result;


}

AnsiString __fastcall TModuleVersionInfo::GetVersionInfo (int Index) const
{

  return StandardKeys[Index];

}





#pragma package(smart_init)
