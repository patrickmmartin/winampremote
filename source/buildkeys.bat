@setlocal
@echo off

:: parse and output various items

FOR /F "eol=; delims=, tokens=1,2,3,4" %%i IN (version.txt) DO (
  echo Application version is [%%i,%%j,%%k,%%l]
  echo FILEVERSION %%i,%%j,%%k,%%l > build_ffi.rcinc
  echo               VALUE "FileVersion", "%%i.%%j.%%k.%%l\0" > buildkeys.rcinc
)

echo               VALUE "Build Time", "%DATE% %TIME%\0" >> buildkeys.rcinc
echo               VALUE "Build Machine", "%COMPUTERNAME%\0" >> buildkeys.rcinc

:: build base script from the passed basename

 >%~n1.rcscript echo #include "versioninfo-pre.rcinc""
>>%~n1.rcscript echo           VALUE "OriginalFilename", "%1\0"
>>%~n1.rcscript echo           VALUE "InternalName", "%~n1\0"
>>%~n1.rcscript echo #include "versioninfo-post.rcinc"
