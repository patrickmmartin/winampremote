// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VersionInfo.pas' rev: 4.00

#ifndef VersionInfoHPP
#define VersionInfoHPP

#pragma delphiheader begin
#pragma option push -w-
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Versioninfo
{
//-- type declarations -------------------------------------------------------
typedef AnsiString VersionInfo__2[10];

class DELPHICLASS TVersionInfo;
#pragma pack(push, 4)
class PASCALIMPLEMENTATION TVersionInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString VersionInfo;
	AnsiString LangCharset;
	bool InfoAvailable;
	AnsiString StandardKeys[10];
	AnsiString __fastcall GetVersionInfo(int Index);
	void __fastcall SetVersionInfo(int Index, AnsiString Value);
	AnsiString __fastcall GetKey(AnsiString ThisKeyName);
	AnsiString __fastcall GetBuildNumber();
	
public:
	__fastcall TVersionInfo(AnsiString ThisSourceFile);
	__property AnsiString Key[AnsiString KeyName] = {read=GetKey};
	__property AnsiString CompanyName = {read=GetVersionInfo, write=SetVersionInfo, index=0};
	__property AnsiString FileDescription = {read=GetVersionInfo, index=1};
	__property AnsiString FileVersion = {read=GetVersionInfo, index=2};
	__property AnsiString InternalName = {read=GetVersionInfo, index=3};
	__property AnsiString Copyright = {read=GetVersionInfo, index=4};
	__property AnsiString TradeMarks = {read=GetVersionInfo, index=5};
	__property AnsiString OriginalFileName = {read=GetVersionInfo, index=6};
	__property AnsiString ProductName = {read=GetVersionInfo, write=SetVersionInfo, index=7};
	__property AnsiString ProductVersion = {read=GetVersionInfo, write=SetVersionInfo, index=8};
	__property AnsiString Comments = {read=GetVersionInfo, index=9};
	__property AnsiString BuildNumber = {read=GetBuildNumber};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TVersionInfo(void) { }
	#pragma option pop
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxVersionKeys = 0x9;

}	/* namespace Versioninfo */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Versioninfo;
#endif
#pragma option pop	// -w-

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VersionInfo
