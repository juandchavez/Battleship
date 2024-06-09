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
	void updateBoard();
	// Create the ships
	void createShips();
	void shipHit();
	void shipUpdate();
	
	// Return errors
	void getError(int err);

};

#endif 


// TODO: Reference additional headers your program requires here.
