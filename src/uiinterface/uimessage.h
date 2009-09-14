#ifndef UIMESSAGE_H
#define UIMESSAGE_H

#include <QString>
#include <QStringList>

class UiMessage
{
public:
	UiMessage();
	enum MessageType { CommandMessage, ResponseMessage, NotifyMessage, InvalidMessage };

	QString getMessageId() const;
	QString getClientId() const;
	QString getCommand() const;
	QStringList getCommandArgs() const;
	QString getCommandArgNumber(int n) const;

	// reads
	static bool readUiMessage(const QByteArray &data, UiMessage* incomplete, qint64 *index );

protected:
	enum MSG_STATE {NONE, MSGTYPE, MSGID, CLID, CMD, ARGS, COMPLETE};

	static bool isValidMessageType(QString msgtype);
	static MessageType qStringToMessageType(QString msgtype);

	MessageType messageType;
	QString messageId;
	QString clientId;
	QString command;
	QStringList commandArgs;

	MSG_STATE state;
};

#endif // UIMESSAGE_H
