﻿// Battleship.h : Include file for standard system include files,
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
	//TODO: Change typing to ship class
	//std::vector<int> fleet {};									// Holds our battle ships as integers based on their size
	//TODO: Transfer to ship class
	std::vector<std::vector<int>> m_shipCoords;					// Each vector element will hold ship coordinates
	std::vector<Ship> m_fleet;
	int m_fleetSize;
	const wchar_t* m_sea = L"\u25A1";								// Found in builtin character map : Blank square
	const wchar_t* m_shippart = L"\u25A0";						// Found in builtin character map: Black square
	const wchar_t* m_hit = L"\u263c";								// Unicode symbol for a hit
	const wchar_t* m_miss = L"x";									//symbol for a miss
	std::vector<std::vector<const wchar_t*>> m_gameboard;	// The gameboard to play on
	std::vector<std::vector<const wchar_t*>> m_shipyard;		// Holds the battleships

public:
	// Default constructor
	Battleship();
	// Constructor to set up the game
	Battleship(int, int);
	void setx(int);
	int getx();
	void sety(int);
	int gety();
	// Create the game board
	void createBoard();
	// Print the game board
	void printBoard();
	// Update board based on attacked ships
	int updateBoard(int x, int y, char type);
	//TODO: Transfer ship related functions to ship class
	// Create the ships
	void createFleet(int size, std::wstring type);
	void displayFleet();
	void placeShips();
	// Check for an attacked ship
	void shipHit();
	void shipUpdate();

	int checkBoardLimit(int, int, int, char);
	
	// Return errors
	void getError(int err);

};

#endif 


// TODO: Reference additional headers your program requires here.
