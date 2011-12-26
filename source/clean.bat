REM CommandInterpreter: $(COMSPEC)
for %%D in (bin obj lib) do ( del /F /Q /S ..\%%D\*.* )
