
# **Mario Alberto Montes Girón** 
**Programación III** 

**Documentación de una Clase - Árbol** 

**8 de Noviembre del 2023**

En esta tarea vamos a documentar los códigos vistos en clase para un Árbol AVL.

El archivo que se va a analizar es el del  "AVLTree.h"

Antes de entrar de lleno a la documentación del código, comparto una explicación general y sencilla sobre el tema.

### Árbol AVL – Definición

"   Un árbol binario balanceado (también conocidos simplemente como árboles AVL en honor a sus creadores Adelson-Velski y Landis) es un árbol binario de búsqueda (ABB) en el que las alturas de los dos subárboles de cada nodo difieren a lo más en 1.

   El balance de un nodo en un árbol binario en general y de un árbol AVL en particular, se define como la altura de su subárbol izquierdo menos la altura de su subárbol derecho:

| altura(arbolIzquierdo) - altura(arbolDerecho) | < 2

   También existe la correspondiente definición simétrica: la altura de su subárbol derecho menos la altura de su subárbol izquierdo; pero en este blog se adoptará la primera. Por convención, la altura de un árbol AVL nulo o vacío se define como -1.

   Durante el proceso de inserción o eliminación puede ocurrir un desbalance, es decir, que el valor absoluto de la altura de alguno de los nodos del árbol AVL sea mayor que 1.

   En caso de existir desbalance en alguno de los nodos, es decir, una condición que incumpla lo establecido por la expresión anterior, se tiene que rebalancear el árbol para que éste siga siendo un árbol AVL válido.

   En este sentido, existen cuatro casos que corrigen el balanceo de un árbol AVL:

Caso 1: rotación simple derecha.

Caso 2: rotación simple izquierda.

Caso 3: rotación doble izquierda derecha.

Caso 4: rotación doble derecha izquierda." [1]

Ahora sí, pasemos a revisar el código documentado:

```c++
#ifndef TREECLASS_AVLTREE_H
#define TREECLASS_AVLTREE_H

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<memory>

template <typename T>
class Node { // Aquí se está declarando la clase Nodo en el template
public:
    T data; // Variable para almacenar los datos
    int height; // Variable para declarar la altura de los nodos
    std::shared_ptr<Node<T>> left; // Este es u puntero hacia la izquierda
    std::shared_ptr<Node<T>> right; // Este es un puntero hacia la derecha

    Node(T data) : data(data), height(1), left(nullptr), right(nullptr) {} // El constructor está inicializando el árbol con una altura de 1 y que ambos punteros estén como null
};

template <typename T>
class AVLTree { // Aquí se está declarando la clase AVLTree
public:
    std::shared_ptr<Node<T>> root; // Aquí se está declarando un puntero compartido que apunta a la raiz de nuestro árbol

    AVLTree(): root(nullptr) {} // El puntero se inicializa para que esté como null

    void add(T data) { // Este es un método para agregar un nuevo dato a nuestro árbol
        root = insert(root, data); // Se llama a la función insert para que se inserte el dato y luego se actualiza la raíz
    }

    void remove(T data)  { // Este es un método para remover un dato existente en nuestro árbol
        root = deleteNode(root, data); // Se llama a la función remove para que se elimine el dato y luego se actualiza la raíz
    }

    void print() { // Este es un método para imprimir lo que tenemos dentro de nuestro árbol
        if (root != nullptr) { // Primero verifica que la raíz no sea nula
            print(root, 0); // Llama a la función Print
        } else {
            std::cout << "The tree is empty." << std::endl; // Muestra esto en caso de que el árbol esté vacío
        }
    }

private: // Este bloque representa una función Print que va a imprimir todos los elementos del árbol de manera recursiva
    void print(std::shared_ptr<Node<T>> node, int indent) { // Se toman como parámetros un puntero compartido y un entero llamado indent
        if(node) {
            if(node->right) { // Si el nodo tiene un hijo derecho, se le llama a la función print de manera recursiva para que imprima los elementos
                print(node->right, indent + 8); // Indent se incrementa en 8 para que la impresión tenga un mayor alcance a la derecha
            }
            if (indent) { // Si el valor indent es diferente de cero, se imprime un espacio en blanco
                std::cout << std::setw(indent) << ' ';
            }
            if (node->right) { // Si el nodo tiene un hijo derecho, se imprime Right Off seguida de los datos del nodo y luego se hace un salto de línea.
                std::cout << " / (Right of " << node->data << ")\n" << std::setw(indent) << ' ';
            }
            std::cout << node->data << "\n" ; // Se muestra el dato en el nodo actual y luego se hace el salto de línea

            if (node->left) { // Si el nodo tiene un hijo derecho, se imprime Right Off seguida de los datos del nodo y luego se hace un salto de línea.
                std::cout << std::setw(indent) << ' ' << " \\ (Left of " << node->data << ")\n";
                print(node->left, indent + 8); // Indent se incrementa en 8 para que la impresión tenga un mayor alcance a la izquierda
            }
        }
    }

    std::shared_ptr<Node<T>> newNode(T data) { // Esta es una función para crear un nuevo nodo en el árbol
        return std::make_shared<Node<T>>(data); // Toma un dato de tipo genérico T cómo argumento y devuelve un puntero compartido a un nuevo nodo que contiene ese dato
    }

    // Esta es una función que se utiliza para realizar una rotación hacia la derecha en el árbol
    std::shared_ptr<Node<T>> rightRotate(std::shared_ptr<Node<T>> y) { // Toma un puntero compartido "y" cómo argumento que es el nodo que se usa cómo base para hacer la rotación
        std::shared_ptr<Node<T>> x = y->left; // Se crea un nuevo puntero compartido x que apunta al hijo izquierdo de y
        std::shared_ptr<Node<T>> T2 = x->right; // Se crea un nuevo puntero compartido T2 que apunta al hijo derecho de x. Esto para mantener la estructura del árbol después de la rotación

        // Se reorganizan los punteros para hacer la rotación hacia la derecha
        x->right = y; // El nodo x se convierte en la nueva raíz del árbol, con el nodo "y" como su hijo derecho
        y->left = T2; // El nodo T2 se convierte en el hijo izquierdo de "y"

        // Aquí se actualiza la altura de los nodos "x" y "y" después de haber rotado.
        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;

        return x; // Devuelve el puntero compartido x que se convierte en la nueva raíz de subárbol después de la rotación a la derecha
    }

    // Esta es una función que se utiliza para realizar una rotación hacia la izquierda en el árbol
    std::shared_ptr<Node<T>> leftRotate(std::shared_ptr<Node<T>> x) { // Toma un puntero compartido "x" cómo argumento que es el nodo que se usa cómo base para hacer la rotación
        std::shared_ptr<Node<T>> y = x->right; // Se crea un nuevo puntero compartido y que apunta al hijo derecho de x
        std::shared_ptr<Node<T>> T2 = y->left; // Se crea un nuevo puntero compartido T2 que apunta al hijo izquierdo de y. Esto para mantener la estructura del árbol después de la rotación

        // Se reorganizan los punteros para hacer la rotación hacia la izquierda
        y->left = x; // El nodo y se convierte en la nueva raíz del árbol, con el nodo "x" como su hijo izquierdo
        x->right = T2; // El nodo T2 se convierte en el hijo derecho de "x"

        // Aquí se actualiza la altura de los nodos "x" y "y" después de haber rotado.
        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;

        return y; // Devuelve el puntero compartido y que se convierte en la nueva raíz de subárbol después de la rotación a la izquierda
    }


    // Esta es una función que se utiliza para calcular el factor de equilibrio de un nodo en el árbol
    int getBalance(std::shared_ptr<Node<T>> N) { // Se toma un nodo compartido N cómo argumento que apunta al nodo cuyo equilibrio se está calculando
        if (N == nullptr) // Aquí se verifica si el nodo es nulo
            return 0; // Regresa 0 en lugar de ser un nodo nulo
        return height(N->left) - height(N->right); // Aquí es donde se calcula el factor de equilibrio restando la altura del subárbol izquierdo de la altura del subárbol derecho
    // Este factor de equilibrio da la diferencia de alturas entre los subárboles izquierdo y derecho de un nodo en específico.
    // si el valor retornado es positivo, significa que el subárbol izquierdo es más alto y si es negativo, indica que el subárbol derecho es más alto
    }

    // Esta es una función para insertar un nodo con un valor en específico en el árbol
    // Esto es lo que comentamos en clase donde dijimos que lo mas complicado de un árbol es la función de insertar, ya que al hacerlo, alteramos el orden de todos los nodos
    std::shared_ptr<Node<T>> insert(std::shared_ptr<Node<T>> node, T data) {
        if (node == nullptr) // Verifica si el nodo es nulo
            return (newNode(data)); // En caso de serlo, crea un nodo nuevo con los datos que se proporcionan y se devuelve como la nueva raíz del subárbol

            // Si el valor de los datos que se metieron es menor que el valor del nodo actual, la función se llama de manera recursiva en el subárbol izquierdo.
        if (data < node->data)
            node->left = insert(node->left, data);
        // Si es mayor, se llama en el subárbol derecho
        else if (data > node->data)
            node->right = insert(node->right, data);
        // si los datos son iguales, significa que el nodo ya existe y la función devuelve el nodo actual
        else
            return node;

        // Se actualiza la altura del nodo actual en función de las alturas de los subárboles izquierdo y derecho
        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node); // Se calcula el factor de equilibrio del nodo actual utilizando la función GetBalance

        // Una vez que se tiene el factor de equilibrio y los valores de los datos, se realizan las rotaciones hacia la izquierda y hacia la derecha para mantener el equilibrio
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
 // Si no se requiere ninguna rotación, se regresa el nodo actual
        return node;
    }

    // Esta parte del código declara una función llamada minValueNode que se va a utilizar para encontrar el nodo con el valor mínimo en un subárbol dado
    std::shared_ptr<Node<T>> minValueNode(std::shared_ptr<Node<T>> node) {
        std::shared_ptr<Node<T>> current = node; // Se asigna el valor del nodo pasado como argumento a un nuevo puntero compartido llamado current. Esto con el fin de poder iterar a través del árbol y encontrar el nodo con el valor mínimo

        while (current->left != nullptr) // Se usa el ciclo while para poder iterar a través del subárbol izquierdo partiendo del nodo actual
            current = current->left; // En cada iteración se actualiza el nodo actual con su hijo izquierdo

        return current; // Una vez que se ha encontrado el nodo con el valor mínimo, la función lo devuelve
    }

    // Este fragmento del código representa una función llamada DeleteNode. Se usa básicamente para eliminar un nodo deseado
    std::shared_ptr<Node<T>> deleteNode(std::shared_ptr<Node<T>> root, T data) {
        if (!root)
            return root;

        // Aquí ahora se muestran las 3 condiciones para hacer la eliminación del nodo.
        // La primera es cuando el nodo a eliminar no tiene hijos
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }

        // La segunda es cuando el nodo a eliminar tiene un solo hijo
        else if(data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {
            if(!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            }

            // Cuando tiene dos hijos
            else {
                std::shared_ptr<Node<T>> temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
                temp.reset();
            }

            // En todos los casos se reasigna el puntero Root para mantener la estructura del árbol
        }

        // La siguiente parte del código es para actualizar la altura del nodo actual y también se vuelve a calcular el factor de equilibrio
        if(!root)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // Aquí se comienzan a hacer las rotaciones hacia la izquierda o derecha según sea el caso para mantener el equilibrio en el árbol
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Esta es una función Height que agarra el puntero compartido N que apunta a un nodo como argumento y devuelve la altura al nodo
    int height(std::shared_ptr<Node<T>> N) {
        if (N == nullptr) // Si el nodo es nulo, devuelve cero
            return 0;
        return N->height;
    }

    // Esta es una función Max, que toma dos números enteros cómo argumentos y devuelve el mayor de los dos.
    // No entiendo bien para qué es necesaria esta parte
    int max(int a, int b) {
        return (a > b)? a : b;
    }
};

#endif //TREECLASS_AVLTREE_H

```

En resumen, un árbol es una estructura de datos muy dinámica y eficiente cuya función principal es la búsqueda de datos (aunque también puede incluir diversas operaciones). Lo curioso ó diferente del árbol comparado a otras estrcuturas que hemos revisado anteriormente, es que esta tiene la capacidad de balancearse a través de rotaciones y así seguir manteniendo un tiempo de ejecución óptimna.


### Fuentes

[1] Fundamento de la Programación Orientada a Objectos, “Árboles binarios balanceados (AVL)”. [Online]. Disponible : https://fundamentospoorrr.blogspot.com/2017/06/arboles-binarios-balanceados-avl.html. [Consultado Noviembre 8, 2023].