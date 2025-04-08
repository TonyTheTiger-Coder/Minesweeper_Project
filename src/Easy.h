//
// Created by willw on 04/07/2025.
//
#ifndef EASY_H
#define EASY_H
void easy();
void easy()
{
    int rows;
    int columns;
    bool grid[10][10]={false};
    int mines=0;
    while (mines<10)
    {
        rows=rand()%10;
        columns=rand()%10;
        if (!grid[rows][columns])
        {
            grid[rows][columns]=true;
            mines++;
        }
    }
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

        for (rows=0; rows<10; rows++)
        {
            for (columns=0; columns<10; columns++)
            {
                if (grid[rows][columns] == true)
                {
                    sf :: Texture Mine("../../src/mineEasy.png", false, sf :: IntRect({0,0},{50,50}));
                    sf::Sprite mine(Mine);
                    mine.setPosition({712.f+(50*rows),289.f+(50*columns)});
                    easy.draw(mine);
                }
            }
        }
        easy.display();
    }
}
#endif //EASY.h
