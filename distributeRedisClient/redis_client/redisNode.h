#ifndef REDIS_NODE_H
#define REDIS_NODE_H

#include <string>
using namespace std;

class redisNode{

	private:
		string ip;
		string port;
		int iden;
		int virtualNum;
		connRedis *conn;

	public:
	redisNode(string ip, string port);
	virtual ~redisNode();

	void setNode(string ip, string port);
	void setIp(string ip);
	void setPort(string port);
	string getIp();
	string getPort();

	void setVirtualNum(int num);
	int  getVirtualNum();

	connRedis * getConn();
	void buildConn();

	int getIden();
}

#endif
