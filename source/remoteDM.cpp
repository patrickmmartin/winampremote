//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "remoteDM.h"

#include "WinampClientBase.h"
#include "DetailsF.h"
#include "CursorGuard.h"
#include "CommandF.h"
#include "SettingsF.h"
#include "ServersF.h"
#include "RPCException.h"
#include "remotestrs.h"
#include "AboutF.h"
#include "rpcbind.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TdmRemote *dmRemote;

__fastcall TdmRemote::TdmRemote(TComponent* Owner)
        : TDataModule(Owner)
{
}


void TdmRemote::hookStartDock(TForm * NewForm, TForm * PriorForm)
{
	NewForm->OnStartDock = FormStartDock;
	if (PriorForm)
		PriorForm->OnStartDock = NULL;
}


void __fastcall TdmRemote::FormStartDock(TObject *Sender, TDragDockObject *&DragObject)
{
   frmMain->StartDock(Sender, DragObject);
}

void __fastcall TdmRemote::DoAddFiles(TStrings * Files)
{
    WinampRemote::Utils::CursorGuard ci;
	string filelist = Files->Text.c_str();
	vector <string> playlist;
	for (int i = 0 ; i < Files->Count ; i++)
			playlist.push_back(Files->Strings[i].c_str());
	client->setPlayList(playlist);
}


void __fastcall TdmRemote::DoBind(const AnsiString& address, const AnsiString& endpoint)
{
  Bind(address.c_str(), endpoint.c_str(), pszProtocolSequenceNP);
}


void __fastcall TdmRemote::PauseExecute(TObject *)
{
    // TODO: used to have checked update protection
    client->pause();
}


void __fastcall TdmRemote::PlayExecute(TObject *)
{
  client->playSong();
}




void __fastcall TdmRemote::NextExecute(TObject *)
{
  SongChanging->Execute();
  client->nextSong();
  SongChanged->Execute();
}




void __fastcall TdmRemote::NextFadeExecute(TObject *)
{
  StopFade->Execute();
  Next->Execute();
  Play->Execute();

}




void __fastcall TdmRemote::PreviousExecute(TObject *)
{
  SongChanging->Execute();
  client->previousSong();
  SongChanged->Execute();
}



void __fastcall TdmRemote::StopExecute(TObject *)
{
  client->stopSong();
}




void __fastcall TdmRemote::Forward5Execute(TObject *)
{
  client->forward5();
}




void __fastcall TdmRemote::Back5Execute(TObject *)
{
  client->back5();
}




void __fastcall TdmRemote::VolumeUpExecute(TObject *)
{
  client->volumeUp();
  // TODO refresh volume status
}

void __fastcall TdmRemote::VolumeDownExecute(TObject *)
{
  client->volumeDown();
  // TODO refresh volume status
}




void __fastcall TdmRemote::VolumeUpMoreExecute(TObject *)
{
  client->setVolume(client->getVolume() + 10);
  // TODO refresh volume status
}




void __fastcall TdmRemote::VolumeDownMoreExecute(TObject *)
{
  client->setVolume(client->getVolume() - 10);
  // TODO refresh volume status
}




void __fastcall TdmRemote::PlaylistStartExecute(TObject *)
{
  SongChanging->Execute();
  client->startPlaylist();
  SongChanged->Execute();
}




void __fastcall TdmRemote::PlaylistEndExecute(TObject *)
{
  SongChanging->Execute();
  client->playlistEnd();
  SongChanged->Execute();
}




void __fastcall TdmRemote::DeletePlayListExecute(TObject *)
{
  client->deletePlaylist();
  PlaylistRefresh->Execute();
}





void __fastcall TdmRemote::StopFadeExecute(TObject *)
{
  client->stopWithFade();
}




void __fastcall TdmRemote::StopAfterCurrentExecute(TObject *)
{
  client->stopAfterCurrent();
}




void __fastcall TdmRemote::SetVolume0Execute(TObject *)
{
  client->setVolume(0);
  // TODO refresh volume status

}


void __fastcall TdmRemote::SetVolume100Execute(TObject *)
{
  client->setVolume(255);
  // TODO refresh volume status
}




void __fastcall TdmRemote::ShuffleExecute(TObject *)
{
  // shuffle / repeat status only works in very recent versions,
  // so always do for older
  if ( (client->winampVersion() < 0x2604) || (Shuffle->Checked == client->getShuffle() ) )
    client->toggleShuffle();
  // TODO refresh playback status 
}




void __fastcall TdmRemote::RepeatExecute(TObject *)
{
  // shuffle / repeat status only works in very recent versions,
  // so always do for older
  if  ( (client->winampVersion() < 0x2604) || (Repeat->Checked ==  client->getRepeat() ) )
    client->toggleRepeat();
  // TODO refresh playback status 
}




void __fastcall TdmRemote::PlayFromStartExecute(TObject *)
{
  SongChanging->Execute();
  client->playlistStart();
  SongChanged->Execute();
}






void __fastcall TdmRemote::HalfExecute(TObject *)
{
  client->setVolume(128);
  // TODO refresh playback status
}




void __fastcall TdmRemote::ViewToolBarExecute(TObject *)
{
  // need to undock
  frmCommands->Visible = !frmCommands->Visible;
  ViewToolBar->Checked = frmCommands->Visible;
}




void __fastcall TdmRemote::ViewPlaylistExecute(TObject *)
{
  frmPlaylist->Visible = !frmPlaylist->Visible;
  ViewPlaylist->Checked = frmPlaylist->Visible;


}



void __fastcall TdmRemote::ViewVolumeExecute(TObject *)
{
	// TODO: should be in forms management interface
  frmSettings->Visible = !frmSettings->Visible;
  ViewVolume->Checked = frmSettings->Visible;
}



void __fastcall TdmRemote::AutoloadExecute(TObject *)
{
  client->toggleAutoload();
  Autoload->Checked = client->getAutoload();
}



void __fastcall TdmRemote::EQOnExecute(TObject *)
{

  client->toggleEQOn();
  EQOn->Checked = client->getEQOn();

}



void __fastcall TdmRemote::DetailsExecute(TObject *)
{
  TfrmDetails *DetailsForm = new TfrmDetails(NULL);
  try
  {
    DetailsForm->ShowModal();
  }
  __finally
  {
    delete DetailsForm;
  }
}


void __fastcall TdmRemote::PreviousFadeExecute(TObject *)
{
  StopFade->Execute();
  Previous->Execute();
  Play->Execute();

}




void __fastcall TdmRemote::SongChangingExecute(TObject *)
{
  // if special actions required, this action can do them
  // if the fade on stop is checked, the playing status needs to be cached
  // TODO implement this property
//  if (chkFadeOld->Checked)
//    StopFade->Execute();

}




void __fastcall TdmRemote::SongChangedExecute(TObject *)
{
  // if special actions required, this action can do them

  // TODO implement this property
//  if ( (chkFadeOld->Checked) && (WAStatus == WA_PLAYING) )
//	Play->Execute();
}




void __fastcall TdmRemote::NewSongExecute(TObject *)
{
  // gets the index from the playlist form
  SongChanging->Execute();
  // TOD implement getting this
  client->setPlaylistIndex(frmPlaylist->lstSongs->ItemIndex);
  Play->Execute();
  SongChanged->Execute();

}



void __fastcall TdmRemote::PlaylistRefreshExecute(TObject *)
{

  frmPlaylist->lstSongs->Items->BeginUpdate();
  try
  {
    try
    {

      WinampRemote::Utils::CursorGuard ci;
      // TODO update UI status

      LastLength = client->getPlaylistLength();
      LastIndex = CurrentIndex;
      CurrentIndex = client->getCurrentPlayPosition();

      frmPlaylist->lstSongs->Items->Clear();

      TStringList * SongList = new TStringList;
      try
      {

        std::string list = client->getStringList(IPC_GETPLAYLISTTITLE);

        SongList->Clear();
        SongList->Text = list.c_str();

        frmPlaylist->lstSongs->Items->Assign(SongList);

      }
      __finally
      {
        delete SongList;
      }

    }
    catch( ERPCException &E)
    {
      frmPlaylist->lstSongs->Items->Text = AnsiString().sprintf(sListUnobtainable.c_str(), E.what());
    }

  }
  __finally
  {

    frmPlaylist->lstSongs->Items->EndUpdate();
  }
}





void __fastcall TdmRemote::PlaylistRefreshStatsExecute(TObject *)
{


  int SongS = 0;
  int PosMS = 0;

  client->getTimes(SongS, PosMS);

  if ((SongS) && (!frmPlaylist->Dragging))
    frmPlaylist->pbSongPos->Position = (frmPlaylist->pbSongPos->Max * PosMS) / (SongS * 1000);

  if (frmPlaylist->lstSongs->Items->Count > 1)
    frmPlaylist->pbListPos->Position = (frmPlaylist->pbListPos->Max * CurrentIndex) /
                                       (frmPlaylist->lstSongs->Items->Count - 1);
  else
    frmPlaylist->pbListPos->Position = 0;

  // time
  frmPlaylist->sbPlaylist->Panels->Items[1]->Text = TimeToStr(Time());
  // current song length
  frmPlaylist->sbPlaylist->Panels->Items[3]->Text = TimeToStr((float) SongS / SecsPerDay);

}




void __fastcall TdmRemote::AboutExecute(TObject *)
{
  if (!frmAbout)
  {
    frmAbout = new TfrmAbout(this);
    try
    {
      frmAbout->Caption = sAboutWinampRemoteControl;
      frmAbout->ShowModal();
    }
    __finally
    {
      delete frmAbout;
      frmAbout = NULL;
    }
  }
  else
  {
    frmAbout->Show();
    frmAbout->BringToFront();
  }
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::AddDirectoryExecute(TObject *)
{
 // TODO implement here        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::AddFilesExecute(TObject *)
{
 // TODO implement here        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::AddPlayIistExecute(TObject *)
{
AnsiString str;
AnsiString commandstr;

  OpenDialog1->FileName = "";

  // TODO this is poor style
  if (false /* looking for playlist */){
    OpenDialog1->Filter = sPlayListFiles;
    }
  else{
    OpenDialog1->Filter = sAllFiles;
    }

  if (OpenDialog1->Execute())
  {

    TStringList * Files = new TStringList;
    try
    {
      // sort strings by name, for now
      Files->Sorted = true;

      Files->Assign(OpenDialog1->Files);

      DoAddFiles(Files);
      PlaylistRefresh->Execute();
    }
    __finally
    {
      delete Files;
    }
  } // if
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::ConfigurationExecute(TObject *)
{
 // TODO implement here        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::DeleteExecute(TObject *)
{
 // TODO implemente here        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::DownExecute(TObject *)
{
 // TODO implement here        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::DownMoreExecute(TObject *)
{
 // TODO implement here        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::EndExecute(TObject *)
{
 // TODO implemente here        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::ExitExecute(TObject *)
{
  Application->Terminate();        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::FullExecute(TObject *)
{
  // TODO implement here        
        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::LocateServersExecute(TObject *)
{
  AnsiString EndPoint = frmMain->ebEndPoint->Text;
  AnsiString Address = frmMain->ebAddress->Text;

  // TODO - block UI timer
//  timerMain->Enabled = false;
  UnBind();
  TfrmServers * ServersForm = new TfrmServers(this);
  try
  {
    ServersForm->ebEndPoint->Text = EndPoint;
    ServersForm->ShowModal();
    if (ServersForm->ModalResult != mrOk)
    {
      //restore
    	frmMain->ebEndPoint->Text = EndPoint;
    	frmMain->ebAddress->Text = Address;
    }
    else
    {
    	frmMain->ebEndPoint->Text = ServersForm->EndPoint;
    	frmMain->ebAddress->Text = ServersForm->Address;

    }
  }
  __finally
  {
    delete ServersForm;
    DoBind(ServersForm->EndPoint, ServersForm->Address);
    // perform UI update
//    MainTimer(this);
//    timerMain->Enabled = true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::PlaceOnTrayExecute(TObject *)
{
  // TODO implement here        
        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::PlaylistRefreshCurrentExecute(TObject *)
{
  // TODO implement here

}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::ShowMainFormExecute(TObject *)
{

#ifndef IDANI_CLOSE
  #define IDANI_CLOSE         2
#endif
#ifndef IDANI_CAPTION
  #define IDANI_CAPTION       3
#endif

  ShowWindow(Application->Handle, SW_SHOW);

  DWORD dwExStyle = GetWindowLong(Application->Handle, GWL_EXSTYLE);
  dwExStyle ^= WS_EX_TOOLWINDOW;
  SetWindowLong(Application->Handle, GWL_EXSTYLE, dwExStyle);

  TRect FromRect, ToRect;
  FromRect = TRect(Screen->Width - 16, Screen->Height, Screen->Width, Screen->Height - 16);

  ToRect = frmMain->BoundsRect;

  HRGN HideRegion = CreateRectRgn(0,0,1,1);
  SetWindowRgn(frmMain->Handle, HideRegion, false);

  frmMain->Show();

  DrawAnimatedRects(frmMain->Handle, IDANI_CAPTION, &FromRect, &ToRect);

  SetWindowRgn(frmMain->Handle, NULL, true);

  // dodge here
  Application->Restore();

}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::StartExecute(TObject *)
{
  // TODO implement here        
        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::UpExecute(TObject *)
{
  // TODO implement here        
        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::UpMoreExecute(TObject *)
{
  // TODO implement here        
        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::ZeroExecute(TObject *)
{
  // TODO implement here        
        
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::DataModuleCreate(TObject *Sender)
{
  client = new WinampRemote::Client::WinampClientBase();
}
//---------------------------------------------------------------------------

void __fastcall TdmRemote::DataModuleDestroy(TObject *Sender)
{
  delete client;        
}
//---------------------------------------------------------------------------

