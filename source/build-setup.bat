@setlocal
@echo off

:: parse and output various items

FOR /F "eol=; delims=, tokens=1,2,3,4" %%i IN (version.txt) DO (
SET APPVER=%%i.%%j.%%k.%%l
)

echo building installer for [%APPVER%]

C:\Windows\Microsoft.NET\Framework\v2.0.50727\MSBuild /nologo ..\setup\WinampRemote.wixproj  /t:%1

SET INSTALLER=WinampRemote-%APPVER%.msi

if "%1"=="Build" (
	echo copying installer to %INSTALLER%
	copy /Y ..\setup\bin\Debug\WinampRemote.msi ..\bin\%INSTALLER%
) else (
    del /Q ..\bin\%INSTALLER% 2>nul
) 


@endlocal