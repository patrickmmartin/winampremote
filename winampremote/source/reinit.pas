(*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000,2001,2002  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@freenet.co.uk.
*)
unit ReInit;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms;

procedure ReinitializeForms;
function LoadNewResourceModule(Locale: LCID): Longint;

implementation

type
  TAsInheritedReader = class(TReader)
  public
    procedure ReadPrefix(var Flags: TFilerFlags; var AChildPos: Integer); override;
  end;

procedure TAsInheritedReader.ReadPrefix(var Flags: TFilerFlags; var AChildPos: Integer);
begin
  inherited ReadPrefix(Flags, AChildPos);
  Include(Flags, ffInherited);
end;

function SetResourceHInstance(NewInstance: Longint): Longint;
var
  CurModule: PLibModule;
begin
  CurModule := LibModuleList;
  Result := 0;
  while CurModule <> nil do
  begin
    if CurModule.Instance = HInstance then
    begin
      if CurModule.ResInstance <> CurModule.Instance then
        FreeLibrary(CurModule.ResInstance);
      CurModule.ResInstance := NewInstance;
      Result := NewInstance;
      Exit;
    end;
    CurModule := CurModule.Next;
  end;
end;

function LoadNewResourceModule(Locale: LCID): Longint;
var
  FileName: array [0..260] of char;
  P: PChar;
  LocaleName: array[0..4] of Char;
  NewInst: Longint;
begin
  GetModuleFileName(HInstance, FileName, SizeOf(FileName));
  GetLocaleInfo(Locale, LOCALE_SABBREVLANGNAME, LocaleName, SizeOf(LocaleName));
  P := PChar(@FileName) + lstrlen(FileName);
  while (P^ <> '.') and (P <> @FileName) do Dec(P);
  NewInst := 0;
  Result := 0;
  if P <> @FileName then
  begin
    Inc(P);
    if LocaleName[0] <> #0 then
    begin
      // Then look for a potential language/country translation
      lstrcpy(P, LocaleName);
      NewInst := LoadLibraryEx(FileName, 0, LOAD_LIBRARY_AS_DATAFILE);
      if NewInst = 0 then
      begin
        // Finally look for a language only translation
        LocaleName[2] := #0;
        lstrcpy(P, LocaleName);
        NewInst := LoadLibraryEx(FileName, 0, LOAD_LIBRARY_AS_DATAFILE);
      end;
    end;
  end;
  if NewInst <> 0 then
    Result := SetResourceHInstance(NewInst)
end;

function InternalReloadComponentRes(const ResName: string; HInst: THandle; var Instance: TComponent): Boolean;
var
  HRsrc: THandle;
  ResStream: TResourceStream;
  AsInheritedReader: TAsInheritedReader;
begin                   { avoid possible EResNotFound exception }
  if HInst = 0 then HInst := HInstance;
  HRsrc := FindResource(HInst, PChar(ResName), RT_RCDATA);
  Result := HRsrc <> 0;
  if not Result then Exit;
  ResStream := TResourceStream.Create(HInst, ResName, RT_RCDATA);
  try
    AsInheritedReader := TAsInheritedReader.Create(ResStream, 4096);
    try
      Instance := AsInheritedReader.ReadRootComponent(Instance);
    finally
      AsInheritedReader.Free;
    end;
  finally
    ResStream.Free;
  end;
  Result := True;
end;

function ReloadInheritedComponent(Instance: TComponent; RootAncestor: TClass): Boolean;

  function InitComponent(ClassType: TClass): Boolean;
  begin
    Result := False;
    if (ClassType = TComponent) or (ClassType = RootAncestor) then Exit;
    Result := InitComponent(ClassType.ClassParent);
    Result := InternalReloadComponentRes(ClassType.ClassName, FindResourceHInstance(
      FindClassHInstance(ClassType)), Instance) or Result;
  end;

begin
  Result := InitComponent(Instance.ClassType);
end;

procedure ReinitializeForms;
var
  Count: Integer;
  I: Integer;
  Form: TForm;
begin
  Count := Screen.FormCount;
  for I := 0 to Count - 1 do
  begin
    Form := Screen.Forms[I];
    ReloadInheritedComponent(Form, TForm);
  end;
end;

end.
