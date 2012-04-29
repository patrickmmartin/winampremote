/*
 winamp remote control suite © Patrick Michael Martin 2000 - 2012

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


HWND hwnd_winamp = NULL;
const int MAX_WINAMPVER_LEN = 80;

HWND setWinampHwnd(HWND HWinamp)
{

	/* TODO: should this be thread-safe?
	 probably irrelevant except for external monitors of winamp */
	HWND retval = hwnd_winamp;
	hwnd_winamp = HWinamp;
	return retval;
}

/*
 * Utility function to obtain the winamp handle when out of process
 * uses FindWindow, which is incredibly crufty, so let's not put this in a header.
static void GethWnd_WinAmp()
{
	char * windowname = "Winamp v1.x";
	hwnd_winamp = FindWindow(windowname, NULL);
}
*/

void LocalExecuteCommand(int Command)
{
	PostMessage(hwnd_winamp, WM_COMMAND, Command, 0);
}

// 1.7+ send a command with a string parameter
void LocalExecuteStringCommand(char * CommandString, int Command)
{
	COPYDATASTRUCT cds;

	cds.dwData = Command;
	cds.lpData = (void *) CommandString;
	cds.cbData = strlen((char *) cds.lpData) + 1;
	SendMessage(hwnd_winamp, WM_COPYDATA, (WPARAM) NULL, (LPARAM) &cds);
}

// Send a message to Winamp and return an Integer
int LocalQueryInt(int Command, int Data)
{
	return SendMessage(hwnd_winamp, WM_WA_IPC, Data, Command);
}

// Send a message to Winamp and return a String
char * LocalQueryString(int Command, int Data)
{
	return (char *) SendMessage(hwnd_winamp, WM_WA_IPC, Data, Command);
}

/**
 * static buffer for the winamp version
 */
static char winampver[MAX_WINAMPVER_LEN];

/**
 * Returns the formatted standard Winamp version
 * @param version
 * @return
 */
static char * StandardVersion(int version)
{
// formats the version according to (semi) standard numeric scheme
	if (((version >> 4) & 0xf) != 0)
		sprintf(winampver, "winamp %x.%x%x%x", version >> 12,
				(version >> 8) & 0xf, (version >> 4) & 0xf, version & 0xf);
	else
		sprintf(winampver, "winamp %x.%x%x", version >> 12, (version >> 8) & 0xf,
				version & 0xf);
	return winampver;
}

const char * WinampVersionString(int version)
{

	switch (version)
	{
	//special cases
	case 0x00:
		strcpy(winampver, "Winamp unavailable");
		break;
	case 0x1551:
		strcpy(winampver, "winamp 1.55");
		break;
	case 0x16A0:
		strcpy(winampver, "winamp 1.6b");
		break;
	case 0x16AF:
		strcpy(winampver, "winamp 1.60");
		break;
	case 0x16B0:
		strcpy(winampver, "winamp 1.61");
		break;
	case 0x16B1:
		strcpy(winampver, "winamp 1.62");
		break;
	case 0x16B3:
		strcpy(winampver, "winamp 1.64");
		break;
	case 0x16B4:
		strcpy(winampver, "winamp 1.666");
		break;
	case 0x16B5:
		strcpy(winampver, "winamp 1.69");
		break;

	default:
		if (version > 0x2604)
		{
			StandardVersion(version);
		}
		else
		{
			StandardVersion(version);
		}
	}
	return winampver;
}

const char * LocalGetWinampVersion()
{
	int retval;
	retval = LocalQueryInt(IPC_GETVERSION, 0);
	return WinampVersionString(retval);
}

const char * WinampCommandDesc(int Command)
{

	switch (Command)
	{

	case IPC_GETVERSION:
		return "Get Winamp Version";
	case IPC_PLAYFILE:
		return "Play File";
	case IPC_DELETE:
		return "Delete Playlist";
	case IPC_STARTPLAY:
		return "Start Play";
	case IPC_CHDIR:
		return "Change Directory";
	case IPC_ISPLAYING:
		return "Winamp Play Status";
	case IPC_GETOUTPUTTIME:
		return "Get Output Time";
	case IPC_JUMPTOTIME:
		return "Jump To Time";
	case IPC_WRITEPLAYLIST:
		return "Write Playlist";
	case IPC_SETPLAYLISTPOS:
		return "Set Playlist Position";
	case IPC_SETVOLUME:
		return "Set Volume";
	case IPC_SETPANNING:
		return "Set Panning";
	case IPC_GETLISTLENGTH:
		return "Get Playlist Length";

	case IPC_GETPLAYLISTFILE:
		return "Get PlayList File";
	case IPC_GETPLAYLISTTITLE:
		return "Get Playlist Title";

	case IPC_GETLISTPOS:
		return "Get Playlist Position";
	case IPC_GETINFO:
		return "Get Information";
	case IPC_GETEQDATA:
		return "Get EQ data";
	case IPC_SETEQDATA:
		return "Set EQ Data";

	case IPC_GETSHUFFLEOPTION:
		return "Get Shuffle Option";
	case IPC_GETREPEATOPTION:
		return "Get Repeat Option";
	case IPC_SETSHUFFLEOPTION:
		return "Set Shuffle Option";
	case IPC_SETREPEATOPTION:
		return "Set Repeat Option";

	case WINAMP_FILE_QUIT:
		return "Quit";
	case WINAMP_OPTIONS_PREFS:
		return "Options Preferences";
	case WINAMP_OPTIONS_AOT:
		return "Options Always On Top";
	case WINAMP_FILE_REPEAT:
		return "File Repeat";
	case WINAMP_FILE_SHUFFLE:
		return "File Shuffle";
	case WINAMP_HIGH_PRIORITY:
		return "High Priority";
	case WINAMP_FILE_PLAY:
		return "Play File";
	case WINAMP_OPTIONS_EQ:
		return "Options EQ";
	case WINAMP_HELP_ABOUT:
		return "Help About";
	case WINAMP_OPTIONS_PLEDIT:
		return "Option Playlist Editor";
	case WINAMP_VOLUMEUP:
		return "Volume Up";
	case WINAMP_VOLUMEDOWN:
		return "Volume Down";
	case WINAMP_FFWD5S:
		return "Forward 5s";
	case WINAMP_REW5S:
		return "Back 5s";

	case WINAMP_PREVIOUS:
		return "Previous Song";
	case WINAMP_PLAYENTRY:
		return "Play Entry";
	case WINAMP_PAUSE:
		return "Pause";
	case WINAMP_STOP:
		return "Stop";
	case WINAMP_NEXT:
		return "Next Song";

	case WINAMP_BACK5S:
		return "Back 5s";
	case WINAMP_OPENFILE:
		return "Open File";
		// case ?? WINAMP_BUTTON3_SHIFT
	case WINAMP_STOPFADE:
		return "Stop With Fade";
	case WINAMP_FORWARD5S:
		return "Foward 5s";

	case WINAMP_STARTOFPLAYLIST:
		return "Start OF Playlist";
	case WINAMP_OPENLOCATION:
		return "Open Location";
		// case ?? WINAMP_BUTTON3_CTRL
	case WINAMP_STOPAFTERCURRENT:
		return "Stop After Current";
	case WINAMP_ENDOFPLAYLIST:
		return "End of Playlist";

	case IDC_SORT_FILENAME:
		return "Sort Filename";
	case IDC_SORT_FILETITLE:
		return "Sort File Title";
	case IDC_SORT_ENTIREFILENAME:
		return "Sort Entire Filename";
	case IDC_SELECTALL:
		return "SelectAll";
	case IDC_SELECTNONE:
		return "Select None";
	case IDC_SELECTINV:
		return "Selection Invert";

	case IDM_EQ_LOADPRE:
		return "Load Preset";
	case IDM_EQ_LOADMP3:
		return "Load MP3";
	case IDM_EQ_LOADDEFAULT:
		return "Load Default";
	case IDM_EQ_SAVEPRE:
		return "Save Preset";
	case IDM_EQ_SAVEMP3:
		return "Save MP3";
	case IDM_EQ_SAVEDEFAULT:
		return "Save Default";
	case IDM_EQ_DELPRE:
		return "Delete Preset";
	case IDM_EQ_DELMP3:
		return "Delete MP3";

	case WINAMP_JUMP:
		return "Jump";
	case WINAMP_JUMPFILE:
		return "Jump File";
	case WINAMP_JUMP10FWD:
		return "Jump 10 Forward";
	case WINAMP_JUMP10BACK:
		return "Jump 10 Back";
	case WINAMP_PREVSONG:
		return "Previous Song";

	default:
		return "";
	}

}

