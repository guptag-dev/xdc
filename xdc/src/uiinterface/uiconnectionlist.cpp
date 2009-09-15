#include "uiinterface/uiconnectionlist.h"
#include "uiinterface/uiconnection.h"

UiConnectionList::UiConnectionList() {}

// getInstance method
UiConnectionList* UiConnectionList::getInstance() {
	static UiConnectionList theList;
	return &theList;
}

void UiConnectionList::addConnection(UiConnection* conn) {
	connList.append(conn);
	// todo: connect some required signals and slots
}
void UiConnectionList::removeConnection(UiConnection* conn) {
	connList.removeOne(conn);
	// todo: disconnect some signals and slots
}
