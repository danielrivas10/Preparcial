#include <iostream>

//Parte 3.1 ALGORITMOS
void InsertionSort(int values[], int size, int start, int end)
{
    
    if (size <= 0 || start < 0 || end >= size || start > end)
    {
        return;
    } /*
    
size <= 0: el arreglo no tiene elementos.
start < 0: el inicio está antes del arreglo.
end >= size: el final queda fuera del arreglo.
start > end: el segmento está al revés.

    */

    
    for (int i = start + 1; i <= end; ++i)
    {
        int key = values[i]; //key toma el valor de start. En este caso como es 2[+1]= 3.
        int j = i - 1; //2.
        //O sea esto quiere decir que el numero posición 3 es evaluado con el numero posición 2.

        
        while (j >= start && values[j] > key)
        {
            values[j + 1] = values[j]; 
            /*
            Copia el 5 de la casilla 2 a la casilla 3:
Índice:     2   3
Valores:   [5] [5]
            */


            --j; //Solo hace que el while termine para comenzar con el siguiente elemento.
        }


/*
1. j >= start → 2 >= 2: verdadero. j todavía está dentro del segmento que ordenamos.
2. values[j] > key → values[2] > 4, es decir 5 > 4: verdadero.
Como las dos son verdaderas, entra al while y mueve el 5 a la derecha:       
*/
        values[j + 1] = key; //Como j + 1 vale 2, pone el 4 en values[2]. Para iniciar la segunda iteración. Vale 2 porque ya salio del ciclo while.

    }
}

int main()
{
    int values[] = {9, 7, 5, 4, 3, 8, 1, 6};
    int size = 8;

    InsertionSort(values, size, 2, 5); //Quiere decir, ayudame a ordenar las posiciones del 2-5 por favor.
// start=2, end=5;
    for (int i = 0; i < size; ++i)
    {
        std::cout << values[i] << " ";
    }

    std::cout << '\n';
    return 0;
}

/*

//Ordenar el arreglo de menor a mayor.

#include <iostream>

void InsertionSort(int values[], int size, int start, int end)
{
    if (size <= 0 || start < 0 || end >= size || start > end)
        return;

    for (int i = start + 1; i <= end; ++i)
    {
        int key = values[i]; // Valor que vamos a insertar.
        int j = i - 1;       // Empezamos comparando con el anterior.

        while (j >= start && values[j] > key)
        {
            values[j + 1] = values[j]; // Mueve el mayor a la derecha.
            --j;                       // Revisa una posición hacia la izquierda.
        }

        values[j + 1] = key; // Inserta key en el espacio disponible.
    }
}

int main()
{
    int values[] = {9, 7, 5, 4, 3, 8, 1, 6};
    int size = sizeof(values) / sizeof(values[0]);

    // start=0 y end=size-1: ordena el arreglo completo.
    InsertionSort(values, size, 0, size - 1);

    for (int i = 0; i < size; ++i)
        std::cout << values[i] << " ";

    std::cout << '\n';
    return 0;
}


//ordenar de mayor a menor.

#include <iostream>

void InsertionSortDescending(int values[], int size)
{
    if (size <= 0)
        return;

    for (int i = 1; i < size; ++i)
    {
        int key = values[i];
        int j = i - 1;

        // Mueve a la derecha los valores menores que key.
        while (j >= 0 && values[j] < key)
        {
            values[j + 1] = values[j];
            --j;
        }

        values[j + 1] = key;
    }
}

int main()
{
    int values[] = {9, 7, 5, 4, 3, 8, 1, 6};
    int size = sizeof(values) / sizeof(values[0]);

    InsertionSortDescending(values, size);

    for (int i = 0; i < size; ++i)
        std::cout << values[i] << " ";

    std::cout << '\n';
    return 0;
}






*/