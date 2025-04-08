#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Easy.h"
#include "Medium.h"
#include "Hard.h"
#include "Demolition.h"

int main()
{
    sf :: RenderWindow title;
    sf :: RenderWindow difficulty;
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
                    demolition();
                }
                //if play game is clicked
                else if ((localPosition.x >= 751 && localPosition.x <=1175) && (localPosition.y >= 680 && localPosition.y <=780))
                {
                    title.close();
                    difficulty.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
                    difficulty.setFramerateLimit(60);

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
    while (difficulty.isOpen())
    {
        bool mouseHoverEasy,mouseHoverMedium,mouseHoverHard;
        while (const std :: optional event = difficulty.pollEvent())
        {
            if (event->is<sf :: Event :: Closed>())
                difficulty.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    difficulty.close();
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(difficulty);
                //check for easy button
                if ((localPosition.x >=746 && localPosition.x <=1170) && (localPosition.y >= 189 && localPosition.y <=319))
                {
                    difficulty.close();
                    easy();
                }
                //check for medium button
                else if ((localPosition.x >= 747 && localPosition.x <= 1174) && (localPosition.y >= 481 && localPosition.y <= 605))
                {
                    difficulty.close();
                    medium();
                }
                //check for hard button
                else if ((localPosition.x >= 750 && localPosition.x <= 1169) && (localPosition.y >= 743 && localPosition.y <= 873))
                {
                    difficulty.close();
                    hard();
                }
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
            }
            //checks if mouse moved in order to highlight buttons
            else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(difficulty);
                if ((localPosition.x >=746 && localPosition.x <=1170) && (localPosition.y >= 189 && localPosition.y <=319))
                {
                    difficulty.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_difficulty_select_easy.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    difficulty.draw(sprite);
                    difficulty.display();
                    mouseHoverEasy=true;
                }
                else if ((localPosition.x >= 747 && localPosition.x <= 1174) && (localPosition.y >= 481 && localPosition.y <= 605))
                {
                    difficulty.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_difficulty_select_medium.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    difficulty.draw(sprite);
                    difficulty.display();
                    mouseHoverMedium=true;
                }
                else if ((localPosition.x >= 750 && localPosition.x <= 1169) && (localPosition.y >= 743 && localPosition.y <= 873))
                {
                    difficulty.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_difficulty_select_hard.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    difficulty.draw(sprite);
                    difficulty.display();
                    mouseHoverHard=true;
                }
                else
                {
                    difficulty.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_difficulty_select.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    difficulty.draw(sprite);
                    difficulty.display();
                    mouseHoverEasy=false,mouseHoverMedium=false,mouseHoverHard=false;
                }
            }
        }
        //series of if statements to keep buttons highlighted again
        if (mouseHoverEasy==true && mouseHoverMedium==false && mouseHoverHard==false)
        {
            difficulty.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_difficulty_select_easy.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            difficulty.draw(sprite);
            difficulty.display();
        }
        else if (mouseHoverMedium==true && mouseHoverHard==false && mouseHoverEasy==false)
        {
            difficulty.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_difficulty_select_medium.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            difficulty.draw(sprite);
            difficulty.display();
        }
        else if (mouseHoverHard==true && mouseHoverEasy==false && mouseHoverMedium==false)
        {
            difficulty.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_difficulty_select_hard.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            difficulty.draw(sprite);
            difficulty.display();
        }
        else if (mouseHoverEasy==false && mouseHoverMedium==false && mouseHoverHard==false)
        {
            difficulty.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_difficulty_select.png", false, sf :: IntRect({0,0},{1920,1080}));sf::Sprite sprite(texture);
            difficulty.draw(sprite);
            difficulty.display();
        }
    }
}