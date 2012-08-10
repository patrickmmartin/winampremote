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

// winamp IPC declarations
#include "waint.h"


const int TRAY_NOTIFY = WM_APP + 100;

static const Word ENGLISHUS = 0x409;
static const Word ENGLISHUK = 0x809;
static const Word GERMAN = 0x407;
static const Word FRENCH = 0x40c;
static const Word DUTCH = 0x413;


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
        TAction *ShowMainForm;
        TImage *icoTrayIcon;
        TMenuItem *mnuMore;
        TMenuItem *UpMore1;
        TMenuItem *DownMore1;
        TImageList *imlCommandsHot;
        TImageList *imlCommandsCool;
        TImageList *imlTrayIcons;
        TAction *LocateServers;
        TMenuItem *LocateServers1;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TAction *RefreshEQ;
        TAction *Autoload;
        TMenuItem *mnuDetails;
        TAction *Details;
        TMenuItem *mnuLanguage;
        TMenuItem *mnuEnglishUS;
        TMenuItem *mnuEnglishUK;
        TMenuItem *mnuGerman;
        TMenuItem *mnuFrench;
        TMenuItem *mnuDutch;
        TAction *PlaylistRefresh;
        TAction *SetLanguage;
        TAction *NextFade;
        TMenuItem *mnuNextwithFade;
        TMenuItem *NextwithFade2;
        TAction *PreviousFade;
        TMenuItem *mnuPreviouswithFade;
        TAction *SongChanging;
        TAction *SongChanged;
        TAction *NewSong;
        TAction *PlaylistRefreshCurrent;
        TAction *PlaylistRefreshStats;
        TPageControl *pgSettings;
        TTabSheet *tbsMain;
        TPanel *pnlWinampBottom;
        TPanel *pnlIcon;
        TLabel *lblVersion;
        TLabel *lblMessage;
        TTabSheet *tbsPreferences;
        TBevel *bvl3;
        TLabel *lblUpdate;
        TLabel *lblStartupActions;
        TLabel *lblSongChange;
        TCheckBox *chkAutoHide;
        TCheckBox *chkAutoRestore;
        TRadioButton *rbSongChange;
        TRadioButton *rbPlaylistChange;
        TCheckBox *chkFadeOld;
        TEdit *ebEndPoint;
        TEdit *ebAddress;
        TButton *btnLocate;
        TListBox *lstTimer;
        TLabel *lblTimer;
    void __fastcall HideMain(TObject *Sender);
    void __fastcall PauseExecute(TObject *Sender);
    void __fastcall ExitExecute(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnCloseClick(TObject *Sender);
    void __fastcall PlayExecute(TObject *Sender);
    void __fastcall NextExecute(TObject *Sender);
    void __fastcall PreviousExecute(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
    void __fastcall AboutExecute(TObject *Sender);
    void __fastcall StopExecute(TObject *Sender);
    void __fastcall Forward5Execute(TObject *Sender);
    void __fastcall Back5Execute(TObject *Sender);
    void __fastcall VolumeUpExecute(TObject *Sender);
    void __fastcall VolumeDownExecute(TObject *Sender);
    void __fastcall VolumeUpMoreExecute(TObject *Sender);
    void __fastcall VolumeDownMoreExecute(TObject *Sender);
    void __fastcall PlaylistStartExecute(TObject *Sender);
    void __fastcall PlaylistEndExecute(TObject *Sender);
    void __fastcall DeletePlayListExecute(TObject *Sender);
    void __fastcall AddFileToPlayListExecute(TObject *Sender);
    void __fastcall StopFadeExecute(TObject *Sender);
    void __fastcall StopAfterCurrentExecute(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall mnuSayHelloClick(TObject *Sender);
    void __fastcall MainTimer(TObject *Sender);
    void __fastcall SetVolume0Execute(TObject *Sender);
    void __fastcall SetVolume100Execute(TObject *Sender);
    void __fastcall ShuffleExecute(TObject *Sender);
    void __fastcall RepeatExecute(TObject *Sender);
    void __fastcall PlayFromStartExecute(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall lstTimerClick(TObject *Sender);
    void __fastcall HalfExecute(TObject *Sender);
    void __fastcall ViewToolBarExecute(TObject *Sender);
    void __fastcall ViewPlaylistExecute(TObject *Sender);
    void __fastcall ViewVolumeExecute(TObject *Sender);
    void __fastcall ShowMainFormExecute(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall AddressChange(TObject *Sender);
    void __fastcall LocateServersExecute(TObject *Sender);
    void __fastcall DelayTimer(TObject *Sender);
    void __fastcall RefreshEQExecute(TObject *Sender);
    void __fastcall AutoloadExecute(TObject *Sender);
        void __fastcall FormDockOver(TObject *Sender,
          TDragDockObject *Source, int X, int Y, TDragState State,
          bool &Accept);
        void __fastcall StartDock(TObject *Sender,
          TDragDockObject *&DragObject);
        void __fastcall pgSettingsDockDrop(TObject *Sender,
          TDragDockObject *Source, int X, int Y);
        void __fastcall DetailsExecute(TObject *Sender);
        void __fastcall sbMainDrawPanel(TStatusBar *StatusBar,
          TStatusPanel *Panel, const TRect &Rect);
        void __fastcall NextFadeExecute(TObject *Sender);
        void __fastcall PreviousFadeExecute(TObject *Sender);
        void __fastcall SongChangingExecute(TObject *Sender);
        void __fastcall SongChangedExecute(TObject *Sender);
        void __fastcall NewSongExecute(TObject *Sender);
        void __fastcall alMainExecute(TBasicAction *Action, bool &Handled);
        void __fastcall PlaylistRefreshExecute(TObject *Sender);
        void __fastcall PlaylistRefreshStatsExecute(TObject *Sender);

private:        // private user declarations
    int Delay;
    int WinampVerNo;
    int fIconIndex;
    WAPlaybackStatus WAStatus;
    AnsiString SongTitle;
    void __fastcall SetIdent(void);
    void __fastcall TrayNotify(TMessage& Msg);
    void __fastcall ToggleState(void);
    PSTR __fastcall TipText(void);
    void __fastcall DisplayHint(TObject *Sender);
    void UpdateIcon(void);
    char TipChars[64];
    bool doHide;
    bool DoubleClickedL;
    bool DoubleClickedR;
    void __fastcall SetLanguageMenu(TObject *Sender);
    void __fastcall AppException(TObject *Sender, Exception *E);
    void __fastcall AnimateForm(TForm * Form, bool FormVisible);

public:         // public user declarations
    int CurrentIndex;
    int LastIndex;
    int LastLength;
    bool Querying;
    char IdentChars[MAX_PATH];
    virtual __fastcall TfrmMain(TComponent* Owner);
    void _fastcall DoBind(void);
    HANDLE __fastcall IconHandle(void);
    bool __fastcall TrayMessage(DWORD dwMessage);
    void __fastcall DoAddFiles(TStrings * Files);
    void  __fastcall DoDeleteSelected(void);
    void __fastcall GetFilenames(int Start, int Stop, TStringList * Files);
    void __fastcall DropFiles(TStringList * DropFiles, int DropIndex);

BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(TRAY_NOTIFY, TMessage, TrayNotify)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern TfrmMain *frmMain;

void MessageForm(AnsiString MessageStr);


//---------------------------------------------------------------------------
#endif

