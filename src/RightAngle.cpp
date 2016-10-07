#include "RightAngle.h"
#include<math.h>
#include<iostream>
using namespace std;

RightAngle::RightAngle(int h, const string & d) : Triangle(h, h, "RightAngle", d)
{
	//cout << "RightAngle ctor" << endl;
}

RightAngle::~RightAngle()
{
	//cout << "RightAngle dtor" << endl;
}

const RightAngle & RightAngle::operator=(const RightAngle & rhs)
{
	Triangle::operator=(rhs);
	return *this;
}

void RightAngle::scale(int n)
{
	if (getHeight() + n > 0)
	{
		setHeight(getHeight() + n);
		setBase(getHeight() + n);
	}
}

double RightAngle::geoPerimeter() const
{
	return (2 + sqrt(2)) * getHeight();  // (2 + sqrt(2)) * h
}

int RightAngle::scrArea() const
{
	return (getHeight() * (getHeight() + 1)) / 2;
}

int RightAngle::scrPerimeter() const
{
	return 3 * (getHeight() - 1);
}

void RightAngle::draw(int c, int r, Canvas & canvas, char ch) const
{
	for (int h = 0; h < getHeight(); h++)
	{
		for (int w = 0; w <= h; w++)
		{
			canvas.putChar(ch, c + w, r + h); // write to right side of c
		}
	}
}