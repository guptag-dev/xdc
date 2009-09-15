#ifndef RAWSTRINGUTILS_H
#define RAWSTRINGUTILS_H

class RawStringUtils
{
private:
	RawStringUtils();

public:
	static int strlen(const char* str);
	static void strcpy(char* dest, const char* src);
	static bool isWhiteSpace(char c);
	static bool isOperator(char c);

};

#endif // RAWSTRINGUTILS_H
