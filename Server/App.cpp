/*
网络聊天室

1，服务器，监听客户端的连接，
	1.1 服务器类Server 

2，客户端
*/

#include "Server.h"
#include <iostream>

int main()
{
	//创建服务器
	Server server("0.0.0.0", 8080);

	//运行服务器
	server.run();

	return 0;
}