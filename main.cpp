#include <iostream>

#include "utilerias.h"

int main() {
    const int CANTIDAD = 5;

    int pares[CANTIDAD];
    int totalpares = 0;

    std::cout << "Guardar los numeros pares de " << CANTIDAD << " numeros\n";

    int contador = 0;
    while (contador < CANTIDAD) {
        int numero = leerEntero("Escribe un numero: ");
        if (numero % 2 == 0) {
            pares[totalpares] = numero;
            totalpares = totalpares + 1;
        }
        contador = contador + 1;

    std::cout << "Pares encontrados: " << totalpares << "\n";
    
    int i = 0;
    while (i < totalpares) {
        std::cout << pares[i] << "\n";
        i = i + 1;
    }
   
    return 0;
}