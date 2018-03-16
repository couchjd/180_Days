#pragma once
#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include <iostream>
#include <vector>
#include "Projectile.h"

#define THETA 10 * M_PI / 180

enum id { PLAYER1, PLAYER2, PROJECTILE };

class NetShooter {
public:
	NetShooter();
	sf::RenderWindow window;
  sf::TcpSocket socket;

	sf::Vector2f getCentroid(const sf::VertexArray& polygon);
	sf::Vector2f normalize(const sf::Vector2f& vector);
	sf::Vector2f facing(const sf::VertexArray& polygon);
	std::vector<Projectile*> projectiles;
	Projectile* projectile = new Projectile();
	Projectile* newProj;
	void run();

private:
	bool rightPressed = false;
	bool leftPressed = false;
	bool upPressed = false;
	bool downPressed = false;
	bool firing = false;

  id p_id;
	float dt = 0.0f;
	bool outOfBounds(Projectile &projectile);
	void drawProjectiles();
  void netConnect();

};





