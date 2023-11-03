#include "Body.h"
#include <iostream>
#include <math.h>
#include "constants.hpp"

using namespace std;


int constrain(float distance, int lower, int upper)
{
	if (distance < lower) distance = lower;
	else if (distance > upper) distance = upper;
	return distance;
}



Body::Body(float mass, float radius, sf::Color col, float pos_x, float pos_y, float vel_x, float vel_y) {
	this->mass = mass;
	this->radius = radius;
	pos = vec(pos_x, pos_y);
	vel = vec(vel_x, vel_y);

	s.setPosition(pos.get_x(), pos.get_y());
	s.setFillColor(col);
	s.setRadius(radius);
}



// Updating physics relative to all other bodies
// Gravitational Force = (G * mass_1 * mass_2) / distance_between_center^2
void Body::update_physics(std::vector<Body> other_bodies)
{
	// Updating physics of body relative to all other bodies;
	for (int i = 0; i < other_bodies.size(); i++) {

		Body other_body = other_bodies[i];

		vec other_pos = other_body.get_pos();
		vec force_dir = pos.subtract(other_pos);
		float distance = force_dir.get_magnitude();

		distance = constrain(distance, Constants::constrain_lower, Constants::constrain_upper);

		float gForce= (Constants::G * other_body.mass) / pow(distance, 2);
		
		float ang = force_dir.getAngle();

		float m_acc_x = gForce * cos(ang);
		float m_acc_y = gForce * sin(ang);

		vel.add_to_x(m_acc_x * Constants::dt);
		vel.add_to_y(m_acc_y * Constants::dt);

		pos.add_to_x(vel.get_x());
		pos.add_to_y(vel.get_y());

	}
}

// Will ensure that the ball stays in screen (bounce off walls)
void Body::check_bounds()
{
	// Bounces off left side of screen
	if (pos.get_x() <= 0)
	{
		vel.set_x(vel.get_x() * -1);
	}
	// Bounces off top of screen
	if (pos.get_y() <= 0)
	{
		vel.set_y(vel.get_y() * -1);
	}
	// Bouces off right side of screen
	if (pos.get_x() >= Constants::screen_width - radius*2)
	{
		vel.set_x(vel.get_x() * -1);
	}
	// Bounces off bottom of screen
	if (pos.get_y() >= Constants::screen_height - radius*2)
	{
		vel.set_y(vel.get_y() * -1);
	}
}

void Body::set_color(sf::Color col)
{
	s.setFillColor(col);
}

void Body::render(sf::RenderWindow& wind)
{
	s.setPosition(pos.get_x(), pos.get_y());
	wind.draw(s);
}

vec Body::get_pos()
{
	return pos;
}

float Body::get_mass()
{
	return mass;
}

vec Body::get_vel()
{
	return vel;
}
