#pragma once

class AboutGraph
{
	class link;
	class node;

	class node {
	public:
		node() {}
		char value;
		link *links;
	};

	class link {
	public:
		node *start;
		node *end;
		int weight;
	};

	int nodeNum;
	node *nodes;

public:
	
	bool insertValue(int value);
	bool prim();
	bool kruskal();
	AboutGraph(int nodeNumber);
};