object frmSettings: TfrmSettings
  Left = 339
  Top = 236
  Hint = 'Audio Settings Form'
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Audio'
  ClientHeight = 120
  ClientWidth = 290
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = True
  Position = poDefault
  ShowHint = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  OnStartDock = FormStartDock
  PixelsPerInch = 96
  TextHeight = 14
  object pgcSettings: TPageControl
    Left = 0
    Top = 0
    Width = 290
    Height = 120
    ActivePage = tbsEQ
    Align = alClient
    Images = frmMain.imlActions
    Style = tsFlatButtons
    TabOrder = 0
    TabWidth = 133
    object tbsVol: TTabSheet
      Caption = 'Volume'
      ImageIndex = 24
      object bvlVolume: TBevel
        Left = 0
        Top = 0
        Width = 282
        Height = 88
        Align = alClient
      end
      object lblVol: TLabel
        Left = 16
        Top = 19
        Width = 15
        Height = 14
        Caption = '&Vol'
        FocusControl = tbVolume
      end
      object lblBal: TLabel
        Left = 18
        Top = 51
        Width = 15
        Height = 14
        Caption = '&Bal'
        FocusControl = tbBalance
      end
      object tbVolume: TTrackBar
        Left = 50
        Top = 8
        Width = 201
        Height = 28
        Hint = 
          'drag to set volume|drag to set volume -  the volume is not obtai' +
          'ned'
        Anchors = [akLeft, akTop, akRight]
        Max = 255
        Orientation = trHorizontal
        Frequency = 64
        Position = 0
        SelEnd = 0
        SelStart = 0
        TabOrder = 0
        ThumbLength = 15
        TickMarks = tmTopLeft
        TickStyle = tsAuto
        OnChange = tbVolumeChange
      end
      object tbBalance: TTrackBar
        Left = 50
        Top = 42
        Width = 201
        Height = 28
        Hint = 
          'drag to set balance|drag to set balance-  the balance is not obt' +
          'ained'
        Anchors = [akLeft, akTop, akRight]
        Ctl3D = True
        Max = 127
        Min = -127
        Orientation = trHorizontal
        ParentCtl3D = False
        Frequency = 1
        Position = 0
        SelEnd = 10
        SelStart = -10
        TabOrder = 1
        ThumbLength = 15
        TickMarks = tmTopLeft
        TickStyle = tsManual
        OnChange = tbBalanceChange
      end
    end
    object tbsEQ: TTabSheet
      Caption = 'EQ settings'
      ImageIndex = 2
      object bvlEQ: TBevel
        Left = 0
        Top = 0
        Width = 282
        Height = 88
        Align = alClient
      end
      object lblPreamp: TLabel
        Left = 48
        Top = 24
        Width = 25
        Height = 14
        AutoSize = False
        Caption = 'Pre'
      end
      object lblEQ: TLabel
        Left = 96
        Top = 24
        Width = 25
        Height = 14
        AutoSize = False
        Caption = 'EQ'
      end
      object TrackBar1: TTrackBar
        Left = 112
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 2
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar2: TTrackBar
        Left = 129
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 3
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar3: TTrackBar
        Left = 146
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 4
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar4: TTrackBar
        Left = 163
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 5
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar5: TTrackBar
        Left = 180
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 6
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar6: TTrackBar
        Left = 197
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 7
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar7: TTrackBar
        Left = 214
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 8
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar8: TTrackBar
        Left = 231
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 9
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar9: TTrackBar
        Left = 248
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 10
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar10: TTrackBar
        Left = 265
        Top = 6
        Width = 21
        Height = 70
        Hint = 'drag to alter EQ band gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 11
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object TrackBar11: TTrackBar
        Left = 68
        Top = 6
        Width = 21
        Height = 70
        Hint = 'preamp gain'
        Max = 63
        Orientation = trVertical
        PageSize = 0
        Frequency = 1
        Position = 63
        SelEnd = 0
        SelStart = 0
        TabOrder = 1
        ThumbLength = 15
        TickMarks = tmBoth
        TickStyle = tsNone
        OnChange = BarsChange
      end
      object tbEQ: TToolBar
        Left = 8
        Top = 8
        Width = 31
        Height = 54
        Align = alNone
        AutoSize = True
        BorderWidth = 2
        ButtonHeight = 23
        Caption = 'tbEQ'
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        EdgeInner = esNone
        EdgeOuter = esNone
        Flat = True
        Images = frmMain.imlActions
        TabOrder = 0
        object btnEQOn: TToolButton
          Left = 0
          Top = 0
          Wrap = True
        end
        object btnAutoload: TToolButton
          Left = 0
          Top = 23
        end
      end
    end
  end
end
