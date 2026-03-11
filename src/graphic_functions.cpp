//
// Created by stefa on 3/7/2026.
//
#include <SFML/Graphics.hpp>
#include "graphic_functions.h"
#include <vector>

#include "chunk.h"

struct coord_pair{
    int i,j;
};

void rect(sf::RenderWindow& window_obj,float xi,float yi, float xf, float yf,sf::Color color) {
    sf::RectangleShape rect;
    rect.setPosition({xi,yi});
    rect.setSize({xf-xi,yf-yi});
    rect.setFillColor(color);
    window_obj.draw(rect);
}
/*void render_chunks(sf::RenderWindow& window_obj) {
    vector <coord_pair> coords;
    compute_visible_chunks(window_obj,coords);
    vector <chunk> loaded_chunks;
    load_chunks(window_obj,coords,loaded_chunks);
}*/