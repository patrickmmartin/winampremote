/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2012

Copyright (C) 2000,2001,2012  Patrick M. Martin

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

#pragma hdrstop
#include <registry.hpp>         // TRegistry
#include "VersionInfoU.h"       // TVersionInfo
#include "gen_plugin.h"         // winamp plugin declarations
#include "ServerDLLF.h"         // for main form
#include "ConfigDLLF.h"         // for config form
#include "waint.h"              // extern HWND variable
// buffer for the control structure

char VerString[MAX_PATH + 1];

winampGeneralPurposePlugin plugin =
{
	GPPHDR_VER,
	VerString,
	init,
	config,
	quit,
    0,
    0
};


void config();
void quit();
int init();



extern "C" winampGeneralPurposePlugin *  __declspec(dllexport)  __stdcall winampGetGeneralPurposePlugin()
{

  TModuleVersionInfo * VI;
  char FileName[MAX_PATH + 1];

  GetModuleFileName(HInstance, FileName, MAX_PATH);
  VI = new TModuleVersionInfo(FileName);

  strncpy(VerString,
          AnsiString("Winamp Remote Control Suite " + VI->FileVersion).c_str(),
          MAX_PATH);

  delete VI;

  OutputDebugString("RPCInterface get config");
  return &plugin;
}



void config(void)
{

  OutputDebugString("RPCInterface config");
  TConfigForm *frmConfig = new TConfigForm(NULL);
  try
  {
    frmConfig->ShowModal();
  }
  __finally
  {
    delete frmConfig;
  }
}



void quit(void)
{
  OutputDebugString("RPCInterface quit");
  if (frmPluginMain != NULL)
  {
    try
    {
      frmPluginMain->Close();
      delete frmPluginMain;
    }
    __finally
    {
      frmPluginMain = NULL;
    }
  }
}



int init()
{
  OutputDebugString("RPCInterface init");
TRegistry * reg;
AnsiString str;
  if (frmPluginMain == NULL)
  {
    try
    {
      // pass on the provided parameters
	  // this gets better behaviour for VCL dlls
      Application->Handle = plugin.hwndParent;
      frmPluginMain = new TfrmPluginMain(Application);
      try
      {
        // set parent handle
        reg = new TRegistry();
        reg->OpenKey("software\\PMMSoft\\Winamp controller\\server settings", true);
        str = reg->ReadString("Visible");
        if (str.LowerCase() == "true")
          frmPluginMain->Show();
      }
      __finally
      {
        delete reg;
      }
    }
    catch (...)
    {
      delete frmPluginMain;
      frmPluginMain = NULL;
    }
  }
  return 0;
}
