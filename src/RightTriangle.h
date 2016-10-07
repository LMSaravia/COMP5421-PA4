#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H
#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
	RightTriangle();
	virtual ~RightTriangle();

	std::string toString() const;
	virtual void scale() = 0;
	virtual void g_area() = 0;
	virtual void g_perimeter() = 0;
	virtual void s_area() = 0;
	virtual void s_perimeter() = 0;
	virtual int bBoxWidth() = 0;
	virtual int bBoxHeight() = 0;
	// 8- draw textual image of the shape on a drawing surface
	virtual void draw() const = 0;

};
#endif // !RIGHTTRIANGLE_H