#include "CustomHeap.h"
#include <iostream>

using namespace std;

CustomHeap::CustomHeap()
{
	roadsHeap = new Road*[100];
	heapSize = 0;
}

CustomHeap::CustomHeap(Road *roads, int capacity)
{
	roadsHeap = new  Road *[capacity];
	heapSize = capacity;
	for (int i = 0; i < capacity; i++)
	{
		roadsHeap[i] = roads+i ;
	}
	for (int i = (heapSize - 2) / 2; i >= 0; i--)
	{
		fixHeap(i);
		
	}
}

CustomHeap::~CustomHeap()
{
	delete[] roadsHeap;
}

void CustomHeap::fixHeap(int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	if (left < heapSize && roadsHeap[left]->getLowestBridge() > roadsHeap[largest]->getLowestBridge())
	{
		largest = left;
	}
	if (right < heapSize && roadsHeap[right]->getLowestBridge() > roadsHeap[largest]->getLowestBridge())
	{
		largest = right;
	}
	if (largest != index)
	{
		Road * temp = roadsHeap[index];
		roadsHeap[index] = roadsHeap[largest];
		roadsHeap[largest] = temp;
		fixHeap(largest);
	}
}

void CustomHeap::addRoad(Road * road)
{

	roadsHeap[heapSize] = road;
	int index = heapSize;
	while (index > 0 && roadsHeap[index]->getLowestBridge() > roadsHeap[(index - 1) / 2]->getLowestBridge())
	{
		Road * temp = roadsHeap[index];
		roadsHeap[index] = roadsHeap[(index - 1) / 2];
		roadsHeap[(index - 1) / 2] = temp;
		index = (index - 1) / 2;
	}
	heapSize++;
}

int CustomHeap::WhichRoad(int height)
{
	// if heap[0] is heiger than height, return heap[0]
	if (roadsHeap[0]->getLowestBridge() > height)
	{
		return roadsHeap[0]->getLowestBridge();
	}
	else
	{
		return 0;
	}
}

void CustomHeap::printHeap()
{
	for (int i = 0; i < heapSize; i++)
	{
		cout << roadsHeap[i]->getLowestBridge() << " ";
	}
	cout << endl;
}
