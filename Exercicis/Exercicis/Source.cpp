#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

struct Player
{
	int death, kills, puntuation, items, games;
};

struct Point
{
	float x, y;
};

int main() {
	//ejemplo ofstream
	/*std::ofstream myfile("miarchivo.txt");
	if (myfile.is_open()) {
		myfile << "Hello World!\n";
		myfile.close();
	}
	else {
		std::cout << "No he encontrado el archivo\n";
	}*/


	/*std::fstream myfile;
	myfile.open("miArchivo.txt", std::ios::out | std::ios::trunc);
	if (myfile.is_open()) {
		myfile << "Hello Dead World!\n";
		myfile.close();
	}*/

	/*std::string line;
	std::ifstream myfile;
	myfile.open("miArchivo.txt");

	if (myfile.is_open()) {
		while (std::getline(myfile, line)) {
			std::cout << line << std::endl;
		}

		std::cout << line;
		myfile.close();

	}*/

	/*std::vector<Player> listaJugadores;
	std::string line;
	std::ifstream myfile;
	myfile.open("miArchivo.txt");

	if (myfile.is_open()) {
		while (std::getline(myfile, line)) {
			for (int i = 0; i < line.length(); i++)
			{
				Player tmp;
				if (line[i] != ',') {

				}
			}
		}

		myfile.close();

	}*/
	
	/*std::vector<Point> figuraGeometrica;
	std::string line;
	std::ifstream myfile;
	myfile.open("miArchivo.txt");

	if (myfile.is_open()) {
		std::vector<float> numberFloat;

		while (std::getline(myfile, line, ' ')) {
			float numero = std::stof(line);
			numberFloat.push_back(numero);
		}
		for (int i = 0; i < numberFloat.size(); i+=2)
		{
			Point tmp;
			tmp.x = numberFloat[i];
			tmp.y = numberFloat[i+1];
			figuraGeometrica.push_back(tmp);
		}

		for (int i = 0; i < figuraGeometrica.size(); i++)
		{
			std::cout << i << ": " << figuraGeometrica[i].x << "," << figuraGeometrica[i].y << std::endl;
		}

	}*/

	short random;

	for (int i = 0; i < 10; i++)
	{
		
	}



}