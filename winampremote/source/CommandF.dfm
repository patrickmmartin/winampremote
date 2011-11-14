object frmCommands: TfrmCommands
  Left = 482
  Top = 218
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
    HotImages = frmMain.imlCommandsHot
    Images = frmMain.imlCommandsCool
    TabOrder = 0
    object tbtnPrevious: TToolButton
      Left = 0
      Top = 0
      Action = frmMain.Previous
    end
    object tbtnPlay: TToolButton
      Left = 43
      Top = 0
      Action = frmMain.Play
    end
    object tbtnPause: TToolButton
      Left = 86
      Top = 0
      Action = frmMain.Pause
    end
    object tbtnStop: TToolButton
      Left = 129
      Top = 0
      Action = frmMain.Stop
    end
    object tbtnNext: TToolButton
      Left = 172
      Top = 0
      Action = frmMain.Next
    end
  end
end
