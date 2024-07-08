// Función para mostrar el tablero
void mostrarTablero(char tablero[]) {
    cout << "   |   |   " << endl;
    cout << " " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << " " << endl;
    cout << "||_" << endl;
    cout << "   |   |   " << endl;
    cout << " " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << " " << endl;
    cout << "||_" << endl;
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