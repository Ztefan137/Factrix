#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "src/graphic_functions.h"

#include "src/ui.h"
#include "src/color_scheme.h"
#include "src/window.h"
//////////////////////////////////////////////////////////////////////
void render_logic(sf::RenderWindow& window_obj){
        rect(window_obj,0,0,10000,10000,sf::Color::White);
        rect(window_obj,100,100,200,200,sf::Color::Red);
        //draw_chunks();
}



int main() {


    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktop.size.x;
    unsigned int screenHeight = desktop.size.y;

    color_scheme default_scheme=color_scheme();
    default_scheme.window_dark_margin=sf::Color(0x0a,0x0a,0x0a,0xff);
    default_scheme.window_light_margin=sf::Color(0x3a,0x3a,0x3a,0xff);
    default_scheme.window_color=sf::Color(0x2a,0x2a,0x2a,0xff);
    ui_window test_ui(screenWidth/2.f,screenHeight/2,700,450,default_scheme);

    //write an texture sprite declaration


    sf::Texture texture;
    if (!texture.loadFromFile("assets/dirt.png")) {
        std::cout<<"error";
    }

    sf::Sprite sprite(texture);

    // Desired size
    float targetWidth = 150.f;
    float targetHeight = 150.f;

    // Original size
    sf::Vector2u texSize = texture.getSize();

    // Compute scale factors
    float scaleX = targetWidth / texSize.x;
    float scaleY = targetHeight / texSize.y;

    sprite.setScale({scaleX, scaleY});

    sf::RenderWindow window;
    window.create(sf::VideoMode({screenWidth, screenHeight}), "My Window", sf::State::Fullscreen);

    std::cout << "Fereastra a fost creată\n";
    ///////////////////////////////////////////////////////////////////////////
    /// NOTE: mandatory use one of vsync or FPS limit (not both)            ///
    /// This is needed so we do not burn the GPU                            ///
    window.setVerticalSyncEnabled(true);                                    ///
    /// window.setFramerateLimit(60);                                       ///
    ///////////////////////////////////////////////////////////////////////////

    while(window.isOpen()) {
        bool shouldExit = false;

        while(const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                std::cout << "Fereastra a fost închisă\n";
            }
            else if (event->is<sf::Event::Resized>()) {
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
            }
            else if (event->is<sf::Event::KeyPressed>()) {
                const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
                std::cout << "Received key " << (keyPressed->scancode == sf::Keyboard::Scancode::X ? "X" : "(other)") << "\n";
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    shouldExit = true;
                }
            }
        }
        if(shouldExit) {
            window.close();
            std::cout << "Fereastra a fost închisă (shouldExit == true)\n";
            break;
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(300ms);

        window.clear();
        render_logic(window);
        for (float i=0;i<10;i++) {
            for (float j=0;j<10;j++) {
                sprite.setPosition({j*150, i*150});
                window.draw(sprite);
            }
        }
        test_ui.render(window);
        window.display();
    }

    std::cout << "Programul a terminat execuția\n";
    return 0;
}