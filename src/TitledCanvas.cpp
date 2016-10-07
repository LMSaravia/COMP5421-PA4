#include "TitledCanvas.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

TitledCanvas::TitledCanvas(int c, int r, string t) : Canvas(c + DECOR_COLUMNS, r + DECOR_ROWS), title(t)
{
	assert(c > 0  && r > 0);
	//cout << "TitledCanvas ctor" << endl;
	decorate();
}

const TitledCanvas & TitledCanvas::operator=(const TitledCanvas & rhs)
{
	if (this == &rhs) return *this;
	Canvas::operator=(rhs);
	title = rhs.title;
	return *this;
}

void TitledCanvas::clear(char ch)
{
	//cout << "clear()" << endl;
	// set start pointer 
	auto rowIt = grid.begin();
	// move to first client area row
	rowIt += V_ORIGIN;
	// set end pointer
	auto rowEnd = grid.end();
	// move to last row(not beyond last)
	rowEnd--; // not symetric, cannot use V_ORIGIN
	for (; rowIt != rowEnd; ++rowIt)
	{
		// set start pointer to second column
		auto colIt = rowIt->begin();
		colIt += H_ORIGIN;
		// set end pointer to last column (not beyond last)
		auto colEnd = rowIt->end();
		colEnd -= H_ORIGIN;
		for (; colIt != colEnd; ++colIt)
		{
			*colIt = ch; // write char
		}
	}
}

void TitledCanvas::putChar(char ch, int c, int r)
{
	if (valid(c, r))
		grid[r + V_ORIGIN][c + H_ORIGIN] = ch;
}

char TitledCanvas::getChar(int c, int r) const
{
	if (valid(c, r))
		return grid[r + V_ORIGIN][c + H_ORIGIN];
	else
		cerr << "Error. Invalid column or row" << endl;
	return '\0';
}

const string & TitledCanvas::getTitle() const
{
	return title;
}

void TitledCanvas::setTitle(const string & t)
{
	title = t;
}

void TitledCanvas::decorate()
{
	//cout << "decorate()" << endl;
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
			else if (i == 2 && (j > 0 && j < getColsN() - 1)) // title box bottom
			{
				grid[i][j] = HLINE;
			}
		}
	}
	writeTitle(title);
}

bool TitledCanvas::valid(int c, int r) const
{
	if (c >= 0 && r >= 0) // not negative
		return c < getColsN() - DECOR_COLUMNS && r < getRowsM() - DECOR_ROWS; // in column range and in row range.
	else
		return false;
}

void TitledCanvas::writeTitle(const string & t)
{
	//cout << "writeTitle(t)" << endl;
	// get title box capacity
	int boxCapacity{ getColsN() - DECOR_COLUMNS }; 
	// substring that fits in box
	string customSizedTitle{ t.substr(0, boxCapacity) };
	// iterate through all chars in substring
	for (size_t i = 0; i < customSizedTitle.length(); i++) 
	{
		// write in canvas
		grid[1][i + H_ORIGIN] = customSizedTitle[i]; 
	}
}
