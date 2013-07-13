object frmCommands: TfrmCommands
  Left = 625
  Top = 289
  Hint = 'Play Commands'
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Commands'
  ClientHeight = 38
  ClientWidth = 215
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -9
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = True
  Position = poDefault
  OnClose = FormClose
  OnShow = FormShow
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
    EdgeInner = esNone
    EdgeOuter = esNone
    Flat = True
    HotImages = frmMain.imlCommandsHot
    Images = frmMain.imlCommandsCool
    TabOrder = 0
    Transparent = True
    object tbtnPrevious: TToolButton
      Left = 0
      Top = 0
    end
    object tbtnPlay: TToolButton
      Left = 43
      Top = 0
    end
    object tbtnPause: TToolButton
      Left = 86
      Top = 0
    end
    object tbtnStop: TToolButton
      Left = 129
      Top = 0
    end
    object tbtnNext: TToolButton
      Left = 172
      Top = 0
    end
  end
end
