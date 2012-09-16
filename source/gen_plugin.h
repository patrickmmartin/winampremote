
#ifndef gen_pluginH
#define gen_pluginH



typedef struct {
	int version;
	char *description;
	int (*init)();
	void (*config)();
	void (*quit)();
	HWND hwndParent;
	HINSTANCE hDllInstance;
} winampGeneralPurposePlugin;

#define GPPHDR_VER 0x10

extern winampGeneralPurposePlugin plugin;

typedef winampGeneralPurposePlugin * (*winampGeneralPurposePluginGetter)();
#endif


void config(void);
void quit(void);
int init(void);


