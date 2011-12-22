REM CommandInterpreter: $(COMSPEC)
MIDL3 /error stub_data -cpp_cmd CPP32.exe -cpp_opt "-P- -oCON "  winampinterface.idl
pause
