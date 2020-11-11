#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <unistd.h>
#include <cmath>

void lineTo(float x, float y, float length, float angle)
{
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x + length * cos(angle), y + length * sin(angle));
    glEnd();
}

void tree(float x, float y, float length, float angle, float lenDiv, float angleDif, int depth)
{
    lineTo(x, y, length, angle);

    if (depth == 0) return;

    // Right
    tree(x + length * cos(angle), y + length * sin(angle), length * lenDiv, angle + angleDif, lenDiv, angleDif, depth-1);

    // Left
    tree(x + length * cos(angle), y + length * sin(angle), length * lenDiv, angle - angleDif, lenDiv, angleDif, depth-1);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fractal Tree");
    window.setFramerateLimit(30);
    glOrtho(0.0, window.getSize().x, window.getSize().y, 0.0, 1.0, -1.0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();

        tree(400.0, 750.0, 100.0, -M_PI/2.0, 0.8, M_PI/12.0, 10);

        window.display();
        usleep(1000000);
    }

    return 0;
}
