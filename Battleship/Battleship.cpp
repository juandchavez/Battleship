#include "Battleship.h"
#include "Ship.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

#include <io.h>
#include <fcntl.h>


enum ERROR {
	BOARDSIZE = 90,
	XSIZE = 91,
	YSIZE = 92,
	UNKNOWN_XSIZE = 93,
	UNKNOWN_YSIZE = 94,
	OCCUPIED = 95
};

const int carrier = 5;
const int battleship = 4;
const int cruiser = 3;
const int submarine = 3;
const int destroyer = 2;

/**

Desc: Creates a default boardsize with one ship for testing
Passed:	None
Returned: None
*/
Battleship::Battleship() {
	std::wcout << "Default Settings: x - 0, y - 0, ships - none, boardsize - none" << std::endl;
	m_xSize = 0;
	m_ySize = 0;
	m_gameboard;
	m_shipCoords;
	m_fleetSize = 0;
}
Battleship::Battleship(int xSize, int ySize) {
	setx(xSize);
	sety(ySize);
	m_fleetSize = 0;

	std::wcout << "\nYour boardsize will be " << m_xSize << " by " << m_ySize << std::endl;
	std::wcout << "Creating the board!" << std::endl;
	createBoard();
	printBoard();
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

	if (getx() || gety()) {
		// Do nothing, just use the builtin error handlers
	}

	std::vector<const wchar_t*> row(m_ySize, m_sea);

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
// Update board : Need to privatetize this later
int Battleship::updateBoard(int xCoord, int yCoord, char type) {
	const wchar_t* space = m_gameboard[xCoord][yCoord];

	// Check for an empty space
	if (wcscmp(space, m_sea) == 0) {
		if (type == 'H') {
			m_gameboard[xCoord][yCoord] = m_hit;
			return 0;
		}
		else if (type == 'M') {
			m_gameboard[xCoord][yCoord] = m_miss;
			return 0;
		}
	}
	else {
		getError(OCCUPIED);
		return -1;
	}
}

void Battleship::createFleet(int hullSize, std::wstring shipType) {
	Ship temp;
	temp.createShip(hullSize, shipType);

	m_fleet.push_back(temp);
	m_fleetSize = m_fleetSize + 1;
}

void Battleship::displayFleet() {
	/*
	// Ships will be determined by size
	const int tempNumShips = 5;

	int temp[tempNumShips] = {carrier,battleship,cruiser,submarine,destroyer};
	std::wstring shipType[tempNumShips] = {L"Carrier", L"Battleship", L"Cruiser", L"Submarine", L"Destroyer"};
	
	for (int i = 0; i < numOfships; i++)
		fleet.push_back(temp[i]);

	// Create each ship
	for (int i = 0; i < numOfships; i++) {
		// Create a new battleship
		std::vector<const wchar_t*> ship (fleet[i], shippart);
		// Put the new ship into the ship yard
		m_shipyard.push_back(ship);
	}

	for (int i = 0; i < numOfships; i++) {
		//std::wcout << std::setw(55);
		std::wcout << shipType[i].c_str() << std::setw(5);
		for (int j = 0; j < fleet[i]; j++) {
			std::wcout << m_shipyard[i][j] << " ";
		}
		std::wcout << std::endl;
	}
	*/

	for (int i = 0; i < m_fleetSize; i++) {
		m_fleet[i].displayShip();
	}
}

/**

Desc: Gets a random number to place a battle ship on the game board. 
Uses a sliding window method to get coordinates in pairs
Passed:	None
Returned: None
*/
void Battleship::placeShips() {
	unsigned long num = 0;
	char alignment = '\0';
	int random = 0;
	int mixFlag = 0;
	int xCoord = 0;
	int yCoord = 0;

	const int tempNumShips = 5;

	int temp[tempNumShips] = { carrier,battleship,cruiser,submarine,destroyer };

	m_shipCoords;

	srand((unsigned)time(NULL));
	
	for (int i = 0; i < numOfships; i++) {
		// Get the first pair
		xCoord = rand() % getx();
		yCoord = rand() % gety();


		if ((random & 1) == 1) {
			// if odd; Place the ship horizontally
			alignment = 'H';
			
		}
		else {
			// if even; Place the ship vertically;
			alignment = 'V';
		}
		// Need to check if we are at the top or bottom of the board
		checkBoardLimit(xCoord, yCoord, temp[i], alignment);
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
	case OCCUPIED:
		std::wcout << "\nERR: Already occupied" << std::endl;
		break;
	default:
		std::wcout << "UNKNOWN ERROR - FORCE QUIT!" << std::endl;
		exit(-99);
		break;

	}

}

int Battleship::checkBoardLimit(int xCoord, int yCoord, int type, char align) {
	// Handle the limits based on the type of ship
	// Note: case cruiser will handle submarine limits too since they are the same size
	// TODO: Map this out visually
	switch (type) {
	case carrier:
		if (align == 'H') {
			return 0;
		}
		break;
	case battleship:
		return 0;
		break;
	case cruiser:
		return 0;
		break;
	case destroyer:
		return 0;
		break;

	}
}