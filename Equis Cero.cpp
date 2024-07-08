#include <iostream>
using namespace std;

// Función para mostrar el tablero
void mostrarTablero(char tablero[]) {
    cout << "   |   |   " << endl;
    cout << " " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << " " << endl;
    cout << "_|_|_" << endl;
    cout << "   |   |   " << endl;
    cout << " " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << " " << endl;
    cout << "_|_|_" << endl;
    cout << "   |   |   " << endl;
    cout << " " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << " " << endl;
    cout << "   |   |   " << endl << endl;
}

// Función para verificar si hay un ganador o empate
char verificarGanador(char tablero[]) {
    // Combinaciones ganadoras en el tablero
    int combinacionesGanadoras[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // filas
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columnas
        {0, 4, 8}, {2, 4, 6}              // diagonales
    };

    // Verificar cada combinación para determinar el ganador
    for (int i = 0; i < 8; ++i) {
        if (tablero[combinacionesGanadoras[i][0]] != ' ' &&
            tablero[combinacionesGanadoras[i][0]] == tablero[combinacionesGanadoras[i][1]] &&
            tablero[combinacionesGanadoras[i][1]] == tablero[combinacionesGanadoras[i][2]]) {
            return tablero[combinacionesGanadoras[i][0]]; // Retorna 'X' o 'O' si hay ganador
        }
    }

    // Si no hay ganador y el tablero está lleno, es empate
    for (int i = 0; i < 9; ++i) {
        if (tablero[i] == ' ') {
            return ' '; // Aún hay casillas vacías, el juego continúa
        }
    }

    return 'T'; // Si no hay casillas vacías, es un empate
}

int main() {
    char tablero[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int turno = 0;
    char jugador1[20], jugador2[20];
    char jugadorActual = 'X';
    int posicion;

    cout << "* Juego de Equis-Cero *" << endl << endl;

    // Ingresar nombres de jugadores
    cout << "Ingrese el nombre del jugador 1 (X): ";
    cin.getline(jugador1, 20);

    cout << "Ingrese el nombre del jugador 2 (O): ";
    cin.getline(jugador2, 20);

    // Registro de jugadores
    cout << endl << "Registro de jugadores:" << endl;
    cout << "Jugador 1 (X): " << jugador1 << endl;
    cout << "Jugador 2 (O): " << jugador2 << endl << endl;

    do {
        mostrarTablero(tablero);
        
        // Determinar el jugador actual ('X' o 'O')
        jugadorActual = (turno % 2 == 0) ? 'X' : 'O';

        // Solicitar y validar la posición
        do {
            cout << "Turno de " << ((jugadorActual == 'X') ? jugador1 : jugador2) << " (" << jugadorActual << ")" << endl;
            cout << "Ingrese una posición (1-9): ";
            cin >> posicion;
            posicion--; // Ajustar posición para el arreglo (de 1-9 a 0-8)
        } while (posicion < 0 || posicion > 8 || tablero[posicion] != ' ');

        // Colocar la marca en el tablero
        tablero[posicion] = jugadorActual;

        // Verificar si hay un ganador
        char resultado = verificarGanador(tablero);

        // Incrementar turno
        turno++;
        
        // Mostrar mensaje según el resultado
        if (resultado == 'X' || resultado == 'O') {
            mostrarTablero(tablero);
            cout << "¡Felicidades " << ((resultado == 'X') ? jugador1 : jugador2) << " (" << resultado << ") ha ganado!" << endl;
            break;
        } else if (resultado == 'T') {
            mostrarTablero(tablero);
            cout << "¡Es un empate!" << endl;
            break;
        }

    } while (true);

    cout << "Gracias por jugar." << endl;
    cout << "Creado por: " << endl;
    cout << "Allison Andrea Romero Vasquez 00107924" << endl;
    cout << "Miguel Alexander Mejia Reyes 00009324" << endl;
    cout << "Elvis Alexander Salguero Galan 00167624" << endl;
    return 0;
}