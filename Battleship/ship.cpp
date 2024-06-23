#include "Ship.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

#include <io.h>
#include <fcntl.h>

// Default: size - 1, health - 1, sunk - false, xCoord - 0, yCoord - 0, type - "Dummy"
Ship::Ship(){
	shipSize = 1;
	sunk = false;
	xCoord.push_back(0);
	yCoord.push_back(0);
	hull.push_back(shippart);
	health.push_back(shippart);
	type = L"Dummy";
}

void Ship::createShip(int size, std::wstring type) {
	shipSize = size;
	health = size;
	shipType = type;

	// Did this so we can put each ship piece into the health and hull vector
	// number of black squares should equal size
	for (int i = 0; i < shipSize; i++) {
		health.push_back(shippart)
		hull.push_back(shippart);
	}
}

void Ship::displayShip() {
	for (int i = 0; i < shipSize; i++) {
		std::wcout << hull[i];
	}
	std::wcout << std::endl;
}
void Ship::setxCoord(int xPos) {

}
int  Ship::getdxCoord() {
	return 0;
}
void Ship::setyCoord(int yPos) {

}
int  Ship::getyCoord() {
	return 0;
}
void Ship::displayCoords() {

}
void Ship::shipUpdate() {

}
Ship::~Ship() {

}