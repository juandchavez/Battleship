#include "Battleship.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

#include <io.h>
#include <fcntl.h>


enum ERROR {
	BOARDSIZE = 90,
	XSIZE = 91,
	YSIZE = 92,
	UNKNOWN_XSIZE = 93,
	UNKNOWN_YSIZE = 94
};

/**
Battleship()

Desc: Creates a default boardsize with one ship for testing
Passed:	None
Returned: None
*/
Battleship::Battleship() {
	std::wcout << "Default Settings: x - 0, y - 0, ships - none, boardsize - none" << std::endl;
	m_xSize = 0;
	m_ySize = 0;
	m_gameboard;
}
Battleship::Battleship(int xSize, int ySize) {
	setx(xSize);
	sety(ySize);

	std::wcout << "\nYour boardsize will be " << m_xSize << " by " << m_ySize << std::endl;
	std::wcout << "Creating the board!" << std::endl;
	createBoard();
	printBoard();
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
		exit(err);
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
		exit(err);
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
	// Found in builtin character map
	const wchar_t* sea = L"\u25A1";

	if (getx() || gety()) {
		// Do nothing, just use the builtin error handlers
	}

	std::vector<const wchar_t*> row(m_ySize, sea);

	for (int i = 0; i < m_xSize; i++) {
		m_gameboard.push_back(row);
	}
}
// Print the game board
void Battleship::printBoard() {
	for (int i = 0; i < m_xSize; i++) {
		std::wcout << std::setw(55);
		for (int j = 0; j < m_ySize; j++) {
			std::wcout << m_gameboard[i][j] << " ";
		}
		std::wcout << std::endl;
	}
}
// Update board
void Battleship::updateBoard() {

}
//
void Battleship::createShips() {
	// Found in builtin character map: Black square
	const wchar_t* shippart = L"\u25A0";
	// Ships will be determined by size
	int battleship = 4;
	int cruiser = 3;
	int submarine = 3;
	int destroyer = 2;
	int carrier = 5;
	// Number of ships we have currently
	const int numOfships = 5;

	int fleet[numOfships] = {battleship, cruiser, submarine, destroyer, carrier};

	// Create each ship
	for (int i = 0; i < numOfships; i++) {
		// Create a new battleship
		std::vector<const wchar_t*> ship (fleet[i], shippart);
		// Put the new ship into the ship yard
		m_shipyard.push_back(ship);
	}

	for (int i = 0; i < numOfships; i++) {
		//std::wcout << std::setw(55);
		for (int j = 0; j < fleet[i]; j++) {
			std::wcout << m_shipyard[i][j] << " ";
		}
		std::wcout << std::endl;
	}

}
void Battleship::shipHit() {

}

void Battleship::getError(int err) {
	switch (err) {
	case BOARDSIZE:
		std::wcout << "\nERR: Boardsize" << std::endl;
		break;
	case XSIZE:
		std::wcout << "\nERR: Size of x-axis" << std::endl;
		break;
	case YSIZE:
		std::wcout << "\nERR: Size of y-axis" << std::endl;
		break;
	case UNKNOWN_XSIZE:
		std::wcout << "\nERR: X-axis was never defined" << std::endl;
		break;
	case UNKNOWN_YSIZE:
		std::wcout << "\nERR: Y-axis was never defined" << std::endl;
		break;
	default:
		std::wcout << "UNKNOWN ERROR - FORCE QUIT!" << std::endl;
		exit(-99);
		break;

	}

}