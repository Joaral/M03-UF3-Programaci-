#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

struct GameObject {
	char type;
	int x;
	int y;
};

void SaveObjects(std::vector<GameObject>objects, std::string fileName) 
{
	std::ofstream writeFile(fileName, std::ios::binary | std::ios::trunc);
	if (!writeFile.is_open()) {
		return;
	}

	size_t size = objects.size();
	if (size == 0)return;

	writeFile.write(reinterpret_cast<char*>(size), sizeof(size_t));
	writeFile.write(reinterpret_cast<char*>(objects.data()), sizeof(GameObject) * size);
	writeFile.close();
}	

void RecoverObjects(std::vector<GameObject>& objects, std::string fileName) {
	std::ifstream readFile(fileName, std::ios::binary);
	if (!readFile.is_open())return;
	size_t size = objects.size();
	readFile.read(reinterpret_cast<char*>(size), sizeof(size_t));
	readFile.read(reinterpret_cast<char*>(objects.data()), sizeof(GameObject) * size);
	readFile.close();


}

int main() {
	std::string fileName = "data.bin";
	std::vector<GameObject> objects = {
		('A', 10, 20),
		('B', 10, 20),
		('C', 10, 20)
	};
	SaveObjects(objects, fileName);

	std::vector<GameObject> objectsRecovered;
	RecoverObjects(objects, fileName);

	std::cout << "objtos Recuperados \n";
	for (int i = 0; i < objectsRecovered.size(); i++) {
		std::cout << "Type: " << objectsRecovered[i].type << ", X: " << objectsRecovered[i].x << ", Y: " << objectsRecovered[i].y << std::endl;
	}
}