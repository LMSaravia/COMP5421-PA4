#include "Canvas.h"
#include <iostream>
#include <cassert>
using namespace std;

Canvas::Canvas(int c, int r): colsN(c), rowsM(r), grid(r, vector <char> (c, BLANK))
{
	assert(c > 0 && r > 0);
}

const Canvas & Canvas::operator=(const Canvas & rhs)
{
	if (this == &rhs) return *this;
	colsN = rhs.colsN;
	rowsM = rhs.rowsM;
	grid = rhs.grid;
	return *this;
}

int Canvas::getRowsM() const
{
	return rowsM;
}

int Canvas::getColsN() const
{
	return colsN;
}

const std::vector<std::vector<char>>& Canvas::getGrid() const
{
	return grid;
}

const ostream & operator<<(ostream & os, const Canvas & rhs)
{
	for (auto rowIt = rhs.getGrid().begin(), rowEnd = rhs.getGrid().end(); rowIt != rowEnd; ++rowIt)
	{		
		for (auto colIt = rowIt->begin(), colEnd = rowIt->end(); colIt != colEnd; ++colIt)
		{
			os << *colIt;
		}
		os << endl;
		// another way:
		//const char * p = rowIt->data();
		//for (size_t i = 0; i < rowIt->size(); ++i)
		//{
		//	os << *p;
		//	++p;
		//}
	}
	return os;
}
