@echo off
SET FILENAME=%1

if "%FILENAME%"=="" echo usage: %~0 filename && exit /b

for /f "delims=þ  tokens=1" %%i in (%FILENAME%) do (
  @echo %%i 
  call :output %%i
  )

exit /b

:output

  if "%*"==".autodepend"  echo CFLAG1 = -vGc -vGt -vGd $(CFLAG1) &&  echo ALLLIB = cg32.lib $(ALLLIB)

goto :eof


