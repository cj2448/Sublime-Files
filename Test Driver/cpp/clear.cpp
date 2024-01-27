#include <iostream>

#define WINDOWS true

void clearScreen();
void clearInstream();

// int main() {
// 	while (1) {
// 		clearScreen();
// 		clearInstream();
// 	}
// }

void clearScreen() {
if (WINDOWS)
	system("CLS");
else
	system("clear");
}

void clearInstream() {
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}