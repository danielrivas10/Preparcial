// Sección IV. Análisis de complejidad


#include <vector>

int CountGreater(const std::vector<int>& values, int target) {
  int count = 0;
  int size = static_cast<int>(values.size());

  for (int i = 0; i < size; ++i) {
    if (values[i] > target) {
      ++count;
    }
  }

  int last_value = size > 0 ? values[size - 1] : 0;

  if (last_value > target) {
    ++count;
  }

  return count;
} 
/*
Responda:
a. Identifique tres operaciones o instrucciones cuyo costo no crece con el tamaño del vector.

- int count = 0;
- Obtener el tamaño con values.size().
- Leer el último elemento con values[size - 1], si el vector no está vacío.
Cada una se ejecuta una cantidad fija de veces, independientemente de cuántos elementos tenga el vector.

b. ¿Qué parte del código determina principalmente el crecimiento del tiempo de ejecución?

El ciclo for determina principalmente el crecimiento: recorre los elementos del vector y evalúa 
la condición values[i] > target una vez por elemento.


c. ¿Cuál es la complejidad temporal en notación Big-O? Justifique.

La complejidad temporal es O(n), donde n es el tamaño del vector. 
El ciclo realiza aproximadamente n iteraciones; las instrucciones posteriores al ciclo añaden solo trabajo constante.

d. Si el tamaño del vector se duplica, ¿cómo cambia aproximadamente el trabajo realizado por el ciclo principal?

Si se duplica el tamaño del vector, el ciclo realiza aproximadamente el doble de iteraciones y, por tanto, 
el doble de trabajo.



*/