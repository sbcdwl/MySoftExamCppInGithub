#include "Server.h"
#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.h>				//windows网络头文件
#pragma comment(lib,"ws2_32.lib")	//链接到库文件

Server::Server(const std::string& host, uint16_t port)
	: m_address(host)
	, m_port(port)
	, m_running(false)
{	
	//创建服务器.
	//1，初始化网络库
	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0)
	{
		std::cerr << "WSAStartup error" << WSAGetLastError() << std::endl;
		return;
	}

	//2,创建一个socket
	//AF_INET 表示ipv4地址
	//SOCK_STREAM流失套接字（tcp）
	m_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);   
	if (m_fd == INVALID_SOCKET)
	{
		std::cerr << "socket error" << WSAGetLastError() << std::endl;
		return;
	}

	//3,绑定ip地址和端口号
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;	
	addr.sin_port = htons(port);		//大端和小端存储，本机都是小端存储，网络上传输的为大端
										//|1|2|,由低到高为大端存储,htons将小端转换为大端(host to net short)
	inet_pton(AF_INET, host.data(), &addr.sin_addr);//把“地址：端口”转换为下面bind用的二进制，并传入addr.sin_addr
	//至此sockaddr_in的三个参数完成
	
	//bind把socket和一个“地址：端口”绑定，
	if (bind(m_fd, (struct sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		std::cerr << "bind error" << WSAGetLastError() << std::endl;
		return;

	}

	//4,监听
	if (listen(m_fd, 10) == SOCKET_ERROR)
	{
		std::cerr << "listen error" << WSAGetLastError() << std::endl;
		return;
	}
	m_running = true;
	std::cout << "Server listening on port:"<<m_port << std::endl;

}

Server::~Server()
{
	//清理网络库
	WSACleanup();
}

int Server::run()
{
	//事件循环
	while (m_running)
	{	
		char buf[BUFSIZ];
		//接受连接
		SOCKET sock = accept(m_fd, NULL, NULL);
		if (sock == INVALID_SOCKET)
		{
			std::cerr << "accept error" << WSAGetLastError() << std::endl;
			continue;
		}
		//接受客户端消息
		int nread = recv(sock, buf, BUFSIZ, 0);
		//读到了数据
		if (nread > 0)
		{
			//打印数据
			printf("data is:%.*s nread is:%d\n ", nread, buf, nread);
			//回显给客户端
			if (send(sock, buf, nread, 0) <= 0)
			{
				std::cout << "send error: peer closed!";
			}
		}
		//对方调用close正常关闭
		else if (nread <= 0)
		{
			std::cout << "peer closed!";
			closesocket(sock);
		}
	}
	return 0;
}
