
**Mario Alberto Montes Girón**

**Resumen: Trees**

**4.1 Preliminaries**

### Ideas Principales:

1.	One natural way to define a tree is recursively. A tree is a collection of nodes.

2.	A tree consists of a distinguished node, r, called the root.

3.	The root of each subtree is said to be a child of r.

4.	r is the parent of each subtree root.

5.	Every node except the root has one parent.

6.	Each node may have an arbitrary number of children.

7.	Nodes with no children are known as leaves.

8.	Nodes with the same parent are siblings.

9.	Grandparent and grandchild relations can be defined in a similar manner.

10.	The length is the number of edges on the path.

11.	The depth of a tree is equal to the depth of the deepest leaf.

12.	There are many applications for trees. One of the popular uses is the directory structure in many common operating systems.

13.	In a preorder traversal, work at a node is performed before (pre) its children are processed.

14.	In a post order traversal, the work at a node is performed after (post) its children are evaluated.

### Referencias Adicionales:

“Un árbol es un conjunto finito de nodos jerárquicos, organizados y dinámicos. Representan estructuras no lineales y dinámicas.

– Jerárquicos: sus componentes se encuentran en niveles distintos

– Organizados: importa el orden de los componentes

– Dinámicos: porque tanto su forma como su tamaño y contenido pueden variar

– No lineales: a cada elemento puede seguirlo más de un elemento

– Dinámicas: la estructura puede cambiar durante la ejecución del programa” [1]


### Opinión Crítica y Conclusiones:

Esta sección del capítulo habló principalmente sobre el concepto general de un árbol y los elementos que lo componen. Se entiende que un árbol está compuesto por un nodo principal llamado raíz y nodos secundarios que se les conocen cómo hijos y que estos a su vez tienen otros nodos que son los nietos y así sucesivamente. Los árboles tienen largo, ancho y nivel de profundidad. 

-------------------------------------------------------------------------------------------------------
**4.2 Binary Trees**

### Ideas Principales

1.	A binary tree is a tree in which no node can have more than two children.

2.	The depth of an average binary tree is considerably smaller than N.

3.	The declaration of tree nodes is the element information plus two pointers (left and right) to other nodes.

4.	Binary trees have many important uses not associated with searching such as the expression tree.

5.	The leaves of an expression tree are operands, such as constants or variable names, and the other nodes contain operators.

6.	This particular tree happens to be binary, because all the operators are binary.

7.	It is possible for nodes to have more than two children. It is also possible for a node to have only one child.

8.	In our example, the left subtree evaluates to a + (b * c) and the right subtree evaluates to ((d * e) + f) * g. The entire tree therefore represents (a + (b * c)) + (((d * e) + f) * g).

9.	This general strategy (left, node, right) is known as an in-order traversal.

### Referencias Adicionales:

“El árbol binario es una estructura recursiva de conjunto finito de cero o más nodos tales que:

•	Existe un nodo denominado raíz del árbol
•	Cada nodo puede tener 0,1 o 2 subárboles (Izquierdo y derecho)

Esta estructura se puede considerar una estructura recursiva teniendo en cuenta que cada nodo del árbol, junto con todos sus descendientes, y manteniendo el orden original, constituye también un árbol o subárbol del árbol principal.” [2]


### Opinión Crítica y Conclusiones:

En esta parte del capítulo se habla específicamente sobre los árboles binarios. A grandes rasgos, son aquellos en los que los nodos no pueden tener más de 2 hijos. 

En términos mas técnicos, un nodo se declara junto a dos punteros, uno que apunta a la derecha y otro a la izquierda. También se menciona que estos árboles no solo se usan para la búsqueda, sino que tienen otros usos como el de armar expresiones aritméticas. 

-------------------------------------------------------------------------------------------------------------------
**4.3 The Search Tree ADT – Binary Search Trees**

### Ideas Principales:

1. An important application of binary trees is their use in searching.

2.	The property that makes a binary tree into a binary search tree is that all the elements in the tree can be ordered in some consistent manner.

3.	The public member functions use the general technique of calling private recursive functions such as contains, insert, and remove.

4.	Contains: This operation requires returning true if there is a node in tree T that has item X, or false if there is no such node. 

5.	FindMin and FindMax: These private routines return a pointer to the node containing the smallest and largest elements in the tree, respectively. 

6.	To perform a findMin, start at the root and go left as long as there is a left child. The stopping point is the smallest element. The findMax routine is the same, except that branching is to the right child.

7.	Insert: The insertion routine is conceptually simple. To insert X into tree T, proceed down the tree as you would with a contains. If X is found, do nothing. Otherwise, insert X at the last spot on the path traversed.

8.	Remove: If the node is a leaf, it can be deleted immediately. If the node has one child, the node can be deleted after its parent adjusts a link to bypass the node. 

9.	The complicated case deals with a node with two children. The general strategy is to replace the data of this node with the smallest data of the right subtree (which is easily found) and recursively delete that node (which is now empty).

10.	The sum of the depths of all nodes in a tree is known as the internal path length.


### Opinión Crítica y Conclusiones:

Esta sección del capítulo habló principalmente sobre el árbol de búsqueda y las diferentes funciones que se pueden usar como lo son el Contains, FindMin/Max, Insert y el Remove. Todas ellas trabajan bajo una lógica similar que es la de encontrar un valor específico en alguno de los nodos y después proceder a hacer una acción. Todo esto a través de llamadas a funciones recursivas.

------------------------------------------------------------------------------------------


**4.4 AVL Trees**

### Ideas Principales

1.	An AVL tree is a binary search tree with a balance condition.

2.	The balance condition must be easy to maintain, and it ensures that the depth of the tree is O(logN).

3.	The simplest idea is to require that the left and right subtrees have the same height.

4.	An AVL tree is identical to a binary search tree, except that for every node in the tree, the height of the left and right subtrees can differ by at most 1.

5.	Single rotation and double rotation are used when balancing issues appear in the three as a result of applying operations such as remove or insert.

6.	Single rotation: To ideally rebalance the tree, we would like to move X up a level and Z down a level. To do this, we rearrange nodes into an equivalent tree.

7.	Double Rotation: to place k2 as the new root. It restores the height to what it was before the insertion, thus guaranteeing that all rebalancing and height updating is complete.


### Opinión Crítica y Conclusiones:

En esta otra parte del capítulo nos enfocamos en los árboles AVL que son básicamente aquellos que se mantiene balanceados para que el nivel de complejidad siga siendo muy bajo. La idea fundamental es que los sub-árboles izquierdos y derechos tengan el mismo nivel de altura. El texto nos explica que para que esto sea posible se usan los métodos de rotación (sencillos y dobles). 

-------------------------------------------------------------------------------------------------------------------


### Conclusión General

Este tema se me hizo más fácil de comprender porque de cierta manera es algo similar a lo que ya hemos visto antes cómo las listas, colas, pilas, etc. La lógica, estructura y sintaxis en esencia es algo parecida. Sin embargo, tiene elementos muy particulares y diferentes como los nodos raíz, hijos, hermanos, etc. 

Encontré muy interesante el capítulo en general, pero en específico la parte de los AVL Trees. El hecho de que tengan que estar balanceados y que existan métodos para que esto suceda lo hace muy interesante pero complejo a la vez.

La parte teórica me hace sentido y me siento más cómodo con el tema. Sin embargo, me sentiré todavía mas seguro una vez que pueda completar la documentación del código de la estructura del árbol.



### Referencias 

[1] Prograli, “Árboles”. [Online]. Available : https://prograli.wordpress.com/2018/03/10/arboles/. [Accessed October. 30, 2023].

[2] Medium – Paul Ponce Pérez, “Estructuras de Datos: Recursividad y árboles”, 2020. [Online]. Available : https://a01205866.medium.com/estructuras-de-datos-recursividad-y-%C3%A1rboles-5ad7b75ef1fb. [Accessed October 30, 2023].

Weiss, M. A. (2014). Data structures and algorithm analysis in C++ (4th ed.).Pearson Education.



