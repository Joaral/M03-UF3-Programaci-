#include "tablero.h"

void creacionTablero(char tablero[X][Y]) {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			tablero[j][i] = '.';
		}
	}
}

void renderTablero(char tablero[X][Y]) {
	std::cout << "#######\n";
	for (int i = 0; i < Y; i++)
	{
		std::cout << "#";
		for (int j = 0; j < X; j++)
		{
			std::cout << tablero[j][i];
		}
		std::cout << "#" << std::endl;
	}
	std::cout << "#######\n";
}