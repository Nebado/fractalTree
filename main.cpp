#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <unistd.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "Fractal Tree");
    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();

        window.display();
        usleep(1000000);
    }

    return 0;
}
