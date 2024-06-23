#pragma once
#ifndef SHIP_H
#define SHIP_H
#include <vector>
#include <string>
class Ship {
private:
	int shipSize{};										// All of our battleships will be interger size
	bool sunk{};										// Check if the ship was sunk already
	std::vector<int> xCoord{};							// Location of ship on x-axis
	std::vector<int> yCoord{};							// Location of ship on y-axis
	std::wstring shipType{};							// The name of the battleship (wide string -> use L"" format)
	const wchar_t* shippart = L"\u25A0";				// Found in builtin character map: Black square
	std::vector<const wchar_t*> health;					// How much damage the ship took
	std::vector<const wchar_t*> hull;					// Visual representation of the battleship
public:
	Ship();												// Default: size - 1, health - 1, sunk - false, xCoord - 0, yCoord - 0, type - "Dummy"
	void createShip(int size, std::wstring type);		// Create the battleship based on info given
	void displayShip();									// Display type and health
	void setxCoord(int xPos);							// Set Coordinates
	int  getdxCoord();
	void setyCoord(int yPos);
	int  getyCoord();
	void displayCoords();								// Debug only: Display the coordinates of the ship
	void shipUpdate();									// Update the ship values
	~Ship();											// Set all values to default at the end of the game
};
#endif