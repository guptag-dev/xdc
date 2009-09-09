#ifndef DCUTILS_H
#define DCUTILS_H

#include <QString>

class DCUtils
{
private:
	DCUtils();
public:
	static QString lock_to_key(QString lock);
};

#endif // DCUTILS_H
