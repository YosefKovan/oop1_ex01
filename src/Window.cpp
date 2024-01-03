
#include "Window.h"
#include <cmath>


//---------------------------------------------------------------------
Window::Window(const Rectangle& outer, const Rectangle& inner) 
	:m_outer(outer.getBottomLeft(), outer.getTopRight()),
	 m_inner(inner.getBottomLeft(), inner.getTopRight())
{   
	
	if(checkCond())
	   setDefault();	
}
//---------------------------------------------------------------------
Window::Window(const Rectangle& outer, double verticalThickness, double horizontalThickness) 
	: m_outer(outer.getBottomLeft(), outer.getTopRight()),
	  m_inner(outer.getBottomLeft().m_col + horizontalThickness, 
		      outer.getBottomLeft().m_row + verticalThickness,
		      outer.getTopRight().m_col - horizontalThickness, 
		      outer.getTopRight().m_row - horizontalThickness)
{
	
	if (m_outer.getHeight() / 2 < verticalThickness || 
		m_outer.getWidth() / 2 < horizontalThickness)
		setDefault();
}
//---------------------------------------------------------------------
Vertex Window::getBottomLeft() const {

	return m_outer.getBottomLeft();
	
}
//---------------------------------------------------------------------

Vertex Window::getTopRight() const {

	return m_outer.getTopRight();

}
//---------------------------------------------------------------------
double Window::getVerticalThickness() const {

	return (m_outer.getTopRight().m_row - m_inner.getTopRight().m_row);
   
}
//---------------------------------------------------------------------
double Window::getHorizontalThickness() const {

	return (m_inner.getBottomLeft().m_col - m_outer.getBottomLeft().m_col);
}

//---------------------------------------------------------------------
void Window::setDefault() {

	Rectangle defaultRect(30.0, 20.0, 20.0, 10.0);
	m_inner = defaultRect;
	m_outer = defaultRect;

}
//----------------------------------------------------------------------
bool Window::checkCond() {

	if (abs(m_outer.getCenter().m_col - m_inner.getCenter().m_col) > 0.5 ||
		abs(m_outer.getCenter().m_row - m_inner.getCenter().m_row) > 0.5)
		return true;
	
	if (m_outer.getBottomLeft().m_col > m_inner.getBottomLeft().m_col ||
		m_outer.getTopRight().m_row < m_outer.getTopRight().m_row)
		return true;

	return false;
}

//----------------------------------------------------------------------
void Window::draw(Board& board) const {

	m_outer.draw(board);
	m_inner.draw(board);
}
//----------------------------------------------------------------------
Rectangle Window::getBoundingRectangle() const {

	return m_outer;
}
//----------------------------------------------------------------------
double Window::getArea() const {

	return (m_outer.getArea() + m_outer.getArea());
}
//----------------------------------------------------------------------
double Window::getPerimeter() const {

	return (m_outer.getPerimeter() + m_inner.getPerimeter());
	
}
//----------------------------------------------------------------------
Vertex Window::getCenter() const {

	return m_outer.getCenter();
}
//----------------------------------------------------------------------
bool Window::scale(double factor) {

	if (m_outer.scale(factor) && m_inner.scale(factor))
		return true;
	return false;
}
