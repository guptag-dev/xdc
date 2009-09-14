#ifndef GLOBALS_H
#define GLOBALS_H

#include "uiinterface/uiconnectionlist.h"
#include "uiinterface/uinotifier.h"
#include "uiinterface/uireader.h"

namespace Globals {
	extern UiConnectionList *connectionList;
	extern UiInterface *uiInterface;
	extern UiReader *reader;
}

#endif // GLOBALS_H
