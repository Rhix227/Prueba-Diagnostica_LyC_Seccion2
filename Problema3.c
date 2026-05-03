#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Diccionario de traducciones 
//Crea un arreglo de cadenas con palabras reservadas
const char* keywords[] = {"int", "float", "return", "if", "else", "while", "for", "void", "char"};
//Crea un arreglo paralelo con las traducciones exactas
const char* traducciones[] = {"entero", "flotante", "retornar", "si", "sino", "mientras", "para", "vacio", "caracter"};
#define NUM_KEYWORDS 9

//Funcion de traduccion
//Esta función recibe una palabra extraída del archivo 
const char* traducir_palabra(const char* palabra) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(palabra, keywords[i]) == 0) { //Compara la palabra actual con la palabra reservada en la posición
            return traducciones[i];
        }
    }
    return palabra; // Si no es reservada, la deja igual
}

//Fun.Princ y apertura de archivos
int main() {
    FILE *archivo = fopen("codigo_prueba.c", "r");
    if (!archivo) { //Es una validación de seguridad. Si el archivo no existe o no hay permisos
        printf("Error: No se pudo abrir codigo_prueba.c\n");
        return 1;
    }

    // 1. Cargar programa en memoria de forma dinámica
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);

    char *buffer = (char*)malloc(tamano + 1);
    if (!buffer) return 1;
    fread(buffer, 1, tamano, archivo);
    buffer[tamano] = '\0';
    fclose(archivo);

    // 2. Analizar y traducir palabras
    printf("--- CODIGO TRADUCIDO ---\n");
    char palabra[100];
    int p_idx = 0;
    
    for (long i = 0; i <= tamano; i++) {
        if (isalpha(buffer[i]) || buffer[i] == '_') {
            palabra[p_idx++] = buffer[i];
        } else {
            if (p_idx > 0) {
                palabra[p_idx] = '\0';
                printf("%s", traducir_palabra(palabra));
                p_idx = 0;
            }
            if (buffer[i] != '\0') {
                putchar(buffer[i]); // Imprimir simbolos y espacios
            }
        }
    }
    printf("\n");

    free(buffer); // Liberar memoria dinámica
    return 0;
}