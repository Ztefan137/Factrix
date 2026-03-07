//
// Created by stefa on 3/7/2026.
//
#include "ui.h"
#include "color_scheme.h"
#include <SFML/Graphics.hpp>

    ui::ui(float x, float y, float width, float height,color_scheme& color_scheme){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->hidden=true;
        this->color_scheme=color_scheme;
    }