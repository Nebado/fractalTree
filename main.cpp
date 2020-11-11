#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <unistd.h>

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

        glColor3f(0.28, 0.28, 0.28);
        glBegin(GL_LINES);
        glVertex2f(150.0, 300.0);
        glVertex2f(150.0, 500.0);
        glEnd();

        window.display();
        usleep(1000000);
    }

    return 0;
}
