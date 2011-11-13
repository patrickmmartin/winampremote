//---------------------------------------------------------------------------
#include "MainWM.h"

#include <ISAPIApp.hpp>
#include <CGIApp.hpp>

#include "RPCFuncsU.h"
#include "Waint.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TwmMain *wmMain;
//---------------------------------------------------------------------------
__fastcall TwmMain::TwmMain(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TwmMain::ppGetPlaylistHTMLTag(TObject *Sender, TTag Tag,
      const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{

const AnsiString RowFmt = "<TR><TD> %s <A HREF = \"%s/admin/addfile?index=%d&key=%d\" >%s</A> %s </TD></TR>\r\n";
int i, CurrentIndex;
AnsiString OpenTag, CloseTag;
int RequestKey;
TStringList * StringList;



  if (Tag == tgCustom)
  {
    if (TagString.UpperCase() == "PLAYLIST" )
    {

      ReplaceText = "";
      RequestKey = GetTickCount();
      StringList = new TStringList;
      try
      {

        CurrentIndex = IntegerResult("user@localhost", IPC_GETLISTPOS, 0);

        void * buf = NULL;
        int bufsize = 0;

        GetList("user@localhost", &buf, bufsize, IPC_GETPLAYLISTTITLE);

        if (bufsize)
          StringList->Text = (char *) buf;

        if (buf)
          delete buf;

        for (i = 0 ; i < StringList->Count  ; i++ )
        {
          if (CurrentIndex == i)
          {
            OpenTag = "<B>";
            CloseTag = "<\B>";
          }
          else
          {
            OpenTag = "";
            CloseTag = "";
          }

          ReplaceText = ReplaceText + AnsiString().sprintf(RowFmt.c_str(),
                        OpenTag.c_str(), Request->ScriptName.c_str(), i + 1,
                        RequestKey, StringList->Strings[i], CloseTag.c_str());

        }
      }
      __finally
      {
        delete StringList;
      }
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TwmMain::WebModuleBeforeDispatch(TObject *Sender,
      TWebRequest *Request, TWebResponse *Response, bool &Handled)
{
  Bind("localhost", "8000");
}
//---------------------------------------------------------------------------

void __fastcall TwmMain::WebModuleAfterDispatch(TObject *Sender,
      TWebRequest *Request, TWebResponse *Response, bool &Handled)
{
  UnBind();
}
//---------------------------------------------------------------------------

void __fastcall TwmMain::wmMainwaDefaultAction(TObject *Sender,
      TWebRequest *Request, TWebResponse *Response, bool &Handled)
{

AnsiString TemplateFile = "playlist.htm";
    if (FileExists(Request->PathTranslated))
    {
      TemplateFile = Request->PathTranslated;
    }
    else
    {

      if (dynamic_cast<TCGIRequest *>(Request))
      {
        // we can use the base directory of the CGI, hopefully
       // leave Templatefile same

      }
      else
      if (dynamic_cast<TISAPIRequest *>(Request))
      {
        // we can attempt to obtain the correct directory for this plugin
        TemplateFile = Request->TranslateURI(Request->ScriptName) + "\playlist.htm";

      }

    }
  if (FileExists(TemplateFile))
  {
    ppGetPlaylist->HTMLDoc->LoadFromFile(TemplateFile);
  }
  // else just use rubbishy default
  Response->Content = ppGetPlaylist->Content();


}
//---------------------------------------------------------------------------

