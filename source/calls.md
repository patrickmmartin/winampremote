gleaned from the source and grouped by category

```
ExecuteMessage	WINAMP_PLAYENTRY
ExecuteMessage	WINAMP_PAUSE
ExecuteMessage	WINAMP_STOP
ExecuteMessage	WINAMP_STOPFADE
ExecuteMessage	WINAMP_STOPAFTERCURRENT
```

```
ExecuteMessage	WINAMP_BACK5S
ExecuteMessage	WINAMP_FORWARD5S
```

```
ExecuteMessage	WINAMP_STARTOFPLAYLIST
ExecuteMessage	WINAMP_ENDOFPLAYLIST
```

```
ExecuteMessage	WINAMP_PREVIOUS
ExecuteMessage	WINAMP_NEXT
```

```
ExecuteMessage	WINAMP_FILE_REPEAT
ExecuteMessage	WINAMP_FILE_SHUFFLE
```

```
IntegerResult	IPC_DELETE, 0
```

```
IntegerResult	IPC_GETEQDATA, Index
IntegerResult	IPC_GETEQDATA, 11 // AutoLoad
```

```
IntegerResult	IPC_GETLISTLENGTH, 0
IntegerResult	IPC_GETLISTPOS, 0
```

```
IntegerResult	IPC_GETOUTPUTTIME, 0
IntegerResult	IPC_GETOUTPUTTIME, 1
```

```
IntegerResult	IPC_GETREPEATOPTION, 0 // Repeat
IntegerResult	IPC_GETSHUFFLEOPTION, 0 // Shuffle
```

```
IntegerResult	IPC_GETVERSION, 0
```

```
IntegerResult	IPC_ISPLAYING, 0
IntegerResult	IPC_JUMPTOTIME, position in list in seconds
```

```
IntegerResult	IPC_SETEQDATA,Checked 
IntegerResult	IPC_SETPANNING, Position
IntegerResult	IPC_SETVOLUME, Position
```

```
IntegerResult	IPC_SETPLAYLISTPOS, Index
```

```
IntegerResult	IPC_STARTPLAY, 0
```

```
StringResult	IPC_GETPLAYLIST, Index
StringResult	IPC_GETPLAYLISTFILE, i
```