#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>

using namespace std;
int main(int argc, char **argv)
{
/*
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
*/
	int op;
	while((op=getopt(argc, argv, "adlh:p:"))!=-1)
	{
		switch(op)
		{
			case 'a':
			{
				cout<<"add redis node"<<endl;
				break;
			}
			case 'd':
			{
				cout<<"delete redis node"<<endl;
				break;
			}
			case 'l':
			{
				cout<<"list all redis node"<<endl;
				break;
			}
			case 'h':
			{
				cout<<"the redis node'ip is : "<<optarg<<endl;
				break;
			}
			case 'p':
			{
				cout<<"the redis node'port is : "<<optarg<<endl;
				break;
			}
			
		}
	}

	return 1;
	
}
