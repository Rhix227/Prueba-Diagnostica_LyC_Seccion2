import time

def generar_pascal(n):
    # Uso de memoria dinámica nativa en listas de Python
    fila = [1]# Inicializamos la primera fila del triángulo (n=0)
    for _ in range(n):
        # Esta línea es el corazón del algoritmo:
        # 1. Agregamos un [1] al inicio.
        # 2. Suma parejas de números adyacentes de la fila anterior 
        fila = [1] + [fila[i] + fila[i+1] for i in range(len(fila)-1)] + [1]
    return fila

def ejecutar_problema_1():
    # Entrada de datos
    n = int(input("Ingrese el valor de n: "))# Capturar el grado del polinomio.
    
    print("\n--- PARTE a) ---")
    coeficientes = generar_pascal(n)
    print(f"Coeficientes: {' '.join(map(str, coeficientes))}")# Llamado a la función para obtener los coeficientes
    
    # Mostrar polinomio
    terminos = []
    for i, coef in enumerate(coeficientes):
        potencia = n - i
        if potencia == 0: terminos.append(f"{coef}")# Término independiente
        elif potencia == 1: terminos.append(f"{coef}x")# Término lineal
        else: terminos.append(f"{coef}x^{potencia}")# Términos de mayor grado
    print(f"(x+1)^{n} = {' + '.join(terminos)}")

    print("\n--- PARTE b) ---")
    x = float(input("Ingrese el valor de x: "))# Pide el valor para evaluar la función f(x)
    
    # Mostrar f(x) planteado
    planteamiento = " + ".join([f"{c}*{x:.2f}^{n-i}" for i, c in enumerate(coeficientes)])
    print(f"Calculando f({x:.2f}) = {planteamiento}")
    
    print("Paso a paso:")
    total = 0
    for i, coef in enumerate(coeficientes):
        potencia = n - i
        potencia_res = x ** potencia# Calcula x elevado a la potencia 
        termino_res = coef * potencia_res# Multiplica por el coeficiente del triángulo
        print(f"Termino {i+1}: {coef}*{x:.2f}^{potencia} = {coef}*{potencia_res:.6f} = {termino_res:.6f}")
        total += termino_res
    
    print(f"Resultado final: f({x:.2f}) = {total:.6f}")
    print(f"Verificacion: ({x:.2f}+1)^{n} = {(x+1)**n:.6f}")

    # Medición de tiempo para n=100 
    inicio = time.time()
    generar_pascal(100)
    fin = time.time()
    with open("resultado_python.txt", "w") as f:
        f.write(f"Tiempo para n=100: {fin - inicio:.6f} s")

if __name__ == "__main__":
    ejecutar_problema_1()