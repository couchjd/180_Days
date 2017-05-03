#include "Player.h"
#include <iostream>

Player::Player() : jumpTimer(0.f), _shape(sf::Vector2f(30.f, 30.f)), grounded(true), 
				   gravity(0.f, 125.f), friction(200.f, 0.f) {
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_shape, states);
}

void Player::move(sf::Vector2f moveVector) {
	this->setPosition(this->getPosition() + moveVector);
}

void Player::jump() {
	if(grounded) {
		velocity.y = -125.0f;
		grounded = false;
	}
}

void Player::doMove(MOVE_DIR direction) {
	switch(direction) {
		case LEFT:
			if(velocity.x < -MAX_VELOCITY)
				velocity.x = -MAX_VELOCITY;
			else
				velocity.x += -20.f;
			break;

		case RIGHT:
			if(velocity.x > MAX_VELOCITY)
				velocity.x = MAX_VELOCITY;
			else
				velocity.x += 20.f;
			break;
	}
}

void Player::update(float dt) {
	if(grounded) {
		if(velocity.x > 0)
			velocity.x -= (friction.x * dt);

		if(velocity.x < 0)
			velocity.x += (friction.x * dt);
	}

	if(!grounded)
		velocity.y += (gravity.y * dt);
	
	move(velocity * dt);

	if(getPosition().y >= ground) {
		setPosition(getPosition().x, ground);
		grounded = true;
	}
}