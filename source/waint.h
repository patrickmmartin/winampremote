//---------------------------------------------------------------------------
#ifndef waintH
#define waintH
//---------------------------------------------------------------------------

#include <windows.h>

enum WAPlaybackStatus {WA_NOT_PLAYING, WA_PLAYING, WA_UNUSED, WA_PAUSED};

/* major low level interface functions */

// TODO namespace for local utilities?


/**
 * Sets the target handle for the message based API
 * can come from a FindWindow, for example or from the in-process value returned
 * @param HWinamp
 * @return prior value of the target handle
 */
HWND setWinampHwnd(HWND HWinamp);

/**
 *  Executes the Winamp API message on the current target handle
 * @param MessageToExecute winamp command ID
 * returns nothing
 */
void LocalExecuteCommand(int MessageToExecute);

/**
 * Executes the Winamp string based API command on the current target handle.
 * @param CommandString - input parameter
 * @param Command - the winamp API command
 * returns nothing
 */
void LocalExecuteStringCommand(char * CommandString, int Command);

/**
 * Queries the Winamp API for an integer value.
 * @param Command
 * @param Data  - the winamp API command
 * @return the result of the query
 */
int LocalQueryInt(int Command, int Data);


/**
 * Queries the Winamp API for a string value.
 * @param Command
 * @param Data  - the winamp API command
 * @return in-process the pointer to the char data for the the result
 */
char * LocalQueryString(int Command, int Data);

/**
 * Utility function that returns the winamp version description string,
 * according to the known formatting rules.
 * Caters for new standard format Winamp versions and no version.
 * @return the string for the Winamp version
 */
const char * LocalGetWinampVersion();

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

/**
 * Winamp Message definitions
 */
const int WM_WA_IPC = WM_USER;

/**
 * obtain version
 */
const int IPC_GETVERSION = 0;

/**
 * Winamp basic operations
 */
const int IPC_PLAYFILE  = 100;
const int IPC_DELETE  = 101;
const int IPC_STARTPLAY = 102;
const int IPC_CHDIR = 103;
const int IPC_ISPLAYING = 104;
const int IPC_GETOUTPUTTIME = 105;
const int IPC_JUMPTOTIME = 106;
const int IPC_WRITEPLAYLIST = 120;
const int IPC_SETPLAYLISTPOS = 121;
const int IPC_SETVOLUME = 122;
const int IPC_SETPANNING = 123;
const int IPC_GETLISTLENGTH = 124;

const int IPC_GETLISTPOS = 125;
const int IPC_GETINFO = 126;
const int IPC_GETEQDATA = 127;
const int IPC_SETEQDATA = 128;

const int IPC_GETPLAYLISTFILE = 211;
const int IPC_GETPLAYLISTTITLE = 212;
const int IPC_GETSHUFFLEOPTION =  250;
const int IPC_GETREPEATOPTION = 251;
const int IPC_SETSHUFFLEOPTION = 252;
const int IPC_SETREPEATOPTION = 253;

const int WINAMP_FILE_QUIT = 40001;
const int WINAMP_OPTIONS_PREFS = 40012;
const int WINAMP_OPTIONS_AOT = 40019;
const int WINAMP_FILE_REPEAT = 40022;
const int WINAMP_FILE_SHUFFLE = 40023;
const int WINAMP_HIGH_PRIORITY = 40025;
const int WINAMP_FILE_PLAY = 40029;
const int WINAMP_OPTIONS_EQ = 40036;
const int WINAMP_HELP_ABOUT = 40041;
const int WINAMP_OPTIONS_PLEDIT = 40040;
const int WINAMP_VOLUMEUP = 40058;
const int WINAMP_VOLUMEDOWN = 40059;
const int WINAMP_FFWD5S = 40060;
const int WINAMP_REW5S = 40061;

/**
 * Winamp button definitions
 */
const int WINAMP_BUTTON1 = 40044;
const int WINAMP_BUTTON2 = 40045;
const int WINAMP_BUTTON3 = 40046;
const int WINAMP_BUTTON4 = 40047;
const int WINAMP_BUTTON5 = 40048;
const int WINAMP_BUTTON1_SHIFT = 40144;
const int WINAMP_BUTTON2_SHIFT = 40145;
const int WINAMP_BUTTON3_SHIFT = 40146;
const int WINAMP_BUTTON4_SHIFT = 40147;
const int WINAMP_BUTTON5_SHIFT = 40148;
const int WINAMP_BUTTON1_CTRL = 40154;
const int WINAMP_BUTTON2_CTRL = 40155;
const int WINAMP_BUTTON3_CTRL = 40156;
const int WINAMP_BUTTON4_CTRL = 40157;
const int WINAMP_BUTTON5_CTRL = 40158;

/** aliases for convenience... */

const int WINAMP_PREVIOUS  = WINAMP_BUTTON1;
const int WINAMP_PLAYENTRY  = WINAMP_BUTTON2;
const int WINAMP_PAUSE  = WINAMP_BUTTON3;
const int WINAMP_STOP = WINAMP_BUTTON4;
const int WINAMP_NEXT = WINAMP_BUTTON5;

const int WINAMP_BACK5S  = WINAMP_BUTTON1_SHIFT;
const int WINAMP_OPENFILE  = WINAMP_BUTTON2_SHIFT;
//const int ?? WINAMP_BUTTON3_SHIFT
const int WINAMP_STOPFADE  = WINAMP_BUTTON4_SHIFT;
const int WINAMP_FORWARD5S  = WINAMP_BUTTON5_SHIFT;

const int WINAMP_STARTOFPLAYLIST = WINAMP_BUTTON1_CTRL;
const int WINAMP_OPENLOCATION = WINAMP_BUTTON2_CTRL;
//const int ?? WINAMP_BUTTON3_CTRL
const int WINAMP_STOPAFTERCURRENT = WINAMP_BUTTON4_CTRL;
const int WINAMP_ENDOFPLAYLIST = WINAMP_BUTTON5_CTRL;

/**
 * Winamp directives for the Playlist view
 */
const int IDC_SORT_FILENAME = 40166;
const int IDC_SORT_FILETITLE = 40167;
const int IDC_SORT_ENTIREFILENAME = 40168;
const int IDC_SELECTALL = 40169;
const int IDC_SELECTNONE = 40170;
const int IDC_SELECTINV = 40171;


/**
 * Winamp directives for the Equaliser view
 */
const int IDM_EQ_LOADPRE = 40172;
const int IDM_EQ_LOADMP3 = 40173;
const int IDM_EQ_LOADDEFAULT = 40174;
const int IDM_EQ_SAVEPRE = 40175;
const int IDM_EQ_SAVEMP3 = 40176;
const int IDM_EQ_SAVEDEFAULT = 40177;
const int IDM_EQ_DELPRE = 40178;
const int IDM_EQ_DELMP3 = 40180;


/**
 * More advanced navigation directives
 */
const int WINAMP_JUMP = 40193;
const int WINAMP_JUMPFILE = 40194;
const int WINAMP_JUMP10FWD = 40195;
const int WINAMP_JUMP10BACK = 40197;
const int WINAMP_PREVSONG = 40198;

#endif
