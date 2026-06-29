#include <stdio.h>
#include <stdint.h>

int main() {

    // Parámetros del RNG
    uint64_t a = 0x5DEECE66DULL;
    uint64_t c = 0xBULL;

    // M = 2^48
    uint64_t M = (1ULL << 48);

    // Semilla
    uint64_t r = 10;

    // Cantidad de números
    int N = 10000;

    // Archivo
    FILE *file = fopen("rng48.txt", "w");

    if(file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Generar números
    for(int i = 0; i < N; i++) {

        r = (a * r + c) % M;

        // Normalización entre 0 y 1
        double u = (double)r / (double)M;

        fprintf(file, "%lf\n", u);
    }

    fclose(file);

    printf("Numbers saved in rng48.txt\n");

    return 0;
}