#include "Battleship.h"
#include <vector>
#include <iostream>

enum ERROR {
	BOARDSIZE = 90,
	XSIZE = 91,
	YSIZE = 92,
	UNKNOWN_XSIZE = 93,
	UNKNOWN_YSIZE = 94
};

/**
Battleship()

Desc:	Creates a default boardsize with one ship for testing
Passed:	None
Returned: None
*/
Battleship::Battleship() {
	std::cout << "Default Settings: x - 0, y - 0, ships - none, boardsize - none" << std::endl;
	m_xSize = 0;
	m_ySize = 0;
	m_gameboard;
}
Battleship::Battleship(int xSize, int ySize) {
	setx(xSize);
	sety(ySize);

	std::cout << "\nYour boardsize will be " << m_xSize << " by " << m_ySize << std::endl;
	std::cout << "Creating the board!" << std::endl;
	// TODO: insert board creation here
	// and create ships
}

void Battleship::setx(int xSize) {
	try {
		// Length of the X-axis
		if (xSize > 5) {
			m_xSize = xSize;
		}
		else {
			throw(XSIZE);
		}

	}
	catch (ERROR err) {
		getError(err);
		return;
	}

}

int Battleship::getx() {
	try {
		if (m_xSize > 0) {
			return m_xSize;
		}
		else {
			throw(UNKNOWN_XSIZE);
		}
	}
	catch (ERROR err) {
		getError(err);
		exit(err);
	}
}

void Battleship::sety(int ySize) {
	try {
		// Length of the Y-axis
		if (ySize > 5) {
			m_ySize = ySize;
		}
		else {
			throw(YSIZE);
		}

	}
	catch (ERROR err) {
		getError(err);
		return;
	}
}

int Battleship::gety() {
	try {
		if (m_ySize > 0) {
			return m_xSize;
		}
		else {
			throw(UNKNOWN_YSIZE);
		}
	}
	catch (ERROR err) {
		getError(err);
		exit(err);
	}
}

// Create the game baord
void Battleship::createBoard() {
	char sea = 'O';
	std::vector<char> row(m_ySize, sea);

	for (int i = 0; i < m_xSize; i++) {
		m_gameboard.push_back(row);
	}
}
// Print the game board
void Battleship::printBoard() {
	for (int i = 0; i < m_xSize; i++) {
		for (int j = 0; j < m_ySize; i++) {
			std::cout << m_gameboard[i][j] << std::endl;
		}
	}
}
// Update board
void Battleship::updateBoard() {

}
//
void Battleship::createShips() {

}

void Battleship::getError(int err) {
	switch (err) {
	case BOARDSIZE:
		std::cout << "\nERR: Boardsize" << std::endl;
		break;
	case XSIZE:
		std::cout << "\nERR: Size of x-axis" << std::endl;
		break;
	case YSIZE:
		std::cout << "\nERR: Size of y-axis" << std::endl;
		break;
	case UNKNOWN_XSIZE:
		std::cout << "\nERR: X-axis was never defined" << std::endl;
		break;
	case UNKNOWN_YSIZE:
		std::cout << "\nERR: Y-axis was never defined" << std::endl;
		break;
	default:
		std::cout << "UNKNOWN ERROR - FORCE QUIT!" << std::endl;
		exit(-99);
		break;

	}

}