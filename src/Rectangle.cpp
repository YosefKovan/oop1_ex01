
#include "Rectangle.h"
#include "Vertex.h"
#include <cmath>


Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight) 
   : m_bottomLeft(bottomLeft.m_col, bottomLeft.m_row),
	 m_topRight(topRight.m_col, topRight.m_row)
{
	if (checkCond(m_bottomLeft, m_topRight))
		changeToDefault(m_bottomLeft, m_topRight);
	
	setWidthHeight(); 
}
//------------------------------------------------------
Rectangle::Rectangle(const Vertex vertices[2])
	: m_bottomLeft(vertices[0].m_col, vertices[0].m_row),
	  m_topRight(vertices[1].m_col, vertices[1].m_row)
{
	if (checkCond(m_bottomLeft, m_topRight))
		changeToDefault(m_bottomLeft, m_topRight);
	
	setWidthHeight();
	 
}
//------------------------------------------------------
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	: m_bottomLeft(x0, y0), m_topRight(x1, y1)
{
	if (checkCond(m_bottomLeft, m_topRight))
		changeToDefault(m_bottomLeft, m_topRight);
	 
	setWidthHeight();	 
}
//------------------------------------------------------
Rectangle::Rectangle(const Vertex& start, double width, double height)
	: m_bottomLeft(start.m_col, start.m_row),
	  m_topRight(start.m_col + std::abs(width), start.m_row + std::abs(height))
{
	if (checkCond(m_bottomLeft, m_topRight))
		changeToDefault(m_bottomLeft, m_topRight);
	  
	setWidthHeight();
}
//------------------------------------------------------
bool Rectangle::checkCond(Vertex bottomLeft, Vertex topRight) {

	if (bottomLeft.isHigherThan(topRight) || m_bottomLeft.isToTheRightOf(topRight))
		return true;

	if (!bottomLeft.isValid() || !topRight.isValid())
		return true;
	
	return false;
}
//------------------------------------------------------
void Rectangle::changeToDefault(Vertex &bottomLeft, Vertex &topRight) {

	bottomLeft.m_col = 20; 
	bottomLeft.m_row = 10;  
	topRight.m_col = 30;
	topRight.m_row = 20;
}
//------------------------------------------------------
void Rectangle::setWidthHeight() {
	m_width = m_topRight.m_col - m_bottomLeft.m_col;
	m_height = m_topRight.m_row - m_bottomLeft.m_row;
}
//------------------------------------------------------
Vertex Rectangle::getBottomLeft() const{
	
	return  m_bottomLeft;
}
//------------------------------------------------------
Vertex Rectangle::getTopRight() const{

	return  m_topRight;
}
//------------------------------------------------------
double Rectangle::getWidth() const{
	
	return m_width;
}
//------------------------------------------------------
double Rectangle::getHeight() const{

	return m_height;
}
//------------------------------------------------------
void Rectangle::draw(Board& board) const {
	
	Vertex topLeft(m_bottomLeft.m_col, m_topRight.m_row);
	Vertex bottomRight(m_topRight.m_col, m_bottomLeft.m_row);
	
	board.drawLine(topLeft, m_topRight);
	board.drawLine(m_topRight, bottomRight);
	board.drawLine(bottomRight, m_bottomLeft);
	board.drawLine(m_bottomLeft, topLeft);

}
//------------------------------------------------------
Rectangle Rectangle::getBoundingRectangle() const {
	
	//this will create a bounding rectangle and then return it
	Rectangle boundingRectangle(m_bottomLeft, m_topRight);
	return boundingRectangle;

}
//------------------------------------------------------
double Rectangle::getArea() const{
	
 	return m_width * m_height;
}
//------------------------------------------------------
double Rectangle::getPerimeter() const {
	
	return (m_width * 2) + (m_height * 2);
}
//------------------------------------------------------
Vertex Rectangle::getCenter() const {

	double xCenter = (m_bottomLeft.m_col + m_topRight.m_col) / 2;
	double yCenter = (m_bottomLeft.m_row + m_topRight.m_row) / 2;
	
	//this will return the center of the shape
	Vertex center(xCenter, yCenter);
	return center;
		
}
//------------------------------------------------------
bool Rectangle::scale(double factor){
	
	Vertex center = getCenter();
	Vertex bottomLeftTemp = centerToPoint(center, m_bottomLeft, factor);
	Vertex topRightTemp = centerToPoint(center, m_topRight, factor);
    
	if (checkCond(bottomLeftTemp, topRightTemp))
		return false;

	m_bottomLeft = bottomLeftTemp;
	m_topRight = topRightTemp;
	return true;
}
//------------------------------------------------------
Vertex Rectangle::centerToPoint(Vertex center, Vertex point, double factor) {

	double xTemp, yTemp;
	xTemp = abs((center.m_col - point.m_col)) * factor + center.m_col;
	yTemp = abs(center.m_row - point.m_row) * factor + center.m_row;
	Vertex temp(xTemp, yTemp);
	return temp;

}
//------------------------------------------------------