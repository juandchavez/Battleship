#include "Battleship.h"
#include <iostream>
#include <string>

#define DEBUG



int main()
{
	#ifdef DEBUG

	std::cout << "---- DEBUG ----" << std::endl;
	Battleship demo;
	int x = 0;
	int y = 0;

	std::cout << "Enter board size for the x-axis: "; 
	std::cin >> x;
	demo.setx(x);
	
	std::cout << "\nEnter board size for the y-axis: ";
	std::cin >> y;
	demo.sety(y);

	std::cout << "---- END OF DEBUG ----" << std::endl;
	#endif DEBUG

	
	return 0;
}
