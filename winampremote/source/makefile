.silent
default: clean configure all

#could do with an implicit rule for .mak

configure:
	echo creating command line build files
	bpr2mak -q conremote.bpr
	bpr2mak -q remote.bpr 
	bpr2mak -q winampclient.bpr 
	bpr2mak -q gen_RPCinterface.bpr 

conremote.exe:
	make -f conremote.mak

remote.exe:
	make -f remote.mak

winampclient.dll:
	make -f winampclient.mak

gen_RPCinterface.dll:
	make -f gen_RPCinterface.mak


targets: conremote.exe remote.exe winampclient.dll gen_RPCinterface.dll

all: configure targets

clean:
	clean.bat

