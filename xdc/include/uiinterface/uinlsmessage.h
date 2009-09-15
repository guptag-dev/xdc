#ifndef UINLSMESSAGE_H
#define UINLSMESSAGE_H

#include "uimessage.h"

class UiNLSMessage : public UiMessage
{
public:
    UiNLSMessage();

	static bool readUiMessage(const QByteArray &data, UiNLSMessage* incomplete, qint64 *index );
};

#endif // UINLSMESSAGE_H
