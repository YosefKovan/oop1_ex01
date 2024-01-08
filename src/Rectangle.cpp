
#include "Rectangle.h"
#include "Vertex.h"
#include <cmath>


Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight) 
    : m_bottomLeft(bottomLeft), m_topRight(topRight)
{
	if (checkCond(m_bottomLeft, m_topRight))
		changeToDefault();
}
//------------------------------------------------------
Rectangle::Rectangle(const Vertex vertices[2])
	: m_bottomLeft(vertices[0]) ,m_topRight(vertices[1])
{
	if (checkCond(m_bottomLeft, m_topRight))
		changeToDefault();
}
//------------------------------------------------------
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	: m_bottomLeft(x0, y0), m_topRight(x1, y1)
{
	if (checkCond(m_bottomLeft, m_topRight))
		changeToDefault();	 
}
//------------------------------------------------------
Rectangle::Rectangle(const Vertex& start, double width, double height)
	: m_bottomLeft(start),
	  m_topRight(start.m_col + abs(width), start.m_row + abs(height))
{
	 if (checkCond(m_bottomLeft, m_topRight) || width < 0 || height < 0)
		 changeToDefault();
}
//------------------------------------------------------
bool Rectangle::checkCond(Vertex bottomLeft, Vertex topRight) {

	 if (bottomLeft.isHigherThan(topRight) || bottomLeft.isToTheRightOf(topRight))
		 return true;

	 if (!bottomLeft.isValid() || !topRight.isValid())
		 return true;
	
	 return false;
}
//------------------------------------------------------
void Rectangle::changeToDefault() {

     m_bottomLeft.m_col = 20; 
	 m_bottomLeft.m_row = 10;  
	 m_topRight.m_col = 30;
	 m_topRight.m_row = 20;
}
//------------------------------------------------------
Vertex Rectangle::getBottomLeft() const{
	
	 return m_bottomLeft;
}
//------------------------------------------------------
Vertex Rectangle::getTopRight() const{

	 return m_topRight;
}
//------------------------------------------------------
double Rectangle::getWidth() const{
	
	 return m_topRight.m_col - m_bottomLeft.m_col;
}
//------------------------------------------------------
double Rectangle::getHeight() const{

     return m_topRight.m_row - m_bottomLeft.m_row;
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
	
	Rectangle boundingRectangle(m_bottomLeft, m_topRight);
	return boundingRectangle;
}
//------------------------------------------------------
double Rectangle::getArea() const{
	
	return getHeight() * getWidth();
}
//------------------------------------------------------
double Rectangle::getPerimeter() const {
	
	return getWidth() * 2 + getHeight() * 2;
}
//------------------------------------------------------
Vertex Rectangle::getCenter() const {

	double xCenter = (m_bottomLeft.m_col + m_topRight.m_col) / 2;
	double yCenter = (m_bottomLeft.m_row + m_topRight.m_row) / 2;
	
	Vertex center(xCenter, yCenter);
	return center;		
}
//------------------------------------------------------
bool Rectangle::scale(double factor) {

	Vertex center = getCenter();
	Vertex bottomLeft(getScaleVertex(center, m_bottomLeft, factor));
	Vertex topRight(getScaleVertex(center,m_topRight, factor));
		
	if (checkCond(bottomLeft, topRight))
		return false;
	
	m_bottomLeft = bottomLeft;
	m_topRight = topRight;
	return true;
}
//------------------------------------------------------
Vertex Rectangle::getScaleVertex(Vertex center, Vertex vertex, double factor) {
	//this function will return the the new scaled point
	double col = center.m_col + factor * (vertex.m_col - center.m_col);
	double row = center.m_row + factor * (vertex.m_row - center.m_row);
	Vertex scaleVertex(col, row);
	return scaleVertex;
}
  
