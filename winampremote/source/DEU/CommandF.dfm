object frmCommands: TfrmCommands
  Left = 638
  Top = 373
  Hint = 'Play Commands'
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Commands'
  ClientHeight = 38
  ClientWidth = 215
  Color = clBtnFace
  DragKind = dkDock
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -9
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = True
  Position = poDefault
  OnClose = FormClose
  OnEndDock = FormEndDock
  OnStartDock = FormStartDock
  PixelsPerInch = 96
  TextHeight = 12
  object tbCommands: TToolBar
    Left = 0
    Top = 0
    Width = 215
    Height = 38
    Align = alNone
    AutoSize = True
    ButtonHeight = 38
    ButtonWidth = 43
    EdgeBorders = []
    Flat = True
    TabOrder = 0
    object tbtnPrevious: TToolButton
      Left = 0
      Top = 0
      Hint = 'Previous Track'
      Caption = '&Previous'
      ImageIndex = 0
      OnClick = tbtnPreviousClick
    end
    object tbtnPlay: TToolButton
      Left = 43
      Top = 0
      Hint = 'Play Selected'
      Caption = 'play'
      ImageIndex = 1
      OnClick = tbtnPlayClick
    end
    object tbtnPause: TToolButton
      Left = 86
      Top = 0
      Hint = 'Pause Playing'
      Caption = 'pause'
      ImageIndex = 2
      OnClick = tbtnPauseClick
    end
    object tbtnStop: TToolButton
      Left = 129
      Top = 0
      Hint = 'Stop Playing'
      Caption = 'stop'
      ImageIndex = 3
      OnClick = tbtnStopClick
    end
    object tbtnNext: TToolButton
      Left = 172
      Top = 0
      Hint = 'Next in Playlist'
      Caption = 'next'
      ImageIndex = 4
      OnClick = tbtnNextClick
    end
  end
end
