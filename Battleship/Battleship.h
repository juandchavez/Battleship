// Battleship.h : Include file for standard system include files,
// or project specific include files.

#include <vector>
#pragma once
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class Battleship {
private:
	int m_xSize{};	// Size of the board on x-axis
	int m_ySize{};	// Size of the board on y-axis
	const int numOfships = 5;	// Number of ships we have currently
	std::vector<int> fleet {};	// Holds our battle ships as integers based on their size
	std::vector<std::vector<int>> shipCoords;	// Each vector element will hold ship coordinates
	const wchar_t* sea = L"\u25A1"; // Found in builtin character map : Blank square
	const wchar_t* shippart = L"\u25A0";	// Found in builtin character map: Black square
	const wchar_t* hit = L"\u263c";	// Unicode symbol for a hit
	const wchar_t* miss = L"x"; //symbol for a miss
	std::vector<std::vector<const wchar_t*>> m_gameboard {};	// The gameboard to play on
	std::vector<std::vector<const wchar_t*>> m_shipyard{};		// Holds the battleships

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
	int updateBoard(int, int, char);
	// Create the ships
	void createShips();
	void displayShips();
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
