#include "Utilities.h"
#include "Vertex.h"
#include "Rectangle.h"
#include "Board.h"

class Triangle {
public:
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& left, const Vertex& right, double height);
	Vertex getVertex(int index) const;
	double getLength() const;
	double getHeight() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);
	

private:
	Vertex m_vertex1;
	Vertex m_vertex2;
	Vertex m_vertex3;
	double calcLen(Vertex, Vertex);
	bool checkCond(Vertex, Vertex, Vertex);
	void changeTriangleVertices();
	Vertex getScaleVertex(Vertex, Vertex, double);
};
