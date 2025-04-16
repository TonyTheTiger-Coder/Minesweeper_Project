//
// Created by willw on 04/15/2025.
//

#ifndef TITLE_H
#define TITLE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Demolition.h"
#include "Difficulty.h"
inline void title()
{
    sf :: RenderWindow title;
    title.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    title.setFramerateLimit(60);
    // run the program as long as the window is open
    while (title.isOpen())
    {
        bool mouseHoverPlay,mouseHoverDemolition,mouseHoverExit;

        // check all the window's events that were triggered since the last iteration of the loop
        while (const std :: optional event = title.pollEvent())
        {

            // "close requested" event: we close the window
            if (event->is<sf :: Event :: Closed>())
                title.close();
            //closes the window when the ESC key is pressed
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    title.close();
            }
            //sets up invisible buttons that the user can click for the desired action
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(title);
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
                //if exit game is clicked
                if ((localPosition.x >= 753 && localPosition.x <=1177) && (localPosition.y >= 953 && localPosition.y <=1044))
                    title.close();
                //if demolition is clicked
                else if ((localPosition.x >= 752 && localPosition.x <= 1178) && (localPosition.y >= 817 && localPosition.y <= 910))
                {
                    title.close();
                    Demolition();
                }
                //if play game is clicked
                else if ((localPosition.x >= 751 && localPosition.x <=1175) && (localPosition.y >= 680 && localPosition.y <=780))
                {
                    title.close();
                    difficulty();

                }
            }
            //finds position of mouse whenever it is moved in order to highlight buttons
            else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(title);
                if ((localPosition.x >=751 && localPosition.x <=1175) && (localPosition.y >= 680 && localPosition.y <=780))
                {
                    title.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_title_screen_new_play.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    title.draw(sprite);
                    title.display();
                    mouseHoverPlay=true;
                }
                else if ((localPosition.x >= 752 && localPosition.x <= 1178) && (localPosition.y >= 817 && localPosition.y <= 910))
                {
                    title.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_title_screen_new_demolition.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    title.draw(sprite);
                    title.display();
                    mouseHoverDemolition=true;
                }
                else if ((localPosition.x >= 753 && localPosition.x <= 1177) && (localPosition.y >= 953 && localPosition.y <= 1044))
                {
                    title.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_title_screen_new_exit.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    title.draw(sprite);
                    title.display();
                    mouseHoverExit=true;
                }
                else
                {
                    title.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_title_screen_new.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    title.draw(sprite);
                    title.display();
                    mouseHoverPlay=false,mouseHoverDemolition=false,mouseHoverExit=false;
                }
            }
        }
        //series of if statements that keep button highlighted until the mouse is moved off of the button
        if (mouseHoverPlay==true && mouseHoverDemolition==false && mouseHoverExit==false)
        {
            title.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_title_screen_new_play.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            title.draw(sprite);
            title.display();
        }
        else if (mouseHoverDemolition==true && mouseHoverExit==false && mouseHoverPlay==false)
        {
            title.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_title_screen_new_demolition.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            title.draw(sprite);
            title.display();
        }
        else if (mouseHoverExit==true && mouseHoverPlay==false && mouseHoverDemolition==false)
        {
            title.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_title_screen_new_exit.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            title.draw(sprite);
            title.display();
        }
        else if (mouseHoverPlay==false && mouseHoverDemolition==false && mouseHoverExit==false)
        {
            title.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_title_screen_new.png", false, sf :: IntRect({0,0},{1920,1080}));sf::Sprite sprite(texture);
            title.draw(sprite);
            title.display();
        }
    }
}
#endif //TITLE_H
