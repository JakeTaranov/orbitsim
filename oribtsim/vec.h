#pragma once
class vec
{
	float x;
	float y;

public:
	vec();
	vec(float, float);
	void print();

	vec sum(vec);
	vec subtract(vec);
	void multiplty_scalar(float);
	void normalize();

	void add_to_x(float);
	void add_to_y(float);
	// getters
	float getAngle();
	float get_magnitude();
	float get_x();
	float get_y();

	// setters
	void set_x(float);
	void set_y(float);
	void reset(float, float);


};

