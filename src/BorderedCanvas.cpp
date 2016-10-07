#include "BorderedCanvas.h"
#include <iostream>
#include <cassert>
using namespace std;

BorderedCanvas::BorderedCanvas(int c, int r) : Canvas(c + DECOR_COLUMNS, r + DECOR_ROWS)
{
	assert(c > 0  && r > 0);
	decorate();
}

const BorderedCanvas & BorderedCanvas::operator=(const BorderedCanvas & rhs)
{
	if (this == &rhs) return *this;
	Canvas::operator=(rhs);
	return *this;
}

void BorderedCanvas::clear(char ch)
{
	auto rowIt = grid.begin();
	rowIt += V_ORIGIN; // skip border row
	
	auto rowEnd = grid.end();
	rowEnd -= V_ORIGIN; // set end pointer to border row (not beyond it)
	for (; rowIt != rowEnd ; ++rowIt)
	{
		auto colIt = rowIt->begin();
		colIt += H_ORIGIN; // skip border column
		auto colEnd = rowIt->end();
		colEnd -= H_ORIGIN; // set end pointer to border column (not beyond it)
		for (; colIt != colEnd; ++colIt)
		{
			*colIt = ch; // write char
		}
	}
}

void BorderedCanvas::putChar(char ch, int c, int r)
{
	if (valid(c, r))
		grid[r + V_ORIGIN][c + H_ORIGIN] = ch;
}

char BorderedCanvas::getChar(int c, int r) const
{
	if (valid(c, r))
		return grid[r + V_ORIGIN][c + H_ORIGIN];
	else
		cerr << "Error. Invalid column or row" << endl;
	return '\0';
}

void BorderedCanvas::decorate()
{
	const char CORNER{ '+' };
	const char HLINE{ '-' };
	const char VLINE{ '|' };

	for (int i = 0; i < getRowsM(); i++)
	{
		for (int j = 0; j < getColsN(); j++)
		{
			if (i == 0 && j == 0 || i == 0 && j == getColsN() - 1 || // upper corners or
				i == getRowsM() - 1 && j == 0 || i == getRowsM() - 1 && j == getColsN() - 1) // lower corners
			{
				grid[i][j] = CORNER;
			}
			else if (i == 0 || i == getRowsM() - 1) // sides
			{
				grid[i][j] = HLINE;
			}
			else if (j == 0 || j == getColsN() - 1) // top and bottom
			{
				grid[i][j] = VLINE;
			}
		}
	}
}

bool BorderedCanvas::valid(int c, int r) const
{
	if (c >= 0 && r >= 0) // not negative
		return c < getColsN() - DECOR_COLUMNS && r < getRowsM() - DECOR_ROWS; // in column range and in row range.
	else
		return false;
}