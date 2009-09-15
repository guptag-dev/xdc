#include "utils/rawstringutils.h"

RawStringUtils::RawStringUtils() {}

int RawStringUtils::strlen(const char* str) {
	int i;
	for( i=0; str[i]!='\0'; i++ )
		;
	return i;
}

void RawStringUtils::strcpy(char* dest, const char* src) {
	for( int i=0; src[i]!='\0'; i++ )
		dest[i] = src[i];
}

bool RawStringUtils::isWhiteSpace(char c) {
	return( c==' ' || c=='\t' || c=='\0' );
}

bool RawStringUtils::isOperator(char c) {
	return (c=='=' || c=='|');
}
