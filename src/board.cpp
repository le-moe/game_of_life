#include <stdlib.h>
#include "board.hpp"

Board::Board(uint width, uint height, uint scale) : width(width), height(height), scale(scale)
{
    totalCells = width*height;
    pixels = (Uint8*) malloc(totalCells*scale*scale*4);
    cells = (Cell*) malloc(sizeof(Cell) * width*height);
    printf("malloc size %lu\n", sizeof(Cell) * width*height);
    for(uint x=0; x<width; x++)
    {
        for(uint y=0; y<height; y++)
        {
            cells[getCellIdx(x,y)].x        = x;
            cells[getCellIdx(x,y)].y        = y;
            cells[getCellIdx(x,y)].color    =  sf::Color(50,0,0);
        }
    }
} // list d'initialisation pour tous les attributs

void Board::printCells() const
{
    for(uint i=0; i<totalCells; i++)
    {
        Cell t = cells[i];
        printf("x:%u, y:%u, %u %u %u\n", t.x, t.y, t.color.r, t.color.g, t.color.b);
    }
}

void Board::colorCell(uint posx, uint posy, sf::Color c)
{
    cells[getCellIdx(posx, posy)].color = c;
}

uint Board::getCellIdx(uint x, uint y) const
{
    return y*width + x;
}

void Board::toArray()
{
    for (uint i=0; i<totalCells; i++)
    {
        Cell current = cells[i];
        for(uint sx=0; sx<scale; sx++)
        {
            for(uint sy=0; sy<scale; sy++)
            {
                uint px = current.x*scale + sx;
                uint py = current.y*scale + sy;
                
                uint window_sx = width*scale;
                uint window_sy = height*scale;

                uint pixel_idx = (px + py*window_sx)*4;
                pixels[pixel_idx]     = current.color.r;
                pixels[pixel_idx + 1] = current.color.g;
                pixels[pixel_idx + 2] = current.color.b;
                pixels[pixel_idx + 3] = current.color.a;
            }
        } 
    }

}

Uint8* Board::getPixels() const
{
    return pixels;
}

uint Board::getWidth() const
{
    return width;
}

uint Board::getHeight() const
{
    return height;
}
