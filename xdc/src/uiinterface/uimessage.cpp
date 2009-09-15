#include "uiinterface/uimessage.h"

UiMessage::UiMessage()
	: state(NONE)
{}

UiMessage::MessageType UiMessage::getType() const {
	return messageType;
}
QString UiMessage::getMessageId() const {
	return messageId;
}
QString UiMessage::getClientId() const {
	return clientId;
}
QString UiMessage::getCommand() const {
	return command;
}
QStringList UiMessage::getArgs() const {
	return commandArgs;
}
int UiMessage::getArgsCount() const {
	return commandArgs.size();
}
QString UiMessage::getArgNumber(int n) const {
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
