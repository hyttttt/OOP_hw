// Name: ½²´ð¼ü
// Date:  March 22, 2022
// Last Update: March 22, 2022
// Problem statement: This C++ program make sure the sudoku board is valid

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Intent: To examine the input array contains exactly 1~9
// Pre: The input array is the numbers of a row, a column, or a square
// Post: Return true for meeting exactly 1~9, otherwise return false
bool check(char* charInput)
{
	int correct[9] = { 1,2,3,4,5,6,7,8,9 };

	std::vector<int> intInput;

	//convert char numbers into int
	for (int i = 0; i < 9; i++)
	{
		intInput.push_back(charInput[i] - '0');
	}

	//arrange the int from small to big
	std::sort(intInput.begin(), intInput.end());

	//examine if the input has exactly each number from 1 to 9
	for (int j = 0; j < 9; j++)
	{
		if (intInput[j] == correct[j])
			continue;
		else
			return false;
	}

	return true;
}

int main()
{
	std::string input;
	std::vector<std::string> board;

	int total = 0;	//"total" to count how many lines in total
	int start = 0;	//"start" to mark the start of each sudoku board
	int row = 0;	//"row" to act as the index of each line in the sudoku board

	//get all the inputs at a time
	while (getline(std::cin, input))
	{
		if (input.empty() == true)
			continue;
		else
		{
			board.push_back(input);
			total++;
		}
	}

	int boardNum = total / 9;	//count how many sudoku board there are

	for (int count = 0; count < boardNum; count++)
	{
		bool valid = true;

		//check if all rows in a sudoku board are valid
		for (row = start; row < start + 9; row++)
		{
			char oneRow[9];

			//get one row
			for (int i = 0, j = 0; i < 17; i += 2, j++)
			{
				oneRow[j] = board[row][i];
			}

			//call "check" to make sure whether the row is valid or not
			if (check(oneRow) == true)
			{
				valid = true;
			}
			else
			{
				valid = false;
				goto output;
			}
		}

		//check if all columns in a sudoku board are valid
		for (int i = 0; i < 17; i += 2)
		{
			char oneColumn[9];

			//get one column
			for (int j = 0, row = start; row < start + 9; row++, j++)
			{
				oneColumn[j] = board[row][i];
			}

			//call "check" to make sure whether the column is valid or not
			if (check(oneColumn) == true)
			{
				valid = true;
			}
			else
			{
				valid = false;
				goto output;
			}
		}

		//check if all squares in a sudoku board are valid
		for (row = start; row < start + 9; row += 3) //start from beginning of sudoku board, move on to next row of squares
		{
			for (int column = 0; column < 13; column += 6)	//start from beginning of sudoku board, move on to next column of squares
			{
				char oneSquare[9];

				//get one square
				for (int r = row, i = 0; r < row + 3; r++)	//start from beginning of a square in the board
				{
					for (int c = column; c < column + 5; c += 2)
					{
						oneSquare[i] = board[r][c];
						i++;
					}
				}

				//call "check" to make sure whether the square is valid or not
				if (check(oneSquare) == true)
				{
					valid = true;
				}
				else
				{
					valid = false;
					goto output;
				}
			}
		}


	output:
		if (valid == true)
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;

		//move on to next sudoku board
		start += 9;
	}
}