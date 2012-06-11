ROOT = $(MAKEDIR)\..
BRCC = $(ROOT)\bin\brcc32.exe 

.silent
default: clean all

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

unittests.exe: winampinterface.lib

testserver.exe: winampinterface.lib

testclient.exe: winampinterface.lib

conremote.exe: winampinterface.lib

remote.exe: winampinterface.lib

winampclient.dll: winampinterface.lib

gen_RPCinterface.dll: winampinterface.lib

winampserver.exe: winampinterface.lib

clean-setup:
	build-setup Clean

setup: remote.exe gen_RPCinterface.dll
	build-setup Build

TARGETS= winampinterface.lib\
		unittests.exe\
		testserver.exe\
		testclient.exe\
		conremote.exe\
		remote.exe\
		winampserver.exe\
		winampclient.dll\
		gen_RPCinterface.dll 

all: $(TARGETS) docs

help:
	@echo targets built by this makefile: $(TARGETS)
	@echo.
	@echo help - shows this output
	@echo all - builds all targets
	@echo clean - cleans all targets
	@echo tests - performs some tests on targets
	@echo midl - compiles the IDL files
	@echo docs - generates the doxygen output
	@echo setup	- builds the installer
	@echo copy-plugin - installs the plugin to the default location for the OS
	@echo default - clean all
	
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

tests: unittests.exe pre-tests unit-tests post-tests
		
test-builds:
	echo ========== ensuring independent builds ======
	make clean testserver.exe > nul
	make clean testclient.exe > nul
	make clean conremote.exe > nul
	make clean remote.exe > nul
	make clean winampclient.dll > nul
	make clean gen_RPCinterface.dll > nul
	make clean winampserver.exe > nul
	@echo independent builds completed
	
unit-tests: testserver.exe
	start "mock server"  ..\bin\testserver	
	..\bin\unittests
	-taskkill /IM testserver.exe	



	