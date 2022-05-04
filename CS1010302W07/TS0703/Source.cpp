//Name: ½²´ð¼ü
//Date: Apr 5, 2022
//Last update: Apr 5, 2022
//Problem statement: This C++ program is a seven segment displayer

#include <iostream>
#include <string>

int main()
{
	std::string input;

	while (std::getline(std::cin, input))
	{
		//line 1
		for (int i = 0; i < input.size(); i++)
		{
			int digit = input[i] - '0';

			if (digit >= 0 && digit <= 9)
			{
				if (digit == 1 || digit == 4)
					std::cout << "   ";
				else
					std::cout << " _ ";
			}
		}
		std::cout << std::endl;

		//line 2
		for (int i = 0; i < input.size(); i++)
		{
			int digit = input[i] - '0';

			if (digit >= 0 && digit <= 9)
			{
				if (digit == 1 || digit == 7)
					std::cout << "  |";

				else if (digit == 2 || digit == 3)
					std::cout << " _|";
				
				else if (digit == 4 || digit == 8 || digit == 9)
					std::cout << "|_|";
				
				else if (digit == 5 || digit == 6)
					std::cout << "|_ ";
		
				else
					std::cout << "| |";
			}
		}
		std::cout << std::endl;

		//line 3
		for (int i = 0; i < input.size(); i++)
		{
			int digit = input[i] - '0';

			if (digit >= 0 && digit <= 9)
			{
				if (digit == 1 || digit == 4 || digit == 7)
					std::cout << "  |";
			
				else if (digit == 3 || digit == 5 || digit == 9)
					std::cout << " _|";
				
				else if (digit == 6 || digit == 8 || digit == 0)
					std::cout << "|_|";
				
				else
					std::cout << "|_ ";
			}
		}
		std::cout << std::endl;
	}
}