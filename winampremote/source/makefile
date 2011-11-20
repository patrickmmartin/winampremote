
.silent
default: clean configure all

#could do with an implicit rule for .mak

configure:
	echo creating command line build files
	bpr2mak -q conremote.bpr
	bpr2mak -q remote.bpr 
	bpr2mak -q winampclient.bpr 
	bpr2mak -q gen_RPCinterface.bpr 
	bpr2mak -q winampserver.bpr 

midl: 
	runmidl.bat

conremote.exe: midl
	make -f conremote.mak

remote.exe: midl
	make -f remote.mak

winampclient.dll: midl
	make -f winampclient.mak

gen_RPCinterface.dll: midl
	make -f gen_RPCinterface.mak

winampserver.exe: midl
	make -f winampserver.mak


targets: conremote.exe remote.exe winampserver.exe winampclient.dll gen_RPCinterface.dll

all: configure targets

clean:
	clean.bat

