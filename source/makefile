
ROOT = $(MAKEDIR)\..
BRCC = $(ROOT)\bin\brcc32.exe 

.silent
default: clean winampinterface.lib all docs

clean: clean-setup
	echo ========== cleaning object files ======
	-for %D in (bin obj lib) do @DEL /F /Q /S ..\%D\*.* 1>nul
	
clean-client-reg:
	@echo delete the client registry settings...
	reg import WARC-client-del.reg
	
clean-server-reg:	
	@echo delete the server registry settings...
	reg import WARC-server-del.reg
		
# this override of the default implicit rule is a hack for not getting a ".bpr.exe" rule working correctly
# to override the default .cpp.exe rule
# currently relying upon BCB convention of a main cpp file named for the project listing project files
.cpp.exe: 
	echo ========== build for $@ ======
	if not exist ..\bin mkdir ..\bin
	if not exist ..\obj mkdir ..\obj
	if not exist ..\obj\$& mkdir ..\obj\$&
	buildkeys $@
	$(BRCC) $&.rcscript
	bpr2mak -q $&.bpr
	echo PROJECT=..\bin\$&.exe >> $&.mak
	make -a -f $&.mak

# this copy of the .exe rule is a similar hack for not getting a ".bpr.dll" rule working correctly
# currently relying upon BCB convention of a main cpp file named for the project listing project files
.cpp.dll: 
	echo ========== build for $@ ======
	if not exist ..\bin mkdir ..\bin
	if not exist ..\obj mkdir ..\obj
	if not exist ..\obj\$& mkdir ..\obj\$&
	buildkeys $@
	$(BRCC) $&.rcscript
	bpr2mak -q $&.bpr
	echo PROJECT=..\bin\$&.dll >> $&.mak
	make -a -f $&.mak
	
midl: 
	echo ========== running MIDL compiler ======
	# this is invoked by the IDE also, hence why it's a script
	runmidl.bat
	
winampinterface.lib: midl
	# build lib
	echo ========== build for $@ ======
	if not exist ..\obj mkdir ..\obj
	if not exist ..\lib mkdir ..\lib
	if not exist ..\obj\$& mkdir ..\obj\$&
	bpr2mak -q -t$(ROOT)\bin\deflib.bmk $&.bpr
	make -B -a -$(MAKEFLAGS) -f $&.mak

unittests.exe: 

testserver.exe: 

conremote.exe: 

remote.exe: 

winampclient.dll: 

gen_RPCinterface.dll: 

winampserver.exe: 

clean-setup:
	build-setup Clean

setup: remote.exe gen_RPCinterface.dll
	build-setup Build

TARGETS= unittests.exe\
		testserver.exe\
		conremote.exe\
		remote.exe\
		winampclient.dll\
		gen_RPCinterface.dll 

all: $(TARGETS)

help:
	@echo targets built by this makefile: $(TARGETS)
	@echo.
	@echo help - shows this output
	@echo all - builds all targets
	@echo clean - cleans all targets
	@echo test-suite - performs some tests on targets
	@echo midl - compiles the IDL files
	@echo docs - generates the doxygen output
	@echo setup	- builds the installer
	@echo copy-plugin - installs the plugin to the default location for the OS
	@echo default - cleans, builds IDL and lib and then all targets
	
docs:
	# ideally would discover from the Doxygen
	echo ========== cleaning doxygen output ======
	>nul del /S /Q ..\doc\*.* 
	echo ========== building doxygen output ======
	>nul doxygen 
	
	
WINAMP_PLUGINS_DEFAULT=$(PROGRAMFILES)\Winamp\Plugins
!ifdef PROGRAMFILES(x86)
WINAMP_PLUGINS_DEFAULT=$(PROGRAMFILES(x86))\Winamp\Plugins
!endif
	
copy-plugin:
	echo ========== copying plugin dll to $(WINAMP_PLUGINS_DEFAULT) ======
	copy ..\bin\gen_RPCinterface.dll "$(WINAMP_PLUGINS_DEFAULT)"
	
pre-tests: 
	echo ========== running tests ======

post-tests: 
	echo ========== completed tests ======

tests: pre-tests test-suite post-tests
		
test-builds:
	echo ========== ensuring independent builds ======
	make clean testserver.exe > nul
	make clean testclient.exe > nul
	make clean conremote.exe > nul
	make clean remote.exe > nul
	make clean winampclient.dll > nul
	make clean gen_RPCinterface.dll > nul
	@echo independent builds completed

run-unittests: 
	echo running unit tests ...
	-..\bin\unittests  -w NoAssertions
	echo unit tests complete

start-mockserver:  
	echo running mock server ...
	start "mock server"  ..\bin\testserver	
	echo mock server launched
	
test-suite: testserver.exe unittests.exe start-mockserver run-unittests
	echo killing mock server
	-taskkill /IM testserver.exe > nul	
	echo mock server killed

install:
	echo installer action: $&
	pushd ..\bin & msiexec /i WinampRemote.msi /quiet /l* $&.log	
	
install-typical:
	echo installer action: $&
	pushd ..\bin & msiexec /i WinampRemote.msi /quiet /l* $&.log INSTALLLEVEL=1	
	
install-typical-override:
	echo installer action: $&
	pushd ..\bin & msiexec /i WinampRemote.msi /quiet /l* $&.log INSTALLLEVEL=1	INSTALLDIR=c:\WinampRemote
	
install-complete:
	echo installer action: $&
	pushd ..\bin & msiexec /i WinampRemote.msi /quiet /l* $&.log INSTALLLEVEL=3 
	
install-complete-override:
	echo installer action: $&
	pushd ..\bin & msiexec /i WinampRemote.msi /quiet /l* $&.log INSTALLLEVEL=3	INSTALLDIR=c:\WinampRemote WINAMP_PLUGIN_DIR=c:\WinampRemote
	
uninstall:
	echo installer action: $&
	pushd ..\bin & msiexec /x WinampRemote.msi /quiet /l* $&.log	
		

install-gui:
	echo installer action: $&
	pushd ..\bin & msiexec /i WinampRemote.msi /l* $&.log	
	
uninstall-gui:
	echo installer action: $&
	pushd ..\bin & msiexec /x WinampRemote.msi /l* $&.log	
				