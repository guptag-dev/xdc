#include "hubconnection.h"
#include "utils/dctokenparser.h"
#include "utils/dcutils.h"

#include <QByteArray>
#include <QCoreApplication>
#include <QDir>

HubConnection::HubConnection()
{
	conn = new QTcpSocket;
	connect(conn, SIGNAL(connected()), this, SLOT(connected()));
	connect(conn, SIGNAL(readyRead()), this, SLOT(read()));
	connect(conn, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(conn, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));

	log.setFileName(QDir::homePath()+"/xdclog");
	log.open(QFile::ReadWrite);
}
HubConnection::~HubConnection() {
	conn->close();
	delete conn;
}

// properties
void HubConnection::setNick(QString n) {
	nick = n;
}
QString HubConnection::getNick() {
	return nick;
}
void HubConnection::setAddress(QHostAddress addr) {
	address = addr;
}
QHostAddress HubConnection::getAddress() {
	return address;
}
void HubConnection::setPort(qint16 p) {
	port = p;
}
qint16 HubConnection::getPort() {
	return port;
}

// public slots
void HubConnection::connectToHub() {
	conn->connectToHost(address, port, QAbstractSocket::ReadWrite);
}
void HubConnection::disconnectFromHub() {
	conn->close();
}

// protected slots
void HubConnection::connected() {
	// todo: notify ui interface
	qDebug() << "connected\n";	
}
void HubConnection::read() {
	QByteArray data = conn->readAll();
	DCTokenParser parser(data.constData());
	QString command = parser.getNextToken();

	qDebug() << data << '\n';
	log.write(data);
	log.write("\n\n");
	log.flush();

	if( command=="$Lock" ) {
		QString lock = parser.getNextToken(false);
		QString key = DCUtils::lock_to_key(lock);

		QString response = "$Key "+key+'|';
		response += "$ValidateNick hot123abc|";


		qDebug() << response << '\n';
		conn->write(response.toAscii());
		conn->flush();
		return;
	} else if( command=="$Hello" ) {
		QString response = "$MyINFO $ALL "+nick+" bot hai bhai bot$ $Modem$acchabot@botmail.com$107374182400$|";
		qDebug() << response << '\n';
		conn->write(response.toAscii());
		conn->flush();
		return;
	}
}

void HubConnection::disconnected() {
	qDebug() << "disconnected\n";
	conn->close();
	log.close();
	qApp->exit(0);
}

void HubConnection::error(QAbstractSocket::SocketError error) {
	qDebug() << "error: " << error << '\n';
}
