//
// Created by stefa on 3/7/2026.
//

#ifndef OOP_UI_H
#define OOP_UI_H
#include <SFML/Graphics.hpp>
#include "color_scheme.h"
class ui {
protected:
    float x;
    float y;
    float width;
    float height;
    bool hidden;
    color_scheme ui_color_scheme;
public:
    ui(float x, float y, float width, float height,color_scheme& ui_color_scheme);
};

#endif //OOP_UI_H
