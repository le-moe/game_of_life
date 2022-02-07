#include <SFML/Graphics.hpp>

typedef unsigned int uint;
typedef unsigned char Uint8;
typedef unsigned int Uint32;

class Board 
{
    private:
        uint width;
        uint height;
        uint scale;
        Uint8* pixels;

    public:
        Board(uint width, uint height, uint scale);
        void colorCell(uint posx, uint posy, sf::Color c);
        void toArray() const; // indiquer const car toArray ne modifie pas l'instance
        uint getWidth() const;
        uint getHeight() const;
        Uint8* getPixels() const;
};
