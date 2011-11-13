object frmAbout: TfrmAbout
  Left = 483
  Top = 186
  Width = 483
  Height = 345
  Caption = 'Über'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = True
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnKeyPress = FormKeyPress
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnPaint = FormPaint
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TheControl: TPanel
    Left = 0
    Top = 0
    Width = 475
    Height = 317
    Hint = 'drag the mouse over me!'
    Align = alClient
    BevelOuter = bvNone
    Color = clBlack
    FullRepaint = False
    TabOrder = 0
    OnMouseDown = FormMouseDown
    OnMouseMove = FormMouseMove
    OnMouseUp = FormMouseUp
  end
  object tmrMain: TTimer
    Enabled = False
    Interval = 10
    OnTimer = IdleHandler
    Left = 120
    Top = 65528
  end
end
