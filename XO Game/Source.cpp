#include <iostream>
using namespace std;


void DrawBoard(char **board)
{
	int height = 4;
	int width = 12;
	int x, y;
	for (int i = 0; i < height; i++)
	{
		x = i - 1;
		y = -1;
		if (i == 0)
		{
			for (int j = 0; j < width; j++)
			{
				cout << "_";
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j <= width; j++)
			{
				if (j % 4 == 0)
				{
					cout << "|";
					y++;
				}
				else
				{
					if (board[x][y] != ' ' && (j == 2 ||
						j == 6 || j == 10))
						cout << board[x][y];
					else
						cout << "_";
				}
			}
			//cout << "|";
			cout << endl;
		}
	}
}

char CheckWinner(char** board)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] 
			&& board[i][1] == board[i][2])
			return board[i][0];
	}

	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] != ' ' && board[0][i] == board[1][i] 
			&& board[1][i] == board[2][i])
			return board[0][i];
	}

	if (board[0][0] != ' ' && board[0][0] == board[1][1] 
		&& board[1][1] == board[2][2])
		return board[0][0];
	
	if (board[0][2] != ' ' && board[0][2] == board[1][1] 
		&& board[1][1] == board[2][0])
		return board[0][2];

	return ' ';
}

void main()
{
	char** board = new char* [3];//char board[3][3];
	for (int i = 0; i < 3; i++)
	{
		board[i] = new char[3];
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}

	DrawBoard(board);

	int choices = 0;
	bool isX = true;
	while (choices < 9)
	{
		int X, Y;
		cout << "Please enter X and Y for your location: ";
		cin >> X >> Y;
		while (board[X][Y] != ' ')
		{
			cout << "Location is not empty! Please try to input again: ";
			cin >> X >> Y;
		}

		if (isX)
		{
			board[X][Y] = 'X';
		}
		else
		{
			board[X][Y] = 'O';
		}

		isX = !isX;
		DrawBoard(board);
		char winner = CheckWinner(board);
		if (winner == 'X')
		{
			cout << "X won!" << endl;
			return;
		}
		else if(winner == 'O')
		{
			cout << "O won!" << endl;
			return;
		}

		choices++;
	}

	cout << "Game Over!" << endl;

	for (int i = 0; i < 3; i++)
	{
		delete[] board[i];
	}

	delete[] board;
}