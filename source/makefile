
.silent
default: clean configure all

#could do with an implicit rule for .mak

bin: 
	if not exist ..\bin mkdir ..\bin

obj-base:
	if not exist ..\obj mkdir ..\obj
obj-testserver: obj-base
	if not exist ..\obj\remote mkdir ..\obj\testserver
obj-testclient: obj-base
	if not exist ..\obj\remote mkdir ..\obj\testclient
obj-remote: obj-base
	if not exist ..\obj\remote mkdir ..\obj\remote
obj-gen_RPCinterface: obj-base
	if not exist ..\obj\gen_RPCinterface mkdir ..\obj\gen_RPCinterface
obj-conremote: obj-base
	if not exist ..\obj\conremote mkdir ..\obj\conremote
obj-winampclient: obj-base
	if not exist ..\obj\winampclient mkdir ..\obj\winampclient
obj-winampserver: obj-base
	if not exist ..\obj\winampserver mkdir ..\obj\winampserver

obj: obj-base obj-remote  obj-gen_RPCinterface obj-conremote obj-winampclient obj-winampserver



configure:
	# empty task
	

midl: 
	runmidl.bat

testserver.exe: bin obj-testserver midl
	bpr2mak -q testserver.bpr > nul
	make -f testserver.mak

testclient.exe: bin obj-testclient midl
	bpr2mak -q testclient.bpr > nul
	make -f testclient.mak

conremote.exe: bin obj-conremote midl
	bpr2mak -q conremote.bpr > nul
	make -f conremote.mak

remote.exe: bin obj-remote midl
	bpr2mak -q remote.bpr > nul
	make -f remote.mak

winampclient.dll: bin obj-winampclient midl
	bpr2mak -q winampclient.bpr > nul
	make -f winampclient.mak

gen_RPCinterface.dll: bin obj-gen_RPCinterface midl
	bpr2mak -q gen_RPCinterface.bpr > nul
	make -f gen_RPCinterface.mak

winampserver.exe: bin obj-winampserver midl
	bpr2mak -q winampserver.bpr > nul
	make -f winampserver.mak


targets: testserver.exe testclient.exe conremote.exe remote.exe winampserver.exe winampclient.dll gen_RPCinterface.dll

all: configure targets

clean:
	if exist ..\obj del /F /Q /S ..\obj\*.* > nul
	if exist ..\bin del /F /Q /S ..\bin\*.* > nul


pre-tests: 
	@echo running tests ...

post-tests: 
	@echo completed tests

tests: pre-tests test-builds post-tests
	
	

test-builds:
	@echo ensuring independent builds ...
	make clean testserver.exe > nul
	make clean testclient.exe > nul
	make clean conremote.exe > nul
	make clean remote.exe > nul
	make clean winampclient.dll > nul
	make clean gen_RPCinterface.dll > nul
	make clean winampserver.exe > nul
	@echo independent builds completed


