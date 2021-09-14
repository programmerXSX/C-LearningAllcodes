#pragma once
#include <iostream>
#define PI 3.1415926

class Circle
{
public:
	double c_X, c_Y, R;
	double	S = 2 * PI * R;
	void printS();
};