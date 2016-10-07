#ifndef PLAINCANVAS_H
#define PLAINCANVAS_H
#include "Canvas.h"
class PlainCanvas : public Canvas
{
public:
	PlainCanvas() = delete;
	PlainCanvas(int n, int m);
	const PlainCanvas & operator=(const PlainCanvas & rhs);
	virtual ~PlainCanvas() = default;
	virtual void clear(char ch) override;
	virtual void putChar(char ch, int c, int r) override;
	virtual char getChar(int c, int r) const override;
	virtual void decorate() override;
	virtual bool valid(int c, int r) const override;
};
const std::ostream & operator<<(std::ostream & os, const PlainCanvas & rhs);
#endif // !PLAINCANVAS_H
