//---------------------------------------------------------------------------

#ifndef remoteDMH
#define remoteDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>

#include "IWinamp.h"

#include "MainF.h"

//---------------------------------------------------------------------------
class TdmRemote : public TDataModule
{
__published:	// IDE-managed Components
        TActionList *alRemote;
        TAction *VolumeUp;
        TAction *VolumeDown;
        TAction *VolumeupMore;
        TAction *VolumeDownMore;
        TAction *Volume0;
        TAction *Volume50;
        TAction *Volume100;
        TAction *RefreshPlaylist;
        TAction *RefreshSettings;
        void __fastcall Volume0Execute(TObject *Sender);
        void __fastcall Volume100Execute(TObject *Sender);
        void __fastcall Volume50Execute(TObject *Sender);
        void __fastcall VolumeDownExecute(TObject *Sender);
        void __fastcall VolumeDownMoreExecute(TObject *Sender);
        void __fastcall VolumeUpExecute(TObject *Sender);
        void __fastcall VolumeupMoreExecute(TObject *Sender);
private:	// User declarations
	WinampRemote::Client::IWinamp * client;
	TfrmMain* FMainForm;
	TForm* FCommandForm;
	TForm* FPlaylistForm;
	TForm* FSettingsForm;
	void hookStartDock(TForm * NewForm, TForm * PriorForm);
        void __fastcall FormStartDock(TObject *Sender, TDragDockObject *&DragObject);
public:		// User declarations
        __fastcall TdmRemote(TComponent* Owner);

	__property TfrmMain* MainForm = {read = FMainForm, write = setMainForm};
	__property TForm* CommandForm = {read = FCommandForm, write = setCommandForm};
	__property TForm* PlaylistForm = {read = FPlaylistForm, write = setPlaylistForm};
	__property TForm* SettingsForm = {read = FSettingsForm , write = setSettingsForm };

        void setClient(WinampRemote::Client::IWinamp * client_);
        void setMainForm(TfrmMain * Form_);
        void setCommandForm(TForm * Form_);
        void setPlaylistForm(TForm * Form_);
        void setSettingsForm(TForm * Form_);






// signature is generic - can be set upon attachment
// TODO: form manager - upon start dragging commands // frmMain->StartDock(Sender, DragObject);

// TODO: form manager - upon start drag of playlist // frmMain->StartDock(Sender, DragObject);

// TODO: form manager - upon start drag of the volume form // frmMain->StartDock(Sender, DragObject);


// signature of events are uniform, but need dispatch upon the instance  - good ? bad ?:P

// TODO: form manager - upon close playlist // frmMain->ViewPlaylist->Execute();

// TODO: form manager - upon close of the settings form // frmMain->ViewVolume->Execute();

// TODO: form manager - upon closing Commands form //frmMain->ViewToolBar->Execute(); BTW are we still doing that?


// TODO: form manager - action for display or hide Settings // hide show


// TODO: form manager - action for refreshing playlist // frmMain->PlaylistRefresh->Execute();

// TODO: form manager - need action for adding files to playlist




};
//---------------------------------------------------------------------------
extern PACKAGE TdmRemote *dmRemote;
//---------------------------------------------------------------------------
#endif
