

#include "Utilities.h"
#include "Hexagram.h"
#include <cmath>
#include "Rectangle.h"

Hexagram::Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3])
	    : m_triangle1(firstTriangle), m_triangle2(secondTriangle)
{
	 if(!conditionsOccur())
	    setDefault();
}
//--------------------------------------------------------------------
Hexagram::Hexagram(const Triangle& t1, const Triangle& t2)
    : m_triangle1(t1), m_triangle2(t2)
{
	 if(!conditionsOccur())
	    setDefault();
}
//--------------------------------------------------------------------
double Hexagram::getTotalHeight() const{

	 return abs(m_triangle1.getVertex(2).m_row - m_triangle2.getVertex(2).m_row);
}
//--------------------------------------------------------------------
double Hexagram::getLength() const{

	 return m_triangle1.getLength();
}
//--------------------------------------------------------------------
bool Hexagram::conditionsOccur() {

	if (!doubleEqual(m_triangle1.getCenter().m_col, m_triangle2.getCenter().m_col) ||
		!doubleEqual(m_triangle1.getCenter().m_row, m_triangle2.getCenter().m_row))
		return false;
	if (doubleEqual(m_triangle1.getVertex(1).m_row, m_triangle2.getVertex(1).m_row))
		return false;
	
	return true;
}
//--------------------------------------------------------------------
void Hexagram::setDefault() {
	
	Vertex vertex1Tri1(20, 20), vertex2Tri1(25, 20 + sqrt(75)),
	       vertex3Tri1(30, sqrt(75) * 2 / 3);
	Vertex t1VertexArr[3] = { vertex1Tri1 , vertex2Tri1 , vertex3Tri1 };
	
	Vertex vertex1Tri2(20, 20 + sqrt(75) * 2 / 3),
		   vertex2Tri2(25, 20 - sqrt(75) / 3),
		   vertex3Tri2(30, 20 + sqrt(75) * 2 / 3);
	Vertex t2VertexArr[3] = { vertex1Tri2 , vertex2Tri2 , vertex3Tri2 };
	 
	Triangle triangle1(t1VertexArr), triangle2(t2VertexArr);
	m_triangle1 = triangle1;
	m_triangle2 = triangle2;
}
//--------------------------------------------------------------------
void Hexagram::draw(Board& board) const {

	m_triangle1.draw(board);
	m_triangle2.draw(board);
}
//--------------------------------------------------------------------
Rectangle Hexagram::getBoundingRectangle() const {

	double bottomLeftRow;

	if (m_triangle1.getVertex(2).m_row < m_triangle2.getVertex(2).m_row)
		bottomLeftRow = m_triangle1.getVertex(2).m_row;
	else 
		bottomLeftRow = m_triangle2.getVertex(2).m_row;
	
	Vertex bottomLeft(m_triangle2.getVertex(1).m_col, bottomLeftRow);
	Rectangle boundingRectangle(bottomLeft, getLength(), getTotalHeight());
	return boundingRectangle;
}
//--------------------------------------------------------------------
double Hexagram::getArea() const {

	return m_triangle2.getArea() * 4 / 3;
}
//--------------------------------------------------------------------
double Hexagram::getPerimeter() const {

	return m_triangle2.getPerimeter() * 4 / 3;
}
//--------------------------------------------------------------------
Vertex Hexagram::getCenter() const {

	return m_triangle1.getCenter();
}
//--------------------------------------------------------------------
bool Hexagram::scale(double factor) {

	return (m_triangle1.scale(factor) && m_triangle2.scale(factor));		
}

