#pragma once
#include "vector2i.h"

class Node {
public:
	Vector2i* tile;
	Node* parent;
	double fCost, gCost, hCost;
	Node(	Vector2i* tile, Node* parent, 
			double gCost, double hCost);
	~Node();
private:
};
