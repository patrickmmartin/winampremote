object dmRemote: TdmRemote
  OldCreateOrder = False
  Left = 285
  Top = 161
  Height = 479
  Width = 741
  object alRemote: TActionList
    Left = 40
    Top = 24
    object VolumeUp: TAction
      Caption = 'VolumeUp'
      OnExecute = VolumeUpExecute
    end
    object VolumeDown: TAction
      Caption = 'VolumeDown'
      OnExecute = VolumeDownExecute
    end
    object VolumeupMore: TAction
      Caption = 'VolumeupMore'
      OnExecute = VolumeupMoreExecute
    end
    object VolumeDownMore: TAction
      Caption = 'VolumeDownMore'
      OnExecute = VolumeDownMoreExecute
    end
    object Volume0: TAction
      Caption = 'Volume0'
      OnExecute = Volume0Execute
    end
    object Volume50: TAction
      Caption = 'Volume50'
      OnExecute = Volume50Execute
    end
    object Volume100: TAction
      Caption = 'Volume100'
      OnExecute = Volume100Execute
    end
    object RefreshPlaylist: TAction
      Caption = 'RefreshPlaylist'
    end
    object RefreshSettings: TAction
      Caption = 'RefreshSettings'
    end
  end
end
