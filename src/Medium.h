//
// Created by willw on 04/08/2025.
//

#ifndef MEDIUM_H
#define MEDIUM_H
void medium();
void medium()
{
    sf :: RenderWindow medium;
    medium.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    medium.setFramerateLimit(60);
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
        sf :: Texture Square("../../src/emptySquareMedium.png", false, sf :: IntRect({0,0},{35,35}));
        Square.setRepeated(true);
        sf::Sprite square(Square);
        square.setTextureRect(sf::IntRect({0,0},{700,700}));
        square.setPosition({610.f, 190.f});
        medium.draw(square);
        medium.display();
    }
}
#endif //MEDIUM_H
