//
// Created by stefa on 3/7/2026.
//

#ifndef OOP_COLOR_SCHEME_H
#define OOP_COLOR_SCHEME_H
#include <SFML/Graphics.hpp>

struct element_color_scheme {
    sf::Color color;
    sf::Color dark_margin=sf::Color::White;
    sf::Color light_margin=sf::Color::White;
};
class color_scheme {
    sf::Color window_color=sf::Color::White;
    sf::Color window_dark_margin=sf::Color::White;
    sf::Color window_light_margin=sf::Color::White;
    sf::Color section_color=sf::Color::White;
    sf::Color section_dark_margin=sf::Color::White;
    sf::Color section_light_margin=sf::Color::White;
    sf::Color button_color=sf::Color::White;
    sf::Color button_dark_margin=sf::Color::White;
    sf::Color button_light_margin=sf::Color::White;
public:
    color_scheme();
    void set_window_scheme(element_color_scheme scheme);
};


#endif //OOP_COLOR_SCHEME_H