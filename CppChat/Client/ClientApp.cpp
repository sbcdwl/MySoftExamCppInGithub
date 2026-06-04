#include "Client.h"
#include<iostream>

int main() 
{

	Client client;
	if (!client.connectToHost("127.0.0.1", 8080))
	{
		std::cerr << "Connect Server error" << std::endl;
		return -1;
	}

	//连接成功后发送消息给服务器
	client.write("hello world");

	//接受
	auto msg = client.read();
	std::cout << "msg is:" << msg << std::endl;

	return 0;
}