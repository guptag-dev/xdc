#include "dcutils.h"

DCUtils::DCUtils() {}

QString DCUtils::lock_to_key(QString lock)
{
	int len = lock.length();
	QString key="";

	int i;
	for(i=1; i<len; i++)
		key[i] = lock[i].toAscii() ^ lock[i-1].toAscii();

	key[0] = lock[0].toAscii() ^ lock[len-1].toAscii() ^ lock[len-2].toAscii() ^ 5;

	for(i = 0; i < len; i++)
		key[i] = ((key[i].toAscii()<<4) & 0xF0) | ((key[i].toAscii()>>4) & 0x0F);

	QString newkey="";
	for(i = 0; i < len; i++)
	{
		switch(key[i].toAscii())
		{
		case 0:
		case 5:
		case 36:
		case 96:
		case 124:
		case 126:
			newkey += QString().sprintf("/%%DCN%03d%%/", key[i].toAscii());
			break;

		default:
			newkey += key[i];
		}
	}
	return newkey;
}
