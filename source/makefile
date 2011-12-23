
.silent
default: clean all

# this is a hack for not getting a ".bpr.exe" rule working correctly
# to override the default .cpp.exe rule
# currently relying upon convention of a main cpp file for the project to work
.cpp.exe: 
	echo ========== build for $@ ======
	if not exist ..\bin mkdir ..\bin
	if not exist ..\obj mkdir ..\obj
	if not exist ..\obj\$($&) mkdir ..\obj\$($&)
	bpr2mak -q $&.bpr
	make -f $&.mak

.cpp.dll: 
	echo ========== build for $@ ======
	if not exist ..\bin mkdir ..\bin
	if not exist ..\obj mkdir ..\obj
	if not exist ..\obj\$($&) mkdir ..\obj\$($&)
	bpr2mak -q $&.bpr
	make -f $&.mak
	
midl:
	# this is invoked by the IDE also, hence why it's a script
	echo ========== running MIDL compiler ======
	runmidl.bat
	
winampinterface_c.c: midl

winampinterface_s.c: midl

testserver.exe: winampinterface_s.c

testclient.exe:  winampinterface_c.c

conremote.exe: winampinterface_c.c

remote.exe: winampinterface_c.c

winampclient.dll: winampinterface_c.c

gen_RPCinterface.dll: winampinterface_s.c

winampserver.exe: winampinterface_s.c

TARGETS= testserver.exe testclient.exe conremote.exe remote.exe winampserver.exe winampclient.dll gen_RPCinterface.dll

all: $(TARGETS)

clean:
	echo ========== cleaning object files ======
	if exist ..\obj del /F /Q /S ..\obj\*.* > nul
	if exist ..\bin del /F /Q /S ..\bin\*.* > nul

help:
	@echo targets built by this makefile: $(TARGETS)
	@echo.
	@echo all - builds all targets
	@echo clean - cleans all targets
	@echo tests - performs some tests on targets
	@echo midl - compiles the IDL files
	@echo default - clean all
	
pre-tests: 
	echo ========== running tests ======

post-tests: 
	echo ========== completed tests ======

tests: pre-tests test-builds post-tests
		
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



	