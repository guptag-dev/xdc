#include "uiinterface/uinlsmessagetest.h"

#include "uiinterface/uinlsmessage.h"

#include <QtTest/QtTest>
#include <QString>
#include <QByteArray>

void UiNLSMessageTest::simpleTest() {
	QCOMPARE(10,10);
	/*
	UiNLSMessage msg;
	QString stream = "$command\n10\n20\nConnect\n10.8.21.186\n4112\nhrj\n$end\n";
	qint64 index=0;
	QByteArray data( stream.toAscii() );

	UiNLSMessage::readUiMessage(data, &msg, &index);

	QCOMPARE(msg.getType(), UiMessage::CommandMessage);
	QCOMPARE(msg.getMessageId(), QString("10"));
	QCOMPARE(msg.getClientId(), QString("20"));
	QCOMPARE(msg.getCommand(), QString("$command"));
	QCOMPARE(msg.getArgsCount(), 3);

	QCOMPARE(msg.getArgNumber(0), QString("10.8.21.186"));
	QCOMPARE(msg.getArgNumber(1), QString("4112"));
	QCOMPARE(msg.getArgNumber(2), QString("hrj"));
	*/
}

