
#include "Rectangle.h"

class Window {

public:
	Window(const Rectangle& outer, const Rectangle& inner);
	Window(const Rectangle& outer, double verticalThickness, double horizontalThickness);
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getVerticalThickness() const;
	double getHorizontalThickness() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);


private:
	Rectangle m_inner;
	Rectangle m_outer;
	bool checkCond();
	void setDefault();
};
