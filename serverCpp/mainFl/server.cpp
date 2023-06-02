//Define
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#define DEFAULT_PORT "27015"
//Pragma 
#pragma comment(lib, "ws2_32.lib")

//Include
#include <iostream>
#include "Source.h"
#include <WinSock2.h>
#include <string>
#include <cstdio>
#include <inaddr.h>
#include <ws2tcpip.h>

//Server
int calling()
{
	//External dependencies
	std::string pathHTML= "mainFL//eyesopen.html";
	char basicRequest [4048] = "HTTP/1.1 200 OK\r\n\n";
	//Code
	strcat(basicRequest, compressor(pathHTML));
	strcat(basicRequest, "\r\n\n");
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET AcceptSocket = INVALID_SOCKET;
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0) {
		std::cout << "Success";
	}
	ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in sockParams;
	sockParams.sin_family = AF_INET;
	sockParams.sin_port = htons(6969);
	sockParams.sin_addr.s_addr = INADDR_ANY;
	bind(ListenSocket, (struct sockaddr*)&sockParams, sizeof(sockParams));
	listen(ListenSocket, SOMAXCONN);
	int bytesSend = 0;
	std::cout << basicRequest;
	while (true)
	{
		AcceptSocket = accept(ListenSocket, NULL, NULL);
		bytesSend = send(AcceptSocket, basicRequest, sizeof(basicRequest), 0);
	}
	closesocket(ListenSocket);
	WSACleanup();
	return 0;
}




int main() 
{
	calling();
	return 0;
}