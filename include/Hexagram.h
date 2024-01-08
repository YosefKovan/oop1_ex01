
#include "Vertex.h"
#include "Triangle.h"
#include "Rectangle.h"

class Hexagram {

public:
	Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3]);
	Hexagram(const Triangle& t1, const Triangle& t2);
	double getTotalHeight() const;
	double getLength() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Triangle m_triangle1;
	Triangle m_triangle2;
	bool conditionsOccur();
	void setDefault();
};
