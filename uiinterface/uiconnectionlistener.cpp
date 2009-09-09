#include "uiconnectionlistener.h"

UiConnectionListener::UiConnectionListener() {
	sock = new QTcpServer;
	connect(sock, SIGNAL(newConnection()), this, SLOT(newConnection()));
}
UiConnectionListener::~UiConnectionListener() {
	sock->close();
	delete sock;
}

// public slots
void UiConnectionListener::start() {
}

// protected slots
void UiConnectionListener::newConnection() {
	QTcpSocket *conn = sock->nextPendingConnection();
	// todo: wrap 'conn' in a UiConnection.
}
