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
	
	return (distance(m_firstTriangle.getVertex(2), m_secondTriangle.getVertex(2)));
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


	double X = m_firstTriangle.getVertex(1).m_col;
	double minY = std::min(m_firstTriangle.getVertex(2).m_row, m_secondTriangle.getVertex(2).m_row);
	Vertex m_BottomLeft(X, minY);
	Rectangle temp(m_BottomLeft, getLength(), getTotalHeight());
	return (temp);

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
