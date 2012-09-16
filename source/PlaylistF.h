
#ifndef PlaylistFH
#define PlaylistFH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>


#include "IWinamp.h"
#include "GlassExtender.h"

/**
  UI class to display the winamp playlist and respond similarly to UI actions. 
*/
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
        TMenuItem *mnuPlay;
        TPanel *pnlBottom;
        TProgressBar *pbSongPos;
        TProgressBar *pbListPos;
        TStatusBar *sbPlaylist;
    void __fastcall lstSongsDblClick(TObject *Sender);

    void __fastcall FormCreate(TObject *Sender);
    void __fastcall lstSongsDrawItem(TWinControl *Control, int Index,
          const TRect &Rect, TOwnerDrawState State);
    void __fastcall lstSongsDrawItemGlass(TWinControl *Control, int Index,
          const TRect &Rect, TOwnerDrawState State);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall lstSongsDragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
        void __fastcall lstSongsDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
        void __fastcall FormStartDock(TObject *Sender,
          TDragDockObject *&DragObject);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall lstSongsMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall mnuPlayClick(TObject *Sender);
        void __fastcall pmnuSongsPopup(TObject *Sender);
        void __fastcall lstSongsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall pbSongPosMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall pbSongPosMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall pbSongPosMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall mnuRefreshClick(TObject *Sender);
        void __fastcall lstSongsMeasureItem(TWinControl *Control,
          int Index, int &Height);

private:	// User declarations

    int BelowIndex;
    bool fDragging;
    TStringList *SongList;
    GlassExtender * ge;

    void __fastcall DeleteSelected(void);
    void __fastcall DropFiles(TMessage& Msg);

private:     // User declarations

    int _currentpos;
    int _lastindex;
    int _lastlength;

    void __fastcall SongIndexUpdate(TObject *Sender);
public:
    __fastcall TfrmPlaylist(TComponent* Owner);
    bool __property Dragging = {read = fDragging};
    WinampRemote::Client::IWinamp * client;

BEGIN_MESSAGE_MAP
// handling file dropped into the playlist form 
MESSAGE_HANDLER(WM_DROPFILES,TMessage,DropFiles)
END_MESSAGE_MAP(TForm)

};

extern PACKAGE TfrmPlaylist *frmPlaylist;

#endif
