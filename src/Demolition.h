//
// Created by willw on 04/08/2025.
//
#ifndef DEMOLITION_H
#define DEMOLITION_H
void demolition();
void demolition()
{
    int rows;
    int columns;
    bool grid[20][20]={false};
    int mines=0;
    while (mines<60)
    {
        rows=rand()%20;
        columns=rand()%20;
        if (!grid[rows][columns])
        {
            grid[rows][columns]=true;
            mines++;
        }
    }
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
        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {
                if (grid[rows][columns] == true)
                {
                    sf :: Texture Mine("../../src/mineMedium.png", false, sf :: IntRect({0,0},{35,35}));
                    sf::Sprite mine(Mine);
                    mine.setPosition({610.f+(35*rows),190.f+(35*columns)});
                    demolition.draw(mine);
                }
            }
        }
        demolition.display();
    }
    //60 mines in demolition
}
#endif //DEMOLITION_H
