# Práctica 2: Guardar los números pares
## 1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->

Ientifica en una serie de numeros cuales de estos son pares, y creo que serivira para poder identificar este tipo de numeros en un caso como de una empresa que identifique como los que asistierona trabajar con un numero para y los que no vinieron con un numero impar

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y su objetivo. -->

**Entradas:**
1. Los 5 numeros que se van a escribir uno por uno

**Salidas:**
1. La cantidad de numeros pares que se encontraron
2. La lista de esos numeros pares mostrados uno por uno

## 3. Restricciones e invariante (Fase 1 y 2)

**Restricciones** (¿qué debe cumplirse?):
- Que debe leer el programa exactamente 5 numeros
- Solo se deben guardar los numeros que sean pares

**Tamaño del arreglo y por qué** (piensa en el peor caso):
El arreglo con un tamaño maximo de 5, porque si se ponen 5 numeros pares seguidos se necesita el espacio para guardarse todos

**¿El 0 y los negativos son pares? ¿Por qué?**
si porque el 0 al dividirlo entre 2 da 0 y los negativos funcionan de la misma manera que los positivos

**Invariante** (¿qué es verdad después de cada vuelta del ciclo?):
despues de cada vuelta tiene que tener guardado el numero exacto de pares encontrados hasta ese momento

## 4. Casos resueltos a mano (Fase 1)

| Caso | Números | Pares guardados | Posición de cada par |
|---|---|---|---|
| 1 | 3, 8, 5, 2, 7 | 8, 2 | 8 en posición 1 y 2 en posición 2 |
| 2 | 2, 4, 11, 10, 1 | 2, 4, 10 | 2 en posición 1, 4 en posición 2 y 10 en posición 5 |
| 3 | 119. 1, 7, 9, 21 | ninguno | no se llena ninguna posición |

## 5. Receta en pseudocódigo (Fase 2)
<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las dos preguntas. -->

**¿Probé mi receta a mano con un caso?** Sí
**¿Tuve que corregirla?** No, ya que el pseudocodigo funciono igual que como quedo el codigo al final

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o numeros_pares
./numeros_pares
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con un caso normal. -->

Guardar los numeros pares de 5 numeros
Escribe un numero: 5
Escribe un numero: 2
Escribe un numero: 1
Escribe un numero: 11
Escribe un numero: 20
Pares encontrados: 2
2
20

## 8. Experimentos (Fase 3)

**Experimento A: ¿qué apareció al imprimir las 5 posiciones del arreglo? ¿Por qué?**
si en vez de usar totalPares se usa cantidad como limite el programa pone posiciones del arreglo que nunca se llenaron y aparecen numeros que no tendrian sentido

**Experimento B: ¿qué pasó al usar la variable del ciclo como posición del arreglo? ¿Por qué?**
si se cambia totalPares por contador para el arreglo, se pierden los datos porque el contador avanza en cada vuelta del ciclo

## 9. Tabla de pruebas (Fase 4)

| Caso | Números | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Mezcla | 1, 2, 3, 4, 5 | 2 pares: 2, 4 | 2 y 4 | si |
| Posiciones distintas | 3, 8, 5, 2, 7 | 2 pares: 8, 2 | 8 y 2 | si |
| Todos pares | 2, 4, 6, 8, 10 | 5 pares | 2, 4, 6, 8 y 10 | si |
| Todos impares | 1, 3, 5, 7, 9 | 0 pares | ninguno apareció | si |
| Con cero y negativos | 0, -3, -4, 7, 1 | 2 pares: 0, -4 | 0 y -4 | si |
| Entrada inválida | `hola` o `3.5` | vuelve a pedir | entrada no valida, escribe un numero entero | si |
| Caso propio 1 | 1, 1, 1, 1, 1 | 0 pares encontrados | 0 pares encontrados | si |
| Caso propio 2 | 1200, 2, 1, 991, 4 | 1200, 2 y 4 | 1200, 2 y 4 | si |

## 10. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | no sabia si usar total pares o contador como la posicion del arreglo | use total pares porque solo asi avanzaba cuando se guardaba un par | si |
| 2 | no sabia si el arreglo tenia que ser del tamaño de "cantidad" o menos | use el tamaño de candiad para cubrir lo del caso de que todos fueran pares | si |

**Reto elegido (opcional):** _____

## 11. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| que pasaba si usaba decimal | vi que si ponia lo de leerEntero que es la funcion que se encarga de eso, pero no probe que mensaje daba  |

## 12. Reflexión final

**¿Qué aprendí con esta práctica?**
a definir entre el contador y lo de cantidad y ver cuales serian como variable y limites

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
escribir el codigo a mano para ver si asi comprendo mejor lo que hago

**¿Qué fue lo más difícil y cómo lo resolví?**
El saber para que se necesitan 2 contadores diferentes como "totalPares" y "contador" lo resolvi viendo que uno cuenta los numeros que se leen y el otro solo los que se guardan 

**¿Qué pregunta me quedó sin responder?**
el si es que podriamos hacer que acepte otro tipo de numeros como los romanos

**¿Por qué no puedo usar la variable del ciclo para guardar en el arreglo?**
porque estaria avanzando en cada vuelta del ciclo sin importar si el numero es par o no 

## 13. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené todas las secciones (no quedan `_____`)
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 3 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Entregué el enlace de mi fork en Classroom