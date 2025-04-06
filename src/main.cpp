#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    int screenWidth;
    int screenHeight;
    sf :: RenderWindow window;
    screenWidth = sf :: VideoMode :: getDesktopMode().size.x;
    screenHeight = sf :: VideoMode :: getDesktopMode().size.y;
    window.create(sf :: VideoMode(), "Minesweeper", sf :: State :: Fullscreen);
    sf::Vector2u size = window.getSize();
    auto [width, height] = size;
    std::cout << width << " " << height << std::endl;
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std :: optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf :: Event :: Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    window.close();
            }

        }
        window.clear(sf :: Color :: Black);
        sf :: Texture texture("Minesweeper_title_screen.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        window.draw(sprite);

        window.display();
    }
}