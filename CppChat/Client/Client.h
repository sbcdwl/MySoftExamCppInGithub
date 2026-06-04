#pragma once
#include<string>
/// <summary>
/// Client.h
/// 客户端类
/// </summary>
class Client
{
public:
	Client();
	~Client();

	bool connectToHost(const std::string& host, uint64_t port);
	//发送数据给服务器
	int write(const char* buf,int len);
	int write(const std::string& str);
	//接受服务器发来的数据
	int read(char* buf, int len);
	std::string read();

private:
	std::string m_address;
	uint16_t m_port;
	uint64_t m_fd;
};

