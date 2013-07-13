//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "remoteDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmRemote *dmRemote;
//---------------------------------------------------------------------------
__fastcall TdmRemote::TdmRemote(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------



// TODO: form manager - need references to the commands, playlist and volume forms

// TODO: form manager - need reference to the winamp client

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



// TODO: form manager - need volume up

// TODO: form manager - need volume down

// TODO: form manager - need volume up more

// TODO: form manager - need volume down more

// TODO: form manager - need refresh volume etc.

// TODO: form manager - need set volume 0

// TODO: form manager - need set volume 50%

// TODO: form manager - need set volume 100%

