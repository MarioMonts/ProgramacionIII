
## **Mario Alberto Montes Girón**

## **Resumen: Trees**

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

------------------------------------------------------------------------------------------------

**4.5 Splay Trees**

### Ideas Principales

1.	A splay tree that guarantees that any M consecutive tree operations starting from an empty tree take at most O(M logN) time.

2.	Splay trees are based on the fact that the O(N) worst-case time per operation for binary search trees is not bad, as long as it occurs relatively infrequently.

3.	The problem with binary search trees is that it is possible, and not uncommon, for a whole sequence of bad accesses to take place.

4.	The basic idea of the splay tree is that after a node is accessed, it is pushed to the root by a series of AVL tree rotations.

5.	One way of performing the restructuring described above is to perform single rotations, bottom up. This means that we rotate every node on the access path with its parent.

6.	The splaying strategy is similar to the rotation idea above, except that we are a little more selective about how rotations are performed. We will still rotate bottom up along the access path.

7.	These figures highlight the fundamental and crucial property of splay trees. When access paths are long, thus leading to a longer-than-normal search time, the rotations tend to be good for future operations.

8.	The analysis of splay trees is difficult because it must consider the everchanging structure of the tree.

9.	Splay trees are much simpler to program than most balanced search trees since there are fewer cases to consider and no balance information to maintain.


### Opinión Crítica y Conclusiones:

Esta sección del capítulo nos habla sobre los Splay Trees. Lo que yo comprendo es que estos árboles garantizan que casi la mayor parte del tiempo, se van a ejecutar de manera muy rápida. Sin embargo, existe la posibilidad de que esto no suceda ya que puede haber operaciones que lo hagan más complejo. 

Aquí es donde entran las rotaciones que sirven para reestructurar los nodos y el código pueda ejecutarse de una forma más sencilla. En general, estos árboles son más sencillos de programar porque al balancear, no tenemos que preocuparnos por la información que los nodos almacenan. 

------------------------------------------------------------------------------------------------

**4.6 Tree Traversals (Revisited)**

### Ideas Principales

1.	Because of the ordering information in a binary search tree, it is simple to list all the items in sorted order.

2.	The general strategy of an inorder traversal is to process the left subtree first, then perform processing at the current node, and finally process the right subtree.

3.	The total running time is O(N).

4.	This is because there is constant work being performed at every node in the tree.

5.	Sometimes we need to process both subtrees first before we can process a node. Is known as a postorder traversal.

6.	Preorder traversal. Here, the node is processed before the children. This could be useful, for example, if you wanted to label each node with its depth.

7.	In a level-order traversal, all nodes at depth d are processed before any node at depth d + 1.

### Opinión Crítica y Conclusiones:

En esta parte pequeña del capítulo, nos enfocamos principalmente en los diferentes métodos para ordenar todos los elementos de un árbol de búsqueda binaria. Existen 4 y son inorder traversal, postorder traversal, preorder traversal y level-order traversal. 

------------------------------------------------------------------------------------------------

**4.7 B-Trees**

### Ideas Principales

1.	We have assumed that we can store an entire data structure in the main memory of a computer. 

2.	The rules of the game change, because the Big-Oh model is no longer meaningful.

3.	The problem is that a Big-Oh analysis assumes that all operations are equal. However, this is not true, especially when disk I/O is involved.

4.	In principle, a B-tree guarantees only a few disk accesses.
5.	The data items are stored at leaves. 

6.	The nonleaf nodes store up to M − 1 keys to guide the searching; key i represents the smallest key in subtree i + 1. 

7.	The root is either a leaf or has between two and M children.

8.	All nonleaf nodes (except the root) have between  M/2  and M children.

9.	All leaves are at the same depth and have between  L/2  and L data items, for some L (the determination of L is described shortly).

### Referencias Adicionales:

“Meet the B-Tree, the multi-talented data structure that can handle massive amounts of data with ease. When it comes to storing and searching large amounts of data, traditional binary search trees can become impractical due to their poor performance and high memory usage. B-Trees, also known as B-Tree or Balanced Tree, are a type of self-balancing tree that was specifically designed to overcome these limitations.

B-Trees maintain balance by ensuring that each node has a minimum number of keys, so the tree is always balanced. This balance guarantees that the time complexity for operations such as insertion, deletion, and searching is always O(log n), regardless of the initial shape of the tree.”[3]

### Opinión Crítica y Conclusiones:

Logro comprender que los B-Trees están diseñados específicamente para combatir el problema de la complejidad cuando los árboles almacenan demasiada información. Estos árboles se balancean solos al asegurarse que cada nodo mantenga un mínimo número de llaves (las llaves son un valor único asociado a cada elemento/ nodo del árbol). 

------------------------------------------------------------------------------------------------

**4.8 Sets and Maps in the Standard Library**

### Ideas Principales

1.	The set is an ordered container that does not allow duplicates.

2.	Many of the idioms used to access items in vector and list also work for a set.

3.	The unique operations required by the set are the abilities to insert, remove, and perform a basic search (efficiently).

4.	However, because a set does not allow duplicates, it is possible for the insert to fail.
5.	A map is used to store a collection of ordered entries that consists of keys and their values.

6.	Keys must be unique, but several keys can map to the same values. Thus, values need not be unique. The keys in the map are maintained in logically sorted order.

7.	C++ requires that set and map support the basic insert, erase, and find operations in logarithmic worst-case time. Consequently, the underlying implementation is a balanced binary search tree.

8.	An important issue in implementing set and map is providing support for the iterator classes.

9.	The hard part is efficiently advancing to the next node.


### Opinión Crítica y Conclusiones:

No comprendí muy bien esta ultima parte. Entiendo que tanto el Set cómo el Map son conjuntos de elementos que se mantienen ordenados y que pueden efectuar operaciones básicas como las que ya hemos visto antes con las listas. Lo que no tengo muy claro es por qué se encuentra este tema en el capítulo de árboles. 

------------------------------------------------------------------------------------------------

### Conclusión General

Este capítulo de árboles se me hizo más fácil de comprender porque de cierta manera es algo similar a lo que ya hemos visto antes cómo las listas, colas, pilas, etc. La lógica, estructura y sintaxis en esencia es algo parecida. Sin embargo, tiene elementos muy particulares y diferentes como los nodos raíz, hijos, hermanos, etc. 

Encontré muy interesante el capítulo en general, pero en específico la parte de los AVL Trees. El hecho de que tengan que estar balanceados y que existan métodos para que esto suceda (las rotaciones) lo hace muy interesante pero complejo a la vez.

La parte teórica me hace sentido y me siento más cómodo con el tema. Sin embargo, me sentiré todavía mas seguro una vez que pueda completar la documentación del código de la estructura del árbol.

------------------------------------------------------------------------------------------------

### Referencias 

[1] Prograli, “Árboles”. [Online]. Available : https://prograli.wordpress.com/2018/03/10/arboles/. [Accessed October. 30, 2023].

[2] Medium – Paul Ponce Pérez, “Estructuras de Datos: Recursividad y árboles”, 2020. [Online]. Available : https://a01205866.medium.com/estructuras-de-datos-recursividad-y-%C3%A1rboles-5ad7b75ef1fb. [Accessed October 30, 2023].

[3] Geeks for Geeks, “Introduction of B-Tree”. [Online]. Available : https://www.geeksforgeeks.org/introduction-of-b-tree-2/. [Accessed November 1, 2023].

Weiss, M. A. (2014). Data structures and algorithm analysis in C++ (4th ed.).Pearson Education.

