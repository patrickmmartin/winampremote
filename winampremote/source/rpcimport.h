extern "C"
{

__declspec(dllexport) __stdcall void Bind(unsigned char * NetworkAddress, unsigned char * EndPoint);
__declspec(dllexport) __stdcall void UnBind(void);

__declspec(dllexport) __stdcall void SendString(char * pszString);
__declspec(dllexport) __stdcall void ExecuteMessage(char * pszString, int command);
__declspec(dllexport) __stdcall void ExecuteStringMessage(char * pszString, char * pszParam, int command);
__declspec(dllexport) __stdcall int StringResult(char * pszString, int command, int data);
__declspec(dllexport) __stdcall int IntegerResult(char * pszString, int command, int data);
__declspec(dllexport) __stdcall void Shutdown(void);

__declspec(dllexport)void __stdcall SendList(char * pszString, void * Buffer, int Size, int Command);
__declspec(dllexport)void __stdcall GetList(char * pszString, void ** Buffer, int& Size, int Command);


}

 