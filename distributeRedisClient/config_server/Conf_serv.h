#include <string>
#include <event.h>

class Conf_serv
{
	public:
	Conf_serv();
	virtual ~Conf_serv();
	
	
	int serv_socket(string ip, string port);
	void handle_event(int listen_fd);
	bool check_timer();
	void reslove_mesg();
	
	Redis_node *rn;
	Redis_pool *rp;
}
