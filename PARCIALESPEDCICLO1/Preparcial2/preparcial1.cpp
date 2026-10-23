/* Sección I. Listas doblemente enlazadas*/

#include <iostream>

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

void Insert(Node *&head, int value)
{
  Node *new_node = new Node{value, nullptr, nullptr};

  if (head == nullptr)
  {
    head = new_node;
    return;
  }

  Node *current = head; 

  while (current->next != nullptr)
  {
    current = current->next;
  }

  current->next = new_node;
  new_node->prev = current;
}
// Punto 1.1 insertar después de un valor.
// Resultado esperado: 10 20 25 30 40 50

bool InsertAfter(Node *head, int target, int value)
{

  Node *current = head;
  while (current != nullptr && current->data != target) // current avanza porque no ha encontrado todavia el objetivo del ejercicio.
  {

    current = current->next;
  }
  if (current == nullptr)
  {

    return false;
  }
//Es como {data, next, prev}
  Node *new_node = new Node{value, current->next, current}; // Crea el nuevo nodo con el  dato buscado.

  if (new_node->next != nullptr)
  {
    new_node->next->prev = new_node; // new_node->next apunta a 30, así que hacemos que 30.prev apunte al nodo nuevo:
  }

  current->next = new_node; // Como current apunta a 20, ahora 20.next apunta a 25.

  return true;
}
//entendido.

// Punto 1.2 Separar una lista por posición.
void SplitByPosition(Node *&head, Node *&even_head, Node *&odd_head) // even_head es par, odd_head es impar.
{
  //(Además, even head es el primer nodo de los pares, even tail es el ultimo nodo de esa lista y asi.)

  Node *current = head;
  int position = 0; // Para saber si debe ir a even_head o a odd_head.
  Node *even_tail = nullptr;
  Node *odd_tail = nullptr;
  while (current != nullptr)
  {
    Node *next_node = current->next; //O sea el siguiente valor que apunta current.Esto para desconectar el valor de current.
    if (position % 2 == 0)
    {
      current->prev = nullptr; //Ahora 10 ya no apunta ni atras
      current->next = nullptr;  //Ni adelante.

      if (even_tail == nullptr)
      {
        even_head = current; //Ahora toman el valor de 10.
        even_tail = current;
      }
      else
      {
        current->prev = even_tail; //El anterior del nodo actual (30) apunta al último par (10).
        even_tail->next = current; // El siguiente del último par (10) apunta al nodo actual (30). // even_head ► [10] ⇄ [30] ◄─ even_tail
        even_tail = current; // Actualiza even_tail para que ahora apunte a 30.
      }
    }
    else
    {
      current->prev = nullptr; //Acá es para los impares.
      current->next = nullptr;

      if (odd_tail == nullptr)
      {
        odd_head = current; //Acá se toma el valor de los impares desconectados de la original.
        odd_tail = current;
      }
      else
      {
        current->prev = odd_tail;
        odd_tail->next = current;
        odd_tail = current; 
      }
    }
    current = next_node; //Esto pasa despues de guardar 10. Ahora current apunta a 20.
    // En la siguiente vuelta, current ya significa “estoy procesando el nodo 20”. Al final de esa vuelta, se repetirá lo mismo para avanzar a 30
    position++; //Ahora posicion vale 1 y así.
  }
  head = nullptr;
}

// Punto 1.3
void MoveLastToFront(Node *&head)
{
  // Una lista vacía o con un solo nodo no necesita cambios.
  if (head == nullptr || head->next == nullptr)
  {
    return;
  }

  // Buscar el último nodo.
  Node *last = head;
  while (last->next != nullptr) // Cuando last apunta a 30, last->next es nullptr, así que el ciclo termina.
  {
    last = last->next;
  }

  // Guardar el nodo anterior a last. before_last → [20] ⇄ [30] ← last
  Node *before_last = last->prev;

  // Desconectar el último de su posición actual.
  before_last->next = nullptr; // last todavía apunta a 30; el nodo no se borró. Solo se cortó su enlace desde 20.
  /*
    head           last
    ↓               ↓
  [10] ⇄ [20]      [30]
  */

  // Colocar el último antes del antiguo primero.
  last->prev = nullptr;
  last->next = head; // “En el nodo señalado por last (el 30), guarda en su campo next la dirección a la que apunta head (el 10).”
  head->prev = last; //Ahora ambos se apuntan directamente.

  // Actualizar el inicio de la lista.
  head = last; //head ahora es 30.
}

void PrintForward(Node *head)
{
  Node *current = head;

  while (current != nullptr)
  {
    std::cout << current->data << " ";
    current = current->next;
  }

  std::cout << '\n';
}

void PrintBackward(Node *head)
{
  if (head == nullptr)
  {
    return;
  }

  Node *current = head;

  while (current->next != nullptr)
  {
    current = current->next;
  }

  while (current != nullptr)
  {
    std::cout << current->data << " ";
    current = current->prev;
  }

  std::cout << '\n';
}

int main()
{

  // Prueba de SplitByPosition
  Node *head = nullptr;
  Node *even_head = nullptr;
  Node *odd_head = nullptr;

  Insert(head, 10);
  Insert(head, 20);
  Insert(head, 30);
  Insert(head, 40);
  Insert(head, 50);
  Insert(head, 60);
  Insert(head, 70);

  SplitByPosition(head, even_head, odd_head);

  std::cout << "Pares hacia adelante: ";
  PrintForward(even_head);   // 10 30 50 70

  std::cout << "Pares hacia atrás: ";
  PrintBackward(even_head);  // 70 50 30 10

  std::cout << "Impares hacia adelante: ";
  PrintForward(odd_head);    // 20 40 60

  std::cout << "Impares hacia atrás: ";
  PrintBackward(odd_head);  // 60 40 20


  // Prueba de MoveLastToFront
  Node *move_head = nullptr;

  Insert(move_head, 10);
  Insert(move_head, 20);
  Insert(move_head, 30);
  Insert(move_head, 40);
  Insert(move_head, 50);

  MoveLastToFront(move_head);

  std::cout << "Lista después de mover el último al frente: ";
  PrintForward(move_head);   // 50 10 20 30 40

  std::cout << "La misma lista hacia atrás: ";
  PrintBackward(move_head);  // 40 30 20 10 50

  return 0;
}










/*Por si debo de mover el ultimo nodo a cualquier lugar

// 10 ⇄ 20 ⇄ 30 ⇄ 40 ⇄ 50 -> 10 ⇄ 20 ⇄ 50 ⇄ 30 ⇄ 40

bool MoveLastToPosition(Node *&head, int position)
{
  // No se puede mover si la lista está vacía o la posición no es válida.
  if (head == nullptr || position < 1)
  {
    return false;
  }

  // Buscar el último nodo.
  Node *last = head;
  int length = 1;

  while (last->next != nullptr)
  {
    last = last->next;
    length++;
  }

  // La posición debe existir después de sacar el último nodo.
  if (position >= length)
  {
    return false;
  }

  // Desconectar el último de su lugar.
  Node *before_last = last->prev;
  before_last->next = nullptr;

  // Buscar el nodo que actualmente ocupa la posición anterior a la deseada.
  Node *current = head;
  for (int i = 1; i < position - 1; i++)
  {
    current = current->next;
  }

  // Insertar last después de current.
  last->next = current->next;
  last->prev = current;

  current->next->prev = last;
  current->next = last;

  return true;
}

int main()
{
  Node *head = nullptr;

  Insert(head, 10);
  Insert(head, 20);
  Insert(head, 30);
  Insert(head, 40);
  Insert(head, 50);

  std::cout << "Antes:   ";
  PrintForward(head);

  int position = 2; //Con esto lo cambias de posición, a donde quieres que vaya.
  MoveLastToPosition(head, position);

  std::cout << "Despues: ";
  PrintForward(head);
}







// La llamada especifica el orden: MoveAfter(head, 10, 30);
// Significa “mueve el nodo con valor 10 y colócalo después del nodo con valor 30”

bool MoveAfter(Node *&head, int value, int targetValue)
{
  Node *moving = head;
  while (moving != nullptr && moving->data != value)
  {
    moving = moving->next;
  }

  Node *target = head;
  while (target != nullptr && target->data != targetValue)
  {
    target = target->next;
  }

  if (moving == nullptr || target == nullptr)
  {
    return false; // No encontró alguno de los valores.
  }

  if (moving == target)
  {
    return true; // Es el mismo nodo; no hay que moverlo.
  }

  // Primero desconecta el nodo que se va a mover.
  if (moving->prev != nullptr)
  {
    moving->prev->next = moving->next;
  }
  else
  {
    head = moving->next; // moving era el primero; actualiza head.
  }

  if (moving->next != nullptr)
  {
    moving->next->prev = moving->prev;
  }

  // Luego inserta moving después de target.
  moving->prev = target;
  moving->next = target->next;

  if (target->next != nullptr)
  {
    target->next->prev = moving;
  }

  target->next = moving;

  return true;
}

int main()
{
  Node *head = nullptr;

  Insert(head, 10);
  Insert(head, 20);
  Insert(head, 30);
  Insert(head, 40);
  Insert(head, 50);

  std::cout << "Antes:   ";
  PrintForward(head);

  bool moved = MoveAfter(head, 10, 30); //Se cambia esto.

  if (moved)
  {
    std::cout << "Despues: ";
    PrintForward(head);
  }
  else
  {
    std::cout << "No se pudo mover el nodo.\n";
  }

  return 0;
}




// Eliminar la primera aparición de un valor.

#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void Insert(Node*& head, int value)
{
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

bool RemoveFirst(Node*& head, int target)
{
    Node* current = head;

    // Avanza hasta encontrar la primera aparición de target.
    while (current != nullptr && current->data != target)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        return false; // No encontró el valor.
    }

    if (current->prev != nullptr)
    {
        // El nodo anterior salta sobre current.
        current->prev->next = current->next;
    }
    else
    {
        // current era el primer nodo.
        head = current->next;
    }

    if (current->next != nullptr)
    {
        // El nodo siguiente apunta hacia el anterior de current.
        current->next->prev = current->prev;
    }

    delete current; // Libera el nodo eliminado.

    return true;
}

void PrintForward(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << '\n';
}

int main()
{
    Node* head = nullptr;

    Insert(head, 10);
    Insert(head, 20);
    Insert(head, 30);
    Insert(head, 20);
    Insert(head, 40);

    std::cout << "Antes:   ";
    PrintForward(head);

    bool removed = RemoveFirst(head, 20);

    if (removed)
    {
        std::cout << "Despues: ";
        PrintForward(head);
    }
    else
    {
        std::cout << "No se encontro el valor.\n";
    }

    return 0;
}




//Invertir toda la lista.

#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void Insert(Node*& head, int value)
{
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void ReverseList(Node*& head)
{
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr)
    {
        // Guarda el enlace anterior original.
        temp = current->prev;

        // Intercambia los enlaces del nodo actual.
        current->prev = current->next;
        current->next = temp;

        // Avanza usando el enlace que era next antes del intercambio.
        current = current->prev;
    }

    if (temp != nullptr)
    {
        // El último nodo recorrido ahora es el primero.
        head = temp->prev;
    }
}

void PrintForward(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << '\n';
}

int main()
{
    Node* head = nullptr;

    Insert(head, 10);
    Insert(head, 20);
    Insert(head, 30);
    Insert(head, 40);

    std::cout << "Antes:   ";
    PrintForward(head);

    ReverseList(head);

    std::cout << "Despues: ";
    PrintForward(head);

    return 0;
}















*/