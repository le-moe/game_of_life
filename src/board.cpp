#include "board.hpp"


Board::Board(uint width, uint height): width(width), height(height)
{
    cells = (uint*) malloc(sizeof(uint) * width * height);
}

uint Board::getCell(uint x, uint y)
{
    return this->cells[y*this->width + x];
}
