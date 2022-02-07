#include <stdlib.h>
#include "board.hpp"


Board::Board(uint width, uint height) : width(width), height(height)
{
    pixels = (Uint8*) malloc(width * height * 4);
} // list d'initialisation pour tous les attributs

void Board::colorCell(uint posx, uint posy, sf::Color c)
{
    pixels[(posx + posy * width)*4] = c.r;
    pixels[(posx + posy * width)*4 + 1] = c.g;
    pixels[(posx + posy * width)*4 + 2] = c.b;
    pixels[(posx + posy * width)*4 + 3] = c.a;
}

void Board::toArray() const
{
    // TODO
}

uint Board::getWidth() const
{
    return width;
}

uint Board::getHeight() const
{
    return height;
}

Uint8* Board::getPixels() const
{
    return pixels;
}