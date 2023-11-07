
# **Mario Alberto Montes Girón** 
**Programación III** | 

**Documentación de una Clase: Lista - Lista Doble - Pila - Cola** |

**6 de Noviembre del 2023**

En este proyecto vamos a documentar los códigos vistos en clase para una Lista Sencilla, una Lista Doble, una Pila y una Cola.

### Lista Sencilla
El primer código que se va a analizar es el del  "SLList.h"


"Una lista lineal es un conjunto de elementos de un tipo dado que se encuentran ordenados y pueden variar en número. Permite el recorrido de todos y cada uno de sus elementos, sin saltear ninguno y en forma ordenada.

Algunos ejemplos de listas son los siguientes:

1. Guía telefónica

2. Lista de asistencia a un curso

3. Índice de un libro

4. Listado de compras

5. Listado de ingredientes de una receta

Una lista enlazada o encadenada es un conjunto de elementos mas un campo especial que contiene el pun-tero al elemento siguiente de la lista.

Cada elemento de la lista debe tener al menos dos campos: 

1. Elemento o dato.
2. Enlace, link, conexión al siguiente elemento.

Los elementos de una lista son enlazados por medio de los campos enlaces." [1]

Ahora sí, pasemos a revisar el código documentado:

```c++


#ifndef SLLLIST_H
#define SLLLIST_H

#include <iostream>
#include <utility>

template <typename Object> // Este es indicador de que estamos usando un template de la librería fundamental de C++
class SLList { // Estamos asingándole nombre a la clase que en este caso será SLList
private: // Comenzaremos con los constructores privados, aquellos que no queremos sean cambiados en ningúna otra parte del código

    struct Node  { // En esta parte vamos a crear el flujo de los Nodos (que son los elementos de la lista)
        Object data; // Estamos definiendo que cada elemento en la lista se va a llamar Data
        Node *next;// Estamos definiendo que cada puntero (que sirve para conectar los nodos) se va a llamar next

        // Este es un constructor para la estructura del Nodo. Lleva dos parámetros (uno para el objeto y otro para el nodo).
        // Constructor por copia
        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n} {}

         // Este es un constructor para la estructura del Nodo. Lleva dos parámetros (uno para el objeto y otro para el nodo).
        // Constructor por referencia
        Node(Object &&d, Node *n = nullptr)
                : data{std::move(d)}, next{n} {}
    };

public:
    class iterator { // Para que una lista funcione, se necesita de un iterador y aquí lo estamos creando
    public: // La clase iterador va a ser de tipo publico porque queremos que pueda ser accesado por diferentes partes del código
        iterator() : current{nullptr} {} // Aquí el constructor inicializa el iterador diciendo que no apunta a ningun nodo


        // Aquí se hace una sobrecarga para el operador * y lo reconozca como puntero y hay una condición que dice que si el current es un puntero nulo, que mande un error
        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        // Esta es otra sobrecarga para el operador ++. Con verlo parece que es la iteración, el ir avanzando entre nodos. Simboliza un incremento. Este es el que Lee
        // Hay una condición para que siga avanzando y otro mensaje para que ya no lo haga porque llegó al ultimo nodo
        // un -- sería para retroceder pero esto solo se puede hacer en una doble lista porque hay flujo bi-direccional. En la sencilla no se puede porque solo va hacia adelante en una direccion
        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }


        // Aquí se está haciendo otra sobrecarga para el operador ++ pero con un valor int.
        // Este segundo iterador es el que lleva los conteos y el primero (anterior) es el que lee
        iterator operator++(int) {
            iterator old = *this;
            ++(*this); // Esto representa la operación actual de sumarle 1 al valor que ya se tenía
            return old;
        }



        // Aquí se está haciendo otra sobrecarga para el operador ==
        // El igual es para que la lista pueda evaluar condiciones (concepto similar al de un while)
        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }

        // Aquí se está haciendo otra sobrecarga para el operador !=
        // El diferente de es para que la lista pueda evaluar condiciones (concepto similar al de un while)
        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }


    private:
        Node *current; // Representa el nodo actual al que apunta el iterador. NO ENTIENDO para qué es necesario/ guarda el orden del iterador como objeto
        iterator(Node *p) : current{p} {} // Este es otro constructor con un parámetro y que inicializa el valor de p en current
        friend class SLList<Object>; // friend class/ es una forma de decirle que a mis atributos privados puedo entrar yo como iterador o a lista para modificarla
    };


// Esto parece ser otro constructor que define e inicio, el final y el tamaño de cada nodo
public:
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail; // Es para definir el minimo que debe de tener una lista que es un inicio y final y ya de ahí puedo meterle mas nodos pero x default debe de tener esos dos
    }
// Este es el destructor, que limpia la memoria del inicio (head) o el tail (final)
// Primero borra todos los elementos de la lista y leugo borra los espacios de memoria para la cabeza y cola
    ~SLList() {
        clear();
        delete head;
        delete tail;
    }


    iterator begin() { return {head->next}; } // Esta es una función que hace que el iterador comience desde head (inicio) y se vaya con el siguiente // Nos va a dar un iterador al inicio
    iterator end() { return {tail}; } // Esta es una función que hace que cuando el iterador sepa cuando llega al final de la lista (tail) // nos va a dar un iterador al final

    int size() const { return theSize; } // Función para que regrese el tamaño de la lista y saber cuanto se va a iterar
    bool empty() const { return size() == 0; } // Función para saber si la lista está vacía

    void clear() { while (!empty()) pop_front(); } // Función para limpiar todos los elementos que estén en la lista//

    Object &front() { // Esta es una función para revisar el primer valor de la lista y verificar si está vacío // si la lista no está vacia, regresa a el elemento de hasta enfrente
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    void push_front(const Object &x) { insert(begin(), x); } // Es una función para insertar un nuevo elemento al inicio de la lista
    void push_front(Object &&x) { insert(begin(), std::move(x)); } // Es una función similar a la anterior.
    // Son dos porque uno es por copia y otro por referencia

    void pop_front() { // Es una función que quita el primer elemento deu na lista. Si ya está vacío, manda un error
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    iterator insert(iterator itr, const Object &x) { // Esta función inserta un elemento en la posición inmediata anterior a la que esté apuntando el iterador/ la x representa el valor que se le va a insertar
        Node *p = itr.current; // Genera un puntero en el nodo que esté apuntando el iterador
        head->next = new Node{x, head->next};
        theSize++; // Esto es un incremento en el tamaño de la lista como consecuencia de haber insertado un elemento
        return iterator(head->next); // Regresa un iterador que apunta al nuevo nodo insertado en la lista
    }

    // Esto es similar al código anterior pero aplicado por referencia &&
    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }


    iterator erase(iterator itr) { // Esta es una función que quita el elemento al que está apuntado el iterador
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator"); // Aquí hace una validación donde si el iterador está apuntdo al final de la lista, salga un error
        Node *p = head; // Inicializa un puntero al inicio del nodo
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current; // Borra el nodo al que está apuntando el iterador
        theSize--; // Decrementa el tamaño de la lista para reflejar lo que se borró
        return iterator(p->next);
    }

    void printList() { // Esta es una función para imprimir la lista, va desde el inicio hasta el final. Es un Getter
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private: // se van a delimitar los miembors que son privados para que no puedan ser modificados desde otra parte de la clase
    Node *head; // Es un puntero al inicio de la lista
    Node *tail; // Es un puntero al final de la lista
    int theSize; // guarda el tamaño de la lista
    void init() { // Es el inicializador o constructor para inicializar una lista vacia
        theSize = 0; // Hace que el tamaño inicial de la lista sea cero
        head->next = tail; // Hace que desde el inicio de la lista siga moviendo los nodos hasta que llegue al final
    }
};

#endif

```

### Lista Doble

El segundo código que vamos a analizar es el de DLList.h.

"Es un tipo de lista enlazada que permite moverse hacia delante y hacia atras.

Cada nodo de una lista doblemente enlazada tiene dos enlaces, ademas de los campos de datos. 
Un enlace, el derecho, se utiliza para navegar la lista hacia delante. 

El otro enlace, el isquierdo, se utiliza para navegar la lista hacia atras.

Las Listas pueden navegarse hacia delante y hacia atras.

Las Listas pueden crear, actualizar y eliminar elementos.

En las Listas la posicion de los elementos es relevante.

Las Listas admiten elementos duplicados.

Las Listas tienen dos protocolos, uno secuencial y el otro directo." [2]

Veamos el código documentado:

```c++

#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include <utility>

// La clase DLList es muy similar a la SLList. Solo estoy comentando las líneas que se tuvieron que agregar

template <typename Object>
class DLList {
private:
    struct Node  {
        Object data;
        Node *next;
        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n} {}

        Node(Object &&d, Node *n = nullptr)
                : data{std::move(d)}, next{n} {}
    };

public:
    class iterator {
    public:

        iterator() : current{nullptr} {}

        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

        // Esta es una sobrecarga adicional que se tuvo que agregar para que mi DLLista reconociera el operador + y así poder insertar valores en la lista a través de adiciones
        // Esto no estaba en la SLList y por eso fue necesario agregarlo
        iterator operator+(int n) const {
            iterator iter = *this;
            for (int i = 0; i < n; ++i) {
                if (iter.current == nullptr)
                    throw std::out_of_range("Iterator out of range");
                ++iter;
            }
            return iter;
        }



    private:
        Node *current;
        iterator(Node *p) : current{p} {}
        friend class DLList<Object>;
    };


public:
    DLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

    ~DLList() {
        clear();
        delete head;
        delete tail;
    }

    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    void clear() { while (!empty()) pop_front(); }

    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    void push_front(const Object &x) { insert(begin(), x); }
    void push_front(Object &&x) { insert(begin(), std::move(x)); }

    // Este es otro elemento que se agregó en la DLList y que no estaba en la SLList.
    void push_back(const Object &x) { insert(end(), x); } // Hace que pueda agregar elementos al final de mi lista por copia
    void push_back(Object &&x) { insert(end(), std::move(x)); } // Hace que pueda agregar elementos al final de mi lista por referencia

    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }

    // Esta es otra función que no estaba en mi SLLIST y que es necesario agregar en la DLLIST
    // Lo que hace a grandes rasgos es poder insertar un valor en mi lista en una posición en específico
    // Una es por copia y otra por referencia. Comentaré únicamente la de copia

    iterator insert(int index, const Object &x) {
        if (index < 0 || index > theSize)
            throw std::out_of_range("Index out of range"); // Aquí evalúa que la posición deseada sea permitida

        Node *p = head; // Aquí se hace la navegación de los nodos hasta llegar al indicado
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }

        p->next = new Node{x, p->next}; // Se crea el nuevo nodo en la posición deseada
        theSize++;
        return iterator(p->next);
    }

    iterator insert(int index, Object &&x) {
        if (index < 0 || index > theSize)
            throw std::out_of_range("Index out of range");

        Node *p = head;
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }

        p->next = new Node{std::move(x), p->next};
        theSize++;
        return iterator(p->next);
    }


    iterator erase(iterator itr) {
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }

    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private:
    Node *head;
    Node *tail;
    int theSize;
    void init() {
        theSize = 0;
        head->next = tail;
    }
};


#endif //LISTCLASS_DLLIST_H

```
### Pila

El tercer código que vamos a analizar es el de Stack.h.


"Una pila (stack en inglés) es una lista ordinal o estructura de datos en la que el modo de acceso a sus elementos es de tipo LIFO (del inglés Last In First Out, último en entrar, primero en salir) que permite almacenar y recuperar datos. 

Esta estructura se aplica en multitud de ocasiones en el área de informática debido a su simplicidad y ordenación implícita de la propia estructura.

Para el manejo de los datos se cuenta con dos operaciones básicas: apilar (push), que coloca un objeto en la pila, y su operación inversa, retirar (o desapilar, pop), que retira el último elemento apilado." [3]

Así es cómo se ve el código documentado:

```c++


#ifndef LISTCLASS_STACK_H
#define LISTCLASS_STACK_H


#include <iostream>
#include <stdexcept>


template <typename Object> // Este es indicador de que estamos usando un template de la librería fundamental de C++ y nos permite trabajar con diferentes tipos de datos
class Stack { // Estamos asignándole nombre a la clase que en este caso será Stack
private:
    struct Node { // Esta es una estructura que representa los miembros individuales en la pila que son los nodos
        Object data; // Datos - Nodos
        Node* next; // Puntero
        Node(const Object& data, Node* next = nullptr) : data(data), next(next) {} // Aquí se ve el funcionamiento de cada nodo apuntando al siguiente
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {} // Este es un puntero que "apunta" a la parte de arriba de la pila

    void push(const Object& value) { // Esta es una función que agrega un nodo hasta arriba de la pila
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
    }

    void pop() { // Esta es una función que quita el elemento de arriba de la pila
        if (!isEmpty()) { // Primero checa si la pila no está vacía para proceder
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    Object& top() { // Esta es una función para saber cuál es el dato que se encuentra hasta arriba en la pila
        if (!isEmpty()) { // Primero checa si la pila no está vacía para proceder
            return topNode->data;
        } else {
            throw std::runtime_error("Stack is empty."); // Si está vacío, manda un mensaje de error
        }
    }

    bool isEmpty() const { // Checa si la pila está vacía
        return topNode == nullptr;
    }

    void print() const { // Esta función navega por toda la pila e imprime el dato que se encuentra en cada nodo
        Node* current = topNode;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() { // Esta función quita los elementos que se encuentran en cada nodo hasta que quede todo vacío
        while (!isEmpty()) {
            pop();
        }
    }

    ~Stack() { // Este es el destructor que se encarga de llamar a la función Clear
        clear();
    }
};


#endif //LISTCLASS_STACK_H


```
### Pila

El cuarto y último código que vamos a analizar es el de Queue.h.

"Una cola es una estructura de datos que almacena elementos en una lista y permite acceder a los datos por uno de los dos extremos de la lista.

Un elemento se inserta en la cola (parte final) de la lista y se suprime o elimina por la frente (parte inicial, cabeza) de la lista.

Los elementos se eliminan (se quitan) de la cola en el mismo orden en que se
almacenan y, por consiguiente, una cola es una estructura de tipo FIFO(first-in-first-out)." [4]

Y finalmente así es cómo se ve nuestro código documentado:

```c++

#ifndef LISTCLASS_QUEUE_H
#define LISTCLASS_QUEUE_H

#include <iostream>
#include <utility>

// Aquí se está creando la clase llamada Queue que opera con un tipo de dato llamado Object
template <typename Object>
class Queue {
private:
    struct Node { // Aquí estamos creando una estructura anidada llamada Nodo que guarda datos y tiene punteros al siguiente nodo
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr) : data{d}, next{n} {} // Constructor por copia

        Node(Object &&d, Node *n = nullptr) : data{std::move(d)}, next{n} {} // Constructor por referencia
    };

public:
    class iterator { // Aquí creamos una clase llamada iterator
    public:
        iterator() : current{nullptr} {} // Este es un constructor para el iterator en el que se inicializa el miembro "current" con el "nullptr"

        Object &operator*() { // Esta es una sobrecarga para el operador * para que el iterator borre la información en el nodo
            if (current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() { // Esta es una sobrecarga para el operador ++ para que el iterator se pueda mover al siguiente nodo
            if (current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) { // No entiendo bien por qué hay otra sobre carga del mismo operador. Puede que sea para hacer incrementos adicionales (?)
            iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const iterator &rhs) const { // Esta es otra sobrecarga para el operador == para que la clase iterator compare iteradores
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const { // Esta es otra sobrecarga para el operador != para que la clase iterator compare iteradores
            return !(*this == rhs);
        }

    private:
        Node *current; // Se declara un miembro privado de la clase llamado current de tipo nodo para poder llevar la cuenta de cuál es el nodo actual
        iterator(Node *p) : current{p} {} // Este es un constructor que inicializa current con el puntero asignado
        friend class Queue<Object>; // Esto hace que Queue se haga amiga de la clase iterator para que pueda acceder a sus miembros privados
    };

public:
    Queue() : head(new Node()), tail(new Node()), theSize(0) { // Este es un constructor para la clase Queue. Inicializa el inicio y el fin con sus respectivos nodos e indica que el tamaño de la cola va a ser de 0.
        head->next = tail;
    }

    ~Queue() { // Este es el destructor. Limpia la memoria de los nodos.
        clear();
        delete head;
        delete tail;
    }

    iterator begin() { return {head->next}; } // Esta línea regresa un iterador que apunta al primer elemento de la cola

    iterator end() { return {tail}; } // Esta línea regresa un iterador apuntando al último elemento de la cola

    int size() const { return theSize; } // Esta línea regresa el tamaño de la cola

    bool empty() const { return size() == 0; } // Esta línea checa si la cola está vacía

    void clear() { while (!empty()) dequeue(); } // Esta línea limpia la cola al quitar a todos los elementos que estén en espera

    Object &front() { // Esta es una función para que regrese una referencia a la información almacenada en el nodo que está al frente de la cola
        if (empty())
            throw std::logic_error("Queue is empty.");
        return head->next->data;
    }


    void enqueue(const Object &x) { insert(end(), x); } // Esta línea hace que metamos un elemento a la cola

    void enqueue(Object &&x) { insert(end(), std::move(x)); } // Lo mismo que la anterior pero por referencia


    void dequeue() { // Esta función hace que quitemos un elemento al inicio de la cola
        if (empty())
            throw std::logic_error("Queue is empty.");
        erase(begin());
    }

    iterator insert(iterator itr, const Object &x) { // Esta función es para insertar un elemento en una posición específica de la cola
        Node *p = itr.current;
        tail->next = new Node{x, nullptr};
        tail = tail->next;
        theSize++;
        return iterator(tail);
    }

    iterator insert(iterator itr, Object &&x) { // Lo mismo que la anterior pero por referencia
        Node *p = itr.current;
        tail->next = new Node{std::move(x), nullptr};
        tail = tail->next;
        theSize++;
        return iterator(tail);
    }



    iterator erase(iterator itr) { // Esta función elimina de la cola un elemento en una posición en específico
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }

    void print() { // Función para imprimir los elementos en la cola
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private:
    Node *head; // Declara un miembro privado llamado head de tipo nodo para llevar registro del nodo que va al frente
    Node *tail; // Declara un miembro privado llamado head de tipo nodo para llevar registro del nodo que va atrás
    int theSize; // Esta línea declara un miembro privado para llevar registro del tamaño de la cola
    void init() { // Esta línea es un método para inicializar el tamaño de la cola y el puntero que está en camino hacia el último nodo
        theSize = 0;
        head->next = tail;
    }
};


#endif //LISTCLASS_QUEUE_H


```












### Fuentes

[1] Rodrigo Paszniuk, “Listas en C++”. [Online]. Disponible : https://www.programacion.com.py/escritorio/c/listas-en-c. [Consultado Octubre. 5, 2023].

[2] FCEIA, “Estructura de Datos: Lista Enlazada Doble”. [Online]. Disponible : https://www.fceia.unr.edu.ar/estruc/2005/listendo.htm. [Consultado Noviembre. 6, 2023].

[3] Martín Cruz, “Pilas en C++”. [Online]. Disponible : https://blog.martincruz.me/2012/10/pilas-en-c.html. [Consultado Noviembre. 6, 2023].

[4] UV, “Estructuras de Datos”. [Online]. Disponible : https://www.uv.mx/personal/ermeneses/files/2021/08/Clase6-ColasFinal.pdf. [Consultado Noviembre. 6, 2023].