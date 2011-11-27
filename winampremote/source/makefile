
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
	echo creating command line build files
	bpr2mak -q testserver.bpr
	bpr2mak -q testclient.bpr
	bpr2mak -q conremote.bpr
	bpr2mak -q remote.bpr 
	bpr2mak -q winampclient.bpr 
	bpr2mak -q gen_RPCinterface.bpr 
	bpr2mak -q winampserver.bpr 
	

midl: 
	runmidl.bat

testserver.exe: bin obj-testserver midl
	make -f testserver.mak

testclient.exe: bin obj-testclient midl
	make -f testclient.mak

conremote.exe: bin obj-conremote midl
	make -f conremote.mak

remote.exe: bin obj-remote midl
	make -f remote.mak

winampclient.dll: bin obj-winampclient midl
	make -f winampclient.mak

gen_RPCinterface.dll: bin obj-gen_RPCinterface midl
	make -f gen_RPCinterface.mak

winampserver.exe: bin obj-winampserver midl
	make -f winampserver.mak


targets: testserver.exe testclient.exe conremote.exe remote.exe winampserver.exe winampclient.dll gen_RPCinterface.dll

all: configure targets

clean:
	del /F /Q /S ..\obj\*.* > nul
	del /F /Q /S ..\bin\*.* > nul


