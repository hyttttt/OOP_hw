// Name: ½²´ð¼ü
// Date:  March 22, 2022
// Last Update: March 22, 2022
// Problem statement: This C++ program records at most 10 student data by structures

#include <iostream>
#include <string>
#include <vector>

typedef struct {
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

int main()
{
	std::string command;
	std::string first, last, phone;
	std::vector<StRec> list;

	while (std::cin >> command)
	{
		int count = 0;
		bool error = false;

		if (command == "print")
		{
			//print error message when the list is empty
			if (list.size() == 0)
			{
				std::cout << "Print Error" << std::endl;
			}
			else
			{
				//print the whole list
				for (count = 0; count < list.size(); count++)
				{
					std::cout << list[count].firstName << ' ' << list[count].lastName << ' ' << list[count].phone << std::endl;
				}
			}
		}
		else
		{
			std::cin >> first >> last >> phone;

			//when length exceeds the requirement
			if (first.length() > 25 || last.length() > 30 || phone.length() > 15)
			{
				goto inputError;
			}

			//check if elements in phone are all numbers
			for (count = 0; count < phone.length(); count++)
			{
				if (phone[count] - '0' >= 0 && phone[count] - '0' <= 9)
				{
					continue;
				}
				else
				{
					goto inputError;
				}
			}

			if (command == "insert")
			{
				//print error message when the list is full
				if (list.size() >= 10)
				{
					std::cout << "Insert Error" << std::endl;
					error = true;
				}

				//print error message when there is a duplication in the list
				for (count = 0; count < list.size(); count++)
				{
					if (list[count].firstName == first && list[count].lastName == last && list[count].phone == phone)
					{
						std::cout << "Insert Error" << std::endl;
						error = true;
						break;
					}
				}

				//insert the information into list when no error occours
				if (error == false)
				{
					StRec student;
					strncpy_s(student.firstName, first.c_str(), first.length() + 1);
					strncpy_s(student.lastName, last.c_str(), last.length() + 1);
					strncpy_s(student.phone, phone.c_str(), phone.length() + 1);
					list.push_back(student);
				}
			}
			else if (command == "delete")
			{
				error = true;

				for (count = 0; count < list.size(); count++)
				{
					//erase the element when it is found in the list
					if (list[count].firstName == first && list[count].lastName == last && list[count].phone == phone)
					{
						list.erase(list.begin() + count);
						error = false;
						break;
					}
				}

				//print error message when the element can't be found in the list
				if (error == true)
				{
					std::cout << "Delete Error" << std::endl;
				}
			}
			else if (command == "search")
			{
				error = true;

				for (count = 0; count < list.size(); count++)
				{
					if (list[count].firstName == first && list[count].lastName == last && list[count].phone == phone)
					{
						//print where the element is when it is found the element in the list
						std::cout << count << std::endl;
						error = false;
						break;
					}
				}

				//print error message when the element can't be found in the list
				if (error == true)
				{
					std::cout << "Search Error" << std::endl;
				}
			}
			else //print error message when the input command is not one of the four command
			{
			inputError:
				std::cout << "Input Error" << std::endl;
			}
		}
	}
}