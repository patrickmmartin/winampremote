//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MainFH
#define MainFH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <ActnList.hpp>
#include <ExtCtrls.hpp>
#define MYWM_NOTIFY         (WM_APP+100)
#define IDC_MYICON                     1006


#include "waint.h"


//class ERPCException;
class ERPCException : public Sysutils::Exception
{
public:
	 __fastcall ERPCException(const System::AnsiString Msg) : Sysutils::Exception(Msg
		) { }
};



//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:
    TPopupMenu *pmnuMain;
    TMenuItem *mnuShow;
    TMenuItem *mnuPause;
    TMenuItem *mnuShutDown;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *mnuPlay;
    TMenuItem *mnuAbout;
    TMenuItem *mnuPlaylist;
    TMenuItem *mnuStop;
    TMenuItem *mnuStopFade;
    TMenuItem *mnuStopCurrent;
    TMenuItem *mnuVolume;
    TMenuItem *mnuVolumeUp;
    TMenuItem *mnuVolumeDown;
    TMenuItem *mnuVolumeUpMore;
    TMenuItem *mnuVolumeDownMore;
    TMenuItem *mnuForward5;
    TMenuItem *mnuBack5;
    TOpenDialog *OpenDialog1;
    TMainMenu *mnuMain;
    TMenuItem *mnuFile;
    TMenuItem *mnuFileExit;
    TMenuItem *mnuHelp;
    TMenuItem *mnuHelpAbout;
    TMenuItem *Pause1;
    TMenuItem *Play1;
    TMenuItem *Stop1;
    TMenuItem *MoreStops1;
    TMenuItem *StopafterCurrent1;
    TMenuItem *StopWithFade1;
    TMenuItem *Playlist1;
    TMenuItem *Volume1;
    TMenuItem *Down1;
    TMenuItem *Up1;
    TMenuItem *Forward51;
    TMenuItem *Back51;
    TMenuItem *mnuActions;
    TMenuItem *mnuPlaceOnTray;
    TTimer *timerMain;
    TMenuItem *mnuSetVolume0;
    TMenuItem *mnuSetVolume100;
    TMenuItem *Volumezero1;
    TMenuItem *Volumefull1;
    TMenuItem *mnuShuffle;
    TMenuItem *mnuRepeat;
    TMenuItem *Shuffletoggle1;
    TMenuItem *Repeattoggle1;
    TMenuItem *mnuAdministerPlayList;
    TMenuItem *Administer1;
    TMenuItem *mnuShowSettings;
    TMenuItem *ViewEditSettings1;
    TMenuItem *Actions1;
    TMenuItem *mnuNext;
    TMenuItem *mnuPrevious;
    TMenuItem *mnuStart;
    TMenuItem *mnuEnd;
    TMenuItem *mnuDelete;
    TMenuItem *mnuAddFiles;
    TMenuItem *mnuAddPlayList;
    TMenuItem *mnuPlayfromStart;
    TMenuItem *mnuAddDirectory;
    TMenuItem *Actions2;
    TMenuItem *Next1;
    TMenuItem *Previous1;
    TMenuItem *Start1;
    TMenuItem *End1;
    TMenuItem *Delete1;
    TMenuItem *PlayfromStart2;
    TMenuItem *AddFiles2;
    TMenuItem *AddPlayList1;
    TMenuItem *AddDirectory1;
    TMenuItem *mnuCommands;
    TMenuItem *ViewToolbar1;
    TMenuItem *mnuViewCommands;
    TStatusBar *sbMain;
        TActionList *alMain;
        TAction *Exit;
        TImageList *imlActions;
        TAction *PlaceOnTray;
        TAction *Configuration;
        TAction *ViewToolBar;
        TAction *Pause;
        TAction *Play;
        TAction *Stop;
        TAction *StopFade;
        TAction *StopAfterCurrent;
        TAction *Forward5;
        TAction *Back5;
        TAction *ViewPlaylist;
        TAction *Shuffle;
        TAction *Repeat;
        TAction *Next;
        TAction *Previous;
        TAction *Start;
        TAction *End;
        TAction *Delete;
        TAction *PlayFromStart;
        TAction *AddFiles;
        TAction *AddPlayIist;
        TAction *AddDirectory;
        TAction *ViewVolume;
        TAction *Up;
        TAction *Down;
        TAction *UpMore;
        TAction *DownMore;
        TAction *Zero;
        TAction *Full;
        TAction *About;
        TAction *Half;
        TMenuItem *N501;
        TMenuItem *N502;
        TAction *ShowMain;
        TPageControl *pgSettings;
        TTabSheet *tbsConfig;
        TLabel *lblEndpoint;
        TLabel *lblAddress;
        TLabel *lblTimer;
        TEdit *ebEndPoint;
        TEdit *ebAddress;
        TListBox *lstTimer;
        TTabSheet *tbsPreferences;
        TCheckBox *chkAutoHide;
        TCheckBox *chkAutoRestore;
        TTabSheet *tbsMain;
        TLabel *lblVersion;
        TImage *icoState;
        TImage *icoTrayIcon;
        TLabel *lblUpdate;
        TRadioButton *rbSongChange;
        TRadioButton *rbPlaylistChange;
        TLabel *lblMessage;
        TMenuItem *mnuMore;
        TMenuItem *UpMore1;
        TMenuItem *DownMore1;
        TLabel *lblStartupActions;
        TBevel *Bevel1;
        TImageList *imlCommandsHot;
        TImageList *imlCommandsCool;
        TImageList *imlTrayIcons;
        TButton *btnLocate;
        TAction *LocateServers;
        TMenuItem *LocateServers1;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TAction *RefreshEQ;
        TBevel *bvl1;
        TBevel *bvl2;
        TBevel *bvl3;
        TAction *Autoload;
    void __fastcall btnHideClick(TObject *Sender);
    void __fastcall EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall mnuPauseClick(TObject *Sender);
    void __fastcall mnuShutDownClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnCloseClick(TObject *Sender);
    void __fastcall mnuPlayClick(TObject *Sender);
    void __fastcall mnuNextClick(TObject *Sender);
    void __fastcall mnuPreviousClick(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
    void __fastcall mnuAboutClick(TObject *Sender);
    void __fastcall mnuStopClick(TObject *Sender);
    void __fastcall mnuForward5Click(TObject *Sender);
    void __fastcall mnuBack5Click(TObject *Sender);
    void __fastcall mnuVolumeUpClick(TObject *Sender);
    void __fastcall mnuVolumeDownClick(TObject *Sender);
    void __fastcall mnuVolumeUpMoreClick(TObject *Sender);
    void __fastcall mnuVolumeDownMoreClick(TObject *Sender);
    void __fastcall mnuPlaylistStartClick(TObject *Sender);
    void __fastcall mnuPlaylistEndClick(TObject *Sender);
    void __fastcall mnuDeletePlayListClick(TObject *Sender);
    void __fastcall mnuAddFileToPlayListClick(TObject *Sender);
    void __fastcall mnuStopFadeClick(TObject *Sender);
    void __fastcall mnuStopCurrentClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall mnuSayHelloClick(TObject *Sender);
    void __fastcall MainTimer(TObject *Sender);
    void __fastcall mnuSetVolume0Click(TObject *Sender);
    void __fastcall mnuSetVolume100Click(TObject *Sender);
    void __fastcall mnuShuffleClick(TObject *Sender);
    void __fastcall mnuRepeatClick(TObject *Sender);
    void __fastcall mnuPlayFromStartClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall lstTimerClick(TObject *Sender);
    void __fastcall HalfExecute(TObject *Sender);
    void __fastcall ViewToolBarExecute(TObject *Sender);
    void __fastcall ViewPlaylistExecute(TObject *Sender);
    void __fastcall ViewVolumeExecute(TObject *Sender);
    void __fastcall ShowMainExecute(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall AddressChange(TObject *Sender);
    void __fastcall LocateServersExecute(TObject *Sender);
    void __fastcall DelayTimer(TObject *Sender);
    void __fastcall RefreshEQExecute(TObject *Sender);
    void __fastcall AutoloadExecute(TObject *Sender);



private:        // private user declarations
    int Delay;
    WAPlaybackStatus WAStatus;
    int WinampVerNo;
    LRESULT __fastcall IconDrawItem(LPDRAWITEMSTRUCT lpdi);
    void __fastcall DrawItem(TMessage& Msg);
    void __fastcall MyNotify(TMessage& Msg);
    bool __fastcall TrayMessage(DWORD dwMessage);
    HANDLE __fastcall IconHandle(void);
    void __fastcall ToggleState(void);
    PSTR __fastcall TipText(void);
    void __fastcall DisplayHint(TObject *Sender);
    void UpdateWAStatus(void);
    void UpdateIcon(void);
    char TipChars[64];
    bool doHide;
    bool DoubleClickedL;
    bool DoubleClickedR;
    void __fastcall AppException(TObject *Sender, Exception *E);

public:         // public user declarations
    virtual __fastcall TfrmMain(TComponent* Owner);
BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(WM_DRAWITEM,TMessage,DrawItem)
MESSAGE_HANDLER(MYWM_NOTIFY,TMessage,MyNotify)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern TfrmMain *frmMain;


// this is extern to allow the RPC functions to be simple methods
extern char IdentChars[65];

// see above for below
void SetIdent(void);

/* this binds to the interface before the RPC call*/
void Bind(void);
void UnBind(void);

void SendString(char * pszString);
void ExecuteMessage(char * pszString, int command);
void ExecuteStringMessage(char * pszString, char * pszParam, int command);
int StringResult(char * pszString, int command, int data);
int IntegerResult(char * pszString, int command, int data);
void Shutdown(void);

void MessageForm(AnsiString MessageStr);

void  __RPC_FAR * __RPC_USER midl_user_allocate(size_t len);
void __RPC_USER midl_user_free(void __RPC_FAR * ptr);

//---------------------------------------------------------------------------
#endif
