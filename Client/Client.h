#pragma once
#include<string>
/// <summary>
/// ¿Í»§¶ËÀà
/// </summary>
class Client
{
public:
	Client();
	~Client();
private:
	std::string m_address;
	uint16_t m_port;
	uint64_t m_fd;
};

