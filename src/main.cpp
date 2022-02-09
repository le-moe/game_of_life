#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h> // srand rand
#include <time.h> //time
#include "board.hpp"

#define WIDTH 40
#define HEIGHT 40
#define SCALE 20

#define I(X,Y) (Y*WIDTH + X)*CHANNELS

using namespace sf;



int main()
{
    RenderWindow window(VideoMode(WIDTH*SCALE, HEIGHT*SCALE), "Game of Life");

    // Create board
    Board board = Board(WIDTH, HEIGHT, SCALE);

    // Init board
    srand(time(NULL));
    for(uint px=0; px<WIDTH; px++)
    {
        for(uint py=0; py<HEIGHT; py++)
        {
            board.colorCell(px, py, sf::Color(rand() % 255,0,0));
        }
    }

    // board.printCells();
    board.toArray();

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

        Image img;
        img.create(WIDTH*SCALE, WIDTH*SCALE, board.getPixels());

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
