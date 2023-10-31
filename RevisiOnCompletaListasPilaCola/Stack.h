
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
