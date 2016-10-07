#ifndef TITLEDCANVAS_H
#define TITLEDCANVAS_H
#include "Canvas.h"
class TitledCanvas : public Canvas
{
public:
	TitledCanvas() = delete;
	TitledCanvas(int c, int r, std::string t = "A titled canvas...");
	const TitledCanvas & operator=(const TitledCanvas & rhs);
	virtual ~TitledCanvas() = default;
	virtual void clear(char ch = ' ') override;
	virtual void putChar(char ch, int c, int r) override;
	virtual char getChar(int c, int r) const override;
	const std::string & getTitle() const;
	void setTitle(const std::string & t);
	virtual void decorate() override;
	virtual bool valid(int c, int r) const override;
private:
	static const int DECOR_COLUMNS{ 2 }; // number of not client area columns
	static const int DECOR_ROWS{ 4 }; // number of not client area rows
	static const int H_ORIGIN{ 1 }; // horizontal origin = side border width
	static const int V_ORIGIN{ 3 }; // vertical origin = upper border height
	std::string title;
	void writeTitle(const std::string & t);
};
#endif // !TITLEDCANVAS_H
