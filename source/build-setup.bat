@setlocal
@echo off

:: parse and output various items

FOR /F "eol=; delims=, tokens=1,2,3,4" %%i IN (version.txt) DO (
SET APPVER=%%i.%%j.%%k.%%l
)

echo building installer for [%APPVER%]

C:\Windows\Microsoft.NET\Framework\v2.0.50727\MSBuild /nologo ..\setup\WinampRemote.wixproj  /t:%1

@endlocal