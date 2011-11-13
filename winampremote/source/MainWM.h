//---------------------------------------------------------------------------
#ifndef MainWMH
#define MainWMH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
//---------------------------------------------------------------------------
class TwmMain : public TWebModule
{
__published:	// IDE-managed Components
        TPageProducer *ppGetPlaylist;
        void __fastcall ppGetPlaylistHTMLTag(TObject *Sender, TTag Tag,
          const AnsiString TagString, TStrings *TagParams,
          AnsiString &ReplaceText);
        void __fastcall WebModuleBeforeDispatch(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
        void __fastcall WebModuleAfterDispatch(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
        void __fastcall wmMainwaDefaultAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
private:	// User declarations
public:		// User declarations
	__fastcall TwmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TwmMain *wmMain;
//---------------------------------------------------------------------------
#endif
