object wmMain: TwmMain
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'waDefault'
      OnAction = wmMainwaDefaultAction
    end>
  BeforeDispatch = WebModuleBeforeDispatch
  AfterDispatch = WebModuleAfterDispatch
  Left = 62
  Top = 261
  Height = 294
  Width = 557
  object ppGetPlaylist: TPageProducer
    HTMLDoc.Strings = (
      '<HTML>'
      '<BODY>'
      '<H1>Default Playlist table </H1>'
      '<TABLE BORDER="1" PADDING="1">'
      '<#Playlist>'
      '</TABLE>'
      '</BODY>'
      '</HTML>')
    OnHTMLTag = ppGetPlaylistHTMLTag
    Left = 32
    Top = 24
  end
end
