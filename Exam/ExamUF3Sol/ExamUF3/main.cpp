#include "gameplay.h"


void main() {
	char tablero[X][Y];
	bool gameOver = false;
	int probabilitatAtac = 3; //probabilitat de que te peguen
	int vidaPlayer = 3;
	int oroAcumulado = 0;
	int posx = 0;
	int posy = 0;
	std::vector<int>infoPartida{ posx, posy, vidaPlayer, oroAcumulado, probabilitatAtac };

	pantallaInicio(tablero, gameOver, infoPartida);
	gameplay(tablero, gameOver, posx, posy, probabilitatAtac, vidaPlayer, oroAcumulado);
}