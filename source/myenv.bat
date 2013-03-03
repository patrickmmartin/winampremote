@echo off
IF "%ProgramFiles(x86)%"=="" echo setting 32-bit Windows path & SET PATH=C:\WINDOWS\System32;C:\WINDOWS\System32\wbem;"C:\PROGRA~1\Borland\CBUILD~1\bin";"C:\Program Files\Git\cmd";"c:\Program Files\doxygen\bin" & exit /b
echo setting 64-bit Windows path & SET PATH=C:\WINDOWS\System32;C:\CBuilder5\bin;"C:\Program Files (x86)\Git\cmd";"c:\Program Files\doxygen\bin"
