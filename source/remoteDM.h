//---------------------------------------------------------------------------

#ifndef remoteDMH
#define remoteDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>

#include "IWinamp.h"
#include "waint.h"

#include "MainF.h"
#include "PlaylistF.h"
#include "SettingsF.h"
#include "CommandF.h"

#include <Dialogs.hpp>

//---------------------------------------------------------------------------
class TdmRemote : public TDataModule
{
__published:	// IDE-managed Components
        TActionList *alMain;
        TAction *Configuration;
        TAction *PlaceOnTray;
        TAction *Exit;
        TAction *ViewToolBar;
        TAction *Pause;
        TAction *Play;
        TAction *Stop;
        TAction *StopFade;
        TAction *StopAfterCurrent;
        TAction *Forward5;
        TAction *Back5;
        TAction *ViewPlaylist;
        TAction *Shuffle;
        TAction *Repeat;
        TAction *Next;
        TAction *Previous;
        TAction *Start;
        TAction *End;
        TAction *Delete;
        TAction *PlaylistRefresh;
        TAction *PlayFromStart;
        TAction *AddFiles;
        TAction *AddPlayIist;
        TAction *AddDirectory;
        TAction *ViewVolume;
        TAction *Up;
        TAction *Down;
        TAction *UpMore;
        TAction *DownMore;
        TAction *Zero;
        TAction *Half;
        TAction *Full;
        TAction *About;
        TAction *ShowMainForm;
        TAction *LocateServers;
        TAction *Autoload;
        TAction *Details;
        TAction *NextFade;
        TAction *PreviousFade;
        TAction *SongChanging;
        TAction *SongChanged;
        TAction *NewSong;
        TAction *PlaylistRefreshCurrent;
        TAction *PlaylistRefreshStats;
        TAction *EQOn;
        TOpenDialog *odlgMain;

void __fastcall PauseExecute(TObject * Sender);
void __fastcall PlayExecute(TObject *Sender);
void __fastcall NextExecute(TObject *Sender);
void __fastcall NextFadeExecute(TObject *Sender);
void __fastcall PreviousExecute(TObject *Sender);
void __fastcall StopExecute(TObject *Sender);
void __fastcall Forward5Execute(TObject *Sender);
void __fastcall Back5Execute(TObject *Sender);
void __fastcall VolumeUpExecute(TObject *Sender);
void __fastcall VolumeDownExecute(TObject *Sender);
void __fastcall VolumeUpMoreExecute(TObject *Sender);
void __fastcall VolumeDownMoreExecute(TObject *Sender);
void __fastcall PlaylistStartExecute(TObject *Sender);
void __fastcall PlaylistEndExecute(TObject *Sender);
void __fastcall DeletePlayListExecute(TObject *Sender);
void __fastcall StopFadeExecute(TObject *Sender);
void __fastcall StopAfterCurrentExecute(TObject *Sender);
void __fastcall SetVolume0Execute(TObject *Sender);
void __fastcall SetVolume100Execute(TObject *Sender);
void __fastcall ShuffleExecute(TObject *Sender);
void __fastcall RepeatExecute(TObject *Sender);
void __fastcall PlayFromStartExecute(TObject *Sender);
void __fastcall HalfExecute(TObject *Sender);
void __fastcall ViewToolBarExecute(TObject *Sender);
void __fastcall ViewPlaylistExecute(TObject *Sender);
void __fastcall ViewVolumeExecute(TObject *Sender);
void __fastcall AutoloadExecute(TObject *Sender);
void __fastcall EQOnExecute(TObject *Sender);
void __fastcall DetailsExecute(TObject *Sender);
void __fastcall PreviousFadeExecute(TObject *Sender);
void __fastcall SongChangingExecute(TObject *Sender);
void __fastcall SongChangedExecute(TObject *Sender);
void __fastcall NewSongExecute(TObject *Sender);
void __fastcall PlaylistRefreshExecute(TObject *Sender);
void __fastcall PlaylistRefreshStatsExecute(TObject *Sender);
        void __fastcall AboutExecute(TObject *Sender);
        void __fastcall AddDirectoryExecute(TObject *Sender);
        void __fastcall AddFilesExecute(TObject *Sender);
        void __fastcall AddPlayIistExecute(TObject *Sender);
        void __fastcall ConfigurationExecute(TObject *Sender);
        void __fastcall DeleteExecute(TObject *Sender);
        void __fastcall DownExecute(TObject *Sender);
        void __fastcall DownMoreExecute(TObject *Sender);
        void __fastcall EndExecute(TObject *Sender);
        void __fastcall ExitExecute(TObject *Sender);
        void __fastcall FullExecute(TObject *Sender);
        void __fastcall LocateServersExecute(TObject *Sender);
        void __fastcall PlaceOnTrayExecute(TObject *Sender);
        void __fastcall PlaylistRefreshCurrentExecute(TObject *Sender);
        void __fastcall ShowMainFormExecute(TObject *Sender);
        void __fastcall StartExecute(TObject *Sender);
        void __fastcall UpExecute(TObject *Sender);
        void __fastcall UpMoreExecute(TObject *Sender);
        void __fastcall ZeroExecute(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);


private:	// User declarations
        int LastLength;
        int LastIndex;
        int CurrentIndex;

		WinampRemote::Client::IWinamp * client;

		TfrmPlaylist * FPlaylistForm;
		TfrmMain * FMainForm;
		TfrmSettings * FSettingsForm;
		TfrmCommands * FCommandsForm;


        void __fastcall GetFilenames(int Start, int Stop, TStringList * Files);
        void hookEvents(TForm * NewForm, TForm * PriorForm);
        void __fastcall ChildFormStartDock(TObject *Sender, TDragDockObject *&DragObject);
        void __fastcall ChildFormClose(TObject * aForm, TCloseAction & aAction);
public:		// User declarations
        __fastcall TdmRemote(TComponent* Owner);
        void setClient(WinampRemote::Client::IWinamp * client_);
        void __fastcall DropFiles(TStringList * DropFiles, int DropIndex);
        void __fastcall DoAddFiles(TStrings * Files, int selectedIndex = -1);
        void __fastcall PlaylistDragDrop(int dropIndex, int currentPos);
        void __fastcall SetSongPosition(int pos, int width);

        void __fastcall SetVolume(int volume);
        void __fastcall SetBalance(int balance);
        void __fastcall BarChange(int index, byte position);
        void __fastcall UpdateBars();
        void __fastcall UpdateValues();
        WAPlaybackStatus __fastcall PlaybackStatus();
        std::string __fastcall WinampVersionString();
        std::string __fastcall TdmRemote::CurrentSong();
        void __fastcall GetPlaylistState(int& length, int & index);

        void __fastcall DoDeleteSelected(void);
        void __fastcall DoBind(const AnsiString& address, const AnsiString& endpoint);
        void __fastcall registerForm(TForm * aForm);
        void __fastcall unRegisterForm(TForm * aForm);


};
//---------------------------------------------------------------------------
extern PACKAGE TdmRemote *dmRemote;
//---------------------------------------------------------------------------
#endif
