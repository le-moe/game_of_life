#include "cell.hpp"
#include <SFML/Graphics.hpp>

Cell::Cell(u4 x, u4 y, bool isAlive) : x(x), y(y), isAlive(isAlive) {}

void Cell::die()
{
    isAlive = false;
    color = sf::Color(0,0,0,255);
}

void Cell::live()
{
    isAlive = true;
    color = sf::Color(255,255,255,255);
}

