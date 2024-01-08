#include "Triangle.h"
#include <cmath>

Triangle::Triangle(const Vertex vertices[3])
	: m_vertex1(vertices[0]), m_vertex2(vertices[1]), m_vertex3(vertices[2])
{  
	if (checkCond(m_vertex1, m_vertex2, m_vertex3))
		changeTriangleVertices();
}
//----------------------------------------------------
Triangle::Triangle(const Vertex& left, const Vertex& right, double height)
	: m_vertex1(left), m_vertex3(right),
	  m_vertex2((right.m_col - left.m_col) / 2, right.m_row + height)	  
{
	if (checkCond(m_vertex1, m_vertex2, m_vertex3))
		changeTriangleVertices();
}
//----------------------------------------------------
Vertex Triangle::getVertex(int index) const {

	if (index == 1)
		return m_vertex1;
	if (index == 2)
		return m_vertex2;

	return m_vertex3;

}
//----------------------------------------------------
double Triangle::getLength() const {

	return abs(m_vertex1.m_col - m_vertex3.m_col);
}
//----------------------------------------------------
double Triangle::getHeight() const {
	return abs(m_vertex1.m_row - m_vertex2.m_row);
}
//----------------------------------------------------
bool Triangle::checkCond(Vertex vertex1, Vertex vertex2, Vertex vertex3) {

	if (!vertex1.isValid() || !vertex2.isValid() || !vertex3.isValid())
		return true;
	if (!doubleEqual(vertex1.m_row ,vertex3.m_row))
		return true;
	if (!doubleEqual(calcLen(vertex1, vertex3), calcLen(vertex1,vertex2)) ||
		!doubleEqual(calcLen(vertex2, vertex3), calcLen(vertex1, vertex2)))
		return true;

	return false;
}
//----------------------------------------------------
void Triangle::changeTriangleVertices() {

	m_vertex1.m_col = m_vertex1.m_row = 20;
	m_vertex2.m_col = 25;
	m_vertex2.m_row = 20 + sqrt(75);
	m_vertex3.m_col = 30;
	m_vertex3.m_row = 20;

}
//----------------------------------------------------
double Triangle::calcLen(Vertex vertexA, Vertex vertexB) {

	double vectorX = vertexA.m_col - vertexB.m_col;
	double vectorY = vertexA.m_row - vertexB.m_row;
	return sqrt(pow(vectorX, 2) + pow(vectorY, 2));
}
//----------------------------------------------------

void Triangle::draw(Board& board) const {

	board.drawLine(m_vertex1, m_vertex2);
	board.drawLine(m_vertex2, m_vertex3);
	board.drawLine(m_vertex3, m_vertex1);
}
//----------------------------------------------------
Rectangle Triangle::getBoundingRectangle() const {

	//this check if the triangle is pointed upwards 
	if (m_vertex1.m_row < m_vertex2.m_row) {
		Rectangle boundingRect(m_vertex1, getLength(), getHeight());
		return boundingRect;
	}

	Vertex vertex1(m_vertex1.m_col, m_vertex2.m_row);
	Rectangle boundingRect(vertex1, m_vertex3);
	return boundingRect;
}
//----------------------------------------------------
double Triangle::getArea() const {

	return (getLength() * getHeight()) / 2;
}
//----------------------------------------------------
double Triangle::getPerimeter() const {

	return getLength() * 3;
}
//----------------------------------------------------
Vertex Triangle::getCenter() const {

	double centerX = (m_vertex1.m_col + m_vertex2.m_col + m_vertex3.m_col) / 3;
	double centerY = (m_vertex1.m_row + m_vertex2.m_row + m_vertex3.m_row) / 3;
	Vertex center(centerX, centerY);
	return center;
}
//----------------------------------------------------
bool Triangle::scale(double factor) {

	Vertex center = getCenter();

	Vertex leftPoint = getScaleVertex(center, m_vertex1, factor);
	Vertex middlePoint = getScaleVertex(center, m_vertex2, factor);
	Vertex rightPoint = getScaleVertex(center, m_vertex3, factor);

	if (checkCond(leftPoint, middlePoint, rightPoint))
		return false;

	m_vertex1 = leftPoint;
	m_vertex2 = middlePoint;
	m_vertex3 = rightPoint;
	return true;
}
//----------------------------------------------------
Vertex Triangle::getScaleVertex(Vertex center, Vertex vertex, double factor) {
	//this function will return the the new scaled point
	double col = center.m_col + factor * (vertex.m_col - center.m_col);
	double row = center.m_row + factor * (vertex.m_row - center.m_row);
	Vertex scaleVertex(col, row);
	return scaleVertex;	
}
