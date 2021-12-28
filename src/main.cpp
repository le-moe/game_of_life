#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <board.hpp>

#define WIDTH 40
#define HEIGHT 40
#define SCALE 10

#define I(X,Y) (Y*WIDTH + X)*4
#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(WIDTH*SCALE, HEIGHT*SCALE), "Game of Life");

    Uint8 pixels[WIDTH*HEIGHT*4*SCALE*SCALE];

    Board board(WIDTH, HEIGHT);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if(Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i pos = Mouse::getPosition(window);
            printf("x: %i, y: %i\n", pos.x, pos.y);
        }

        // render
        for(uint x=0; x<WIDTH*SCALE; x++)
        {
            for(uint y=0; y<HEIGHT*SCALE; y++)
            {
                // uint value = board.getCell(x,y);
                for(uint i=0; i<SCALE; i++)
                {
                    for(uint j=0; j<SCALE; j++)
                    {
                        pixels[I(x*SCALE+i,y*SCALE+j)] = 255;
                        pixels[I(x*SCALE+i,y*SCALE+j)+1] = 0;
                        pixels[I(x*SCALE+i,y*SCALE+j)+2] = 0;
                        pixels[I(x*SCALE+i,y*SCALE+j)+3] = 255;
                    }

                }
            }
            
        }

        Image img;
        img.create(WIDTH*SCALE, HEIGHT*SCALE, pixels);

        Texture texture;
        texture.create(WIDTH*SCALE,HEIGHT*SCALE);
        texture.loadFromImage(img);

        Sprite sprite;
        sprite.setTexture(texture);
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
