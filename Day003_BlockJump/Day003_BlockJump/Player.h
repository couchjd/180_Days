#include <SFML/Graphics.hpp>
#define MAX_VELOCITY 200.f

enum MOVE_DIR { LEFT, RIGHT };

class Player : public sf::Drawable {
public:
	Player();
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;

	void move(sf::Vector2f moveVector);
	sf::RectangleShape _shape;

	float ground;
	float jumpTimer;
	bool grounded;
	sf::Vector2f velocity;
	sf::Vector2f gravity;
	sf::Vector2f friction;

	auto getPosition() {
		return _shape.getPosition();
	}

	auto getSize() {
		return _shape.getSize();
	}

	template<typename ... Args>
	void setFillColor(Args&& ... args) {
		_shape.setFillColor(std::forward<Args>(args)...);
	}

	template<typename ... Args>
	void setPosition(Args&& ... args) {
		_shape.setPosition(std::forward<Args>(args)...);
	}

	void jump();
	void Player::doMove(MOVE_DIR direction);
	void update(float dt);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

