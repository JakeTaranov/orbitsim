#include <SFML/Graphics.hpp>
#include <vector>
#include "Body.h"
#include <iostream>
#include "vec.h"
#include "Constants.hpp"

using namespace std;

sf::Color generate_random_color() 
{

    float r = rand() * 255;
    float g = rand() * 255;
    float b = rand() * 255;

    return sf::Color(r, g, b);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(Constants::screen_width, Constants::screen_height), "Orbit Simulation");
    window.setFramerateLimit(60);


    std::vector<Body> bodies;
    bodies.push_back(Body(100000, 20, generate_random_color(), 800, 600, 0, 0, false));
    bodies.push_back(Body(100, 10, generate_random_color(), 800, 200, 1, 1, true));
    bodies.push_back(Body(100, 10, generate_random_color(), 100, 200, 1, 0, true));

    // bodies.push_back(Body(0.1, 5, sf::Color::Blue, 1100, 600, -0, -0));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }


       window.clear();


        // Iterate over each body, creating a list of all other bodies except the current
        // then update physics relative to all other bodies and redner window again
        for (int i = 0; i < bodies.size(); i++) {
            std::vector<Body> bodies_except_self;
            for (int j = 0; j < bodies.size(); j++) {
                if (i == j) continue;
                bodies_except_self.push_back(bodies[j]);
            }

            bodies[i].update_physics(bodies_except_self);
            bodies[i].update_line();
            bodies[i].check_bounds();
            if (bodies[i].get_drawline())
            {
                bodies[i].draw_line(window);
            }
            bodies[i].render(window);

        }

        window.display();
    }


    return 0;
}

