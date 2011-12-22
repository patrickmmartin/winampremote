Winamp Remote Controller Suite.


Released under the GPL

This is the readme file for the winamp remote controller.

Overview:

Have you ever encountered one of these dire situations?

     Only one stereo, too many machines? 
     Can't... Raise... Bulk... - Must... Resist... Sofa... 
     I dream of the day I can put "written listening to winamp" on one of my products; 'til then, nobody must know I
     work with the stereo on... 
     We want to be able to share choosing the tracks on the winamp machine, but without playing musical chairs. 

Do you have Windows machines, networked via tcp-ip*?

* If not, why not?

If so, this may be the application suite for you!

And it's free!

What it does: 

The broadest overview would have to be that the winamp plugin gives winamp the ability to respond to control
messages from remote machines connected via a network.

In more concrete terms - install the plugin, and you can control winamp on machine 1, by using a client application on
machine 2.

The Client 

Installation:

Simply use one of the setup options in the setup provided.

Use:

Simply get the endpoint right (machine, endpoint - read it off the server messages form), and it should just work

I hope the interface is fairly self-explanatory - just try it out!

ps - right click the tray-icon for a menu, and left click for a quick pause, when the back manager calls.
The pause code actually tests to see if the server state is consistent with what you are seeing, and does not act if winamp
is already paused.
So you can *all* dive for pause at once (ish).

The Server 

Installation:

Simply use the "Typical" setup or "Custom" and select the server plugin group.

The server plugin install option puts a shortcut to install the winamp plugin. Click on this while winamp is not running,
and restart winamp - the plugin is loaded automatically by winamp at startup, and it starts to export winamp's abilities
soon after, assuming all is well with your machine.

Use:

"Out of the box", this will work straight off for client, server and winamp all on the same machine.

To finally use the suite as intended, you will have to have a client remote to the winamp machine, that can "see" the
server endpoint.

New - now the locate servers function will find the local winamp server for you!

*Users without a network, or only dial-up read me 
- Without a known IP address, these calls, and the remote's operation can take a very long time.
In these cases, I recommend adding the line 

127.0.0.1 localhost # this is the local loopback

to the Windows Hosts file.
What's the windows hosts file?
Well, in the Windows directory, or WinNT/System32/drivers/etc, there should be a file called (just) 

HOSTS

which contains a list of ip address lookups - win9x often has a hosts.sam sample file.
With the previous line added, the ip alias localhost is available as the local loopback address.
You could even add your machine name (try to resist the temptation to make it www.microsoft.com - it will "override"
real net aliases, and prevent you going there.)

What You will need: 

     The Installation process 
     Get the install files 
     Run setup 
     Select Your option
     - Typical gives you the server and the client.
     - Compact gives you client only.
     - Custom gives you option to select the client, server and MS OpenGL options. 
     Continue with the setup - to install the server, click on the "install server plugin" link 
     You are now ready to go - the client needs only the correct endpoint setting - the default should be OK.
     If you have trouble and the server is definitely running on a machine you can 'see', have a work with your network
     person, if you have one.
     If all else fails, drop me a line, maybe it's my fault, or I can help. 

Requirements

     The Client 
     Win 9x/NT4 (dunno about NT3.5 - can anyone let me know?) 
     tcp-ip between the server and client on at least one port that is free you are aware of. 
     I think that's it 

     The Server 
     Win 9x/NT4 
     tcp-ip between the client and server on at least one port that is free you are aware of. 
     I think that's it 

Oh, and winamp and some block-rocking beats ;-)

Future Plans: 

     Imminent (know how to do it, but must sleep...) 
     Client - implement multi-threading of client to prevent scary hangs
     Honest, it's not my fault... 
     Linux clients / shared libraries - courtesy of the sterling detective work by Ernesto Baschny 
     New Projects
     New Server Plugin using XMLRPC
     New Client using XMLRPC with modular architecture
     Client RPC DLL project for use in other projects
     Client XMLRPC DLL project for use in other projects
     Winamp RPC "SDK"
     - which may just be the IDL file - for the propellerheads out there
     - or a full template project in your choice of tool (as long as it's BCB) Anyone wishing to port to VC or rewrite in
     ANSI c++ - get in touch. 
     Linux projects and web server utility modules 
     Enhancements and rationalisation of the "API" prior to GPL release 
     Release under GPL 

     Distant (or next major version) 
     Properly versioned RPC interface (backwards and forwards compatibility with all these new extensions
     guaranteed) 
     Greater set of protocols, for performance boost / ease of use on non tcpip (or just plain odd) net configurations. 
     Drag and dock with full view of windows - see below 
     Skinnable client (maybe winamp 2 {3?}/ real / kjofol compatible skin format) 
     Server: allow some "administrative functions" ie playlist tyranny to be applied to the client machines 
     Server: implement lightweight HTTP server for web administration 
     Client: produce portable ANSI c++ client for OSs capable of handling the RPC calls 

     Moon shooting (no idea if facility does or can ever exist) 
     Client: Fix add directory function? - still open after 6 months! 
     Server: notify clients of winamp status asynchronously
     I do know how to do this, but I'm not sure if is solves more problems than it fixes... 
     Server: I have been asked this - send back the audio / video too!
     ?!*@ = what kind of networks do you guys have out there?
     And isn't this what Shoutcast is for? 

     Evident Insanity 
     Client: port to PalmOS 
     And Windows CE 
     And MAC 

     Total and Utter Drooling insanity 
     (moved here where it belongs) Server: execute the visualisation plugin remotely as well.
     Server: Port to all OSs, along with Winamp, of course 
     Produce prototype Bluetooth device using interface 

About the author: 

what's to say - I hope to let my work speak for itself

Get in touch:

I have too few machines, or access to others', and too few network configurations to be able to test this thoroughly

If anyone notices any problems / interface quirks, I would love to hear from them: patrickmmartin@gmail.com

Application History: 

     14/05/02 fifteenth release - DCE compatible RPC interface and GPL release
          Important points: 
          The RPC interface is now DCE compatible. 
          Backwards compatibility had to be broken as a consequence. 
          Source released under the GPL. 
          Server enhancements: 
          Change in RPC interface to produce a DCE RPC compatible interface. 
          Client enhancements: 
          New interface support. 
     14/10/00 fourteenth release - bug fixes and tidying up
          Server enhancements: 
          Winamp 2.6x NT4 showstopper bug fixed in server plugin. 
          Client enhancements: 
          When in tray with no visible windows, there is no taskbar icon. 
     30/08/00 thirteenth release � tidz up
          Server enhancements: 
          Small enhancment to clients view. 
          Default port now chosen to one more likely to be free. 
          List of known ports now 1000 items long (should help debugging RPC bind problems). 
          Client enhancements: 
          Children forms can be dragged and docked to main window. State is of course, persistent. Enjoy. 
     22/08/00 twelfth release - drag and drop fun! 
          Server enhancements: 
          None, though maybe it's getting to be time. 
          Client enhancements: 
          Drag into the playlist window inserts into list at drop point.
          A bit of a performance hit, but what the hey? 
          Dragging selected files within the playlist window also inserts into list at drop point. 
          Autoload button on EQ form. 
     18/07/00 eleventh release - new header file from Nullsoft! 
          Server enhancements: 
          Fuller list of commands with descriptions!
          (OK, not very important) 
          Client enhancements: 
          Shuffle and repeat now display their values - try the menus!
          These behave as per pause i.e. if your display state is correct, the action is invoked. 
          EQ is working!
          The behaviour is a little "beta", owing to the truly bizarre way winamp implements getting and setting the
          properties.
          The upshot is that for performance reasons, and to avoid users interfering with each other, the EQ is not
          updated regularly.
          Try the refresh button to see the results.
          Oh, and the winamp skin doesn't update, thought the settings are altered...
          You can alter it and see (and hear?) the results, however. 
     18/07/00 tenth release - new "locate servers" function - connect yourself up with as little hassle as possible 
          Server enhancements: 
          Suggestions have kept on rolling in - still under consideration! 
          Client enhancements: 
          Any machines in the netwoprk neightbourhood can be "automatically" located and tested. 
     07/06/00 ninth release - upgraded to C++ builder 4 - nice!, interface enhancements and few bug fixes 
          Server enhancements: 
          Some more optimisations - should be a little bit more efficient on slower machines 
          Suggestions have been rolling in - now under consideration 
          Client enhancements: 
          interface overhaul - hope you like it. 
          nice full colour pictures. 
          overhaul of popup menu, should be more usable. 
          Bug fixed where update on song change kicked off endless updates. 
     07/05/00 eighth release - minor interface changes and optimisations for the client
          Server enhancements: 
          Icon animations for the clients connected - these do happen when there are client requests
          I hope it's useful to people (or just amusing) 
          string size returned clamped down to MAX_PATH
          - I hope this is the right upper limit, though you would have to go pretty over the top to hit this limit 
          Client enhancements: 
          Various tweaks to attempt a consistent view when large fonts is on. 
          Slight change to commands toolbar as a result of the above. 
          Bug fixed where two updates of the playlist were being performed for one change of the list - this should
          save some time for those long playlists. 
     31/03/00 seventh release - minor interface changes and optimisations for the client
          Server enhancements: 
          None - can you believe it? 
          Client enhancements: 
          Some configurability and efficiency enhancements. 
               You can chose whether to automatically hide the upon startup. 
               You can chose whether to automatically restore the child windows . 
               The server poll interval is remembered, and has a niftier control (I think). 
               More subtly, the behaviour of the playlist editor has altered. If the update when list changes option
               (now default) is chosen, the list is not reloaded every song play. The other setting is as before:
               refresh the list every time the song changes. It's hard for the playlist to get out of step, but it can be a
               little hard on the network. I hope this takes some of the pain away. 
     31/03/00 sixth release - minor interface enhancements of the client and server
          Server enhancements: 
          The problem with non-thread safe code leading to intermittent corruption of the playlists for multiple clients
          is fixed: 
          the visible state of the server messages window is persistent. 
          animation of icons is still coming in the next version, see below. 
          Client enhancements: 
          The behaviour and number of sub forms has altered. 
               The network configuration is hideable, and the server poll time is configurable 
               The playlist form supports delete and drag and drop. Hope this is more useful. It's a little heavy on
               the network to delete, so be sparing 
               There is a new commands "toolbar" ,which can be used for ultra-friendly access to the basic
               commands. 
               The visibility and position of all the forms is saved on exit, and restored. Nice... 
     05/03/00 fifth release - minor interface enhancements of the client and server
          Server enhancements: 
          The server messages form has some nice new windows and enhancements: 
               the visible state of the server messages window is persistent. 
               the current clients of the server and their status are shown in a nice view (animation next version,
               once the images are good enough). 
               the notification messages added to the messages window are selectable. Just who is it who keeps
               skipping my favourite track? 
          Client enhancements: 
          The behaviour and number of sub forms has altered. 
               The playlist form gets told of song / playlist changes, and is a bit more efficient/stingy about getting
               the entire playlist. 
               There is a volume and balance form that works interactively. Sorry, the initial values of these are
               nonsense until you move them. This isn't my fault, and I'm trying to think of a way around it. 
     05/03/00 fourth release - major upgrade of the server
          New Features: 
          new server approach
          The server is no longer a stand-alone exe, but a generic plugin loaded in-process by winamp upon startup.
          - what this gives you is a single-click winamp server.
          The server can be monitored by going to Plugins > General > Configure and selecting the pmmsoft RPC
          interface entry.
          The server can be configured to use different ports on the fly, and the settings are persistent.
          Warnings are issued for all RFC1060 ports (which didn't include http ?!) -and http.
          You should only use such ports if you really have to, and you know what you are doing. 
          new features to the interface
               The client remembers the endpoint settings at the last shutdown, and also hides itself to the taskbar if
               it was shut down from the taskbar, but only if the initial connect to the server was successful. 
               The client can now show the current song title, and the winamp version. 
               The full playlist is available, and can be deleted/added to using add files with a right-click menu. 
     05/03/00 third release - major upgrade of the interface
          New Features: 
          interface redesign
          The server is now intended to be entirely a pass-through server
          - as winamp gains capabilities, the client can be altered to exploit them, and different/new ideas can be
          tried in the client(s?) without alteration of the server.
          The server interface is independent of the previous version, and they can run side by side. 
          Winamp status is now returned!
          Winamp's playing status is polled every second, where the RPC call succeeds, and every 5s after a failure.
          The status is displayed on the new-look form and the taskbar. 
          Client is now registry aware - settings are per user, and loaded/saved on startup/shutdown.
          Some more options, and a few cosmetic alterations. 
          Pause now checks for the status, and displays the appropriate action.
          More crucially, pause checks winamp's state and only pauses where appropriate (this can catch people
          out otherwise in an office). 
          The old style interface for sending strings appears to be broken in winamp V2.6 (access violation and
          crashes out)
          so, have to change approach. This means add directory does not work - don't know why.
          However, add file accepts multiple files, so no great loss there. 
     15/02/00 second release 
          Bug Fixes: 
          Add file/playlist/directory was broken in the last version

          sorry!

          now fixed, though I will be putting a bit more thought into this whole area
          re: machines not on an NT domain - any suggestions, anyone?
          Stay tuned. 
     05/02/00 first release candidate
          Features: 
          Client 
          Networking
          Uses tcp/ip and (through no effort of my own )WINS to allow local machine names and port nos to be
          specified for the server. 
          Server
          Simply start it up, the port is hard-coded (sorry), and the machine name and the port number are
          displayed.
          If winamp is running on that machine, it should be able to send messages to it, as far as I know.
          There is minimal messaging for errors. 
          Fatal Problems/Bugs: 
          OpenGL
          None known of, though there are some problems I have in debugging that don't appear to be reproducible
          in 'real life'. 
          Windows95
          Windows 95a doesn't have the MS OpenGL as a default; win95b upwards do, so the inclusion of the
          OpenGl libraries is intended as a convenience. Having said that, anyone encountering display problems on
          their system could try installing with that options, as they are the target I built and tested against.
          Use the included dlls, and the recommendation is to install them in app. directory 
          Windows98
          None known 
          WindowsNT4
          None Known 
          Non-Fatal/UI Problems/Bugs: 
          Many, no doubt. I am perfectly open to suggestions for enhancements, though I should point out that the
          client application employs the full set of documented winamp commands I am [a] aware of [b] could get to
          work. A case in point is Add Directory, which had to disappear with the advent of winamp 2.6, as one of
          the IPC methods used to communicate with it invariably crashed winamp, and the other just does nothing. 


