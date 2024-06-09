#include "Battleship.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#ifdef _WIN32
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#endif

#define DEBUG

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

int main() {
#ifdef _WIN32
	//SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << L"Hello, \u25A1!\n";
#endif
#ifdef DEBUG
	std::wcout << std::setw(65);
	std::wcout << "---- DEBUG ----" << std::endl;
	Battleship demo;
	int x = 0;
	int y = 0;
	char user = '\0';


	//Attempt to create a board with no size
	//demo.createBoard();
	std::wcout << "Enter board size for the x-axis: ";
	std::cin >> x;
	demo.setx(x);

	std::wcout << "\nEnter board size for the y-axis: ";
	std::cin >> y;
	demo.sety(y);

	std::wcout << "\nIs this the board size you want, enter [Y/N]" << std::endl;
	std::wcout << "Boardsize: " << x << " x " << y << "\n";
	std::wcout << ">> ";
	std::cin >> user;

	
	if (toupper(user) != 'Y' && toupper(user) != 'N') {
		std::wcout << "\nNot a valid choice, try again!";
		while (toupper(user) != 'Y' && toupper(user) != 'N') {
			std::wcout << "\n>> ";
			std::cin >> user;
		}
	}
	else if (toupper(user) == 'N') {
		std::wcout << "\nExiting";
		exit(-99);
	}
	else {
		std::wcout << "\nContinuing" << std::endl;
	}
	clear();


	demo.createBoard();
	demo.printBoard();
	std::wcout << "Creating battleships " << std::endl;
	demo.createShips();
	std::wcout << "Simulating a hit " << std::endl;
	std::wcout << "Simulating a miss " << std::endl;
	std::wcout << std::setw(65);
	std::wcout << "---- END OF DEBUG ----" << std::endl;
#endif DEBUG


	return 0;
}
