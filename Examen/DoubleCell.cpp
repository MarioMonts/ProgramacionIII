#include "DoubleCell.h"
#include <stdexcept>

// Default constructor
DoubleCell::DoubleCell() : Storedvalue(0.0) {} // Aquí estoy indicando que puedo inicializar variables de tipo double que por default van a tener 0.0 en caso de no asignarle valor.

// Constructor with value
DoubleCell::DoubleCell(double value): Storedvalue(value){} // Aquí estoy indicando que puedo inicializar variables de tipo double y asignarles un valor.

// Copy constructor
DoubleCell::DoubleCell(const DoubleCell &other) : Storedvalue(other.Storedvalue){} // Aquí creamos la copia del constructor. La cual va a crear un nuevo objeto al copiar el storedvalue de other.

//Reference  constructor
DoubleCell::DoubleCell(DoubleCell &&other) noexcept: Storedvalue(other.Storedvalue){} // Aquí creamos la copia referenciada del constructor. La cual va a crear un nuevo objeto al referenciar el storedvalue de other.


// Destructor


// Assignment operator by copy
// Aquí estamos indicando que cuando se use el operador "=", que mi clase sepa que hacer. Esto es porque mi clase está desde cero. No sabe nada.
// En resumen esta es una condición para validar que la parte de la izquierda no sea la misma de la derecha. Si los objetos no son los mismos, entonces se copia lo que está en other.storedValue en storedValue.
DoubleCell& DoubleCell::operator=(const DoubleCell& other){
    if (this != &other){
        Storedvalue = other.Storedvalue;
    }
    return *this;
}

// Assignment operator by reference
// Esto es lo mismo que lo anterior pero con referencia.
DoubleCell& DoubleCell::operator=(DoubleCell &&other) noexcept{
    if (this != &other){
        Storedvalue = other.Storedvalue;
        other.Storedvalue = 0;
    }
    return *this;
}


// Assignment operator for double
// Aquí basicamente le decimos al operador que puede usarse para asignar a variables valores de tipo double
DoubleCell& DoubleCell::operator=(double value){
    Storedvalue = value;
    return *this;
}

// Arithmetic operators
// En la siguientes lineas estamos definiendo como va a trabajar cada operador con los double values. Cada uno tiene un escenario en el que se hace una operación con otro valor del mismo tipo y el otro escenario en el que se usa el double value y otro valor dado.
// La lógica es la misma para todas las operaciones solo cambia la naturaleza dada por el operador.
//DoubleCell adding
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{
    return DoubleCell(Storedvalue + other.Storedvalue);
}
//primitive double adding
DoubleCell DoubleCell::operator +(double value) const{
    return DoubleCell(Storedvalue + value);
}

//DoubleCell substracting
DoubleCell DoubleCell::operator -(const DoubleCell& other) const{
    return DoubleCell(Storedvalue - other.Storedvalue);
}

//primitive double substracting
DoubleCell DoubleCell::operator -(double value) const{
    return DoubleCell(Storedvalue - value);
}

//DoubleCell multiplication
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{
    return DoubleCell(Storedvalue * other.Storedvalue);
}
//primitive double multiplication
DoubleCell DoubleCell::operator *(double value) const{
    return DoubleCell(Storedvalue * value);
}


//DoubleCell division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{
    if(other.Storedvalue == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / other.Storedvalue);
}

//Primitive Double division
DoubleCell DoubleCell::operator /(double value) const{
    if(value == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / value);
}

// Setters
// Función para dar un valor.
void DoubleCell::SetValue(double value){
    Storedvalue = value;
}

// Getters
// Función para obtener un valor.
double DoubleCell::GetValue() const {
    return Storedvalue;
}