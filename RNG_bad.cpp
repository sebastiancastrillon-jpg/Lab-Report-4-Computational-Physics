# include <iostream>
#include <fstream>

int main () {
    // Parámetros del RNG
    int a = 57;
    int c = 1;
    int M = 256;

    // Semilla inicial
    int r = 10;

    // Cantidad de números a generar
    int N = 200;

     // Crear archivo
    std::ofstream file("random_numbers_bad.txt");

    // Verificar apertura
    if(!file) {
        std::cout << "Error opening file\n";
        return 1;
    }

    // Generar números
    for(int i = 0; i < N; i++) {

        r = (a * r + c) % M;

        double u = double(r)/M;

        file << u << '\n';
    }

    // Cerrar archivo
    file.close();

    std::cout << "Data saved in random_numbers.txt\n";

    return 0;
} 