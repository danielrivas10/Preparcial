/*Sección II. Pilas y colas con STL */
#include <iostream>
#include <stack>

// Parte 2.1 PILAS. //top().Consulta arriba. push() agrega uno. pop()quita uno.
void RemoveFromStack(std::stack<int> &tasks, int target)
{
    std::stack<int> auxiliary; // Crea una pila temporal vacía. Usada para guardaar numeros que no sean 20.

    // Sacar de tasks todos los elementos.
    // Guardar en auxiliary solo los que no sean target.
    while (!tasks.empty())
    {
        int value = tasks.top(); // O sea si es el valor buscado entonces lo sube
        tasks.pop();             // Acá lo elimina.

        if (value != target)
        {
            auxiliary.push(value); // Si no es igual se guarda en auxiliary. Creando la pila.
        }
    }

    // Devolver los elementos a tasks para conservar su orden. Quitandolo de auxiliary.
    while (!auxiliary.empty())
    {
        tasks.push(auxiliary.top());
        /*

    auxiliary:       tasks:
    10 arriba        vacía
    30
    40 abajo
auxiliary.top() lee 10, y tasks.push(10) mete 10 en tasks:
        */
        auxiliary.pop(); // Quita el elemento de auxiliary.
    }
}

int main()
{
    std::stack<int> tasks;

    tasks.push(10);
    tasks.push(20);
    tasks.push(30);
    tasks.push(20);
    tasks.push(40);

    RemoveFromStack(tasks, 20); // Revisa toda la pila y elimina los valores que sean 20

    // Al extraerlos, deben salir: 40, 30, 10.
    while (!tasks.empty())
    {
        std::cout << tasks.top();

        tasks.pop();

        if (!tasks.empty())
        {
            std::cout << ", ";
        }
    }

    std::cout << '\n';

    return 0;
}


/*
//Buscar un valor.

#include <iostream>
#include <stack>

bool ContainsValue(std::stack<int> tasks, int target)
{
    // tasks es una copia, así que la pila original no se modifica.
    while (!tasks.empty())
    {
        int value = tasks.top(); // Lee el elemento de arriba.
        tasks.pop();             // Lo quita de la copia para revisar el siguiente.

        if (value == target)
        {
            return true; // Lo encontró.
        }
    }

    return false; // Revisó toda la pila y no lo encontró.
}

int main()
{
    std::stack<int> tasks;
    tasks.push(10);
    tasks.push(20);
    tasks.push(30);
    tasks.push(20);
    tasks.push(40);

    int target = 30;

    if (ContainsValue(tasks, target))
        std::cout << "Si se encontro " << target << ".\n";
    else
        std::cout << "No se encontro " << target << ".\n";

    return 0;

}


//Contar cuantas veces aparece un valor.

#include <iostream>
#include <stack>

int CountOccurrences(std::stack<int> tasks, int target)
{
    int count = 0;

    // Revisa la copia elemento por elemento.
    while (!tasks.empty())
    {
        int value = tasks.top();
        tasks.pop();

        if (value == target)
        {
            count++; // Aumenta el contador si coincide.
        }
    }

    return count;
}

int main()
{
    std::stack<int> tasks;
    tasks.push(10);
    tasks.push(20);
    tasks.push(30);
    tasks.push(20);
    tasks.push(40);

    int target = 20;

    std::cout << target << " aparece "
              << CountOccurrences(tasks, target)
              << " veces.\n";

    return 0;
}



//Invertir orden

#include <iostream>
#include <stack>

std::stack<int> ReverseOrder(std::stack<int> tasks)
{
    std::stack<int> reversed;

    // Saca cada valor de la copia y lo apila en reversed.
    while (!tasks.empty())
    {
        reversed.push(tasks.top());
        tasks.pop();
    }

    return reversed;
}

void PrintStack(std::stack<int> values)
{
    // Imprime desde el tope hacia abajo.
    while (!values.empty())
    {
        std::cout << values.top();
        values.pop();

        if (!values.empty())
            std::cout << ", ";
    }

    std::cout << '\n';
}

int main()
{
    std::stack<int> tasks;
    tasks.push(10);
    tasks.push(20);
    tasks.push(30);
    tasks.push(20);
    tasks.push(40);

    std::stack<int> reversed = ReverseOrder(tasks);

    std::cout << "Pila original, desde el tope: ";
    PrintStack(tasks);    // 40, 20, 30, 20, 10

    std::cout << "Pila invertida, desde el tope: ";
    PrintStack(reversed); // 10, 20, 30, 20, 40

    return 0;
}


//Encontrar menor y mayor.

#include <iostream>
#include <stack>

bool FindMinimumAndMaximum(
    std::stack<int> tasks,
    int& minimum,
    int& maximum)
{
    // No hay valores que comparar.
    if (tasks.empty())
    {
        return false;
    }

    // El primer valor sirve como punto de partida.
    minimum = tasks.top();
    maximum = tasks.top();
    tasks.pop();

    while (!tasks.empty())
    {
        int value = tasks.top();
        tasks.pop();

        if (value < minimum)
            minimum = value;

        if (value > maximum)
            maximum = value;
    }

    return true;
}

int main()
{
    std::stack<int> tasks;
    tasks.push(10);
    tasks.push(20);
    tasks.push(30);
    tasks.push(20);
    tasks.push(40);

    int minimum;
    int maximum;

    if (FindMinimumAndMaximum(tasks, minimum, maximum))
    {
        std::cout << "El menor es: " << minimum << '\n';
        std::cout << "El mayor es: " << maximum << '\n';
    }
    else
    {
        std::cout << "La pila esta vacia.\n";
    }

    return 0;
}







*/