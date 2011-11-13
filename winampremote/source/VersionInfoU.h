//---------------------------------------------------------------------------
#ifndef VersionInfoUH
#define VersionInfoUH
//---------------------------------------------------------------------------


extern const int MaxVersionKeys;
extern const AnsiString VersionKeyNames[];

class TModuleVersionInfo
{

private:
	void * VersionInfo;
	AnsiString LangCharset;
	bool InfoAvailable;
	AnsiString StandardKeys[10];
	AnsiString __fastcall GetVersionInfo(int Index);
	AnsiString __fastcall GetKey(AnsiString ThisKeyName);

public:
	__fastcall TModuleVersionInfo(AnsiString ThisSourceFile);
	__property AnsiString Key[AnsiString KeyName] = {read=GetKey};
	__property AnsiString CompanyName = {read=GetVersionInfo, index=0};
	__property AnsiString FileDescription = {read=GetVersionInfo, index=1};
	__property AnsiString FileVersion = {read=GetVersionInfo, index=2};
	__property AnsiString InternalName = {read=GetVersionInfo, index=3};
	__property AnsiString Copyright = {read=GetVersionInfo, index=4};
	__property AnsiString TradeMarks = {read=GetVersionInfo, index=5};
	__property AnsiString OriginalFileName = {read=GetVersionInfo, index=6};
	__property AnsiString ProductName = {read=GetVersionInfo, index=7};
	__property AnsiString ProductVersion = {read=GetVersionInfo, index=8};
	__property AnsiString Comments = {read=GetVersionInfo, index=9};
public:
	__fastcall virtual ~TModuleVersionInfo(void);

};

#endif

