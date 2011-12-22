; Pimpscript file v1.3.0
; Copyright (C) 1999 Nullsoft Inc.
; You can comment by starting lines with ; or #.

; Name specifies what the installer will use for its name
Name winamp remote control suite

; Text specifies what text will appear in the dialog window
Text This will install the winamp remote control suite DCE-RPC plugin for winamp

; OutFile specifies where to write the installer executable to
OutFile rpcwinamp.exe


; You can add a line that just says Silent to make the installer silent.
;Silent



SetOutPath $INSTDIR\PLugins

AddFile ..\gen_RPCinterface.dll


; Path is relative unless you use a variable (see DefaultDir).
ExecFile readme.html

; end
