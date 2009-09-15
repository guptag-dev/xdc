#include "uiinterface/uiconnection.h"
#include "uiinterface/uiconnectionlist.h"

#include <QByteArray>

UiConnection::UiConnection(QTcpSocket* s) : conn(s) {
	// set up signals and slots
	connect(conn, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
	connect(conn, SIGNAL(readyRead()), this, SLOT(readyRead()));

	UiConnectionList::getInstance()->addConnection(this);
}
UiConnection::~UiConnection() {
	UiConnectionList::getInstance()->removeConnection(this);
	delete conn;
}

// protected slots
void UiConnection::readyRead() {
	// todo: right now, assuming "data" contains a complete message from ui
	//       need to handle broken reads
	QString data = conn->readAll();

}
void UiConnection::stateChanged(QAbstractSocket::SocketState state) {
	// todo: if state==disconnected, then do appropriate stuff
}
