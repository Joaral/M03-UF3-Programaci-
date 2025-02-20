#include "gameplay.h"

void atacEnemy(char tablero[X][Y], short random, short atacEnemy, int vidaPlayer) {
	std::cout << "Has empezado un combate, pulsa para atacar" << std::endl;
	system("pause");
	random = rand() % atacEnemy;
	if (random == 1) {
		std::cout << "Has matat al enemic y no has perdut vides!\n";
	}
	else {
		std::cout << "Has matat al enemic... Pero has rebut el seu atac.\n";
		vidaPlayer -= 1;
	}
}

void gameplay(char tablero[X][Y], bool gameOver, int posx, int posy, int probabilitatAtac, int vidaPlayer, int oroAcumulado) {
	srand(time(NULL));
	int posicionP[2] = { posx, posy };
	short random = 0;
	short cantidadEnemy = 2;
	char casilla = '.';
	char player = '@';
	char enemy = 'E';
	char cofre = 'C';
	char input;

	//randomizacion de posicion Enemigo/s
	short xEnemigo = 0;
	short yEnemigo = 0;
	for (int i = 0; i < cantidadEnemy; i++)
	{
		while (tablero[xEnemigo][yEnemigo] != '.') {
			xEnemigo = rand() % 5;
			yEnemigo = rand() % 2;
		}
		tablero[xEnemigo][yEnemigo] = enemy;
	}
	std::cout << "Añade una letra entre estas(w,a,s,d) y dale enter para moverte.\n";
	while (!gameOver) {
		renderTablero(tablero);

		//movimiento jugador
		std::cout << ">>";
		std::cin >> input;

		//Aqui debug de input

		//

		if (input == 'w') {
			if (posicionP[1] != 0) {
				tablero[posicionP[0]][posicionP[1]] = casilla;
				posicionP[1] -= 1;
				//ataque enemigo
				if (tablero[posicionP[0]][posicionP[1]] == enemy) {
					atacEnemy(tablero, random, probabilitatAtac, vidaPlayer);
					cantidadEnemy -= 1;
				}
				tablero[posicionP[0]][posicionP[1]] = player;
			}
		}
		if (input == 'a') {
			if (posicionP[0] != 0) {
				tablero[posicionP[0]][posicionP[1]] = casilla;
				posicionP[0] -= 1;
				//ataque enemigo
				if (tablero[posicionP[0]][posicionP[1]] == enemy) {
					atacEnemy(tablero, random, probabilitatAtac, vidaPlayer);
					cantidadEnemy -= 1;
				}
				tablero[posicionP[0]][posicionP[1]] = player;
			}
		}
		if (input == 's') {
			if (posicionP[1] != 1) {
				tablero[posicionP[0]][posicionP[1]] = casilla;
				posicionP[1] += 1;
				//ataque enemigo
				if (tablero[posicionP[0]][posicionP[1]] == enemy) {
					atacEnemy(tablero, random, probabilitatAtac, vidaPlayer);
					cantidadEnemy -= 1;
				}
				tablero[posicionP[0]][posicionP[1]] = player;
			}
		}
		if (input == 'd') {
			if (posicionP[0] != 4) {
				tablero[posicionP[0]][posicionP[1]] = casilla;
				posicionP[0] += 1;
				//ataque enemigo
				if (tablero[posicionP[0]][posicionP[1]] == enemy) {
					atacEnemy(tablero, random, probabilitatAtac, vidaPlayer);
					cantidadEnemy -= 1;
				}
				tablero[posicionP[0]][posicionP[1]] = player;
			}
		}
		system("pause");
		system("cls");
		//guardado partida
		short posx = posicionP[0];
		short posy = posicionP[1];
		std::vector<int>infoPartida{ posx, posy, vidaPlayer, oroAcumulado, probabilitatAtac };
		std::ofstream guardado("partida.dat", std::ios::binary | std::ios::trunc);
		if (!guardado.is_open()) {
			std::cout << "Error al intentar abrir el archivo.\n";
		}
		size_t cantidad = infoPartida.size();
		guardado.write(reinterpret_cast<const char*>(&cantidad), sizeof(size_t));// Escribimos tamaño 
		guardado.write(reinterpret_cast<const char*>(infoPartida.data()), cantidad * sizeof(infoPartida)); // Escribimos todo el vector
		guardado.close(); std::cout << "partida guardada correctamente.\n";

		system("pause");
		system("cls");
		if (cantidadEnemy == 0) {
			gameOver = true;
			std::cout << "Has Guanyat!\n";
		}
	}

}