#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Source.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

const char* compressor(std::string pathHTML)
{

	FILE* fileHTML;
	const char* pathCHTML = pathHTML.c_str();
	std::string line;
	std::string resultHTML;
	std::ifstream file(pathHTML);
	while (getline(file, line)) {
		int sz = line.size() -4;
		if (line[0] == ' ') { 
			line.erase(line.begin(), line.end() - sz);
			resultHTML.append(line);
		}
		else {
			resultHTML.append(line);
		}
	}
	char* resultC = new char[resultHTML.size() + 1];
	strcpy(resultC, resultHTML.c_str());
	return resultC;
}
