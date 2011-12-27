/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000 - 2011  Patrick M. Martin

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

#ifndef WAINTSTRS_H
#define WAINTSTRS_H

#pragma hdrstop

#include <string>

const std::string sWinampUnavailable;


const std::string sIPC_GETVERSION;
const std::string sIPC_PLAYFILE;
const std::string sIPC_DELETE;
const std::string sIPC_STARTPLAY;
const std::string sIPC_CHDIR;
const std::string sIPC_ISPLAYING;
const std::string sIPC_GETOUTPUTTIME;
const std::string sIPC_JUMPTOTIME;
const std::string sIPC_WRITEPLAYLIST;
const std::string sIPC_SETPLAYLISTPOS;
const std::string sIPC_SETVOLUME;
const std::string sIPC_SETPANNING;
const std::string sIPC_GETLISTLENGTH;

const std::string sIPC_GETPLAYLISTFILE;
const std::string sIPC_GETPLAYLISTTITLE;

const std::string sIPC_GETLISTPOS;
const std::string sIPC_GETINFO;
const std::string sIPC_GETEQDATA;
const std::string sIPC_SETEQDATA;

const std::string sIPC_GETSHUFFLEOPTION;
const std::string sIPC_GETREPEATOPTION;
const std::string sIPC_SETSHUFFLEOPTION;
const std::string sIPC_SETREPEATOPTION;

const std::string sWINAMP_FILE_QUIT;
const std::string sWINAMP_OPTIONS_PREFS;
const std::string sWINAMP_OPTIONS_AOT;
const std::string sWINAMP_FILE_REPEAT;
const std::string sWINAMP_FILE_SHUFFLE;
const std::string sWINAMP_HIGH_PRIORITY;
const std::string sWINAMP_FILE_PLAY;
const std::string sWINAMP_OPTIONS_EQ;
const std::string sWINAMP_HELP_ABOUT;
const std::string sWINAMP_OPTIONS_PLEDIT;
const std::string sWINAMP_VOLUMEUP;
const std::string sWINAMP_VOLUMEDOWN;
const std::string sWINAMP_FFWD5S;
const std::string sWINAMP_REW5S;

const std::string sWINAMP_PREVIOUS;
const std::string sWINAMP_PLAYENTRY;
const std::string sWINAMP_PAUSE;
const std::string sWINAMP_STOP;
const std::string sWINAMP_NEXT;

const std::string sWINAMP_BACK5S;
const std::string sWINAMP_OPENFILE;
  //
const std::string sWINAMP_STOPFADE;
const std::string sWINAMP_FORWARD5S;

const std::string sWINAMP_STARTOFPLAYLIST;
const std::string sWINAMP_OPENLOCATION;
  //
const std::string sWINAMP_STOPAFTERCURRENT;
const std::string sWINAMP_ENDOFPLAYLIST;

const std::string sIDC_SORT_FILENAME;
const std::string sIDC_SORT_FILETITLE;
const std::string sIDC_SORT_ENTIREFILENAME;
const std::string sIDC_SELECTALL;
const std::string sIDC_SELECTNONE;
const std::string sIDC_SELECTINV;

const std::string sIDM_EQ_LOADPRE;
const std::string sIDM_EQ_LOADMP3;
const std::string sIDM_EQ_LOADDEFAULT;
const std::string sIDM_EQ_SAVEPRE;
const std::string sIDM_EQ_SAVEMP3;
const std::string sIDM_EQ_SAVEDEFAULT;
const std::string sIDM_EQ_DELPRE;
const std::string sIDM_EQ_DELMP3;


const std::string sWINAMP_JUMP;
const std::string sWINAMP_JUMPFILE;
const std::string sWINAMP_JUMP10FWD;
const std::string sWINAMP_JUMP10BACK;
const std::string sWINAMP_PREVSONG;


#endif //  WAINTSTRS_H
