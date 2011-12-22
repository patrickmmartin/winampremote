object frmDetails: TfrmDetails
  Left = 325
  Top = 368
  Width = 412
  Height = 240
  BorderIcons = [biSystemMenu]
  Caption = 'Details'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object lvDetails: TListView
    Left = 0
    Top = 25
    Width = 404
    Height = 187
    Align = alClient
    Columns = <
      item
        Caption = 'key'
        Width = 120
      end
      item
        AutoSize = True
        Caption = 'value'
      end>
    ColumnClick = False
    TabOrder = 0
    ViewStyle = vsReport
  end
  object pnlCaption: TPanel
    Left = 0
    Top = 0
    Width = 404
    Height = 25
    Align = alTop
    Alignment = taLeftJustify
    BevelOuter = bvNone
    BorderWidth = 7
    Caption = 'program details'
    TabOrder = 1
  end
end
