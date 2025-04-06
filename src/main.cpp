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
        bool mouse_hover_play,mouse_hover_demolition,mouse_hover_exit;

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
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
                if ((localPosition.x >= 753 && localPosition.x <=1177) && (localPosition.y >= 953 && localPosition.y <=1044))
                    window.close();
            }
            else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if ((localPosition.x >=751 && localPosition.x <=1175) && (localPosition.y >= 680 && localPosition.y <=780))
                {
                    window.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_title_screen_new_play.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    window.draw(sprite);
                    window.display();
                    mouse_hover_play=true;
                }
                else if ((localPosition.x >= 752 && localPosition.x <= 1178) && (localPosition.y >= 817 && localPosition.y <= 910))
                {
                    window.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_title_screen_new_demolition.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    window.draw(sprite);
                    window.display();
                    mouse_hover_demolition=true;
                }
                else if ((localPosition.x >= 753 && localPosition.x <= 1177) && (localPosition.y >= 953 && localPosition.y <= 1044))
                {
                    window.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_title_screen_new_exit.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    window.draw(sprite);
                    window.display();
                    mouse_hover_exit=true;
                }
                else
                {
                    window.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_title_screen_new.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    window.draw(sprite);
                    window.display();
                    mouse_hover_play=false,mouse_hover_demolition=false,mouse_hover_exit=false;
                }
            }
        }

        if (mouse_hover_play==true && mouse_hover_demolition==false && mouse_hover_exit==false)
        {
            window.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_title_screen_new_play.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            window.draw(sprite);
            window.display();
        }
        if (mouse_hover_demolition==true && mouse_hover_exit==false && mouse_hover_play==false)
        {
            window.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_title_screen_new_demolition.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            window.draw(sprite);
            window.display();
        }
        if (mouse_hover_exit==true && mouse_hover_play==false && mouse_hover_demolition==false)
        {
            window.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_title_screen_new_exit.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            window.draw(sprite);
            window.display();
        }
        if (mouse_hover_play==false && mouse_hover_demolition==false && mouse_hover_exit==false)
        {
            window.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_title_screen_new.png", false, sf :: IntRect({0,0},{1920,1080}));sf::Sprite sprite(texture);
            window.draw(sprite);
            window.display();
        }
    }
}