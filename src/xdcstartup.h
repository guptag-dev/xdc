#ifndef XDCSTARTUP_H
#define XDCSTARTUP_H

#include "uiinterface/uiconnectionlistener.h"

class XDCStartup
{
public:
    XDCStartup();
	~XDCStartup();
private:
	UiConnectionListener *listener;
};

#endif // XDCSTARTUP_H
