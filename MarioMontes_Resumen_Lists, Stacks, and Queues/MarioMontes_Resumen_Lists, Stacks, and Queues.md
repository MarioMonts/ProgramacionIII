
**Mario Alberto Montes Girón**

**Resumen: Listas, Stacks, and Queues - página 77 a 103**

**3.1 Abstact Data Types (ADTs)**

### Ideas Principales:

1. An abstract data type (ADT) is a set of objects together with a set of operations.

2. Objects such as lists, sets, and graphs, along with their operations, can be viewed as ADTs, just as integers, reals, and booleans are data types.

3. The C++ class allows for the implementation of ADTs.

### Opinión Crítica y Conclusiones:

Los ADTs son basicamente otro tipo de datos. Así como los que conozco al día de hoy (Int, Float, etc.) y es por eso que operaciones aritméticas pueden ser ejecutadas con este tipo de datos. Yo nunca había escuchado antes de este tipo de datos y tampoco lo he implementado.

-------------------------------------------------------------------------------------------------------
**3.2 The List ADT**

### Ideas Principales

1. The first element of the list is A0

2. The last element is AN−1.
3. The position of element Ai in a list is i.
4. Elements in a list asre usually integers but any type of elements are allowed
5. Some popular operations are printList, makeEmpty, insert, remove and findKth
6. To use an array, an estimate of the maximum size of the list was required. This estimate is no longer needed (with a List).
7. If insertions and deletions occur throughout the list and at the front of the list, then the array is not a good option. That's why we have Linked Lists.
8. The linked list consists of a series of nodes.
9. Each node contains the element and a link to a node containing its successor. We call this the next link. The last cell’s next link points to nullptr.
10. To execute printList() or find(x), we merely start at the first node in the list and
then traverse the list by following the next links.
11. The findKth operation is no longer quite as efficient as an
array implementation.
12. The remove method can be executed in one next pointer change.
13. The insert method requires obtaining a new node from the system by using a new call
and then executing two next pointer maneuvers. 
14. Every node maintain a link to its previous node in the list. This is called a doubly linked list.

### Opinión Crítica y Conclusiones:

Estoy entendiendo que las Listas son algo similar a un arreglo. El espacio inicial es el espacio "0" y el ultimo es AN-1 (esto no me queda del todo claro). Pero existen operaciones distintas que sirven para interactuar con la lista y los datos que almacena.  

El libro también comenta que las listas son a simple vista algo parecido a un arreglo, pero los arreglos tienen ciertas limitantes. Es por eso que existen las Listas y las Linked Lists. Las listas están formadas por nodos y punteros que se usan para conectar estos nodos.

Cuando existen nodos que conectan con nodo siguiente y el previo, se les conoce como Double List.

-------------------------------------------------------------------------------------------------------------------
**3.3 Vector and list in the STL**

### Ideas Principales:

1. Standard Template Library (STL): an implementation of common data structures.

2. The List ADT is one of the data structures implemented in the STL.
3. These data structures are called collections or containers.
4. There are two popular implementations of the List ADT: Vector and Lists.
5. Both vector and list are class templates that are instantiated with the type of items that they store. Both have several methods in common.
6.  The main methods are:

int size( ) const: returns the number of elements in the container.

void clear( ): removes all elements from the container.

bool empty( ) const: returns true if the container contains no elements, and false otherwise.

void push_back( const Object & x ): adds x to the end of the list.

void pop_back( ): removes the object at the end of the list.

const Object & back( ) const: returns the object at the end of the list (a mutator that returns a reference is also provided).

const Object & front( ) const: returns the object at the front of the list (a mutator that returns a reference is also provided).

7. Methods only available for list: 

void push_front( const Object & x ): adds x to the front of the list.

void pop_front( ): removes the object at the front of the list.

8. Methods only available for Vector: 

Object & operator[] ( int idx ): returns the object at index idx in the vector, with no bounds-checking (an accessor that returns a constant reference is also provided).

Object & at( int idx ): returns the object at index idx in the vector, with bounds checking (an accessor that returns a constant reference is also provided).
int capacity( ) const: returns the internal capacity of the vector. 
void reserve( int newCapacity ): sets the new capacity. If a good estimate is available, it can be used to avoid expansion of the vector.

9. In the STL, a position is represented by a nested type, iterator.

iterator begin( ): returns an appropriate iterator representing the first item in the container.
iterator end( ): returns an appropriate iterator representing the endmarker in the container.

itr++ and ++itr: advances the iterator itr to the next location. 
*itr: returns a reference to the object stored at iterator itr’s location. 
itr1==itr2: returns true if iterators itr1 and itr2 refer to the same location and false otherwise.
itr1!=itr2: returns true if iterators itr1 and itr2 refer to a different location and false otherwise.

10. The three most popular methods that require iterators are those that add or remove from the list.

iterator insert( iterator pos, const Object & x ): adds x into the list, prior to the position given by the iterator pos. 

Iterator erase( iterator pos ): removes the object at the position given by the iterator.

iterator erase( iterator start, iterator end ): removes all items beginning at position start, up to, but not including end. 

### Referencias Adicionales:

"An iterator is a pointer-like object representing an element's position in a container. It is used to iterate over elements in a container." [1]

Example of usage of an iterator:

```c++
#include <iostream>
#include<vector>
using namespace std;

int main() {

    vector <string> languages = {"Python", "C++", "Java"};

    // create an iterator to a string vector
    vector<string>::iterator itr;

    // iterate over all elements
    for (itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << ", ";
    }

    return 0;
}
```

### Opinión Crítica y Conclusiones:

En esta sección del capítulo se habla principalmente sobre templates que ya exiten en la librería fundamental de C++ y los métodos que existen para aplicarse en ellos. Hay métodos que aplican para ambos y otros que son exclusivos de cada uno. Estos métodos van desde conocer el tamaño/ capacidad, insertar, remover, etc. 

Los métodos dan pie a otro tema muy importante que son los iteradores. Entiendo que a grandes rasgos estos son algo similar a punteros que se usan para jugar con los elementos que se encuentran dentro de los contenedores de las listas y vectores. Estos se combinan con los métodos descritos aneriormente.

------------------------------------------------------------------------------------------


**3.4 Implementation of Vector**

### Ideas Principales

Array vs Vector 

1. The array is simply a pointer variable to a block of memory; the actual array size must
be maintained separately by the programmer.

2. The block of memory can be allocated via new[] but then must be freed via delete[].

3. The block of memory cannot be resized (but a new, presumably larger block can be obtained and initialized with the old block, and then the old block can be freed).

4. The Vector will maintain the primitive array (via a pointer variable to the block of
allocated memory), the array capacity, and the current number of items stored in the
Vector.

5. The Vector will implement the Big-Five to provide deep-copy semantics for the copy
constructor and operator=, and will provide a destructor to reclaim the primitive array.
It will also implement C++11 move semantics.

6. The Vector will provide a resize routine that will change (generally to a larger number)
the size of the Vector and a reserve routine that will change (generally to a larger
number) the capacity of the Vector. The capacity is changed by obtaining a new block
of memory for the primitive array, copying the old block into the new block, and
reclaiming the old block.

7. The Vector will provide an implementation of operator[] (as mentioned in
Section 1.7.2, operator[] is typically implemented with both an accessor and mutator
version).

8. The Vector will provide basic routines, such as size, empty, clear (which are typically
one-liners), back, pop_back, and push_back. The push_back routine will call reserve if the
size and capacity are same.

9. The Vector will provide support for the nested types iterator and const_iterator, and
associated begin and end method.


### Opinión Crítica y Conclusiones:
Esta parte del capítulo nos mostró dos cosas. La primera, las diferencias entre un arreglo y un vector. En esencia, los arreglos son menos flexibles y dinámicos que los vectores. Estos últimos usan al arreglo como base y sobre ese aplican estos comandos/ instrucciones para poder "jugar" con lo que hay dentro.

 También se mostró como es la estructura de una Clase tipo Vector. Esta clase se parece mucho a las clases que vimos en el parcial 1 en el sentido que tienen todos los elementos como constructores (públicos y privados), destructores, copias, referencias, etc.

-------------------------------------------------------------------------------------------------------------------
**3.5 Implementation of List**

### Ideas Principales

In order to implement a List Template, 4 elements inside it are escencial are needed:

1. The List class itself, which contains links to both ends, the size of the list, and a host
of methods.

2. The Node class, which is likely to be a private nested class. A node contains the data
and pointers to the previous and next nodes, along with appropriate constructors.

3. The const_iterator class, which abstracts the notion of a position, and is a public nested class. The const_iterator stores a pointer to “current” node, and provides
implementation of the basic iterator operations, all in the form of overloaded operators
such as =, ==, !=, and ++.

4. The iterator class, which abstracts the notion of a position, and is a public nested
class. The iterator has the same functionality as const_iterator, except that operator*
returns a reference to the item being viewed, rather than a constant reference to
the item. An important technical issue is that an iterator can be used in any routine that requires a const_iterator, but not vice versa. In other words, iterator IS-A
const_iterator

5. The node at the front is sometimes known as a header node.

6. The node at the end is sometimes known as a tail node.


### Referencias Adicionales:

"The C++ Standard Library list class is a class template of sequence containers that maintain their elements in a linear arrangement and allow efficient insertions and deletions at any location within the sequence. The sequence is stored as a bidirectional linked list of elements, each containing a member of some type Type." [2]


### Opinión Crítica y Conclusiones:

Esta sección del capítulo habló principalmente sobre tres cosas: la primera es ilustrar los elementos mas importantes de una Lista (nodos, punteros, cabeza y cola), la segunda fue plantear a grandes rasgos la estructura de una Clase Lista (que se integra por la creación misma de la clase, otra clase para los nodos y otra clase para los iteradores) y la tercera fue mostrar un código con la sintaxis de todo lo descrito anteriormente.

Me quedan varias dudas sobre la sintaxis, ya que me es dificil comprender viendo tantas líneas y relacionarlas con el texto que las explica pero espero me queden mas claras con la actividad que tenemos paralela a este resumen (documentar el código de un Lista).

-------------------------------------------------------------------------------------------------

### Conclusión General
Este tema es casi completamente nuevo para mi. Tenía conocimiento de los Vectores y Arreglos pero solamente su aplicación directa en el Main. Este capítulo abarca sobre como hacer una Clase a partir de los templates existentes para una Lista y un Vector, lo cual hace el tema un poco mas difícil de entender. 

Me ayuda que esto va relacionado con las Clases que vimos en el primer parcial ya que la estructura de la creación de la clase es muy similar pero mucha de la sintaxis me sigue siendo compleja de entender por la parte de los iteradores y nodos. Me sentiré mas cómodo con mi aprendizaje una vez que pueda documentar línea por línea en la actividad que tenemos asignada sobre "Documentar una Lista".


### Referencias 
[1] Programiz, “C++ Iterators”. [Online]. Available : https://www.programiz.com/cpp-programming/iterators. [Accessed October. 3, 2023].

[2] Microsoft - Multiple Contributors, “List Class”, 2021. [Online]. Available : https://learn.microsoft.com/en-us/cpp/standard-library/list-class?view=msvc-170#syntax. [Accessed October 03, 2023].

Weiss, M. A. (2014). Data structures and algorithm analysis in C++ (4th ed.).Pearson Education.

