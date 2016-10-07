#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Shape.h"
#include <iostream>
class Rhombus : public Shape
{
public:
	Rhombus() = delete;
	Rhombus(int diag, const std::string & desc = "");
	Rhombus(const Rhombus &) = default;
	~Rhombus();
	const Rhombus & operator=(const Rhombus & rhs);
	int getDiagonal() const;
	void setDiagonal(int h);
	std::string toString() const override;
	void scale(int n) override;
	double geoArea() const override;
	double geoPerimeter() const override;
	int scrArea() const override;
	int scrPerimeter() const override;
	int bBoxHeight() const override;
	int bBoxWidth() const override;
	/* Draws textual image of the shape on a drawing surface*/
	void draw(int c, int r, Canvas & canvas, char ch = '*') const override;
private:
	int diagonal;
};
std::ostream & operator<<(std::ostream & ostr, const Rhombus & rhs);
#endif // !RHOMBUS_H