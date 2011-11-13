(*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000,2001,2002  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@freenet.co.uk.
*)
unit remotestrs;

interface

resourcestring

  sTestString = 'Test String';
  sWinampRemoteClient = 'Winamp Remote Client';
  sInitialisingApplication = 'initialising application';
  sCreatingMainForm = 'creating main form';
  sReadyToRun ='ready to run';
  sClosing ='closing';
  sPause = '&Pause';
  sUnPause = 'Un&Pause';

  sPlaying = ' [playing]';
  sStopped = ' [stopped]';
  sPaused = ' [paused]';

  sAboutWinampRemoteControl = 'About winamp remote control client'; 
  sWinampRemoteControl = 'winamp'#13#10'remote'#13#10'control'#13#10'client'; 

  sPlayListFiles = 'Playlist Files(*.m3u,*.pls)|*.m3u,*.pls';
  sAllFiles = 'All files|*.*';
  sRPCFailed = 'An RPC call failed'#13#10#13#10'(hint) is the server running at that endpoint?'#13#10;
  sUnhandledException = 'There was an unhandled exception'#13#10'Type: ';
  sCurrentTrack = 'current track';
  sUnknown = '<unknown>';
  sDelaying = 'delaying"';
  sDelayingForFmt = 'delaying for %d more s';
  sRestarting = 'restarting';

  sDetailsCaptionFmt = '%s details';
  sGettingPlaylist = 'getting playlist...';

  sListUnobtainable = '<list unobtainable: %s >';
  sPlaylistHint = 'Playlist view -drag files to the desired location';
  sPlay = 'Play';
  sStop = 'Stop';

  sWNetGetLastErrorFailedFmt = 'WNetGetLastError failed; error %ld.';
  sWNetFailedFmt  = '%s failed with code %ld; %s."';
  sFailed = ' failed ';
  sStartEnumerateNetwork = 'Starting to enumerate network.';
  sEnumeratingContainer = 'Enumerating container %s.';
  sLocalMachine = 'local machine';
  sServerUnknown = 'unknown';
  sAttemptingToContact = 'Attempting to contact %s.';
  sMayTakeTime = 'This may take a very long time.';
  sResponseReceivedFmt = 'Response received. Took %.3f s.';
  sCallFailed = 'Call Failed: ';
  sNotFound = 'not found';
  sTest = 'Test';

  sPortOutOfRangeFmt = 'port %d specified is out of range';
  sEndpointInvalid = 'Endpoint port invalid';
  sWellKnownPortFmt = 'The port chosen: %d %s is a well known service.'#13#10 +
                               'In some cases, this choice of port could lead to the application hanging'#13#10 +
                               'if it is already in use by another service on the server.'#13#10 +
                               'Proceed with this choice?';

  sAlertWellKnownPort = 'Alert - Well-known port number chosen!';
  sIPLookup = 'Results for ip address lookup on ';
  sAuthoritativeName = 'Authoritative name: ';
  sAddressesRetrieved = 'Addresses were retrieved';
  sAddressesNotRetrieved = 'Addresses were retrieved';
  sIPAddress = 'ip address: ';
  sAliasesRetrieved = 'Aliases were retrieved';
  sAliasesNotRetrieved = 'Aliases were not retrieved';
  sIPAlias = 'ip alias: ';
  sGetIPAddressFailed = 'Get IP address failed: ';

  sWinampRemoteLoading = 'winamp remote control client loading';


implementation

end.
