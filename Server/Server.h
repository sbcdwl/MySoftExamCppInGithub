#pragma once
#include<string>

/**
* 服务器类
*/

class Server
{
public:
	/**
	* \param host 监听的地址
	* \param port 监听的端口号
	* 
	*/
	Server(const std::string& host,uint16_t port);
	~Server();

	/*
	运行服务器
	*/
	int run();

private:
	std::string m_address;
	uint16_t m_port;
	uint64_t m_fd;			//服务器描述符
	bool m_running;			//是否在运行

};

