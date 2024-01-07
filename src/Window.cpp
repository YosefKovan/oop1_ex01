
#include "Window.h"
#include <cmath>
#include "Utilities.h"

//---------------------------------------------------------------------
Window::Window(const Rectangle& outer, const Rectangle& inner)
	:m_outer(outer), m_inner(inner)
{
	if (checkCond())
		setDefault();
}
//---------------------------------------------------------------------
Window::Window(const Rectangle& outer, double verticalThickness, double horizontalThickness)
	: m_outer(outer),
	  m_inner(outer.getBottomLeft().m_col + horizontalThickness,
		      outer.getBottomLeft().m_row + verticalThickness,
		      outer.getTopRight().m_col - horizontalThickness,
		      outer.getTopRight().m_row - verticalThickness)
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

	if (!doubleEqual(m_outer.getCenter().m_col, m_inner.getCenter().m_col) ||
		!doubleEqual(m_outer.getCenter().m_row, m_inner.getCenter().m_row))
		return true;

	if (m_outer.getBottomLeft().m_col > m_inner.getBottomLeft().m_col ||
		m_outer.getTopRight().m_row < m_inner.getTopRight().m_row)
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

	return (m_outer.scale(factor) && m_inner.scale(factor));
}
