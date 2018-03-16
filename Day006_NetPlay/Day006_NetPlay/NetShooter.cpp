#include "NetShooter.h"

NetShooter::NetShooter() :
	window(sf::VideoMode(800, 600), "Shooter") {
}

sf::Packet& operator <<(sf::Packet& packet, const sf::VertexArray& vertices) {
  return packet <<
    vertices[0].position.x << vertices[0].position.y << vertices[0].color.r << vertices[0].color.g << vertices[0].color.b <<
    vertices[1].position.x << vertices[1].position.y << vertices[1].color.r << vertices[1].color.g << vertices[1].color.b <<
    vertices[2].position.x << vertices[2].position.y << vertices[2].color.r << vertices[2].color.g << vertices[2].color.b;
}
sf::Packet& operator >> (sf::Packet& packet, sf::VertexArray& vertices) {
  return packet >>
    vertices[0].position.x >> vertices[0].position.y >> vertices[0].color.r >> vertices[0].color.g >> vertices[0].color.b >>
    vertices[1].position.x >> vertices[1].position.y >> vertices[1].color.r >> vertices[1].color.g >> vertices[1].color.b >>
    vertices[2].position.x >> vertices[2].position.y >> vertices[2].color.r >> vertices[2].color.g >> vertices[2].color.b;
}
sf::Packet& operator << (sf::Packet& packet, const id& ID) {
  return packet << ID;
}
sf::Packet& operator >> (sf::Packet& packet, id& ID) {
  return packet >> ID;
}

sf::Packet& operator >> (sf::Packet& packet, Projectile& proj) {
  return packet >> proj;
}

void NetShooter::run() {
  //sf::Thread netThread(&NetShooter::netConnect, this);
  sf::VertexArray player(sf::Triangles, 3);
  sf::VertexArray enemy(sf::Triangles, 3);

  socket.connect(sf::IpAddress::getLocalAddress(), 5000);

  sf::Packet packet;
  id packetID;
  sf::VertexArray playerPkt;

  socket.receive(packet);
  packet >> packetID >> player;
  p_id = packetID;
  packet.clear();
  socket.receive(packet);
  packet >> packetID >> enemy;

  sf::Clock clock;
	std::vector<float> z = { 0, 0, 0 };

	while(window.isOpen()) {

    sf::Vector2f centroid = getCentroid(player);

		sf::Event event;
		while(window.pollEvent(event)) {

      if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();

			if(event.type == sf::Event::MouseButtonPressed) {
				if(event.mouseButton.button == sf::Mouse::Left)
					firing = true;
			}

			if(event.type == sf::Event::MouseButtonReleased) {
				if(event.mouseButton.button == sf::Mouse::Left)
					firing = false;
			}

			if(event.type == sf::Event::KeyReleased) {
				if(event.key.code == sf::Keyboard::W)
					upPressed = false;
				if(event.key.code == sf::Keyboard::S)
					downPressed = false;
				if(event.key.code == sf::Keyboard::A)
					leftPressed = false;
				if(event.key.code == sf::Keyboard::D)
					rightPressed = false;
				if(event.key.code == sf::Keyboard::Space)
					firing = false;
			}

			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Space)
					firing = true;
				if(event.key.code == sf::Keyboard::W)
					upPressed = true;
				if(event.key.code == sf::Keyboard::S)
					downPressed = true;
				if(event.key.code == sf::Keyboard::A)
					leftPressed = true;
				if(event.key.code == sf::Keyboard::D)
					rightPressed = true;
			}
		}

		if(clock.getElapsedTime().asSeconds() > 0.05f) {

      clock.restart();

			if(rightPressed) {
				for(int x = 0; x < 3; x++) {
					player[x].position = sf::Vector2f(player[x].position.x - centroid.x, player[x].position.y - centroid.y);
					float xPos = (player[x].position.x * cos(THETA)) - (player[x].position.y * sin(THETA));
					float yPos = (player[x].position.x * sin(THETA)) + (player[x].position.y * cos(THETA));
					player[x].position = sf::Vector2f(xPos + centroid.x, yPos + centroid.y);
				}
			}

			if(leftPressed) {
				for(int x = 0; x < 3; x++) {
					player[x].position = sf::Vector2f(player[x].position.x - centroid.x, player[x].position.y - centroid.y);
					float xPos = (player[x].position.x * cos(-THETA)) - (player[x].position.y * sin(-THETA));
					float yPos = (player[x].position.x * sin(-THETA)) + (player[x].position.y * cos(-THETA));
					player[x].position = sf::Vector2f(xPos + centroid.x, yPos + centroid.y);
				}
			}

			if(upPressed) {
				sf::Vector2f faceDir = facing(player);
				for(int x = 0; x < 3; x++) {
					player[x].position = sf::Vector2f(player[x].position.x + 10 * faceDir.x, player[x].position.y + 10 * faceDir.y);
				}
			}

			if(downPressed) {
				sf::Vector2f faceDir = facing(player);
				for(int x = 0; x < 3; x++) {
					player[x].position = sf::Vector2f(player[x].position.x - 10 * faceDir.x, player[x].position.y - 10 * faceDir.y);
				}
			}

			if(firing) {
				Projectile* newProj = new Projectile(player[1].position, facing(player));
        packet << id::PROJECTILE << newProj;
        socket.send(packet);
        packet.clear();
        //projectiles.push_back(newProj);
			}
		}

    packet << p_id << player;
    socket.send(packet);
    packet.clear();

    socket.receive(packet);
    
    packet >> packetID;

    switch(packetID) {
      case id::PROJECTILE:
        projectiles.clear();
        sf::Uint32 size;
        packet >> size;
        for(sf::Uint32 i = 0; i < size; ++i) {
          Projectile* proj;
          packet >> *proj;
          projectiles.push_back(proj);
        }
        break;
      case id::PLAYER1:
        packet >> player;
        break;
      case id::PLAYER2:
        packet >> enemy;
        break;
    }
    packet.clear();

		window.clear();

		drawProjectiles();

		window.draw(player);
    window.draw(enemy);
		window.display();

	}
}

sf::Vector2f NetShooter::getCentroid(const sf::VertexArray& polygon) {
	return sf::Vector2f((polygon[0].position.x + polygon[1].position.x + polygon[2].position.x) / 3,
		(polygon[0].position.y + polygon[1].position.y + polygon[2].position.y) / 3);
}

sf::Vector2f NetShooter::normalize(const sf::Vector2f& vector) {
	float length = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
	return sf::Vector2f(vector.x / length, vector.y / length);
}

sf::Vector2f NetShooter::facing(const sf::VertexArray& polygon) {
	sf::Vector2f v1(polygon[0].position.x - polygon[1].position.x, polygon[0].position.y - polygon[1].position.y);
	sf::Vector2f v2(polygon[2].position.x - polygon[1].position.x, polygon[2].position.y - polygon[1].position.y);

	return normalize(sf::Vector2f(-(v1.x + v2.x), -(v1.y + v2.y)));
}

bool NetShooter::outOfBounds(Projectile &projectile) {
	float x = projectile.projectile[0].position.x;
	float y = projectile.projectile[0].position.y;
	float xBound = window.getSize().x;
	float yBound = window.getSize().y;

	return (x > xBound || x < 0 || y > yBound || y < 0);
}

void NetShooter::drawProjectiles() {
	for(int x = 0; x < projectiles.size(); x++) {
		window.draw(*projectiles[x]);
		projectiles[x]->update();
		if(outOfBounds(*projectiles[x])) {
			delete projectiles[x];
			projectiles.erase(projectiles.begin() + x);
		}
	}
}

//void NetShooter::netConnect() {
//  sf::Socket::Status status = socket.connect("127.0.0.1", 53000);
//  if(status != sf::Socket::Done)
//    std::cout << "CONNECTION FAILED" << std::endl;
//}
