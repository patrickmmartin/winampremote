; Pimpscript file v1.3.0
; Copyright (C) 1999 Nullsoft Inc.
; You can comment by starting lines with ; or #.


;set prmopt to desktop
DefaultDir $DESKTOP

; Name specifies what the installer will use for its name
Name pmmSoft winamp remote control suite install

; Text specifies what text will appear in the dialog window
Text This will unpack the install the pmmSoft remote control suite plugin and client for winamp

; OutFile specifies where to write the installer executable to
OutFile winampremote.exe

; You can add a line that just says Silent to make the installer silent.
;Silent

SetOutPath $DESKTOP
AddFile winampcontrollerlite.zip
AddFile winampremotereadme.html

; end
