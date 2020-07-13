#include <iostream>
#include "include/vector2i.h"
#include "math.h"

Vector2i::Vector2i() {
	set(0, 0);
}

Vector2i::Vector2i(Vector2i& vector) {
	set(vector.x, vector.y);
}

Vector2i::Vector2i(int x,  int y) {
	set(x, y);
}

Vector2i::~Vector2i() {
}

void Vector2i::set(int x,  int y) {
	this->x = x;
	this->y = y;
}

Vector2i& Vector2i::setX(int x) {
	this->x = x;
	return *this;
}

Vector2i& Vector2i::setY(int y) {
	this->y = y;
	return *this;
}

int Vector2i::getX() {
	return x;
}

int Vector2i::getY() {
	return y;
}

Vector2i& Vector2i::add(Vector2i& vector) {
	this->x += vector.x;
	this->y += vector.y;
	return *this;
}

Vector2i& Vector2i::sub(Vector2i& vector) {
	this->x -= vector.x;
	this->y -= vector.y;
	return *this;
}

double Vector2i::distance(Vector2i& vector) {
	double dx = x - vector.x;
	double dy = y - vector.y;
	return sqrt(dx * dx + dy * dy);
}

bool Vector2i::equals(Vector2i& vector) {
	return ((x == vector.x) && (y == vector.y));
}








