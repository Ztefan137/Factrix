//
// Created by stefa on 3/7/2026.
//

#include "ui.h"
#include <SFML/Graphics.hpp>

#ifndef OOP_WINDOW_H
#define OOP_WINDOW_H


class ui_window :public ui{
    public:
        ui_window(float x, float y, float width, float height,color_scheme& ui_color_scheme);
        void render(sf::RenderWindow& window_obj);
};


#endif //OOP_WINDOW_H