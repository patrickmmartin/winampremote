//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef remotemainH
#define remotemainH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#define MYWM_NOTIFY         (WM_APP+100)
#define IDC_MYICON                     1006
extern HINSTANCE g_hinst;
LRESULT IconDrawItem(LPDRAWITEMSTRUCT lpdi);



class ERPCException;
class ERPCException : public Sysutils::Exception
{
//	typedef Sysutils::ERPCException inherited;

public:
	/* Exception.Create */ __fastcall ERPCException(const System::AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall ERPCException(const System::AnsiString Msg, const System::TVarRec
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall ERPCException(int Ident, Extended Dummy) : Sysutils::Exception(Ident
		, Dummy) { }
	/* Exception.CreateResFmt */ __fastcall ERPCException(int Ident, const System::TVarRec * Args, const int
		Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall ERPCException(const System::AnsiString Msg, int AHelpContext) :
		Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall ERPCException(const System::AnsiString Msg, const System::TVarRec
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall ERPCException(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall ERPCException(int Ident, const System::TVarRec * Args, const
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~ERPCException(void) { }
	
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
    TMenuItem *mnuStops;
    TOpenDialog *OpenDialog1;
    TMenuItem *mnuSayHello;
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
    TMenuItem *Downmore1;
    TMenuItem *Upmore1;
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
    TGroupBox *grpSong;
    TLabel *lblMessage;
    TPanel *pnlMid;
    TGroupBox *grpVersion;
    TLabel *lblVersion;
    TGroupBox *grpButtons;
    TButton *btnSettings;
    TButton *btnHide;
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
    TPanel *Panel1;
    TImage *icoState;
    TMenuItem *mnuCommands;
    TMenuItem *ViewToolbar1;
    TMenuItem *mnuViewCommands;
    TGroupBox *grpSettings;
    TPageControl *pgSettings;
    TTabSheet *tbsConfig;
    TLabel *lblEndpoint;
    TLabel *lblAddress;
    TEdit *ebEndPoint;
    TEdit *ebAddress;
    TTabSheet *tbsPreferences;
    TStatusBar *sbMain;
    TCheckBox *chkAutoHide;
    TCheckBox *chkAutoRestore;
    TLabel *lblTimer;
    TListBox *lstTimer;
    TGroupBox *grpPlaylistUpdate;
    TRadioButton *rbSongChange;
    TRadioButton *rbPlaylistChange;
    void __fastcall btnHideClick(TObject *Sender);
    void __fastcall EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall mnuShowClick(TObject *Sender);
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
    void __fastcall mnuAddDirClick(TObject *Sender);
    void __fastcall mnuSayHelloClick(TObject *Sender);
    
    void __fastcall timerMainTimer(TObject *Sender);
    void __fastcall mnuSetVolume0Click(TObject *Sender);
    void __fastcall mnuSetVolume100Click(TObject *Sender);
    void __fastcall mnuShuffleClick(TObject *Sender);
    void __fastcall mnuRepeatClick(TObject *Sender);
    
    void __fastcall mnuPlayFromStartClick(TObject *Sender);
    void __fastcall mnuAdministerPlayListClick(TObject *Sender);
    
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall mnuShowSettingsClick(TObject *Sender);
    
    
    void __fastcall btnHideMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall btnHideMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    
    void __fastcall btnSettingsClick(TObject *Sender);
    
    void __fastcall mnuViewCommandsClick(TObject *Sender);
    
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    
    void __fastcall lstTimerClick(TObject *Sender);
    
private:        // private user declarations
    void __fastcall DrawItem(TMessage& Msg);
    void __fastcall MyNotify(TMessage& Msg);
    bool __fastcall TrayMessage(DWORD dwMessage);
    HANDLE __fastcall IconHandle(void);
    void __fastcall ToggleState(void);
    PSTR __fastcall TipText(void);
    void __fastcall DisplayHint(TObject *Sender);
    void UpdateIcon(void);
    void __fastcall AppException(TObject *Sender, Exception *E);

public:         // public user declarations
    virtual __fastcall TfrmMain(TComponent* Owner);
    char TipChars[64];
    bool doHide;
BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(WM_DRAWITEM,TMessage,DrawItem)
MESSAGE_HANDLER(MYWM_NOTIFY,TMessage,MyNotify)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern TfrmMain *frmMain;



char * Ident(void);

/* this binds to the interface before the RPC call*/
void Bind(void);
void UnBind(void);

void SendString(char * pszString);
void ExecuteMessage(char * pszString, int command);
void ExecuteStringMessage(char * pszString, char * pszParam, int command);
int StringResult(char * pszString, int command, int data);
int IntegerResult(char * pszString, int command, int data);
void Shutdown(void);

void MessageForm(AnsiString *MessageStr);

void  __RPC_FAR * __RPC_USER midl_user_allocate(size_t len);
void __RPC_USER midl_user_free(void __RPC_FAR * ptr);

//---------------------------------------------------------------------------
#endif
