#include <iostream>
#include <fstream>
#include <random>

int main() {

    // Generador Mersenne Twister
    std::mt19937 rng(42);

    // Distribución uniforme entre 0 y 1
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // Cantidad de números
    int N = 10000;

    // Archivo de salida
    std::ofstream file("mt_random.txt");

    if(!file) {
        std::cout << "Error opening file\n";
        return 1;
    }

    // Generar números
    for(int i = 0; i < N; i++) {

        double r = dist(rng);

        file << r << '\n';
    }

    file.close();

    std::cout << "Random numbers saved in mt_random.txt\n";

    return 0;
}