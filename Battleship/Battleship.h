// Battleship.h : Include file for standard system include files,
// or project specific include files.
#pragma once
#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <vector>
#include "Ship.h"
class Battleship {
private:
	int m_xSize;												// Size of the board on x-axis
	int m_ySize;												// Size of the board on y-axis
	const int numOfships = 5;									// Number of ships we have currently
	//TODO: Transfer to ship class
	std::vector<std::vector<int>> m_shipCoords;					// Each vector element will hold ship coordinates
	std::vector<Ship> m_fleet;
	int m_fleetSize;
	const wchar_t* m_sea = L"\u25A1";							// Found in builtin character map : Blank square
	const wchar_t* m_shippart = L"\u25A0";						// Found in builtin character map: Black square
	const wchar_t* m_hit = L"\u263c";							// Unicode symbol for a hit
	const wchar_t* m_miss = L"x";								//symbol for a miss
	std::vector<std::vector<const wchar_t*>> m_gameboard;		// The gameboard to play on
	std::vector<std::vector<const wchar_t*>> m_shipyard;		// Holds the battleships

public:
	
	Battleship();												// Default constructor
	Battleship(int, int);										// Constructor to set up the game
	void setx(int);
	int getx();
	void sety(int);
	int gety();
	void createBoard();
	void printBoard();
	int updateBoard(int x, int y, char type);
	void createFleet(int size, std::wstring type);
	void displayFleet();
	void placeShips();
	void shipHit();												// Check for an attacked ship
	int checkBoardLimit(int, int, int, char);
	void getError(int err);

};

#endif 


// TODO: Reference additional headers your program requires here.
