int main() {
    int numero = 5;
    if (numero > 0) {
        return numero;
    } else {
        while (numero < 0) {
            numero = numero + 1;
        }
    }
    return 0;
}