//
// Created by willw on 04/07/2025.
//

#ifndef WINDOWS_H
#define WINDOWS_H
void Windows();
void Windows()
{
    sf :: RenderWindow title;
    sf :: RenderWindow difficulty;
    sf :: RenderWindow easy;
    sf :: RenderWindow medium;
    sf :: RenderWindow hard;
    sf :: RenderWindow demolition;
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
                    demolition.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
                    demolition.setFramerateLimit(60);
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
                    easy.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
                    easy.setFramerateLimit(60);
                }
                //check for medium button
                else if ((localPosition.x >= 747 && localPosition.x <= 1174) && (localPosition.y >= 481 && localPosition.y <= 605))
                {
                    difficulty.close();
                    medium.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
                    medium.setFramerateLimit(60);
                }
                //check for hard button
                else if ((localPosition.x >= 750 && localPosition.x <= 1169) && (localPosition.y >= 743 && localPosition.y <= 873))
                {
                    difficulty.close();
                    hard.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
                    hard.setFramerateLimit(60);
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
    while (demolition.isOpen())
    {
        while (const std :: optional event = demolition.pollEvent())
        {

            if (event->is<sf :: Event :: Closed>())
                demolition.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    demolition.close();
            }
        }
        demolition.clear(sf :: Color :: Black);
        //demolition will always use the medium sized difficulty
        sf :: Texture texture("../../src/Minesweeper_medium.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        demolition.draw(sprite);
        demolition.display();
    }
    while (easy.isOpen())
    {
        while (const std :: optional event = easy.pollEvent())
        {
            if (event->is<sf :: Event :: Closed>())
                easy.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    easy.close();
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(easy);
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
            }
        }
        easy.clear(sf :: Color :: Black);
        sf :: Texture texture("../../src/Minesweeper_easy.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        easy.draw(sprite);
        easy.display();
    }
    while (medium.isOpen())
    {
        while (const std :: optional event = medium.pollEvent())
        {
            if (event->is<sf :: Event :: Closed>())
                medium.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    medium.close();
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(medium);
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
            }
        }
        medium.clear(sf :: Color :: Black);
        sf :: Texture texture("../../src/Minesweeper_medium.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        medium.draw(sprite);
        medium.display();
    }
    while (hard.isOpen())
    {
        while (const std :: optional event = hard.pollEvent())
        {
            if (event->is<sf :: Event :: Closed>())
                hard.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    hard.close();
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(hard);
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
            }
        }
        hard.clear(sf :: Color :: Black);
        sf :: Texture texture("../../src/Minesweeper_hard.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        hard.draw(sprite);
        hard.display();
    }
}
#endif //WINDOWS.h
