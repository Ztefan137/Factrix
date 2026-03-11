//
// Created by stefa on 3/7/2026.
//

#include "ui.h"
#include "window.h"
#include "graphic_functions.h"
#include <SFML/Graphics.hpp>
ui_window::ui_window(float x, float y, float width, float height,color_scheme& ui_color_scheme) : ui(x,y,width,height,ui_color_scheme) {

}
void ui_window::render(sf::RenderWindow& window_obj) {
    float left   = x - width  * 0.5f;
    float right  = x + width  * 0.5f;
    float top    = y - height * 0.5f;
    float bottom = y + height * 0.5f;

    rect(window_obj, left, top, right, bottom, ui_color_scheme.window_dark_margin);
    rect(window_obj, left + 4, top + 4, right - 4, bottom - 4, ui_color_scheme.window_light_margin);
    rect(window_obj, left + 4, top, right - 4, bottom + 4, ui_color_scheme.window_color);
}