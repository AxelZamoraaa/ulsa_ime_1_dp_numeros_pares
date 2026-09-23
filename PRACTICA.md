# Práctica: Guardar los números pares

## Sobre esta práctica

**Problema:** escribir un programa en C++ que pida al usuario 5 números enteros, uno por uno, guarde **solo los pares** en un arreglo y descarte los impares. Al final debe mostrar cuántos pares encontró y cuáles son.

**Lo que vas a practicar:** arreglos (declaración, tamaño, posiciones y recorrido), decisión simple (`if`), el operador módulo (`%`), iteración con contador, el uso de una función ya construida, y la restricción y la invariante de un algoritmo.

**Idea central:** un arreglo no sabe cuántos datos útiles tiene; esa cuenta la llevas tú en una variable aparte. Igual que en la práctica anterior, tu meta no es solo que el programa funcione, sino que entiendas **por qué funciona** y **cómo lo construiste**. Por eso esta guía te hace preguntas antes de darte pistas. Responde cada pregunta por escrito en tu `README.md` antes de avanzar a la siguiente fase.

**Repositorio base:** https://github.com/narizwallace/ulsa_ime_1_dp_numeros_pares

**Entregable:** el enlace a tu repositorio, publicado en Google Classroom.

**El proceso que vas a seguir:**

| Fase | Qué haces |
|---|---|
| 0 | Preparar tu entorno (fork y clonar) |
| 1 | Entender el problema |
| 2 | Diseñar la solución como una receta detallada |
| 3 | Implementar |
| 4 | Probar y mejorar |
| 5 | Publicar en GitHub |

**Cómo usar el `README.md`:** ya viene en el repositorio base con espacios en blanco (`_____`). Lo vas llenando fase por fase, así no tienes que preguntarte qué va en él. Cada fase de esta guía te indica qué secciones llenar. No es necesario que uses el archivo README.md, también puedes copiar el contenido y hacerlo en un editor de texto de tu elección. Solo asegúrate de subir el archivo equivalente a tu repositorio.


## Fase 0. Preparar tu entorno

1. Entra al repositorio base: https://github.com/narizwallace/ulsa_ime_1_dp_numeros_pares
2. Haz clic en **Fork** (arriba a la derecha) para crear tu propia copia en tu cuenta de GitHub.
3. En tu fork, haz clic en **Code**, copia la URL y clónalo en tu computadora.

Estos son los comandos para clonar un repositorio desde tu terminal o línea de comando:
```bash
git clone <URL-de-tu-fork>
cd ulsa_ime_1_dp_numeros_pares
```
También puedes hacer el clone desde GitHub Desktop como lo hemos hecho antes.


4. Abre la carpeta en tu editor y revisa los archivos:

```
ulsa_ime_1_dp_numeros_pares/
├── README.md      ← plantilla con espacios en blanco para llenar
├── PRACTICA.md    ← este documento
├── RECETA.md      ← donde vas a escribir tu solución antes de implementarla
├── main.cpp       ← punto de partida de tu programa
├── utilerias.h    ← función de apoyo para leer números (no lo modifiques)
└── .gitignore     ← evita subir el ejecutable
```

**Todo tu trabajo va dentro de esta carpeta.**

> **Nota técnica: usar una función sin ver su interior.**
> En `utilerias.h` está la función `leerEntero`. Pide un número al usuario y no avanza hasta que escriba un entero válido. No necesitas entender cómo funciona por dentro, igual que no necesitas saber cómo está hecho `std::cout`. Lo que sí necesitas es su *contrato*: qué recibe y qué devuelve. Se usa así:
> `int numero = leerEntero("Escribe un numero: ");`
> **Pregunta guía:** lee los comentarios de `utilerias.h`. ¿Qué recibe `leerEntero`? ¿Qué devuelve?

---

## Fase 1. Entender el problema

*Aquí no se escribe código. Llena las secciones 1 a 4 de tu `README.md`.*

**Preguntas guía**

1. Explica el problema con tus palabras, en una o dos frases.
2. ¿Cuál es la entrada? ¿Cuántos datos entran en total?
3. ¿Cuál es la salida? ¿Es un solo valor, como en la práctica anterior, o son varios?
4. ¿Entiendes el problema? Compruébalo: explícaselo a un compañero en 1 minuto, sin mirar tus notas.
5. ¿Para qué sirve separar datos según una condición? Da un ejemplo de la vida real (lecturas válidas de un sensor, piezas que pasan un control de calidad...).

**Restricciones: ¿qué debe cumplirse?**

- ¿Cuántos números pide el programa? ¿De qué tamaño debe ser el arreglo? Piensa en el peor caso: ¿qué pasa si los 5 números son pares?
- ¿El 0 es par? ¿Y los negativos, como -4? Decide y justifica tu decisión.
- Esta vez no tienes que decidir sobre los decimales: `leerEntero` solo acepta enteros. ¿Por qué tiene sentido para este problema?

**Resuelve a mano 3 casos.** Para cada uno, anota qué pares se guardan y **en qué posición del arreglo** queda cada uno. Usa al menos este: `3, 8, 5, 2, 7`. ¿En qué posición queda el 8? ¿Y el 2? ¿Coinciden con el número de vuelta del ciclo?

> **Nota técnica: ¿qué es un arreglo?**
> Es un conjunto de datos del mismo tipo, guardados uno tras otro bajo un solo nombre. Cada dato se identifica por su posición (índice), que **empieza en 0**. Un arreglo de 5 enteros va de `pares[0]` a `pares[4]`.

---

## Fase 2. Diseñar la receta

*Llena la sección 3 de tu `README.md`, escribe tu receta en `RECETA.md` y responde en la sección 5 si la probaste a mano.*

> **Nota técnica: ¿por qué diseñar antes de programar?**
> En la práctica anterior el código solo traducía una receta que ya tenías. Aquí es aún más importante: el error más común con arreglos no es de sintaxis, es de lógica (guardar en la posición equivocada), y ese error se detecta mejor en papel que en la pantalla.

**¿Qué preguntas te ayudan a definir el proceso?**

- ¿Cómo lo harías con lápiz y papel, número por número?
- ¿Cómo decides si un número se guarda o se descarta?
- Cuando guardas un par, ¿cómo sabes en qué posición va? ¿Qué necesitas recordar para saberlo?
- ¿Con qué valor empieza esa cuenta antes del primer número?
- Al final, ¿cuántas posiciones del arreglo debes mostrar? ¿Siempre 5?

**Completa la receta en pseudocódigo** (los espacios en blanco son tuyos), esta receta la puedes escribir en el archivo `RECETA.md`:

```
1. Mostrar mensaje de bienvenida
2. totalPares ← ______
3. contador ← ______
4. MIENTRAS contador ______ CANTIDAD HACER
       numero ← leerEntero("______")
       SI numero ______ ENTONCES
           pares[______] ← numero
           totalPares ← ______
       FIN SI
       contador ← ______
   FIN MIENTRAS
5. Mostrar "Pares encontrados: " y ______
6. i ← 0
7. MIENTRAS i ______ ______ HACER
       Mostrar pares[i]
       i ← ______
   FIN MIENTRAS
```

> **Nota técnica: la invariante.**
> Una **restricción** es una condición que deben cumplir los datos (por ejemplo: el arreglo tiene espacio para 5 números). Una **invariante** es una relación que permanece verdadera en cada vuelta del ciclo.
> **Pregunta guía:** después de cada vuelta, ¿qué representa exactamente `totalPares`? ¿Qué relación tiene con las posiciones ocupadas del arreglo? ¿Y con la siguiente posición libre? Escribe la frase que se cumple siempre.

**Prueba tu receta a mano** con el caso `3, 8, 5, 2, 7`: anota en cada vuelta los valores de `contador`, `numero`, `totalPares` y el contenido del arreglo. Si algo no cuadra, corrige la receta ahora, no el código después.

---

## Fase 3. Implementar

*Trabaja sobre `main.cpp`. Llena las secciones 6, 7, 8 y 11 de tu `README.md`.*

**Preguntas guía**

- ¿Has pensado cómo dividir la implementación en pasos pequeños?
- ¿Qué variables necesitas? ¿Cuál es constante y cuáles cambian?
- ¿Con qué valor inicial debe empezar cada variable?

**Así se ve tu punto de partida en `main.cpp`:**

```cpp
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
```

**Construye en pasos pequeños.** Compila y prueba después de cada uno:

1. Leer **un** número con `leerEntero` y mostrarlo.
2. Mostrar si ese número es par o impar (solo un mensaje, sin arreglo todavía).
3. Repetirlo `CANTIDAD` veces.
4. Guardar los pares en el arreglo y contarlos.
5. Recorrer el arreglo e imprimir los pares (haz primero el Experimento A).

**Para compilar y ejecutar:**

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o numeros_pares
./numeros_pares
```

> **Nota de C++: el operador módulo.**
> `%` devuelve el residuo de una división entera: `7 % 2` es `1` y `8 % 2` es `0`. Para saber si un número es par, compara `numero % 2 == 0`. Evita `numero % 2 == 1` para los impares: en C++, `-3 % 2` da `-1`.

> **Nota de C++: el tamaño de un arreglo debe ser constante.**
> Por eso usamos `CANTIDAD`. Escribir `int n = 5; int pares[n];` compila en g++ por una extensión, pero no es C++ estándar y otros compiladores lo rechazan.

> **Nota de C++: no te salgas del arreglo.**
> Escribir en `pares[5]` en un arreglo de 5 elementos **compila sin error**, pero escribe en memoria que no le pertenece. C++ no te protege: tú eres responsable de los límites.

> **Nota de C++: recorrer un arreglo.**
> **Experimento A (obligatorio):** escribe un `for` que imprima **las 5 posiciones** del arreglo, sin importar cuántos pares guardaste. Ejecuta con `3, 8, 5, 2, 7`. ¿Qué aparece en las posiciones que no llenaste? ¿Por qué? Después, corrige el ciclo para recorrer solo las posiciones con datos. ¿Qué variable te dice hasta dónde llegar?

> **Nota de C++: el índice del arreglo no es la vuelta del ciclo.**
> **Experimento B (obligatorio):** en la línea donde guardas el par, cambia `totalPares` por la variable de tu ciclo (`contador` o `i`) y ejecuta con `3, 8, 5, 2, 7`. ¿Qué observas? ¿Por qué pasa? Vuelve a dejarlo como estaba al terminar.

> **Nota de C++: buenas prácticas.**
> - Usa nombres descriptivos (`pares`, `totalPares`, no `a` ni `c`).
> - Inicializa siempre tus variables, incluido el contador.
> - Usa la constante en lugar de escribir `5` en varios lugares.
> - Escribe mensajes claros para el usuario (`"Pares encontrados: 2"`).
> - Comenta el *porqué* de lo que haces, no lo obvio.

**Bitácora de dudas:** ¿qué dudas quieres cubrir con el profesor? Anótalas en la sección 11 de tu `README.md`, junto con lo que ya intentaste para resolverlas.

---

## Fase 4. Probar y mejorar

*Llena las secciones 9 y 10 de tu `README.md`.*

**Tabla de pruebas** (en tu `README.md` completa las columnas "Obtenido" y "¿Pasó?"):

| Caso | Números ingresados | Resultado esperado |
|---|---|---|
| Mezcla | 1, 2, 3, 4, 5 | 2 pares: 2, 4 |
| Posiciones distintas | 3, 8, 5, 2, 7 | 2 pares: 8, 2 |
| Todos pares | 2, 4, 6, 8, 10 | 5 pares: 2, 4, 6, 8, 10 |
| Todos impares | 1, 3, 5, 7, 9 | 0 pares, con un mensaje claro |
| Con cero y negativos | 0, -3, -4, 7, 1 | 2 pares: 0, -4 |
| Entrada inválida | escribe `hola` o `3.5` en algún número | vuelve a pedir ese número |

**Agrega al menos 2 casos propios.**

**Preguntas guía**

- ¿Alguna prueba falló? ¿Fue un error en la receta, en el código o en tus datos esperados?
- En el caso "Todos pares", ¿cómo compruebas que no te saliste del arreglo?
- Cuando no hay pares, ¿qué muestra tu programa? ¿Es claro para el usuario?

**Ciclo de mejora:** identifica → cambia una sola cosa → vuelve a probar todo. Registra cada cambio en tu bitácora de mejoras.

**Retos opcionales (para tu insatisfacción positiva):**

1. Muestra `No se encontraron pares` cuando el arreglo quede vacío.
2. Imprime los pares en una sola línea separados por comas, sin coma al final.
3. Muestra la **suma** y el **promedio** de los pares (¡lo hiciste en la práctica anterior!).
4. Guarda también los impares en un segundo arreglo e imprime ambos.
5. Pregunta al usuario cuántos números capturar. ¿Qué pasa si pide más que el tamaño del arreglo? ¿Cómo lo evitas?

---

## Fase 5. Publicar en GitHub

1. Verifica que tu `README.md` esté completo, sin `_____` pendientes, y que tu programa compile sin advertencias.
2. Sube tus cambios a tu fork. Debes tener **al menos 3 commits** hechos durante el trabajo (no uno solo al final), con mensajes que digan qué cambió, por ejemplo: `Agrega lectura con leerEntero`, `Agrega condicion de par`, `Agrega recorrido del arreglo`.

Con los siguientes comandos puedes hacer un commit y publicarlo desde tu terminal o línea de comando:

```bash
git add .
git commit -m "Agrega condicion de par"
git push origin main
```
También puedes usar GitHub Desktop como lo hemos hecho antes.

3. Abre tu repositorio en GitHub y comprueba que ahí aparezcan tu código y tu `README.md` actualizados. Tu fork tiene esta forma:
   `https://github.com/<tu-usuario>/ulsa_ime_1_dp_numeros_pares`
4. Entrega en Google Classroom el enlace a **tu fork**.

> **Nota técnica: commits pequeños.**
> Cada commit es un punto al que puedes volver si algo sale mal. Confirma cambios cada vez que completes un paso pequeño que funcione, como los de la Fase 3. Te será especialmente útil en los experimentos: si algo se rompe, puedes regresar al último commit.

---

## Cierre y reflexión

*Llena la sección 12 de tu `README.md` antes de entregar.*

1. ¿Qué aprendiste con esta práctica?
2. Ahora que la terminaste, ¿qué cambiarías de tu proceso?
3. ¿Qué fue lo más difícil y cómo lo resolviste?
4. ¿Qué pregunta te quedó sin responder?
5. ¿Por qué no puedes usar la variable del ciclo para guardar en el arreglo?

---

## Lista de verificación antes de entregar

- [ ] Llené todas las secciones de mi `README.md` (no quedan `_____`)
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 3 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_numeros_pares` y el código está en `main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom