#include <vector>

int CountPairs(const std::vector<int>& values) {
  int count = 0;
  int size = static_cast<int>(values.size());

  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (values[i] == values[j]) {
        ++count;
      }
    }
  }

  return count;
}

/*
a. ¿Qué función cumple cada ciclo?
El ciclo externo selecciona el elemento en la posición i. 
El ciclo interno lo compara con cada elemento que está después, desde i + 1 hasta el final.

b. ¿Por qué no basta con analizar el ciclo externo?
Porque el trabajo total también depende de cuántas veces se ejecuta el ciclo interno.
Su cantidad de iteraciones cambia con cada valor de i: empieza con n - 1 comparaciones, luego n - 2, y así sucesivamente.

c. Número exacto de comparaciones:
Para un arreglo de tamaño n:(n-1)+(n-2)+...+1= n(n-1)/2.

d. Complejidad temporal:
Es O(n²). La fórmula contiene un término cuadrático, n^2/2, que domina el crecimiento cuando n aumenta.

e. Si el tamaño se duplica:
Para tamaños grandes, las comparaciones aumentan aproximadamente cuatro veces, porque (2n)^2 = 4n^2

*/