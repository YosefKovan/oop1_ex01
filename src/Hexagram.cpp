#include "Hexagram.h"
#include <cmath>

Hexagram::Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3])
	: m_vertexFirst1(firstTriangle[0].m_col, firstTriangle[0].m_row),
	m_vertexFirst2(firstTriangle[1].m_col, firstTriangle[1].m_row),
	m_vertexFirst3(firstTriangle[2].m_col, firstTriangle[2].m_row),
	m_vertexSecond1(secondTriangle[0].m_col, secondTriangle[0].m_row),
	m_vertexSecond2(secondTriangle[1].m_col, secondTriangle[1].m_row),
	m_vertexSecond3(secondTriangle[2].m_col, secondTriangle[2].m_row)
{
	if (checkCond())
		DefaultHexagram();
}

	
//--------------------------------------------------
Hexagram::Hexagram(const Triangle& t1, const Triangle& t2)
	:m_t1(t1.Vertex1, t1.Vertex2, t1.Vertex3),
	m_t2(t2.Vertex1, t2.Vertex2, t2.Vertex3)
{
	if (checkCond())
		DefaultHexagram();
}


//---------------------------------------------------

void Hexagram::DefaultHexagram(); {
	Triangle defaultTrian1(20, 20, 25, 20 + sqrt(75), 30, 20);
	Triangle defaultTrian2(20, 20 + sqrt(75), 25, 20 - sqrt(75) / 3, 30, 20 + sqrt(75) * 2 / 3);
	m_t1 = defaultTrian1;
	m_t2 = defaultTrian2;
}

//----------------------------------------------------

void Hexagram::draw(Board& board) const {
	m_t1.draw(board);
	m_t2.draw(board);
}

//----------------------------------------------------------------------
bool Hexagram::scale(double factor) {


	return false;
}
