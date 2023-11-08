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
    bool drawline;
    sf::Color color;
    sf::VertexArray line;
    sf::CircleShape s;
    sf::Color col;

public:
    Body(float mass, float radius, sf::Color col, float pos_x, float pos_y, float vel_x, float vel_y, bool drawline);

    void render(sf::RenderWindow&);

    void clear(sf::RenderWindow&);

    void update_physics(std::vector<Body>);

    void check_bounds();

    void update_line();

    void draw_line(sf::RenderWindow& wind);

    void set_color(sf::Color);

    vec get_pos();

    float get_mass();

    vec get_vel();

    bool get_drawline();

    sf::Color get_color();


};