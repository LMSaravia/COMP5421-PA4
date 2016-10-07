#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
class Canvas
{
public:
	Canvas() = delete;
	Canvas(int c, int r); // default char is blank space
	explicit Canvas(const Canvas &) = default;
	virtual ~Canvas() = default;
	virtual const Canvas & operator=(const Canvas & rhs);
	int getRowsM() const;
	int getColsN() const;
	const std::vector< std::vector< char > > & getGrid() const;
	virtual void clear(char ch = ' ') = 0;
	virtual void putChar(char ch, int c, int r) = 0;
	virtual char getChar(int c, int r) const = 0;
	virtual void decorate() = 0;
	virtual bool valid(int c, int r) const = 0;
protected:
	std::vector< std::vector< char > > grid; // maybe should be made pvt and add pub method setChar(int c, int r)
private:
	int colsN; // number of columns
	int rowsM; // number of rows
	static const char BLANK{ ' ' };
};
const std::ostream & operator<<(std::ostream & os, const Canvas & rhs);
#endif // !CANVAS_H
