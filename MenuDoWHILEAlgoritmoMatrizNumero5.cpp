#include <iomanip>
#include <iostream>
#include <windows.h>
#define color SetConsoleTextAttribute

using namespace std;

int matriz[6][4];

void dibujarTablero();
void llenarMatriz();

int main() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int opcion = 0;

  do {
    cout << "1. Llenar matriz\n";
    cout << "2. Mostrar matriz\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
      llenarMatriz();
      break;
    case 2:
      dibujarTablero();
      break;
    case 3:
      cout << "Saliendo del programa...\n";
      break;
    }
  } while (opcion != 3);
}

void llenarMatriz() {

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      cout << "Ingrese dato [" << i << "][" << j << "]: ";
      cin >> matriz[i][j];
    }
  }
}

void dibujarTablero() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  cout << "\n    ";
  for (int j = 0; j < 4; j++) {
    cout << "   " << j << "    ";
  }
  cout << "\n    +";
  for (int j = 0; j < 4; j++) {
    cout << "-------+";
  }
  cout << "\n";

  for (int i = 0; i < 6; i++) {

    cout << "  " << i << " |";
    for (int j = 0; j < 4; j++) {

      bool esSombreado = (i == 0) or (j == 0 and i <= 3) or (i == 3) or
                         (i >= 3 and j == 3) or (i == 5);

      if (esSombreado) {
        color(hConsole, 2); // Verde
      } else {
        color(hConsole, 7); // Gris claro
      }
      cout << "  " << setw(2) << matriz[i][j] << "   ";
      color(hConsole, 7);
      cout << "|";
    }
    cout << "\n";

    cout << "    |";
    for (int j = 0; j < 4; j++) {

      bool esSombreado = (i == 0) or (j == 0 and i <= 3) or (i == 3) or
                         (i >= 3 and j == 3) or (i == 5);

      if (esSombreado) {
        color(hConsole, 2); // Verde
      } else {
        color(hConsole, 7); // Gris claro
      }
      cout << " [" << i << "," << j << "] ";
      color(hConsole, 7);
      cout << "|";
    }
    cout << "\n";

    cout << "    +";
    for (int j = 0; j < 4; j++) {
      cout << "-------+";
    }
    cout << "\n";
  }
  color(hConsole, 7);
}
