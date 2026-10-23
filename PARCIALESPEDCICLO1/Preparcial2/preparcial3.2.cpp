#include <iostream>
//Parte 3.2
// Este código busca un número en un arreglo ordenado de mayor a menor. Además, si el número aparece varias veces, busca su primera aparición, es decir, la que tiene el índice más pequeño.

int BinarySearchFirst(const int values[], int size, int target)
{
    int left = 0;
    int right = size - 1; //Como el tamaño es de 7.
    int first_index = -1; //No encontré el objetivo.

    while (left <= right)
    {
        int mid = left + (right - left) / 2; //Si acá encuentras lo que buscas
        //En la primera ronda si son 6 posiciones, o sea 0 1 2 3 4 5 6, entonces es 0+(6-0)/2 que es igual a 3.
        //Ahora en la segunda ronda ya se acorta. Porque ahora buscas los valores menores del objetivo. Si ahi te dio 3 entonces irias a buscar del 0 1 2.
        //La respuesta no es al encontrar el objetivo por primera vez. sino la ultima vez porque va de orden descendente a ascendente.

        if (values[mid] == target) //Entras acá
        {
            first_index = mid; //first_index es el valor que buscabas
            right = mid - 1;  //right es la resta del valor que buscabas-1 y vuelves a ver a ver si ese valor encontrado es el primero y el único.
        }
        else if (values[mid] < target) // Queda por revisar: índices 0, 1 y 2
        {
            
            right = mid - 1; //En este caso es como cuando buscas el 9.Te da un resultado de mid que no es la posicion que buscas.
            //Entonces le restas a right y vuelves  a hacer el proceso hasta que te salga.
        }
        else
        {
           
            left = mid + 1;
        }
    }

    return first_index;
}

int main()
{
    int values[] = {9, 7, 7, 7, 5, 3, 1};
    int size = 7;

    std::cout << BinarySearchFirst(values, size, 7) << '\n'; // 1
    /*
    
mid = left + (right - left) / 2
mid = 0 + (6 - 0) / 2
mid = 3    
    */
    std::cout << BinarySearchFirst(values, size, 4) << '\n'; // -1 porque no está en el arreglo.
    std::cout << BinarySearchFirst(values, size, 9) << '\n'; // 0

    return 0;
}

/*

//Buscar un valor y devolver un indice cualquiera.

#include <iostream>

int BinarySearch(const int values[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (values[mid] == target)
        {
            return mid; // Lo encontró; devuelve este índice.
        }
        else if (values[mid] < target)
        {
            // El arreglo es descendente: buscar hacia índices menores.
            right = mid - 1;
        }
        else
        {
            // Buscar hacia índices mayores.
            left = mid + 1;
        }
    }

    return -1; // No lo encontró.
}

int main()
{
    int values[] = {9, 7, 7, 7, 5, 3, 1};
    int size = 7;

    std::cout << BinarySearch(values, size, 5) << '\n'; // 4: está en índice 4
    std::cout << BinarySearch(values, size, 4) << '\n'; // -1: no está

    return 0;
}



// Buscar la ultima aparición.

#include <iostream>

int BinarySearchLast(const int values[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int lastIndex = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (values[mid] == target)
        {
            lastIndex = mid; // Guarda esta aparición.
            left = mid + 1;  // Revisa si hay otra después.
        }
        else if (values[mid] < target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return lastIndex;
}

int main()
{
    int values[] = {9, 7, 7, 7, 5, 3, 1};
    int size = 7;

    std::cout << BinarySearchLast(values, size, 7) << '\n'; // 3
    std::cout << BinarySearchLast(values, size, 4) << '\n'; // -1

    return 0;
}


//Contar cuantas veces aparece.

#include <iostream>

int BinarySearchFirst(const int values[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int answer = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (values[mid] == target)
        {
            answer = mid;
            right = mid - 1; // Busca una aparición anterior.
        }
        else if (values[mid] < target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}

int BinarySearchLast(const int values[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int answer = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (values[mid] == target)
        {
            answer = mid;
            left = mid + 1; // Busca una aparición posterior.
        }
        else if (values[mid] < target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}

int CountOccurrences(const int values[], int size, int target)
{
    int first = BinarySearchFirst(values, size, target);

    if (first == -1)
    {
        return 0; // No apareció ninguna vez.
    }

    int last = BinarySearchLast(values, size, target);

    return last - first + 1;
}

int main()
{
    int values[] = {9, 7, 7, 7, 5, 3, 1};
    int size = 7;

    std::cout << CountOccurrences(values, size, 7) << '\n'; // 3
    std::cout << CountOccurrences(values, size, 4) << '\n'; // 0

    return 0;
}

*/




