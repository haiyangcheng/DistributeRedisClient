#ifndef REDIS_VIRTUAL_NODE_H
#define REDIS_VIRTUAL_NODE_H
#include "redisNode.h"

class redisVirtualNode{
private:
	redisNode * node;
	long hashVal;
	
public:
	redisVirtualNode();
	redisVirtualNode(redisNode *node);
	
	void setNode(redisNode *node);
	redisNode * getNode();
	void setHash(long hash);
	long getHash();
}
#endif
