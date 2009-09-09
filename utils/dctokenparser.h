#ifndef DCTOKENPARSER_H
#define DCTOKENPARSER_H

#include <QString>

class DCTokenParser
{
public:
	DCTokenParser(const char* str);

	QString getNextToken(bool stopForOperators=true);
	bool hasMoreTokens();
private:
	char* string;
	int len;
	int currIndex;

};

#endif // DCTOKENPARSER_H
