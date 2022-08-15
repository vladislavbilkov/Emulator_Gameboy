#include <iostream>
#include <SFML/Graphics.hpp>

#include "debug.h"
#include "emulator.h"

int main(int argc, char *argv[])
{
    std::cout << "Nintendo Game Boy emulator\n";

    sf::RenderWindow window(sf::VideoMode(160, 144), "DMG", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    window.draw(shape);
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    Emulator DMG;

    if (argc > 1) {
        std::string cartridge = argv[1];
        DMG.InsertCartridge("roms/"+cartridge);
    } else {
        DMG.InsertCartridge("roms/Tetris.gb");
    }

    DMG.Run();

    return 0;
}
