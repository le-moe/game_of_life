#include "stdlib.h"
typedef unsigned int uint;

class Board
{
    public:
        uint* cells;
        uint width;
        uint height;

        Board(uint width, uint height);
        uint getCell(uint x, uint y);
};
