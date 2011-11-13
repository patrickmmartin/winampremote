object frmMain: TfrmMain
  Left = 320
  Top = 293
  Hint = 'the winamp remote control client'
  Action = Shuffle
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Winamp Remote Control'
  ClientHeight = 172
  ClientWidth = 392
  Color = clBtnFace
  Constraints.MaxHeight = 220
  Constraints.MaxWidth = 400
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Arial'
  Font.Style = []
  Menu = mnuMain
  OldCreateOrder = True
  Position = poScreenCenter
  OnClick = mnuShuffleClick
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
    SizeGrip = False
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
      ImageIndex = 2
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
      ImageIndex = 1
      object bvl3: TBevel
        Left = 0
        Top = 0
        Width = 384
        Height = 114
        Align = alClient
      end
      object lblUpdate: TLabel
        Left = 168
        Top = 12
        Width = 101
        Height = 14
        Caption = 'Update playlist when'
      end
      object lblStartupActions: TLabel
        Left = 8
        Top = 12
        Width = 73
        Height = 14
        Caption = 'Startup actions'
      end
      object chkAutoHide: TCheckBox
        Left = 16
        Top = 36
        Width = 177
        Height = 17
        Hint = 'hide self only if connection to server established'
        Caption = '&Hide if server found'
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object chkAutoRestore: TCheckBox
        Left = 16
        Top = 63
        Width = 177
        Height = 17
        Hint = 'restore the child windows'#39's last state upon startup'
        Caption = 'Restore child windows'
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
      object rbSongChange: TRadioButton
        Left = 176
        Top = 36
        Width = 120
        Height = 17
        Hint = 'playlist is obtained when the current song changes'
        Caption = 'song changes'
        TabOrder = 2
      end
      object rbPlaylistChange: TRadioButton
        Left = 176
        Top = 64
        Width = 120
        Height = 17
        Hint = 'playlist is obtained when the playlist is altered'
        Caption = 'playlist changes'
        Checked = True
        TabOrder = 3
        TabStop = True
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
    Left = 424
    Top = 65528
  end
  object mnuMain: TMainMenu
    Images = imlActions
    Left = 360
    Top = 65520
    object mnuFile: TMenuItem
      Caption = '&Application'
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
      object Previous1: TMenuItem
        Action = Previous
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
    Left = 185
    Top = 65520
    object Configuration: TAction
      Category = 'File'
      Caption = '&Configuration'
      Hint = 'Configuration'
      ImageIndex = 2
    end
    object PlaceOnTray: TAction
      Category = 'File'
      Caption = 'Place On &Tray'
      Hint = 'Place on Tray'
      ImageIndex = 1
      ShortCut = 16456
      OnExecute = HideMain
    end
    object Exit: TAction
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'File Exit'
      ImageIndex = 27
      OnExecute = mnuShutDownClick
    end
    object ViewToolBar: TAction
      Category = 'Action'
      Caption = 'View &ToolBar'
      Hint = 'Commands Toolbar'
      ImageIndex = 3
      OnExecute = ViewToolBarExecute
    end
    object Pause: TAction
      Category = 'Action'
      Caption = '&Pause'
      Hint = 'Pause'
      ImageIndex = 6
      OnExecute = mnuPauseClick
    end
    object Play: TAction
      Category = 'Action'
      Caption = 'P&lay'
      Hint = 'Play'
      ImageIndex = 7
      OnExecute = mnuPlayClick
    end
    object Stop: TAction
      Category = 'Action'
      Caption = '&Stop'
      Hint = 'Stop'
      ImageIndex = 8
      OnExecute = mnuStopClick
    end
    object StopFade: TAction
      Category = 'Action'
      Caption = 'Stop With &Fade'
      Hint = 'Stop with Fade'
      ImageIndex = 8
      OnExecute = mnuStopFadeClick
    end
    object StopAfterCurrent: TAction
      Category = 'Action'
      Caption = 'Stop After &Current'
      Hint = 'Stop after Current'
      ImageIndex = 8
      OnExecute = mnuStopCurrentClick
    end
    object Forward5: TAction
      Category = 'Action'
      Caption = '&Forward 5 seconds'
      Hint = 'Forward 5'
      ImageIndex = 9
      OnExecute = mnuForward5Click
    end
    object Back5: TAction
      Category = 'Action'
      Caption = '&Back 5 seconds'
      Hint = 'Back 5'
      ImageIndex = 10
      OnExecute = mnuBack5Click
    end
    object ViewPlaylist: TAction
      Category = 'Playlist'
      Caption = 'View &Playlist'
      Hint = 'Playlist Editor'
      ImageIndex = 5
      OnExecute = ViewPlaylistExecute
    end
    object Shuffle: TAction
      Category = 'Playlist'
      Caption = '&Shuffle'
      Hint = 'Playlist Shuffle'
      ImageIndex = 11
      OnExecute = mnuShuffleClick
    end
    object Repeat: TAction
      Category = 'Playlist'
      Caption = '&Repeat'
      Hint = 'Playlist Repeat'
      ImageIndex = 12
      OnExecute = mnuRepeatClick
    end
    object Next: TAction
      Category = 'Playlist'
      Caption = '&Next'
      Hint = 'Next in Playlist'
      ImageIndex = 9
      OnExecute = mnuNextClick
    end
    object Previous: TAction
      Category = 'Playlist'
      Caption = '&Previous'
      Hint = 'Previous in Playlist'
      ImageIndex = 10
      OnExecute = mnuPreviousClick
    end
    object Start: TAction
      Category = 'Playlist'
      Caption = 'St&art'
      Hint = 'Start of Playlist'
      ImageIndex = 13
      OnExecute = mnuPlaylistStartClick
    end
    object End: TAction
      Category = 'Playlist'
      Caption = '&End'
      Hint = 'End of Playlist'
      ImageIndex = 14
      OnExecute = mnuPlaylistEndClick
    end
    object Delete: TAction
      Category = 'Playlist'
      Caption = '&Delete'
      Hint = 'Delete Playlist'
      ImageIndex = 15
      OnExecute = mnuDeletePlayListClick
    end
    object PlayFromStart: TAction
      Category = 'Playlist'
      Caption = 'Play &From Start'
      Hint = 'Play from Start'
      ImageIndex = 7
      Visible = False
      OnExecute = mnuPlayFromStartClick
    end
    object AddFiles: TAction
      Category = 'Playlist'
      Caption = 'Add Fi&les'
      Hint = 'Add Files To Playlist'
      ImageIndex = 16
      OnExecute = mnuAddFileToPlayListClick
    end
    object AddPlayIist: TAction
      Category = 'Playlist'
      Caption = 'Add Pla&yIist'
      Hint = 'Add Playlist'
      ImageIndex = 17
      Visible = False
      OnExecute = mnuAddFileToPlayListClick
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
      ImageIndex = 4
      OnExecute = ViewVolumeExecute
    end
    object Up: TAction
      Category = 'Volume'
      Caption = '&Up'
      Hint = 'Volume Up'
      ImageIndex = 19
      OnExecute = mnuVolumeUpClick
    end
    object Down: TAction
      Category = 'Volume'
      Caption = '&Down'
      Hint = 'Voume Down'
      ImageIndex = 20
      OnExecute = mnuVolumeDownClick
    end
    object UpMore: TAction
      Category = 'Volume'
      Caption = 'Up &More'
      Hint = 'Volume Up (More)'
      ImageIndex = 21
      OnExecute = mnuVolumeUpMoreClick
    end
    object DownMore: TAction
      Category = 'Volume'
      Caption = 'Down M&ore'
      Hint = 'Volume Down (more)'
      ImageIndex = 22
      OnExecute = mnuVolumeDownMoreClick
    end
    object Zero: TAction
      Category = 'Volume'
      Caption = '&Zero'
      Hint = 'Volume off'
      ImageIndex = 23
      OnExecute = mnuSetVolume0Click
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
      OnExecute = mnuSetVolume100Click
    end
    object About: TAction
      Category = 'Help'
      Caption = '&About'
      Hint = 'About this Application '
      ImageIndex = 26
      OnExecute = mnuAboutClick
    end
    object ShowMainForm: TAction
      Category = 'File'
      Caption = 'Show'
      Hint = 'Show'
      ImageIndex = 0
      OnExecute = ShowMain
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
      ImageIndex = 0
      OnExecute = DetailsExecute
    end
    object PlaylistRefresh: TAction
      Category = 'Playlist'
      Caption = 'PlaylistRefresh'
      ImageIndex = 13
    end
    object SetLanguage: TAction
      Category = 'File'
      Caption = 'SetLanguage'
      ImageIndex = 2
    end
  end
  object imlActions: TImageList
    Left = 272
    Top = 65520
    Bitmap = {
      494C010121002200040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000009000000001001000000000000048
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
      0000000000000000000000000000000000001000100010001000100010001000
      1000100010001000100010001000100010000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001000100010001000100010001000
      1000100010001000100010001000100010000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001000100010001000100010001000
      1000100010001000100010001000100010000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007C0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C88700000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C08710000000000000000000000000000
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
      000000000000000000000000000000000000E07FE07FE07FE07FE07FE07FE07F
      E07FE07FE07FE07FE07FE07FE07FE07FE07F10001000100010001000FF7FFE7F
      FE7FFE7FFF7F007C007C007C007C007C0000FE7F007CFF7F900010001000FF7F
      007C007CFF7F100010001000FF7FFE7F007C007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007CE07FE07FE07FE07FE07FE07FE07F
      E07FE07FE07FE07FE07FE07FE07FE07FE07F10001000100010001000FF7FFF7F
      FE7FFE7FFF7F007C007C007C007C007C00001000FF7F007C007CFF7F1000FF7F
      007C007CFF7F1000FF7FFF7F007C007C1000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FE07FE07FE07FE07FE07FE07FE07F
      E07FE07FE07FE07FE07FE07FE07FE07FE07F10001000100010001000FF7FFF7F
      FE7FFE7FFF7F007C007C007C007C007C0000100010001000FF7F007C007CFF7F
      007C007CFF7FFF7F007C007C100010001000007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007C007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007C10001000100010001000FF7FFE7F
      FE7FFE7FFF7F007C007C007C007C007C0000007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007CFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007C10001000100010001000FF7FFE7F
      FF7FFE7FFF7F007C007C007C007C007C0000007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007C1F001F001F001F001F001F001F00
      007C007C007C007C007C007C007C007C007C007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007C10001000100010001000FF7FFE7F
      FE7FFE7FFF7F007C007C007C007C007C0000100010001000007C007CFF7FFF7F
      007C007CFF7F007C007CFF7F1000100010001F001F001F001F001F001F001F00
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C007C007C007C007C007C
      007C007C007C007C007C007C007C007C007C10001000100010001000FF7FFE7F
      FF7FFE7FFF7F007C007C007C007C007C00001000007C007CFF7FFF7F1000FF7F
      007C007CFF7F1000FF7F007C007CFF7F10001F001F001F001F001F001F001F00
      007C007C007C007C007C007C007C007C007C0000000000000000000000000000
      00000000000000000000000000000000000010001000100010001000FF7FFE7F
      FE7FFE7FFF7F007C007C007C007C007C0000007CFE7FFF7F100010001000FF7F
      007C007CFF7F100010009000FF7F007CFE7F1F001F001F001F001F001F001F00
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      00000000000000000000000000000000000010001000100010001000FF7FFE7F
      FE7FFF7FFF7F007C007C007C007C007C00000000000000000000000000000000
      0000000000000000000000000000000000001F001F001F001F001F001F001F00
      007C007C007C007C007C007C007C007C007C0000000000000000000000000000
      00000000000000000000000000000000000010001000100010001000FF7FFE7F
      FF7FFE7FFF7F007C007C007C007C007C00000000000000000000000000000000
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
      00000000000000000000000000000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B556000000000000524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2DFF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A831800000000AD35FF7F6B2D6B2D00000000FF7F6B2D
      6B2D00000000007C007C007C007C000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      00000000007CFF7F007C007CFF7F007C0000E003E003E0030000000000000000
      0000000000000000524A8318000000000000E003E003E0030000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      00000000007C007CFF7FFF7F007C007C0000E003E003E0030000000000000000
      0000000000000000524A8318000000000000E003E003E0030000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      00000000007C007CFF7FFF7F007C007C0000E07FE07FE07F0000000000000000
      0000000000000000524A8318000000000000E07FE07FE07F0000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      00000000007CFF7F007C007CFF7F007C0000E07FE07FE07F0000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      000000000000007C007C007C007C00000000007C007C007C0000000000000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000000340034000000000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      664D000000006B2D2925A514000000000000007C007C007C0000000000000000
      000043552631A514A5146B2D0000000000000000000000000000000000000000
      000043552631A514A5146B2D00000000000000000000007C0000000000000000
      000043552631A514A5146B2D0000000000000000000000000000000000000000
      000043552631A514A5146B2D0000000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C310000000000000000007C0034000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      8C31C6184741877A6576434DC6188C3100000000000000000000000000000000
      8C31C6184741877A6576434DC6188C31000000000000007C007C003400000000
      8C31C6184741877A6576434DC6188C3100000000000000000000000000000000
      8C31C6184741877A6576434DC6188C3100000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E6772272929250000003400340000007C007C00000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      000031460C4ACA72E97E87764A2D000000000000000000000000000000000000
      000031460C4ACA72E97E87764A2D00000000007C007C00000034007C00340000
      000031460C4ACA72E97E87764A2D000000000000000000000000000000000000
      000031460C4ACA72E97E87764A2D000000000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000007C0034007C007C00000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B362000000000000007C007C000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B362000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B556000000000000524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2DFF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A83180000000000000D000D000D000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000D000D000D000000000000000000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A831800000000000000000D0000000000AD3500000000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A831800000000000000000D00000000000000AD350000
      664D000000006B2D2925A5140000000000000D000D000D000000000000000000
      664D000000006B2D2925A51400000000000000000D00000000000000AD350000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      000043552631A514A5146B2D00000000000000000D0000000000000000000000
      000043552631A514A5146B2D00000000000000000D000000000000000000AD35
      000043552631A514A5146B2D0000000000000000000000000000000000000000
      000043552631A514A5146B2D0000000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C3100000000000000000000AD35000000000000
      8C31C6184741877A6576434DC6188C31000000000000AD350000000000000000
      8C31C6184741877A6576434DC6188C3100000000000000000000AD3500000000
      8C31C6184741877A6576434DC6188C3100000000000000000000000000000000
      8C31C6184741877A6576434DC6188C3100000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      000031460C4ACA72E97E87764A2D000000000000000000000000000000000000
      000031460C4ACA72E97E87764A2D00000000000000000000000000000000AD35
      000031460C4ACA72E97E87764A2D000000000000000000000000000000000000
      000031460C4ACA72E97E87764A2D0000000000000000000000000000AD350000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B362000000000000000000000000AD350000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000AD350000FF7F
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B362000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B556000000000000524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2DFF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A8318000000000000E003E003E003E003000000000000
      0000000000000000524A83180000000000000000ED7FED7FE07FE07FED7F0000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000ED7FE07FE07FE07FE07F0000
      0000000000000000524A831800000000000000000D0000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A8318000000000000E003E003E003E003000000000000
      0000000000000000524A83180000000000000000ED7FE07FE07FE07FE07F0000
      0000000000000000524A83180000000000000D000D000D000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000E07FE07F0000000000000000
      664D000000006B2D2925A51400000000000000000D00000000000000AD350000
      664D000000006B2D2925A5140000000000000000E003E003E003E00300000000
      000043552631A514A5146B2D000000000000E003E003E003E003000000000000
      000043552631A514A5146B2D0000000000000000000000000000000000000000
      000043552631A514A5146B2D0000000000000000000000000000000000000000
      000043552631A514A5146B2D0000000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000D00000000000000
      8C31C6184741877A6576434DC6188C310000000000000D000000000000000000
      8C31C6184741877A6576434DC6188C310000000000000D000000000000000000
      8C31C6184741877A6576434DC6188C310000000000000000AD35000000000000
      8C31C6184741877A6576434DC6188C310000000000000D000D000D0000000000
      4A294641C87EE97EC87E677227292925000000000D000D000D00000000000000
      4A294641C87EE97EC87E677227292925000000000D000D000D00000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000D00000000000000
      000031460C4ACA72E97E87764A2D00000000000000000D000000000000000000
      000031460C4ACA72E97E87764A2D00000000000000000D000000000000000000
      000031460C4ACA72E97E87764A2D000000000000000000000000000000000000
      000031460C4ACA72E97E87764A2D000000000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B362000000000000000000000000AD350000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B362000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B556000000000000524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2DFF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A8318000000000000E003E003E003E003000000000000
      0000000000000000524A8318000000000000FF7FFF7FFF7FFF7F000000000000
      0000000000000000524A8318000000000000E003E003E003E003000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000010001000100000000000
      0000000000000000524A8318000000000000E003E003E003E003000000000000
      0000000000000000524A8318000000000000E003E003E003E003000000000000
      0000000000000000524A831800000000000000000000E003E003000000000000
      0000000000000000524A83180000000000000000000010001000100000000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000010001000100000000000
      000043552631A514A5146B2D000000000000E003E003E003E003000000000000
      000043552631A514A5146B2D000000000000E003E003E003E003000000000000
      000043552631A514A5146B2D000000000000E003000000000000000000000000
      000043552631A514A5146B2D0000000000000000000000000000000010000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000000000000000000010000000
      8C31C6184741877A6576434DC6188C310000E003E003E003E003000000000000
      8C31C6184741877A6576434DC6188C310000E003E003E003E003000000000000
      8C31C6184741877A6576434DC6188C31000000000000E0030000000000000000
      8C31C6184741877A6576434DC6188C3100000000000010000000100000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000000010001000000000000000
      000031460C4ACA72E97E87764A2D00000000FF7FFF7FFF7FFF7F000000000000
      000031460C4ACA72E97E87764A2D00000000E003E003E003E003000000000000
      000031460C4ACA72E97E87764A2D00000000E003E003E003E003000000000000
      000031460C4ACA72E97E87764A2D000000000000000010001000100000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B362000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B556000000000000524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2DFF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A8318000000000000E003E003E003E003100000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000010000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A8318000000000000E003E003E003E003000010000000
      0000000000000000524A83180000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000000000000002400000000
      664D000000006B2D2925A5140000000000000024000000000000000000240000
      664D000000006B2D2925A5140000000000000000000000000000000010000000
      664D000000006B2D2925A5140000000000000024002400240024002400000000
      000043552631A514A5146B2D0000000000000024000000000000007C00000000
      000043552631A514A5146B2D000000000000007C0000000000000024007C0000
      000043552631A514A5146B2D000000000000E003E003E003E003100000000000
      000043552631A514A5146B2D000000000000007C007C007C007C007C00000000
      00008B41246A8359A518C6188C3100000000007C002400000000007C00000000
      00008B41246A8359A518C6188C3100000000007C000000000024007C007C0000
      00008B41246A8359A518C6188C31000000000000000000000000000000000000
      00008B41246A8359A518C6188C3100000000007C007C007C007C007C00000000
      8C31C6184741877A6576434DC6188C310000007C007C00240000007C00000000
      8C31C6184741877A6576434DC6188C310000007C00000024007C007C007C0000
      8C31C6184741877A6576434DC6188C310000E003E003E003E003100000000000
      8C31C6184741877A6576434DC6188C310000007C007C007C007C007C00000000
      4A294641C87EE97EC87E6772272929250000007C007C007C0000007C00000000
      4A294641C87EE97EC87E6772272929250000007C00000000007C007C007C0000
      4A294641C87EE97EC87E67722729292500000000000000000000000010000000
      4A294641C87EE97EC87E6772272929250000007C007C007C007C007C00000000
      000031460C4ACA72E97E87764A2D00000000007C007C00000000007C00000000
      000031460C4ACA72E97E87764A2D00000000007C000000000000007C007C0000
      000031460C4ACA72E97E87764A2D00000000E003E003E003E003100000000000
      000031460C4ACA72E97E87764A2D00000000007C007C007C007C007C00000000
      00000000734E734E10426A5E8676B3620000007C000000000000007C00000000
      00000000734E734E10426A5E8676B3620000007C0000000000000000007C0000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000008318B5560000000000008318
      B5560000000000008318B55600000000000000008318B5560000000000008318
      B5560000000000008318B5560000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D0000000000000000000000000000
      0000000000000000000000000000000000000000000000001042104210421042
      104210421042104210421042000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A8318000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A83180000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000001042FF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F10420000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000001042FF7F00000000
      0000000000000000FF7F10420000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000001042FF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F10420000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000001042FF7F00000000
      00000000FF7FFF7FFF7FAD350000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000001042104210421042
      1042104210421042104210420000000000000000000000001042FF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F10420000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000001042F75EF75EF75E
      F75EF75EF75EF75EF75E10420000000000000000000000001042FF7F007C007C
      007C007C007CFF7FFF7F10420000000000000000002400000000002400000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000000001042F75EAD35AD35
      AD35AD35AD35AD35F75E10420000000000000000000000001042FF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F10420000000000000000007C00000000007C00000000
      000043552631A514A5146B2D0000000000000000002400000000000000000000
      000043552631A514A5146B2D0000000000000000000000001042F75EF75EF75E
      AD35F75EF75EF75EF75E10420000000000000000000000001042FF7F00000000
      0000000000000000FF7F10420000000000000000007C00000000007C00000000
      00008B41246A8359A518C6188C31000000000000007C00240024000000000000
      00008B41246A8359A518C6188C31000000000000000000001042F75EF75EF75E
      F75EF75EF75EF75EF75E10420000000000000000000000001042FF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F10420000000000000000007C00000000007C00000000
      8C31C6184741877A6576434DC6188C3100000000007C007C007C002400240000
      8C31C6184741877A6576434DC6188C3100000000000000001042F75EAD35AD35
      AD35AD35AD35AD35F75E10420000000000000000000000001042FF7F00000000
      000000000000FF7FFF7F10420000000000000000007C00000000007C00000000
      4A294641C87EE97EC87E67722729292500000000007C007C007C007C007C0000
      4A294641C87EE97EC87E67722729292500000000000000001042F75EF75EF75E
      AD35F75EF75EF75EF75E10420000000000000000000000001042FF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F10420000000000000000007C00000000007C00000000
      000031460C4ACA72E97E87764A2D000000000000007C007C007C007C00000000
      000031460C4ACA72E97E87764A2D00000000000000000000067E0D000D000D00
      0D000D000D00000000000000000000000000000000000000067E0D000D000D00
      0D000D000D000000000000000000000000000000007C00000000007C00000000
      00000000734E734E10426A5E8676B36200000000007C007C0000000000000000
      00000000734E734E10426A5E8676B36200000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      000000000000524A314600000000B362000000008318B5560000000000008318
      B5560000000000008318B5560000000000000000104210421042104210421042
      1042104210421042104210421042104210420000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000524A6B2D6B2D4A296B2D524A6B2D
      6B2D4A296B2D524A6B2D83186B2D6B2D6B2D0000104210421042104210421042
      104210421042104210421042A57D067EAD350000000000000000000010420000
      0000000000000000000018631042000000000000000000000000000000000000
      000000000000000000000000000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000524A83180000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF7F18631042
      0000000000000000186310421863000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      00000000000000000000104210421042000000000000000000000000FF7F1863
      1042000000001863104218630000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF7F
      1863104218631042186300000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      1042104210421042104210421042000000000000000000000000000000000000
      FF7F186310421863000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      1863104218630000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000524A83180000000000000000000000000000104210421042
      1042104210421042104210420000000000000000000000000000000000001863
      1042186300001863104200000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      664D000000006B2D2925A5140000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000010420000000018631042
      186300000000FF7F186310421042000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000043552631A514A5146B2D0000000000000000104210421042104210421042
      1042104210421042000000000000000000000000186310421042000010421863
      0000000000000000186310421042104200000000000000001042104210421042
      1042104210421042104210420000000000000000000000000000000000000000
      00008B41246A8359A518C6188C31000000000000104218631863186318631863
      1863186318631042000000000000000000000000000010421042104200000000
      0000000000000000186310420000000010420000000000001042F75EF75EF75E
      F75EF75EF75EF75EF75E10420000000000000000000000000000000000000000
      8C31C6184741877A6576434DC6188C310000000010421863067E186318631863
      1863186318631042000000000000000000000000000018631042104210420000
      0000000000000000FF7F18631042000000000000000000001042F75EAD35F75E
      AD35F75EAD35F75EF75E10420000000000000000000000000000000000000000
      4A294641C87EE97EC87E67722729292500000000104218631863104210421042
      1863186318631042000000000000000000000000000000001863104210421042
      00000000000000000000FF7F1863104200000000000000001042F75EA57DF75E
      A57DF75EA57DF75EF75E10420000000000000000000000000000000000000000
      000031460C4ACA72E97E87764A2D000000000000104218631863186318631863
      1863186318631042000000000000000000000000000000000000000018630000
      0000000000000000000000000000000000000000000000001042F75EF75EF75E
      F75EF75EF75EF75EF75E10420000000000000000000000000000000000000000
      00000000734E734E10426A5E8676B36200000000067E0D000D000D000D000D00
      0D00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000067E0D000D000D00
      0D000D000D000000000000000000000000000000000000000000000000000000
      000000000000524A314600000000B36200000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
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
      C781FF81FF81FF81FFCDFFCDFFCDFFCD9CE79CE79CE79CE70000000000000000
      18E718E718E718E7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE707E7
      FFE7FFE7FFE7FBE7FFE7FFE7FFE70BE7FEC7F6C77AC7FAC70707770773070707
      070337036303FF030601160142010601060116016201FA010703370373030703
      078177817B81FF81FFCDFFCDFFCDFFCDFFFFFFFF9CE79CE7FFFFFFFF00000000
      FFFFE00718E718E7FFFFE007FFE7FFE7FFFFE007FFE7FFE7FFFFE007FFE7FFE7
      FFFFE007FFE7FFE7E007E007FFE7FFE7E007E007B6C7FEC7E007E007B707BF07
      E007E007B7038F03E007E007B6018201E007E007B6018201E007E007B7038703
      E007E007B7819F81FFFFFFFFFFCDFFCD9CE78000FFFFFFFF00008000F9F3FFFF
      18E7FFFFF0E1FFFFFFE7FFF1F843FFFFFFE7FFFFFC07FFFFFFE7FE03FE0FFFFF
      FFE7FFFFFE0FFFFFFFE7F007FC07FFFFFEC7FFFFD841FFFFFF07801F80E0E007
      FF03801FC1E6E007FE01801FC3E3E007FE01801FE1F1E007FF03801FFBFFE007
      FF81801FFFFFE007FFCDFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object imlCommandsHot: TImageList
    Height = 32
    Width = 32
    Left = 72
    Top = 65521
    Bitmap = {
      494C010107000900040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000800000006000000001001000000000000060
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F0000FF7FFF7FFF7FFF7FFF7FFF7F0000FF7FFF7FFF7F0000
      FF7FFF7FFF7F0000FF7FFF7FFF7FFF7FFF7FFF7FFF7F0000FF7FFF7FFF7FFF7F
      0000FF7FFF7FFF7F0000FF7FFF7F0000FF7FFF7FFF7F0000FF7FFF7F00000000
      FF7FFF7F0000FF7FFF7FFF7FFF7F0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3DFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EEF3D0000F75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EA839EF3DFF7FF75EF75EEF3D0000F75EF75EEF3D0000FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75E
      F75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F000000000000FF7F
      FF7F00000000FF7F00000000FF7FFF7FFF7FFF7FFF7F0000FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EEF3DFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D0000
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3D0000F75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EA839EF3DFF7FF75EF75EEF3D0000F75EF75EEF3D0000
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EF3DF75EF75EF75EF75EFF7FFF7FFF7F0000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      000000000000FF7FFF7FFF7F00000000000000000000FF7FFF7FFF7FFF7F0000
      FF7FFF7FFF7FFF7FFF7F0000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75E
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FA839EF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEF3DEF3DEF3DF75EF75EFF7FFF7FFF7F0000FF7FFF7FFF7F
      0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000FF7FFF7FFF7FFF7F
      FF7FFF7FFF7F0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EEF3DF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FEF3DF75EF75EF75EFF7FFF7FFF7F
      FF7F0000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F00000000000000000000FF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EEF3D0000F75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EA839EF3DFF7F
      F75EF75EEF3D0000F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FEF3DFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75E
      F75EF75EF75EEF3DFF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3DFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EEF3D0000F75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EEF3DFF7FF75EF75EEF3D0000F75EF75EEF3D0000FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FEF3DEF3DEF3DEF3D
      EF3DFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75E
      F75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EEF3D0000
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EEF3D0000F75EF75EEF3D0000
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EF3DEF3DEF3DEF3DEF3DFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EEF3DFF7FF75EF75EF75EF75EF75EEF3DFF7FF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3D0000F75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EEF3DFF7FF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F7B6FFF7FF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
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
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EF75EF75EF75EF75E
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEF3DEF3DEF3DEF3DEF3DFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F00000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A5140000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FA5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E8C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C31FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524AFF7F524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524AFF7F524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524AFF7F524A
      8C318C31524A524A524A524A524A524A524AFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000FF7F524A8C318C318C310000
      0000000000000000FF7F524A8C318C318C31000000000000000000000000FF7F
      524A8C31A5140000000000000000000000000000FF7F524A8C318C318C310000
      0000000000000000FF7F524A8C318C318C31000000000000000000000000FF7F
      524A8C31A5140000000000000000000000000000FF7F524A8C318C318C310000
      0000000000000000FF7F524A8C318C318C31000000000000000000000000FF7F
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3DFF7FF75EF75EF75EF75EF75EF75EF75E00000000FF7F524A8C3100000000
      00000000000000000000FF7F524A8C3100000000000000000000000000000000
      524A8C31A51400000000000000000000000000000000FF7F524A8C3100000000
      00000000000000000000FF7F524A8C3100000000000000000000000000000000
      524A8C31A51400000000000000000000000000000000FF7F524A8C3100000000
      00000000000000000000FF7F524A8C3100000000000000000000000000000000
      524A8C31A5140000000000000000000000000000F75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EA839EF3DFF7FF75EF75EEF3D0000F75E0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75E
      F75EF75EF75EF75EF75EF75EF75EEF3DFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E0000000000000000000000000000
      000000000000000000000000000052660000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000300030
      003000000000000000000000000052660000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000000000
      000000000000000000000000000052660000000000000000000000000000524A
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      00000000003000300000000000004C4A8549526600000000000000008C31A514
      8C318C31A5140000000000000000000000000000000000000000000000300030
      00300000000000000000000000004C4A8549526600000000000000008C31A514
      8C318C31A5140000000000000000000000000000000000000030003000300030
      00300030003000300030003000004C4A8549526600000000000000008C31A514
      8C318C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000003000000000000000000000
      000000000030003000000000000000004C4A85494C4A000000008C31A514A514
      A5148C31A5140000000000000000000000000000000000000000007C007C007C
      003000000000000000000000000000004C4A85494C4A000000008C31A514A514
      A5148C31A5140000000000000000000000000000000000000000003000300030
      003000300030003000300000000000004C4A85494C4A000000008C31A514A514
      A5148C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7F007C003000300000000000000000
      0000007C007C0030000000000000000000004C4A854985498531A514A514A514
      A514A5148C310000000000000000000000000000000000000000007C007C007C
      0000000000000000000000000000000000004C4A854985498531A514A514A514
      A514A5148C3100000000000000000000000000000000007C007C007C007C007C
      007C007C007C007C007C00000000000000004C4A854985498531A514A514A514
      A514A5148C31000000000000000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EA839EF3DFF7F
      F75EF75EEF3D0000F75EF75EEF3D0000FF7F007C007C00300030000000000000
      0000007C007C00300000000000000000000000008549856585498549A514A514
      A514A514A5148C31000000000000000000000000000000000000000000300030
      00000000000000000000000000000000000000008549856585498549A514A514
      A514A514A5148C3100000000000000000000000000000000007C007C007C007C
      007C007C007C007C0000000000000000000000008549856585498549A514A514
      A514A514A5148C3100000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75E
      F75EF75EF75EEF3DFF7FF75EF75EF75EF75E007C007C007C0030003000000000
      0000007C007C00300000000000000000000000008C4985494566456685658531
      A514A514A514A5148C3100000000000000000000000000000000007C007C007C
      00300000000000000000000000000000000000008C4985494566456685658531
      A514A514A514A5148C310000000000000000000000000000007C007C007C007C
      007C007C007C007C0000000000000000000000008C4985494566456685658531
      A514A514A514A5148C310000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C007C007C003000300000
      0000007C007C0030000000000000000000008C31A51485314566457E457E4566
      85658531A514A514A5148C310000000000000000000000000000007C007C007C
      0030003000000000000000000000000000008C31A51485314566457E457E4566
      85658531A514A514A5148C310000000000000000000000000000007C007C007C
      007C007C007C0000000000000000000000008C31A51485314566457E457E4566
      85658531A514A514A5148C31000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C007C007C007C00300030
      0000007C007C003000000000000000008C31A514A5148C318C494C7E4C7E4C7E
      457E45668549A530A514A5148C310000000000000000000000000000007C007C
      007C00300030000000000000000000008C31A514A5148C318C494C7E4C7E4C7E
      457E45668549A530A514A5148C310000000000000000000000000000007C007C
      007C007C0000000000000000000000008C31A514A5148C318C494C7E4C7E4C7E
      457E45668549A530A514A5148C3100000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F0000FF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C007C007C007C007C0030
      0000007C007C00300000000000008C31A514A5148C318C3185494C7E2C7F2C7F
      4C7E4C7E457E45668549A514A514524A000000000000000000000000007C007C
      007C007C003000000000000000008C31A514A5148C318C3185494C7E2C7F2C7F
      4C7E4C7E457E45668549A514A514524A0000000000000000000000000000007C
      007C0030003000000000000000008C31A514A5148C318C3185494C7E2C7F2C7F
      4C7E4C7E457E45668549A514A514524A0000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E007C007C007C007C007C007C0000
      0000007C007C003000000000000000008C318C31854945662C7F2C7F2C7F2C7F
      2C7F2C7F4C7E85498C31A5148C3100000000000000000030003000480000007C
      007C007C007C003000000000000000008C318C31854945662C7F2C7F2C7F2C7F
      2C7F2C7F4C7E85498C31A5148C3100000000000000000000000000000030007C
      007C00300030003000000000000000008C318C31854945662C7F2C7F2C7F2C7F
      2C7F2C7F4C7E85498C31A5148C3100000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C007C007C007C00000000
      0000007C007C0030000000000000000000008C318C494C662C7F2C7F2C7F2C7F
      2C7F2C7F85498C318C318C310000000000000000000000300030004800000000
      007C007C007C0030003000000000000000008C318C494C662C7F2C7F2C7F2C7F
      2C7F2C7F85498C318C318C3100000000000000000000000000000030007C007C
      007C007C00300030003000000000000000008C318C494C662C7F2C7F2C7F2C7F
      2C7F2C7F85498C318C318C31000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C007C007C000000000000
      0000007C007C0030000000000000000000000000524A8C314C4A4C662C7F2C7F
      2C7F2C7F4C7E85498C3100000000000000000000007C007C007C003000480000
      0030007C007C007C003000000000000000000000524A8C314C4A4C662C7F2C7F
      2C7F2C7F4C7E85498C3100000000000000000000000000000000007C007C007C
      007C007C007C0030003000000000000000000000524A8C314C4A4C662C7F2C7F
      2C7F2C7F4C7E85498C310000000000000000FF7F0000FF7FFF7F0000FF7FFF7F
      FF7FFF7FFF7FFF7FFF7F0000FF7FFF7FFF7F0000FF7FFF7FFF7F0000FF7FFF7F
      FF7FFF7F0000FF7FFF7FFF7F0000FF7FFF7F007C007C007C0000000000000000
      0000007C007C00300000000000000000000000000000524A524A524A524A524A
      4C662C7F2C7F4C7E4C6632670000000000000000007C007C007C003000300030
      0030007C007C007C0000000000000000000000000000524A524A524A524A524A
      4C662C7F2C7F4C7E4C663267000000000000000000000000007C007C007C007C
      007C007C007C007C0030003000000000000000000000524A524A524A524A524A
      4C662C7F2C7F4C7E4C663267000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E007C007C00000000000000000000
      0000007C007C000000000000000000000000000000000000524A524A524A524A
      524A4C4A4C662C7F457E456652660000000000000000007C007C007C00300030
      007C007C007C000000000000000000000000000000000000524A524A524A524A
      524A4C4A4C662C7F457E4566526600000000000000000000007C007C007C007C
      007C007C007C007C00000000000000000000000000000000524A524A524A524A
      524A4C4A4C662C7F457E4566526600000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C000000000000000000000000
      0000007C007C0000000000000000000000000000000000000000524A524A524A
      8C31524A0000000032674C7E45665266000000000000007C007C007C007C007C
      007C007C007C0000000000000000000000000000000000000000524A524A524A
      8C31524A0000000032674C7E45665266000000000000007C007C007C007C007C
      007C007C007C007C007C00000000000000000000000000000000524A524A524A
      8C31524A0000000032674C7E456652660000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A0000000000000000000052664C6600000000000000000000007C007C007C
      007C0000000000000000000000000000000000000000000000000000524A8C31
      524A0000000000000000000052664C6600000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A0000000000000000000052664C660000FF7FFF7F7B6FFF7FF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EF75EF75EF75EF75E
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      000000000000000000000000000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7F00000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A5140000000000000000000000000000A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A5148C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C31524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524AFF7F524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524AFF7F524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524AFF7F524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524AFF7F524A
      8C318C31524A524A524A524A524A524A524A0000FF7F524A8C318C318C310000
      0000000000000000FF7F524A8C318C318C31000000000000000000000000FF7F
      524A8C31A5140000000000000000000000000000FF7F524A8C318C318C310000
      0000000000000000FF7F524A8C318C318C31000000000000000000000000FF7F
      524A8C31A5140000000000000000000000000000FF7F524A8C318C318C310000
      0000000000000000FF7F524A8C318C318C31000000000000000000000000FF7F
      524A8C31A5140000000000000000000000000000FF7F524A8C318C318C310000
      0000000000000000FF7F524A8C318C318C31000000000000000000000000FF7F
      524A8C31A51400000000000000000000000000000000FF7F524A8C3100000000
      00000000000000000000FF7F524A8C3100000000000000000000000000000000
      524A8C31A51400000000000000000000000000000000FF7F524A8C3100000000
      00000000000000000000FF7F524A8C3100000000000000000000000000000000
      524A8C31A51400000000000000000000000000000000FF7F524A8C3100000000
      00000000000000000000FF7F524A8C3100000000000000000000000000000000
      524A8C31A51400000000000000000000000000000000FF7F524A8C3100000000
      00000000000000000000FF7F524A8C3100000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      000000000000000000000000000052660000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000000000
      000000000000000000000000000052660000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000000000
      000000000000000000000000000052660000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000000000
      000000000000000000000000000052660000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000003000300000000000000000
      00000000000000000000004800004C4A8549526600000000000000008C31A514
      8C318C31A5140000000000000000000000000000000000000000000000000000
      00000000000000000000000000004C4A8549526600000000000000008C31A514
      8C318C31A5140000000000000000000000000000000000000030003000000000
      00000000003000300000000000004C4A8549526600000000000000008C31A514
      8C318C31A5140000000000000000000000000000000000000000000000000000
      00000000000000000000000000004C4A8549526600000000000000008C31A514
      8C318C31A5140000000000000000000000000000003000300000000000000000
      000000000000000000300048000000004C4A85494C4A000000008C31A514A514
      A5148C31A5140000000000000000000000000000000000000000000000000000
      000000000000000000000000000000004C4A85494C4A000000008C31A514A514
      A5148C31A5140000000000000000000000000000000000000030003000000000
      000000000030003000000000000000004C4A85494C4A000000008C31A514A514
      A5148C31A5140000000000000000000000000000003000300030003000300030
      003000300030003000000000000000004C4A85494C4A000000008C31A514A514
      A5148C31A514000000000000000000000000007C007C00300000000000000000
      0000000000000048007C00480000000000004C4A854985498531A514A514A514
      A514A5148C310000000000000000000000000000000000000048004800000000
      0000000000000000000000000000000000004C4A854985498531A514A514A514
      A514A5148C3100000000000000000000000000000000007C007C003000000000
      0000007C007C0030000000000000000000004C4A854985498531A514A514A514
      A514A5148C310000000000000000000000000000003000300030003000300030
      0030003000300030000000000000000000004C4A854985498531A514A514A514
      A514A5148C31000000000000000000000000007C007C00300000000000000000
      000000000048007C007C004800000000000000008549856585498549A514A514
      A514A514A5148C31000000000000000000000000000000000030003000480048
      00000000000000000000000000000000000000008549856585498549A514A514
      A514A514A5148C310000000000000000000000000000007C007C003000000000
      0000007C007C00300000000000000000000000008549856585498549A514A514
      A514A514A5148C3100000000000000000000007C007C007C007C007C007C007C
      007C007C007C00300000000000000000000000008549856585498549A514A514
      A514A514A5148C3100000000000000000000007C007C00300000000000000000
      00000048007C007C007C004800000000000000008C4985494566456685658531
      A514A514A514A5148C31000000000000000000000000007C007C003000300030
      00300048000000000000000000000000000000008C4985494566456685658531
      A514A514A514A5148C31000000000000000000000000007C007C003000000000
      0000007C007C00300000000000000000000000008C4985494566456685658531
      A514A514A514A5148C310000000000000000007C007C007C007C007C007C007C
      007C007C007C00300000000000000000000000008C4985494566456685658531
      A514A514A514A5148C310000000000000000007C007C00300000000000000000
      0048007C007C007C007C00480000000000008C31A51485314566457E457E4566
      85658531A514A514A5148C3100000000000000000000007C007C007C007C0030
      0030003000300048000000000000000000008C31A51485314566457E457E4566
      85658531A514A514A5148C3100000000000000000000007C007C003000000000
      0000007C007C0030000000000000000000008C31A51485314566457E457E4566
      85658531A514A514A5148C31000000000000007C007C007C007C007C007C007C
      007C007C007C0030000000000000000000008C31A51485314566457E457E4566
      85658531A514A514A5148C31000000000000007C007C00300000000000000048
      007C007C007C007C007C0048000000008C31A514A5148C318C494C7E4C7E4C7E
      457E45668549A530A514A5148C310000000000000000007C007C007C007C007C
      007C00300030003000300048000000008C31A514A5148C318C494C7E4C7E4C7E
      457E45668549A530A514A5148C310000000000000000007C007C003000000000
      0000007C007C003000000000000000008C31A514A5148C318C494C7E4C7E4C7E
      457E45668549A530A514A5148C3100000000007C007C007C007C007C007C007C
      007C007C007C003000000000000000008C31A514A5148C318C494C7E4C7E4C7E
      457E45668549A530A514A5148C3100000000007C007C0030000000000000007C
      007C007C007C007C007C004800008C31A514A5148C318C3185494C7E2C7F2C7F
      4C7E4C7E457E45668549A514A514524A000000000000007C007C007C007C007C
      007C007C007C00300030003000008C31A514A5148C318C3185494C7E2C7F2C7F
      4C7E4C7E457E45668549A514A514524A000000000000007C007C003000000000
      0000007C007C00300000000000008C31A514A5148C318C3185494C7E2C7F2C7F
      4C7E4C7E457E45668549A514A514524A0000007C007C007C007C007C007C007C
      007C007C007C00300000000000008C31A514A5148C318C3185494C7E2C7F2C7F
      4C7E4C7E457E45668549A514A514524A0000007C007C0030000000000000007C
      007C007C007C007C007C0048000000008C318C31854945662C7F2C7F2C7F2C7F
      2C7F2C7F4C7E85498C31A5148C310000000000000000007C007C007C007C007C
      007C007C007C007C007C0000000000008C318C31854945662C7F2C7F2C7F2C7F
      2C7F2C7F4C7E85498C31A5148C310000000000000000007C007C003000000000
      0000007C007C003000000000000000008C318C31854945662C7F2C7F2C7F2C7F
      2C7F2C7F4C7E85498C31A5148C3100000000007C007C007C007C007C007C007C
      007C007C007C003000000000000000008C318C31854945662C7F2C7F2C7F2C7F
      2C7F2C7F4C7E85498C31A5148C3100000000007C007C00300000000000000000
      007C007C007C007C007C00480000000000008C318C494C662C7F2C7F2C7F2C7F
      2C7F2C7F85498C318C318C3100000000000000000000007C007C007C007C007C
      007C007C007C007C007C00000000000000008C318C494C662C7F2C7F2C7F2C7F
      2C7F2C7F85498C318C318C3100000000000000000000007C007C003000000000
      0000007C007C0030000000000000000000008C318C494C662C7F2C7F2C7F2C7F
      2C7F2C7F85498C318C318C31000000000000007C007C007C007C007C007C007C
      007C007C007C0030000000000000000000008C318C494C662C7F2C7F2C7F2C7F
      2C7F2C7F85498C318C318C31000000000000007C007C00300000000000000000
      0000007C007C007C007C00480000000000000000524A8C314C4A4C662C7F2C7F
      2C7F2C7F4C7E85498C31000000000000000000000000007C007C007C007C007C
      007C007C007C0000000000000000000000000000524A8C314C4A4C662C7F2C7F
      2C7F2C7F4C7E85498C31000000000000000000000000007C007C003000000000
      0000007C007C0030000000000000000000000000524A8C314C4A4C662C7F2C7F
      2C7F2C7F4C7E85498C310000000000000000007C007C007C007C007C007C007C
      007C007C007C0030000000000000000000000000524A8C314C4A4C662C7F2C7F
      2C7F2C7F4C7E85498C310000000000000000007C007C00300000000000000000
      00000000007C007C007C004800000000000000000000524A524A524A524A524A
      4C662C7F2C7F4C7E4C66326700000000000000000000007C007C007C007C007C
      007C0000000000000000000000000000000000000000524A524A524A524A524A
      4C662C7F2C7F4C7E4C66326700000000000000000000007C007C003000000000
      0000007C007C00300000000000000000000000000000524A524A524A524A524A
      4C662C7F2C7F4C7E4C663267000000000000007C007C007C007C007C007C007C
      007C007C007C00300000000000000000000000000000524A524A524A524A524A
      4C662C7F2C7F4C7E4C663267000000000000007C007C00000000000000000000
      000000000000007C007C0000000000000000000000000000524A524A524A524A
      524A4C4A4C662C7F457E456652660000000000000000007C007C007C007C0000
      000000000000000000000000000000000000000000000000524A524A524A524A
      524A4C4A4C662C7F457E456652660000000000000000007C007C000000000000
      0000007C007C000000000000000000000000000000000000524A524A524A524A
      524A4C4A4C662C7F457E4566526600000000007C007C007C007C007C007C007C
      007C007C007C000000000000000000000000000000000000524A524A524A524A
      524A4C4A4C662C7F457E4566526600000000007C007C00000000000000000000
      0000000000000000007C00000000000000000000000000000000524A524A524A
      8C31524A0000000032674C7E45665266000000000000007C007C000000000000
      0000000000000000000000000000000000000000000000000000524A524A524A
      8C31524A0000000032674C7E45665266000000000000007C007C000000000000
      0000007C007C0000000000000000000000000000000000000000524A524A524A
      8C31524A0000000032674C7E456652660000007C007C007C007C007C007C007C
      007C007C007C0000000000000000000000000000000000000000524A524A524A
      8C31524A0000000032674C7E4566526600000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A0000000000000000000052664C6600000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A0000000000000000000052664C6600000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A0000000000000000000052664C6600000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A0000000000000000000052664C6600000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
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
      0000000000003600000028000000800000006000000001001000000000000060
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
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
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000EF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3D
      EF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
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
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EA839A839A839A839F75EF75EF75EF75EA839A839A839A839F75E
      F75EF75EF75EA839A839A839A839F75EF75EF75EEF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
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
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EA839EF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EA839EF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FA839EF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EA839EF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E00000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A5140000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FA5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F8C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C31FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524A0000524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524A0000524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524A0000524A
      8C318C31524A524A524A524A524A524A524AF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E00000000524A8C318C318C310000
      00000000000000000000524A8C318C318C310000000000000000000000000000
      524A8C31A51400000000000000000000000000000000524A8C318C318C310000
      00000000000000000000524A8C318C318C310000000000000000000000000000
      524A8C31A51400000000000000000000000000000000524A8C318C318C310000
      00000000000000000000524A8C318C318C310000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F000000000000524A8C3100000000
      000000000000000000000000524A8C3100000000000000000000000000000000
      524A8C31A514000000000000000000000000000000000000524A8C3100000000
      000000000000000000000000524A8C3100000000000000000000000000000000
      524A8C31A514000000000000000000000000000000000000524A8C3100000000
      000000000000000000000000524A8C3100000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75E0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000524A0000000000000000000000000000524A
      524A8C31A51400000000000000000000000000000000000000000000A514A514
      A514000000000000000000000000524A0000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000524A0000000000000000000000000000524A
      524A8C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      00000000A514A514000000000000524A8C31524A00000000000000008C31A514
      8C318C31A51400000000000000000000000000000000000000000000A514A514
      A514000000000000000000000000524A8C31524A00000000000000008C31A514
      8C318C31A514000000000000000000000000000000000000A514A514A514A514
      A514A514A514A514A514A5140000524A8C31524A00000000000000008C31A514
      8C318C31A514000000000000000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75E0000A51400000000000000000000
      00000000A514A5140000000000000000524A8C31524A000000008C31A514A514
      A5148C31A5140000000000000000000000000000000000000000524A524A524A
      A5140000000000000000000000000000524A8C31524A000000008C31A514A514
      A5148C31A5140000000000000000000000000000000000000000A514A514A514
      A514A514A514A514A514000000000000524A8C31524A000000008C31A514A514
      A5148C31A514000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524AA514A5140000000000000000
      0000524A524AA51400000000000000000000524A8C318C318C31A514A514A514
      A514A5148C310000000000000000000000000000000000000000524A524A524A
      000000000000000000000000000000000000524A8C318C318C31A514A514A514
      A514A5148C3100000000000000000000000000000000524A524A524A524A524A
      524A524A524A524A524A0000000000000000524A8C318C318C31A514A514A514
      A514A5148C31000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524AA514A514000000000000
      0000524A524AA5140000000000000000000000008C31524A8C318C31A514A514
      A514A514A5148C310000000000000000000000000000000000000000A514A514
      00000000000000000000000000000000000000008C31524A8C318C31A514A514
      A514A514A5148C3100000000000000000000000000000000524A524A524A524A
      524A524A524A524A0000000000000000000000008C31524A8C318C31A514A514
      A514A514A5148C3100000000000000000000F75EF75EF75EEF3DFF7FF75EF75E
      F75EF75EF75EF75EF75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A524AA514A51400000000
      0000524A524AA5140000000000000000000000008C318C31524A524A524A8C31
      8C318C318C31A5148C3100000000000000000000000000000000524A524A524A
      A5140000000000000000000000000000000000008C318C31524A524A524A8C31
      8C318C318C31A5148C310000000000000000000000000000524A524A524A524A
      524A524A524A524A0000000000000000000000008C318C31524A524A524A8C31
      8C318C318C31A5148C310000000000000000A839EF3DFF7FF75EF75EEF3D0000
      F75EF75EEF3D0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A524A524AA514A5140000
      0000524A524AA514000000000000000000008C31A5148C31524A3967524A524A
      524A8C318C318C31A5148C310000000000000000000000000000524A524A524A
      A514A51400000000000000000000000000008C31A5148C31524A3967524A524A
      524A8C318C318C31A5148C310000000000000000000000000000524A524A524A
      524A524A524A0000000000000000000000008C31A5148C31524A3967524A524A
      524A8C318C318C31A5148C31000000000000F75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E524A524A524A524A524AA514A514
      0000524A524AA51400000000000000008C31A5148C318C318C31396739673967
      3967524A8C318C318C31A5148C310000000000000000000000000000524A524A
      524AA514A514000000000000000000008C31A5148C318C318C31396739673967
      3967524A8C318C318C31A5148C310000000000000000000000000000524A524A
      524A524A0000000000000000000000008C31A5148C318C318C31396739673967
      3967524A8C318C318C31A5148C3100000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A524A524A524A524AA514
      0000524A524AA5140000000000008C31A5148C318C318C318C31396739673967
      396739673967524A8C318C31A514524A000000000000000000000000524A524A
      524A524AA51400000000000000008C31A5148C318C318C318C31396739673967
      396739673967524A8C318C31A514524A0000000000000000000000000000524A
      524AA514A51400000000000000008C31A5148C318C318C318C31396739673967
      396739673967524A8C318C31A514524A0000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A524A524A524A524A0000
      0000524A524AA51400000000000000008C318C318C31524A3967396739673967
      3967396739678C318C318C318C310000000000000000A514A514A5140000524A
      524A524A524AA51400000000000000008C318C318C31524A3967396739673967
      3967396739678C318C318C318C310000000000000000000000000000A514524A
      524AA514A514A51400000000000000008C318C318C31524A3967396739673967
      3967396739678C318C318C318C3100000000EF3DEF3DFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A524A524A524A00000000
      0000524A524AA514000000000000000000008C318C3139673967396739673967
      396739678C318C318C318C3100000000000000000000A514A514A51400000000
      524A524A524AA514A51400000000000000008C318C3139673967396739673967
      396739678C318C318C318C310000000000000000000000000000A514524A524A
      524A524AA514A514A51400000000000000008C318C3139673967396739673967
      396739678C318C318C318C31000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E524A524A524A524A000000000000
      0000524A524AA514000000000000000000000000524A8C31524A524A39673967
      3967396739678C318C3100000000000000000000524A524A524AA514A5140000
      A514524A524A524AA51400000000000000000000524A8C31524A524A39673967
      3967396739678C318C3100000000000000000000000000000000524A524A524A
      524A524A524AA514A51400000000000000000000524A8C31524A524A39673967
      3967396739678C318C310000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A524A0000000000000000
      0000524A524AA5140000000000000000000000000000524A524A524A524A524A
      3967396739673967396739670000000000000000524A524A524AA514A514A514
      A514524A524A524A0000000000000000000000000000524A524A524A524A524A
      396739673967396739673967000000000000000000000000524A524A524A524A
      524A524A524A524AA514A51400000000000000000000524A524A524A524A524A
      396739673967396739673967000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A524A00000000000000000000
      0000524A524A000000000000000000000000000000000000524A524A524A524A
      524A524A524A39673967524A39670000000000000000524A524A524AA514A514
      524A524A524A000000000000000000000000000000000000524A524A524A524A
      524A524A524A39673967524A396700000000000000000000524A524A524A524A
      524A524A524A524A00000000000000000000000000000000524A524A524A524A
      524A524A524A39673967524A396700000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F0000FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7B6F
      FF7FF75EF75EF75EF75EF75EF75EF75EF75E524A000000000000000000000000
      0000524A524A0000000000000000000000000000000000000000524A524A524A
      8C31524A0000000039673967524A3967000000000000524A524A524A524A524A
      524A524A524A0000000000000000000000000000000000000000524A524A524A
      8C31524A0000000039673967524A3967000000000000524A524A524A524A524A
      524A524A524A524A524A00000000000000000000000000000000524A524A524A
      8C31524A0000000039673967524A39670000F75EF75EF75EF75EF75EF75EF75E
      EF3D0000F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E0000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A000000000000000000003967396700000000000000000000524A524A524A
      524A0000000000000000000000000000000000000000000000000000524A8C31
      524A000000000000000000003967396700000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A00000000000000000000396739670000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F7B6FFF7FF75EF75E0000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F00000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A514000000000000000000000000000000000000A514A514A51400000000
      00000000000000000000A514A514A5140000000000000000000000000000A514
      A514A5140000000000000000000000000000A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A514A5148C318C318C318C31A514A514
      A514A514A514A5148C318C318C318C31A514A514A514A514A514A514A5148C31
      8C31A514A514A514A514A514A514A514A5148C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C318C31524A8C318C318C318C31A514
      8C318C318C318C31524A8C318C318C318C31A5148C318C318C318C31524A8C31
      8C318C31A5148C318C318C318C318C318C31524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524A0000524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524A0000524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524A0000524A
      8C318C31524A524A524A524A524A524A524A524A524A8C318C318C318C31524A
      524A524A524A524A524A8C318C318C318C31524A524A524A524A524A0000524A
      8C318C31524A524A524A524A524A524A524A00000000524A8C318C318C310000
      00000000000000000000524A8C318C318C310000000000000000000000000000
      524A8C31A51400000000000000000000000000000000524A8C318C318C310000
      00000000000000000000524A8C318C318C310000000000000000000000000000
      524A8C31A51400000000000000000000000000000000524A8C318C318C310000
      00000000000000000000524A8C318C318C310000000000000000000000000000
      524A8C31A51400000000000000000000000000000000524A8C318C318C310000
      00000000000000000000524A8C318C318C310000000000000000000000000000
      524A8C31A514000000000000000000000000000000000000524A8C3100000000
      000000000000000000000000524A8C3100000000000000000000000000000000
      524A8C31A514000000000000000000000000000000000000524A8C3100000000
      000000000000000000000000524A8C3100000000000000000000000000000000
      524A8C31A514000000000000000000000000000000000000524A8C3100000000
      000000000000000000000000524A8C3100000000000000000000000000000000
      524A8C31A514000000000000000000000000000000000000524A8C3100000000
      000000000000000000000000524A8C3100000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000524A0000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000524A0000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000524A0000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000524A0000000000000000000000000000524A
      524A8C31A5140000000000000000000000000000A514A5140000000000000000
      00000000000000000000A5140000524A8C31524A00000000000000008C31A514
      8C318C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000524A8C31524A00000000000000008C31A514
      8C318C31A514000000000000000000000000000000000000A514A51400000000
      00000000A514A514000000000000524A8C31524A00000000000000008C31A514
      8C318C31A5140000000000000000000000000000000000000000000000000000
      0000000000000000000000000000524A8C31524A00000000000000008C31A514
      8C318C31A5140000000000000000000000000000A514A5140000000000000000
      0000000000000000A514A51400000000524A8C31524A000000008C31A514A514
      A5148C31A5140000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000524A8C31524A000000008C31A514A514
      A5148C31A514000000000000000000000000000000000000A514A51400000000
      00000000A514A5140000000000000000524A8C31524A000000008C31A514A514
      A5148C31A5140000000000000000000000000000A514A514A514A514A514A514
      A514A514A514A5140000000000000000524A8C31524A000000008C31A514A514
      A5148C31A514000000000000000000000000524A524AA5140000000000000000
      000000000000A514524AA514000000000000524A8C318C318C31A514A514A514
      A514A5148C31000000000000000000000000000000000000A514A51400000000
      000000000000000000000000000000000000524A8C318C318C31A514A514A514
      A514A5148C3100000000000000000000000000000000524A524AA51400000000
      0000524A524AA51400000000000000000000524A8C318C318C31A514A514A514
      A514A5148C310000000000000000000000000000A514A514A514A514A514A514
      A514A514A514A51400000000000000000000524A8C318C318C31A514A514A514
      A514A5148C31000000000000000000000000524A524AA5140000000000000000
      00000000A514524A524AA51400000000000000008C31524A8C318C31A514A514
      A514A514A5148C3100000000000000000000000000000000A514A514A514A514
      00000000000000000000000000000000000000008C31524A8C318C31A514A514
      A514A514A5148C310000000000000000000000000000524A524AA51400000000
      0000524A524AA5140000000000000000000000008C31524A8C318C31A514A514
      A514A514A5148C3100000000000000000000524A524A524A524A524A524A524A
      524A524A524AA5140000000000000000000000008C31524A8C318C31A514A514
      A514A514A5148C3100000000000000000000524A524AA5140000000000000000
      0000A514524A524A524AA51400000000000000008C318C31524A524A524A8C31
      8C318C318C31A5148C31000000000000000000000000524A524AA514A514A514
      A514A514000000000000000000000000000000008C318C31524A524A524A8C31
      8C318C318C31A5148C31000000000000000000000000524A524AA51400000000
      0000524A524AA5140000000000000000000000008C318C31524A524A524A8C31
      8C318C318C31A5148C310000000000000000524A524A524A524A524A524A524A
      524A524A524AA5140000000000000000000000008C318C31524A524A524A8C31
      8C318C318C31A5148C310000000000000000524A524AA5140000000000000000
      A514524A524A524A524AA5140000000000008C31A5148C31524A3967524A524A
      524A8C318C318C31A5148C3100000000000000000000524A524A524A524AA514
      A514A514A514A514000000000000000000008C31A5148C31524A3967524A524A
      524A8C318C318C31A5148C3100000000000000000000524A524AA51400000000
      0000524A524AA514000000000000000000008C31A5148C31524A3967524A524A
      524A8C318C318C31A5148C31000000000000524A524A524A524A524A524A524A
      524A524A524AA514000000000000000000008C31A5148C31524A3967524A524A
      524A8C318C318C31A5148C31000000000000524A524AA514000000000000A514
      524A524A524A524A524AA514000000008C31A5148C318C318C31396739673967
      3967524A8C318C318C31A5148C310000000000000000524A524A524A524A524A
      524AA514A514A514A514A514000000008C31A5148C318C318C31396739673967
      3967524A8C318C318C31A5148C310000000000000000524A524AA51400000000
      0000524A524AA51400000000000000008C31A5148C318C318C31396739673967
      3967524A8C318C318C31A5148C3100000000524A524A524A524A524A524A524A
      524A524A524AA51400000000000000008C31A5148C318C318C31396739673967
      3967524A8C318C318C31A5148C3100000000524A524AA514000000000000524A
      524A524A524A524A524AA51400008C31A5148C318C318C318C31396739673967
      396739673967524A8C318C31A514524A000000000000524A524A524A524A524A
      524A524A524AA514A514A51400008C31A5148C318C318C318C31396739673967
      396739673967524A8C318C31A514524A000000000000524A524AA51400000000
      0000524A524AA5140000000000008C31A5148C318C318C318C31396739673967
      396739673967524A8C318C31A514524A0000524A524A524A524A524A524A524A
      524A524A524AA5140000000000008C31A5148C318C318C318C31396739673967
      396739673967524A8C318C31A514524A0000524A524AA514000000000000524A
      524A524A524A524A524AA514000000008C318C318C31524A3967396739673967
      3967396739678C318C318C318C310000000000000000524A524A524A524A524A
      524A524A524A524A524A0000000000008C318C318C31524A3967396739673967
      3967396739678C318C318C318C310000000000000000524A524AA51400000000
      0000524A524AA51400000000000000008C318C318C31524A3967396739673967
      3967396739678C318C318C318C3100000000524A524A524A524A524A524A524A
      524A524A524AA51400000000000000008C318C318C31524A3967396739673967
      3967396739678C318C318C318C3100000000524A524AA5140000000000000000
      524A524A524A524A524AA5140000000000008C318C3139673967396739673967
      396739678C318C318C318C3100000000000000000000524A524A524A524A524A
      524A524A524A524A524A00000000000000008C318C3139673967396739673967
      396739678C318C318C318C3100000000000000000000524A524AA51400000000
      0000524A524AA514000000000000000000008C318C3139673967396739673967
      396739678C318C318C318C31000000000000524A524A524A524A524A524A524A
      524A524A524AA514000000000000000000008C318C3139673967396739673967
      396739678C318C318C318C31000000000000524A524AA5140000000000000000
      0000524A524A524A524AA5140000000000000000524A8C31524A524A39673967
      3967396739678C318C31000000000000000000000000524A524A524A524A524A
      524A524A524A0000000000000000000000000000524A8C31524A524A39673967
      3967396739678C318C31000000000000000000000000524A524AA51400000000
      0000524A524AA514000000000000000000000000524A8C31524A524A39673967
      3967396739678C318C310000000000000000524A524A524A524A524A524A524A
      524A524A524AA514000000000000000000000000524A8C31524A524A39673967
      3967396739678C318C310000000000000000524A524AA5140000000000000000
      00000000524A524A524AA51400000000000000000000524A524A524A524A524A
      39673967396739673967396700000000000000000000524A524A524A524A524A
      524A0000000000000000000000000000000000000000524A524A524A524A524A
      39673967396739673967396700000000000000000000524A524AA51400000000
      0000524A524AA5140000000000000000000000000000524A524A524A524A524A
      396739673967396739673967000000000000524A524A524A524A524A524A524A
      524A524A524AA5140000000000000000000000000000524A524A524A524A524A
      396739673967396739673967000000000000524A524A00000000000000000000
      000000000000524A524A0000000000000000000000000000524A524A524A524A
      524A524A524A39673967524A39670000000000000000524A524A524A524A0000
      000000000000000000000000000000000000000000000000524A524A524A524A
      524A524A524A39673967524A39670000000000000000524A524A000000000000
      0000524A524A000000000000000000000000000000000000524A524A524A524A
      524A524A524A39673967524A396700000000524A524A524A524A524A524A524A
      524A524A524A000000000000000000000000000000000000524A524A524A524A
      524A524A524A39673967524A396700000000524A524A00000000000000000000
      0000000000000000524A00000000000000000000000000000000524A524A524A
      8C31524A0000000039673967524A3967000000000000524A524A000000000000
      0000000000000000000000000000000000000000000000000000524A524A524A
      8C31524A0000000039673967524A3967000000000000524A524A000000000000
      0000524A524A0000000000000000000000000000000000000000524A524A524A
      8C31524A0000000039673967524A39670000524A524A524A524A524A524A524A
      524A524A524A0000000000000000000000000000000000000000524A524A524A
      8C31524A0000000039673967524A396700000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A000000000000000000003967396700000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A000000000000000000003967396700000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A000000000000000000003967396700000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524A8C31
      524A000000000000000000003967396700000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
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
      0000000000003600000028000000400000003000000001001000000000000018
      000000000000000000000000000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75E657E00000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75E0000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FA5146B2D6B2D6B2DFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FA514734EFF7FFF7FFF7FA514734EFF7FFF7FFF7F
      A514734EFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F734EA514FF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F6B2D6B2DFF7FFF7FFF7F6B2D6B2DFF7FFF7FFF7F
      734EA514FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F734E6B2D6B2D
      6B2D6B2D734E6B2D6B2D6B2D6B2D734E6B2DFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      734EA514FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F734EA514FF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      734EA514FF7FFF7FFF7FFF7FFF7FFF7FFF7F6B2DFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F654DFF7FFF7F6B2D
      6B2DA514FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F734EA514FF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C
      007C002C002CFF7F6B2DA514654D657E657E654DA5146B2DFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F007C002C002CFF7FFF7FFF7FFF7F6B4D685A6565
      A514A5146B2DFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F002CFF7F
      FF7FFF7FFF7FFF7FFF7F654D652DA514A514FF7FFF7FFF7FFF7FFF7F734E734E
      734E6B66657E7366FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C
      007C007CFF7FFF7FFF7F734E685A2B7F2B7F657E6B2DFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F007C007C007C007C007CFF7F6B2D654D2B7F2B7F
      2B7F657E652D6B2DFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F734E734EFF7FFF7F7366FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F007C007CFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      E03CF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EE03CF75EFF7FF75EFF7F7B6FFF7FF75E
      F75EF75EFF7FF75EFF7FF75EFF7FF75EFF7FF75EFF7FF75EFF7FF75EFF7FF75E
      FF7FF75EFF7FF75EFF7F7B6FFF7FF75EF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EFF7FF75EFF7FF75EFF7FF75E
      FF7FF75EFF7FF75EFF7FF75EFF7FF75EFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FF75EF75EEF3D00007B6FFF7FF75E
      F75EF75EF75EF75EF75EF75EF75EEF3DFF7FF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EEF3D00007B6FFF7FF75EF75EF75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75E0000A514734E000000000000A514
      734E000000000000A514734E0000000000000000A514734E000000000000A514
      734E000000000000A514734E0000000000000000A514734E000000000000A514
      734E000000000000A514734E000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F734E6B2D6B2D6B2D6B2D734E6B2D
      6B2D6B2D6B2D734E6B2DA5146B2D6B2D6B2D734E6B2D6B2D6B2D6B2D734E6B2D
      6B2D6B2D6B2D734E6B2DA5146B2D6B2D6B2D734E6B2D6B2D6B2D6B2D734E6B2D
      6B2D6B2D6B2D734E6B2DA5146B2D6B2D6B2DF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75EFF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000734EA514000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000734EA514000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000734EA514000000006B2DF75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EFF7F0000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA514000000000000734EFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FA514734EFF7F0000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA514000000000000FF7FF75EFF7FF75EFF7FF75EFF7F
      F75EFF7FF75EFF7FF75EFF7FF75EFF7FF75E0000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA514000000000000F75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75E0000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA514000000000000A514FF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F6B2D6B2DFF7F0000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA514000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E0000000000000000002C00000000
      654D000000006B2D6B2DA5140000000000000000000000000000000000000000
      654D000000006B2D6B2DA5140000000000000000000000000000000000000000
      654D000000006B2D6B2DA514000000000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EFF7FFF7FFF7F002C000000000000007C00000000
      0000654D652DA514A5146B2D0000000000000000007C007C007C007C00000000
      0000654D652DA514A5146B2D0000000000000000007C007C007C007C007C0000
      0000654D652DA514A5146B2D000000000000A514FF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C002C00000000007C00000000
      00006B4D685A6565A514A5146B2D00000000007CFF7F007C007CFF7F007C0000
      00006B4D685A6565A514A5146B2D0000000000000000007C007C007C00000000
      00006B4D685A6565A514A5146B2D00000000F75EFF7FF75EFF7FF75EFF7FF75E
      FF7FF75EFF7FF75EFF7FF75EFF7FF75EFF7F007C007C002C0000007C00000000
      6B2DA514654D657E657E654DA5146B2D0000007C007CFF7FFF7F007C007C0000
      6B2DA514654D657E657E654DA5146B2D0000000000000000007C000000000000
      6B2DA514654D657E657E654DA5146B2D0000F75EF75EF75EF75EF75EF75EEF3D
      FF7FF75EF75EF75EF75EF75EF75EF75EF75E007C007C007C0000007C00000000
      6B2D654D2B7F2B7F2B7F657E652D6B2D0000007C007CFF7FFF7F007C007C0000
      6B2D654D2B7F2B7F2B7F657E652D6B2D0000000000000000007C000000000000
      6B2D654D2B7F2B7F2B7F657E652D6B2D0000A514FF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007C007C00000000007C00000000
      0000734E685A2B7F2B7F657E6B2D00000000007CFF7F007C007CFF7F007C0000
      0000734E685A2B7F2B7F657E6B2D0000000000000000007C007C007C00000000
      0000734E685A2B7F2B7F657E6B2D00000000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75EF75EF75EF75E007C000000000000007C00000000
      00000000734E734E734E6B66657E736600000000007C007C007C007C00000000
      00000000734E734E734E6B66657E736600000000007C007C007C007C007C0000
      00000000734E734E734E6B66657E73660000F75EF75EF75EF75EF75EF75EF75E
      F75EF75EF75EF75EF75EF75E0000000000000000000000000000000000000000
      000000000000734E734E00000000736600000000000000000000000000000000
      000000000000734E734E00000000736600000000000000000000000000000000
      000000000000734E734E0000000073660000A514FF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000A514734E000000000000A514
      734E000000000000A514734E0000000000000000A514734E000000000000A514
      734E000000000000A514734E0000000000000000A514734E000000000000A514
      734E000000000000A514734E0000000000000000A514734E000000000000A514
      734E000000000000A514734E000000000000734E6B2D6B2D6B2D6B2D734E6B2D
      6B2D6B2D6B2D734E6B2DA5146B2D6B2D6B2D734E6B2D6B2D6B2D6B2D734E6B2D
      6B2D6B2D6B2D734E6B2DA5146B2D6B2D6B2D734E6B2D6B2D6B2D6B2D734E6B2D
      6B2D6B2D6B2D734E6B2DA5146B2D6B2D6B2D734E6B2D6B2D6B2D6B2D734E6B2D
      6B2D6B2D6B2D734E6B2DA5146B2D6B2D6B2DFF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000734EA514000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000734EA514000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000734EA514000000000000FF7F6B2D6B2D00000000FF7F6B2D
      6B2D000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA5140000000000000000000000000000000000000000
      0000000000000000734EA514000000000000002C0000000000000000002C0000
      654D000000006B2D6B2DA5140000000000000000000000000000000000000000
      654D000000006B2D6B2DA5140000000000000000002C00000000002C00000000
      654D000000006B2D6B2DA5140000000000000000000000000000000000000000
      654D000000006B2D6B2DA514000000000000007C000000000000002C007C0000
      0000654D652DA514A5146B2D0000000000000000002C00000000000000000000
      0000654D652DA514A5146B2D0000000000000000007C00000000007C00000000
      0000654D652DA514A5146B2D000000000000002C002C002C002C002C00000000
      0000654D652DA514A5146B2D000000000000007C00000000002C007C007C0000
      00006B4D685A6565A514A5146B2D000000000000007C002C002C000000000000
      00006B4D685A6565A514A5146B2D000000000000007C00000000007C00000000
      00006B4D685A6565A514A5146B2D00000000007C007C007C007C007C00000000
      00006B4D685A6565A514A5146B2D00000000007C0000002C007C007C007C0000
      6B2DA514654D657E657E654DA5146B2D00000000007C007C007C002C002C0000
      6B2DA514654D657E657E654DA5146B2D00000000007C00000000007C00000000
      6B2DA514654D657E657E654DA5146B2D0000007C007C007C007C007C00000000
      6B2DA514654D657E657E654DA5146B2D0000007C00000000007C007C007C0000
      6B2D654D2B7F2B7F2B7F657E652D6B2D00000000007C007C007C007C007C0000
      6B2D654D2B7F2B7F2B7F657E652D6B2D00000000007C00000000007C00000000
      6B2D654D2B7F2B7F2B7F657E652D6B2D0000007C007C007C007C007C00000000
      6B2D654D2B7F2B7F2B7F657E652D6B2D0000007C000000000000007C007C0000
      0000734E685A2B7F2B7F657E6B2D000000000000007C007C007C007C00000000
      0000734E685A2B7F2B7F657E6B2D000000000000007C00000000007C00000000
      0000734E685A2B7F2B7F657E6B2D00000000007C007C007C007C007C00000000
      0000734E685A2B7F2B7F657E6B2D00000000007C0000000000000000007C0000
      00000000734E734E734E6B66657E736600000000007C007C0000000000000000
      00000000734E734E734E6B66657E736600000000007C00000000007C00000000
      00000000734E734E734E6B66657E73660000007C007C007C007C007C00000000
      00000000734E734E734E6B66657E736600000000000000000000000000000000
      000000000000734E734E00000000736600000000000000000000000000000000
      000000000000734E734E00000000736600000000000000000000000000000000
      000000000000734E734E00000000736600000000000000000000000000000000
      000000000000734E734E0000000073660000424D3E000000000000003E000000
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
