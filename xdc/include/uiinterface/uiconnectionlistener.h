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
	quint16 getPort();

public slots:
	void start();

protected slots:
	void newConnection();
	void couldNotBindError();

private:
	QHostAddress interface;
	quint16 port;

	QTcpServer *sock;
};

#endif // UICONNECTIONLISTENER_H
