//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.


#ifndef MainFH
#define MainFH

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

// winamp client interface
#include "IWinamp.h"

const int TRAY_NOTIFY = WM_APP + 100;


class TfrmMain: public TForm
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
	TImageList *imlActions;
	TMenuItem *N501;
	TMenuItem *N502;
	TImage *icoTrayIcon;
	TMenuItem *mnuMore;
	TMenuItem *UpMore1;
	TMenuItem *DownMore1;
	TImageList *imlCommandsHot;
	TImageList *imlCommandsCool;
	TImageList *imlTrayIcons;
	TMenuItem *LocateServers1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *mnuDetails;
	TMenuItem *mnuNextwithFade;
	TMenuItem *NextwithFade2;
	TMenuItem *mnuPreviouswithFade;
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
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnCloseClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MainTimer(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall lstTimerClick(TObject *Sender);
	void __fastcall AddressChange(TObject *Sender);
	void __fastcall DelayTimer(TObject *Sender);
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
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:        // private user declarations
	int Delay;
	int fIconIndex;
	WAPlaybackStatus WAStatus;
	AnsiString SongTitle;
	char TipChars[64];
	bool doHide;
	bool DoubleClickedL;
	bool DoubleClickedR;
	bool connected;
	void __fastcall TrayNotify(TMessage& Msg);
	void __fastcall ToggleState(void);
	PSTR __fastcall TipText(void);
	void __fastcall DisplayHint(TObject *Sender);
	void UpdateIcon(void);
	void __fastcall AppException(TObject *Sender, Exception *E);
	void __fastcall AnimateForm(TForm * Form, bool FormVisible);

public:         // public user declarations
	int CurrentIndex;
	int LastIndex;
	int LastLength;
	virtual __fastcall TfrmMain(TComponent* Owner);
	HANDLE __fastcall IconHandle(void);
	bool __fastcall TrayMessage(DWORD dwMessage);

BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(TRAY_NOTIFY, TMessage, TrayNotify)
		END_MESSAGE_MAP(TForm)
};

extern TfrmMain *frmMain;

void MessageForm(AnsiString MessageStr);



#endif

