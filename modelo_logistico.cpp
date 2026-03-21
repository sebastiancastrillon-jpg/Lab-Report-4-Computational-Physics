#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
//Elegimos los parametros del modelo caotico
double r = 4.0;
double xn = 0.4;

// Creamos las listas donde se guardaran los datos para 50 y 10000 iteraciones
vector<double> datos_50;
vector<double> datos_10000;

// Calculamos la secuencia para 50 iteraciones
for (int i = 0; i < 50; i++) {
    xn = r * xn * (1 - xn);
    datos_50.push_back(xn);
}

int N_50 = datos_50.size();

cout << "El valor aleatorio obtenido luego de 50 iteraciones es: " << datos_50[N_50 - 1] << endl;

// En primer lugar, calculamos el promedio para 50 iteraciones
double suma_50 = 0.0;
for (int i = 0; i < datos_50.size(); i++) {
    suma_50 = suma_50 + datos_50[i];
}
double x_mean_50 = suma_50 / N_50;

// Luego, la varianza para 50 iteraciones
double suma_varianza_50 = 0.0;
for (int i = 0; i < datos_50.size(); i++) {
    suma_varianza_50 = suma_varianza_50 + pow(datos_50[i] - x_mean_50, 2);
}
double varianza_50 = suma_varianza_50 / N_50;

// Finalmente, la asimetria para 50 iteraciones
double suma_asimetria_50 = 0.0;
for (int i = 0; i < datos_50.size(); i++) {
    suma_asimetria_50 = suma_asimetria_50 + pow((datos_50[i] - x_mean_50) / sqrt(varianza_50), 3);
}
double asimetria_50 = suma_asimetria_50 / N_50;

// Asi, imprimimos los valores estadisticos para 50 iteraciones
cout << "El valor promedio de los datos (50 iteraciones) es: " << x_mean_50 << endl;
cout << "El valor de varianza de los datos (50 iteraciones) es: " << varianza_50 << endl;
cout << "El valor de asimetria de los datos (50 iteraciones) es: " << asimetria_50 << endl;


// Ahora repetimos el procedimiento para 10000 iteraciones

r = 4.0;
xn = 0.4;

for (int i = 0; i < 10000; i++) {
    xn = r * xn * (1 - xn);
    datos_10000.push_back(xn);
}

int N_10000 = datos_10000.size();

cout << "El valor aleatorio obtenido luego de 10000 iteraciones es: " << datos_10000[N_10000 - 1] << endl;

// Calculamos el promedio para 10000 iteraciones
double suma_10000 = 0.0;
for (int i = 0; i < datos_10000.size(); i++) {
    suma_10000 = suma_10000 + datos_10000[i];
}
double x_mean_10000 = suma_10000 / N_10000;

// Calculamos la varianza para 10000 iteraciones
double suma_varianza_10000 = 0.0;
for (int i = 0; i < datos_10000.size(); i++) {
    suma_varianza_10000 = suma_varianza_10000 + pow(datos_10000[i] - x_mean_10000, 2);
}
double varianza_10000 = suma_varianza_10000 / N_10000;

// Calculamos la asimetria para 10000 iteraciones
double suma_asimetria_10000 = 0.0;
for (int i = 0; i < datos_10000.size(); i++) {
    suma_asimetria_10000 = suma_asimetria_10000 + pow((datos_10000[i] - x_mean_10000) / sqrt(varianza_10000), 3);
}
double asimetria_10000 = suma_asimetria_10000 / N_10000;

// Asi, imprimimos los valores estadisticos para 10000 iteraciones
cout << "El valor promedio de los datos (10000 iteraciones) es: " << x_mean_10000 << endl;
cout << "El valor de varianza de los datos (10000 iteraciones) es: " << varianza_10000 << endl;
cout << "El valor de asimetria de los datos (10000 iteraciones) es: " << asimetria_10000 << endl;


// Guardamos las secuencias en un archivo csv para graficarlas en Python
ofstream archivo("datos_mapeo_logistico.csv");
archivo << "Datos 50 iteraciones,Datos 10000 iteraciones" << endl;

for (int i = 0; i < datos_10000.size(); i++) {
    if (i < datos_50.size()) {
        archivo << datos_50[i] << "," << datos_10000[i] << endl;
    } else {
        archivo << "," << datos_10000[i] << endl;
    }
}

archivo.close();
return 0;
}
