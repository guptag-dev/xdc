#ifndef UICONNECTIONLIST_H
#define UICONNECTIONLIST_H

#include <QObject>
#include <QList>

class UiConnection;

// is a singleton
class UiConnectionList : public QObject
{
	Q_OBJECT
public:
	void addConnection(UiConnection* conn);
	void removeConnection(UiConnection* conn);

	static UiConnectionList* getInstance();

private:
	UiConnectionList();
	QList<UiConnection*> connList;
};

#endif // UICONNECTIONLIST_H
