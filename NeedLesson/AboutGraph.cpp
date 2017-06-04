#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "AboutGraph.h"

bool AboutGraph::insertValue(int value)
{
	return false;
}
bool AboutGraph::prim()
{
	return false;
}
bool AboutGraph::kruskal()
{
	return false;
}

AboutGraph::AboutGraph(int nodeNumber)
{	
	nodeNum = nodeNumber;
	nodes= (node*)malloc(sizeof(node)*nodeNum);

	for (int i = 0; i < nodeNum; i++) 
		nodes[i].links=(link*)malloc(sizeof(link)*nodeNum);
	
}