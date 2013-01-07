#ifndef waintH
#define waintH

#include "windows.h"
#include <iosfwd>

#pragma hdrstop

/* TODO : are these sort types working? IDC_SORT_FILETITLE, IDC_SORT_FILENAME, IDC_SORT_ENTIREFILENAME */


enum WAPlaybackStatus
{
	WA_NOT_PLAYING, WA_PLAYING, WA_UNUSED, WA_PAUSED
};

/**
 * @param os the output stream
 * @param status the playback status
 * @return streams out the string representation
 */
std::ostream& operator << (std::ostream& os, WAPlaybackStatus status);

/**
 * Winamp basic operations
 */

enum WinampCommand
{

	IPC_GETVERSION = 0,
	IPC_PLAYFILE = 100,
	IPC_DELETE = 101,
	IPC_STARTPLAY = 102,
	IPC_CHDIR = 103,
	IPC_ISPLAYING = 104,
	IPC_GETOUTPUTTIME = 105,
	IPC_JUMPTOTIME = 106,
	IPC_WRITEPLAYLIST = 120,
	IPC_SETPLAYLISTPOS = 121,
	IPC_SETVOLUME = 122,
	IPC_SETPANNING = 123,
	IPC_GETLISTLENGTH = 124,

	IPC_GETLISTPOS = 125,
	IPC_GETINFO = 126,
	IPC_GETEQDATA = 127,
	IPC_SETEQDATA = 128,

	IPC_GETPLAYLISTFILE = 211,
	IPC_GETPLAYLISTTITLE = 212,
	IPC_GETSHUFFLEOPTION = 250,
	IPC_GETREPEATOPTION = 251,
	IPC_SETSHUFFLEOPTION = 252,
	IPC_SETREPEATOPTION = 253,

	WINAMP_FILE_QUIT = 40001,
	WINAMP_OPTIONS_PREFS = 40012,
	WINAMP_OPTIONS_AOT = 40019,
	WINAMP_FILE_REPEAT = 40022,
	WINAMP_FILE_SHUFFLE = 40023,
	WINAMP_HIGH_PRIORITY = 40025,
	WINAMP_FILE_PLAY = 40029,
	WINAMP_OPTIONS_EQ = 40036,
	WINAMP_HELP_ABOUT = 40041,
	WINAMP_OPTIONS_PLEDIT = 40040,
	WINAMP_VOLUMEUP = 40058,
	WINAMP_VOLUMEDOWN = 40059,
	WINAMP_FFWD5S = 40060,
	WINAMP_REW5S = 40061

};

/**
 * @param os the output stream
 * @param status the command
 * @return streams out the string representation
 */
std::ostream& operator << (std::ostream& os, WinampCommand command);

/**
 * Winamp button definitions
 */

enum WinampButtons
{
	WINAMP_BUTTON1 = 40044,
	WINAMP_BUTTON2 = 40045,
	WINAMP_BUTTON3 = 40046,
	WINAMP_BUTTON4 = 40047,
	WINAMP_BUTTON5 = 40048,
	WINAMP_BUTTON1_SHIFT = 40144,
	WINAMP_BUTTON2_SHIFT = 40145,
	WINAMP_BUTTON3_SHIFT = 40146,
	WINAMP_BUTTON4_SHIFT = 40147,
	WINAMP_BUTTON5_SHIFT = 40148,
	WINAMP_BUTTON1_CTRL = 40154,
	WINAMP_BUTTON2_CTRL = 40155,
	WINAMP_BUTTON3_CTRL = 40156,
	WINAMP_BUTTON4_CTRL = 40157,
	WINAMP_BUTTON5_CTRL = 40158
};

/** aliases for convenience... */

enum WinampCommandButtons
{
	WINAMP_PREVIOUS = WINAMP_BUTTON1,
	WINAMP_PLAYENTRY = WINAMP_BUTTON2,
	WINAMP_PAUSE = WINAMP_BUTTON3,
	WINAMP_STOP = WINAMP_BUTTON4,
	WINAMP_NEXT = WINAMP_BUTTON5,

	WINAMP_BACK5S = WINAMP_BUTTON1_SHIFT,
	WINAMP_OPENFILE = WINAMP_BUTTON2_SHIFT,
// ?? WINAMP_BUTTON3_SHIFT
	WINAMP_STOPFADE = WINAMP_BUTTON4_SHIFT,
	WINAMP_FORWARD5S = WINAMP_BUTTON5_SHIFT,

	WINAMP_STARTOFPLAYLIST = WINAMP_BUTTON1_CTRL,
	WINAMP_OPENLOCATION = WINAMP_BUTTON2_CTRL,
// ?? WINAMP_BUTTON3_CTRL
	WINAMP_STOPAFTERCURRENT = WINAMP_BUTTON4_CTRL,
	WINAMP_ENDOFPLAYLIST = WINAMP_BUTTON5_CTRL
};

/**
 * Winamp directives for the Playlist view
 */
enum WinampPlaylistOptions
{
	IDC_SORT_FILENAME = 40166,
	IDC_SORT_FILETITLE = 40167,
	IDC_SORT_ENTIREFILENAME = 40168,
	IDC_SELECTALL = 40169,
	IDC_SELECTNONE = 40170,
	IDC_SELECTINV = 40171
};

/**
 * Winamp directives for the Equaliser view
 */
enum WinampEQOptions
{
	IDM_EQ_LOADPRE = 40172,
	IDM_EQ_LOADMP3 = 40173,
	IDM_EQ_LOADDEFAULT = 40174,
	IDM_EQ_SAVEPRE = 40175,
	IDM_EQ_SAVEMP3 = 40176,
	IDM_EQ_SAVEDEFAULT = 40177,
	IDM_EQ_DELPRE = 40178,
	IDM_EQ_DELMP3 = 40180
};

/**
 * More advanced navigation directives
 */
enum WinampJumpOptions
{
	WINAMP_JUMP = 40193,
	WINAMP_JUMPFILE = 40194,
	WINAMP_JUMP10FWD = 40195,
	WINAMP_JUMP10BACK = 40197,
	WINAMP_PREVSONG = 40198
};

/* major low level interface functions */

/**
 * Sets the target handle for the message based API
 * can come from a FindWindow, for example or from the in-process value returned
 * @param HWinamp
 * @return prior value of the target handle
 */
HWND setWinampHwnd(HWND HWinamp);

/**
 *  Executes the Winamp API message on the current target handle
 * @param HWinamp window handle of the winamp instance
 * @param MessageToExecute winamp command ID
 * returns nothing
 */
void LocalExecuteCommand(HWND HWinamp, WinampCommand MessageToExecute);

/**
 * Executes the Winamp string based API command on the current target handle.
 * @param HWinamp window handle of the winamp instance
 * @param CommandString - input parameter
 * @param Command - the winamp API command
 * returns nothing
 */
void LocalExecuteStringCommand(HWND HWinamp, const char * CommandString, WinampCommand Command);

/**
 * Queries the Winamp API for an integer value.
 * @param HWinamp window handle of the winamp instance
 * @param Command
 * @param Data  - the winamp API command
 * @return the result of the query
 */
int LocalQueryInt(HWND HWinamp, WinampCommand Command, int Data);

/**
 * Queries the Winamp API for a string value.
 * @param HWinamp window handle of the winamp instance
 * @param Command
 * @param Data  - the winamp API command
 * @return in-process the pointer to the char data for the the result
 */
char * LocalQueryString(HWND HWinamp, WinampCommand Command, int Data);

/**
 * Utility function that returns the winamp version description string,
 * according to the known formatting rules.
 * Caters for new standard format Winamp versions and no version.
 * @param HWinamp window handle of the winamp instance
 * @return the string for the Winamp version
 */
const char * LocalGetWinampVersion(HWND HWinamp);

/* strings identifying the commands */
/**
 * Utility function to name the Winamp commands.
 * @param Command
 * @return the Winamp API command description constant
 */
const char * WinampCommandDesc(int Command);

/**
 * Utility function to name the Winamp version from the version number.
 * @param version
 * @return the string for the Winamp version
 */
const char * WinampVersionString(int version);


#endif // waintH
