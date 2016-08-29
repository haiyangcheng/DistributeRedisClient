#ifndef REDIS_NODE_H
#define REDIS_NODE_H
#include <string>

using namespace std;

class Redis_node
{
private:
	string ip;
	string port;
	

public:
	Redis_node(string r_ip, string r_port):ip(r_ip),port(r_port){}
	
//	virtual ~Redis_node();
	string getRedis_node_ip()
	{
		return ip;
	}
    string getRedis_node_port()
	{
		return port;
	}
	void setRedis_node_ip(string ip)
	{
		this->ip = ip;
	}
	void setRedis_node_port(string port)
	{
		this->port = port;
	}
};

#endif
