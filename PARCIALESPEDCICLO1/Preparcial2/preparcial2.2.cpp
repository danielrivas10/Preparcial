#include <iostream>
#include <queue>

//Parte 2.2 COLAS.
//front() mira el primero, pop() lo quita y push() agrega al final.
void RotateQueue(std::queue<int>& requests, int k) // Recibe la cola por referencia, así que los cambios se hacen sobre la cola original
{
    if (requests.empty() || k <= 0) //K indica cuantos movimientos hacer.
    {
        return;
    }

    // Por ejemplo, 7 rotaciones en una cola de 5 equivalen a 2.
    std::size_t rotations = static_cast<std::size_t>(k) % requests.size(); // Supongamos que hay 5 elementos y k vale 7. Después de rotar cinco veces, la cola vuelve a su orden inicial. Por eso solo necesitamos calcular:7 % 5 = 2

    for (std::size_t i = 0; i < rotations; i++) // Repite el movimiento la cantidad de veces calculada.
    {
        int first = requests.front(); //Recibe el primer elemento de la cola pero todavia no lo quita.
        requests.pop(); //Quita el 10 de frente
        requests.push(first); //Ahora 10 pasa al final. Pero eso con una iteración.
    }
}

int main()
{
    std::queue<int> requests;

    requests.push(10);
    requests.push(20);
    requests.push(30);
    requests.push(40);
    requests.push(50);

    RotateQueue(requests, 2); //Mueve el primer elemento al final dos veces.

    while (!requests.empty())
    {
        std::cout << requests.front() << " "; //Muestra el que está enfrente 
        requests.pop(); //y luego lo quita. Todo depende de la cantidad de vueltas.
    }

    std::cout << '\n';
    return 0;

   }
/*

//Por si piden la copia.
#include <iostream>
#include <queue>

// Recibe una copia de la cola y devuelve esa copia ya rotada.
std::queue<int> RotateQueue(std::queue<int> requests, int k)
{
    if (requests.empty() || k <= 0)
    {
        return requests;
    }

    // Si hay 5 elementos, 7 rotaciones equivalen a 2.
    std::size_t rotations =
        static_cast<std::size_t>(k) % requests.size();

    for (std::size_t i = 0; i < rotations; i++)
    {
        int first = requests.front(); // Mira el frente.
        requests.pop();               // Lo quita de la copia.
        requests.push(first);         // Lo agrega al final de la copia.
    }

    return requests; // Devuelve la copia rotada.
}

// También recibe una copia: imprime y vacía solo esa copia.
void PrintQueue(std::queue<int> requests)
{
    while (!requests.empty())
    {
        std::cout << requests.front() << " ";
        requests.pop();
    }

    std::cout << '\n';
}

int main()
{
    std::queue<int> requests;

    requests.push(10);
    requests.push(20);
    requests.push(30);
    requests.push(40);
    requests.push(50);

    std::cout << "Original: ";
    PrintQueue(requests);

    // RotateQueue recibe una copia y devuelve esa copia rotada.
    std::queue<int> rotated = RotateQueue(requests, 2);

    std::cout << "Rotada:   ";
    PrintQueue(rotated);

    // La original todavía conserva su orden.
    std::cout << "Original despues: ";
    PrintQueue(requests);

    return 0;
}


//Invertir una cola


#include <iostream>
#include <queue>
#include <stack>

std::queue<int> ReverseQueue(std::queue<int> requests)
{
    std::stack<int> auxiliary;

    // Pasamos los elementos de la copia de la cola a la pila.
    while (!requests.empty())
    {
        auxiliary.push(requests.front());
        requests.pop();
    }

    std::queue<int> reversed;

    // La pila los entrega en orden inverso.
    while (!auxiliary.empty())
    {
        reversed.push(auxiliary.top());
        auxiliary.pop();
    }

    return reversed;
}

void PrintQueue(std::queue<int> requests)
{
    while (!requests.empty())
    {
        std::cout << requests.front() << " ";
        requests.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::queue<int> requests;
    requests.push(10);
    requests.push(20);
    requests.push(30);
    requests.push(40);

    std::queue<int> reversed = ReverseQueue(requests);

    std::cout << "Original:  ";
    PrintQueue(requests);

    std::cout << "Invertida: ";
    PrintQueue(reversed);

    return 0;
}

//Buscar un valor


#include <iostream>
#include <queue>

bool ContainsValue(std::queue<int> requests, int target)
{
    // Revisa la copia elemento por elemento.
    while (!requests.empty())
    {
        int value = requests.front();
        requests.pop();

        if (value == target)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::queue<int> requests;
    requests.push(10);
    requests.push(20);
    requests.push(30);
    requests.push(40);

    int target = 30;

    if (ContainsValue(requests, target))
        std::cout << "Se encontro " << target << ".\n";
    else
        std::cout << "No se encontro " << target << ".\n";

    return 0;
}


//Encontrar mayor y menor.

#include <iostream>
#include <queue>

bool FindMinimumAndMaximum(
    std::queue<int> requests,
    int& minimum,
    int& maximum)
{
    if (requests.empty())
    {
        return false;
    }

    // El primer elemento sirve como punto de partida.
    minimum = requests.front();
    maximum = requests.front();
    requests.pop();

    while (!requests.empty())
    {
        int value = requests.front();
        requests.pop();

        if (value < minimum)
            minimum = value;

        if (value > maximum)
            maximum = value;
    }

    return true;
}

int main()
{
    std::queue<int> requests;
    requests.push(10);
    requests.push(40);
    requests.push(20);
    requests.push(30);

    int minimum;
    int maximum;

    if (FindMinimumAndMaximum(requests, minimum, maximum))
    {
        std::cout << "Menor: " << minimum << '\n';
        std::cout << "Mayor: " << maximum << '\n';
    }
    else
    {
        std::cout << "La cola esta vacia.\n";
    }

    return 0;
}

//Contar apariciones.

#include <iostream>
#include <queue>

int CountOccurrences(std::queue<int> requests, int target)
{
    int count = 0;

    while (!requests.empty())
    {
        int value = requests.front();
        requests.pop();

        if (value == target)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    std::queue<int> requests;
    requests.push(10);
    requests.push(20);
    requests.push(30);
    requests.push(20);
    requests.push(40);

    int target = 20;

    std::cout << target << " aparece "
              << CountOccurrences(requests, target)
              << " veces.\n";

    return 0;
}

//Eliminar valores especificos.

#include <iostream>
#include <queue>

void RemoveValue(std::queue<int>& requests, int target)
{
    std::queue<int> auxiliary;

    // Sacamos todos los elementos de la cola original.
    while (!requests.empty())
    {
        int value = requests.front();
        requests.pop();

        // Guardamos únicamente los que no se deben eliminar.
        if (value != target)
        {
            auxiliary.push(value);
        }
    }

    // Devolvemos los conservados a la cola original.
    while (!auxiliary.empty())
    {
        requests.push(auxiliary.front());
        auxiliary.pop();
    }
}

void PrintQueue(std::queue<int> requests)
{
    while (!requests.empty())
    {
        std::cout << requests.front() << " ";
        requests.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::queue<int> requests;
    requests.push(10);
    requests.push(20);
    requests.push(30);
    requests.push(20);
    requests.push(40);

    RemoveValue(requests, 20);

    std::cout << "Despues de eliminar los 20: ";
    PrintQueue(requests);

    return 0;
}











*/








