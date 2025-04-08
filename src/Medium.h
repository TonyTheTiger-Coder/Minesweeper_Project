//
// Created by willw on 04/08/2025.
//
#ifndef MEDIUM_H
#define MEDIUM_H
#include "Easy.h"

void medium();
void medium()
{
    int countMinesMedium(bool grid[20][20], int rows, int columns);
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
        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {

                if (grid[rows][columns] == false)
                {
                    int mineCount=countMinesMedium(grid,rows,columns);
                    switch (mineCount)
                    {
                        case 1:
                        {
                            sf :: Texture Num1("../../src/minNum1Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num1(Num1);
                            num1.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num1);
                            break;
                        }
                        case 2:
                        {
                            sf :: Texture Num2("../../src/minNum2Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num2(Num2);
                            num2.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num2);
                            break;
                        }
                        case 3:
                        {
                            sf :: Texture Num3("../../src/minNum3Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num3(Num3);
                            num3.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num3);
                            break;
                        }
                        case 4:
                        {
                            sf :: Texture Num4("../../src/minNum4Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num4(Num4);
                            num4.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num4);
                            break;
                        }
                        case 5:
                        {
                            sf :: Texture Num5("../../src/minNum5Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num5(Num5);
                            num5.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num5);
                            break;
                        }
                        case 6:
                        {
                            sf :: Texture Num6("../../src/minNum6Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num6(Num6);
                            num6.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num6);
                            break;
                        }
                        case 7:
                        {
                            sf :: Texture Num7("../../src/minNum7Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num7(Num7);
                            num7.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num7);
                            break;
                        }
                        case 8:
                        {
                            sf :: Texture Num8("../../src/minNum8Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num8(Num8);
                            num8.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num8);
                            break;
                        }
                        default:
                        {
                            sf :: Texture Empty("../../src/emptySelectedSquareMedium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite empty(Empty);
                            empty.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(empty);
                            break;
                        }
                    }
                }
                if (grid[rows][columns] == true)
                {
                    sf :: Texture Mine("../../src/mineMedium.png", false, sf :: IntRect({0,0},{35,35}));
                    sf::Sprite mine(Mine);
                    mine.setPosition({610.f+(35*rows),190.f+(35*columns)});
                    medium.draw(mine);
                }
            }
        }
        medium.display();
    }
}
int countMinesMedium(bool grid[20][20], int rows, int columns)
{
    int checkHorizontal;
    int checkVertical;
    int count=0;
    for (int horizontal=-1;horizontal<=1;horizontal++)
    {
        for (int vertical=-1;vertical<=1;vertical++)
        {
            if (horizontal==0 && vertical==0)
                continue;
            else
            {
                checkHorizontal=rows+horizontal;
                checkVertical=columns+vertical;
            }
            if ((checkHorizontal >=0 && checkHorizontal<20) && (checkVertical >=0 && checkVertical<20))
            {
                if (grid[checkHorizontal][checkVertical])
                    count++;
            }
        }
    }
    return count;
}
#endif //MEDIUM_H
