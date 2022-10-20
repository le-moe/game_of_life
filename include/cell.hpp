#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
typedef unsigned int            u4;

class Cell
{
    private:
    public:
        u4 x;
        u4 y;
        bool isAlive;
        sf::Color color;
        
        Cell(u4 x, u4 y, bool isAlive);
        void die();
        void live();

} ;

#endif // CELL_HPP