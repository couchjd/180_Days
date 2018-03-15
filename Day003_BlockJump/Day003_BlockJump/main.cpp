#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Day 003 - Block Jump");
	
	Player player;
	sf::Time deltaTime;
	sf::Clock clock;
	
	float dtAsSeconds;

	sf::RectangleShape floor(sf::Vector2f(800.f, 100.f));
	sf::CircleShape sun(50.f);

	floor.setPosition(sf::Vector2f(0.f, window.getSize().y - floor.getSize().y));
	player.setPosition(sf::Vector2f(30.f, floor.getPosition().y - player.getSize().y));
	sun.setPosition(sf::Vector2f(600.f, 50.f));
	
	player.ground = player.getPosition().y;

	player.setFillColor(sf::Color::Red);
	floor.setFillColor(sf::Color::Green);
	sun.setFillColor(sf::Color::Yellow);

	while(window.isOpen()) {
		deltaTime = clock.restart();
		dtAsSeconds = deltaTime.asSeconds();
		
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed) {
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					player.jump();
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					player.doMove(RIGHT);
				}

				if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					player.doMove(LEFT);
				}
			}
		}

    if(player.getPosition().x < 0) {
      player.setPosition(sf::Vector2f(0.f, player.getPosition().y));
      player.velocity.x = 0;
    }
    if(player.getPosition().x + player.getSize().x > window.getSize().x) {
      player.setPosition(sf::Vector2f(window.getSize().x - player.getSize().x, player.getPosition().y));
      player.velocity.x = 0;
    }
		player.update(dtAsSeconds);
		
		window.clear(sf::Color::Cyan);

		
		window.draw(floor);
		window.draw(sun);
    window.draw(player);

		window.display();
	}
	return 0;
}

