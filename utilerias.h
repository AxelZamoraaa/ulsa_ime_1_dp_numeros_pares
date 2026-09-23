#ifndef UTILERIAS_H
#define UTILERIAS_H

// =====================================================
// NO MODIFICAR ESTE ARCHIVO
// Contiene funciones de apoyo para la practica.
// =====================================================

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

// Muestra el mensaje y lee una linea completa.
// Repite la pregunta hasta que el usuario escriba un entero valido.
// Rechaza texto, decimales ("3.5") y entradas mixtas ("12abc").
//
// Recibe: el mensaje que se muestra al usuario.
// Devuelve: el numero entero que escribio el usuario.
inline int leerEntero(const std::string& mensaje) {
    std::string linea;
    while (true) {
        std::cout << mensaje;
        if (!std::getline(std::cin, linea)) {
            std::cout << "\nNo hay mas entrada. Fin del programa.\n";
            std::exit(1);
        }
        try {
            std::size_t pos = 0;
            int valor = std::stoi(linea, &pos);
            while (pos < linea.size() &&
                   std::isspace(static_cast<unsigned char>(linea[pos]))) {
                pos++;
            }
            if (pos == linea.size()) {
                return valor;
            }
        } catch (const std::exception&) {
            // Texto no numerico o numero fuera de rango: se vuelve a pedir
        }
        std::cout << "Entrada no valida. Escribe un numero entero.\n";
    }
}

#endif