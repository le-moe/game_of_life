#ifndef BOARD_HPP
#define BOARD_HPP


#include <SFML/Graphics.hpp>
#include <config.hpp>
#include "cell.hpp"

class Board 
{
    private:
        u4 width;
        u4 height;
        u4 totalCells;
        u4 scale;
        u1* pixels;
        Cell* cells;

    public:
        Board(u4 width, u4 height, u4 scale);
        void randomize();
        void colorCell(u4 posx, u4 posy, sf::Color c);
        void toArray(); // indiquer const car toArray ne modifie pas l'instance
        void epoch(); // une iteration de l'automate
        u4 getLivingNeighbour(u4 x, u4 y) const;
        u4 getCellIdx(u4 x, u4 y) const;
        u4 getWidth() const;
        u4 getHeight() const;
        u1* getPixels() const;
};

#endif // BOARD_HPP
