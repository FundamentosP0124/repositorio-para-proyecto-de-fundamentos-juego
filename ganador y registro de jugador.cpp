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