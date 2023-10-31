
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
