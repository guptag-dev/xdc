#include "xdcstartup.h"
#include "uiinterface/uiconnectionlist.h"
#include "uiinterface/uireader.h"
#include "uiinterface/uinotifier.h"

#include <QHostAddress>

XDCStartup::XDCStartup() {
	// pre construct the singletons
	UiConnectionList::getInstance();
	UiReader::getInstance();
	UiNotifier::getInstance();

	// set up a listener
	listener = new UiConnectionListener();
	listener->setInterface(QHostAddress::Any);
	listener->setPort(14112);
	listener->start();
}
XDCStartup::~XDCStartup() {
	delete listener;
}
