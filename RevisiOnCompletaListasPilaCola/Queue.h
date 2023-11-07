
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
