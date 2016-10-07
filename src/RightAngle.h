#ifndef RIGHTANGLE_H
#define RIGHTANGLE_H
#include "Triangle.h"

class RightAngle : public Triangle
{
public:

	RightAngle() = delete;
	RightAngle(int h, const std::string & d = "");
	RightAngle(const RightAngle &) = default;
	virtual ~RightAngle();
	const RightAngle & operator=(const RightAngle & rhs);
	void scale(int n) override;
	double geoPerimeter() const override;
	int scrArea() const override;
	int scrPerimeter() const override;
	/* Draws textual image of the shape on a drawing surface*/
	void draw(int c, int r, Canvas & canvas, char ch = '*') const override;
};
#endif // !RIGHTANGLE_H