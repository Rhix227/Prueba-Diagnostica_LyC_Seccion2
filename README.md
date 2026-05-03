Problema 1: Polinomios y Triángulo de Pascal

Archivos Incluidos

•	Problema1.LenguajeC: Código fuente de la implementación en lenguaje C.
•	Problame2.LenguajePy: Código fuente de la implementación en lenguaje Python.

Requisitos Previos (Dependencias)

•	Para C: Para compilar y ejecutar la solución en C++, utilice un compilador como g++
•	Para Python:Para ejecutar la solución en Python, asegúrese de tener instalado Python 3.x

Instrucciones de Compilación y Ejecución

1.	Implementacion en C: g++ solucion.cpp -o solucion ./solucion
2.	Implementacion en Python: python solucion_polinomio.py

Problema 2: Validador de Notación FEN (Forsyth-Edwards Notation)

Requisitos Previos (Dependencias)

•	Un compilador de lenguaje C

Instrucciones de Compilación y Ejecución

Dado que es un código fuente en C estándar, no requiere de scripts complejos de instalación, pero puede ser construido y ejecutado mediante los siguientes comandos en la terminal:
1.	Compilación Abra la terminal en el directorio problema2 y ejecute: bash gcc -o validador_fen validador_fen.c
	
Problema 3: Traductor de Palabras Reservadas en C

Ejecución
1.	Asegúrese de que codigo_prueba esté en el mismo directorio.
2.	Compile y ejecute: gcc traductor.c -o traductor ./traductor`
Explicación El programa utiliza fseek() y ftell() para conocer el tamaño exacto del archivo fuente. Luego se utiliza malloc() para alojar ese volumen de caracteres exactamente en la memoria dinámica. El programa recorre este bloque aislando cadenas alfanuméricas, y compara cada una contra un diccionario de palabras clave, reemplazándolas si hay coincidencia.
