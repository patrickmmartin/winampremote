#pragma once

#include "windows.h"

typedef struct tagWinampGeneralPurposePlugin{
	int version;
	char *description;
	int (*init)();
	void (*config)();
	void (*quit)();
	HWND hwndParent;
	HINSTANCE hDllInstance;
} winampGeneralPurposePlugin, *pwinampGeneralPurposePlugin;

#define GPPHDR_VER 0x10

extern winampGeneralPurposePlugin plugin;

void config(void);
void quit(void);
int init(void);

