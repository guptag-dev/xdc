#ifndef UICONNECTION_H
#define UICONNECTION_H

#include <QObject>
#include <QTcpSocket>

class UiConnection : public QObject
{
	Q_OBJECT
public:
	UiConnection(QTcpSocket* s);
	~UiConnection();
protected slots:
	void readyRead();
	void stateChanged(QAbstractSocket::SocketState);

private:
	QTcpSocket* conn;
};

#endif // UICONNECTION_H
