#pragma once
class Vec
{
	float x;
	float y;

public:
	Vec();
	Vec(float, float);
	void print();
	Vec sum(Vec);
	Vec subtract(Vec);
	void multiplty_scalar(float);
	void normalize();
	void add_to_x(float);
	void add_to_y(float);
	float getAngle();
	float get_magnitude();
	float get_x();
	float get_y();
	void set_x(float);
	void set_y(float);
	void reset(float, float);
};

