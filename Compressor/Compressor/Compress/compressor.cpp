#include <iostream>
#include <vector>
#include <string>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

FILE* composer(FILE* fileHTML)
{
	return fileHTML;
}
int main()
{
	char pathHTML[100] = "Compressor//testfrocomposer.html";
	char fullpage[100];
	FILE* fileHTML = fopen(pathHTML, "r");
	if (fopen(pathHTML, "r") == NULL) {
		std::cout << "Error opening a file";
	}
	composer(fileHTML);
	return 0;
}