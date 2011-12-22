extern "C"
{

  __declspec(dllexport) void __stdcall ClientFree(void * mem);

  __declspec(dllexport) void __stdcall Bind(char * NetworkAddress, char * EndPoint);
  __declspec(dllexport) void __stdcall UnBind(void);

  __declspec(dllexport) void __stdcall SendString(char * pszString);
  __declspec(dllexport) void __stdcall ExecuteMessage(char * pszString, int command);
  __declspec(dllexport) void __stdcall ExecuteStringMessage(char * pszString, char * pszParam, int command);
  __declspec(dllexport) int __stdcall StringResult(char * pszString, int command, int data);
  __declspec(dllexport) int __stdcall IntegerResult(char * pszString, int command, int data);
  __declspec(dllexport) void __stdcall Shutdown(void);

  __declspec(dllexport) void __stdcall SetStringList(char * pszString, void * Buffer, int Size, int Command);
  __declspec(dllexport) void __stdcall GetStringList(char * pszString, void ** Buffer, int& Size, int Command);

  __declspec(dllexport) int __stdcall SafeSendString(char * pszString);
  __declspec(dllexport) int __stdcall SafeExecuteMessage(char * pszString, int command);
  __declspec(dllexport) int __stdcall SafeExecuteStringMessage(char * pszString, char * pszParam, int command);
  __declspec(dllexport) int __stdcall SafeStringResult(char * pszString, int command, int data, int * Result);
  __declspec(dllexport) int __stdcall SafeIntegerResult(char * pszString, int command, int data, int * Result);

  __declspec(dllexport) int __stdcall SafeSetStringList(char * pszString, void * Buffer, int Size, int Command);
  __declspec(dllexport) int __stdcall SafeGetStringList(char * pszString, void ** Buffer, int& Size, int Command);

}

