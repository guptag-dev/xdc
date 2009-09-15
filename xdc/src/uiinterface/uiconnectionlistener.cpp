#include "uiinterface/uiconnectionlistener.h"
#include "uiinterface/uiconnection.h"

UiConnectionListener::UiConnectionListener() {
	sock = new QTcpServer;
	connect(sock, SIGNAL(newConnection()), this, SLOT(newConnection()));
}
UiConnectionListener::~UiConnectionListener() {
	sock->close();
	delete sock;
}

//properties
void UiConnectionListener::setInterface(QHostAddress addr) {
	interface = addr;
}
QHostAddress UiConnectionListener::getInterface() {
	return interface;
}
void UiConnectionListener::setPort(qint16 p) {
	port = p;
}
// todo: find other classes which are declaring "port" as qint16 instead of quint16
quint16 UiConnectionListener::getPort() {
	return port;
}

// public slots
void UiConnectionListener::start() {
	bool success = sock->listen(interface,port);
	if( !success ) {
		couldNotBindError();
	}
}

// protected slots
void UiConnectionListener::newConnection() {
	QTcpSocket *conn = sock->nextPendingConnection();
	qDebug() << "new connection recvd";
	new UiConnection(conn); // this will suffice
}
void UiConnectionListener::couldNotBindError() {
	// todo: handle errors like unable to bind to port, etc.
}
