#include "PlainCanvas.h"
#include <iostream>
using namespace std;

PlainCanvas::PlainCanvas(int n, int m) : Canvas(n,m)
{
}

const PlainCanvas & PlainCanvas::operator=(const PlainCanvas & rhs)
{
	if (this == &rhs) return *this;
	Canvas::operator=(rhs);
	return *this;
}

void PlainCanvas::clear(char ch)
{
	for (auto rowIt = grid.begin(), rowEnd = grid.end(); rowIt != rowEnd; ++rowIt)
	{
		for (auto colIt = rowIt->begin(), colEnd = rowIt->end(); colIt != colEnd; ++colIt)
		{
			*colIt = ch;
		}
	}
}

void PlainCanvas::putChar(char ch, int c, int r)
{
	if (valid(c, r))
		grid[r][c] = ch;
}

char PlainCanvas::getChar(int c, int r) const
{
	if (valid(c, r))
		return grid[r][c];
	else
	{
		cerr << "Error. Invalid column or row" << endl;
		return '\0';
	}

}

void PlainCanvas::decorate()
{// no decoration for plain canvas
}

bool PlainCanvas::valid(int c, int r) const
{
	if (c >= 0 && r >= 0) // not negative and starts from [0,0]
		return c < getColsN() && r < getRowsM(); // in column range and in row range.
	else
		return false;
}

const ostream & operator<<(ostream & os, const PlainCanvas & rhs)
{
	const Canvas * cPtr = &rhs;
	os << *cPtr;
	return os;
}
