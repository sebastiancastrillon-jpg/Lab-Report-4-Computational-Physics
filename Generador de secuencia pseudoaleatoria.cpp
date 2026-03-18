#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
//Elegimos los parametros de la secuencia pseudoaleatoria
int c = 1;
int a = 4;
int M = 9;
int r_1 = 3;

// Creamos las listas donde se guardaran la secuencia pseudoaleatoria, la secuencia normalizada y la secuencia escalada
vector<int> secuencia;
vector<double> secuencia_normalizada;
vector<double> secuencia_escalada;

// Calculamos la secuencia pseudoaleatoria mas grande posible (Con 9 elementos)
int r_i = r_1;
secuencia.push_back(r_1); // Guardamos la semilla r_1 en la lista
do {
    r_i = (a * r_i + c) % M;
    if (r_i != r_1) {
        secuencia.push_back(r_i);
    }
} while (r_i != r_1); 

// Normalizamos la secuecncia pseudoaleatoria
for (int i = 0; i < secuencia.size(); i++) {
    double x_i = static_cast<double>(secuencia[i]) / M;
    secuencia_normalizada.push_back(x_i);
}
// Escalamos la secuencia a un rango de A = 10 a B = 20 
for (int i=0; i < secuencia_normalizada.size(); i++) {
    double y_i =  10 + (20 - 10) * secuencia_normalizada[i];
    secuencia_escalada.push_back(y_i);
}
// Imprimimos la secuencia original, la secuencia normalizada y la secuencia escalada

// Imprimmimos la cantidad total de terminos en la secuencia pseudoaleatoria
cout << "Cantidad total de terminos en la secuencia pseudoaleatoria: " << secuencia.size() << endl;

cout << "Secuencia original: ";
for (int i=0; i < secuencia.size(); i++) {
    cout << secuencia[i] << (i < secuencia.size() - 1 ? ", " : "\n");
}

cout << "Secuencia normalizada: ";
for (int i=0; i < secuencia_normalizada.size(); i++) {
    cout << secuencia_normalizada[i] << (i < secuencia_normalizada.size() - 1 ? ", " : "\n");
}

cout << "Secuencia escalada: ";
for (int i=0; i < secuencia_escalada.size(); i++) {
    cout << secuencia_escalada[i] << (i < secuencia_escalada.size() - 1 ? ", " : "\n");
}

// Guardamos la secuencia en un archivo csv para graficarlo en Python
ofstream archivo("secuencia_pseudoaleatoria.csv");
archivo << "Secuencia original, Secuencia Normalizada, Secuencia escalada"<< endl;
for (int i=0; i < secuencia_escalada.size(); i++) {
    archivo << secuencia[i] << "," 
            << secuencia_normalizada[i] << "," 
            << secuencia_escalada[i] << endl;
}
archivo.close();
return 0; 
}