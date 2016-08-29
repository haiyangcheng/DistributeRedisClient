#include "Config_client.h"

Config_client::Config_client() {
	node = new Redis_node("", "");
	op = INIT;
}


void Config_client::set_op(op_status op)
{
	this->op = op;
}

void long_2_NetByte(char *buf, long value)
{	
	long tmp = htonl(value);
	memcpy(buf, &tmp, 4);
}
void int_2_NetByte(char *buf, int value)
{	
	int tmp = htonl(value);
	memcpy(buf, &tmp, 4);
}

int Config_client::to_buffer(char *buf)
{
	int index = 0;
	//op_status
	int_2_NetByte(buf, (int)get_op());
	index+=4;
	//ip length | ip
	string ip = node->getRedis_node_ip();
	int ip_len = ip.length();

	int_2_NetByte(buf+index, ip_len);
	index+=4;
	
	memcpy(buf+index,ip.c_str(), ip_len); 
	index+=ip_len;
	//port length | port
	string port = node->getRedis_node_port();
	int port_len = port.length();

	int_2_NetByte(buf+index, port_len);
	index+=4;
	memcpy(buf+index,port.c_str(), port_len); 
	index+=port_len;

	return index;
}

Config_client::~Config_client()
{
	delete node;
}

