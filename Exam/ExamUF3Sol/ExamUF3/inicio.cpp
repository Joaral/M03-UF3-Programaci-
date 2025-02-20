#include "inicio.h"

void pantallaInicio(char tablero[X][Y], bool gameOver, std::vector<int>infoPartida) {
	short input = 0;

	std::cout << "Menu Inicial:" << std::endl;
	std::cout << "1. Nova Partida" << std::endl << "2. Carregar Partida" << std::endl << "3. Sortir" << std::endl << ">>";
	std::cin >> input;

	switch(input){
	case 1:

		creacionTablero(tablero);
		tablero[0][0] = '@';

		break;
	case 2: // no se perque no hem va la lectura

		//creacionTablero(tablero);

		//std::ifstream cargado("partida.dat", std::ios::binary);
		//if (!cargado.is_open()) {
		//	std::cout << "Error al abrir el archivo para leer.\n";
		//	return;
		//}
		//size_t cantidad;
		//cargado.read(reinterpret_cast<char*>(&cantidad), sizeof(size_t)); // Leemos el tamaño
		//infoPartida.resize(cantidad); // Reservamos espacio en el vector
		//cargado.read(reinterpret_cast<char*>(infoPartida.data()), cantidad * sizeof(infoPartida)); // Leemos todos los elementos
		//cargado.close();
		//std::cout << "Vector cargado correctamente.\n";

		//renderTablero(tablero);

		break;
	case 3:
		gameOver = true;
		break;
	default:
		system("pause");
		system("cls");
	}
}