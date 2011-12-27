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

#pragma hdrstop
#include <stdio.h>
#include "waint.h"
#include "waintstrs.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

HWND hwnd_winamp;

char winampver[MAX_WINAMPVER_LEN];

void GethWnd_WinAmp()
{
char * windowname = "Winamp v1.x";
 hwnd_winamp = FindWindow(windowname, NULL);
}

void ExecuteMessage(int Command){
#ifdef HWND_UPDATE
  GethWnd_WinAmp();
#endif
  PostMessage(hwnd_winamp, WM_COMMAND, Command, 0);
  }

// 1.7+ send a command with a string parameter
void ExecuteStringMessage(char * CommandString, int Command){
  COPYDATASTRUCT cds;

#ifdef HWND_UPDATE
  GethWnd_WinAmp();
#endif
  cds.dwData = Command;
  cds.lpData = (void *) CommandString;
  cds.cbData = strlen((char *) cds.lpData) + 1;
  SendMessage(hwnd_winamp, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds);
  }

 // Send a message to Winamp and return an Integer
int GetAmpInt(int Command, int Data)
{
#ifdef HWND_UPDATE
  GethWnd_WinAmp();
#endif
  return SendMessage(hwnd_winamp, WM_WA_IPC, Data, Command);
}

// Send a message to Winamp and return a String
char * GetAmpStr(int Command, int Data)
{
#ifdef HWND_UPDATE
  GethWnd_WinAmp();
#endif

  /*return (char *) */ SendMessage(hwnd_winamp, WM_WA_IPC, Data, Command);
  return (char *) SendMessage(hwnd_winamp, WM_WA_IPC, Data, Command);
}



char * GetWinampVersion(void){
int retval;
#ifdef HWND_UPDATE
  GethWnd_WinAmp();
#endif
  retval = GetAmpInt(IPC_GETVERSION,  0);
  return WinampVersion(retval);
}


char * StandardVersion(int retval)
{
// formats the version according to (semi) standard numeric scheme

  if (((retval >> 4) & 0xf) != 0)
    sprintf(winampver, "winamp %x.%x%x%x", retval >> 12, (retval >> 8) & 0xf , (retval >> 4) & 0xf , retval & 0xf);
  else
    sprintf(winampver, "winamp %x.%x%x", retval >> 12, (retval >> 8) & 0xf , retval & 0xf);
  return winampver;
}


char * WinampVersion(int retval){
  switch (retval){
  //special cases
  case  0x00 :
    strcpy(winampver, "Winamp unavailable");
    break;
  case  0x1551 :
    strcpy(winampver, "winamp 1.55");
    break;
  case  0x16A0 :
    strcpy(winampver, "winamp 1.6b");
    break;
  case  0x16AF :
    strcpy(winampver, "winamp 1.60");
    break;
  case  0x16B0 :
    strcpy(winampver, "winamp 1.61");
    break;
  case  0x16B1 :
    strcpy(winampver, "winamp 1.62");
    break;
  case  0x16B3 :
    strcpy(winampver, "winamp 1.64");
    break;
  case  0x16B4 :
    strcpy(winampver, "winamp 1.666");
    break;
  case  0x16B5 :
    strcpy(winampver, "winamp 1.69");
    break;

  default :
   if (retval > 0x2604){
      StandardVersion(retval);
      }
    else{
      StandardVersion(retval);
      }
    }
  return winampver;
  }

const char * WinampCommandDesc(int Command){

  switch(Command){

   case IPC_GETVERSION : return sIPC_GETVERSION.c_str();
   case IPC_PLAYFILE : return sIPC_PLAYFILE.c_str();
   case IPC_DELETE : return sIPC_DELETE.c_str();
   case IPC_STARTPLAY : return sIPC_STARTPLAY.c_str();
   case IPC_CHDIR : return sIPC_CHDIR.c_str();
   case IPC_ISPLAYING : return sIPC_ISPLAYING.c_str();
   case IPC_GETOUTPUTTIME : return sIPC_GETOUTPUTTIME.c_str();
   case IPC_JUMPTOTIME : return sIPC_JUMPTOTIME.c_str();
   case IPC_WRITEPLAYLIST : return sIPC_WRITEPLAYLIST.c_str();
   case IPC_SETPLAYLISTPOS : return sIPC_SETPLAYLISTPOS.c_str();
   case IPC_SETVOLUME : return sIPC_SETVOLUME.c_str();
   case IPC_SETPANNING : return sIPC_SETPANNING.c_str();
   case IPC_GETLISTLENGTH : return sIPC_GETLISTLENGTH.c_str();

   case IPC_GETPLAYLISTFILE : return sIPC_GETPLAYLISTFILE.c_str();
   case IPC_GETPLAYLISTTITLE : return sIPC_GETPLAYLISTTITLE.c_str();

   case IPC_GETLISTPOS : return sIPC_GETLISTPOS.c_str();
   case IPC_GETINFO : return sIPC_GETINFO.c_str();
   case IPC_GETEQDATA : return sIPC_GETEQDATA.c_str();
   case IPC_SETEQDATA : return sIPC_SETEQDATA.c_str();

   case IPC_GETSHUFFLEOPTION : return sIPC_GETSHUFFLEOPTION.c_str();
   case IPC_GETREPEATOPTION : return sIPC_GETREPEATOPTION.c_str();
   case IPC_SETSHUFFLEOPTION : return sIPC_SETSHUFFLEOPTION.c_str();
   case IPC_SETREPEATOPTION : return sIPC_SETREPEATOPTION.c_str();

   case WINAMP_FILE_QUIT : return sWINAMP_FILE_QUIT.c_str();
   case WINAMP_OPTIONS_PREFS : return sWINAMP_OPTIONS_PREFS.c_str();
   case WINAMP_OPTIONS_AOT : return sWINAMP_OPTIONS_AOT.c_str();
   case WINAMP_FILE_REPEAT : return sWINAMP_FILE_REPEAT.c_str();
   case WINAMP_FILE_SHUFFLE : return sWINAMP_FILE_SHUFFLE.c_str();
   case WINAMP_HIGH_PRIORITY : return sWINAMP_HIGH_PRIORITY.c_str();
   case WINAMP_FILE_PLAY : return sWINAMP_FILE_PLAY.c_str();
   case WINAMP_OPTIONS_EQ : return sWINAMP_OPTIONS_EQ.c_str();
   case WINAMP_HELP_ABOUT : return sWINAMP_HELP_ABOUT.c_str();
   case WINAMP_OPTIONS_PLEDIT : return sWINAMP_OPTIONS_PLEDIT.c_str();
   case WINAMP_VOLUMEUP : return sWINAMP_VOLUMEUP.c_str();
   case WINAMP_VOLUMEDOWN : return sWINAMP_VOLUMEDOWN.c_str();
   case WINAMP_FFWD5S : return sWINAMP_FFWD5S.c_str();
   case WINAMP_REW5S  : return sWINAMP_REW5S.c_str();

   case WINAMP_PREVIOUS : return sWINAMP_PREVIOUS.c_str();
   case WINAMP_PLAYENTRY : return sWINAMP_PLAYENTRY.c_str();
   case WINAMP_PAUSE : return sWINAMP_PAUSE.c_str();
   case WINAMP_STOP : return sWINAMP_STOP.c_str();
   case WINAMP_NEXT : return sWINAMP_NEXT.c_str();

   case WINAMP_BACK5S : return sWINAMP_BACK5S.c_str();
   case WINAMP_OPENFILE : return sWINAMP_OPENFILE.c_str();
  // case ?? WINAMP_BUTTON3_SHIFT
   case WINAMP_STOPFADE : return sWINAMP_STOPFADE.c_str();
   case WINAMP_FORWARD5S : return sWINAMP_FORWARD5S.c_str();

   case WINAMP_STARTOFPLAYLIST : return sWINAMP_STARTOFPLAYLIST.c_str();
   case WINAMP_OPENLOCATION : return sWINAMP_OPENLOCATION.c_str();
  // case ?? WINAMP_BUTTON3_CTRL
   case WINAMP_STOPAFTERCURRENT : return sWINAMP_STOPAFTERCURRENT.c_str();
   case WINAMP_ENDOFPLAYLIST : return sWINAMP_ENDOFPLAYLIST.c_str();

   case IDC_SORT_FILENAME : return sIDC_SORT_FILENAME.c_str();
   case IDC_SORT_FILETITLE : return sIDC_SORT_FILETITLE.c_str();
   case IDC_SORT_ENTIREFILENAME : return sIDC_SORT_ENTIREFILENAME.c_str();
   case IDC_SELECTALL : return sIDC_SELECTALL.c_str();
   case IDC_SELECTNONE : return sIDC_SELECTNONE.c_str();
   case IDC_SELECTINV : return sIDC_SELECTINV.c_str();

   case IDM_EQ_LOADPRE : return sIDM_EQ_LOADPRE.c_str();
   case IDM_EQ_LOADMP3 : return sIDM_EQ_LOADMP3.c_str();
   case IDM_EQ_LOADDEFAULT : return sIDM_EQ_LOADDEFAULT.c_str();
   case IDM_EQ_SAVEPRE : return sIDM_EQ_SAVEPRE.c_str();
   case IDM_EQ_SAVEMP3 : return sIDM_EQ_SAVEMP3.c_str();
   case IDM_EQ_SAVEDEFAULT : return sIDM_EQ_SAVEDEFAULT.c_str();
   case IDM_EQ_DELPRE : return sIDM_EQ_DELPRE.c_str();
   case IDM_EQ_DELMP3 : return sIDM_EQ_DELMP3.c_str();


   case WINAMP_JUMP  : return sWINAMP_JUMP.c_str();
   case WINAMP_JUMPFILE : return sWINAMP_JUMPFILE.c_str();
   case WINAMP_JUMP10FWD : return sWINAMP_JUMP10FWD.c_str();
   case WINAMP_JUMP10BACK : return sWINAMP_JUMP10BACK.c_str();
   case WINAMP_PREVSONG : return sWINAMP_PREVSONG.c_str();

   default:
      return "";
    }

  }

