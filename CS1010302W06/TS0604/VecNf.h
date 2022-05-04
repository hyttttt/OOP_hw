#pragma once
#ifndef VEC_NF_H
#define VEC_NF_H
#include <iostream>
#include <vector>

class VecNf
{
public:
	std::vector<float> vec;
	int len;

	VecNf();
	VecNf(float* dest, int cnt);
	VecNf(const VecNf& rhs);

	int Size();

	VecNf& operator=(const VecNf& vector);
	VecNf operator+(VecNf vector);
	VecNf operator-(VecNf vector);
	float operator*(VecNf vector);
	friend VecNf operator*(float f, VecNf vector);
	float& operator[](int i);
};

#endif // !VEC_NF_H