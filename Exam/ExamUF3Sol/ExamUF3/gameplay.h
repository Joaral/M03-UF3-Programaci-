#pragma once
#include "inicio.h"

void atacEnemy(char tablero[X][Y], short random, short atacEnemy, int vidaPlayer);
void gameplay(char tablero[X][Y], bool gameOver, int posx, int posy, int probabilitatAtac, int vidaPlayer, int oroAcumulado);