#include <SFML/Graphics.hpp>

class Mario
{
public:
    Mario()
    {
        groundLevel = 300;
        image.loadFromFile("mario.png");
        mario = sf::Sprite(image, sf::IntRect(0, 98, 80, 80));
        mario.setPosition(0, groundLevel);
    }

    void draw(sf::RenderWindow& window)
    {
        if (clock.getElapsedTime() > sf::seconds(0.1f))
        {
            clock.restart();
            mario.move(speed);
            auto pos = mario.getPosition().y - groundLevel;
            speed -= {0, pos / 10 };
        }
        window.draw(mario);
    }

    void move(sf::Event event)
    {
        if (event.key.code == sf::Keyboard::Left)
            speed -= { 1, 0 };
        else if (event.key.code == sf::Keyboard::Right)
            speed += { 1, 0 };
        else if (event.key.code == sf::Keyboard::Up)
            speed += { 0, -50 };
        else if (event.key.code == sf::Keyboard::Down)
            mario.move(0, 1);
    }

private:
    sf::Texture image;
    sf::Sprite mario;
    sf::Vector2f speed;
    sf::Clock clock;
    int groundLevel;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Mario!");
    sf::CircleShape virus(10.f);
    virus.setPosition(580, 200);
    Mario mario;
    virus.setFillColor(sf::Color::Green);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                mario.move(event);
        }

        if (clock.getElapsedTime() > sf::seconds(0.1f))
        {
            clock.restart();
            if (virus.getPosition().x < 0)
                virus.setPosition(580, 200);
            virus.move(-1, 0);
        }

        window.clear();
        window.draw(virus);
        mario.draw(window);
        window.display();
    }

    return 0;
}
