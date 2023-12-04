
## **Mario Alberto Montes Girón**

## **Resumen: Sorting**

**7.2 Insertion Sort**

### Ideas Principales:

1.	Insertion sort consists of N−1 passes. For pass p=1 through N−1, insertion sort ensures that the elements in positions 0 through p are in sorted order.

2.	In pass p, we move the element in position p left until its correct place is found among the first p+1 elements.

3.	In the STL, instead of having the sort routines take an array of comparable items as a single parameter, the sort routines receive a pair of iterators that represent the start and endmarker of a range.

4.	Because of the nested loops, each of which can take N iterations, insertion sort is O(N2). Furthermore, this bound is tight, because input in reverse order can achieve this bound.

5.	An inversion in an array of numbers is any ordered pair (i, j) having the property that i < j but a[i] > a[j].

6.	We can compute precise bounds on the average running time of insertion sort by computing the average number of inversions in a permutation.

7.	A sorting algorithm makes progress by eliminating inversions, and to run efficiently, it must eliminate more than just one inversion per exchange.

### Complejidad Espacial y Temporal

La complejidad espacial del algoritmo de ordenamiento por inserción en es O(1).

La complejidad temporal del algoritmo de ordenamiento por inserción en el peor caso es O(n2).

### Ventajas y Desventajas del Algoritmo

•	El algoritmo de inserción es fácil de entender e implementar. 

•	Es eficiente cuando se trata de conjuntos de datos pequeños o casi ordenados.

•	Este algoritmo puede ser eficiente en el caso de listas enlazadas.

•	La complejidad cuadrática hace que el método de inserción sea ineficiente para conjuntos de datos grandes. 

•	El rendimiento del algoritmo es sensible al orden inicial de los elementos. 

•	Aunque es estable, lo que significa que conserva el orden relativo de elementos con claves iguales, puede no ser tan eficiente como otros algoritmos estables para grandes conjuntos de datos.

### En qué momento es útil

Es útil en situaciones específicas donde la simplicidad y la eficiencia para conjuntos de datos pequeños o casi ordenados son más importantes que la eficiencia en términos de tiempo de ejecución en grandes conjuntos de datos.

### Referencias Adicionales:

“El Insertion Sort, divide el conjunto de elementos en una parte ordenada y otra desordenada. Toma un elemento de la parte desordenada y lo inserta en la posición correcta en la parte ordenada. Repite este proceso hasta que todos los elementos estén ordenados.” [1]

-------------------------------------------------------------------------------------------------------
**7.4 Shellsort**

### Ideas Principales

1.	It works by comparing elements that are distant; the distance between comparisons decreases as the algorithm runs until the last phase, in which adjacent elements are compared.

2.	Shellsort is sometimes referred to as diminishing increment sort.

3.	Shellsort uses a sequence, h1, h2, ... , ht, called the increment sequence. Any increment sequence will do as long as h1 = 1, but some choices are better than others (we will discuss that issue later).

4.	After a phase, using some increment hk, for every i, we have a[i] ≤ a[i + hk] (where this makes sense); all elements spaced hk apart are sorted. The file is then said to be hk-sorted.

5.	The running time of Shellsort depends on the choice of increment sequence, and the proofs can be rather involved. The average-case analysis of Shellsort is a long-standing open problem, except for the most trivial increment sequences.

6.	The problem with Shell’s increments is that pairs of increments are not necessarily relatively prime, and thus the smaller increment can have little effect.

7.	Shellsort is a fine example of a very simple algorithm with an extremely complex analysis.

8.	The performance of Shellsort is quite acceptable in practice, even for N in the tens of thousands. The simplicity of the code makes it the algorithm of choice for sorting up to moderately large input.

### Complejidad Espacial y Temporal

La complejidad espacial del algoritmo de ordenamiento Shell Sort es O(1).

La complejidad temporal del algoritmo de ordenamiento Shell Sort va desde O(nlogn) a O(n2).


### Ventajas y Desventajas del Algoritmo


•	Mejora significativamente el rendimiento en comparación con algoritmos cuadráticos tradicionales.

•	La flexibilidad para elegir la secuencia de brechas permite adaptar el algoritmo a diferentes situaciones, lo que puede mejorar su rendimiento en casos específicos.

•	Requiere una cantidad constante de memoria adicional, independientemente del tamaño del conjunto de datos.

•	La implementación de Shell Sort no es demasiado compleja.

•	El rendimiento de Shell Sort puede depender significativamente de la elección de la secuencia de brechas.

•	No es tan eficiente como algoritmos más avanzados como Merge Sort o Quick Sort, especialmente para conjuntos de datos grandes.

•	No garantiza estabilidad en la ordenación.


### En qué momento es útil

Es útil cuando el conjunto de datos que se maneja es de tamaño moderado, cuando están parcialmente ordenados, cuando no se requiere estabilidad y cuando se requiere que la complejidad espacial sea baja.

------------------------------------------------------------------------------------------

**7.5 Heapsort**

### Ideas Principales

1.	Priority queues can be used to sort in O(N logN) time. The algorithm based on this idea is known as heapsort and gives the best Big-Oh running time we have seen so far.

2.	Strategy is to build a binary heap of N elements. This stage takes O(N) time. We then perform N deleteMin operations. The elements leave the heap smallest first, in sorted order.

3.	By recording these elements in a second array and then copying the array back, we sort N elements.

4.	The main problem with this algorithm is that it uses an extra array. Thus, the memory requirement is doubled.

5.	Experiments have shown that the performance of heapsort is extremely consistent: On average it uses only slightly fewer comparisons than the worst-case bound suggests.

6.	The problem, it seems, is that successive deleteMax operations destroy the heap’s randomness, making the probability arguments very complex. Eventually, another approach proved successful.

7.	Heapsort always uses at least N logN − O(N) comparisons and that there are inputs that can achieve this bound.


### Complejidad Espacial y Temporal

La complejidad espacial del algoritmo de ordenamiento Heapsort es O(1).

La complejidad temporal del algoritmo de ordenamiento Heapsort es de O(nlogn).


### Ventajas y Desventajas del Algoritmo

•	Garantiza una complejidad temporal de O(nlogn) en todos los casos.

•	Heapsort ordena los elementos directamente en el array de entrada.

•	Conserva el orden relativo de elementos con claves iguales durante el proceso de ordenación.

•	Puede ser eficiente en operaciones de entrada/salidas secuenciales.

•	En ciertos casos, otros algoritmos pueden ser más rápidos.

•	No es tan ampliamente utilizado en la práctica como otros algoritmos de ordenamiento.

### En qué momento es útil

Es útil cuando se requiera un algoritmo con una complejidad temporal garantizada en todos los casos. Cuando la memoria adicional es limitada. Cuando sea importante mantener el orden relativo de los elementos. Cuando las operaciones de entrada y salida secuenciales sean una consideración crítica y cuando se trabaje con conjuntos de datos muy específicos. 

### Referencias Adicionales

“Is a comparison-based sorting technique based on Binary Heap data structure. It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. Repeat the same process for the remaining elements.” [2]

------------------------------------------------------------------------------------------------

**7.6 Mergesort**

### Ideas Principales

1.	Mergesort runs in O(N logN) worst-case running time, and the number of comparisons used is nearly optimal. It is a fine example of a recursive algorithm.

2.	The fundamental operation in this algorithm is merging two sorted lists. Because the lists are sorted, this can be done in one pass through the input, if the output is put in a third list.

3.	The basic merging algorithm takes two input arrays A and B, an output array C, and three counters, Actr, Bctr, and Cctr, which are initially set to the beginning of their respective arrays.

4.	The merge routine is subtle. If a temporary array is declared locally for each recursive call of merge, then there could be logN temporary arrays active at any point.

5.	Mergesort is a classic example of the techniques used to analyze recursive routines: We have to write a recurrence relation for the running time.

6.	The running time of mergesort, when compared with other O(N logN) alternatives, depends heavily on the relative costs of comparing elements and moving elements in the array (and the temporary array). These costs are language dependent.

7.	Mergesort uses the lowest number of comparisons of all the popular sorting algorithms, and thus is a good candidate for general-purpose sorting in Java.

8.	On the other hand, in classic C++, in a generic sort, copying objects can be expensive if the objects are large, while comparing objects often is relatively cheap because of the ability of the compiler to aggressively perform inline optimization.

### Complejidad Espacial y Temporal

La complejidad espacial del algoritmo de ordenamiento Mergesort es O(n).

La complejidad temporal del algoritmo de ordenamiento Mergesort es de O(nlogn).

### Ventajas y Desventajas del Algoritmo

•	Garantiza una complejidad temporal eficiente de O(nlogn) en todos los casos y es un algoritmo estable.

•	Funciona bien en conjuntos de datos en los que los elementos están ligadamente acoplados.

•	Puede ser fácilmente adaptado para ordenar estructuras de datos enlazadas.

•	No es sensible a la distribución de los datos y mantiene su rendimiento eficiente en una variedad de situaciones.

•	Requiere memoria adicional para almacenar temporalmente los subconjuntos durante la fase de fusión.

•	No ordena los elementos directamente en el array de entrada.

•	puede tener constantes ocultas mayores que algunos otros algoritmos.

### En qué momento es útil

Es útil cuando se manejan conjuntos de datos grandes, cuando se requiere estabilidad, cuando la complejidad espacial es aceptable, cuando se manejan operaciones en listas enlazadas, cuando la distribución de datos es desconocida y cuando se valora tanto la estabilidad como la eficiencia. 

------------------------------------------------------------------------------------------------

**7.7 Quicksort**

### Ideas Principales

1.	Quicksort has historically been the fastest known generic sorting algorithm in practice.

2.	Its average running time is O(N logN). It is very fast, mainly due to a very tight and highly optimized inner loop. 

3.	It has O(N2) worst-case performance, but this can be made exponentially unlikely with a little effort.

4.	Like mergesort, quicksort is a divide-and conquer recursive algorithm.

5.	Arbitrarily choose any item, and then form three groups: those smaller than the chosen item, those equal to the chosen item, and those larger than the chosen item.

6.	Recursively sort the first and third groups, and then concatenate the three groups. 

7.	The result is guaranteed by the basic principles of recursion to be a sorted arrangement of the original list.

8.	Like mergesort, quicksort is recursive; therefore, its analysis requires solving a recurrence formula.

9.	We will do the analysis for a quicksort, assuming a random pivot (no medianof-three partitioning) and no cutoff for small arrays. We will take T(0) = T(1) = 1, as in mergesort.

10.	The running time of quicksort is equal to the running time of the two recursive calls plus the linear time spent in the partition (the pivot selection takes only constant time).

### Complejidad Espacial y Temporal

La complejidad espacial del algoritmo de ordenamiento Quicksort es O(logn).

La complejidad temporal del algoritmo de ordenamiento Quicksort es de O(nlogn).

### Ventajas y Desventajas del Algoritmo


•	Tiene una complejidad temporal promedio eficiente.

•	Opera directamente en el array sin necesidad de memoria adicional.

•	Tiene un rendimiento muy bueno debido a su baja constante oculta. 

•	Puede adaptarse para manejar conjuntos de datos preordenados.

•	Su implementación es mas simple y compacta. 

•	Puede degradarse a una complejidad cuadrática. 

•	No es estable.


### En qué momento es útil

Este método de ordenamiento puede ser útil cuando se necesite tener un rendimiento promedio muy bueno, cuando se quiera reducir el tamaño del problema a resolver, cuando se necesite ordenar arreglos y listas enlazadas, cuando no se requiera el uso de memoria adicional, cuando se necesite ordenar datos aleatorios y cuando se necesite ordenar datos de situaciones muy específicas.

------------------------------------------------------------------------------------------------

### Conclusión General

En conclusión, los métodos de ordenamiento son algoritmos que organizan elementos en un conjunto de datos. Cuál elegir depende del tamaño del conjunto, la distribución de los datos y la eficiencia que se necesite tener. Cada algoritmo tiene sus puntos fuertes y en contra dependiendo de la situación para la que vaya a ser usado.

------------------------------------------------------------------------------------------------

### Referencias 

[1] SWHosting, “Algoritmos de ordenación con ejemplos en C++”. [Online]. Available : https://www.swhosting.com/es/comunidad/manual/algoritmos-de-ordenacion-con-ejemplos-en-c. [Accessed November 29th, 2023].

[2] Geeks for Geeks, “Heap Sort – Data Structures and Algorithms Tutorials”. [Online]. Available : https://www.geeksforgeeks.org/heap-sort/ [Accessed December 4, 2023].

Weiss, M. A. (2014). Data structures and algorithm analysis in C++ (4th ed.).Pearson Education.
