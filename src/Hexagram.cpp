#include "Hexagram.h"
#include <cmath>

Hexagram::Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3])
	: m_firstTriangle(firstTriangle), m_secondTriangle(secondTriangle)
{
	if (checkCond())
		DefaultHexagram();
}

	
//--------------------------------------------------
Hexagram::Hexagram(const Triangle& t1, const Triangle& t2)
	:m_firstTriangle(t1), m_secondTriangle(t2)
{
	if (checkCond())
		DefaultHexagram();
}



//---------------------------------------------------

bool Hexagram::checkCond() {

	if (sameCol(m_firstTriangle.getVertex(2), m_secondTriangle.getVertex(2)) ||
		sameRow(m_firstTriangle.getVertex(1), m_secondTriangle.getVertex(1))) {
		return true;
	}

	return false;
}

//---------------------------------------------------

void Hexagram::DefaultHexagram() {
	// Assuming vertices for the first triangle
	Vertex firstTriangleVertices[3] = {
		Vertex(20, 20),
		Vertex(25, 20 + sqrt(75)),
		Vertex(30, 20)
	};

	// Assuming vertices for the second triangle
	Vertex secondTriangleVertices[3] = {
		Vertex(20, 20 + sqrt(75)* 2 / 3),
		Vertex(25, 20 - sqrt(75) / 3),
		Vertex(30, 20 + sqrt(75) * 2 / 3)
	};

	m_firstTriangle = Triangle(firstTriangleVertices);
	m_secondTriangle = Triangle(secondTriangleVertices);
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


	//-----------------------------------------------

double Hexagram::getArea() const {

	return m_firstTriangle.getArea() * 4 / 3;
	}

	//----------------------------------------------

double Hexagram::getPerimeter() const {

	return m_firstTriangle.getPerimeter() * 4/3;
}
	//---------------------------------------------

Vertex Hexagram::getCenter() const {

	return m_firstTriangle.getCenter();

}
//----------------------------------------------------------------------
bool Hexagram::scale(double factor) {
	if (m_firstTriangle.scale(factor) && m_secondTriangle.scale(factor))
		return true;

	return false;

}
