#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <windows.h>        
#define color SetConsoleTextAttribute 
#include <random>

using namespace std;

int matrizR[5][4];
int matrizNumero5[5][3];

void dibujarTablero(int tablero[5][4]);
void dibujarTableroConResaltado(int tablero[5][4], bool resaltados[5][4]);
void NumeroEntre15y20();
void PromedioNumerosPares();
void PenultimoMenor();
void mostarMatriz();
void llenarMatriz();
void llenarMatrizNumero5();
void dibujarTableroNumero5();

int main() {
    int opcion = 0;

    do {
        cout << "1. Llenar matriz Letra R" << endl;
        cout << "2. Llenar matriz Numero 5" << endl;
        cout << "3. Mostrar Matriz R" << endl;
        cout << "4. Mostrar Matriz Numero 5" << endl;
        cout << "5. Numeros Entre 15 y 20 dentro de la Matriz Letra R" << endl;
        cout << "6. Penultimo Menor dentro de la matriz Letra R" << endl;
        cout << "7. Promedio numeros pares dentro de la matriz Letra R" << endl;
        cout << "8. Salir del menu" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            llenarMatriz();
            cout << "Matriz R llenada con exito.\n" << endl;
            break;
        case 2:
            llenarMatrizNumero5();
            cout << "Matriz Numero 5 llenada con exito.\n" << endl;
            break;
        case 3:
            dibujarTablero(matrizR);
            break;
        case 4:
            dibujarTableroNumero5();
            break;
        case 5:
            NumeroEntre15y20();
            break;
        case 6:
            PenultimoMenor();
            break;
        case 7:
            PromedioNumerosPares();
            break;
        case 8:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida.\n" << endl;
            break;
        }
    } while (opcion != 8);

    return 0;
}

void dibujarTablero(int tablero[5][4]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "    ";
    for (int j = 0; j < 4; j++) {
        cout << "   " << j << "    ";
    }
    cout << "\n    +";
    for (int j = 0; j < 4; j++) {
        cout << "-------+";
    }
    cout << "\n";

    for (int i = 0; i < 5; i++) {
        cout << "  " << i << " |";
        for (int j = 0; j < 4; j++) {
            bool esSombreado = (j==0)||(i==0 && j<=2)||(i==1 && j==3)||(i==2 && j<=2)||(i==3 && j==2)||(i==4 && j==3);

            if (esSombreado) {
                color(hConsole, 2); 
            } else {
                color(hConsole, 7); 
            }
            cout << "  " << setw(2) << tablero[i][j] << "   ";
            color(hConsole, 7);
            cout << "|";
        }
        cout << "\n    |";

        for (int j = 0; j < 4; j++) {
            bool esSombreado = (j==0)||(i==0 && j<=2)||(i==1 && j==3)||(i==2 && j<=2)||(i==3 && j==2)||(i==4 && j==3);

            if (esSombreado) {
                color(hConsole, 2); 
            } else {
                color(hConsole, 7); 
            }
            cout << " [" << i << "," << j << "] ";
            color(hConsole, 7);
            cout << "|";
        }
        cout << "\n    +";
        for (int j = 0; j < 4; j++) {
            cout << "-------+";
        }
        cout << "\n";
    }
    color(hConsole, 7);
}

void dibujarTableroConResaltado(int tablero[5][4], bool resaltados[5][4]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "    ";
    for (int j = 0; j < 4; j++) {
        cout << "   " << j << "    ";
    }
    cout << "\n    +";
    for (int j = 0; j < 4; j++) {
        cout << "-------+";
    }
    cout << "\n";

    for (int i = 0; i < 5; i++) {
        cout << "  " << i << " |";
        for (int j = 0; j < 4; j++) {
            if (resaltados[i][j]) {
                color(hConsole, 3); 
            } else {
                color(hConsole, 7); 
            }
            cout << "  " << setw(2) << tablero[i][j] << "   ";
            color(hConsole, 7);
            cout << "|";
        }
        cout << "\n    |";

        for (int j = 0; j < 4; j++) {
            if (resaltados[i][j]) {
                color(hConsole, 3);
            } else {
                color(hConsole, 7);
            }
            cout << " [" << i << "," << j << "] ";
            color(hConsole, 7);
            cout << "|";
        }
        cout << "\n    +";
        for (int j = 0; j < 4; j++) {
            cout << "-------+";
        }
        cout << "\n";
    }
    color(hConsole, 7);
}

void NumeroEntre15y20() {
    int contadorentre15y20 = 0;
    bool matrizResaltada[5][4] = {false};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrizR[i][j] >= 15 && matrizR[i][j] <= 20) {
                contadorentre15y20++;
                matrizResaltada[i][j] = true; 
            }
        }
    }

    cout << "Hay " << contadorentre15y20 << " numeros entre el 15 y el 20 en esta matriz:\n" << endl;
    dibujarTableroConResaltado(matrizR, matrizResaltada);
    cout << endl;
}

void PromedioNumerosPares() {
    int contadorPares = 0;
    int promedio = 0;
    int acumuladorPares = 0;
    bool matrizResaltada[5][4] = {false};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrizR[i][j] % 2 == 0) {
                acumuladorPares += matrizR[i][j];
                contadorPares++;
                matrizResaltada[i][j] = true; 
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

    dibujarTableroConResaltado(matrizR, matrizResaltada);
    cout << endl;
}

void PenultimoMenor() {
    int menor = 999;
    int penultimo = 999;
    bool matrizResaltada[5][4] = {false};

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

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrizR[i][j] == penultimo) {
                matrizResaltada[i][j] = true;
            }
        }
    }

    if (penultimo == 999) {
        cout << "No se encontro un penultimo menor valido." << endl;
    } else {
        cout << penultimo << " es el penultimo menor" << endl;
    }
    cout << endl;

    dibujarTableroConResaltado(matrizR, matrizResaltada);
    cout << endl;
}

void mostarMatriz() {
    bool esSombreado = false;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            esSombreado = (j == 0) || (i == 0 && j <= 3) || (j == 3 && i <= 2) ||
                          (i == 2 && j <= 2) || (i == 3 && j == 2) ||
                          (i == 4 && j == 3);

            if (esSombreado) {
                color(hConsole, 2); 
            } else {
                color(hConsole, 7); 
            }
            cout << matrizR[i][j] << "  ";
        }
        cout << "\n";
    }
    color(hConsole, 7);
}

void llenarMatriz() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 100);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            matrizR[i][j] = distrib(gen);
        }
    }
}

void dibujarTableroNumero5() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "\n    ";
    for (int j = 0; j < 3; j++) {
        cout << "   " << j << "    ";
    }
    cout << "\n    +";
    for (int j = 0; j < 3; j++) {
        cout << "-------+";
    }
    cout << "\n";

    for (int i = 0; i < 5; i++) {
        cout << "  " << i << " |";
        for (int j = 0; j < 3; j++) {
            bool esSombreado = (i == 0) or (j == 0 and i <= 2) or (i == 2) or
                               (i >= 2 and j == 2) or (i == 4);

            if (esSombreado) {
                color(hConsole, 2); 
            } else {
                color(hConsole, 7); 
            }
            cout << "  " << setw(2) << matrizNumero5[i][j] << "   ";
            color(hConsole, 7);
            cout << "|";
        }
        cout << "\n    |";

        for (int j = 0; j < 3; j++) {
            bool esSombreado = (i == 0) or (j == 0 and i <= 2) or (i == 2) or
                               (i >= 2 and j == 2) or (i == 4);

            if (esSombreado) {
                color(hConsole, 2); 
            } else {
                color(hConsole, 7); 
            }
            cout << " [" << i << "," << j << "] ";
            color(hConsole, 7);
            cout << "|";
        }
        cout << "\n    +";
        for (int j = 0; j < 3; j++) {
            cout << "-------+";
        }
        cout << "\n";
    }
    color(hConsole, 7);
}

void llenarMatrizNumero5() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 100);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            matrizNumero5[i][j] = distrib(gen);
        }
    }
}
