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

void TdmRemote::hookEvents(TForm * NewForm, TForm * PriorForm)
{
	// hook the generic form events so the state can be managed
	// drag and dock is currently disabled
	NewForm->OnStartDock = ChildFormStartDock;
	// close event
	NewForm->OnClose = ChildFormClose;
	{
		if (PriorForm)
			PriorForm->OnStartDock = NULL;
		if (PriorForm)
			PriorForm->OnClose = NULL;
	}
}

void __fastcall TdmRemote::ChildFormStartDock(TObject *Sender, TDragDockObject *&DragObject)
{
   frmMain->StartDock(Sender, DragObject);
}

void __fastcall TdmRemote::ChildFormClose(TObject * aForm, TCloseAction & aAction)
{
	// handle the update
	if (aForm == FPlaylistForm)
	{
		this->ViewPlaylist->Checked = false;
	}
	if (aForm == FMainForm)
	{
		this->ShowMainForm->Checked = false;
	}
	if (aForm == FSettingsForm)
	{
		this->ViewVolume->Checked = false;
	}
	if (aForm == FCommandsForm)
	{
		this->ViewToolBar->Checked = false;
	}

}

void __fastcall TdmRemote::GetFilenames(int Start, int Stop, TStringList * Files)
{

int i;

  for (i = Start ; i < Stop; i++)
  {
    Files->Add(dmRemote->client->getPlayListItem(i, false).c_str());
  } // for

}

void __fastcall TdmRemote::DoAddFiles(TStrings * Files, int selectedIndex)
{
    WinampRemote::Utils::CursorGuard ci;
	string filelist = Files->Text.c_str();
	vector <string> playlist;
	for (int i = 0 ; i < Files->Count ; i++)
			playlist.push_back(Files->Strings[i].c_str());
	client->setPlayList(playlist);
    if (selectedIndex >= 0)
    	client->setPlaylistIndex(selectedIndex);

}

void __fastcall TdmRemote::DropFiles(TStringList * DropFiles, int DropIndex)
{
  std::auto_ptr<TStringList> Playlist(new TStringList());

  // get the top of the list
  if (DropIndex > -1)
    GetFilenames(0, DropIndex, Playlist.get());
  else
    GetFilenames(0, frmPlaylist->lstSongs->Items->Count, Playlist.get());

  Playlist->AddStrings(DropFiles);

  // get the rest of the list;
  if (DropIndex > -1)
    GetFilenames(DropIndex, frmPlaylist->lstSongs->Items->Count - 1, Playlist.get());

  dmRemote->DoAddFiles(Playlist.get());

  // reset position here

  // AAAACK - used to be a "magic object"
  int NewPos = DropFiles->IndexOfObject((TObject *) true);
  dmRemote->client->setPlaylistIndex(NewPos);

  dmRemote->PlaylistRefresh->Execute();
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
  UpdateBars();
}

void __fastcall TdmRemote::VolumeDownExecute(TObject *)
{
  client->volumeDown();
  UpdateBars();
}

void __fastcall TdmRemote::VolumeUpMoreExecute(TObject *)
{
  client->setVolume(client->getVolume() + 10);
  UpdateBars();
}

void __fastcall TdmRemote::VolumeDownMoreExecute(TObject *)
{
  client->setVolume(client->getVolume() - 10);
  UpdateBars();
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
  UpdateBars();

}

void __fastcall TdmRemote::SetVolume100Execute(TObject *)
{
  client->setVolume(255);
  UpdateBars();
}

void __fastcall TdmRemote::ShuffleExecute(TObject *)
{
  // shuffle / repeat status only works in very recent versions,
  // so always do for older
  if ( (client->winampVersion() < 0x2604) || (Shuffle->Checked == client->getShuffle() ) )
    client->toggleShuffle();
}

void __fastcall TdmRemote::RepeatExecute(TObject *)
{
  // shuffle / repeat status only works in very recent versions,
  // so always do for older
  if  ( (client->winampVersion() < 0x2604) || (Repeat->Checked ==  client->getRepeat() ) )
    client->toggleRepeat();
}

void __fastcall TdmRemote::PlayFromStartExecute(TObject *)
{
  SongChanging->Execute();
  client->playlistStart();
  SongChanged->Execute();
}

void __fastcall TdmRemote::ZeroExecute(TObject *)
{
  client->setVolume(0);
  UpdateBars();

}

void __fastcall TdmRemote::HalfExecute(TObject *)
{
  client->setVolume(128);
  UpdateBars();
}

void __fastcall TdmRemote::FullExecute(TObject *)
{
  client->setVolume(255);
  UpdateBars();

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
  // TODO form manager - implement this property
//  if (chkFadeOld->Checked)
//    StopFade->Execute();

}

void __fastcall TdmRemote::SongChangedExecute(TObject *)
{
  // if special actions required, this action can do them

  // TODO form manager - implement this property
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

      LastLength = client->getPlaylistLength();
      LastIndex = CurrentIndex;
      CurrentIndex = client->getCurrentPlayPosition();

      frmPlaylist->lstSongs->Items->Clear();

      std::auto_ptr<TStringList> SongList(new TStringList());

	  std::string list = client->getStringList(IPC_GETPLAYLISTTITLE);

	  SongList->Clear();
	  SongList->Text = list.c_str();

	  frmPlaylist->lstSongs->Items->Assign(SongList.get());


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

void __fastcall TdmRemote::AddDirectoryExecute(TObject *)
{
 // attached to menu entry        
}
void __fastcall TdmRemote::AddPlayIistExecute(TObject *)
{
AnsiString str;
AnsiString commandstr;

  odlgMain->FileName = "";

  // TODO this is poor style
  if (false /* looking for playlist */){
    odlgMain->Filter = sPlayListFiles;
    }
  else{
    odlgMain->Filter = sAllFiles;
    }

  if (odlgMain->Execute())
  {

    std::auto_ptr<TStringList> Files(new TStringList);
    // sort strings by name, for now
    Files->Sorted = true;

    Files->Assign(odlgMain->Files);

    DoAddFiles(Files.get());
    PlaylistRefresh->Execute();
  } // if
}void __fastcall TdmRemote::DownExecute(TObject *)
{
 // TODO referenced from menu
}

void __fastcall TdmRemote::DownMoreExecute(TObject *)
{
 // TODO referenced from menu
}

void __fastcall TdmRemote::EndExecute(TObject *)
{
 // TODO referenced from menu        
}

void __fastcall TdmRemote::ExitExecute(TObject *)
{
  Application->Terminate();        
}

void __fastcall TdmRemote::LocateServersExecute(TObject *)
{
  AnsiString EndPoint = frmMain->ebEndPoint->Text;
  AnsiString Address = frmMain->ebAddress->Text;

  // TODO - should be done via an interface
  // block UI timer
  frmMain->timerMain->Enabled = false;
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
    DoBind(ServersForm->Address, ServersForm->EndPoint);
    delete ServersForm;
    // perform UI update
    frmMain->MainTimer(this);
    frmMain->timerMain->Enabled = true;
  }
}

void __fastcall TdmRemote::PlaceOnTrayExecute(TObject *)
{
  // TODO referenced from menu

}

void __fastcall TdmRemote::PlaylistRefreshCurrentExecute(TObject *)
{
  // TODO referenced from menu
}

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

void __fastcall TdmRemote::StartExecute(TObject *)
{
  // TODO referenced from menu
        
}

void __fastcall TdmRemote::UpExecute(TObject *)
{
  // TODO referenced from menu
}

void __fastcall TdmRemote::UpMoreExecute(TObject *)
{
  // TODO referenced from menu
}


void __fastcall TdmRemote::PlaylistDragDrop(int dropIndex, int currentPos)
{
  int i;

  bool CurrentSong;
  int NewPos;

  std::auto_ptr<TStringList> TopList(new TStringList());
  std::auto_ptr<TStringList> MiddleList(new TStringList());
  std::auto_ptr<TStringList> BottomList(new TStringList());

  /* rather wasteful, as we have to get all the undeleted items and resend them to winamp*/


    for (i = 0 ; i < FPlaylistForm->lstSongs->Items->Count; i++)
    {
        std::string filename = client->getPlayListItem(i, false);

      CurrentSong = i == currentPos;

      if (FPlaylistForm->lstSongs->Selected[i])
      {
        MiddleList->AddObject(filename.c_str(), (TObject *) CurrentSong);
      }
      else if (i < dropIndex)
      {
        TopList->AddObject(filename.c_str(), (TObject *) CurrentSong);
      }
      else
      {
        BottomList->AddObject(filename.c_str(), (TObject *) CurrentSong);
      }
    } // for

    // rebuild list
    TopList->AddStrings(MiddleList.get());
    TopList->AddStrings(BottomList.get());
  // reset position

    DoAddFiles(TopList.get());

    NewPos = TopList->IndexOfObject((TObject *) true);

    PlaylistRefresh->Execute();

    if (NewPos >= 0)
    	client->setPlaylistIndex(NewPos);

}


void __fastcall TdmRemote::SetSongPosition(int pos, int width)
{

	int SongS = 0, PosMS;
	client->getTimes(SongS, PosMS);
	client->setTime((1000 * SongS * pos) / width);

}



void __fastcall TdmRemote::SetVolume(int volume)
{
  client->setVolume(volume);
}


void __fastcall TdmRemote::SetBalance(int balance)
{
  client->setPanning(balance);
}


void __fastcall TdmRemote::BarChange(int index, byte position)
{

	client->setEQData(index, position );
}


void __fastcall TdmRemote::UpdateBars()
{

	if (FPlaylistForm)
	{
		vector<int> bands;
		for (int i = 0; i < 11; i++)
		{
			bands.push_back(dmRemote->client->getEQData(i));
		}

		FSettingsForm->UpdateBars(dmRemote->client->getAutoload(),
								  dmRemote->client->getEQOn(),
								  bands);
	}
}

void __fastcall TdmRemote::UpdateValues()
{

	Shuffle->Checked = (client->winampVersion() >= 0x2604) && client->getShuffle();
    Repeat->Checked = (client->winampVersion() >= 0x2604) && client->getRepeat();

    frmSettings->tbVolume->Position = client->getVolume();
    frmSettings->tbBalance->Position = client->getPanning();

    UpdateBars();

	dmRemote->PlaylistRefreshStats->Execute();


}

WAPlaybackStatus __fastcall TdmRemote::PlaybackStatus()
{
    return client->getPlaybackStatus();
}

std::string __fastcall TdmRemote::WinampVersionString()
{
    return ::WinampVersionString(client->winampVersion());
}

std::string __fastcall TdmRemote::CurrentSong()
{
	int index = client->getCurrentPlayPosition();
	std::string title = "";
	if (index > 0)
		title = client->getPlayListItem(index, true);

	return title;
}

void __fastcall TdmRemote::GetPlaylistState(int& length, int & index)
{
	index = client->getCurrentPlayPosition();
	length = client->getPlaylistLength();
}

void __fastcall TdmRemote::DoDeleteSelected(void)
{
    int i;
	WinampRemote::Utils::CursorGuard ci(crAppStart);
	std::auto_ptr < TStringList > StringList(new TStringList);

	/* rather wasteful, as we have to get all the undeleted items and resend them to winamp*/
	std::string list = client->getStringList(IPC_GETPLAYLISTFILE);

	StringList->Text = list.c_str();

	for (i = FPlaylistForm->lstSongs->Items->Count - 1; i >= 0; i--)
	{
		if (FPlaylistForm->lstSongs->Selected[i])
		{

			StringList->Delete(i);
			if (i < CurrentIndex)
				CurrentIndex--;
		}
	} // for

	// add remaining
	dmRemote->DoAddFiles(StringList.get());
	// reset position

	dmRemote->client->setPlaylistIndex(CurrentIndex);

	dmRemote->PlaylistRefresh->Execute();

}

void __fastcall TdmRemote::DataModuleCreate(TObject *)
{
  client = new WinampRemote::Client::WinampClientBase();
}

void __fastcall TdmRemote::DataModuleDestroy(TObject *)
{
  delete client;
}

void __fastcall TdmRemote::registerForm(TForm * aForm)
{
	// TODO PMM - this could be made generic in a couple of ways
	{
		TfrmPlaylist * form = dynamic_cast<TfrmPlaylist *>(aForm);
		if (form)
		{
			hookEvents(aForm, FPlaylistForm);
			FPlaylistForm = form;
		}
	}
	{
		TfrmMain * form = dynamic_cast<TfrmMain *>(aForm);
		if (form)
		{
			hookEvents(aForm, FMainForm);
			FMainForm = form;
		}
	}
	{
		TfrmSettings * form = dynamic_cast<TfrmSettings *>(aForm);
		if (form)
		{
			hookEvents(aForm, FSettingsForm);
			FSettingsForm = form;
		}
	}
	{
		TfrmCommands * form = dynamic_cast<TfrmCommands *>(aForm);
		if (form)
		{
			hookEvents(aForm, FCommandsForm);
			FCommandsForm = form;
		}
	}
}

void __fastcall TdmRemote::unRegisterForm(TForm * aForm)
{
	if (aForm == FPlaylistForm)
		FPlaylistForm = NULL;
	if (aForm == FMainForm)
		FMainForm = NULL;
	if (aForm == FSettingsForm)
		FSettingsForm = NULL;
}

//---------------------------------------------------------------------------

