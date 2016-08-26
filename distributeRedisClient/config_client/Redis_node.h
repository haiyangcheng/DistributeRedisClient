#ifndef REDIS_NODE_H
#define REDIS_NODE_H
#include <string>


class Redis_node
{
	private:
	string ip;
	unsigned int port;
	

	public:
	Redis_node(string r_ip, unsigned int r_port):ip(r_ip),port(r_port);
	
	virtual ~Redis_node();
	string getRedis_node_ip()
	{
		return ip;
	}
	unsigned int getRedis_node_port()
	{
		return port;
	}
}

#endif
