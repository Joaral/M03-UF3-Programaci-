#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void Ex10() {
    std::ofstream fitxer("numeros.dat", std::ios::binary | std::ios::trunc);

    if (!fitxer) {
        std::cout << "Error en obrir el fitxer." << std::endl;
        return;
    }

    int numeros[5];

    std::cout << "Introdueix 5 numeros enters:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Numero " << (i + 1) << ": ";
        std::cin >> numeros[i];
    }

    fitxer.write(reinterpret_cast<char*>(numeros), sizeof(numeros));
    fitxer.close();

    std::cout << "Els numeros s'han desat correctament a 'numeros.dat'." << std::endl;
}

void Ex11() {
    std::ifstream fitxer("numeros.dat", std::ios::binary);

    if (!fitxer) {
        std::cout << "Error en obrir el fitxer." << std::endl;
        return;
    }

    int numeros[5];
    fitxer.read(reinterpret_cast<char*>(numeros), sizeof(numeros));
    fitxer.close();

    std::cout << "Els numeros llegits del fitxer son:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Numero " << (i + 1) << ": " << numeros[i] << std::endl;
    }
}

void Ex12() {
    std::vector<std::string> frases;
    std::string entrada;

    std::cout << "Introdueix frases (introdueix una línia buida per acabar):" << std::endl;
    while (true) {
        std::getline(std::cin, entrada);
        if (entrada.empty()) break;
        frases.push_back(entrada);
    }

    std::ofstream fitxerEscriptura("frases.dat", std::ios::binary | std::ios::trunc);
    if (!fitxerEscriptura) {
        std::cout << "Error en obrir el fitxer per escriure." << std::endl;
        return;
    }

    size_t mida = frases.size();
    fitxerEscriptura.write(reinterpret_cast<const char*>(&mida), sizeof(mida));
    for (const auto& frase : frases) {
        mida = frase.size();
        fitxerEscriptura.write(reinterpret_cast<const char*>(&mida), sizeof(mida));
        fitxerEscriptura.write(frase.c_str(), mida);
    }
    fitxerEscriptura.close();

    std::ifstream fitxerLectura("frases.dat", std::ios::binary);
    if (!fitxerLectura) {
        std::cout << "Error en obrir el fitxer per llegir." << std::endl;
        return;
    }

    size_t numFrases;
    fitxerLectura.read(reinterpret_cast<char*>(&numFrases), sizeof(numFrases));
    frases.resize(numFrases);
    for (size_t i = 0; i < numFrases; i++) {
        fitxerLectura.read(reinterpret_cast<char*>(&mida), sizeof(mida));
        frases[i].resize(mida);
        fitxerLectura.read(&frases[i][0], mida);
    }
    fitxerLectura.close();

    std::cout << "Frases llegides del fitxer:" << std::endl;
    for (const auto& frase : frases) {
        std::cout << frase << std::endl;
    }
}

void Ex13() {
    std::ifstream fitxerEntrada("numeros.dat", std::ios::binary);
    if (!fitxerEntrada) {
        std::cout << "Error en obrir el fitxer d'entrada." << std::endl;
        return;
    }

    std::vector<int> numeros;
    int num;
    while (fitxerEntrada.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        numeros.push_back(num * 2);
    }
    fitxerEntrada.close();

    std::ofstream fitxerSortida("resultats.dat", std::ios::binary | std::ios::trunc);
    if (!fitxerSortida) {
        std::cout << "Error en obrir el fitxer de sortida." << std::endl;
        return;
    }

    for (int n : numeros) {
        fitxerSortida.write(reinterpret_cast<const char*>(&n), sizeof(n));
    }
    fitxerSortida.close();

    std::cout << "S'han processat " << numeros.size() << " valors." << std::endl;
}
