//
// Created by willw on 04/08/2025.
//

#ifndef DEMOLITION_H
#define DEMOLITION_H
void demolition();
void demolition()
{
    sf :: RenderWindow demolition;
    demolition.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    demolition.setFramerateLimit(60);
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
        sf :: Texture texture("../../src/Minesweeper_demolition.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        demolition.draw(sprite);
        sf :: Texture Square("../../src/emptySquareMedium.png", false, sf :: IntRect({0,0},{35,35}));
        Square.setRepeated(true);
        sf::Sprite square(Square);
        square.setTextureRect(sf::IntRect({0,0},{700,700}));
        square.setPosition({610, 190});
        demolition.draw(square);
        demolition.display();
    }
}
#endif //DEMOLITION_H
