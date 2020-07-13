#include "include/node.h"

Node::Node(	Vector2i* tile, Node* parent,
			double gCost, double hCost) {
	this->tile = tile;
	this->parent = parent;
	this->gCost = gCost;
	this->hCost = hCost;
	this->fCost = this->gCost + this->hCost;
}

Node::~Node() {
	delete tile;
}
