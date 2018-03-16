#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Projectile.h"

enum id { PLAYER1, PLAYER2, PROJECTILE };

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

void initPlayer(id ID, sf::VertexArray& verts);

int main() {
  std::vector<Projectile*> projectiles;
  sf::VertexArray player1;
  sf::VertexArray player2;

  initPlayer(id::PLAYER1, player1);
  initPlayer(id::PLAYER2, player2);

  sf::TcpSocket player1Sock;
  sf::TcpSocket player2Sock;

  sf::Packet packet;

  sf::TcpListener listener;
  listener.listen(5000);

  listener.accept(player1Sock);
  listener.accept(player2Sock);

  packet << id::PLAYER1 << player1;
  player1Sock.send(packet);
  packet.clear();
  packet << id::PLAYER2 << player2;
  player1Sock.send(packet);
  packet.clear();

  packet << id::PLAYER2 << player2;
  player2Sock.send(packet);
  packet.clear();
  packet << id::PLAYER1 << player1;
  player2Sock.send(packet);

  id id;
  while(true) {
    player1Sock.receive(packet);
    packet >> id >> player1;
    packet.clear();
    player2Sock.receive(packet);
    packet >> id >> player2;
    packet.clear();

    packet << id::PLAYER1 << player1;
    player1Sock.send(packet);
    packet.clear();
    packet << id::PLAYER2 << player2;
    player1Sock.send(packet);
    packet.clear();

    packet << id::PLAYER2 << player2;
    player2Sock.send(packet);
    packet.clear();
    packet << id::PLAYER1 << player1;
    player2Sock.send(packet);
  }
  return 0;
}

void initPlayer(id ID, sf::VertexArray& verts) {
  verts = sf::VertexArray(sf::Triangles, 3);
  switch(ID) {
    case id::PLAYER1:
      verts[0].position = sf::Vector2f(100, 100);
      verts[1].position = sf::Vector2f(150, 125);
      verts[2].position = sf::Vector2f(100, 150);

      verts[0].color = sf::Color::White;
      verts[1].color = sf::Color::Red;
      verts[2].color = sf::Color::White;
      break;
    case id::PLAYER2:
      verts[0].position = sf::Vector2f(700, 100);
      verts[1].position = sf::Vector2f(650, 125);
      verts[2].position = sf::Vector2f(700, 150);

      verts[0].color = sf::Color::Blue;
      verts[1].color = sf::Color::Red;
      verts[2].color = sf::Color::Blue;
      break;
  }
}