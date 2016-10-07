#ifndef BORDEREDCANVAS_H
#define BORDEREDCANVAS_H
#include "Canvas.h"
class BorderedCanvas : public Canvas
{
public:
	BorderedCanvas() = delete;
	BorderedCanvas(int c, int r);
	const BorderedCanvas & operator=(const BorderedCanvas & rhs);
	virtual ~BorderedCanvas() = default;
	virtual void clear(char ch) override;
	virtual void putChar(char ch, int c, int r) override;
	virtual char getChar(int c, int r) const override;
	virtual void decorate() override;
	virtual bool valid(int c, int r) const override;
private:
	static const int DECOR_COLUMNS{ 2 }; // number of not client area columns
	static const int DECOR_ROWS{ 2 }; // number of not client area rows
	static const int H_ORIGIN{ 1 }; // horizontal origin = side border width
	static const int V_ORIGIN{ 1 }; // vertical origin = upper border height
};
#endif // !BORDEREDCANVAS_H
