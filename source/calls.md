# actions available from the API using the function values  

gleaned from the source and grouped by category

## basic song playback control / querying 
```
ExecuteMessage	WINAMP_PLAYENTRY
ExecuteMessage	WINAMP_PAUSE
ExecuteMessage	WINAMP_STOP
ExecuteMessage	WINAMP_STOPFADE
ExecuteMessage	WINAMP_STOPAFTERCURRENT
IntegerResult  IPC_ISPLAYING
```

## playlist play options
```
ExecuteMessage  WINAMP_FILE_REPEAT
ExecuteMessage	WINAMP_FILE_SHUFFLE
```

## playlist manipulation
```
IntegerResult	IPC_DELETE, 0
```

## basic playlist navigation 
```
ExecuteMessage	WINAMP_BACK5S
ExecuteMessage	WINAMP_FORWARD5S
ExecuteMessage	WINAMP_STARTOFPLAYLIST
ExecuteMessage	WINAMP_ENDOFPLAYLIST
ExecuteMessage	WINAMP_PREVIOUS
ExecuteMessage	WINAMP_NEXT
IntegerResult  IPC_SETPLAYLISTPOS, Index
IntegerResult	IPC_STARTPLAY, 0
IntegerResult  IPC_JUMPTOTIME, position in list in seconds
```

## playlist query commands
```
IntegerResult  IPC_GETLISTLENGTH, 0
IntegerResult	IPC_GETLISTPOS, 0
IntegerResult	IPC_GETOUTPUTTIME, 0
IntegerResult	IPC_GETOUTPUTTIME, 1
IntegerResult	IPC_GETREPEATOPTION, 0 // Repeat
IntegerResult	IPC_GETSHUFFLEOPTION, 0 // Shuffle
```

## playlist querying
```
StringResult  IPC_GETPLAYLIST, Index
StringResult	IPC_GETPLAYLISTFILE, i
```

## EQ data (0-9 and Autoload) (what's 10?)
```
IntegerResult	IPC_GETEQDATA, Index (11 = AutoLoad)
IntegerResult IPC_SETEQDATA, Index (11 = AutoLoad) 
IntegerResult	IPC_SETPANNING, Position
IntegerResult	IPC_SETVOLUME, Position
```

## get the host winamp version
```
IntegerResult	IPC_GETVERSION, 0
```

