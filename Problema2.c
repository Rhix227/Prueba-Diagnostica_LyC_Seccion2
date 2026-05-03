#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Valida una sola fila del tablero
int validarFila(char *fila)
{
    int count = 0;
    for (int i = 0; fila[i]; i++)
    {
        if (isdigit(fila[i]))// Si el carácter actual es un número
            count += fila[i] - '0';
        else if (strchr("rnbqkpRNBQKP", fila[i]))//Si no es número, busca si el carácter pertenece a la lista válida de piezas de ajedrez
            count++;
        else //Si encuentra un carácter extraño, la fila es inválida inmediatamente
            return 0;
    }
    return count == 8;
}

//Separa y valida la estructura general
int validarFEN(const char *fen)
{
    char copia[128];
    strcpy(copia, fen);

    char *campos[6];//Arreglo para guardar los 6 campos que exige la notación FEN oficial
    int i = 0;
    char *token = strtok(copia, " ");
    while (token && i < 6)
    {
        campos[i++] = token;
        token = strtok(NULL, " ");
    }
    if (i != 6)//Si no encontró exactamente 6 partes separadas por espacios, la cadena no es un FEN válido
        return 0;

    char tablero[128];//Toma el primer campo y lo copia para analizarlo por separado
    strcpy(tablero, campos[0]);
    char *fila = strtok(tablero, "/");
    int filas = 0;
    while (fila)
    {
        if (!validarFila(fila))//Le pasa esa fila a la función validarFila. Si esa función dice que es inválida (0), todo el FEN falla y retorna 0
            return 0;
        filas++;
        fila = strtok(NULL, "/");
    }
    return filas == 8;
}

//Ejecucion Principal
int main()
{
    char fen[128];
    printf("Ingrese la cadena FEN: ");
    fgets(fen, sizeof(fen), stdin);
    fen[strcspn(fen, "\n")] = 0;

    if (validarFEN(fen))
        printf(" La cadena esta en notacion FEN valida.\n");
    else
        printf(" Cadena FEN invalida.\n");

    return 0;
}