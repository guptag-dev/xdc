#ifndef HUBCONNECTION_H
#define HUBCONNECTION_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>

class HubConnection : public QObject
{
	Q_OBJECT
public:
	HubConnection();
	~HubConnection();

	void setNick(QString n);
	QString getNick();

	void setAddress(QHostAddress addr);
	QHostAddress getAddress();

	void setPort(qint16 p);
	qint16 getPort();

public slots:
	// only to be called by the UINetworkInterface
	void connectToHub();
	void disconnectFromHub();

protected slots:
	// only to be called self. must notify UINetworkInterface
	void read();
	void connected();
	void disconnected();
	void error(QAbstractSocket::SocketError err);

private:
	QString nick;
	QHostAddress address;
	qint16 port;

	QTcpSocket* conn;
	bool isConnected;
};

#endif // HUBCONNECTION_H
