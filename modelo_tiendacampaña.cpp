#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
//Elegimos los parametros del modelo caotico
double miu = 2.0;
double xn = 0.371234;

// Creamos las listas donde se guardaran los datos para 40, 100 y 10000 iteraciones
vector<double> datos_40;
vector<double> datos_100;
vector<double> datos_10000;

// Calculamos la secuencia para 40 iteraciones
for (int i = 0; i < 40; i++) {
    if (xn < 0.5) {
        xn = miu * xn;
    } else {
        xn = miu * (1 - xn);
    }
    datos_40.push_back(xn);
}

int N_40 = datos_40.size();
cout << "El valor aleatorio obtenido luego de 40 iteraciones es: " << datos_40[N_40 - 1] << endl;

// En primer lugar, calculamos el promedio para 40 iteraciones
double suma_40 = 0.0;
for (int i = 0; i < datos_40.size(); i++) {
    suma_40 = suma_40 + datos_40[i];
}
double x_mean_40 = suma_40 / N_40;

// Luego, la varianza para 40 iteraciones
double suma_varianza_40 = 0.0;
for (int i = 0; i < datos_40.size(); i++) {
    suma_varianza_40 = suma_varianza_40 + pow(datos_40[i] - x_mean_40, 2);
}
double varianza_40 = suma_varianza_40 / N_40;

// Finalmente, la asimetria para 40 iteraciones
double suma_asimetria_40 = 0.0;
for (int i = 0; i < datos_40.size(); i++) {
    suma_asimetria_40 = suma_asimetria_40 + pow((datos_40[i] - x_mean_40) / sqrt(varianza_40), 3);
}
double asimetria_40 = suma_asimetria_40 / N_40;

// Asi, imprimimos los valores estadisticos para 40 iteraciones
cout << "El valor promedio de los datos para 40 iteraciones es: " << x_mean_40 << endl;
cout << "El valor de varianza de los datos para 40 iteraciones es: " << varianza_40 << endl;
cout << "El valor de asimetria de los datos para 40 iteraciones es: " << asimetria_40 << endl;


// En segunda instancia, repetimos el procedimiento para 100 iteraciones

miu = 2.0;
xn = 0.371234;

for (int i = 0; i < 100; i++) {
    if (xn < 0.5) {
        xn = miu * xn;
    } else {
        xn = miu * (1 - xn);
    }
    datos_100.push_back(xn);
}

int N_100 = datos_100.size();
cout << "El valor aleatorio obtenido luego de 100 iteraciones es: " << datos_100[N_100 - 1] << endl;

// Calculamos el promedio para 100 iteraciones
double suma_100 = 0.0;
for (int i = 0; i < datos_100.size(); i++) {
    suma_100 = suma_100 + datos_100[i];
}
double x_mean_100 = suma_100 / N_100;

// Calculamos la varianza para 100 iteraciones
double suma_varianza_100 = 0.0;
for (int i = 0; i < datos_100.size(); i++) {
    suma_varianza_100 = suma_varianza_100 + pow(datos_100[i] - x_mean_100, 2);
}
double varianza_100 = suma_varianza_100 / N_100;

// Calculamos la asimetria para 100 iteraciones
double suma_asimetria_100 = 0.0;
for (int i = 0; i < datos_100.size(); i++) {
    suma_asimetria_100 = suma_asimetria_100 + pow((datos_100[i] - x_mean_100) / sqrt(varianza_100), 3);
}
double asimetria_100 = suma_asimetria_100 / N_100;

// Asi, imprimimos los valores estadisticos para 100 iteraciones
cout << "El valor promedio de los datos para 100 iteraciones es: " << x_mean_100 << endl;
cout << "El valor de varianza de los datos para 100 iteraciones es: " << varianza_100 << endl;
cout << "El valor de asimetria de los datos para 100 iteraciones es: " << asimetria_100 << endl;


// En tercera instancia, repetimos el procedimiento para 10000 iteraciones

miu = 2.0;
xn = 0.371234;

for (int i = 0; i < 10000; i++) {
    if (xn < 0.5) {
        xn = miu * xn;
    } else {
        xn = miu * (1 - xn);
    }
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
cout << "El valor promedio de los datos para 10000 iteraciones es: " << x_mean_10000 << endl;
cout << "El valor de varianza de los datos para 10000 iteraciones es: " << varianza_10000 << endl;
cout << "El valor de asimetria de los datos para 10000 iteraciones es: " << asimetria_10000 << endl;


// Guardamos las secuencias en un archivo csv para graficarlas en Python
ofstream archivo("datos_mapeo_tienda_campana.csv");
archivo << "Datos 40 iteraciones,Datos 100 iteraciones,Datos 10000 iteraciones" << endl;

for (int i = 0; i < datos_10000.size(); i++) {
    if (i < datos_40.size() && i < datos_100.size()) {
        archivo << datos_40[i] << "," << datos_100[i] << "," << datos_10000[i] << endl;
    } else if (i < datos_100.size()) {
        archivo << "," << datos_100[i] << "," << datos_10000[i] << endl;
    } else {
        archivo << ",," << datos_10000[i] << endl;
    }
}

archivo.close();
return 0;
}