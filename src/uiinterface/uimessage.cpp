#include "uimessage.h"

UiMessage::UiMessage()
	: state(NONE)
{}

QString UiMessage::getMessageId() const {
	return messageId;
}
QString UiMessage::getClientId() const {
	return clientId;
}
QString UiMessage::getCommand() const {
	return command;
}
QStringList UiMessage::getCommandArgs() const {
	return commandArgs;
}
QString UiMessage::getCommandArgNumber(int n) const {
	// todo: check for index out of bound!
	return commandArgs.at(n);
}

bool UiMessage::isValidMessageType(QString msgtype) {
	QStringList list;
	list << "$command" << "$response" << "$notify";
	return list.contains(msgtype);
}
UiMessage::MessageType UiMessage::qStringToMessageType(QString msgtype) {
	// todo: this smells of bad code; fix it
	if(msgtype=="$command")
		return CommandMessage;
	else if(msgtype=="$response")
		return ResponseMessage;
	else if(msgtype=="$notify")
		return NotifyMessage;
	else
		return InvalidMessage;
}
