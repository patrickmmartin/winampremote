object frmPlaylist: TfrmPlaylist
  Left = 512
  Top = 197
  Width = 423
  Height = 276
  BorderIcons = [biSystemMenu]
  Caption = 'Playlist'
  Color = clBtnFace
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
  OnResize = FormResize
  OnShow = FormShow
  OnStartDock = FormStartDock
  PixelsPerInch = 96
  TextHeight = 14
  object lstSongs: TListBox
    Left = 0
    Top = 0
    Width = 407
    Height = 195
    Hint = 'Playlist view -drag files to the desired location'
    Align = alClient
    BorderStyle = bsNone
    Color = clNone
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
    Top = 195
    Width = 407
    Height = 24
    Align = alBottom
    AutoSize = True
    BevelOuter = bvNone
    Caption = 'pnlBottom'
    Color = clNone
    TabOrder = 1
    object pbSongPos: TProgressBar
      Left = 0
      Top = 0
      Width = 407
      Height = 12
      Hint = 'track position - click to move '
      Align = alBottom
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
      Width = 407
      Height = 12
      Hint = 'songlist position'
      Align = alBottom
      Min = 0
      Max = 10000
      Smooth = True
      TabOrder = 1
    end
  end
  object sbPlaylist: TStatusBar
    Left = 0
    Top = 219
    Width = 407
    Height = 19
    Color = clNone
    Panels = <
      item
        Text = 'time'
        Width = 50
      end
      item
        Width = 60
      end
      item
        Text = 'length'
        Width = 50
      end
      item
        Width = 60
      end>
    SimplePanel = False
  end
  object pmnuSongs: TPopupMenu
    Images = frmMain.imlActions
    OnPopup = pmnuSongsPopup
    Left = 136
    Top = 65528
    object mnuRefresh: TMenuItem
      Caption = 'Refresh List'
      ImageIndex = 5
      OnClick = mnuRefreshClick
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
    end
    object mnuSortFile: TMenuItem
      Caption = 'Sort by filename'
      Visible = False
    end
    object mnuSortFileEntire: TMenuItem
      Caption = 'Sort by entire filename'
      Visible = False
    end
  end
end
