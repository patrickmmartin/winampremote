object frmPlaylist: TfrmPlaylist
  Left = 344
  Top = 274
  Width = 286
  Height = 188
  BorderIcons = [biSystemMenu]
  Caption = 'Playlist'
  Color = clBtnFace
  DragKind = dkDock
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = True
  Position = poDefault
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnEndDock = FormEndDock
  OnShow = FormShow
  OnStartDock = FormStartDock
  PixelsPerInch = 96
  TextHeight = 14
  object lstSongs: TListBox
    Left = 0
    Top = 0
    Width = 278
    Height = 132
    Hint = 'Playlist view -drag files to the desired location'
    Align = alClient
    DragMode = dmAutomatic
    ItemHeight = 13
    Items.Strings = (
      '<songlist unobtained>')
    MultiSelect = True
    PopupMenu = pmnuSongs
    Style = lbOwnerDrawFixed
    TabOrder = 0
    OnDblClick = lstSongsDblClick
    OnDragDrop = lstSongsDragDrop
    OnDragOver = lstSongsDragOver
    OnDrawItem = lstSongsDrawItem
    OnKeyDown = lstSongsKeyDown
    OnMouseMove = lstSongsMouseMove
  end
  object pnlBottom: TPanel
    Left = 0
    Top = 132
    Width = 278
    Height = 28
    Align = alBottom
    AutoSize = True
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'pnlBottom'
    TabOrder = 1
    object pbSongPos: TProgressBar
      Left = 0
      Top = 0
      Width = 274
      Height = 12
      Hint = 'track position - click to move '
      Align = alBottom
      BorderWidth = 1
      Min = 0
      Max = 10000
      Smooth = True
      TabOrder = 0
      OnMouseDown = pbSongPosMouseDown
      OnMouseMove = pbSongPosMouseMove
      OnMouseUp = pbSongPosMouseUp
    end
    object pbListPos: TProgressBar
      Left = 0
      Top = 12
      Width = 274
      Height = 12
      Hint = 'songlist position'
      Align = alBottom
      BorderWidth = 1
      Min = 0
      Max = 10000
      Smooth = True
      TabOrder = 1
    end
  end
  object pmnuSongs: TPopupMenu
    Images = frmMain.imlActions
    OnPopup = pmnuSongsPopup
    Left = 80
    Top = 72
    object mnuRefresh: TMenuItem
      Caption = 'Refresh List'
      ImageIndex = 5
      OnClick = SongsRefresh
    end
    object mnuPlay: TMenuItem
      Caption = 'Play This Item'
      ImageIndex = 7
      OnClick = mnuPlayClick
    end
    object mnuAddFiles: TMenuItem
      Action = frmMain.AddFiles
    end
    object mnuDelete: TMenuItem
      Action = frmMain.Delete
    end
    object Repeat1: TMenuItem
      Action = frmMain.Repeat
    end
    object Shuffle1: TMenuItem
      Action = frmMain.Shuffle
    end
    object mnuSort: TMenuItem
      Caption = 'Sort by title'
      Visible = False
      OnClick = mnuSortClick
    end
    object mnuSortFile: TMenuItem
      Caption = 'Sort by filename'
      Visible = False
      OnClick = mnuSortClick
    end
    object mnuSortFileEntire: TMenuItem
      Caption = 'Sort by entire filename'
      Visible = False
      OnClick = mnuSortClick
    end
  end
end
