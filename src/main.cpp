#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf :: RenderWindow window;
    window.create(sf :: VideoMode(), "Minesweeper", sf :: State :: Fullscreen);
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std :: optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf :: Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }

        }
        window.clear(sf :: Color::Black);

        window.display();
    }
}