#ifndef UICONNECTION_H
#define UICONNECTION_H

#include <QObject>
#include <QTcpSocket>

class UiConnection : public QObject
{
public:
	UiConnection(QTcpSocket* s);
	~UiConnection();

private:
	QTcpSocket* conn;
};

#endif // UICONNECTION_H
