#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

auto compressor(std::string pathHTML)
{

	FILE* fileHTML;
	const char * pathCHTML = pathHTML.c_str();
	char line;
	std::string resultHTML;
	fileHTML = fopen(pathCHTML, "r");
	do {
		line = fgetc(fileHTML);
		if ((line == '\n') || (line == '    ') || (line == ' ') || (line == '\t')) {
			continue;
		}
		else resultHTML.push_back(line);
	} while (line != EOF);
	char* resultC = new char[resultHTML.size() + 1];
	strcpy(resultC, resultHTML.c_str());
	return resultC;
}
int main()
{
	return 0;
}