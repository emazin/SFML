#include <SFML/Graphics.hpp>

void movement(sf::Transformable& shape, sf::Event event)
{
    if(event.key.code == sf::Keyboard::Left)
        shape.move(-1, 0);
    else if (event.key.code == sf::Keyboard::Right)
        shape.move(1, 0);
    else if (event.key.code == sf::Keyboard::Up)
        shape.move(0, -1);
    else if (event.key.code == sf::Keyboard::Down)
        shape.move(0, 1);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Mario!");
    sf::CircleShape shape(10.f);
    sf::Texture image;
    image.loadFromFile("mario.png");
    sf::Sprite mario(image, sf::IntRect(100, 100, 120, 120));
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                movement(mario, event);
        }

        window.clear();
        window.draw(mario);
        window.display();
    }

    return 0;
}
