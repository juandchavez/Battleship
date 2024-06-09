#include "Battleship.h"
#include <iostream>
#include <string>

#include <fcntl.h>
#include <io.h>
#include <stdio.h>

//#define DEBUG




int main() {
#ifdef DEBUG
	std::cout << "---- DEBUG ----" << std::endl;
	Battleship demo;
	int x = 0;
	int y = 0;


	//Attempt to create a board with no size
	//demo.createBoard();

	std::cout << "Enter board size for the x-axis: ";
	std::cin >> x;
	demo.setx(x);

	std::cout << "\nEnter board size for the y-axis: ";
	std::cin >> y;
	demo.sety(y);

	demo.createBoard();
	demo.printBoard();

	std::cout << "---- END OF DEBUG ----" << std::endl;
#endif DEBUG


	return 0;
}
