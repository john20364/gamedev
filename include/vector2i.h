#pragma once

class Vector2i {
public:
	Vector2i();
	Vector2i(Vector2i& vector);
	Vector2i(int x, int y);
	~Vector2i();
	int getX();
	int getY();
	Vector2i& setX(int x);
	Vector2i& setY(int y);
	Vector2i& add(Vector2i& vector);
	Vector2i& sub(Vector2i& vector);
	double distance(Vector2i& vector); 
	bool equals(Vector2i& vector);
private:
	void set(int x, int y);
	int x;
	int y;
};
