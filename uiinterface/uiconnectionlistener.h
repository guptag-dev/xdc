#ifndef UICONNECTIONLISTENER_H
#define UICONNECTIONLISTENER_H

#include <QObject>
#include <QHostAddress>
#include <QTcpServer>

class UiConnectionListener : public QObject
{
	Q_OBJECT

public:
	UiConnectionListener();
	~UiConnectionListener();

	void setInterface(QHostAddress addr);
	QHostAddress getInterface();

	void setPort(qint16 p);
	qint16 getPort();

public slots:
	void start();

protected slots:
	void newConnection();

private:
	QHostAddress interface;
	qint16 port;

	QTcpServer *sock;
};

#endif // UICONNECTIONLISTENER_H
