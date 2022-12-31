// mevene-ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Road.h"
#include "CustomHeap.h"
using namespace std;


int main()
{
//    get number of roads to be added and read from user input
int numOfRoads;
Road *roads = new Road[100];
CustomHeap *heap = new CustomHeap();
cin >> numOfRoads;
//    get number of actions that is about to be done
int numOfActions;
cin >> numOfActions;

// loop for the number of actions
for (int i = 0; i < numOfActions; i++)
{
	//    get the action type
	char actionType;
	cin >> actionType;
	//    if the action is "a" then get the number of the road and add it to the roads array
	if (actionType == 'a')
	{
		// crete a array of roads and init it with the linked lists to each one
		roads = new Road[numOfRoads];
		// create a heap of roads and init it with the roads array 
		heap = new CustomHeap(roads, numOfRoads);
	}
	//    if the action is "b" then get the number of the road and the height of the bridge and add it to the road
	else if (actionType == 'b')
	{
		// get the number of the road and the height of the bridge
		int roadNum;
		int bridgeHeight;
		cin >> bridgeHeight;
		cin >> roadNum;

		// add the bridge to the road
		roads[roadNum-1].addBridge(bridgeHeight);
		if (bridgeHeight < roads[roadNum-1].getLowestBridge())
		{
			roads[roadNum-1].setLowestBridge(bridgeHeight);
			heap->fixHeap(roadNum-1);
		}

	}
	heap->printHeap();
}

//print the bridges of a road
heap->printHeap();

// afer that get the actions in the form of:
// "a"= init the roads array with the linked lists to each one
// "b"= add a bridge to a road
// "c"= get a car height as input and print the road number that has the height bridge that is higher than the car height
// "d"= print the bridges of a road

// thats it

}

