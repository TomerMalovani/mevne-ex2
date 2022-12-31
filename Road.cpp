#include "Road.h"
#include <iostream>

using namespace std;

Road::Road()
{
	lowestBridge = 0;
	bridges = Linkedlist();
}

Road::~Road()
{
}

void Road::addBridge(int bridgeHeight)
{
	bridges.pushToTail(bridgeHeight);
	if (lowestBridge == 0)
	{
		lowestBridge = bridgeHeight;
	}
	else if (bridgeHeight < lowestBridge)
	{
		lowestBridge = bridgeHeight;
	}
}

int Road::getLowestBridge()
{
	return lowestBridge;
}

void Road::printBridges()
{
	bridges.printList();
}

void Road::setLowestBridge(int bridgeHeight)
{
	lowestBridge = bridgeHeight;
}