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
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 14
  object lstSongs: TListBox
    Left = 0
    Top = 0
    Width = 407
    Height = 190
    Hint = 'Playlist view -drag files to the desired location'
    Align = alClient
    DragMode = dmAutomatic
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '<songlist unobtained>')
    MultiSelect = True
    ParentFont = False
    PopupMenu = pmnuSongs
    Style = lbOwnerDrawVariable
    TabOrder = 0
    OnDblClick = lstSongsDblClick
    OnDragDrop = lstSongsDragDrop
    OnDragOver = lstSongsDragOver
    OnDrawItem = lstSongsDrawItem
    OnKeyDown = lstSongsKeyDown
    OnMeasureItem = lstSongsMeasureItem
    OnMouseMove = lstSongsMouseMove
  end
  object pnlBottom: TPanel
    Left = 0
    Top = 190
    Width = 407
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
      Width = 403
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
      Width = 403
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
  object sbPlaylist: TStatusBar
    Left = 0
    Top = 218
    Width = 407
    Height = 19
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
    Visible = False
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
    end
    object mnuDelete: TMenuItem
    end
    object Repeat1: TMenuItem
    end
    object Shuffle1: TMenuItem
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
