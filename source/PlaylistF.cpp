/*
winamp remote control suite �Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000,2001,2002  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/


#include <vcl.h>
#pragma hdrstop

#include "PlaylistF.h"
#include "waint.h"
#include "MainF.h"
#include "shellapi.h"
#include "remotestrs.h"
#include "remoteDM.h"


#pragma package(smart_init)
#pragma resource "*.dfm"

#include "winampinterface.h"    // header file generated by MIDL compiler

const int Offset = 4;

TfrmPlaylist *frmPlaylist;

__fastcall TfrmPlaylist::TfrmPlaylist(TComponent* Owner)
    : TForm(Owner), _currentpos(0), _lastindex(0), _lastlength(0)
{
}


void __fastcall TfrmPlaylist::lstSongsDblClick(TObject *)
{

  // this action will use the playlist itemindex, and do the pre and post actions
  dmRemote->NewSong->Execute();

}

void __fastcall TfrmPlaylist::FormCreate(TObject *)
{

  lstSongs->ItemHeight = Canvas->TextHeight('W');
  // TODO register with main datamodule
  dmRemote->registerForm(this);
  dmRemote->PlaylistRefresh->Execute();

}



void __fastcall TfrmPlaylist::DeleteSelected(void)
{
  frmMain->DoDeleteSelected();

}

// debug stuffs
/*

odSelected, odGrayed, odDisabled, odChecked, odFocused, odDefault, odHotLight, odInactive,
	odNoAccel, odNoFocusRect, odReserved1, odReserved2, odComboBoxEdit

*/

const char* States[odComboBoxEdit + 1] =
{"odSelected",  "odGrayed",  "odDisabled",  "odChecked",  "odFocused",  "odDefault",  "odHotLight",  "odInactive",
	"odNoAccel",  "odNoFocusRect",  "odReserved1",  "odReserved2",  "odComboBoxEdit"
};

void itemState(TOwnerDrawState State)
{
  AnsiString setstr;

  for (Windows__1 i = odSelected ; i < odComboBoxEdit ; i++)
  {
        if (State.Contains(i))
                setstr += AnsiString(States[i]) + " ";
  }
}

 void __fastcall TfrmPlaylist::lstSongsDrawItem(TWinControl *Control, int Index, const TRect &Rect, TOwnerDrawState State)
{
  TListBox * ListBox = (TListBox *) Control;
  AnsiString ItemText = ListBox->Items->Strings[Index];
  TCanvas * Canvas = ListBox->Canvas;

  if (State.Contains(odFocused))
        return;

  itemState(State);

  if (Index == frmMain->CurrentIndex)
    Canvas->Font->Color = clRed;

  itemState(State);

  Canvas->TextOut(Rect.Left + Offset, Rect.Top, ItemText);

  if (Index == frmMain->CurrentIndex)
    Canvas->Font->Color = clWindowText;

}

 void __fastcall TfrmPlaylist::lstSongsDrawItemGlass(TWinControl *Control,
                                                     int Index, const TRect &Rect,
                                                     TOwnerDrawState State)
{
  TListBox * ListBox = (TListBox *) Control;
  AnsiString ItemText = ListBox->Items->Strings[Index];
  TCanvas * Canvas = ListBox->Canvas;

  if (State.Contains(odFocused))
        return;

  itemState(State);

  // paints now accumulate, so this is needed
  Canvas->FillRect(Rect);
  ge->drawGlowText(Canvas->Handle, ItemText, Rect, (Index == frmMain->CurrentIndex) );
}


void __fastcall TfrmPlaylist::DropFiles(TMessage& Msg)
{
  int len, i;
  char CFileName[MAX_PATH];
  TStringList * Files = new TStringList;
  void * hDrop = (void *) Msg.WParam;
  TPoint DropPoint;

  int DropIndex;
  DragQueryPoint(hDrop, &DropPoint);

  // this returns -1 if there was no hit item
  DropIndex = lstSongs->ItemAtPos(DropPoint, true);

  try
  {
    // this gets the dragged files list and passes them onto the form
    len = DragQueryFile((void *) hDrop, 0xFFFFFFFF, NULL, 0);
    for (i = 0 ; i < len ; i++){
      if (DragQueryFile((void *) hDrop, i, CFileName, MAX_PATH) > 0){
        Files->Add(CFileName);
        }
      }
     dmRemote->DropFiles(Files, DropIndex);
    }
  __finally
  {
    DragFinish((void *) Msg.WParam);
    delete Files;
  }

}

void __fastcall TfrmPlaylist::SongIndexUpdate(TObject *)
{

  try
  {
    lstSongs->Items->BeginUpdate();
     // update the current title, at least
     std::string current = dmRemote->client->getPlayListItem(_currentpos, true);

     if ((lstSongs->Items->Count - 1) > _currentpos)
     {
       bool Selected = lstSongs->Selected[_currentpos];
       lstSongs->Items->Strings[_currentpos] = current.c_str();
       lstSongs->Selected[_currentpos] =  Selected;
     }


    /*much neater...*/
    lstSongs->TopIndex = _currentpos - 2;
    lstSongs->Update();

  }
  __finally
  {
    lstSongs->Items->EndUpdate();
  }
}



void __fastcall TfrmPlaylist::lstSongsDragOver(TObject *, TObject *, int , int , TDragState , bool &Accept)
{
  Accept = true;
}


void __fastcall TfrmPlaylist::lstSongsDragDrop(TObject *, TObject *, int X, int Y)
{
  int i;

  bool CurrentSong;
  int NewPos;

  // want to know if exceed the list length
  int DropIndex = lstSongs->ItemAtPos(TPoint(X, Y), false);


  TStringList * TopList = new TStringList;
  TStringList * MiddleList = new TStringList;
  TStringList * BottomList = new TStringList;

  try
  {
  /* rather wasteful, as we have to get all the undeleted items and resend them to winamp*/


    for (i = 0 ; i < lstSongs->Items->Count; i++)
    {
        std::string filename = dmRemote->client->getPlayListItem(i, false);

      CurrentSong = i == _currentpos;

      if (lstSongs->Selected[i])
      {
        MiddleList->AddObject(filename.c_str(), (TObject *) CurrentSong);
      }
      else if (i < DropIndex)
      {
        TopList->AddObject(filename.c_str(), (TObject *) CurrentSong);
      }
      else
      {
        BottomList->AddObject(filename.c_str(), (TObject *) CurrentSong);
      }
    } // for

    // rebuild list
    TopList->AddStrings(MiddleList);
    TopList->AddStrings(BottomList);
  // reset position

    // TODO: form manager - should be in forms management interface
    dmRemote->DoAddFiles(TopList);

    NewPos = TopList->IndexOfObject((TObject *) true);
    dmRemote->client->setPlaylistIndex(NewPos);

    // TODO: form manager - need refresh playlist event
    dmRemote->PlaylistRefresh->Execute();
  }
  __finally
  {
    delete BottomList;
    delete MiddleList;
    delete TopList;
  }
}



void __fastcall TfrmPlaylist::FormStartDock(TObject *Sender,
      TDragDockObject *&DragObject)
{
	// TODO: form manager - should be hooked
  frmMain->StartDock(Sender, DragObject);

}




void __fastcall TfrmPlaylist::FormShow(TObject *)
{
  // TODO custom OnShow prevents having a generic hook in the datamodule 
  // extend glass on Aero
  ge = new GlassExtender(this);
  if (ge->isCompositionActive())
  {
      lstSongs->Color = clNone;
      lstSongs->BorderStyle = bsNone;

      pnlBottom->Color = clNone;
      pnlBottom->BorderStyle = bsNone;

      sbPlaylist->Color = clNone;
      lstSongs->OnDrawItem = lstSongsDrawItemGlass;
  }
  // need to re-assert this
  DragAcceptFiles(lstSongs->Handle, true);
}



void __fastcall TfrmPlaylist::lstSongsMouseMove(TObject *, TShiftState , int X, int Y)
{

  int Index = lstSongs->ItemAtPos(TPoint(X, Y), true);

  if (Index > -1)
  {
    if (lstSongs->Canvas->TextWidth(lstSongs->Items->Strings[Index]) > lstSongs->ClientWidth - Offset)
    {
      lstSongs->Hint = lstSongs->Items->Strings[Index];
    }
    else
      lstSongs->Hint = "";

  }
  else
  {
    lstSongs->Hint = sPlaylistHint;
  }

}




void __fastcall TfrmPlaylist::mnuPlayClick(TObject *)
{

  if (BelowIndex > -1)
  {
    lstSongs->ItemIndex = BelowIndex;
    lstSongsDblClick(this);
  }

}




void __fastcall TfrmPlaylist::pmnuSongsPopup(TObject *)
{

  BelowIndex = lstSongs->ItemAtPos(lstSongs->ScreenToClient(Mouse->CursorPos), true);
  mnuPlay->Enabled = (BelowIndex > -1);
  if (BelowIndex > -1)
    mnuPlay->Caption = lstSongs->Items->Strings[BelowIndex];
  else
    mnuPlay->Caption = sPlay;


}




void __fastcall TfrmPlaylist::lstSongsKeyDown(TObject *, WORD &Key, TShiftState )
{

  switch (Key)
  {
    case VK_DELETE:
      DeleteSelected(); break;
    case VK_RETURN :
      lstSongsDblClick(this); break;
    case VK_F5 :
      mnuRefreshClick(this); break;

  }

}




void __fastcall TfrmPlaylist::pbSongPosMouseUp(TObject *, TMouseButton , TShiftState , int , int )
{

  fDragging = false;

}




void __fastcall TfrmPlaylist::pbSongPosMouseMove(TObject *, TShiftState , int X, int Y)
{

  if (fDragging)
  {
    if (PtInRect(&(pbSongPos->ClientRect), TPoint(X,Y)))
    {
      pbSongPos->Position = (pbSongPos->Max *  X) / pbSongPos->ClientWidth;
      int PosMS, SongS;
      dmRemote->client->getTimes(SongS, PosMS);
      dmRemote->client->setTime( (1000 *  SongS *  X) / pbSongPos->ClientWidth);

    }
  }


}




void __fastcall TfrmPlaylist::pbSongPosMouseDown(TObject *, TMouseButton , TShiftState , int , int )
{
  fDragging = true;
}


void __fastcall TfrmPlaylist::mnuRefreshClick(TObject *)
{
  dmRemote->PlaylistRefresh->Execute();
}


void __fastcall TfrmPlaylist::lstSongsMeasureItem(TWinControl *, int , int &Height)
{
   Height = 17;        
}


void __fastcall TfrmPlaylist::FormDestroy(TObject *Sender)
{
  dmRemote->unRegisterForm(this);
}
//---------------------------------------------------------------------------

