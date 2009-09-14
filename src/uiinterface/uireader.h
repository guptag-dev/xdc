#ifndef UIREADER_H
#define UIREADER_H

#include <QObject>

// is a singleton
class UiReader : public QObject
{
	Q_OBJECT
public:
	static UiReader* getInstance();

private:
	UiReader();
};

#endif // UIINTERFACE_H
