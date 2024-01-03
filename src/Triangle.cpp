#include "Utilities.h"
#include "Triangle.h"
#include <cmath>

Triangle::Triangle(const Vertex vertices[3]) 
	 : m_vertex1(vertices[0].m_col, vertices[0].m_row),
	   m_vertex2(vertices[1].m_col, vertices[1].m_row),
	   m_vertex3(vertices[2].m_col, vertices[2].m_row)    
{
	  if(checkCond())
		changeTriangleVertices();
}
//----------------------------------------------------
Triangle::Triangle(const Vertex& left, const Vertex& right, double height) 
     : m_vertex1(left.m_col, left.m_row),
	   m_vertex2((right.m_col - left.m_col)/2, right.m_row+height),
	   m_vertex3(right.m_col, right.m_row)
{
	  if (checkCond())
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
double Triangle::getHeight() const{
	return abs(m_vertex1.m_row - m_vertex2.m_row);
}
//----------------------------------------------------
bool Triangle::checkCond() {

	if (!m_vertex1.isValid() || !m_vertex2.isValid() || !m_vertex3.isValid())
		return true;
	if (m_vertex1.m_row != m_vertex3.m_row)
		return true;
	if (!doubleEqual(getLength(), calculateLength(m_vertex1, m_vertex2)) ||
		!doubleEqual(getLength(),  calculateLength(m_vertex1, m_vertex2)))
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
double Triangle::calculateLength(Vertex vertexA, Vertex vertexB){
  
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
		Rectangle temp(m_vertex1, getLength(), getHeight());
		return temp;
	}
	
	Vertex vertex1(m_vertex1.m_col, m_vertex2.m_row);
	Rectangle temp(vertex1, m_vertex3);
	return temp;
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

	double centerX = (m_vertex1.m_col + m_vertex2.m_col + m_vertex3.m_col)/3;
	double centerY = (m_vertex1.m_row + m_vertex2.m_row + m_vertex3.m_row)/3;
	Vertex center(centerX, centerY);
	return center;
}
//----------------------------------------------------
bool Triangle::scale(double factor) {
	Vertex center = getCenter();
	m_vertex1.m_col = center.m_col + factor * (m_vertex1.m_col - center.m_col);
	m_vertex1.m_row = m_vertex3.m_row = center.m_row + factor * (m_vertex1.m_row - center.m_row);
	m_vertex2.m_row = center.m_row + factor * (m_vertex2.m_row - center.m_row);
	m_vertex3.m_col = center.m_col + factor * (m_vertex3.m_col - center.m_col);
	if (checkCond())
		return false;
	return true;
}

	return false;
}
