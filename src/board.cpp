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
    printf("Making board width=%u, height=%u\n", width, height);
} // list d'initialisation pour tous les attributs

void Board::Debug()
{
    for(u4 x=0; x<width; x++)
    {
        for(u4 y=0; y<height; y++)
        {
            u4 nalive = getLivingNeighbour(x,y);
            u4 alive = getCell(y,x).isAlive;
            printf("cell (%u,%u)\talive=%d\thas %u neighbour\n", x,y,alive, nalive);
        }
    }
}

Cell Board::getCell(u4 x, u4 y) const
{
    u4 idx = getCellIdx(x,y);
    return cells[idx];
}


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

void Board::printBoard(void) const
{

    printf("Board Cells\n======\n");
    for (u4 y=0; y<height; y++)
    {
        for (u4 x=0; x<width; x++)
        {
            Cell c = getCell(x,y);
            char symb;
            if (c.isAlive) {
                symb = 'X';
            } 
            else {
                symb = '0';
            }
            printf("%c    ", symb);
        }
        printf("\n");
    }
}

void Board::printBoardNeighbour(void) const
{

    printf("Board Neghbour\n======\n");
    for (u4 y=0; y<height; y++)
    {
        for (u4 x=0; x<width; x++)
        {
            Cell c = getCell(x,y);
            u4 nbr = getLivingNeighbour(x,y);
            printf("%u    ", nbr);
        }
        printf("\n");
    }
}

u4 Board::getLivingNeighbour(u4 x, u4 y) const
{
    u4 nalive = 0;
    u4 idx[8];
    int a = (int) x; /* cast to compare with signedness */
    int b = (int) y; /* cast to compare with signedness */
    for ( int i=a-1; i<= a+1; i++)
    {
        if (i < 0 || i >= (int) width){
            continue; /* out of bounds */
        }
        for ( int j=b-1; j<=b+1; j++)
        {
            if (j < 0 || j >= (int) height){
                continue; /* out of bounds */
            }   
            Cell target = cells[getCellIdx(i,j)];
            if(target.isAlive)
            {
                nalive++;
            }
        }
    }

    if (cells[getCellIdx(x,y)].isAlive)
    {
        nalive--; /* cell cannot be its own neighbour */
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
