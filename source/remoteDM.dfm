object dmRemote: TdmRemote
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Left = 376
  Top = 175
  Height = 480
  Width = 928
  object alMain: TActionList
    Images = frmMain.imlActions
    Left = 17
    Top = 8
    object Configuration: TAction
      Category = 'File'
      Caption = '&Configuration'
      Hint = 'Configuration'
      ImageIndex = 7
      OnExecute = ConfigurationExecute
    end
    object PlaceOnTray: TAction
      Category = 'File'
      Caption = 'Place On &Tray'
      Hint = 'Place on Tray'
      ImageIndex = 6
      ShortCut = 16456
      OnExecute = PlaceOnTrayExecute
    end
    object Exit: TAction
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'File Exit'
      ImageIndex = 27
      OnExecute = ExitExecute
    end
    object ViewToolBar: TAction
      Category = 'Action'
      Caption = 'View &ToolBar'
      Hint = 'Commands Toolbar'
      ImageIndex = 8
      OnExecute = ViewToolBarExecute
    end
    object Pause: TAction
      Category = 'Action'
      Caption = '&Pause'
      Hint = 'Pause'
      ImageIndex = 2
      OnExecute = PauseExecute
    end
    object Play: TAction
      Category = 'Action'
      Caption = 'P&lay'
      Hint = 'Play'
      ImageIndex = 1
      OnExecute = PlayExecute
    end
    object Stop: TAction
      Category = 'Action'
      Caption = '&Stop'
      Hint = 'Stop'
      ImageIndex = 3
      OnExecute = StopExecute
    end
    object StopFade: TAction
      Category = 'Action'
      Caption = 'Stop With &Fade'
      Hint = 'Stop with Fade'
      ImageIndex = 3
      OnExecute = StopFadeExecute
    end
    object StopAfterCurrent: TAction
      Category = 'Action'
      Caption = 'Stop After &Current'
      Hint = 'Stop after Current'
      ImageIndex = 3
      OnExecute = StopAfterCurrentExecute
    end
    object Forward5: TAction
      Category = 'Action'
      Caption = '&Forward 5 seconds'
      Hint = 'Forward 5'
      ImageIndex = 4
      OnExecute = Forward5Execute
    end
    object Back5: TAction
      Category = 'Action'
      Caption = '&Back 5 seconds'
      Hint = 'Back 5'
      ImageIndex = 0
      OnExecute = Back5Execute
    end
    object ViewPlaylist: TAction
      Category = 'Playlist'
      Caption = 'View &Playlist'
      Hint = 'Playlist Editor'
      ImageIndex = 10
      OnExecute = ViewPlaylistExecute
    end
    object Shuffle: TAction
      Category = 'Playlist'
      Caption = '&Shuffle'
      Hint = 'Playlist Shuffle'
      ImageIndex = 11
      OnExecute = ShuffleExecute
    end
    object Repeat: TAction
      Category = 'Playlist'
      Caption = '&Repeat'
      Hint = 'Playlist Repeat'
      ImageIndex = 12
      OnExecute = RepeatExecute
    end
    object Next: TAction
      Category = 'Playlist'
      Caption = '&Next'
      Hint = 'Next in Playlist'
      ImageIndex = 4
      OnExecute = NextExecute
    end
    object Previous: TAction
      Category = 'Playlist'
      Caption = '&Previous'
      Hint = 'Previous in Playlist'
      ImageIndex = 0
      OnExecute = PreviousExecute
    end
    object Start: TAction
      Category = 'Playlist'
      Caption = 'St&art'
      Hint = 'Start of Playlist'
      ImageIndex = 0
      OnExecute = StartExecute
    end
    object End: TAction
      Category = 'Playlist'
      Caption = '&End'
      Hint = 'End of Playlist'
      ImageIndex = 4
      OnExecute = EndExecute
    end
    object Delete: TAction
      Category = 'Playlist'
      Caption = '&Delete'
      Hint = 'Delete Playlist'
      ImageIndex = 15
      OnExecute = DeleteExecute
    end
    object PlaylistRefresh: TAction
      Category = 'Playlist'
      Caption = 'PlaylistRefresh'
      ImageIndex = 13
      OnExecute = PlaylistRefreshExecute
    end
    object PlayFromStart: TAction
      Category = 'Playlist'
      Caption = 'Play &From Start'
      Hint = 'Play from Start'
      ImageIndex = 0
      Visible = False
      OnExecute = PlayFromStartExecute
    end
    object AddFiles: TAction
      Category = 'Playlist'
      Caption = 'Add Fi&les'
      Hint = 'Add Files To Playlist'
      ImageIndex = 16
      OnExecute = AddFilesExecute
    end
    object AddPlayIist: TAction
      Category = 'Playlist'
      Caption = 'Add Pla&ylist'
      Hint = 'Add Playlist'
      ImageIndex = 17
      Visible = False
      OnExecute = AddPlayIistExecute
    end
    object AddDirectory: TAction
      Category = 'Playlist'
      Caption = 'Add Direc&tory'
      Hint = 'add Directory'
      ImageIndex = 18
      Visible = False
      OnExecute = AddDirectoryExecute
    end
    object ViewVolume: TAction
      Category = 'Volume'
      Caption = 'View &Settings'
      Hint = 'Audio Settings Editor'
      ImageIndex = 9
      OnExecute = ViewVolumeExecute
    end
    object Up: TAction
      Category = 'Volume'
      Caption = '&Up'
      Hint = 'Volume Up'
      ImageIndex = 19
      OnExecute = UpExecute
    end
    object Down: TAction
      Category = 'Volume'
      Caption = '&Down'
      Hint = 'Voume Down'
      ImageIndex = 20
      OnExecute = DownExecute
    end
    object UpMore: TAction
      Category = 'Volume'
      Caption = 'Up &More'
      Hint = 'Volume Up (More)'
      ImageIndex = 21
      OnExecute = UpMoreExecute
    end
    object DownMore: TAction
      Category = 'Volume'
      Caption = 'Down M&ore'
      Hint = 'Volume Down (more)'
      ImageIndex = 22
      OnExecute = DownMoreExecute
    end
    object Zero: TAction
      Category = 'Volume'
      Caption = '&Zero'
      Hint = 'Volume off'
      ImageIndex = 23
      OnExecute = ZeroExecute
    end
    object Half: TAction
      Category = 'Volume'
      Caption = '50 %'
      Hint = 'Volume 50%'
      ImageIndex = 25
      OnExecute = HalfExecute
    end
    object Full: TAction
      Category = 'Volume'
      Caption = '&Full'
      Hint = 'Volume FULL'
      ImageIndex = 24
      OnExecute = FullExecute
    end
    object About: TAction
      Category = 'Help'
      Caption = '&About'
      Hint = 'About this Application '
      ImageIndex = 26
      OnExecute = AboutExecute
    end
    object ShowMainForm: TAction
      Category = 'File'
      Caption = 'Show'
      Hint = 'Show'
      ImageIndex = 0
      OnExecute = ShowMainFormExecute
    end
    object LocateServers: TAction
      Category = 'File'
      Caption = '&Locate Servers'
      Hint = 'locate possible winamp servers'
      ImageIndex = 26
      ShortCut = 16460
      OnExecute = LocateServersExecute
    end
    object Autoload: TAction
      Category = 'Volume'
      Caption = 'EQ Autoload'
      Hint = 'Autoload EQ settings'
      ImageIndex = 13
      OnExecute = AutoloadExecute
    end
    object Details: TAction
      Category = 'Help'
      Caption = 'Details'
      ImageIndex = 7
      OnExecute = DetailsExecute
    end
    object NextFade: TAction
      Category = 'Playlist'
      Caption = 'Next with &Fade'
      ImageIndex = 4
      OnExecute = NextFadeExecute
    end
    object PreviousFade: TAction
      Category = 'Playlist'
      Caption = 'Previous with F&ade'
      ImageIndex = 0
      OnExecute = PreviousFadeExecute
    end
    object SongChanging: TAction
      Category = 'Playlist'
      Caption = 'SongChanging'
      ImageIndex = 26
      OnExecute = SongChangingExecute
    end
    object SongChanged: TAction
      Category = 'Playlist'
      Caption = 'SongChanging'
      ImageIndex = 26
      OnExecute = SongChangedExecute
    end
    object NewSong: TAction
      Category = 'Playlist'
      Caption = 'NewSong'
      ImageIndex = 26
      OnExecute = NewSongExecute
    end
    object PlaylistRefreshCurrent: TAction
      Category = 'Playlist'
      Caption = 'PlaylistRefresh'
      ImageIndex = 13
      OnExecute = PlaylistRefreshCurrentExecute
    end
    object PlaylistRefreshStats: TAction
      Category = 'Playlist'
      Caption = 'PlaylistRefreshStats'
      ImageIndex = 26
      OnExecute = PlaylistRefreshStatsExecute
    end
    object EQOn: TAction
      Category = 'Volume'
      Caption = 'EQOn'
      ImageIndex = 12
      OnExecute = EQOnExecute
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Playlist Files|*.m3u, *.pls'
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofPathMustExist, ofFileMustExist]
    Left = 80
    Top = 8
  end
end
