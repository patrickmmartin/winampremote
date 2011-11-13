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
        TPageControl *pgSettings;
        TTabSheet *tbsMain;
        TPanel *pnlWinampBottom;
        TPanel *pnlIcon;
        TLabel *lblVersion;
        TPanel *Panel1;
        TBevel *Bevel3;
        TTabSheet *tbsConfig;
        TLabel *lblEndpoint;
        TLabel *lblAddress;
        TLabel *lblTimer;
        TBevel *bvl2;
        TEdit *ebEndPoint;
        TEdit *ebAddress;
        TListBox *lstTimer;
        TButton *btnLocate;
        TTabSheet *tbsPreferences;
        TLabel *lblUpdate;
        TLabel *lblStartupActions;
        TBevel *bvl3;
        TCheckBox *chkAutoHide;
        TCheckBox *chkAutoRestore;
        TRadioButton *rbSongChange;
        TRadioButton *rbPlaylistChange;
        TLabel *lblMessage;
        TBevel *Bevel1;
        TImage *icoState;
        TBevel *Bevel2;
        TPanel *pnlMiddle;
        TPanel *pnlCommands;
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
    void __fastcall HideMain(TObject *Sender);
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
    void __fastcall ShowMain(TObject *Sender);
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
        void __fastcall EndDock(TObject *Sender, TObject *Target, int X,
          int Y);
        void __fastcall DetailsExecute(TObject *Sender);
        void __fastcall sbMainDrawPanel(TStatusBar *StatusBar,
          TStatusPanel *Panel, const TRect &Rect);
        void __fastcall SetLanguageExecute(TObject *Sender);

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
    bool Querying;
    char IdentChars[65];
    virtual __fastcall TfrmMain(TComponent* Owner);
    void _fastcall DoBind(void);
    HANDLE __fastcall IconHandle(void);
    bool __fastcall TrayMessage(DWORD dwMessage);

BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(TRAY_NOTIFY, TMessage, TrayNotify)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern TfrmMain *frmMain;

void MessageForm(AnsiString MessageStr);


//---------------------------------------------------------------------------
#endif

