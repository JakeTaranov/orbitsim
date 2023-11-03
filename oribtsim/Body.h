#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include "vec.h"

class Body
{

    float mass;
    float radius;
    vec pos;
    vec vel;
    sf::CircleShape s;
    sf::Color col;

public:
    Body(float mass, float radius, sf::Color col, float pos_x, float pos_y, float vel_x, float vel_y);

    void render(sf::RenderWindow&);

    void update_physics(std::vector<Body>);

    void check_bounds();

    void set_color(sf::Color);

    vec get_pos();

    float get_mass();

    vec get_vel();


};