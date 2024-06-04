#include "Battleship.h"
#include <vector>
#include <iostream>

Battleship::Battleship() {
	m_xSize = 1;
	m_ySize = 1;
	m_gameboard;
}
Battleship::Battleship(int xSize, int ySize) {
	try {
		if (xSize < 5) {
			m_xSize = xSize;
		}
		else {
			throw(xSize);
		}

		if (ySize < 5 && xSize < 5) {
			m_ySize = ySize;
		}
		else {
			throw(ySize);
		}
	
	}
	catch (int err) {
		std::cout << "ERR: Board size is too small!\n";
		std::cout << "Board size: " << xSize << "x" << ySize << std::endl;
	}


	// TODO: insert board creation here
	// and create ships
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