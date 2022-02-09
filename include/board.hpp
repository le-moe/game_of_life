#ifndef BOARD_HPP
#define BOARD_HPP


#include <SFML/Graphics.hpp>
#include <config.hpp>
#include "cell.hpp"

class Board 
{
    private:
        uint width;
        uint height;
        uint totalCells;
        uint scale;
        Uint8* pixels;
        Cell* cells;

    public:
        Board(uint width, uint height, uint scale);
        void colorCell(uint posx, uint posy, sf::Color c);
        void toArray(); // indiquer const car toArray ne modifie pas l'instance
        void printCells() const;
        uint getCellIdx(uint x, uint y) const;
        uint getWidth() const;
        uint getHeight() const;
        Uint8* getPixels() const;
};

#endif // BOARD_HPP
