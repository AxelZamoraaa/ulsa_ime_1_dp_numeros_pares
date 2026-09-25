# Receta: Guardar los números pares

1. Mostrar mensaje de bienvenida
2. totalPares = 0
3. contador = 0
4. MIENTRAS contador < CANTIDAD HACER
       numero ← leerEntero("Ingrese un numero")
       SI numero ______ ENTONCES
           pares[totalPares] ← numero
           totalPares = totalPares + 1
       FIN SI
       contador = contador + 1
   FIN MIENTRAS
5. Mostrar "Pares encontrados: " + totalPares
6. Mostrar "Valores:" 
7. i = 0
8. MIENTRAS i < totalPares HACER
       Mostrar pares[i]
       i = i + 1
   FIN MIENTRAS
