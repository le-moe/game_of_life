#include "stdlib.h"

class Board
{
    public:
        uint* cells;
        uint width;
        uint height;

        Board(uint width, uint height);
        uint getCell(uint x, uint y);
};