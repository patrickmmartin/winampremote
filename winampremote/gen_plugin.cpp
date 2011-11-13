//---------------------------------------------------------------------------
#include <vcl.h>
#include <registry.hpp>
#pragma hdrstop

#include "gen_plugin.h"
#include "ServerDLLF.h"
#include "ConfigDLLF.h"
#include "waint.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

winampGeneralPurposePlugin plugin =
{
	GPPHDR_VER,
	"Remote Control Suite 1.3 RPC interface ©pmm 2000",
	init,
	config,
	quit,
    0,
    0
};


void config();
void quit();
int init();



/*
extern "C" int __declspec(dllexport)  __stdcall MyFunction();
 int __stdcall MyFunction(){
   return 0;
   }
*/   

/*
important : need the __stdccall to lose the underscores without setting
a compiler option that busts VCL forms
*/

extern "C" winampGeneralPurposePlugin *  __declspec(dllexport)  __stdcall  winampGetGeneralPurposePlugin()
{
    OutputDebugString("queried for plugin information...");
	return &plugin;
}

void config(){

  OutputDebugString("gen_RPCinterface.dll config");
  TConfigForm *frmConfig = new TConfigForm(NULL);
  try{
    frmConfig->ShowModal();
    }
    __finally{
      delete frmConfig;
    }
 }

void quit(){
  OutputDebugString("gen_RPCinterface.dll quit");
    if (frmMain != NULL){
      try{
        frmMain->Close();
        delete frmMain;
        }
      catch ( ... ){
        //
        }
      frmMain = NULL;
    }
  }

int init(){
TRegistry * reg;
AnsiString str;
  OutputDebugString("gen_RPCinterface.dll init");
  if (frmMain == NULL){
  try{
    hwnd_winamp = plugin.hwndParent;
    frmMain = new TfrmMain(NULL);
    try{
        reg = new TRegistry();
        reg->OpenKey("software\\PMMSoft\\Winamp controller\\server settings", true);
        str = reg->ReadString("Visible");
        if (str.LowerCase() == "true")
          frmMain->Show();
      }
  __finally {
    delete reg;
    }

    }
  catch (...){
    delete frmMain;
    frmMain = NULL;
    }
  }
  return 0;
  }
