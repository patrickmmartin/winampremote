REM CommandInterpreter: $(COMSPEC)
MIDL /nologo /error stub_data -cpp_cmd CPP32.exe -cpp_opt "-P- -oCON "  winampinterface.idl
