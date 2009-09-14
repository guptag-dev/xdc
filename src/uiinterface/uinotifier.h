#ifndef UINOTIFIER_H
#define UINOTIFIER_H

#include <QObject>

// is a singleton
class UiNotifier : public QObject
{
	Q_OBJECT
public:
	static UiNotifier* getInstance();

private:
    UiNotifier();
};

#endif // UINOTIFIER_H
