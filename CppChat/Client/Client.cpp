/**
*Client.cpp
*/

#include "Client.h"
#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.h>				//windows网络头文件
#pragma comment(lib,"ws2_32.lib")	//链接到库文件

Client::Client()
{
	//1，初始化网络库
	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0)
	{
		std::cerr << "WSAStartup error" << WSAGetLastError() << std::endl;
		return;
	}
}

Client::~Client()
{
	//清理网络库
	WSACleanup();
}

bool Client::connectToHost(const std::string& host, uint64_t port)
{	
	//2,创建一个socket
	//AF_INET 表示ipv4地址
	//SOCK_STREAM流失套接字（tcp）
	m_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_fd == INVALID_SOCKET)
	{
		std::cerr << "socket error" << WSAGetLastError() << std::endl;
		return false;
	}

	//3,指定服务器ip地址和端口号
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);		//大端和小端存储，本机都是小端存储，网络上传输的为大端
	//|1|2|,由低到高为大端存储,htons将小端转换为大端(host to net short)
	inet_pton(AF_INET, host.data(), &addr.sin_addr);//IP地址

	/*if (bind(m_fd, (struct sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		std::cerr << "bind error" << WSAGetLastError() << std::endl;
		return false;

	}*/

	//连接服务器
	if (connect(m_fd, (struct sockaddr*)&addr, sizeof(addr)) != 0)
	{
		std::cerr << "connect error" << WSAGetLastError() << std::endl;
		return false;
	}

	return true;
}

int Client::write(const char* buf, int len)
{
	int nsend = send(m_fd, buf, len, 0);
	if (nsend <= 0)
	{
		std::cout << "write peer closed" << std::endl;
	}
	return nsend;
}

int Client::write(const std::string& str)
{
	return write(str.data(),str.length());
}

int Client::read(char* buf, int len)
{
	int nread = recv(m_fd, buf, len, 0);
	if (nread <= 0)
	{
		std::cout << "read peer closed" << std::endl;
	}
	return nread;
}

std::string Client::read()
{
	char buf[2048];
	int nread = read(buf,2048);
	return std::string(buf,nread);
}


