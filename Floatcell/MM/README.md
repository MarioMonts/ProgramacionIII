
# **Mario Alberto Montes Girón** 
**Programación III** | 
**Documentación de una Clase** |
**28 de Septiembre del 2023**

En esta tarea vamos a documentar los códigos vistos en clase para FloatCell.

Comenzaremos con el archivo "FloatCell.h"

El ".h" se define como la Inferfaz. Es como un intermediario entre el código y la implementación.

Esta parte no contiene todo el código. Sino que solo dice que es lo que va a haber.


```c++

#ifndef MM_FLOATCELL_H
#define MM_FLOATCELL_H

class FloatCell { // Estamos creando nuestra clase que se va a llamar FloatCell.
public: // Comenzaremos a definir los miembros de nuestra clase. Los públicos son accessibles desde cualquier donde el objeto al que pertenece sea visible. 

    explicit FloatCell(float newValue =0); // "explicit" es una palabra reservada. Se usa en los constructores para que el tipo de dato no se vaya a cambiar de manera implicita por alguna razón. Este constructor lo usamos para definir que IntCell es el tipo de dato que estamos creando. 



    FloatCell(const FloatCell &rhs); // Constructor explícito por copia indicado por el &. Estamos diciendo que FloatCell va a funcionar como un rhs (right hand side ó rvalue). Por copia significa que puede usarse por otras variables para ser copiado pero no tienen relación. Si la original se modifica, la copia no cambia.


    FloatCell(FloatCell &&rhs) noexcept; // Constructor explícito por referencia indicado por el &&. Estamos diciendo que IntCell va a funcionar como un rhs (right hand side ó rvalue). Por referencia significa que puede usarse por otras variables para ser referenciada y si tienen relación. Si la original se modifica, la referenciada también lo hace.

    // "noexcept" es una palabra reservada que nos dice si la función puede admitir excepciones o no. 



    ~FloatCell() = default; // Destructor. Indica que se hará un vaciado de memoria cuando sea necesario. 

    FloatCell &operator=(const FloatCell &rhs); // Aquí le estoy diciendo a mi clase, como va a funcionar con el operador de = cuando sea por copia.
    FloatCell &operator=(FloatCell &&rhs) noexcept; // Aquí le estoy diciendo a mi clase, como va a funcionar con el operador de = cuando sea por referencia.


    FloatCell &operator = (float rhs); // Aquí estoy delimitando que solo puede trabajar con enteros.

   [[nodiscard]] float getValue() const; // Función para obtener un valor.
   void setValue(int newValue); // Función para dar un valor.

private: // Comenzaremos a definir los miembros de nuestra clase. Los privados son accessibles solamente desde dentro de la clase. Únicamente los otros miembros podrán verlos. 

    float storedValue; // Aquí defino el espacio de memoria que se reserva para el valor que va a usar mi clase.

};

#endif //MM_FLOATCELL_H // Cerramos la clase.
```

Ahora seguimos con el archivo "FloatCell.cpp"

El ".cpp" se define como la Implementación. Aquí ya le decimos a la clase (y esta aprende) qué es lo que va a hacer. 

```c++

#include "FloatCell.h"

// Default constructor
FloatCell::FloatCell(float newValue) : storedValue(newValue) {} // Toda constructor comienza con un constructor default porque este es el que usan de referencia los demás que se creen. Aquí estamos delimitando el alcance de IntCell con :: y estamos diciendo que todo lo de esta clase se va a almacenar en storedValue. 

// Copy constructor
FloatCell::FloatCell(const FloatCell &rhs) : storedValue(rhs.storedValue){} // Este es un constructor por copia y hace que lo del lado derecho se va a guardar como copia en el lado izquierdo, en el storedValue. Basicamente después de que copiamos el valor a la izquierda, deja vacío nuevamente el de la derecha.

// Move constructor
FloatCell::FloatCell(FloatCell &&rhs) noexcept : storedValue(rhs.storedValue){ // Este es un constructor por referencia y hace que lo del lado derecho se va a guardar como copia en el lado izquierdo, en el storedValue. Basicamente después de que copiamos el valor a la izquierda, deja vacío nuevamente el de la derecha.

   // rhs.storedValue = 0;
}

// Copy assignment operator
// Aquí estamos indicando que cuando se use el operador "=", que mi clase sepa que hacer. Esto es porque mi clase está desde cero. No sabe nada.
FloatCell &FloatCell::operator=(const FloatCell &rhs){ // Esta parte hace que cuando se use el "=" en un Floatcell, esta función se llame
    if(this != &rhs) { // Es una condición para validar que la parte de la izquierda no sea la misma de la derecha
        storedValue = rhs.storedValue; // Si los objetos no son los mismos, entonces se copia lo que está en rhs.storedValue en storedValue. 
    }
    return *this;
}

// Remove Move assignment operator
// Esto es lo mismo que lo anterior pero con referencia.
FloatCell &FloatCell::operator=(FloatCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}



// Removed overloaded assignment operator to accept any data

// Overloaded assignment operator to accept only integer data
// Aquí le estoy diciendo al operador que cuando reciba floats, que los almacene en storedValue. 
    FloatCell &FloatCell::operator=(float rhs) {
        storedValue = rhs;
        return *this;
    }



    float FloatCell ::getValue() const{ // Función para obtener un valor.
        return storedValue;
    }


    void FloatCell::setValue(int newValue) { // Función para dar un valor.
        storedValue = newValue;
    }


```

