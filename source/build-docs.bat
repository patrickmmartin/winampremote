@setlocal
@echo off

:: parse and output various items

FOR /F "eol=; delims=, tokens=1,2,3,4" %%i IN (version.txt) DO (
SET APPVER=%%i.%%j.%%k.%%l
)


( type Doxyfile & echo PROJECT_NUMBER=%APPVER% ) | Doxygen

@endlocal