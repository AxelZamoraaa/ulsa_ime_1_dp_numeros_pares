// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Por qué este include usa comillas y no < >?
#include "utilerias.h"

// ¿por qué debe existir la función main()?
int main() {
    // 1. Constante: cantidad de números a leer
    const int CANTIDAD = 5;

    // 2. Arreglo y contador (siempre inicializados)
    //    TODO: declara el arreglo pares. ¿De qué tamaño en el peor caso?
    //    TODO: declara totalPares. ¿Con qué valor empieza?

    std::cout << "Guardar los numeros pares de " << CANTIDAD << " numeros\n";

    // 3. Ciclo: leer CANTIDAD números
    //    TODO: lee cada número con leerEntero("Escribe un numero: ")
    //    TODO: si el número es par, guárdalo en la siguiente posición libre
    //    ¿Qué variable te dice cuál es la siguiente posición libre?

    // 4. Salida
    //    TODO: muestra cuántos pares se guardaron
    //    TODO: recorre el arreglo e imprime cada par
    //    ¿Hasta qué posición debes llegar?

    // ¿Qué significa return 0;?
    return 0;
}