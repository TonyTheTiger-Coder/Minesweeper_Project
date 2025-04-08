//
// Created by willw on 04/08/2025.
//
#ifndef HARD_H
#define HARD_H
void hard();
void hard()
{
    int rows;
    int columns;
    bool grid[30][30]={false};
    int mines=0;
    while (mines<180)
    {
        rows=rand()%30;
        columns=rand()%30;
        if (!grid[rows][columns])
        {
            grid[rows][columns]=true;
            mines++;
        }
    }
    sf :: RenderWindow hard;
    hard.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    hard.setFramerateLimit(60);
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
        sf :: Texture Square("../../src/emptySquareHard.png", false, sf :: IntRect({0,0},{30,30}));
        Square.setRepeated(true);
        sf::Sprite square(Square);
        square.setTextureRect(sf::IntRect({0,0},{900,900}));
        square.setPosition({511.f,93.f});
        hard.draw(square);
        for (rows=0; rows<30; rows++)
        {
            for (columns=0; columns<30; columns++)
            {
                if (grid[rows][columns] == true)
                {
                    sf :: Texture Mine("../../src/mineHard.png", false, sf :: IntRect({0,0},{30,30}));
                    sf::Sprite mine(Mine);
                    mine.setPosition({511.f+(30*rows),93.f+(30*columns)});
                    hard.draw(mine);
                }
            }
        }
        hard.display();
    }
    //180 mines for hard
}
#endif //HARD_H
