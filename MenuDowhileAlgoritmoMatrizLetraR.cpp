#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <windows.h>                  //Libreria para los colores
#define color SetConsoleTextAttribute // Definición de Variable

using namespace std;

const int MAX = 5;
int matrizR[5][5];
void dibujarTablero(int tablero[MAX][MAX], int tam);
void NumeroEntre15y20();
void PromedioNumerosPares();
void PenultimoMenor();
void mostarMatriz();
void llenarMatriz();

int main() {

  int opcion = 0;

  do {
    cout << "1.llenar matriz" << endl;
    cout << "2.mostrar matriz" << endl;
    cout << "3.numeros entre 15 y 20" << endl;
    cout << "4.promedio de los numeros pares" << endl;
    cout << "5.penultimo menor" << endl;
    cout << "6.salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
      llenarMatriz();
      break;
    case 2:
      dibujarTablero(matrizR, MAX);
      break;
    case 3:
      NumeroEntre15y20();
      break;
    case 4:
      PromedioNumerosPares();
      break;
    case 5:
      PenultimoMenor();
      break;
    case 6:
      break;
    default:
      break;
    }
  } while (opcion != 6);

  return 0;
}

void dibujarTablero(int tablero[MAX][MAX], int tam) {

  cout << "    ";
  for (int j = 0; j < tam; j++) {
    cout << "   " << j << "    ";
  }
  cout << "\n";

  cout << "    +";
  for (int j = 0; j < tam; j++) {
    cout << "-------+";
  }
  cout << "\n";

  for (int i = 0; i < tam; i++) {

    cout << "  " << i << " |";
    for (int j = 0; j < tam; j++) {
      cout << "  " << setw(2) << tablero[i][j] << "   |";
    }
    cout << "\n";

    cout << "    |";
    for (int j = 0; j < tam; j++) {
      cout << " [" << i << "," << j << "] |";
    }
    cout << "\n";

    cout << "    +";
    for (int j = 0; j < tam; j++) {
      cout << "-------+";
    }
    cout << "\n";
  }
}

void NumeroEntre15y20() {
  int contadorentre15y20 = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (matrizR[i][j] >= 15 && matrizR[i][j] <= 20) {
        contadorentre15y20++;
      }
    }
  }
  cout << " hay " << contadorentre15y20
       << " numeros entre el 15 y el 20 en esta matriz" << endl;
  cout << endl;
}

void PromedioNumerosPares() {
  int contadorPares = 0;
  int promedio = 0;
  int acumuladorPares = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (matrizR[i][j] % 2 == 0) {
        acumuladorPares = acumuladorPares + matrizR[i][j];
        contadorPares = contadorPares + 1;
      }
    }
  }
  promedio = acumuladorPares / contadorPares;
  cout << "Promedio de los numeros pares: " << promedio << endl;
  cout << endl;
}

void PenultimoMenor() {
  int menor = 999;
  int penultimo = 999;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (matrizR[i][j] < menor) {
        penultimo = menor;
        menor = matrizR[i][j];
      } else if (matrizR[i][j] < penultimo && matrizR[i][j] != menor) {
        penultimo = matrizR[i][j];
      }
    }
  }

  cout << penultimo << " es el penultimo menor" << endl;
  cout << endl;
}

void mostarMatriz() {
  const int filas = 5;
  const int columnas = 5;
  int matriz[filas][columnas];

  bool esSombreado = false;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Llamar Función
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      esSombreado = (i == j) || (i + j == filas - 1);

      if (esSombreado) {
        color(hConsole, 2); //  Color  Verde
      } else {
        color(hConsole, 7); //  Color Gris Claro
      }
      cout << matriz[i][j] << "  ";
    }
    cout << "\n";
  }

  for (int pintar = 1; pintar < 255; pintar++) {
    color(hConsole, pintar);
    cout << pintar << ": \nEste es el color..";
    if (pintar % 50 == 0) {
      system("PAUSE");
    }
  }
}
void llenarMatriz() {
  int dato = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << "ingrese datos" << "[" << i << "," << j << "]:";
      cin >> dato;
      matrizR[i][j] = dato;
    }
  }
}