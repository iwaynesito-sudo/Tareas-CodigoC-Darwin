#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <windows.h>                  //Libreria para los colores
#define color SetConsoleTextAttribute // Definicion de Variable

using namespace std;

int matrizR[5][4];

void dibujarTablero(int tablero[5][4]);
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
      dibujarTablero(matrizR);
      cout << endl;
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
}

void dibujarTablero(int tablero[5][4]) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Llamar Funcion

  cout << "    ";
  for (int j = 0; j < 4; j++) {
    cout << "   " << j << "    ";
  }
  cout << "\n";

  cout << "    +";
  for (int j = 0; j < 4; j++) {
    cout << "-------+";
  }
  cout << "\n";

  for (int i = 0; i < 5; i++) {

    cout << "  " << i << " |";
    for (int j = 0; j < 4; j++) {
      bool esSombreado = (j == 0) || (i == 0 && j <= 3) || (j == 3 && i <= 2) ||
                         (i == 2 && j <= 2) || (i == 3 && j == 2) ||
                         (i == 4 && j == 3);

      if (esSombreado) {
        color(hConsole, 2); //  Color Verde
      } else {
        color(hConsole, 7); //  Color Gris Claro
      }
      cout << "  " << setw(2) << tablero[i][j] << "   ";
      color(hConsole, 7); // Restaurar color de la linea divisoria
      cout << "|";
    }
    cout << "\n";

    cout << "    |";
    for (int j = 0; j < 4; j++) {
      bool esSombreado = (j == 0) || (i == 0 && j <= 3) || (j == 3 && i <= 2) ||
                         (i == 2 && j <= 2) || (i == 3 && j == 2) ||
                         (i == 4 && j == 3);

      if (esSombreado) {
        color(hConsole, 2); //  Color Verde
      } else {
        color(hConsole, 7); //  Color Gris Claro
      }
      cout << " [" << i << "," << j << "] ";
      color(hConsole, 7); // Restaurar color de la linea divisoria
      cout << "|";
    }
    cout << "\n";

    cout << "    +";
    for (int j = 0; j < 4; j++) {
      cout << "-------+";
    }
    cout << "\n";
  }
  color(hConsole, 7); // Restaurar color por defecto
}

void NumeroEntre15y20() {
  int contadorentre15y20 = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
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
    for (int j = 0; j < 4; j++) {
      if (matrizR[i][j] % 2 == 0) {
        acumuladorPares = acumuladorPares + matrizR[i][j];
        contadorPares = contadorPares + 1;
      }
    }
  }
  if (contadorPares > 0) {
    promedio = acumuladorPares / contadorPares;
    cout << "Promedio de los numeros pares: " << promedio << endl;
  } else {
    cout << "No hay numeros pares en la matriz" << endl;
  }
  cout << endl;
}

void PenultimoMenor() {
  int menor = 999;
  int penultimo = 999;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
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
  bool esSombreado = false;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Llamar Funcion

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      esSombreado = (j == 0) || (i == 0 && j <= 3) || (j == 3 && i <= 2) ||
                    (i == 2 && j <= 2) || (i == 3 && j == 2) ||
                    (i == 4 && j == 3);

      if (esSombreado) {
        color(hConsole, 2); //  Color Verde
      } else {
        color(hConsole, 7); //  Color Gris Claro
      }
      cout << matrizR[i][j] << "  ";
    }
    cout << "\n";
  }
  color(hConsole, 7); // Restaurar color por defecto
}

void llenarMatriz() {
  int dato = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      cout << "ingrese datos" << "[" << i << "," << j << "]:";
      cin >> dato;
      matrizR[i][j] = dato;
    }
  }
}