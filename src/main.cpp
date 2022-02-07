#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h> // srand rand
#include <time.h> //time
#include "board.h"

#define WIDTH 400
#define HEIGHT 400
#define SCALE 10

#define I(X,Y) (Y*WIDTH + X)*CHANNELS

using namespace sf;



int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Game of Life");

    // Create board
    Board board = Board(WIDTH, HEIGHT);

    srand(time(NULL));
    for(uint px=0; px<board.getWidth(); px++)
    {
        for(uint py=0; py<board.getHeight(); py++)
        {
            board.colorCell(px, py, sf::Color(rand() % 255,0,0));
        }
    }

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
        img.create(board.getWidth(), board.getHeight(), board.getPixels());

        Texture texture;
        texture.create(WIDTH,HEIGHT);
        texture.loadFromImage(img);

        Sprite sprite;
        sprite.setTexture(texture);
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
