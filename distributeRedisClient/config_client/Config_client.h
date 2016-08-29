#ifndef CONFIG_CLIENT_H
#define CONFIG_CLIENT_H
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#include "Redis_node.h"
using namespace std;

typedef enum {INIT,ADD, DEL, LIST}op_status ;

class Config_client
{
public:
	Redis_node *node;
	op_status op; //add, delete, list

public:
	Config_client();
	void set_op(op_status op);
	op_status get_op()
	{
		return op;
	}
	int to_buffer(char *buf);
	virtual ~Config_client();
};

#endif
