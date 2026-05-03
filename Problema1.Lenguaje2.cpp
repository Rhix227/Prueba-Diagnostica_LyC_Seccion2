#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <fstream>

using namespace std;

// Generación con memoria dinámica (punteros)
unsigned long long* generar_pascal_dinamico(int n) {
    // ASIGNACIÓN DINÁMICA: Reserva espacio para enteros largos en el Heap.
    // Esto es crucial porque no se sabe el tamaño de 'n' hasta que el usuario lo ingresa
    unsigned long long* fila = new unsigned long long[n + 1];
    fila[0] = 1;
    for (int i = 1; i <= n; i++) {
        // Fórmula de coeficientes binomiales para llenar el arreglo dinámico
        fila[i] = fila[i - 1] * (n - i + 1) / i;
    }
    return fila;
}

int main() {
    int n;
    double x;

    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "\n--- PARTE a) ---\n";
        // Llamada a la función y recepción del puntero
    unsigned long long* coefs = generar_pascal_dinamico(n);
    
    cout << "Coeficientes: ";
    for(int i = 0; i <= n; i++) cout << coefs[i] << " ";
    
    cout << "\n(x+1)^" << n << " = ";
    for (int i = 0; i <= n; i++) {
        cout << coefs[i] << (n-i > 0 ? "x^" + to_string(n-i) + " + " : "");
    }

    cout << "\n\n--- PARTE b) ---\n";
    cout << "Ingrese el valor de x: ";
    cin >> x;

    cout << fixed << setprecision(6);
    cout << "Calculando f(" << setprecision(2) << x << ") = ";
    for(int i = 0; i <= n; i++) {
        cout << coefs[i] << "*" << x << "^" << n-i << (i < n ? " + " : "");
    }

    cout << "\n" << setprecision(6) << "Paso a paso:\n";
    double total = 0;
    for (int i = 0; i <= n; i++) {
        double pot_res = pow(x, n - i);// Cálculo de potencia.
        double term_res = coefs[i] * pot_res;// Multiplicación de coeficiente por potencia
        cout << "Termino " << i + 1 << ": " << coefs[i] << "*" << setprecision(2) << x 
             << "^" << n - i << " = " << coefs[i] << "*" << setprecision(6) << pot_res 
             << " = " << term_res << "\n";
        total += term_res;
    }

    cout << "Resultado final: f(" << setprecision(2) << x << ") = " << setprecision(6) << total << "\n";
    cout << "Verificacion: (" << setprecision(2) << x << "+1)^" << n << " = " << setprecision(6) << pow(x + 1, n) << "\n";

    // Medición de tiempo (n=100)
    auto start = chrono::high_resolution_clock::now();
    unsigned long long* test = generar_pascal_dinamico(100);
    auto end = chrono::high_resolution_clock::now();
    
    ofstream file("resultado_cpp.txt");
    file << "Tiempo para n=100: " << chrono::duration<double>(end - start).count() << " s";
    file.close();

    delete[] coefs; // Liberación de memoria dinámica
    delete[] test;
    return 0;
}