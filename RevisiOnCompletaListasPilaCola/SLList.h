
#ifndef SLLLIST_H
#define SLLLIST_H

#include <iostream>
#include <utility>

template <typename Object> // Este es indicador de que estamos usando un template de la librería fundamental de C++ y nos permite trabajar con diferentes tipos de datos
class SLList { // Estamos asignándole nombre a la clase que en este caso será SLList
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
    public: // La clase iterador va a ser de tipo público porque queremos que pueda ser accesado por diferentes partes del código
        iterator() : current{nullptr} {} // Aquí el constructor inicializa el iterador diciendo que no apunta a ningún nodo


        // Aquí se hace una sobrecarga para el operador * y lo reconozca como puntero y hay una condición que dice que si el current es un puntero nulo, que mande un error
        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        // Esta es otra sobrecarga para el operador ++. Con verlo parece que es la iteración, el ir avanzando entre nodos. Simboliza un incremento. Este es el que Lee
        // Hay una condición para que siga avanzando y otro mensaje para que ya no lo haga porque llegó al último nodo
        // un -- sería para retroceder pero esto solo se puede hacer en una doble lista porque hay flujo bi-direccional. En la sencilla no se puede porque solo va hacia adelante en una dirección
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
        // El diferente de, es para que la lista pueda evaluar condiciones (concepto similar al de un while)
        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }


    private:
        Node *current; // Representa el nodo actual al que apunta el iterador.
        iterator(Node *p) : current{p} {} // Este es otro constructor con un parámetro y que inicializa el valor de p en current
        friend class SLList<Object>; // friend class/ es una forma de decirle que a mis atributos privados puedo entrar yo como iterador o a lista para modificarla
    };


// Esto parece ser otro constructor que define e inicio, el final y el tamaño de cada nodo
public:
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail; // Es para definir el mínimo que debe de tener una lista que es un inicio y final y ya de ahí puedo meterle más nodos pero x default debe de tener esos dos
    }
// Este es el destructor, que limpia la memoria del inicio (head) o el tail (final)
// Primero borra todos los elementos de la lista y luego borra los espacios de memoria para la cabeza y cola
    ~SLList() {
        clear();
        delete head;
        delete tail;
    }


    iterator begin() { return {head->next}; } // Esta es una función que hace que el iterador comience desde head (inicio) y se vaya con el siguiente // Nos va a dar un iterador al inicio
    iterator end() { return {tail}; } // Esta es una función que hace que cuando el iterador sepa cuando llega al final de la lista (tail) // nos va a dar un iterador al final

    int size() const { return theSize; } // Función para que regrese el tamaño de la lista y saber cuanto se va a iterar
    bool empty() const { return size() == 0; } // Función para saber si la lista está vacía

    void clear() { while (!empty()) pop_front(); } // Función para limpiar todos los elementos que estén en la lista

    Object &front() { // Esta es una función para revisar el primer valor de la lista y verificar si está vacío // si la lista no está vacia, regresa al elemento de hasta enfrente
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    void push_front(const Object &x) { insert(begin(), x); } // Es una función para insertar un nuevo elemento al inicio de la lista
    void push_front(Object &&x) { insert(begin(), std::move(x)); } // Es una función similar a la anterior
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
            throw std::logic_error("Cannot erase at end iterator"); // Aquí hace una validación donde si el iterador está apuntando al final de la lista, salga un error
        Node *p = head; // Inicializa un puntero al inicio del nodo
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current; // Borra el nodo al que está apuntando el iterador
        theSize--; // Decrementa el tamaño de la lista para reflejar lo que se borró
        return iterator(p->next);
    }

    void print() { // Esta es una función para imprimir la lista, va desde el inicio hasta el final. Es un Getter
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private: // se van a delimitar los miembros que son privados para que no puedan ser modificados desde otra parte de la clase
    Node *head; // Es un puntero al inicio de la lista
    Node *tail; // Es un puntero al final de la lista
    int theSize; // guarda el tamaño de la lista
    void init() { // Es el inicializador o constructor para inicializar una lista vacía
        theSize = 0; // Hace que el tamaño inicial de la lista sea cero
        head->next = tail; // Hace que desde el inicio de la lista siga moviendo los nodos hasta que llegue al final
    }
};

#endif