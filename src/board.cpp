#include <stdlib.h>
#include "board.hpp"
#include "cell.hpp"

Board::Board(u4 width, u4 height, u4 scale) : width(width), height(height), scale(scale)
{
    totalCells = width*height;
    pixels = (u1*) malloc(totalCells*scale*scale*4);
    cells = (Cell*) malloc(sizeof(Cell) * width*height);
    printf("malloc size %lu\n", sizeof(Cell) * width*height);
    for(u4 x=0; x<width; x++)
    {
        for(u4 y=0; y<height; y++)
        {
            cells[getCellIdx(x,y)] = Cell(x,y, false);
        }
    }
} // list d'initialisation pour tous les attributs

void Board::epoch()
{
    Cell* cells_n = (Cell*) malloc(sizeof(Cell) * width*height);
    memcpy(cells_n, cells, sizeof(Cell) * width*height);

    for(u4 x=0; x<width; x++)
    {
        for(u4 y=0; y<height; y++)
        {
            u4 nalive = getLivingNeighbour(x,y);
            u4 c_idx = getCellIdx(x,y);
            Cell current = cells[c_idx];
            printf("%u %u - %u neighbour\n", x, y, nalive);
            // if (current.isAlive && !(nalive == 2 or nalive == 3))
            //     cells_n[c_idx].die();
            // if (!current.isAlive && nalive == 3)
            //     cells_n[c_idx].live();
        }
    }
    memcpy(cells, cells_n, sizeof(Cell) * width*height);
}

u4 Board::getLivingNeighbour(u4 x, u4 y) const
{
    u4 nalive = 0;
    u4 idx[8];
    idx[0] = getCellIdx(x-1,y-1);  // topL
    idx[1] = getCellIdx(x,y-1);  // topM
    idx[2] = getCellIdx(x+1,y-1);  // topR
    idx[3] = getCellIdx(x-1,y);  // left
    idx[4] = getCellIdx(x+1,y);  // right
    idx[5] = getCellIdx(x-1,y+1);  // botL
    idx[6] = getCellIdx(x, y+1);  // botM
    idx[7] = getCellIdx(x+1,y+1);  // botR

    for (u4 n = 0; n<8; n++)
    {
        if (idx[n] < 0 or idx[n] >= width*height)
            continue;
        
        if(cells[idx[n]].isAlive)
            nalive++;
    }
    return nalive;
}

void Board::randomize()
{
    srand(time(NULL));
    for(u4 x=0; x<width; x++)
    {
        for(u4 y=0; y<height; y++)
        {
            rand()%2==0 ? cells[getCellIdx(x,y)].live() : cells[getCellIdx(x,y)].die();
        }
    }
}

void Board::colorCell(u4 posx, u4 posy, sf::Color c)
{
    cells[getCellIdx(posx, posy)].color = c;
}

u4 Board::getCellIdx(u4 x, u4 y) const
{
    return y*width + x;
}

void Board::toArray()
{
    for (u4 i=0; i<totalCells; i++)
    {
        Cell current = cells[i];
        for(u4 sx=0; sx<scale; sx++)
        {
            for(u4 sy=0; sy<scale; sy++)
            {
                u4 px = current.x*scale + sx;
                u4 py = current.y*scale + sy;
                
                u4 window_sx = width*scale;
                u4 window_sy = height*scale;

                u4 pixel_idx = (px + py*window_sx)*4;
                pixels[pixel_idx]     = current.color.r;
                pixels[pixel_idx + 1] = current.color.g;
                pixels[pixel_idx + 2] = current.color.b;
                pixels[pixel_idx + 3] = current.color.a;
            }
        } 
    }

}

u1* Board::getPixels() const
{
    return pixels;
}

u4 Board::getWidth() const
{
    return width;
}

u4 Board::getHeight() const
{
    return height;
}
