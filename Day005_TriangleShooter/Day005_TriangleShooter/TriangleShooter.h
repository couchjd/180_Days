#pragma once
#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <vector>
#include "Projectile.h"
#include "Allocator.h"

#define THETA 10 * M_PI / 180

class TriangleShooter {
public:
	TriangleShooter();
	sf::RenderWindow window;
	sf::Vector2f getCentroid(const sf::VertexArray& polygon);
	sf::Vector2f normalize(const sf::Vector2f& vector);
	sf::Vector2f facing(const sf::VertexArray& polygon);
	std::vector<Projectile*> projectiles;
	Projectile* projectile = new Projectile();
	Projectile* newProj;
	Allocator alloc;
	void run();

private:
	bool rightPressed = false;
	bool leftPressed = false;
	bool upPressed = false;
	bool downPressed = false;
	bool firing = false;

	float dt = 0.0f;
	bool outOfBounds(Projectile &projectile);
	void drawProjectiles();
	

};





