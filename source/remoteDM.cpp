//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "remoteDM.h"

#include "WinampClientBase.h"

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


void TdmRemote::setClient(WinampRemote::Client::IWinamp * client_)
{
        client = client_;
}

void TdmRemote::setMainForm(TfrmMain * Form_)
{
        FMainForm = Form_;
}

void TdmRemote::hookStartDock(TForm * NewForm, TForm * PriorForm)
{
	NewForm->OnStartDock = FormStartDock;
	if (PriorForm)
		PriorForm->OnStartDock = NULL;
}


void TdmRemote::setCommandForm(TForm * Form_)
{
	if (!Form_)
		return;
	hookStartDock(Form_, FCommandForm);
	FCommandForm = Form_;
}

void TdmRemote::setPlaylistForm(TForm * Form_)
{
	if (!Form_)
		return;
	hookStartDock(Form_, FPlaylistForm);
	FPlaylistForm = Form_;
}

void TdmRemote::setSettingsForm(TForm * Form_)
{
	if (!Form_)
		return;
	hookStartDock(Form_, FSettingsForm);
	FSettingsForm = Form_;
}


void __fastcall TdmRemote::FormStartDock(TObject *Sender, TDragDockObject *&DragObject)
{
  if (FMainForm)
   FMainForm->StartDock(Sender, DragObject);
}

//---------------------------------------------------------------------------

void __fastcall TdmRemote::Volume0Execute(TObject *Sender)
{
  if (client)
          client->setVolume(0);
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::Volume100Execute(TObject *Sender)
{
  if (client)
          client->setVolume(255);
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::Volume50Execute(TObject *Sender)
{
  if (client)
          client->setVolume(128);
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::VolumeDownExecute(TObject *Sender)
{
  if (client)
          client->volumeDown();
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::VolumeDownMoreExecute(TObject *Sender)
{
  if (client)
          client->setVolume(client->getVolume() - 10);
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::VolumeUpExecute(TObject *Sender)
{
  if (client)
          client->volumeUp();
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::VolumeupMoreExecute(TObject *Sender)
{
  if (client)
      client->setVolume(client->getVolume() + 10);
}
//---------------------------------------------------------------------------

