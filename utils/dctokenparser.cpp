#include "dctokenparser.h"
#include "rawstringutils.h"

DCTokenParser::DCTokenParser(const char* str) {
	len=RawStringUtils::strlen(str);
	currIndex = 0;
	string = new char[len+1];
	RawStringUtils::strcpy(string, str);
}


QString DCTokenParser::getNextToken(bool stopForOperators) {
	QString tokenToReturn="";
	if( currIndex >= len ) return tokenToReturn;

	if( stopForOperators && RawStringUtils::isOperator(string[currIndex]) ) {
		tokenToReturn += string[currIndex++];
		return tokenToReturn;
	}

	while(currIndex<len) {
		char c=string[currIndex];
		if( RawStringUtils::isWhiteSpace(c) )
			break;
		if( stopForOperators && RawStringUtils::isOperator(c) )
			break;
		tokenToReturn += string[currIndex++];
	}
	// now skip whitespaces
	while(RawStringUtils::isWhiteSpace(string[currIndex]))
		currIndex++;
	return tokenToReturn;
}

bool DCTokenParser::hasMoreTokens() {
	return (currIndex<len);
}

