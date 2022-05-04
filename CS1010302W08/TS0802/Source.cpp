// Name: ½²´ð¼ü
// Date:  April 12, 2022
// Last Update: April 12, 2022
// Problem statement: Matrix multiplication

#include <iostream>

int main()
{
	int aRow, aCol, bRow, bCol;
	std::cin >> aRow >> aCol >> bRow >> bCol;

	if (aCol != bRow)
	{
		std::cout << "Matrix multiplication failed.";
		exit(1);
	}

	//create dynamic 2d array A
	double** a = new double* [aRow];
	for (int i = 0; i < aRow; i++)
	{
		a[i] = new double[aCol];
	}

	//create dynamic 2d array B
	double** b = new double* [bRow];
	for (int i = 0; i < bRow; i++)
	{
		b[i] = new double[bCol];
	}

	//create dynamic 2d array C
	double** c = new double* [aRow];
	for (int i = 0; i < aRow; i++)
	{
		c[i] = new double[bCol];
	}

	//input matrix A
	for (int i = 0; i < aRow; i++)
	{
		for (int j = 0; j < aCol; j++)
		{
			std::cin >> a[i][j];
		}
	}

	//input matrix B
	for (int i = 0; i < bRow; i++)
	{
		for (int j = 0; j < bCol; j++)
		{
			std::cin >> b[i][j];
		}
	}

	//A*B
	for (int i = 0; i < aRow; i++)
	{
		for (int j = 0; j < bCol; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < bRow; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	//output
	for (int i = 0; i < aRow; i++)
	{
		for (int j = 0; j < bCol; j++)
		{
			std::cout << c[i][j];
			if (j != (bCol - 1))
			{
				std::cout << " ";
			}
			else
			{
				std::cout << std::endl;
			}
		}
	}

	//delete dynamic 2d array A
	for (int i = 0; i < aRow; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	//delete dynamic 2d array B
	for (int i = 0; i < bRow; i++)
	{
		delete[] b[i];
	}
	delete[] b;

	//delete dynamic 2d array C
	for (int i = 0; i < aRow; i++)
	{
		delete[] c[i];
	}
	delete[] c;
}