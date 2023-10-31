
#ifndef LISTCLASS_QUEUE_H
#define LISTCLASS_QUEUE_H

#include <iostream>
#include <utility>


template <typename Object>
class Queue {
private:
    struct Node {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr) : data{d}, next{n} {}

        Node(Object &&d, Node *n = nullptr) : data{std::move(d)}, next{n} {}
    };

public:
    class iterator {
    public:
        iterator() : current{nullptr} {}

        Object &operator*() {
            if (current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() {
            if (current)
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

    private:
        Node *current;
        iterator(Node *p) : current{p} {}
        friend class Queue<Object>;
    };

public:
    Queue() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

    ~Queue() {
        clear();
        delete head;
        delete tail;
    }

    iterator begin() { return {head->next}; }

    iterator end() { return {tail}; }

    int size() const { return theSize; }

    bool empty() const { return size() == 0; }

    void clear() { while (!empty()) dequeue(); }

    Object &front() {
        if (empty())
            throw std::logic_error("Queue is empty.");
        return head->next->data;
    }


    void enqueue(const Object &x) { insert(end(), x); }

    void enqueue(Object &&x) { insert(end(), std::move(x)); }


    void dequeue() {
        if (empty())
            throw std::logic_error("Queue is empty.");
        erase(begin());
    }

    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        tail->next = new Node{x, nullptr};
        tail = tail->next;
        theSize++;
        return iterator(tail);
    }

    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        tail->next = new Node{std::move(x), nullptr};
        tail = tail->next;
        theSize++;
        return iterator(tail);
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




#endif //LISTCLASS_QUEUE_H
