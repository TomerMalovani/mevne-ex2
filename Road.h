// road class declaration 
// shoud have a linked list of bridges as numbers indicating the bridge height
// should also have the value of the lowest bridge
#include "Linkedlist.h"
#ifndef ROAD_H
#define ROAD_H


class Road
{
public:
	Road();
	~Road();
	void addBridge(int bridgeHeight);
	int getLowestBridge();
	void setLowestBridge(int bridgeHeight);
	void printBridges();
private:
	int lowestBridge=0;
	int bridgeCount;
	Linkedlist bridges;
};

#endif
