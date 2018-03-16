#include "NetShooter.h"
#include <thread>
#include <iostream>

int main() {
	NetShooter* game = new NetShooter();
	game->run();
	return 0;
}
