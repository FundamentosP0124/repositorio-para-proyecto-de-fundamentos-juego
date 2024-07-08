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