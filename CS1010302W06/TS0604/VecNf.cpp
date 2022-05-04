#include "VecNf.h"
#include <iostream>

// Intent: Default constructor of calss VecNf
// Pre: No input needed
// Post: Construct a one-dimensional zero vector
VecNf::VecNf()
{
	this->vec.push_back(0.0);
	this->len = 1;
}

// Intent: Constructor of calss VecNf
// Pre: Dest contains all the float we want to put in the vector, and cnt is the length of the vector
// Post: Construct a cnt dimensional vector using the first cnt numbers in dest
VecNf::VecNf(float* dest, int cnt)
{
	this->len = cnt;

	for (int i = 0; i < cnt; i++)
	{
		this->vec.push_back(*(dest + i));
	}
}

// Intent: Copy constructor of calss VecNf
// Pre: Rhs is the object that would be copied
// Post: Construct a new vector from a VecNf
VecNf::VecNf(const VecNf& rhs)
{
	this->len = rhs.len;

	for (int i = 0; i < this->len; i++)
	{
		this->vec.push_back(rhs.vec[i]);
	}
}

// Intent: Access the length of the vector
// Pre: No input needed
// Post: Return the length of the vector
int VecNf::Size()
{
	return this->len;
}

// Intent: Overload assign operator(=) for class VecNf
// Pre: Input a VecNf object to be copied
// Post: Assign a VecNf object to another
VecNf& VecNf::operator=(const VecNf& vector)
{
	std::cout << "ASSIGNMENT!!!" << std::endl;
	this->vec.clear(); //clear the default 0 in the vector
	this->len = vector.len;
	for (int i = 0; i < this->len; i++)
	{
		this->vec.push_back(vector.vec[i]);
	}

	return *this;
}

// Intent: Overload adding operator(+) for class VecNf
// Pre: Input a VecNf object to be added
// Post: Add a VecNf object to another
VecNf VecNf::operator+(VecNf vector)
{
	if (this->len == vector.len)
	{
		VecNf add;
		add.len = vector.len;
		add.vec.clear(); //clear the default 0 in the vector

		for (int i = 0; i < vector.len; i++)
		{
			add.vec.push_back(this->vec[i] + vector.vec[i]);
		}

		return add;
	}
	else
	{
		std::cout << "dimensions inconsistent" << std::endl;

		VecNf err;
		return err;
	}
}

// Intent: Overload subtracting operator(-) for class VecNf
// Pre: Input a VecNf object to be subtracted from another
// Post: Subtract a VecNf object from another
VecNf VecNf::operator-(VecNf vector)
{
	if (this->len == vector.len)
	{
		VecNf sub;
		sub.len = vector.len;
		sub.vec.clear(); //clear the default 0 in the vector

		for (int i = 0; i < vector.len; i++)
		{
			sub.vec.push_back(this->vec[i] - vector.vec[i]);
		}

		return sub;
	}
	else
	{
		std::cout << "dimensions inconsistent" << std::endl;
		VecNf err;
		return err;
	}
}

// Intent: Overload multiplying operator(*) for class VecNf, calculate the inner product
// Pre: Input a VecNf object to do inner product
// Post: Return the inner product
float VecNf::operator*(VecNf vector)
{
	float mul = 0.0;

	if (this->len == vector.len)
	{
		for (int i = 0; i < vector.len; i++)
		{
			mul += this->vec[i] * vector.vec[i];
		}

		return mul;
	}
	else
	{
		std::cout << "dimensions inconsistent" << std::endl;

		return mul;
	}
}

// Intent: Overload adding operator(+) for class VecNf, multiply a vector by a scalar
// Pre: Input a VecNf object and a scalar to multiply
// Post: Multiply a vector by a scalar
VecNf operator*(float f, VecNf vector)
{
	VecNf mul;
	mul.len = vector.len;
	mul.vec.clear(); //clear the default 0 in the vector

	for (int i = 0; i < vector.len; i++)
	{
		mul.vec.push_back(f * vector.vec[i]);
	}

	return mul;
}

// Intent: Overload subscription operator([]) for class VecNf, get the value in the class member vec
// Pre: Input the index according to which we can find the value in the vector
// Post: Retrun the value in the vector
float& VecNf::operator[](int i)
{
	return this->vec[i];
}