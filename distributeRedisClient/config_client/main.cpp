#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include "Config_client.h"

#define BUF_MAX_LEN 99

using namespace std;
int main(int argc, char *argv[])
{
	
	Config_client client;
	int op;
	while((op=getopt(argc, argv, "adlh:p:"))!=-1)
	{
		switch(op)
		{
			case 'a':
			{
				cout<<"add redis node"<<endl;
				client.set_op(ADD);
				break;
			}
			case 'd':
			{
				cout<<"delete redis node"<<endl;
				client.set_op(DEL);
				break;
			}
			case 'l':
			{
				cout<<"list all redis node"<<endl;
				client.set_op(LIST);
				break;
			}
			case 'h':
			{
				cout<<"the redis node'ip is : "<<optarg<<endl;
				client.node->setRedis_node_ip(optarg);
				break;
			}
			case 'p':
			{
				cout<<"the redis node'port is : "<<optarg<<endl;
				client.node->setRedis_node_port(optarg);
				break;
			}
			
		}
	}

	char buf[BUF_MAX_LEN];
	memset(buf,0, sizeof(buf));

	int buf_len = client.to_buffer(buf);
/*
//op_status
	int i= 0;
	long op_s;
	memcpy(&op_s, buf+i, 4);
	cout<<"op:"<<ntohl(op_s)<<endl;
	i+=4;
//ip len
	int ip_l;
	memcpy(&ip_l, buf+i, 4);
	cout<<"ip_len:"<<ntohl(ip_l)<<endl;
	i+=4;
//ip
	char ipp[100];
	memcpy(ipp, buf+i, ntohl(ip_l));
	cout<<"test"<<endl;
	ipp[ntohl(ip_l)] = '\0';
	cout<<"ip:"<<ipp<<endl;
*/
	
/*
	if(client.get_op() != LIST && (client.node->getRedis_node_ip()==NULL || client.node->getRedis_node_port == NULL))
	{
		cout<<"paramter error, please checkout"<<endl;
		return 0;
	}
*/
	
	//socket;
	struct sockaddr_in client,serv_addr;
	int serv_fd;
	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_fd = socket(AF_INET, SOCK_STREAM,0);
	if(-1 == serv_fd)
	{
		cout<<"socket error"<<endl;
		return 0;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(atoi("9999"));

	if(connect(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		cout<<"connect error<<endl;
		return 0;
	}
	//send buf to server 
	write(serv_fd, buf, buf_len);
	//wait serval time , config in xml or default

	//success or failed 
	char read_buf[BUF_MAX_LEN];
	int srt_len = read(serv_fd, read_buf, BUF_MAX_LEN);
	cout<<"success"<<endl;

	return 1;
	
}
