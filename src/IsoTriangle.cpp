#include "IsoTriangle.h"
#include<math.h>
#include<iostream>
using namespace std;

IsoTriangle::IsoTriangle(int h, const string & d) : Triangle(h, 2 * h - 1 ,"IsoTriangle", d)
{
	//cout << "IsoTriangle ctor" << endl;
}

IsoTriangle::~IsoTriangle()
{
	//cout << "IsoTriangle dtor" << endl;
}

const IsoTriangle & IsoTriangle::operator=(const IsoTriangle & rhs)
{
	Triangle::operator=(rhs);
	return *this;
}

void IsoTriangle::scale(int n)
{
	if (getHeight() + n > 0) 
	{
		setHeight(getHeight() + n);
		setBase(2 * getHeight() - 1);
	}
}

double IsoTriangle::geoPerimeter() const
{
	double partial{ 0.25 * getBase() * getBase() }; // 0.25 * b^2
	partial += getHeight() * getHeight();  // 0.25 * b^2 + h^2
	return getBase() + 2 * sqrt(partial);  // b + 2* sqrt(0.25 * b^2 + h^2)
}

int IsoTriangle::scrArea() const
{
	return getHeight() * getHeight();
}

int IsoTriangle::scrPerimeter() const
{
	return 4 * (getHeight() - 1);
}

/* draw textual image of the shape on a drawing surface */
void IsoTriangle::draw(int c, int r, Canvas & canvas, char ch) const
{
	c += getBase() / 2; // fixes position, aligns leftmost char to c, instead of c as center.

	for (int h = 0; h < getHeight(); h++)
	{
			for (int w = 0; w <= h; w++)
			{
				canvas.putChar(ch, c + w, r + h); // write to right side
				canvas.putChar(ch, c - w, r + h); // write to left side
			}
	}
}
