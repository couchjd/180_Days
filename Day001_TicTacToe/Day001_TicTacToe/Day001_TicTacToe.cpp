#include <iostream>
#include <windows.h>

#define STD_BOARD_SPACES 9

struct BoardSpace {
	char marker;
	bool occupied;
};

class GameBoard 
{
public:
   GameBoard();
   GameBoard(int width, int height, int win_length);

   ~GameBoard();

   bool isBoardFull();
   void printBoard(bool player);

private:
   void initBoard();

   BoardSpace** m_spaces;
   
   int m_filled_spaces;
   int m_spaces_count;
   int m_width;
   int m_height;
   int m_win_length;

};

GameBoard::GameBoard() :
   m_spaces_count(STD_BOARD_SPACES),
   m_filled_spaces(0)
{
}

GameBoard::GameBoard(int width, int height, int win_length) : 
   m_filled_spaces(0),
   m_spaces_count(width * height),
   m_width(width),
   m_height(height),
   m_win_length(win_length),
   m_spaces(nullptr)
{
   initBoard();
}

GameBoard::~GameBoard()
{
   free(m_spaces);
   m_spaces = nullptr;
}

void GameBoard::initBoard()
{
   m_spaces = (BoardSpace**)malloc(sizeof(BoardSpace) * m_height * m_width);

   for (int x = 0; x < m_height; x++)
   {
      for (int y = 0; y < m_width; y++)
      {
         itoa((m_width * x + y) + 1, &(m_spaces[x][y].marker), 10);
      }
   }
}

bool GameBoard::isBoardFull()
{
   return m_spaces_count == m_filled_spaces;
}

void GameBoard::printBoard(bool player)
{
   system("cls");

   for (int x = 0; x < m_height; x++)
   {
      for (int y = 0; y < m_width; y++)
      {
         std::cout << gameBoard[x][y].marker << (y < m_width ? '|' : '\n');
      }
      
      if (x < m_height)
      {
         for (int z = 0; z < m_width; z++)
         {
            std::cout << "-";
         }
      }
      std::cout << "\n";
   }

   if (gameOver && boardFull)
   {
      system("cls");
      std::cout << "No winner." << std::endl;
      return;
   }

   if (!gameOver)
   {
      std::cout << (!player ? "Player 1 " : "Player 2 ") << "choose a space: ";
   }
   else
   {
      std::cout << (player ? "Player 1 " : "Player 2 ") << "wins!";
   }
}

void initBoard();
void printBoard(bool &player);
void checkBoard();
void getInput(bool &player);

bool gameOver = false;
bool boardFull = false;

BoardSpace gameBoard[3][3];

int main(){
	bool playerTurn = false;

   GameBoard game_board;
   game_board.printBoard(playerTurn);
	//initBoard();
	//printBoard(playerTurn);

	//while(!gameOver) 
 //  {
	//	getInput(playerTurn);
	//	checkBoard();
	//	printBoard(playerTurn);
	//}
	getchar(); getchar();
	return 0;
}

void initBoard() {
	for(int x = 0; x < 3; x++) 
   {
		for(int y = 0; y < 3; y++) 
      {
			itoa((3 * x + y) + 1, &(gameBoard[x][y].marker), 10);
		}
	}
}

void printBoard(bool &player) 
{
	system("cls");
	
   for(int x = 0; x < 3; x++) 
   {
		for(int y = 0; y < 3; y++) 
      {
			std::cout << gameBoard[x][y].marker << (y < 2 ? '|' : '\n');
		}
		std::cout << (x < 2 ? "------\n" : "\n");
	}
	if(gameOver && boardFull) 
   {
		system("cls");
		std::cout << "No winner." << std::endl;
		return;
	}

   if (!gameOver)
   {
      std::cout << (!player ? "Player 1 " : "Player 2 ") << "choose a space: ";
   }
   else
   {
      std::cout << (player ? "Player 1 " : "Player 2 ") << "wins!";
   }
}

void checkBoard() {
	if(gameBoard[0][0].marker == gameBoard[0][1].marker && gameBoard[0][1].marker == gameBoard[0][2].marker) 
   {
		gameOver = true; 
      return;
	}
	if(gameBoard[1][0].marker == gameBoard[1][1].marker && gameBoard[1][1].marker == gameBoard[1][2].marker) 
   {
		gameOver = true; 
      return;
	}
	if(gameBoard[2][0].marker == gameBoard[2][1].marker && gameBoard[2][1].marker == gameBoard[2][2].marker) 
   {
		gameOver = true; 
      return;
	}
	if(gameBoard[0][0].marker == gameBoard[1][0].marker && gameBoard[1][0].marker == gameBoard[2][0].marker) 
   {
		gameOver = true; 
      return;
	}
	if(gameBoard[0][1].marker == gameBoard[1][1].marker && gameBoard[1][1].marker == gameBoard[2][1].marker) 
   {
		gameOver = true;
      return;
	}
	if(gameBoard[0][2].marker == gameBoard[1][2].marker && gameBoard[1][2].marker == gameBoard[2][2].marker) 
   {
		gameOver = true; 
      return;
	}
	if(gameBoard[0][0].marker == gameBoard[1][1].marker && gameBoard[1][1].marker == gameBoard[2][2].marker) 
   {
		gameOver = true; 
      return;
	}
	if(gameBoard[0][2].marker == gameBoard[1][1].marker && gameBoard[1][1].marker == gameBoard[2][0].marker) 
   {
		gameOver = true; 
      return;
	}

	for(int x = 0; x < 3; x++) 
   {
		for(int y = 0; y < 3; y++) 
      {
			if(!gameBoard[x][y].occupied)
				return;
		}
	}
	gameOver = true;
	boardFull = true;
}

void getInput(bool &player) 
{
	int input;
	
   std::cin >> input;
	
   input--;
	
   int x = input / 3;
	int y = input % 3;
	
   if(!gameBoard[x][y].occupied) 
   {
		gameBoard[x][y].occupied = true;
		gameBoard[x][y].marker = (!player ? 'X' : 'O');
		player = !player;
	}
}