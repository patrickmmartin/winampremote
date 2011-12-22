//---------------------------------------------------------------------------
#ifndef IPAddressUH
#define IPAddressUH
//---------------------------------------------------------------------------
#endif

void __fastcall GetIPAddress(char * HostName, AnsiString &ResolvedName, TStringList * Addresses, TStringList * Aliases);

//class EIPException;
class EIPException : public Sysutils::Exception
{
public:
	 __fastcall EIPException(const System::AnsiString Msg) : Sysutils::Exception(Msg) { }
};

