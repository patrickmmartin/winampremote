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

#include "messageF.h"
#include "ColourU.h"

#pragma package(smart_init)
#pragma resource "*.dfm"



TfrmMessage *frmMessage;

const TRect FinalSize = TRect(0, 0, 350, 150);

float startcount = 0;

__fastcall TfrmMessage::TfrmMessage(TComponent* Owner)
    : TForm(Owner)
{
}



void __fastcall TfrmMessage::FormShow(TObject *)
{
  tmrAnimate->Enabled = true;
  StartCount = GetTickCount();
}

void __fastcall TfrmMessage::tmrAnimateTimer(TObject *)
{
//

  int TicksCount = GetTickCount() - StartCount;
  memTitle->Font->Color = rainbowColour(TicksCount);
  if (TicksCount > 3000)
  {
    tmrAnimate->Enabled = false;
    Close();
  }
}

void __fastcall TfrmMessage::FormActivate(TObject *)
{
//
}





