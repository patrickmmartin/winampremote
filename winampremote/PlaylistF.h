//---------------------------------------------------------------------------
#ifndef PlaylistFH
#define PlaylistFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmPlaylist : public TForm
{
__published:	// IDE-managed Components
    TListBox *lstSongs;
    TPopupMenu *pmnuSongs;
    TMenuItem *mnuRefresh;
    TMenuItem *mnuSort;
    TMenuItem *mnuSortFile;
    TMenuItem *mnuSortFileEntire;
    TMenuItem *mnuDelete;
    TMenuItem *mnuAddFiles;
        TMenuItem *Repeat1;
        TMenuItem *Shuffle1;
    void __fastcall lstSongsRefresh(TObject *Sender);
    void __fastcall lstSongsDblClick(TObject *Sender);

    void __fastcall mnuSortClick(TObject *Sender);

    void __fastcall FormCreate(TObject *Sender);
    void __fastcall lstSongsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall lstSongsDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall lstSongsDragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
        void __fastcall lstSongsDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);

private:	// User declarations
    void __fastcall DeleteSelected(void);
    void __fastcall DropFiles(TMessage& Msg);
    void __fastcall GetFilenames(int Start, int Stop, TStringList * StringList);

public:     // User declarations
    int currentpos;
    int lastindex;
    int lastlength;
    __fastcall TfrmPlaylist(TComponent* Owner);
    void __fastcall SongIndexUpdate(TObject *Sender);
    void __fastcall AddFiles(TStringList * Files);
BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(WM_DROPFILES,TMessage,DropFiles)
END_MESSAGE_MAP(TForm)

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPlaylist *frmPlaylist;
//---------------------------------------------------------------------------
#endif
