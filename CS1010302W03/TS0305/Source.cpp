//Name: ½²´ð¼ü
//Date: Mar 9, 2022
//Last update: Mar 9, 2022
//Problem statement: This C++ program do simple drawing

#include <iostream>
#include <string>
#include <cmath>

void drawS(int w, int x, int y, char** board, int m, int n);
void drawT(int w, int x, int y, std::string triangle, char** board, int m, int n);
void drawL(int x1, int y1, int x2, int y2, char** board, int m, int n);

int main()
{
	int m, n;
	std::string command, triangle;
	int w, x, y, x1, y1, x2, y2;

	//create the dynamic array
	std::cin >> n >> m;
	char** board;
	board = new char* [m];
	for (int i = 0; i < m; i++)
	{
		board[i] = new char[n];
	}
	//fill the board with *
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = '*';
		}
	}

	//recieve the command
	while (std::cin >> command)
	{
		if (command == "S")
		{
			std::cin >> w >> x >> y;
			drawS(w, x, y, board, m, n);
			std::cout << std::endl;
		}
		else if (command == "T")
		{
			std::cin >> w >> x >> y >> triangle;
			drawT(w, x, y, triangle, board, m, n);
			std::cout << std::endl;
		}
		else if (command == "L")
		{
			std::cin >> x1 >> y1 >> x2 >> y2;
			drawL(x1, y1, x2, y2, board, m, n);
			std::cout << std::endl;
		}
		else if (command == "EXIT")
		{
			break;
		}


	}

	//release the dynamic array
	for (int i = 0; i < m; i++)
	{
		delete[]board[i];
	}
	delete[]board;
}

void drawS(int w, int x, int y, char** board, int m, int n)
{
	if ((x + w) <= n && (y + w) <= m)
	{
		//draw the square
		for (int i = y; i < (w + y); i++)
		{
			for (int j = x; j < (w + x); j++)
			{
				board[i][j] = 'X';
			}
		}
		//output the board
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << board[i][j];
			}
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "Out of range." << std::endl;
	}
}

void drawT(int w, int x, int y, std::string triangle, char** board, int m, int n)
{
	int i, j;
	w--; //adjust

	//draw the triangle
	if (triangle == "RU")
	{
		if ((y - w) >= 0 && (x + w) < n)
		{
			int wy = w, wx = w;
			for (i = y; i >= (y - wy); i--)
			{
				for (j = (x + wx); j >= x; j--)
				{
					board[i][j] = 'X';
				}
				wx--;
			}
		}
		else
		{
			std::cout << "Out of range." << std::endl;
			goto endT;
		}
	}
	else if (triangle == "RD")
	{
		if ((y + w) < m && (x + w) < n)
		{
			int wy = w, wx = w;
			for (i = y; i <= (y + wy); i++)
			{
				for (j = (x + wx); j >= x; j--)
				{
					board[i][j] = 'X';
				}
				wx--;
			}
		}
		else
		{
			std::cout << "Out of range." << std::endl;
			goto endT;
		}
	}
	else if (triangle == "LU")
	{
		if ((y - w) >= 0 && (x - w) < n)
		{
			int wy = w, wx = w;
			for (i = y; i >= (y - wy); i--)
			{
				for (j = (x - wx); j <= x; j++)
				{
					board[i][j] = 'X';
				}
				wx--;
			}
		}
		else
		{
			std::cout << "Out of range." << std::endl;
			goto endT;
		}
	}
	else if (triangle == "LD")
	{
		if ((x - w) >= 0 && (y + w) < m)
		{
			int wy = w, wx = w;
			for (i = y; i <= (y + wy); i++)
			{
				for (j = (x - wx); j <= x; j++)
				{
					board[i][j] = 'X';
				}
				wx--;
			}
		}
		else
		{
			std::cout << "Out of range." << std::endl;
			goto endT;
		}
	}

	//output the board
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}

endT:
	int none = 0;
}

void drawL(int x1, int y1, int x2, int y2, char** board, int m, int n)
{
	int i, j;

	//make sure point1 is always the left point
	if (x1 > x2)
	{
		int temp = x1;
		x1 = x2;
		x2 = temp;

		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	//check whether it is drawable
	if (y1 == y2) //the line is parallel with x-axis
	{
		if (x2 - x1 + 1 > n)
		{
			std::cout << "Out of range." << std::endl;
			goto endL;
		}
		else
		{
			for (i = x1; i <= x2; i++)
			{
				board[y1][i] = 'X';
			}
		}
	}
	else if (x1 == x2) //the line is parallel with y-axis
	{
		if (abs(y1 - y2) + 1 > m)
		{
			std::cout << "Out of range." << std::endl;
			goto endL;
		}
		else
		{
			if (y1 < y2) //point1 is upper
			{
				for (j = y1; j <= y2; j++)
				{
					board[j][x1] = 'X';
				}
			}
			else //point1 is lower
			{
				for (j = y1; j >= y2; j--)
				{
					board[j][x1] = 'X';
				}
			}
		}

	}
	else if (abs(x1 - x2) == abs(y1 - y2)) //the line is diagonal
	{
		if ((abs(y1 - y2) + 1 > m) || (abs(x1 - x2) + 1 > n))
		{
			std::cout << "Out of range." << std::endl;
			goto endL;
		}
		else
		{
			if (y1 < y2) //point1 is upper
			{
				for (j = 0; j <= abs(y1 - y2); j++)
				{
					board[y1 + j][x1 + j] = 'X';
				}
			}
			else //point1 is lower
			{
				for (j = 0; j <= abs(y1 - y2); j++)
				{
					board[y1 - j][x1 + j] = 'X';
				}
			}
		}
	}
	else if (x1 == x2 && y1 == y2) //two point overlaps
	{
		board[y1][x1] = 'X';
	}
	else //the line is not drawable
	{
		std::cout << "Out of range." << std::endl;
		goto endL;
	}

	//output the board
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}

endL:
	int none = 0;
}