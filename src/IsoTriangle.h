#ifndef ISOTRIANGLE_H
#define ISOTRIANGLE_H
#include "Triangle.h"

class IsoTriangle : public Triangle
{
public:
	IsoTriangle() = delete;
	IsoTriangle(int h, const std::string & d = "");
	IsoTriangle(const IsoTriangle &) = default;
	virtual ~IsoTriangle();
	const IsoTriangle & operator=(const IsoTriangle & rhs);
	void scale(int n) override;
	double geoPerimeter() const override;
	int scrArea() const override;
	int scrPerimeter() const override;
	/* Draws textual image of the shape on a drawing surface*/
	void draw(int c, int r, Canvas & canvas, char ch = '*') const override;
};
#endif // !ISOTRIANGLE_H