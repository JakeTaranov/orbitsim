#include <SFML/Graphics.hpp>
#include <vector>
#include "Body.h"
#include <iostream>
#include "vec.h"
#include "Constants.hpp"
#include "parser.h"
#include "json/json.h"
#include <fstream>

using namespace std;

sf::Color generate_random_color() 
{

    float r = rand() * 255;
    float g = rand() * 255;
    float b = rand() * 255;

    return sf::Color(r, g, b);
}

bool is_file_exist(const char* file_name)
{
    std::ifstream infile(file_name);
    return infile.good();
}

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(Constants::screen_width, Constants::screen_height), "Orbit Simulation");
    window.setFramerateLimit(60);


    std::vector<Body> bodies;

    const char* file_name = argv[1];

    if (!is_file_exist(file_name))
    {
        std::cout << "FILE NOT FOUND - EXITING";
        return -1;
    }

    parser input_parser = parser(file_name);
    Json::Value parsed_json_bodies = input_parser.parse();
    
    if (parsed_json_bodies)
    {
        for (int i = 0; i < parsed_json_bodies["bodies"].size(); i++)
        {
            bodies.push_back(
                Body(
                    parsed_json_bodies["bodies"][i]["mass"].asInt(),
                    parsed_json_bodies["bodies"][i]["radius"].asInt(),
                    generate_random_color(),
                    parsed_json_bodies["bodies"][i]["pos_x"].asInt(),
                    parsed_json_bodies["bodies"][i]["pos_y"].asInt(),
                    parsed_json_bodies["bodies"][i]["vel_x"].asInt(),
                    parsed_json_bodies["bodies"][i]["vel_y"].asInt(),
                    parsed_json_bodies["bodies"][i]["drawline"].asInt()));
        }
    }
    else
    {
        std::cout << "FAILED TO READ JSON FILE" << std::endl;
        return -1;
    }



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
            bodies[i].check_bounds();
            if (bodies[i].get_drawline())
            {
                bodies[i].update_line();
                bodies[i].draw_line(window);
            }
            bodies[i].render(window);

        }

        window.display();
    }


    return 0;
}

