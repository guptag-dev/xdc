#include "uinlsmessage.h"

#include <QBuffer>

UiNLSMessage::UiNLSMessage()
{
}

bool UiNLSMessage::readUiMessage(const QByteArray &data, UiNLSMessage* msg, qint64 *index) {
	if( msg->state == COMPLETE ) return true;

	QBuffer input;
	input.setBuffer( const_cast<QByteArray*> (&data) );
	input.open(QIODevice::ReadOnly);
	QString nextWord(input.readLine());

	while(msg->state != COMPLETE && input.bytesAvailable() > 0 ) {
		switch(msg->state) {
		case MSGTYPE: // have to read message type
			if( isValidMessageType(nextWord) ) {
				msg->messageType = qStringToMessageType(nextWord);
				msg->state = MSGID;
			}
			// todo: else { handle error somehow }
			break;
		case MSGID:   // have to read message id
			msg->messageId = nextWord;
			msg->state = CLID;
			break;
		case CLID:    // have to read client id
			msg->clientId = nextWord;
			msg->state = CMD;
			break;
		case CMD:     // have to read command
			msg->command = nextWord;
			msg->state = ARGS;
			break;
		case ARGS:    // have to read args, or end of command
			if( nextWord=="$end" )
				msg->state = COMPLETE;
			else
				msg->commandArgs << nextWord;
			break;
		default: // first off, this can't really occur.
			; // todo: implement error handling in case some errorneous message arrives here!
		}
	}
	*index = input.pos();
	if( msg->state==COMPLETE )
		return true;
	else
		return false;
}

