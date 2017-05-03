#include <iostream>
#include <windows.h>

struct boardSpace {
	char marker;
	bool occupied;
};

void initBoard();
void printBoard(bool &player);
void checkBoard();
void getInput(bool &player);

bool gameOver = false;
bool boardFull = false;

boardSpace gameBoard[3][3];

int main(){

	bool playerTurn = false;
	
	initBoard();
	printBoard(playerTurn);

	while(!gameOver) {
		getInput(playerTurn);
		checkBoard();
		printBoard(playerTurn);
	}
	getchar(); getchar();
	return 0;
}

void initBoard() {
	char* temp;
	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			itoa((3 * x + y) + 1, &(gameBoard[x][y].marker), 10);
		}
	}
}

void printBoard(bool &player) {
	system("cls");
	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			std::cout << gameBoard[x][y].marker << (y < 2 ? '|' : '\n');
		}
		std::cout << (x < 2 ? "------\n" : "\n");
	}
	if(gameOver && boardFull) {
		system("cls");
		std::cout << "No winner." << std::endl;
		return;
	}

	if(!gameOver)
		std::cout << (!player ? "Player 1 " : "Player 2 ") << "choose a space: ";
	else
		std::cout << (player ? "Player 1 " : "Player 2 ") << "wins!";
		
}

void checkBoard() {
	if(gameBoard[0][0].marker == gameBoard[0][1].marker && gameBoard[0][1].marker == gameBoard[0][2].marker) {
		gameOver = true; return;
	}
	if(gameBoard[1][0].marker == gameBoard[1][1].marker && gameBoard[1][1].marker == gameBoard[1][2].marker) {
		gameOver = true; return;
	}
	if(gameBoard[2][0].marker == gameBoard[2][1].marker && gameBoard[2][1].marker == gameBoard[2][2].marker) {
		gameOver = true; return;
	}
	if(gameBoard[0][0].marker == gameBoard[1][0].marker && gameBoard[1][0].marker == gameBoard[2][0].marker) {
		gameOver = true; return;
	}
	if(gameBoard[0][1].marker == gameBoard[1][1].marker && gameBoard[1][1].marker == gameBoard[2][1].marker) {
		gameOver = true; return;
	}
	if(gameBoard[0][2].marker == gameBoard[1][2].marker && gameBoard[1][2].marker == gameBoard[2][2].marker) {
		gameOver = true; return;
	}
	if(gameBoard[0][0].marker == gameBoard[1][1].marker && gameBoard[1][1].marker == gameBoard[2][2].marker) {
		gameOver = true; return;
	}
	if(gameBoard[0][2].marker == gameBoard[1][1].marker && gameBoard[1][1].marker == gameBoard[2][0].marker) {
		gameOver = true; return;
	}

	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			if(!gameBoard[x][y].occupied)
				return;
		}
	}
	gameOver = true;
	boardFull = true;
}

void getInput(bool &player) {
	int input;
	std::cin >> input;
	input--;
	int x = input / 3;
	int y = input % 3;
	if(!gameBoard[x][y].occupied) {
		gameBoard[x][y].occupied = true;
		gameBoard[x][y].marker = (!player ? 'X' : 'O');
		player = !player;
	}
}