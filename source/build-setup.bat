@setlocal
@echo off

:: parse and output various items

FOR /F "eol=; delims=, tokens=1,2,3,4" %%i IN (version.txt) DO (
SET APPVER=%%i.%%j.%%k.%%l
)

SET INSTALLER=WinampRemote.msi

:: clean is a well-known name
 
if "%1"=="Clean" (
	echo cleaning installer for [%APPVER%]
	C:\Windows\Microsoft.NET\Framework\v2.0.50727\MSBuild /nologo ..\setup\WinampRemote.wixproj  /t:%1
	echo deleting msi file %INSTALLER%
	del /Q ..\bin\%INSTALLER% 2>nul


) else (
	echo building installer target %1 for [%APPVER%]
	C:\Windows\Microsoft.NET\Framework\v2.0.50727\MSBuild /nologo ..\setup\WinampRemote.wixproj  /t:%1

	echo copying installer to %INSTALLER%
	if "%1"=="Build" copy /Y ..\setup\bin\Debug\WinampRemote.msi ..\bin\%INSTALLER%
) 


@endlocal