#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    sf :: Window window;
    window.create(sf :: VideoMode({400, 400}), "Minesweeper");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                std::cout << "new width: " << resized->size.x << std::endl;
                std::cout << "new height: " << resized->size.y << std::endl;
            }
        }
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std :: optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf :: Event::Closed>())
                window.close();
        }
    }
}