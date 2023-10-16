#include <iostream>
#include "SLList.h"
#include "DLList.h"

int main() {
    // Test Simple List
    SLList<int> simpleList;
    simpleList.push_front(20);
    simpleList.push_front(10);
    simpleList.push_front(30);
    simpleList.push_front(40);
    simpleList.push_front(50);
    std::cout << "Simple list: ";
    simpleList.print();
    simpleList.pop_front();
    std::cout << "Simple list after pop: ";
    simpleList.print();
    simpleList.clear();
    std::cout << "Simple list after clear: ";
    simpleList.print();

    // Test integer Double Linked List
    DLList<int> integerList;
    integerList.push_back(10);
    integerList.push_front(20);
    integerList.insert(1, 40);
    int a =3;
    integerList.insert(integerList.begin()+2, 30);
    integerList.insert(a, 12);
    std::cout << "Integer list: ";
    integerList.print();
    (void)integerList.erase(integerList.begin() + 1);
    std::cout << "Integer list after erase: ";
    integerList.print();
    integerList.clear();
    std::cout << "Integer list after clear: ";
    integerList.print();







    return 0;
}