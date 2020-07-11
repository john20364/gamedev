#include <iostream>
#include "include/entity.h"

Entity::Entity() {
}

Entity::~Entity() {
}

void Entity::update() {
}

void Entity::render() {
}

void Entity::remove() {
	// Remove from level
	removed = true;
}

bool Entity::isRemoved() {
	return removed;
}


void Entity::init(Level* level) {
	this->level = level;
}
