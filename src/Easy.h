//
// Created by willw on 04/07/2025.
//

#ifndef EASY_H
#define EASY_H
void easy();
void easy()
{
    sf :: RenderWindow easy;
    easy.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    easy.setFramerateLimit(60);
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
        sf :: Texture Square("../../src/emptySquareEasy.png", false, sf :: IntRect({0,0},{50,50}));
        Square.setRepeated(true);
        sf::Sprite square(Square);
        square.setTextureRect(sf::IntRect({0,0},{500,500}));
        square.setPosition({712.f, 289.f});
        easy.draw(square);
        easy.display();
    }
}

#endif //EASY.h
