/*

Parte 1.2: Separar la lista
a. ¿Por qué guardar el siguiente nodo antes de modificar current->next?
Porque current->next contiene la dirección del nodo que sigue. 
Si cambiamos ese enlace antes de guardar la dirección, podríamos 
perder acceso al resto de la lista. Guardarlo en next_node nos permite continuar el recorrido.

b. ¿Qué puede ocurrir si se actualiza next, pero no prev?
El recorrido hacia adelante podría funcionar, pero el recorrido 
hacia atrás seguiría enlaces incorrectos. La lista quedaría inconsistente 
y operaciones como PrintBackward podrían producir resultados erróneos.

c. ¿Cuál es la complejidad temporal?
Es O(n). Se visita cada nodo una sola vez y el trabajo realizado en cada visita es constante.

Parte 1.3: Mover el último nodo al inicio
Si el antiguo primer nodo actualiza su prev, pero el nuevo primer nodo no actualiza su next, 
los enlaces quedan descoordinados. Desde el antiguo primero se puede retroceder al nuevo, pero
al recorrer hacia adelante desde el nuevo no se llega al resto de la lista.

Parte 2.1: Eliminar un valor de una pila
El primer ciclo vacía la pila original y guarda en auxiliary los elementos que se conservan. 
Es necesario devolverlos para que la pila original contenga el resultado final, con el orden requerido.

Parte 2.2: Rotar una cola
Después de rotar k posiciones, queda al frente el elemento que originalmente estaba en la posición k —contando 
desde 0—. Los primeros k elementos pasan al final, conservando su orden. Por ejemplo, al rotar dos posiciones 
10 20 30 40 50, queda 30 40 50 10 20.

Parte 3.1: Ordenar un segmento
El ciclo empieza en start + 1 porque el primer elemento del segmento, values[start], ya se considera ordenado. 
Empezar en 1 podría modificar elementos que están antes del segmento.

Parte 3.2: Primera aparición con búsqueda binaria
No basta con retornar mid al encontrar el valor, porque puede haber otra aparición en un índice menor. 
Se guarda mid como candidato y se sigue buscando en la parte izquierda para encontrar la primera aparición.


















*/