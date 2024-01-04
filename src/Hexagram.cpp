#include "Hexagram.h"
#include <cmath>

Hexagram::Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3])
	: m_firstTriangle(firstTriangle[0], firstTriangle[1], firstTriangle[2]),
	m_secondTriangle(secondTriangle[0], secondTriangle[1], secondTriangle[2])
{
	if (checkCond())
		DefaultHexagram();
}

	
//--------------------------------------------------
Hexagram::Hexagram(const Triangle& t1, const Triangle& t2)
	:m_firstTriangle(t1.Vertex1, t1.Vertex2, t1.Vertex3),
	m_secondTriangle(t2.Vertex1, t2.Vertex2, t2.Vertex3)
{
	if (checkCond())
		DefaultHexagram();
}


//---------------------------------------------------

void Hexagram::DefaultHexagram() {
	Triangle defaultTrian1(20, 20, 25, 20 + sqrt(75), 30, 20);
	Triangle defaultTrian2(20, 20 + sqrt(75), 25, 20 - sqrt(75) / 3, 30, 20 + sqrt(75) * 2 / 3);
	m_firstTriangle = defaultTrian1;
	m_secondTriangle = defaultTrian2;
}

//----------------------------------------------------

double Hexagram::getTotalHeight() const {

	return (m_firstTriangle.getHeight() + m_secondTriangle.getHeight());
}


//----------------------------------------------------

double Hexagram::getLength() const {

	return (m_firstTriangle.getLength());
}

//----------------------------------------------------

void Hexagram::draw(Board& board) const {
	m_firstTriangle.draw(board);
	m_secondTriangle.draw(board);
}

	//------------------------------------------------

Rectangle Hexagram::getBoundingRectangle() const {

	Rectangle Hexagram::getBoundingRectangle() const {
		// Get the bounding rectangles of each triangle
		Rectangle rect1 = m_firstTriangle.getBoundingRectangle();
		Rectangle rect2 = m_secondTriangle.getBoundingRectangle();

		// Combine the bounding rectangles
		// This might involve finding the minimum and maximum x and y values
		// of both rectangles and creating a new rectangle based on those values
		double minX = std::min(rect1.getBottomLeft().m_col, rect2.getBottomLeft().m_col);
		double minY = std::min(rect1.getBottomLeft().m_row, rect2.getBottomLeft().m_row);
		double maxX = std::max(rect1.getTopRight().m_col, rect2.getTopRight().m_col);
		double maxY = std::max(rect1.getTopRight().m_row, rect2.getTopRight().m_row);

		Rectangle combinedRect(Vertex(minX, minY), Vertex(maxX, maxY));
		return combinedRect;
	}

	}

	//-----------------------------------------------

double Hexagram::getArea() const {

	return m_firstTriangle.getArea() + m_secondTriangle.getArea();
	}

	//----------------------------------------------

double Hexagram::getPerimeter() const {

	return m_firstTriangle.getPerimeter() + m_secondTriangle.getPerimeter();
}
	//---------------------------------------------

Vertex Hexagram::getCenter() const {

	return m_firstTriangle.getCenter();

}
//----------------------------------------------------------------------
bool Hexagram::scale(double factor) {


	return false;
