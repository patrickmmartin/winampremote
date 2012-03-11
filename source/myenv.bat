@echo off
IF "%ProgramFiles(x86)%"=="" (
echo it's 32 bit captain
SET PATH="C:\PROGRA~1\Borland\CBUILD~1\bin";"C:\Program Files\Git\cmd";"c:\Program Files\doxygen\bin";C:\Windows\System32
) else (
echo 64 bits detected, captain
SET PATH=C:\CBuilder5\bin;"C:\Program Files (x86)\Git\cmd";"c:\Program Files (x86)\doxygen\bin";C:\Windows\System32
