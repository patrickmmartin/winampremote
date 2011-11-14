object frmMain: TfrmMain
  Left = 452
  Top = 279
  Hint = 'the winamp remote control client'
  Action = Shuffle
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Winamp Remote Control'
  ClientHeight = 172
  ClientWidth = 392
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Arial'
  Font.Style = []
  Menu = mnuMain
  OldCreateOrder = True
  Position = poScreenCenter
  OnClick = ShuffleExecute
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnEndDock = EndDock
  OnHide = FormHide
  OnShow = FormShow
  OnStartDock = StartDock
  PixelsPerInch = 96
  TextHeight = 14
  object icoTrayIcon: TImage
    Left = 344
    Top = 8
    Width = 16
    Height = 16
    AutoSize = True
    Picture.Data = {
      07544269746D617042020000424D420200000000000042000000280000001000
      0000100000000100100003000000000200000000000000000000000000000000
      0000007C0000E00300001F0000001F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7CEF3D00001F7C1F7C1F7CEF3D00001F7C
      1F7C1F7CEF3D00001F7C1F7C1F7CF75EEF3DEF3DEF3DEF3DF75EEF3DEF3DEF3D
      EF3DF75EEF3DEF3DEF3DEF3DEF3DFF7FEF3DEF3D1F7C1F7CFF7FEF3DEF3D1F7C
      1F7C1F7CF75E00001F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7CEF3D00001F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7CEF3D00001F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7CEF3D00001F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7CEF3D00001F7C1F7C1F7C1F7C1F7C003C003C1F7C1F7C1F7CEF3D1F7C
      1F7CEF3DEF3D00001F7C1F7C1F7C1F7C1F7C007C1F7C1F7C1F7C1F7C1F7CE03D
      EF3D00000000EF3D1F7C1F7C1F7C1F7C1F7C007C003C1F7C1F7C1F7C1F7CEF3D
      E03DE03D003CEF3DEF3D1F7C1F7C1F7C1F7C007C007C003C1F7C1F7CEF3DEF3D
      EF3DE07FE07FE03DEF3DEF3D1F7C003C003C1F7C007C007C1F7C1F7CEF3DEF3D
      E07FE07FE07FEF3DEF3DEF3D1F7C007C007C1F7C003C007C003C1F7C1F7CEF3D
      EF3DF75EE07FE07FEF3D1F7C1F7C1F7C007C003C007C007C1F7C1F7C1F7C1F7C
      EF3DEF3DEF3DEF3DE07FF75E1F7C1F7C1F7C007C007C1F7C1F7C1F7C1F7C1F7C
      1F7CEF3DEF3D1F7C1F7CF75E1F7C}
    Transparent = True
    Visible = False
  end
  object sbMain: TStatusBar
    Left = 0
    Top = 146
    Width = 392
    Height = 26
    Panels = <
      item
        Style = psOwnerDraw
        Width = 26
      end
      item
        Alignment = taCenter
        Width = 50
      end>
    SimplePanel = False
    OnDrawPanel = sbMainDrawPanel
  end
  object pgSettings: TPageControl
    Left = 0
    Top = 0
    Width = 392
    Height = 146
    Hint = 'pages of information and configuration'
    ActivePage = tbsMain
    Align = alClient
    DockSite = True
    HotTrack = True
    Images = imlActions
    TabHeight = 22
    TabOrder = 1
    OnDockDrop = pgSettingsDockDrop
    OnDockOver = FormDockOver
    object tbsMain: TTabSheet
      Hint = 'the parameters sent back from winamp'
      Caption = '&Winamp'
      ImageIndex = 5
      object pnlWinampBottom: TPanel
        Left = 0
        Top = 0
        Width = 384
        Height = 114
        Align = alClient
        BevelOuter = bvLowered
        Caption = 'pnlWinampBottom'
        TabOrder = 0
        object pnlIcon: TPanel
          Left = 1
          Top = 1
          Width = 382
          Height = 66
          Align = alClient
          BevelOuter = bvNone
          Caption = 'pnlIcon'
          TabOrder = 0
          object lblVersion: TLabel
            Left = 48
            Top = 23
            Width = 286
            Height = 43
            Hint = 'the winamp version on the server machine'
            Align = alClient
            Alignment = taCenter
            AutoSize = False
            Caption = 'unknown version'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Arial'
            Font.Style = []
            ParentFont = False
            ShowAccelChar = False
            Layout = tlCenter
            WordWrap = True
          end
          object lblMessage: TLabel
            Left = 0
            Top = 0
            Width = 382
            Height = 23
            Hint = 'the current track name, if accessible'
            Align = alTop
            Alignment = taCenter
            AutoSize = False
            Caption = 'connecting...'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            ShowAccelChar = False
            Layout = tlCenter
            WordWrap = True
          end
          object icoState: TImage
            Left = 0
            Top = 23
            Width = 48
            Height = 43
            Hint = 'graphical view of winamp status'
            Align = alLeft
            Center = True
            Transparent = True
          end
          object Bevel2: TBevel
            Left = 334
            Top = 23
            Width = 48
            Height = 43
            Align = alRight
            Shape = bsSpacer
          end
        end
        object Panel1: TPanel
          Left = 1
          Top = 67
          Width = 382
          Height = 46
          Align = alBottom
          Caption = 'pnlBottom'
          TabOrder = 1
          object Bevel3: TBevel
            Left = 306
            Top = 1
            Width = 75
            Height = 44
            Align = alRight
            Shape = bsSpacer
          end
          object Bevel1: TBevel
            Left = 1
            Top = 1
            Width = 75
            Height = 44
            Align = alLeft
            Shape = bsSpacer
          end
          object pnlMiddle: TPanel
            Left = 76
            Top = 1
            Width = 230
            Height = 44
            Align = alClient
            Caption = 'pnlMiddle'
            TabOrder = 0
            object pnlCommands: TPanel
              Left = 1
              Top = 1
              Width = 228
              Height = 42
              Align = alBottom
              BevelOuter = bvLowered
              Caption = 'commands'
              DockSite = True
              TabOrder = 0
              OnDockOver = FormDockOver
            end
          end
        end
      end
    end
    object tbsConfig: TTabSheet
      Hint = 'net configuration stuff'
      Caption = '&Net'
      ImageIndex = 7
      object bvl2: TBevel
        Left = 0
        Top = 0
        Width = 384
        Height = 114
        Align = alClient
      end
      object lblEndpoint: TLabel
        Left = 8
        Top = 12
        Width = 100
        Height = 21
        AutoSize = False
        Caption = '&Endpoint'
        FocusControl = ebEndPoint
        Layout = tlCenter
      end
      object lblAddress: TLabel
        Left = 8
        Top = 40
        Width = 100
        Height = 21
        AutoSize = False
        Caption = '&Address'
        FocusControl = ebAddress
        Layout = tlCenter
      end
      object lblTimer: TLabel
        Left = 8
        Top = 68
        Width = 100
        Height = 21
        AutoSize = False
        Caption = '&Interval'
        FocusControl = lstTimer
        Layout = tlCenter
      end
      object ebEndPoint: TEdit
        Left = 112
        Top = 12
        Width = 49
        Height = 21
        Hint = 'the server'#39's endpoint'
        AutoSize = False
        TabOrder = 0
        Text = '8000'
        OnChange = AddressChange
      end
      object ebAddress: TEdit
        Left = 112
        Top = 40
        Width = 145
        Height = 22
        Hint = 'the server'#39's address (ip or network neighbourhood name)'
        TabOrder = 1
        Text = 'localhost'
        OnChange = AddressChange
      end
      object lstTimer: TListBox
        Left = 112
        Top = 68
        Width = 146
        Height = 21
        Hint = 'interval between polling server'
        Columns = 11
        ItemHeight = 14
        Items.Strings = (
          ' 1'
          ' 2'
          ' 3'
          ' 4'
          ' 5'
          ' 6'
          ' 7'
          ' 8'
          ' 9'
          '10')
        TabOrder = 3
        OnClick = lstTimerClick
      end
      object btnLocate: TButton
        Left = 264
        Top = 40
        Width = 65
        Height = 22
        Action = LocateServers
        Caption = 'Locate ...'
        TabOrder = 2
      end
    end
    object tbsPreferences: TTabSheet
      Hint = 'user preferences'
      Caption = 'P&references'
      ImageIndex = 6
      object bvl3: TBevel
        Left = 0
        Top = 0
        Width = 384
        Height = 114
        Align = alClient
      end
      object lblUpdate: TLabel
        Left = 8
        Top = 36
        Width = 70
        Height = 14
        Caption = 'Update playlist'
      end
      object lblStartupActions: TLabel
        Left = 8
        Top = 12
        Width = 73
        Height = 14
        Caption = 'Startup actions'
      end
      object lblSongChange: TLabel
        Left = 8
        Top = 60
        Width = 71
        Height = 14
        Caption = 'Song Changed'
      end
      object chkAutoHide: TCheckBox
        Left = 96
        Top = 12
        Width = 153
        Height = 17
        Hint = 'hide self only if connection to server established'
        Caption = '&Hide if server found'
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object chkAutoRestore: TCheckBox
        Left = 232
        Top = 12
        Width = 153
        Height = 17
        Hint = 'restore the child windows'#39's last state upon startup'
        Caption = 'Restore child windows'
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
      object rbSongChange: TRadioButton
        Left = 96
        Top = 36
        Width = 120
        Height = 17
        Hint = 'playlist is obtained when the current song changes'
        Caption = 'song changed'
        TabOrder = 2
      end
      object rbPlaylistChange: TRadioButton
        Left = 232
        Top = 36
        Width = 120
        Height = 17
        Hint = 'playlist is obtained when the playlist is altered'
        Caption = 'playlist changed'
        TabOrder = 3
      end
      object chkFadeOld: TCheckBox
        Left = 96
        Top = 60
        Width = 97
        Height = 17
        Caption = 'Fade out'
        Checked = True
        State = cbChecked
        TabOrder = 4
      end
    end
  end
  object pmnuMain: TPopupMenu
    Images = imlActions
    Left = 312
    Top = 65520
    object mnuAbout: TMenuItem
      Action = About
    end
    object mnuShow: TMenuItem
      Action = ShowMainForm
      Default = True
    end
    object N7: TMenuItem
      Caption = '-'
    end
    object mnuShutDown: TMenuItem
      Action = Exit
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object mnuCommands: TMenuItem
      Caption = 'Commands'
      object mnuPause: TMenuItem
        Action = Pause
      end
      object mnuPlay: TMenuItem
        Action = Play
      end
      object mnuStop: TMenuItem
        Action = Stop
      end
      object mnuForward5: TMenuItem
        Action = Forward5
      end
      object mnuBack5: TMenuItem
        Action = Back5
      end
      object mnuStopFade: TMenuItem
        Action = StopFade
      end
      object mnuStopCurrent: TMenuItem
        Action = StopAfterCurrent
      end
    end
    object mnuPlaylist: TMenuItem
      Caption = 'Playlist'
      Hint = 'playlist functions'
      object Actions1: TMenuItem
        Caption = 'Actions'
        object mnuStart: TMenuItem
          Action = Start
        end
        object mnuEnd: TMenuItem
          Action = End
        end
        object mnuDelete: TMenuItem
          Action = Delete
        end
        object mnuAddFiles: TMenuItem
          Action = AddFiles
        end
        object mnuAddPlayList: TMenuItem
          Action = AddPlayIist
        end
        object mnuPlayfromStart: TMenuItem
          Action = PlayFromStart
        end
        object mnuAddDirectory: TMenuItem
          Action = AddDirectory
        end
      end
      object mnuShuffle: TMenuItem
        Action = Shuffle
      end
      object mnuRepeat: TMenuItem
        Action = Repeat
      end
    end
    object mnuVolume: TMenuItem
      Caption = 'Volume'
      Hint = 'volume functions'
      object mnuVolumeUp: TMenuItem
        Action = Up
      end
      object mnuVolumeDown: TMenuItem
        Action = Down
      end
      object mnuVolumeUpMore: TMenuItem
        Action = UpMore
      end
      object mnuVolumeDownMore: TMenuItem
        Action = DownMore
      end
      object mnuSetVolume0: TMenuItem
        Action = Zero
      end
      object N502: TMenuItem
        Action = Half
      end
      object mnuSetVolume100: TMenuItem
        Action = Full
      end
    end
    object NextwithFade2: TMenuItem
      Action = NextFade
    end
    object mnuNext: TMenuItem
      Action = Next
    end
    object mnuPrevious: TMenuItem
      Action = Previous
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object mnuViewCommands: TMenuItem
      Action = ViewToolBar
    end
    object mnuAdministerPlayList: TMenuItem
      Action = ViewPlaylist
    end
    object mnuShowSettings: TMenuItem
      Action = ViewVolume
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Playlist Files|*.m3u, *.pls'
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofPathMustExist, ofFileMustExist]
    Left = 400
    Top = 65520
  end
  object mnuMain: TMainMenu
    Images = imlActions
    Left = 360
    Top = 65520
    object mnuFile: TMenuItem
      Caption = 'A&pplication'
      Hint = 'File Menu'
      object mnuLanguage: TMenuItem
        Caption = 'Set Language'
        ImageIndex = 2
        object mnuEnglishUK: TMenuItem
          Action = SetLanguage
          Caption = 'English (UK)'
          ImageIndex = 28
        end
        object mnuEnglishUS: TMenuItem
          Action = SetLanguage
          Caption = 'English (US)'
          ImageIndex = 29
        end
        object mnuGerman: TMenuItem
          Action = SetLanguage
          Caption = 'German'
          ImageIndex = 30
        end
        object mnuFrench: TMenuItem
          Action = SetLanguage
          Caption = 'French'
          ImageIndex = 31
        end
        object mnuDutch: TMenuItem
          Action = SetLanguage
          Caption = 'Dutch'
          ImageIndex = 32
        end
      end
      object mnuPlaceOnTray: TMenuItem
        Action = PlaceOnTray
      end
      object LocateServers1: TMenuItem
        Action = LocateServers
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object mnuFileExit: TMenuItem
        Action = Exit
      end
    end
    object mnuActions: TMenuItem
      Caption = '&Actions'
      Hint = 'General Play Actions'
      object ViewToolbar1: TMenuItem
        Action = ViewToolBar
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object Pause1: TMenuItem
        Action = Pause
      end
      object Play1: TMenuItem
        Action = Play
      end
      object Stop1: TMenuItem
        Action = Stop
      end
      object MoreStops1: TMenuItem
        Caption = '&More Stops'
        Hint = 'more types of stop'
        object StopWithFade1: TMenuItem
          Action = StopFade
        end
        object StopafterCurrent1: TMenuItem
          Action = StopAfterCurrent
        end
      end
      object Forward51: TMenuItem
        Action = Forward5
      end
      object Back51: TMenuItem
        Action = Back5
      end
    end
    object Playlist1: TMenuItem
      Caption = '&Playlist'
      Hint = 'Playlist Functions'
      object Administer1: TMenuItem
        Action = ViewPlaylist
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object Next1: TMenuItem
        Action = Next
      end
      object mnuNextwithFade: TMenuItem
        Action = NextFade
      end
      object Previous1: TMenuItem
        Action = Previous
      end
      object mnuPreviouswithFade: TMenuItem
        Action = PreviousFade
      end
      object Actions2: TMenuItem
        Caption = '&Actions'
        object Start1: TMenuItem
          Action = Start
        end
        object End1: TMenuItem
          Action = End
        end
        object Delete1: TMenuItem
          Action = Delete
        end
        object PlayfromStart2: TMenuItem
          Action = PlayFromStart
        end
        object AddFiles2: TMenuItem
          Action = AddFiles
        end
        object AddPlayList1: TMenuItem
          Action = AddPlayIist
        end
        object AddDirectory1: TMenuItem
          Action = AddDirectory
        end
      end
      object Shuffletoggle1: TMenuItem
        Action = Shuffle
      end
      object Repeattoggle1: TMenuItem
        Action = Repeat
      end
    end
    object Volume1: TMenuItem
      Caption = '&Volume'
      Hint = 'Volume Functions'
      object ViewEditSettings1: TMenuItem
        Action = ViewVolume
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object Up1: TMenuItem
        Action = Up
      end
      object Down1: TMenuItem
        Action = Down
      end
      object mnuMore: TMenuItem
        Caption = 'More Up/Down'
        object UpMore1: TMenuItem
          Action = UpMore
        end
        object DownMore1: TMenuItem
          Action = DownMore
        end
      end
      object Volumezero1: TMenuItem
        Action = Zero
      end
      object N501: TMenuItem
        Action = Half
      end
      object Volumefull1: TMenuItem
        Action = Full
      end
    end
    object mnuHelp: TMenuItem
      Caption = '&Help'
      Hint = 'Help on this Application'
      object mnuDetails: TMenuItem
        Action = Details
      end
      object mnuHelpAbout: TMenuItem
        Action = About
      end
    end
  end
  object timerMain: TTimer
    Enabled = False
    Interval = 50
    OnTimer = MainTimer
    Left = 24
    Top = 65520
  end
  object alMain: TActionList
    Images = imlActions
    OnExecute = alMainExecute
    Left = 185
    Top = 65520
    object Configuration: TAction
      Category = 'File'
      Caption = '&Configuration'
      Hint = 'Configuration'
      ImageIndex = 7
    end
    object PlaceOnTray: TAction
      Category = 'File'
      Caption = 'Place On &Tray'
      Hint = 'Place on Tray'
      ImageIndex = 6
      ShortCut = 16456
      OnExecute = HideMain
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
      OnExecute = PlaylistStartExecute
    end
    object End: TAction
      Category = 'Playlist'
      Caption = '&End'
      Hint = 'End of Playlist'
      ImageIndex = 4
      OnExecute = PlaylistEndExecute
    end
    object Delete: TAction
      Category = 'Playlist'
      Caption = '&Delete'
      Hint = 'Delete Playlist'
      ImageIndex = 15
      OnExecute = DeletePlayListExecute
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
      OnExecute = AddFileToPlayListExecute
    end
    object AddPlayIist: TAction
      Category = 'Playlist'
      Caption = 'Add Pla&ylist'
      Hint = 'Add Playlist'
      ImageIndex = 17
      Visible = False
      OnExecute = AddFileToPlayListExecute
    end
    object AddDirectory: TAction
      Category = 'Playlist'
      Caption = 'Add Direc&tory'
      Hint = 'add Directory'
      ImageIndex = 18
      Visible = False
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
      OnExecute = VolumeUpExecute
    end
    object Down: TAction
      Category = 'Volume'
      Caption = '&Down'
      Hint = 'Voume Down'
      ImageIndex = 20
      OnExecute = VolumeDownExecute
    end
    object UpMore: TAction
      Category = 'Volume'
      Caption = 'Up &More'
      Hint = 'Volume Up (More)'
      ImageIndex = 21
      OnExecute = VolumeUpMoreExecute
    end
    object DownMore: TAction
      Category = 'Volume'
      Caption = 'Down M&ore'
      Hint = 'Volume Down (more)'
      ImageIndex = 22
      OnExecute = VolumeDownMoreExecute
    end
    object Zero: TAction
      Category = 'Volume'
      Caption = '&Zero'
      Hint = 'Volume off'
      ImageIndex = 23
      OnExecute = SetVolume0Execute
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
      OnExecute = SetVolume100Execute
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
    object RefreshEQ: TAction
      Category = 'Volume'
      Caption = 'RefreshEQ'
      Hint = 'Refresh EQ values'
      ImageIndex = 12
      OnExecute = RefreshEQExecute
    end
    object Autoload: TAction
      Category = 'Volume'
      Caption = 'Autoload'
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
    object SetLanguage: TAction
      Category = 'File'
      Caption = 'SetLanguage'
      ImageIndex = 2
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
  end
  object imlActions: TImageList
    Left = 272
    Top = 65520
    Bitmap = {
      494C010121002200040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000009000000001002000000000000090
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008400000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000084000000840000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008400000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000084000000840000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008400000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000084000000840000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF004221E7000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF004242E7000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF008400000084000000840000008400
      000084000000FFFFFF00F7FFFF00F7FFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF0000000000F7FFFF000000FF00FFFFFF008421
      00008400000084000000FFFFFF000000FF000000FF00FFFFFF00840000008400
      000084000000FFFFFF00F7FFFF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF008400000084000000840000008400
      000084000000FFFFFF00FFFFFF00F7FFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF000000000084000000FFFFFF000000FF000000
      FF00FFFFFF0084000000FFFFFF000000FF000000FF00FFFFFF0084000000FFFF
      FF00FFFFFF000000FF000000FF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF008400000084000000840000008400
      000084000000FFFFFF00FFFFFF00F7FFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF0000000000840000008400000084000000FFFF
      FF000000FF000000FF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF000000
      FF000000FF008400000084000000840000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF008400000084000000840000008400
      000084000000FFFFFF00F7FFFF00F7FFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF00000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF008400000084000000840000008400
      000084000000FFFFFF00F7FFFF00FFFFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF00000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF00FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF008400000084000000840000008400
      000084000000FFFFFF00F7FFFF00F7FFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF00000000008400000084000000840000000000
      FF000000FF00FFFFFF00FFFFFF000000FF000000FF00FFFFFF000000FF000000
      FF00FFFFFF00840000008400000084000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF008400000084000000840000008400
      000084000000FFFFFF00F7FFFF00FFFFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF0000000000840000000000FF000000FF00FFFF
      FF00FFFFFF0084000000FFFFFF000000FF000000FF00FFFFFF0084000000FFFF
      FF000000FF000000FF00FFFFFF0084000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008400000084000000840000008400
      000084000000FFFFFF00F7FFFF00F7FFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF00000000000000FF00F7FFFF00FFFFFF008400
      00008400000084000000FFFFFF000000FF000000FF00FFFFFF00840000008400
      000084210000FFFFFF000000FF00F7FFFF00FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008400000084000000840000008400
      000084000000FFFFFF00F7FFFF00F7FFFF00FFFFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008400000084000000840000008400
      000084000000FFFFFF00F7FFFF00FFFFFF00F7FFFF00FFFFFF000000FF000000
      FF000000FF000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD00000000000000000000000000949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      94001821310000000000000000006B6B6B00FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A0000000000000000000000FF000000
      FF000000FF000000FF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF00FFFFFF000000
      FF000000FF00FFFFFF000000FF000000000000FF000000FF000000FF00000000
      0000000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FF000000FF000000FF00000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF000000FF00FFFF
      FF00FFFFFF000000FF000000FF000000000000FF000000FF000000FF00000000
      0000000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FF000000FF000000FF00000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF000000FF00FFFF
      FF00FFFFFF000000FF000000FF000000000000FFFF0000FFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FFFF0000FFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF00FFFFFF000000
      FF000000FF00FFFFFF000000FF000000000000FFFF0000FFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF0000000000000000000000FF000000FF000000FF000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A0029292900000000000000000000000000000000000000000000006B000000
      6B00000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000FF000000FF000000FF000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A0000000000000000000000000000000000000000000000FF000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      31003131310063636300000000000000000000000000000000000000FF000000
      6B00000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C0031313100636363000000000000000000000000000000FF000000
      FF0000006B00000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A000000000000006B0000006B00000000000000
      FF000000FF000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000FF000000FF00000000000000
      6B000000FF0000006B0000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC60000000000000000000000FF0000006B000000
      FF000000FF00000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC6000000000000000000000000000000FF000000
      FF00000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD00000000000000000000000000949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000006B0000006B0000006B0000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000006B0000006B0000006B0000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      00006B6B6B000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000006B6B6B0000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000006B0000006B0000006B0000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A0029292900000000000000000000000000000000006B000000000000000000
      0000000000006B6B6B0000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A00000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A00000000000000000000000000000000006B000000000000000000
      000000000000000000006B6B6B00000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000006B6B
      6B0000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C0031313100636363000000000000000000000000006B6B6B000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000000000
      00006B6B6B00000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      000000000000000000006B6B6B00000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      0000000000006B6B6B000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      0000000000006B6B6B000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      00006B6B6B0000000000FFFFFF00000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD00000000000000000000000000949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006BFFFF006BFFFF0000FF
      FF0000FFFF006BFFFF0000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006BFFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000006BFFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000000000000000000000000000000000000000009494
      9400182131000000000000000000000000006B0000006B0000006B0000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000FFFF0000FFFF000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A0029292900000000000000000000000000000000006B000000000000000000
      0000000000006B6B6B0000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000FF000000FF000000FF
      000000FF00000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A0000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000006B00
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C0031313100636363000000000000000000000000006B0000000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C0031313100636363000000000000000000000000006B0000000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000006B6B
      6B0000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C0031313100636363000000000000000000000000006B0000006B00
      00006B0000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A0000000000000000006B0000006B0000006B00
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A0000000000000000006B0000006B0000006B00
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000006B00
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A00000000000000000000000000000000006B0000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A00000000000000000000000000000000006B0000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      0000000000006B6B6B000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD00000000000000000000000000949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000840000008400
      0000840000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000000000000000000000000000009494
      940018213100000000000000000000000000000000000000000000FF000000FF
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000840000008400
      0000840000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000840000008400
      0000840000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A0000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A0000000000000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A0000000000000000000000000000FF000000000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000008400000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      000000000000840000000000000063636300313131003952840039A5F700299C
      EF0018529C0031313100636363000000000000FF000000FF000000FF000000FF
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C0031313100636363000000000000FF000000FF000000FF000000FF
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C00313131006363630000000000000000000000000000FF00000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000840000000000
      0000840000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000840000008400
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A00000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A00000000000000000000FF000000FF000000FF000000FF
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000840000008400
      000084000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400848484008484840084848400848484008484840084848400848484008484
      840084848400000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00848484000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400FFFFFF00000000000000000000000000000000000000000000000000FFFF
      FF00848484000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF008484840000000000000000000000000000FF000000FF000000FF000000FF
      0000840000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400FFFFFF0000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF006B6B6B000000000000000000000000000000000000000000000000000000
      0000000000008400000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400848484008484840084848400848484008484840084848400848484008484
      8400848484000000000000000000000000000000000000000000000000008484
      8400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF008484840000000000000000000000000000FF000000FF000000FF000000FF
      0000000000008400000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400FFFFFF000000FF000000FF000000FF000000FF000000FF00FFFFFF00FFFF
      FF00848484000000000000000000000000000000000000000000000000000000
      0000000000008400000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000008484
      8400848484008484840084848400848484008484840084848400848484008484
      8400848484000000000000000000000000000000000000000000000000008484
      8400BDBDBD006B6B6B006B6B6B006B6B6B006B6B6B006B6B6B006B6B6B00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF008484840000000000000000000000000000FF000000FF000000FF000000FF
      0000840000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000008484
      8400BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400BDBDBD00BDBDBD00BDBDBD006B6B6B00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400FFFFFF00000000000000000000000000000000000000000000000000FFFF
      FF00848484000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000008484
      8400BDBDBD006B6B6B00BDBDBD006B6B6B00BDBDBD006B6B6B00BDBDBD00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF008484840000000000000000000000000000FF000000FF000000FF000000FF
      000084000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000008484
      8400BDBDBD00296BFF00BDBDBD00296BFF00BDBDBD00296BFF00BDBDBD00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400BDBDBD006B6B6B006B6B6B006B6B6B006B6B6B006B6B6B006B6B6B00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400FFFFFF000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00848484000000000000000000000000000000000000000000000000000000
      0000000000008400000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000008484
      8400BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400BDBDBD00BDBDBD00BDBDBD006B6B6B00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00848484000000000000000000000000000000000000000000000000008484
      8400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF008484840000000000000000000000000000FF000000FF000000FF000000FF
      0000840000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000003184
      FF006B0000006B0000006B0000006B0000006B0000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000003184
      FF006B0000006B0000006B0000006B0000006B0000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000003184
      FF006B0000006B0000006B0000006B0000006B0000006B000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000084848400848484008484
      8400848484008484840084848400848484008484840084848400848484008484
      8400848484008484840084848400848484000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A000000000084848400848484008484
      8400848484008484840084848400848484008484840084848400848484008484
      840084848400296BFF003184FF006B6B6B000000000000000000000000000000
      0000000000008484840000000000000000000000000000000000000000000000
      0000C6C6C600848484000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00C6C6C6008484840000000000000000000000000000000000C6C6
      C60084848400C6C6C60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000848484008484840084848400000000000000000000000000000000000000
      000000000000FFFFFF00C6C6C600848484000000000000000000C6C6C6008484
      8400C6C6C6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00C6C6C60084848400C6C6C60084848400C6C6
      C600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000848484008484840084848400848484008484
      8400848484008484840000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00C6C6C60084848400C6C6C6000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C6C6C60084848400C6C6C600000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000848484008484840084848400848484008484840084848400848484008484
      8400848484000000000000000000000000000000000000000000000000000000
      00000000000000000000C6C6C60084848400C6C6C60000000000C6C6C6008484
      8400000000000000000000000000000000000000000000000000000000000000
      000000004A000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000848484000000
      000000000000C6C6C60084848400C6C6C6000000000000000000FFFFFF00C6C6
      C6008484840084848400000000000000000000004A0000000000000000000000
      00000000FF000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000084848400848484008484
      8400848484008484840084848400848484008484840084848400848484000000
      00000000000000000000000000000000000000000000C6C6C600848484008484
      84000000000084848400C6C6C60000000000000000000000000000000000C6C6
      C600848484008484840084848400000000000000FF0000004A00000000000000
      00000000FF000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000000084848400C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600848484000000
      0000000000000000000000000000000000000000000000000000848484008484
      840084848400000000000000000000000000000000000000000000000000C6C6
      C600848484000000000000000000848484000000FF000000FF0000004A000000
      00000000FF00000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000000000000000000000000
      000000000000000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000000084848400C6C6C6003184
      FF00C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600848484000000
      0000000000000000000000000000000000000000000000000000C6C6C6008484
      840084848400848484000000000000000000000000000000000000000000FFFF
      FF00C6C6C6008484840000000000000000000000FF000000FF000000FF000000
      00000000FF000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000000000000000000000000
      0000000000000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000000084848400C6C6C600C6C6
      C600848484008484840084848400C6C6C600C6C6C600C6C6C600848484000000
      000000000000000000000000000000000000000000000000000000000000C6C6
      C600848484008484840084848400000000000000000000000000000000000000
      0000FFFFFF00C6C6C60084848400000000000000FF000000FF00000000000000
      00000000FF000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000000084848400C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600848484000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C6C6C60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      00000000FF00000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC60000000000000000003184FF006B0000006B00
      00006B0000006B0000006B0000006B0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD000000000000000000000000000000000018213100ADADAD000000
      0000000000000000000018213100ADADAD000000000000000000000000001821
      3100ADADAD00000000000000000000000000949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00949494005A5A5A005A5A5A005252
      52005A5A5A00949494005A5A5A005A5A5A00525252005A5A5A00949494005A5A
      5A00182131005A5A5A005A5A5A005A5A5A00FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      940018213100000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400182131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      94001821310000000000000000000000000000004A0000000000000000000000
      00000000000000004A0000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000004A00000000000000
      000000004A000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000315A9C0000000000000000005A5A5A004A4A
      4A00292929000000000000000000000000000000FF0000000000000000000000
      000000004A000000FF0000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000000000004A00000000000000
      0000000000000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A00000000000000000000000000000000000000FF00000000000000
      00000000FF000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A0000000000000000000000000000004A0000004A0000004A000000
      4A0000004A000000000000000000000000001852AD00314A6300292929002929
      29005A5A5A000000000000000000000000000000FF0000000000000000000000
      4A000000FF000000FF0000000000000000005A638400218CD6001863B5002929
      310031313100636363000000000000000000000000000000FF0000004A000000
      4A00000000000000000000000000000000005A638400218CD6001863B5002929
      310031313100636363000000000000000000000000000000FF00000000000000
      00000000FF000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000FF000000FF000000FF000000
      FF000000FF000000000000000000000000005A638400218CD6001863B5002929
      3100313131006363630000000000000000000000FF000000000000004A000000
      FF000000FF000000FF000000000063636300313131003952840039A5F700299C
      EF0018529C00313131006363630000000000000000000000FF000000FF000000
      FF0000004A0000004A000000000063636300313131003952840039A5F700299C
      EF0018529C00313131006363630000000000000000000000FF00000000000000
      00000000FF00000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000FF000000FF000000FF000000
      FF000000FF00000000000000000063636300313131003952840039A5F700299C
      EF0018529C003131310063636300000000000000FF0000000000000000000000
      FF000000FF000000FF0000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A0000000000000000000000FF000000FF000000
      FF000000FF000000FF0000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A0000000000000000000000FF00000000000000
      00000000FF000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000FF000000FF000000FF000000
      FF000000FF000000000000000000525252003152840042B5FF004ABDFF0042B5
      FF00399CE700394A52004A4A4A00000000000000FF0000000000000000000000
      00000000FF000000FF0000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A000000000000000000000000000000FF000000FF000000
      FF000000FF000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A000000000000000000000000000000FF00000000000000
      00000000FF000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000FF000000FF000000FF000000
      FF000000FF000000000000000000000000008C8C8C006384940052B5E7004ABD
      FF0039A5EF0052525A0000000000000000000000FF0000000000000000000000
      0000000000000000FF000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC60000000000000000000000FF000000FF000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC60000000000000000000000FF00000000000000
      00000000FF00000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000FF000000FF000000FF000000
      FF000000FF00000000000000000000000000000000009C9C9C009C9C9C008484
      8400529CBD0031A5EF009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494008C8C
      8C0000000000000000009CADC60000000000424D3E000000000000003E000000
      2800000040000000900000000100010000000000800400000000000000000000
      000000000000000000000000FFFFFF00FFFF000000000000FFFF000000000000
      FFFF000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FFFF000000000000
      FFFF000000000000FFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFF0000000100000000000000010000000000000001
      0000000000000001000000000000000100000000000000010000000000000001
      00000000000000010000000000000001FFFF000000000001FFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9CE79CE79CE79CE70000000000000000
      18E718E718E618C3FFE7FFE7FFE7FF811FE71FE7FFE7FF811FE71FE7FFE7FF81
      1FE71FE7FFE7FF8117E7FFE7FFE7FFC31AC7FAC7CEC7FEC71D07FD07DF07FF07
      FF03FF03CF03FF03C201F201C601FE01FE01FE012601FE01FD03FD032303FF03
      FB81FB818781FF81F7CDFFCDCFCDFFCD9CE79CE79CE79CE70000000000000000
      18E718E718E718E7FFE7FFE7FFE7FFE7FFE7BFE7BFE71FE7BFE7BFE71FE7FFE7
      1FE7BFE7BFE7FFE7BFE7B7E7BFE7FFE7BAC71AC7BAC7FEC7FD07BD07BD07FF07
      FF03FF03FF03FF03E201C201F201FE01FE01FE01FE01FE01FD03FD03FD03FF03
      FB81FB81FB81FF81FFCDF5CDFFCDFFCD9CE79CE79CE79CE70000000000000000
      18E718E718E718E7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE70FE783E7BFE7
      FFE7FFE783E7BFE7FFE70FE783E71FE7FEC7FEC79EC7BAC787070F07FF07FD07
      FF03FF03FF03FF03EE01DE01DE01E201C6018E018E01FE01EF03DF03DF03FD03
      FF81FF81FF81FB81FFCDFFCDFFCDFFCD9CE79CE79CE79CE70000000000000000
      18E718E718E718E7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE70FE70FE70FE7
      FFE7FFE7FFE77BE7C7E70FE70FE707E7C6C7FEC7FEC7B6C7C7070F070F070F07
      FB03FF03FF03CF03FA010E010E010201D601FE01FE017E01CF030F030F030F03
      C781FF81FF81FF81FFCDFFCDFFCDFFCDFFFFFFFFFFFF9CE7FFFFFFFFFFFF0000
      FFFFFFFFE00718E7FFFFFFFFE007FFE7FFFFFFFFE007FFE7FFFFFFFFE00707E7
      FFFFFFFFE007FBE7FFFFE007E0070BE7FFFFE007E007FAC7E007E007E0070707
      E007E007E007FF03E007E007E0070601E007E007E007FA01E007E007E0070703
      E007E007E007FF81FFFFFFFFFFFFFFCD9CE79CE78000FFFF000000008000F9F3
      18E718E7FFFFF0E1FFE7FFE7FFF1F843FFE7FFE7FFFFFC07FFE7FFE7FE03FE0F
      FFE7FFE7FFFFFE0FFFE7FFE7F007FC07F6C7FEC7FFFFD8417707FF07801F80E0
      3703FF03801FC1E61601FE01801FC3E31601FE01801FE1F13703FF03801FFBFF
      7781FF81801FFFFFFFCDFFCDFFFFFFFF9CE79CE79CE79CE70000000000000000
      18E718E718E718E7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7
      FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE77AC7FEC7B6C7FEC77307BF07B7070707
      63038F03B703070342018201B601060162018201B601060173038703B7030703
      7B819F81B7810781FFCDFFCDFFCDFFCD00000000000000000000000000000000
      000000000000}
  end
  object imlCommandsHot: TImageList
    Height = 32
    Width = 32
    Left = 72
    Top = 65521
    Bitmap = {
      494C010107000900040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      00000000000036000000280000008000000060000000010020000000000000C0
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF0000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00426B73007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000FFFFFF000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B0000000000BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00426B73007B7B7B00FFFFFF00BDBDBD00BDBDBD007B7B7B0000000000BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007B7B7B00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00426B73007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007B7B
      7B007B7B7B007B7B7B00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007B7B7B00BDBDBD00BDBDBD00BDBD
      BD00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B0000000000BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00426B73007B7B7B00FFFFFF00BDBDBD00BDBDBD007B7B7B0000000000BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007B7B7B00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007B7B
      7B007B7B7B007B7B7B007B7B7B007B7B7B00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD007B7B7B0000000000BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007B7B7B007B7B7B007B7B7B007B7B7B007B7B
      7B00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B0000000000BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B00FFFFFF00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007B7B
      7B007B7B7B007B7B7B007B7B7B007B7B7B00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      290029292900292929002929290029292900BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      630063636300636363006363630063636300FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      940094949400FFFFFF0094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      940094949400FFFFFF0094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      940094949400FFFFFF0094949400636363006363630094949400949494009494
      940094949400949494009494940094949400FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00949494006363
      630063636300636363000000000000000000000000000000000000000000FFFF
      FF00949494006363630063636300636363000000000000000000000000000000
      00000000000000000000FFFFFF00949494006363630029292900000000000000
      00000000000000000000000000000000000000000000FFFFFF00949494006363
      630063636300636363000000000000000000000000000000000000000000FFFF
      FF00949494006363630063636300636363000000000000000000000000000000
      00000000000000000000FFFFFF00949494006363630029292900000000000000
      00000000000000000000000000000000000000000000FFFFFF00949494006363
      630063636300636363000000000000000000000000000000000000000000FFFF
      FF00949494006363630063636300636363000000000000000000000000000000
      00000000000000000000FFFFFF00949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000FFFFFF009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000FFFFFF009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000FFFFFF009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000FFFFFF009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      00000000000000000000000000000000000000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00426B73007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007B7B7B0000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009494CE00000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000630000006300000063000000000000000000000000000000
      000000000000000000009494CE00000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009494CE00000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000006300000063000000
      0000000000000000000063949400296394009494CE0000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000630000006300000063000000000000000000000000000000
      0000000000000000000063949400296394009494CE0000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      6300000063000000630000006300000063000000630000006300000063000000
      6300000063000000000063949400296394009494CE0000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000006300000000000000
      0000000000000000000000000000000000000000000000006300000063000000
      0000000000000000000000000000639494002963940063949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF00000063000000000000000000000000000000
      0000000000000000000000000000639494002963940063949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000063000000630000006300000063000000630000006300000063000000
      6300000000000000000000000000639494002963940063949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF000000FF0000006300000063000000
      0000000000000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000006394940029639400296394002963
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000006394940029639400296394002963
      6300292929002929290029292900292929002929290063636300000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00000000000000000000000000000000006394940029639400296394002963
      6300292929002929290029292900292929002929290063636300000000000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00426B73007B7B7B00FFFFFF00BDBDBD00BDBDBD007B7B7B0000000000BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF000000FF000000FF00000063000000
      6300000000000000000000000000000000000000FF000000FF00000063000000
      00000000000000000000000000000000000000000000296394002963CE002963
      9400296394002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000630000006300000000000000000000000000000000000000
      00000000000000000000000000000000000000000000296394002963CE002963
      9400296394002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      00000000000000000000000000000000000000000000296394002963CE002963
      9400296394002929290029292900292929002929290029292900636363000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000FF000000FF000000FF000000
      6300000063000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000063639400296394002994
      CE002994CE002963CE0029636300292929002929290029292900292929006363
      6300000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF00000063000000000000000000000000000000
      0000000000000000000000000000000000000000000063639400296394002994
      CE002994CE002963CE0029636300292929002929290029292900292929006363
      6300000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      0000000000000000000000000000000000000000000063639400296394002994
      CE002994CE002963CE0029636300292929002929290029292900292929006363
      630000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF000000FF000000FF000000
      FF00000063000000630000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000006363630029292900296363002994
      CE002994FF002994FF002994CE002963CE002963630029292900292929002929
      2900636363000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF00000063000000630000000000000000000000
      0000000000000000000000000000000000006363630029292900296363002994
      CE002994FF002994FF002994CE002963CE002963630029292900292929002929
      2900636363000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000006363630029292900296363002994
      CE002994FF002994FF002994CE002963CE002963630029292900292929002929
      290063636300000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF000000FF000000FF000000
      FF000000FF000000630000006300000000000000FF000000FF00000063000000
      0000000000000000000000000000636363002929290029292900636363006363
      94006394FF006394FF006394FF002994FF002994CE0029639400292963002929
      2900292929006363630000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000630000006300000000000000
      0000000000000000000000000000636363002929290029292900636363006363
      94006394FF006394FF006394FF002994FF002994CE0029639400292963002929
      2900292929006363630000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000636363002929290029292900636363006363
      94006394FF006394FF006394FF002994FF002994CE0029639400292963002929
      290029292900636363000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF000000FF000000FF000000
      FF000000FF000000FF0000006300000000000000FF000000FF00000063000000
      0000000000000000000063636300292929002929290063636300636363002963
      94006394FF0063CEFF0063CEFF006394FF006394FF002994FF002994CE002963
      9400292929002929290094949400000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000FF0000006300000000000000
      0000000000000000000063636300292929002929290063636300636363002963
      94006394FF0063CEFF0063CEFF006394FF006394FF002994FF002994CE002963
      9400292929002929290094949400000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000630000006300000000000000
      0000000000000000000063636300292929002929290063636300636363002963
      94006394FF0063CEFF0063CEFF006394FF006394FF002994FF002994CE002963
      940029292900292929009494940000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000FF000000FF000000FF000000
      FF000000FF000000FF0000000000000000000000FF000000FF00000063000000
      00000000000000000000000000006363630063636300296394002994CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      6300292929006363630000000000000000000000000000000000000063000000
      630000009400000000000000FF000000FF000000FF000000FF00000063000000
      00000000000000000000000000006363630063636300296394002994CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      6300292929006363630000000000000000000000000000000000000000000000
      000000000000000063000000FF000000FF000000630000006300000063000000
      00000000000000000000000000006363630063636300296394002994CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      630029292900636363000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF000000FF000000FF000000
      FF000000FF000000000000000000000000000000FF000000FF00000063000000
      00000000000000000000000000000000000063636300636394006394CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF0029639400636363006363
      6300636363000000000000000000000000000000000000000000000063000000
      63000000940000000000000000000000FF000000FF000000FF00000063000000
      63000000000000000000000000000000000063636300636394006394CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF0029639400636363006363
      6300636363000000000000000000000000000000000000000000000000000000
      0000000063000000FF000000FF000000FF000000FF0000006300000063000000
      63000000000000000000000000000000000063636300636394006394CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF0029639400636363006363
      630063636300000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF000000FF000000FF000000
      FF00000000000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000094949400636363006394
      94006394CE0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      630000000000000000000000000000000000000000000000FF000000FF000000
      FF00000063000000940000000000000063000000FF000000FF000000FF000000
      6300000000000000000000000000000000000000000094949400636363006394
      94006394CE0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      6300000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      6300000000000000000000000000000000000000000094949400636363006394
      94006394CE0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      630000000000000000000000000000000000FFFFFF0000000000FFFFFF00FFFF
      FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF000000FF000000FF000000FF000000
      0000000000000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000000000000949494009494
      94009494940094949400949494006394CE0063CEFF0063CEFF006394FF006394
      CE0094CECE00000000000000000000000000000000000000FF000000FF000000
      FF00000063000000630000006300000063000000FF000000FF000000FF000000
      0000000000000000000000000000000000000000000000000000949494009494
      94009494940094949400949494006394CE0063CEFF0063CEFF006394FF006394
      CE0094CECE000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      6300000063000000000000000000000000000000000000000000949494009494
      94009494940094949400949494006394CE0063CEFF0063CEFF006394FF006394
      CE0094CECE00000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000FF000000FF00000000000000
      0000000000000000000000000000000000000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940094949400949494009494940094949400639494006394CE0063CEFF002994
      FF002994CE009494CE00000000000000000000000000000000000000FF000000
      FF000000FF0000006300000063000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940094949400949494009494940094949400639494006394CE0063CEFF002994
      FF002994CE009494CE0000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      0000000000000000000000000000000000000000000000000000000000009494
      940094949400949494009494940094949400639494006394CE0063CEFF002994
      FF002994CE009494CE000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF0000000000000000000000
      0000000000000000000000000000000000000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00009494940094949400949494006363630094949400000000000000000094CE
      CE006394FF002994CE009494CE000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00009494940094949400949494006363630094949400000000000000000094CE
      CE006394FF002994CE009494CE000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00000000000000000000000000000000000000000000000000000000000000
      00009494940094949400949494006363630094949400000000000000000094CE
      CE006394FF002994CE009494CE0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      0000000000009494CE006394CE00000000000000000000000000000000000000
      00000000FF000000FF000000FF000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      0000000000009494CE006394CE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      0000000000009494CE006394CE0000000000FFFFFF00FFFFFF00DEDEDE00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      940094949400FFFFFF0094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      940094949400FFFFFF0094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      940094949400FFFFFF0094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      940094949400FFFFFF0094949400636363006363630094949400949494009494
      94009494940094949400949494009494940000000000FFFFFF00949494006363
      630063636300636363000000000000000000000000000000000000000000FFFF
      FF00949494006363630063636300636363000000000000000000000000000000
      00000000000000000000FFFFFF00949494006363630029292900000000000000
      00000000000000000000000000000000000000000000FFFFFF00949494006363
      630063636300636363000000000000000000000000000000000000000000FFFF
      FF00949494006363630063636300636363000000000000000000000000000000
      00000000000000000000FFFFFF00949494006363630029292900000000000000
      00000000000000000000000000000000000000000000FFFFFF00949494006363
      630063636300636363000000000000000000000000000000000000000000FFFF
      FF00949494006363630063636300636363000000000000000000000000000000
      00000000000000000000FFFFFF00949494006363630029292900000000000000
      00000000000000000000000000000000000000000000FFFFFF00949494006363
      630063636300636363000000000000000000000000000000000000000000FFFF
      FF00949494006363630063636300636363000000000000000000000000000000
      00000000000000000000FFFFFF00949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000FFFFFF009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000FFFFFF009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000FFFFFF009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000FFFFFF009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009494CE00000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009494CE00000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009494CE00000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009494CE00000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000006300000063000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000094000000000063949400296394009494CE0000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000063949400296394009494CE0000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      6300000063000000000000000000000000000000000000006300000063000000
      0000000000000000000063949400296394009494CE0000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000063949400296394009494CE0000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000006300000063000000
      0000000000000000000000000000000000000000000000000000000000000000
      6300000094000000000000000000639494002963940063949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000639494002963940063949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      6300000063000000000000000000000000000000000000006300000063000000
      0000000000000000000000000000639494002963940063949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000006300000063000000
      6300000063000000630000006300000063000000630000006300000063000000
      0000000000000000000000000000639494002963940063949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000000000000000094000000
      FF00000094000000000000000000000000006394940029639400296394002963
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      9400000094000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000006394940029639400296394002963
      6300292929002929290029292900292929002929290063636300000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000006394940029639400296394002963
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000000000006300000063000000
      6300000063000000630000006300000063000000630000006300000063000000
      0000000000000000000000000000000000006394940029639400296394002963
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000FF000000FF00000063000000
      00000000000000000000000000000000000000000000000094000000FF000000
      FF000000940000000000000000000000000000000000296394002963CE002963
      9400296394002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000000000000000000000000000
      6300000063000000940000009400000000000000000000000000000000000000
      00000000000000000000000000000000000000000000296394002963CE002963
      9400296394002929290029292900292929002929290029292900636363000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      00000000000000000000000000000000000000000000296394002963CE002963
      9400296394002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      00000000000000000000000000000000000000000000296394002963CE002963
      9400296394002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000FF000000FF00000063000000
      000000000000000000000000000000000000000094000000FF000000FF000000
      FF00000094000000000000000000000000000000000063639400296394002994
      CE002994CE002963CE0029636300292929002929290029292900292929006363
      63000000000000000000000000000000000000000000000000000000FF000000
      FF00000063000000630000006300000063000000940000000000000000000000
      0000000000000000000000000000000000000000000063639400296394002994
      CE002994CE002963CE0029636300292929002929290029292900292929006363
      63000000000000000000000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000063639400296394002994
      CE002994CE002963CE0029636300292929002929290029292900292929006363
      6300000000000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000063639400296394002994
      CE002994CE002963CE0029636300292929002929290029292900292929006363
      6300000000000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000094000000FF000000FF000000FF000000
      FF00000094000000000000000000000000006363630029292900296363002994
      CE002994FF002994FF002994CE002963CE002963630029292900292929002929
      29006363630000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF0000006300000063000000630000006300000094000000
      0000000000000000000000000000000000006363630029292900296363002994
      CE002994FF002994FF002994CE002963CE002963630029292900292929002929
      29006363630000000000000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000006363630029292900296363002994
      CE002994FF002994FF002994CE002963CE002963630029292900292929002929
      2900636363000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      0000000000000000000000000000000000006363630029292900296363002994
      CE002994FF002994FF002994CE002963CE002963630029292900292929002929
      2900636363000000000000000000000000000000FF000000FF00000063000000
      00000000000000000000000094000000FF000000FF000000FF000000FF000000
      FF00000094000000000000000000636363002929290029292900636363006363
      94006394FF006394FF006394FF002994FF002994CE0029639400292963002929
      29002929290063636300000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000630000006300000063000000
      6300000094000000000000000000636363002929290029292900636363006363
      94006394FF006394FF006394FF002994FF002994CE0029639400292963002929
      29002929290063636300000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000636363002929290029292900636363006363
      94006394FF006394FF006394FF002994FF002994CE0029639400292963002929
      2900292929006363630000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      0000000000000000000000000000636363002929290029292900636363006363
      94006394FF006394FF006394FF002994FF002994CE0029639400292963002929
      2900292929006363630000000000000000000000FF000000FF00000063000000
      000000000000000000000000FF000000FF000000FF000000FF000000FF000000
      FF00000094000000000063636300292929002929290063636300636363002963
      94006394FF0063CEFF0063CEFF006394FF006394FF002994FF002994CE002963
      94002929290029292900949494000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      6300000063000000000063636300292929002929290063636300636363002963
      94006394FF0063CEFF0063CEFF006394FF006394FF002994FF002994CE002963
      94002929290029292900949494000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000063636300292929002929290063636300636363002963
      94006394FF0063CEFF0063CEFF006394FF006394FF002994FF002994CE002963
      9400292929002929290094949400000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      0000000000000000000063636300292929002929290063636300636363002963
      94006394FF0063CEFF0063CEFF006394FF006394FF002994FF002994CE002963
      9400292929002929290094949400000000000000FF000000FF00000063000000
      000000000000000000000000FF000000FF000000FF000000FF000000FF000000
      FF000000940000000000000000006363630063636300296394002994CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      63002929290063636300000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000000000000000000000006363630063636300296394002994CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      63002929290063636300000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      00000000000000000000000000006363630063636300296394002994CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      6300292929006363630000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      00000000000000000000000000006363630063636300296394002994CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      6300292929006363630000000000000000000000FF000000FF00000063000000
      00000000000000000000000000000000FF000000FF000000FF000000FF000000
      FF000000940000000000000000000000000063636300636394006394CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF0029639400636363006363
      63006363630000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000000000000000000000000000000063636300636394006394CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF0029639400636363006363
      63006363630000000000000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      00000000000000000000000000000000000063636300636394006394CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF0029639400636363006363
      6300636363000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      00000000000000000000000000000000000063636300636394006394CE0063CE
      FF0063CEFF0063CEFF0063CEFF0063CEFF0063CEFF0029639400636363006363
      6300636363000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000000000FF000000FF000000FF000000
      FF00000094000000000000000000000000000000000094949400636363006394
      94006394CE0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      63000000000000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000094949400636363006394
      94006394CE0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      63000000000000000000000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000094949400636363006394
      94006394CE0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      6300000000000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000094949400636363006394
      94006394CE0063CEFF0063CEFF0063CEFF0063CEFF006394FF00296394006363
      6300000000000000000000000000000000000000FF000000FF00000063000000
      000000000000000000000000000000000000000000000000FF000000FF000000
      FF00000094000000000000000000000000000000000000000000949494009494
      94009494940094949400949494006394CE0063CEFF0063CEFF006394FF006394
      CE0094CECE0000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494009494
      94009494940094949400949494006394CE0063CEFF0063CEFF006394FF006394
      CE0094CECE0000000000000000000000000000000000000000000000FF000000
      FF00000063000000000000000000000000000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000000000000949494009494
      94009494940094949400949494006394CE0063CEFF0063CEFF006394FF006394
      CE0094CECE000000000000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000063000000
      0000000000000000000000000000000000000000000000000000949494009494
      94009494940094949400949494006394CE0063CEFF0063CEFF006394FF006394
      CE0094CECE000000000000000000000000000000FF000000FF00000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF00000000000000000000000000000000000000000000000000000000009494
      940094949400949494009494940094949400639494006394CE0063CEFF002994
      FF002994CE009494CE00000000000000000000000000000000000000FF000000
      FF000000FF000000FF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940094949400949494009494940094949400639494006394CE0063CEFF002994
      FF002994CE009494CE00000000000000000000000000000000000000FF000000
      FF00000000000000000000000000000000000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940094949400949494009494940094949400639494006394CE0063CEFF002994
      FF002994CE009494CE0000000000000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      940094949400949494009494940094949400639494006394CE0063CEFF002994
      FF002994CE009494CE0000000000000000000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF00000000000000000000000000000000000000000000000000000000000000
      00009494940094949400949494006363630094949400000000000000000094CE
      CE006394FF002994CE009494CE000000000000000000000000000000FF000000
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00009494940094949400949494006363630094949400000000000000000094CE
      CE006394FF002994CE009494CE000000000000000000000000000000FF000000
      FF00000000000000000000000000000000000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00009494940094949400949494006363630094949400000000000000000094CE
      CE006394FF002994CE009494CE00000000000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00009494940094949400949494006363630094949400000000000000000094CE
      CE006394FF002994CE009494CE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      0000000000009494CE006394CE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      0000000000009494CE006394CE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      0000000000009494CE006394CE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      0000000000009494CE006394CE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000080000000600000000100010000000000000600000000000000000000
      000000000000000000000000FFFFFF008C31A5148C318C318C318C318C318C31
      A5148C318C318C318C31524A8C318C318C318C318C31524A8C318C318C318C31
      8C31524A8C318C318C318C31A5148C318C31524A524A524A524A524A524A524A
      524A524A524A524A524AFF7F524A8C31524A524A524A524A8C318C318C318C31
      524A524A8C318C318C318C31524A524A8C31524A524A524A524A524A524A524A
      524A524A524A524A524AFF7F524A8C31524A524A524A524A8C318C318C318C31
      524A524A8C318C318C318C31524A524A8C31524A524A524A524A524A524A524A
      524A524A524A524A524AFF7F524A8C31524A524A524A524A8C318C318C318C31
      524A524A8C318C318C318C31524A524A8C31524A524A524A524A524A524A524A
      524A524A524A524A524AFF7F524A8C31524A524A524A524A8C318C318C318C31
      524A524A8C318C318C318C31524A524A8C31A514000000000000000000000000
      000000000000000000000000FF7F524A000000000000FF7F524A8C318C318C31
      0000FF7F524A8C318C318C31000000008C31A514000000000000000000000000
      000000000000000000000000FF7F524A000000000000FF7F524A8C318C318C31
      0000FF7F524A8C318C318C31000000008C31A514000000000000000000000000
      000000000000000000000000FF7F524A000000000000FF7F524A8C318C318C31
      0000FF7F524A8C318C318C3100000000C7F1FC7FC7F1FC7FC7F1FC7F00000000
      000000000000000000000000FF7F524A0000000000000000000000008C318C31
      0000000000000000000000000000000083E0FC3F83E0FC3F83E0FC3F00000000
      C7F1FE3FC7F1FE3FC7F1FE3F0000524AFFFFFE3FFFFFFE3FFFFFFE3F8C310000
      FFFFFE3FFFFFFE3FFFFFFE3F00000000FFFFFE3FFFFFFE3FFFFFFE3F00000000
      FFFFFE3FFFFFFE3FFFFFFE3F0000524AFFFFFE3FFFFFFE3FFFFFFE3F8C310000
      FFFFFE3FFFFFFE3FFFFFFE3F00000000FFFFFE3FFFFFFE3FFFFFFE3F00000000
      FFFFFE3FFFFFFE3FFFFFFE3F0000524AFFFFFE3FFFFFFE3FFFFFFE3F8C310000
      FFFDFC3FF8FDFC3FFFFDFC3F00000000FF9C783FF8FC783FE004783F00000000
      BF9E303FF0FE303FF00E303F0000524A1F1F003FF1FF003FC00F003F8C310000
      0F1F801FF9FF801FE01F801F00000000071F800FF0FF800FE01F800F00000000
      031F0007F07F0007F03F00070000524A011E0003F83E0003F87E000300000000
      011C0001F83C0001FC3C000100000000031E0003C41E0003F81E000300000000
      071F0007C60F0007F00F00070000524A0F1F800F820F800FF00F800F00000000
      1F1FC007801FC007E007C007000000003F3FE003C03FE003E01FE00300000000
      7F3FF061C03FF061C00FF0610000524AFFFFF8F9F0FFF8F9FFFFF8F900000000
      FFFFFDFFFFFFFDFFFFFFFDFF00000000C7F1FC7FC7F1FC7FC7F1FC7FC7F1FC7F
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000083E0FC3F83E0FC3F83E0FC3F83E0FC3F
      C7F1FE3FC7F1FE3FC7F1FE3FC7F1FE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFDFC3FFFFDFC3FFFFDFC3FFFFDFC3F9FF4783FFFFC783FE79C783FFFFC783F
      9FE6303FFFFE303FE79E303F801E303F1FC7003FE7FF003FC71F003F801F003F
      1F87801FE1FF801FC71F801F001F801F1F07800FC07F800FC71F800F001F800F
      1E070007C01F0007C71F0007001F00071C060003C0060003C71E0003001E0003
      1C040001C0040001C71C0001001C00011C060003C00E0003C71E0003001E0003
      1E070007C00F0007C71F0007001F00071F07800FC03F800FC71F800F001F800F
      1F87C007C0FFC007C71FC007001FC0073FCFE003C3FFE003CF3FE003003FE003
      3FEFF061CFFFF061CF3FF061003FF061FFFFF8F9FFFFF8F9FFFFF8F9FFFFF8F9
      FFFFFDFFFFFFFDFFFFFFFDFFFFFFFDFF00000000000000000000000000000000
      000000000000}
  end
  object imlCommandsCool: TImageList
    Height = 32
    Width = 32
    Left = 112
    Top = 65520
    Bitmap = {
      494C010107000900040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      00000000000036000000280000008000000060000000010020000000000000C0
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B00000000007B7B7B007B7B7B007B7B
      7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B
      7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B
      7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00426B7300426B
      7300426B7300426B7300BDBDBD00BDBDBD00BDBDBD00BDBDBD00426B7300426B
      7300426B7300426B7300BDBDBD00BDBDBD00BDBDBD00BDBDBD00426B7300426B
      7300426B7300426B7300BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00426B73007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00426B73007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00426B73007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00426B73007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      290029292900292929002929290029292900FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      630063636300636363006363630063636300FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      9400949494000000000094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      9400949494000000000094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      9400949494000000000094949400636363006363630094949400949494009494
      940094949400949494009494940094949400BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000949494006363
      6300636363006363630000000000000000000000000000000000000000000000
      0000949494006363630063636300636363000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000949494006363
      6300636363006363630000000000000000000000000000000000000000000000
      0000949494006363630063636300636363000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000949494006363
      6300636363006363630000000000000000000000000000000000000000000000
      0000949494006363630063636300636363000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000002929290029292900292929000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000029292900292929000000
      0000000000000000000094949400636363009494940000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000002929290029292900292929000000000000000000000000000000
      0000000000000000000094949400636363009494940000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000002929
      2900292929002929290029292900292929002929290029292900292929002929
      2900292929000000000094949400636363009494940000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000029292900000000000000
      0000000000000000000000000000000000000000000029292900292929000000
      0000000000000000000000000000949494006363630094949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000949494009494940094949400292929000000000000000000000000000000
      0000000000000000000000000000949494006363630094949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900292929002929290029292900292929002929
      2900000000000000000000000000949494006363630094949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940029292900292929000000
      0000000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000009494940063636300636363006363
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000949494009494940094949400000000000000000000000000000000000000
      0000000000000000000000000000000000009494940063636300636363006363
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400949494009494940094949400949494009494
      9400000000000000000000000000000000009494940063636300636363006363
      6300292929002929290029292900292929002929290063636300000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400292929002929
      2900000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000063636300949494006363
      6300636363002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000002929290029292900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000063636300949494006363
      6300636363002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400949494000000
      0000000000000000000000000000000000000000000063636300949494006363
      6300636363002929290029292900292929002929290029292900636363000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD007B7B
      7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD007B7B7B0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400949494002929
      2900292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000063636300636363009494
      9400949494009494940063636300636363006363630063636300292929006363
      6300000000000000000000000000000000000000000000000000000000000000
      0000949494009494940094949400292929000000000000000000000000000000
      0000000000000000000000000000000000000000000063636300636363009494
      9400949494009494940063636300636363006363630063636300292929006363
      6300000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400949494000000
      0000000000000000000000000000000000000000000063636300636363009494
      9400949494009494940063636300636363006363630063636300292929006363
      630000000000000000000000000000000000426B73007B7B7B00FFFFFF00BDBD
      BD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD007B7B7B0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400949494009494
      9400292929002929290000000000000000009494940094949400292929000000
      0000000000000000000000000000000000006363630029292900636363009494
      9400CECECE009494940094949400949494006363630063636300636363002929
      2900636363000000000000000000000000000000000000000000000000000000
      0000949494009494940094949400292929002929290000000000000000000000
      0000000000000000000000000000000000006363630029292900636363009494
      9400CECECE009494940094949400949494006363630063636300636363002929
      2900636363000000000000000000000000000000000000000000000000000000
      0000949494009494940094949400949494009494940094949400000000000000
      0000000000000000000000000000000000006363630029292900636363009494
      9400CECECE009494940094949400949494006363630063636300636363002929
      290063636300000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD009494940094949400949494009494
      9400949494002929290029292900000000009494940094949400292929000000
      0000000000000000000000000000636363002929290063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE009494940063636300636363006363
      6300292929006363630000000000000000000000000000000000000000000000
      0000000000009494940094949400949494002929290029292900000000000000
      0000000000000000000000000000636363002929290063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE009494940063636300636363006363
      6300292929006363630000000000000000000000000000000000000000000000
      0000000000009494940094949400949494009494940000000000000000000000
      0000000000000000000000000000636363002929290063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE009494940063636300636363006363
      630029292900636363000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400949494009494
      9400949494009494940029292900000000009494940094949400292929000000
      0000000000000000000063636300292929006363630063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00949494006363
      6300636363002929290094949400000000000000000000000000000000000000
      0000000000009494940094949400949494009494940029292900000000000000
      0000000000000000000063636300292929006363630063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00949494006363
      6300636363002929290094949400000000000000000000000000000000000000
      0000000000000000000094949400949494002929290029292900000000000000
      0000000000000000000063636300292929006363630063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00949494006363
      630063636300292929009494940000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400949494009494
      9400949494009494940000000000000000009494940094949400292929000000
      000000000000000000000000000063636300636363006363630094949400CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300636363006363630000000000000000000000000000000000292929002929
      2900292929000000000094949400949494009494940094949400292929000000
      000000000000000000000000000063636300636363006363630094949400CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300636363006363630000000000000000000000000000000000000000000000
      0000000000002929290094949400949494002929290029292900292929000000
      000000000000000000000000000063636300636363006363630094949400CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300636363006363630000000000000000007B7B7B007B7B7B00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400949494009494
      9400949494000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000006363630063636300CECECE00CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE0063636300636363006363
      6300636363000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000949494009494940094949400292929002929
      2900000000000000000000000000000000006363630063636300CECECE00CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE0063636300636363006363
      6300636363000000000000000000000000000000000000000000000000000000
      0000292929009494940094949400949494009494940029292900292929002929
      2900000000000000000000000000000000006363630063636300CECECE00CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE0063636300636363006363
      630063636300000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD009494940094949400949494009494
      9400000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000094949400636363009494
      940094949400CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300000000000000000000000000000000000000000094949400949494009494
      9400292929002929290000000000292929009494940094949400949494002929
      2900000000000000000000000000000000000000000094949400636363009494
      940094949400CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300000000000000000000000000000000000000000000000000000000000000
      0000949494009494940094949400949494009494940094949400292929002929
      2900000000000000000000000000000000000000000094949400636363009494
      940094949400CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      630000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400949494000000
      0000000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400CECECE00CECECE00CECECE00CECECE00CECE
      CE00CECECE000000000000000000000000000000000094949400949494009494
      9400292929002929290029292900292929009494940094949400949494000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400CECECE00CECECE00CECECE00CECECE00CECE
      CE00CECECE000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400949494002929
      2900292929000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400CECECE00CECECE00CECECE00CECECE00CECE
      CE00CECECE00000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009494940094949400000000000000
      0000000000000000000000000000000000009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400CECECE00CECE
      CE0094949400CECECE0000000000000000000000000000000000949494009494
      9400949494002929290029292900949494009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400CECECE00CECE
      CE0094949400CECECE0000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400949494000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400CECECE00CECE
      CE0094949400CECECE000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD009494940000000000000000000000
      0000000000000000000000000000000000009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000094949400949494009494940063636300949494000000000000000000CECE
      CE00CECECE0094949400CECECE00000000000000000000000000949494009494
      9400949494009494940094949400949494009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000094949400949494009494940063636300949494000000000000000000CECE
      CE00CECECE0094949400CECECE00000000000000000000000000949494009494
      9400949494009494940094949400949494009494940094949400949494009494
      9400000000000000000000000000000000000000000000000000000000000000
      000094949400949494009494940063636300949494000000000000000000CECE
      CE00CECECE0094949400CECECE0000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD007B7B7B0000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      000000000000CECECE00CECECE00000000000000000000000000000000000000
      0000949494009494940094949400949494000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      000000000000CECECE00CECECE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      000000000000CECECE00CECECE0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000000000000292929002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000292929002929290029292900000000000000000000000000000000000000
      0000000000000000000029292900292929002929290000000000000000000000
      0000000000000000000000000000000000002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929002929290063636300636363006363
      6300636363002929290029292900292929002929290029292900292929006363
      6300636363006363630063636300292929002929290029292900292929002929
      2900292929002929290063636300636363002929290029292900292929002929
      2900292929002929290029292900292929006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363006363630094949400636363006363
      6300636363006363630029292900636363006363630063636300636363009494
      9400636363006363630063636300636363002929290063636300636363006363
      6300636363009494940063636300636363006363630029292900636363006363
      6300636363006363630063636300636363009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      9400949494000000000094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      9400949494000000000094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      9400949494000000000094949400636363006363630094949400949494009494
      9400949494009494940094949400949494009494940094949400636363006363
      6300636363006363630094949400949494009494940094949400949494009494
      9400636363006363630063636300636363009494940094949400949494009494
      9400949494000000000094949400636363006363630094949400949494009494
      9400949494009494940094949400949494000000000000000000949494006363
      6300636363006363630000000000000000000000000000000000000000000000
      0000949494006363630063636300636363000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000949494006363
      6300636363006363630000000000000000000000000000000000000000000000
      0000949494006363630063636300636363000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000949494006363
      6300636363006363630000000000000000000000000000000000000000000000
      0000949494006363630063636300636363000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000949494006363
      6300636363006363630000000000000000000000000000000000000000000000
      0000949494006363630063636300636363000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400636363000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000094949400949494006363630029292900000000000000
      0000000000000000000000000000000000000000000029292900292929000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000292929000000000094949400636363009494940000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400636363009494940000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000002929
      2900292929000000000000000000000000000000000029292900292929000000
      0000000000000000000094949400636363009494940000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400636363009494940000000000000000000000
      0000000000006363630029292900636363006363630029292900000000000000
      0000000000000000000000000000000000000000000029292900292929000000
      0000000000000000000000000000000000000000000000000000000000002929
      2900292929000000000000000000949494006363630094949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000949494006363630094949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000000000000000000002929
      2900292929000000000000000000000000000000000029292900292929000000
      0000000000000000000000000000949494006363630094949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000000000000029292900292929002929
      2900292929002929290029292900292929002929290029292900292929000000
      0000000000000000000000000000949494006363630094949400000000000000
      0000636363002929290029292900292929006363630029292900000000000000
      0000000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000000000000292929009494
      9400292929000000000000000000000000009494940063636300636363006363
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000000000000000000000002929
      2900292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009494940063636300636363006363
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000009494940063636300636363006363
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000000000000029292900292929002929
      2900292929002929290029292900292929002929290029292900292929000000
      0000000000000000000000000000000000009494940063636300636363006363
      6300292929002929290029292900292929002929290063636300000000000000
      0000000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000029292900949494009494
      9400292929000000000000000000000000000000000063636300949494006363
      6300636363002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000000000000000000000002929
      2900292929002929290029292900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000063636300949494006363
      6300636363002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000063636300949494006363
      6300636363002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      0000000000000000000000000000000000000000000063636300949494006363
      6300636363002929290029292900292929002929290029292900636363000000
      0000000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000002929290094949400949494009494
      9400292929000000000000000000000000000000000063636300636363009494
      9400949494009494940063636300636363006363630063636300292929006363
      6300000000000000000000000000000000000000000000000000949494009494
      9400292929002929290029292900292929002929290000000000000000000000
      0000000000000000000000000000000000000000000063636300636363009494
      9400949494009494940063636300636363006363630063636300292929006363
      6300000000000000000000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000063636300636363009494
      9400949494009494940063636300636363006363630063636300292929006363
      6300000000000000000000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      0000000000000000000000000000000000000000000063636300636363009494
      9400949494009494940063636300636363006363630063636300292929006363
      6300000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000292929009494940094949400949494009494
      9400292929000000000000000000000000006363630029292900636363009494
      9400CECECE009494940094949400949494006363630063636300636363002929
      2900636363000000000000000000000000000000000000000000949494009494
      9400949494009494940029292900292929002929290029292900292929000000
      0000000000000000000000000000000000006363630029292900636363009494
      9400CECECE009494940094949400949494006363630063636300636363002929
      2900636363000000000000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000006363630029292900636363009494
      9400CECECE009494940094949400949494006363630063636300636363002929
      2900636363000000000000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      0000000000000000000000000000000000006363630029292900636363009494
      9400CECECE009494940094949400949494006363630063636300636363002929
      2900636363000000000000000000000000009494940094949400292929000000
      0000000000000000000029292900949494009494940094949400949494009494
      9400292929000000000000000000636363002929290063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE009494940063636300636363006363
      6300292929006363630000000000000000000000000000000000949494009494
      9400949494009494940094949400949494002929290029292900292929002929
      2900292929000000000000000000636363002929290063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE009494940063636300636363006363
      6300292929006363630000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000636363002929290063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE009494940063636300636363006363
      6300292929006363630000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      0000000000000000000000000000636363002929290063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE009494940063636300636363006363
      6300292929006363630000000000000000009494940094949400292929000000
      0000000000000000000094949400949494009494940094949400949494009494
      9400292929000000000063636300292929006363630063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00949494006363
      6300636363002929290094949400000000000000000000000000949494009494
      9400949494009494940094949400949494009494940094949400292929002929
      2900292929000000000063636300292929006363630063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00949494006363
      6300636363002929290094949400000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000063636300292929006363630063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00949494006363
      6300636363002929290094949400000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      0000000000000000000063636300292929006363630063636300636363006363
      6300CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00949494006363
      6300636363002929290094949400000000009494940094949400292929000000
      0000000000000000000094949400949494009494940094949400949494009494
      940029292900000000000000000063636300636363006363630094949400CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300636363006363630000000000000000000000000000000000949494009494
      9400949494009494940094949400949494009494940094949400949494009494
      940000000000000000000000000063636300636363006363630094949400CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300636363006363630000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      000000000000000000000000000063636300636363006363630094949400CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300636363006363630000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      000000000000000000000000000063636300636363006363630094949400CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300636363006363630000000000000000009494940094949400292929000000
      0000000000000000000000000000949494009494940094949400949494009494
      9400292929000000000000000000000000006363630063636300CECECE00CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE0063636300636363006363
      6300636363000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400949494009494940094949400949494009494
      9400000000000000000000000000000000006363630063636300CECECE00CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE0063636300636363006363
      6300636363000000000000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000006363630063636300CECECE00CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE0063636300636363006363
      6300636363000000000000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      0000000000000000000000000000000000006363630063636300CECECE00CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE0063636300636363006363
      6300636363000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000009494940094949400949494009494
      9400292929000000000000000000000000000000000094949400636363009494
      940094949400CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300000000000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400949494009494940094949400000000000000
      0000000000000000000000000000000000000000000094949400636363009494
      940094949400CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300000000000000000000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000094949400636363009494
      940094949400CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300000000000000000000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      0000000000000000000000000000000000000000000094949400636363009494
      940094949400CECECE00CECECE00CECECE00CECECE00CECECE00636363006363
      6300000000000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000094949400949494009494
      9400292929000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400CECECE00CECECE00CECECE00CECECE00CECE
      CE00CECECE000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400949494000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400CECECE00CECECE00CECECE00CECECE00CECE
      CE00CECECE000000000000000000000000000000000000000000949494009494
      9400292929000000000000000000000000009494940094949400292929000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400CECECE00CECECE00CECECE00CECECE00CECE
      CE00CECECE000000000000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400292929000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400949494009494940094949400CECECE00CECECE00CECECE00CECECE00CECE
      CE00CECECE000000000000000000000000009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000949494009494
      9400000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400CECECE00CECE
      CE0094949400CECECE0000000000000000000000000000000000949494009494
      9400949494009494940000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400CECECE00CECE
      CE0094949400CECECE0000000000000000000000000000000000949494009494
      9400000000000000000000000000000000009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400CECECE00CECE
      CE0094949400CECECE0000000000000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400949494009494940094949400949494009494940094949400CECECE00CECE
      CE0094949400CECECE0000000000000000009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      9400000000000000000000000000000000000000000000000000000000000000
      000094949400949494009494940063636300949494000000000000000000CECE
      CE00CECECE0094949400CECECE00000000000000000000000000949494009494
      9400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000094949400949494009494940063636300949494000000000000000000CECE
      CE00CECECE0094949400CECECE00000000000000000000000000949494009494
      9400000000000000000000000000000000009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000094949400949494009494940063636300949494000000000000000000CECE
      CE00CECECE0094949400CECECE00000000009494940094949400949494009494
      9400949494009494940094949400949494009494940094949400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000094949400949494009494940063636300949494000000000000000000CECE
      CE00CECECE0094949400CECECE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      000000000000CECECE00CECECE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      000000000000CECECE00CECECE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      000000000000CECECE00CECECE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009494940063636300949494000000000000000000000000000000
      000000000000CECECE00CECECE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000080000000600000000100010000000000000600000000000000000000
      000000000000000000000000FFFFFF00F75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EEF3DFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75E
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FC7F1FC7FC7F1FC7FC7F1FC7FFF7FFF7F
      000000000000000000000000FF7FFF7F000000000000000000000000FF7FFF7F
      000004000000040000000400FF7FFF7FC3F0FE3FC3F0FE3FC3F0FE3FFF7FFF7F
      E7F9FE3FE7F9FE3FE7F9FE3FFF7FFF7FFFFFFE3FFFFFFE3FFFFFFE3F0000FF7F
      FFFFFE3FFFFFFE3FFFFFFE3FF75EF75EFFFFFE3FFFFFFE3FFFFFFE3FF75EF75E
      FFFFFE3FFFFFFE3FFFFFFE3F7B6FFF7FFFFFFE3FFFFFFE3FFFFFFE3FF75EF75E
      FFFFFE3FFFFFFE3FFFFFFE3FF75EF75EFFFFFE3FFFFFFE3FFFFFFE3FF75EF75E
      FFFFFE3FFFFFFE3FFFFFFE3FF75EF75EFFFFFE3FFFFFFE3FFFFFFE3FFFFFFFFF
      FFFDFC3FF8FDFC3FFFFDFC3F0000FFFFFF9C783FF8FC783FE004783FFFFFFFFF
      BF9E303FF0FE303FF00E303FFFFFFFFF1F1F003FF1FF003FC00F003FF75EF75E
      0F1F801FF9FF801FE01F801FFF7FFF7F071F800FF0FF800FE01F800FFF7FFF7F
      031F0007F07F0007F03F0007FF7FFF7F011E0003F83E0003F87E0003FF7FFF7F
      011C0001F83C0001FC3C0001FF7FFF7F031E0003C41E0003F81E0003FF7FFF7F
      071F0007C60F0007F00F0007FF7FFF7F0F1F800F820F800FF00F800FFF7FFF7F
      1F1FC007801FC007E007C007F75EEF3D3F3FE003C03FE003E01FE003F75EF75E
      7F3FF061C03FF061C00FF061F75EF75EFFFFF8F9F0FFF8F9FFFFF8F9F75EF75E
      FFFFFDFFFFFFFDFFFFFFFDFFF75EF75EC7F1FC7FC7F1FC7FC7F1FC7FC7F1FC7F
      0000000000000000000000000000000000000000000000000000000000000000
      00000400000004000000040000000400C3F0FE3FC3F0FE3FC3F0FE3FC3F0FE3F
      E7F9FE3FE7F9FE3FE7F9FE3FE7F9FE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3FFFFFFE3F
      FFFDFC3FFFFDFC3FFFFDFC3FFFFDFC3F9FF4783FFFFC783FE79C783FFFFC783F
      9FE6303FFFFE303FE79E303F801E303F1FC7003FE7FF003FC71F003F801F003F
      1F87801FE1FF801FC71F801F001F801F1F07800FC07F800FC71F800F001F800F
      1E070007C01F0007C71F0007001F00071C060003C0060003C71E0003001E0003
      1C040001C0040001C71C0001001C00011C060003C00E0003C71E0003001E0003
      1E070007C00F0007C71F0007001F00071F07800FC03F800FC71F800F001F800F
      1F87C007C0FFC007C71FC007001FC0073FCFE003C3FFE003CF3FE003003FE003
      3FEFF061CFFFF061CF3FF061003FF061FFFFF8F9FFFFF8F9FFFFF8F9FFFFF8F9
      FFFFFDFFFFFFFDFFFFFFFDFFFFFFFDFF00000000000000000000000000000000
      000000000000}
  end
  object imlTrayIcons: TImageList
    Left = 232
    Top = 65520
    Bitmap = {
      494C010107000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00299CFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00292929005A5A5A005A5A5A005A5A
      5A00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00292929009C9C9C00FFFFFF00FFFFFF00FFFFFF00292929009C9C
      9C00FFFFFF00FFFFFF00FFFFFF00292929009C9C9C00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF009C9C9C0029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF005A5A5A005A5A5A00FFFFFF00FFFFFF00FFFFFF005A5A5A005A5A
      5A00FFFFFF00FFFFFF00FFFFFF009C9C9C0029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF009C9C9C005A5A5A005A5A5A005A5A5A005A5A5A009C9C9C005A5A5A005A5A
      5A005A5A5A005A5A5A009C9C9C005A5A5A00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF009C9C9C0029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF009C9C9C0029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF009C9C9C0029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF005A5A5A00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00295A
      9C00FFFFFF00FFFFFF005A5A5A005A5A5A0029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF009C9C9C0029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000FF000000FF000000FF0000005A0000005A00FFFFFF005A5A
      5A0029292900295A9C00299CFF00299CFF00295A9C00292929005A5A5A00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000FF0000005A0000005A00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF005A5A9C00429CB500295ACE0029292900292929005A5A5A00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000005A00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00295A9C00295A5A002929290029292900FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF009C9C9C009C9C9C009C9C9C005A9CCE00299CFF009C9CCE00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000FF000000FF000000FF000000FF00FFFFFF00FFFFFF00FFFF
      FF009C9C9C00429CB5005ACEFF005ACEFF00299CFF005A5A5A00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000FF000000FF000000FF000000FF000000FF00FFFFFF005A5A
      5A00295A9C005ACEFF005ACEFF005ACEFF00299CFF00295A5A005A5A5A00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF009C9C9C009C9C9C00FFFFFF00FFFFFF009C9CCE00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD0000397B00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD0000397B00BDBDBD00FFFFFF00BDBDBD00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00FFFFFF00BDBDBD00FFFF
      FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
      FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
      FF00DEDEDE00FFFFFF00BDBDBD00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
      FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
      FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00BDBDBD007B7B7B000000
      0000DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD007B7B7B000000
      0000DEDEDE00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000292929009C9C9C000000
      00000000000000000000292929009C9C9C000000000000000000000000002929
      29009C9C9C0000000000000000000000000000000000292929009C9C9C000000
      00000000000000000000292929009C9C9C000000000000000000000000002929
      29009C9C9C0000000000000000000000000000000000292929009C9C9C000000
      00000000000000000000292929009C9C9C000000000000000000000000002929
      29009C9C9C00000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009C9C9C005A5A5A005A5A5A005A5A
      5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A5A005A5A5A009C9C9C005A5A
      5A00292929005A5A5A005A5A5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A
      5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A5A005A5A5A009C9C9C005A5A
      5A00292929005A5A5A005A5A5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A
      5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A5A005A5A5A009C9C9C005A5A
      5A00292929005A5A5A005A5A5A005A5A5A00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009C9C
      9C0029292900000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009C9C
      9C0029292900000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009C9C
      9C002929290000000000000000005A5A5A00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000009C9C9C00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00292929009C9C9C00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C0029292900000000000000000000000000FFFFFF00BDBDBD00FFFFFF00BDBD
      BD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBD
      BD00FFFFFF00BDBDBD00FFFFFF00BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C0029292900000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C002929290000000000000000000000000029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF005A5A5A005A5A5A00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C0029292900000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000000000000000
      000000005A000000000000000000295A9C0000000000000000005A5A5A005A5A
      5A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000295A9C0000000000000000005A5A5A005A5A
      5A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000295A9C0000000000000000005A5A5A005A5A
      5A0029292900000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00FFFFFF00FFFFFF00FFFFFF0000005A0000000000000000000000
      00000000FF00000000000000000000000000295A9C00295A5A00292929002929
      29005A5A5A00000000000000000000000000000000000000FF000000FF000000
      FF000000FF00000000000000000000000000295A9C00295A5A00292929002929
      29005A5A5A00000000000000000000000000000000000000FF000000FF000000
      FF000000FF000000FF000000000000000000295A9C00295A5A00292929002929
      29005A5A5A0000000000000000000000000029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF0000005A00000000000000
      00000000FF000000000000000000000000005A5A9C00429CB500295ACE002929
      2900292929005A5A5A0000000000000000000000FF00FFFFFF000000FF000000
      FF00FFFFFF000000FF0000000000000000005A5A9C00429CB500295ACE002929
      2900292929005A5A5A00000000000000000000000000000000000000FF000000
      FF000000FF000000000000000000000000005A5A9C00429CB500295ACE002929
      2900292929005A5A5A000000000000000000BDBDBD00FFFFFF00BDBDBD00FFFF
      FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
      FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF000000FF000000FF0000005A000000
      00000000FF0000000000000000005A5A5A0029292900295A9C00299CFF00299C
      FF00295A9C00292929005A5A5A00000000000000FF000000FF00FFFFFF00FFFF
      FF000000FF000000FF00000000005A5A5A0029292900295A9C00299CFF00299C
      FF00295A9C00292929005A5A5A00000000000000000000000000000000000000
      FF000000000000000000000000005A5A5A0029292900295A9C00299CFF00299C
      FF00295A9C00292929005A5A5A0000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD007B7B7B00FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000FF000000FF000000FF000000
      00000000FF0000000000000000005A5A5A00295A9C005ACEFF005ACEFF005ACE
      FF00299CFF00295A5A005A5A5A00000000000000FF000000FF00FFFFFF00FFFF
      FF000000FF000000FF00000000005A5A5A00295A9C005ACEFF005ACEFF005ACE
      FF00299CFF00295A5A005A5A5A00000000000000000000000000000000000000
      FF000000000000000000000000005A5A5A00295A9C005ACEFF005ACEFF005ACE
      FF00299CFF00295A5A005A5A5A000000000029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF000000FF00000000000000
      00000000FF000000000000000000000000009C9C9C00429CB5005ACEFF005ACE
      FF00299CFF005A5A5A0000000000000000000000FF00FFFFFF000000FF000000
      FF00FFFFFF000000FF0000000000000000009C9C9C00429CB5005ACEFF005ACE
      FF00299CFF005A5A5A00000000000000000000000000000000000000FF000000
      FF000000FF000000000000000000000000009C9C9C00429CB5005ACEFF005ACE
      FF00299CFF005A5A5A000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000FF0000000000000000000000
      00000000FF00000000000000000000000000000000009C9C9C009C9C9C009C9C
      9C005A9CCE00299CFF009C9CCE0000000000000000000000FF000000FF000000
      FF000000FF00000000000000000000000000000000009C9C9C009C9C9C009C9C
      9C005A9CCE00299CFF009C9CCE0000000000000000000000FF000000FF000000
      FF000000FF000000FF000000000000000000000000009C9C9C009C9C9C009C9C
      9C005A9CCE00299CFF009C9CCE0000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009C9C9C009C9C
      9C0000000000000000009C9CCE00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009C9C9C009C9C
      9C0000000000000000009C9CCE00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009C9C9C009C9C
      9C0000000000000000009C9CCE000000000029292900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000292929009C9C9C000000
      00000000000000000000292929009C9C9C000000000000000000000000002929
      29009C9C9C0000000000000000000000000000000000292929009C9C9C000000
      00000000000000000000292929009C9C9C000000000000000000000000002929
      29009C9C9C0000000000000000000000000000000000292929009C9C9C000000
      00000000000000000000292929009C9C9C000000000000000000000000002929
      29009C9C9C0000000000000000000000000000000000292929009C9C9C000000
      00000000000000000000292929009C9C9C000000000000000000000000002929
      29009C9C9C000000000000000000000000009C9C9C005A5A5A005A5A5A005A5A
      5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A5A005A5A5A009C9C9C005A5A
      5A00292929005A5A5A005A5A5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A
      5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A5A005A5A5A009C9C9C005A5A
      5A00292929005A5A5A005A5A5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A
      5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A5A005A5A5A009C9C9C005A5A
      5A00292929005A5A5A005A5A5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A
      5A005A5A5A009C9C9C005A5A5A005A5A5A005A5A5A005A5A5A009C9C9C005A5A
      5A00292929005A5A5A005A5A5A005A5A5A00FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009C9C
      9C0029292900000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009C9C
      9C0029292900000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009C9C
      9C0029292900000000000000000000000000FFFFFF005A5A5A005A5A5A000000
      000000000000FFFFFF005A5A5A005A5A5A000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C9C
      9C002929290000000000000000000000000000005A0000000000000000000000
      00000000000000005A0000000000295A9C0000000000000000005A5A5A005A5A
      5A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000295A9C0000000000000000005A5A5A005A5A
      5A00292929000000000000000000000000000000000000005A00000000000000
      000000005A000000000000000000295A9C0000000000000000005A5A5A005A5A
      5A00292929000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000295A9C0000000000000000005A5A5A005A5A
      5A00292929000000000000000000000000000000FF0000000000000000000000
      000000005A000000FF000000000000000000295A9C00295A5A00292929002929
      29005A5A5A000000000000000000000000000000000000005A00000000000000
      000000000000000000000000000000000000295A9C00295A5A00292929002929
      29005A5A5A00000000000000000000000000000000000000FF00000000000000
      00000000FF00000000000000000000000000295A9C00295A5A00292929002929
      29005A5A5A0000000000000000000000000000005A0000005A0000005A000000
      5A0000005A00000000000000000000000000295A9C00295A5A00292929002929
      29005A5A5A000000000000000000000000000000FF0000000000000000000000
      5A000000FF000000FF0000000000000000005A5A9C00429CB500295ACE002929
      2900292929005A5A5A000000000000000000000000000000FF0000005A000000
      5A00000000000000000000000000000000005A5A9C00429CB500295ACE002929
      2900292929005A5A5A000000000000000000000000000000FF00000000000000
      00000000FF000000000000000000000000005A5A9C00429CB500295ACE002929
      2900292929005A5A5A0000000000000000000000FF000000FF000000FF000000
      FF000000FF000000000000000000000000005A5A9C00429CB500295ACE002929
      2900292929005A5A5A0000000000000000000000FF000000000000005A000000
      FF000000FF000000FF00000000005A5A5A0029292900295A9C00299CFF00299C
      FF00295A9C00292929005A5A5A0000000000000000000000FF000000FF000000
      FF0000005A0000005A00000000005A5A5A0029292900295A9C00299CFF00299C
      FF00295A9C00292929005A5A5A0000000000000000000000FF00000000000000
      00000000FF0000000000000000005A5A5A0029292900295A9C00299CFF00299C
      FF00295A9C00292929005A5A5A00000000000000FF000000FF000000FF000000
      FF000000FF0000000000000000005A5A5A0029292900295A9C00299CFF00299C
      FF00295A9C00292929005A5A5A00000000000000FF0000000000000000000000
      FF000000FF000000FF00000000005A5A5A00295A9C005ACEFF005ACEFF005ACE
      FF00299CFF00295A5A005A5A5A0000000000000000000000FF000000FF000000
      FF000000FF000000FF00000000005A5A5A00295A9C005ACEFF005ACEFF005ACE
      FF00299CFF00295A5A005A5A5A0000000000000000000000FF00000000000000
      00000000FF0000000000000000005A5A5A00295A9C005ACEFF005ACEFF005ACE
      FF00299CFF00295A5A005A5A5A00000000000000FF000000FF000000FF000000
      FF000000FF0000000000000000005A5A5A00295A9C005ACEFF005ACEFF005ACE
      FF00299CFF00295A5A005A5A5A00000000000000FF0000000000000000000000
      00000000FF000000FF0000000000000000009C9C9C00429CB5005ACEFF005ACE
      FF00299CFF005A5A5A000000000000000000000000000000FF000000FF000000
      FF000000FF000000000000000000000000009C9C9C00429CB5005ACEFF005ACE
      FF00299CFF005A5A5A000000000000000000000000000000FF00000000000000
      00000000FF000000000000000000000000009C9C9C00429CB5005ACEFF005ACE
      FF00299CFF005A5A5A0000000000000000000000FF000000FF000000FF000000
      FF000000FF000000000000000000000000009C9C9C00429CB5005ACEFF005ACE
      FF00299CFF005A5A5A0000000000000000000000FF0000000000000000000000
      0000000000000000FF000000000000000000000000009C9C9C009C9C9C009C9C
      9C005A9CCE00299CFF009C9CCE0000000000000000000000FF000000FF000000
      000000000000000000000000000000000000000000009C9C9C009C9C9C009C9C
      9C005A9CCE00299CFF009C9CCE0000000000000000000000FF00000000000000
      00000000FF00000000000000000000000000000000009C9C9C009C9C9C009C9C
      9C005A9CCE00299CFF009C9CCE00000000000000FF000000FF000000FF000000
      FF000000FF00000000000000000000000000000000009C9C9C009C9C9C009C9C
      9C005A9CCE00299CFF009C9CCE00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009C9C9C009C9C
      9C0000000000000000009C9CCE00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009C9C9C009C9C
      9C0000000000000000009C9CCE00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009C9C9C009C9C
      9C0000000000000000009C9CCE00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009C9C9C009C9C
      9C0000000000000000009C9CCE0000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF00A514000000000000000000006B2D6B2D
      000000000000654D0000000000000000A514000000000000000000006B2D6B2D
      002C00000000654D0000002C00000000A514000000000000000000006B2D6B2D
      000000000000654D0000000000000000A514000000000000000000006B2D6B2D
      0000002C0000654D002C0000000000009CE79CE79CE70000000000000000A514
      18E718E718E60000FFE7FFE7FFE7002CFFE7FFE7FFE70000FFE7FFE7FFE7A514
      FFE7FFE7FFE70000FFE7FFE7FFE70000F6C7FEC782C70000770787078307A514
      37030303C703000016010201EE01000016010201C6010000370303038303A514
      7781878183810000FFCDFFCDFFCD00009CE79CE79CE79CE70000000000000000
      18E718E718E718E7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7
      FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE77AC7FEC7B6C7FEC77307BF07B7070707
      63038F03B703070342018201B601060162018201B601060173038703B7030703
      7B819F81B7810781FFCDFFCDFFCDFFCD00000000000000000000000000000000
      000000000000}
  end
end
