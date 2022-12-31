// maximum heap sttructure based on Roads with a custom comparator as lowest bridge height

#include "Road.h"

#include <string>

using namespace std;

class CustomHeap

{

public:
	CustomHeap();

	CustomHeap(Road *roads, int size);

	~CustomHeap();

	void addRoad(Road * road);

	void fixHeap(int index);

	int WhichRoad(int height);

	void printHeap();

private:
	Road ** roadsHeap;

	int heapSize;

	int heapCapacity;
};
