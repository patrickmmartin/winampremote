object frmServers: TfrmServers
  Left = 285
  Top = 214
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Locate Server'
  ClientHeight = 284
  ClientWidth = 440
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object imgWarning: TImage
    Left = 264
    Top = 200
    Width = 32
    Height = 32
    AutoSize = True
    Visible = False
  end
  object imgError: TImage
    Left = 304
    Top = 200
    Width = 32
    Height = 32
    AutoSize = True
    Visible = False
  end
  object imgInformation: TImage
    Left = 224
    Top = 200
    Width = 32
    Height = 32
    AutoSize = True
    Visible = False
  end
  object pnlPages: TPanel
    Left = 0
    Top = 41
    Width = 440
    Height = 202
    Align = alClient
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 0
    object pbServers: TProgressBar
      Left = 1
      Top = 185
      Width = 438
      Height = 16
      Align = alBottom
      BorderWidth = 1
      Min = 0
      Max = 100
      Smooth = True
      Step = 1
      TabOrder = 0
    end
    object pgcServers: TPageControl
      Left = 1
      Top = 1
      Width = 438
      Height = 184
      ActivePage = tbsServers
      Align = alClient
      Images = frmMain.imlActions
      TabOrder = 1
      TabWidth = 100
      object tbsServers: TTabSheet
        Caption = 'Servers'
        object lvServers: TListView
          Left = 0
          Top = 0
          Width = 430
          Height = 155
          Hint = 'list of servers'
          Align = alClient
          Columns = <
            item
              AutoSize = True
              Caption = 'Server Name'
            end
            item
              AutoSize = True
              Caption = 'Comment'
            end
            item
              AutoSize = True
              Caption = 'Winamp version'
            end>
          ColumnClick = False
          HideSelection = False
          LargeImages = imlServers
          ReadOnly = True
          RowSelect = True
          SmallImages = imlServers
          TabOrder = 0
          ViewStyle = vsReport
          OnClick = lvServersClick
        end
      end
      object tbsMessages: TTabSheet
        Caption = 'Messages'
        ImageIndex = 5
        object lvMessages: TListView
          Left = 0
          Top = 0
          Width = 430
          Height = 155
          Align = alClient
          Columns = <
            item
              AutoSize = True
            end>
          LargeImages = imlEvents
          ReadOnly = True
          RowSelect = True
          ShowColumnHeaders = False
          SmallImages = imlEvents
          TabOrder = 0
          ViewStyle = vsReport
        end
      end
    end
  end
  object pnlTop: TPanel
    Left = 0
    Top = 0
    Width = 440
    Height = 41
    Align = alTop
    BevelInner = bvLowered
    BevelOuter = bvNone
    BorderWidth = 1
    TabOrder = 1
    object lblEndPoint: TLabel
      Left = 16
      Top = 10
      Width = 137
      Height = 21
      AutoSize = False
      Caption = '&End Point to be tested'
      FocusControl = ebEndPoint
      Layout = tlCenter
    end
    object ebEndPoint: TEdit
      Left = 160
      Top = 10
      Width = 57
      Height = 21
      Hint = 'Enter tcpip endpoint to test here'
      TabOrder = 0
    end
  end
  object pnlButtons: TPanel
    Left = 0
    Top = 243
    Width = 440
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object btnCancel: TButton
      Left = 361
      Top = 8
      Width = 75
      Height = 25
      Hint = 'cancel'
      Anchors = [akRight, akBottom]
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 4
    end
    object btnOK: TButton
      Left = 273
      Top = 8
      Width = 75
      Height = 25
      Hint = 'select server'
      Anchors = [akRight, akBottom]
      Caption = 'OK'
      Enabled = False
      TabOrder = 3
      OnClick = btnOKClick
    end
    object btnTest: TButton
      Left = 97
      Top = 8
      Width = 75
      Height = 25
      Hint = 'test the server list'
      Anchors = [akRight, akBottom]
      Caption = 'Test All'
      Enabled = False
      TabOrder = 1
      OnClick = StartTest
    end
    object btnLocate: TButton
      Left = 9
      Top = 8
      Width = 75
      Height = 25
      Hint = 'locate local machines'
      Anchors = [akRight, akBottom]
      Caption = 'Locate All'
      TabOrder = 0
      OnClick = btnLocateClick
    end
    object btnGetIp: TButton
      Left = 185
      Top = 8
      Width = 75
      Height = 25
      Hint = 'Get ip addresses and aliases'
      Anchors = [akRight, akBottom]
      Caption = 'Get IP'
      Enabled = False
      TabOrder = 2
      OnClick = GetServerIp
    end
  end
  object imlServers: TImageList
    Height = 32
    Width = 32
    Left = 321
    Top = 65528
    Bitmap = {
      494C010103000400040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000800000002000000001001000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C618C618C61800000000
      00000000000000000000C618C618C6180000000000000000000000000000C618
      C618C6180000000000000000000000000000FF7FFF7FC618C618C618FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FC618C618C618FF7FFF7FFF7FFF7FFF7FFF7FFF7FC618
      C618C618FF7FFF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C618CE39CE39CE39CE39C618C618
      C618C618C618C618CE39CE39CE39CE39C618C618C618C618C618C618C618CE39
      CE39C618C618C618C618C618C618C618C618C618CE39CE39CE39CE39C618C618
      C618C618C618C618CE39CE39CE39CE39C618C618C618C618C618C618C618CE39
      CE39C618C618C618C618C618C618C618C61800000000EF3DEF3DEF3D00000000
      00000000000000000000EF3DEF3DEF3D00000000000000000000000000000000
      EF3DEF3D000000000000000000000000000000000000EF3DEF3DEF3D00000000
      00000000000000000000EF3DEF3DEF3D00000000000000000000000000000000
      000000000000000000000000000000000000CE39524ACE39CE39CE39CE39C618
      CE39CE39CE39CE39524ACE39CE39CE39CE39C618CE39CE39CE39CE39524ACE39
      CE39CE39C618CE39CE39CE39CE39CE39CE39CE39524ACE39CE39CE39CE39C618
      CE39CE39CE39CE39524ACE39CE39CE39CE39C618CE39CE39CE39CE39524ACE39
      CE39CE39C618CE39CE39CE39CE39CE39CE390000EF3DEF3DEF3DEF3DEF3D0000
      0000000000000000EF3DEF3DEF3DEF3DEF3D000000000000000000000000F75E
      EF3DEF3D00000000000000000000000000000000EF3DEF3DEF3DEF3DEF3D0000
      0000000000000000EF3DEF3DEF3DEF3DEF3D0000000000000000000000000000
      000000000000000000000000000000000000524A524ACE39CE39CE39CE39524A
      524A524A524A524A524ACE39CE39CE39CE39524A524A524A524A524AFF7F524A
      CE39CE39524A524A524A524A524A524A524A524A524ACE39CE39CE39CE39524A
      524A524A524A524A524ACE39CE39CE39CE39524A524A524A524A524AFF7F524A
      CE39CE39524A524A524A524A524A524A524AEF3DF75EEF3DEF3DEF3DEF3DEF3D
      EF3DEF3DEF3DEF3DF75EEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DF75EEF3D
      EF3D0000EF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DF75EEF3DEF3DEF3DEF3DEF3D
      EF3DEF3DEF3DEF3DF75EEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3D
      EF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3D0000FF7F524ACE39CE39CE390000
      0000000000000000FF7F524ACE39CE39CE39000000000000000000000000FF7F
      524ACE39C618000000000000000000000000FF7FFF7F524ACE39CE39CE39FF7F
      FF7FFF7FFF7FFF7FFF7F524ACE39CE39CE39FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7FEF3DF75EEF3DEF3DEF3DEF3DEF3D
      EF3DEF3DEF3DEF3DF75EEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DFF7FF75E
      EF3D0000EF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DF75EEF3DEF3DEF3DEF3DEF3D
      EF3DEF3DEF3DEF3DF75EEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3D
      EF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3DEF3D00000000FF7F524ACE3900000000
      00000000000000000000FF7F524ACE3900000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7F524ACE39FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F524ACE39FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000FF7FF75EEF3DEF3DEF3D0000
      0000000000000000FF7FF75EEF3DEF3DEF3D000000000000000000000000FF7F
      F75EEF3D00000000000000000000000000000000FF7FF75EEF3DEF3DEF3D0000
      0000000000000000FF7FF75EEF3DEF3DEF3D0000000000000000000000000000
      0000F75EF75EEF3D000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F00000000FF7FF75EEF3D00000000
      00000000000000000000FF7FF75EEF3D00000000000000000000000000000000
      EF3DEF3D000000000000000000000000000000000000FF7FF75EEF3D00000000
      00000000000000000000FF7FF75EEF3D00000000000000000000000000000000
      0000F75EF75EEF3D000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      EF3DEF3D00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F75EF75EEF3D000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      EF3DEF3D00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      007C007C007C007C000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      EF3DEF3D00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000007C
      FF7F007C007CFF7F007C00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      EF3DEF3D00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000007C
      007CFF7FFF7F007C007C00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      EF3DEF3D00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000007C
      007CFF7FFF7F007C007C00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      EF3DEF3D00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000007C
      FF7F007C007CFF7F007C00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      EF3DEF3D00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      007C007C007C007C000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F00000000000000000000003C003C
      003C000000000000000000000000715A0000000000000000000000000000524A
      524ACE39C6180000000000000000000000000000000000000000000000000000
      0000000000000000000000000000715A0000000000000000000000000000524A
      524ACE39C6180000000000000000000000000000000000000000000000000000
      0000000000000000000000000000715A0000000000000000000000000000524A
      524ACE39C618000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F715AFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A
      524ACE39C618FF7FFF7FFF7FFF7FFF7FFF7F00000000000000000000003C003C
      003C0000000000000000000000000D52C94D715A0000000000000000EF3DC618
      CE39CE39C6180000000000000000000000000000000000000000000000000000
      00000000000000000000000000000D52C94D715A0000000000000000EF3DC618
      CE39CE39C6180000000000000000000000000000000000000000000000000000
      00000000000000000000000000000D52C94D715A0000000000000000EF3DC618
      CE39CE39C618000000000000000000000000FF7FFF7FFF7F003C003CFF7FFF7F
      FF7FFF7F003C003CFF7FFF7FFF7F0D52C94D715AFF7FFF7FFF7FFF7FEF3DC618
      CE39CE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000007C007C007C
      003C00000000000000000000000000000D52864D4E5600000000EF3DC618C618
      C618CE39C6180000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000D52864D4E5600000000EF3DC618C618
      C618CE39C6180000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000D52864D4E5600000000EF3DC618C618
      C618CE39C618000000000000000000000000FF7FFF7FFF7F003C003CFF7FFF7F
      FF7FFF7F003C003CFF7FFF7FFF7FFF7F0D52864D4E56FF7FFF7FEF3DC618C618
      C618CE39C618FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000007C007C007C
      0000000000000000000000000000000000004D56A655E855893DC61808210821
      08210821CE390000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004D56A655E855893DC61808210821
      08210821CE390000000000000000000000000000000000000040004000000000
      0000000000000000000000000000000000004D56A655E855893DC61808210821
      08210821CE39000000000000000000000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FFF7F4D56A655E855893DC61808210821
      08210821CE39FF7FFF7FFF7FFF7FFF7FFF7F00000000000000000000003C003C
      0000000000000000000000000000000000000000E855E659C6556541E6240821
      082108210821CE39000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000E855E659C6556541E6240821
      082108210821CE3900000000000000000000000000000000003C003C00400040
      0000000000000000000000000000000000000000E855E659C6556541E6240821
      082108210821CE3900000000000000000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FFF7FFF7FE855E659C6556541E6240821
      082108210821CE39FF7FFF7FFF7FFF7FFF7F0000000000000000007C007C007C
      003C000000000000000000000000000000000000EE41C655276A2666E659663D
      0825292529250821EF3D00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000EE41C655276A2666E659663D
      0825292529250821EF3D000000000000000000000000007C007C003C003C003C
      003C004000000000000000000000000000000000EE41C655276A2666E659663D
      0825292529250821EF3D0000000000000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FFF7FFF7FEE41C655276A2666E659663D
      0825292529250821EF3DFF7FFF7FFF7FFF7F0000000000000000007C007C007C
      003C003C0000000000000000000000000000EF3D08214931486A68764772266E
      E6594735292529250821EF3D0000000000000000000000000000000000000000
      000000000000000000000000000000000000EF3D08214931486A68764772266E
      E6594735292529250821EF3D00000000000000000000007C007C007C007C003C
      003C003C003C004000000000000000000000EF3D08214931486A68764772266E
      E6594735292529250821EF3D000000000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FFF7FEF3D08214931486A68764772266E
      E6594735292529250821EF3DFF7FFF7FFF7F00000000000000000000007C007C
      007C003C003C00000000000000000000EF3D082129256B2DAA418A768A7A8A76
      6876276AA64D272929250821EF3D000000000000000000000000000000000000
      00000000000000000000000000000000EF3D082129256B2DAA418A768A7A8A76
      6876276AA64D272929250821EF3D0000000000000000007C007C007C007C007C
      007C003C003C003C003C004000000000EF3D082129256B2DAA418A768A7A8A76
      6876276AA64D272929250821EF3D00000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FEF3D082129256B2DAA418A768A7A8A76
      6876276AA64D272929250821EF3DFF7FFF7F00000000000000000000007C007C
      007C007C003C0000000000000000EF3D082129256B2D6A31C94D8A76CB7ECB7E
      AB7E8A7A68762666874129250821104200000000000000000000000000000000
      0000000000000000000000000000EF3D082129256B2D6A31C94D8A76CB7ECB7E
      AB7E8A7A687626668741292508211042000000000000007C007C007C007C007C
      007C007C007C003C003C003C0000EF3D082129256B2D6A31C94D8A76CB7ECB7E
      AB7E8A7A6876266687412925082110420000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FEF3D082129256B2D6A31C94D8A76CB7ECB7E
      AB7E8A7A687626668741292508211042FF7F00000000003C003C00400000007C
      007C007C007C003C0000000000000000AD356B2DA9412966CB7EEC7EEC7EEC7E
      CB7ECB7E6A72E9518A3529258C31000000000000000000000000000000000000
      00000000000000000000000000000000AD356B2DA9412966CB7EEC7EEC7EEC7E
      CB7ECB7E6A72E9518A3529258C310000000000000000007C007C007C007C007C
      007C007C007C007C007C000000000000AD356B2DA9412966CB7EEC7EEC7EEC7E
      CB7ECB7E6A72E9518A3529258C3100000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FAD356B2DA9412966CB7EEC7EEC7EEC7E
      CB7ECB7E6A72E9518A3529258C31FF7FFF7F00000000003C003C004000000000
      007C007C007C003C003C0000000000000000EF3DCC456C66CC76EC7EEC7EEC7E
      EC7ECB7EC8498C316B2DAD350000000000000000000000000000000000000000
      000000000000000000000000000000000000EF3DCC456C66CC76EC7EEC7EEC7E
      EC7ECB7EC8498C316B2DAD3500000000000000000000007C007C007C007C007C
      007C007C007C007C007C0000000000000000EF3DCC456C66CC76EC7EEC7EEC7E
      EC7ECB7EC8498C316B2DAD35000000000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FFF7FEF3DCC456C66CC76EC7EEC7EEC7E
      EC7ECB7EC8498C316B2DAD35FF7FFF7FFF7F0000007C007C007C003C00400000
      003C007C007C007C003C000000000000000000003146EF3D0F4A6E5ECD72CC76
      EC7EEC7E8A76A849AD3900000000000000000000000000000000000000000000
      00000000000000000000000000000000000000003146EF3D0F4A6E5ECD72CC76
      EC7EEC7E8A76A849AD39000000000000000000000000007C007C007C007C007C
      007C007C007C00000000000000000000000000003146EF3D0F4A6E5ECD72CC76
      EC7EEC7E8A76A849AD390000000000000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FFF7FFF7F3146EF3D0F4A6E5ECD72CC76
      EC7EEC7E8A76A849AD39FF7FFF7FFF7FFF7F0000007C007C007C003C003C003C
      003C007C007C007C0000000000000000000000000000524A3146524A524A7052
      AD6ACC76EC7E8A7A6B6AD3620000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000524A3146524A524A7052
      AD6ACC76EC7E8A7A6B6AD36200000000000000000000007C007C007C007C007C
      007C0000000000000000000000000000000000000000524A3146524A524A7052
      AD6ACC76EC7E8A7A6B6AD362000000000000FF7FFF7F007C007C003CFF7FFF7F
      FF7F007C007C003CFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A3146524A524A7052
      AD6ACC76EC7E8A7A6B6AD362FF7FFF7FFF7F00000000007C007C007C003C003C
      007C007C007C000000000000000000000000000000000000734E524A734E524A
      10420E4A6D5ECD7A8976486AB362000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000734E524A734E524A
      10420E4A6D5ECD7A8976486AB3620000000000000000007C007C007C007C0000
      000000000000000000000000000000000000000000000000734E524A734E524A
      10420E4A6D5ECD7A8976486AB36200000000FF7FFF7F007C007CFF7FFF7FFF7F
      FF7F007C007CFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F734E524A734E524A
      10420E4A6D5ECD7A8976486AB362FF7FFF7F00000000007C007C007C007C007C
      007C007C007C0000000000000000000000000000000000000000734E31461042
      EF3D314600000000F46AAC722966B36200000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000734E31461042
      EF3D314600000000F46AAC722966B362000000000000007C007C000000000000
      0000000000000000000000000000000000000000000000000000734E31461042
      EF3D314600000000F46AAC722966B3620000FF7FFF7F007C007CFF7FFF7FFF7F
      FF7F007C007CFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F734E31461042
      EF3D3146FF7FFF7FF46AAC722966B362FF7F0000000000000000007C007C007C
      007C0000000000000000000000000000000000000000000000000000524AEF3D
      314600000000000000000000B3628F6200000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524AEF3D
      314600000000000000000000B3628F6200000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000524AEF3D
      314600000000000000000000B3628F620000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524AEF3D
      3146FF7FFF7FFF7FFF7FFF7FB3628F62FF7F0000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000524A
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F524A
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F424D3E000000000000003E000000
      2800000080000000200000000100010000000000000200000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFFFFFFFFFFC7F1FC7F00000000
      C7F1FE3FC7F1FFFF000000000000FF00C3F0FE3FC3F0FFFF00000000FF0000FF
      00000000000000000000000000FF0000000000000000000083E0FC3F00000000
      0000000000000000C7F1FE3F0000000083E0FC3F83E0FF1FFFFFFE3F00000000
      C7F1FE3FC7F1FF1FFFFFFE3F0000FF00FFFFFE3FFFFFFF1FFFFFFE3FFF0000FF
      FFFFFE3FFFFFFE1FFFFFFE3F00FF0000FFFFFE3FFFFFFC0FFFFFFE3F00000000
      FFFFFE3FFFFFFC0FFFFFFE3F00000000FFFFFE3FFFFFFC0FFFFFFE3F00000000
      FFFFFE3FFFFFFC0FFFFFFE3F0000FF00FFFFFE3FFFFFFE1FFFFFFE3FFF0000FF
      F8FDFC3FFFFDFC3FFFFDFC3F00FF0000F8FC783FFFFC783FFFFC783F00000000
      F0FE303FFFFE303FFFFE303F00000000F1FF003FFFFF003FE7FF003F00000000
      F9FF801FFFFF801FE1FF801F0000FF00F0FF800FFFFF800FC07F800FFF0000FF
      F07F0007FFFF0007C01F000700FF0000F83E0003FFFE0003C006000300000000
      F83C0001FFFC0001C004000100000000C41E0003FFFE0003C00E000300000000
      C60F0007FFFF0007C00F00070000FF00820F800FFFFF800FC03F800FFF0000FF
      801FC007FFFFC007C0FFC00700FF0000C03FE003FFFFE003C3FFE00300000000
      C03FF061FFFFF061CFFFF06100000000F0FFF8F9FFFFF8F9FFFFF8F944493353
      FFFFFDFFFFFFFDFFFFFFFDFF0000000000000000000000000000000000000000
      000000000000}
  end
  object imlEvents: TImageList
    Left = 288
    Top = 65528
  end
end
