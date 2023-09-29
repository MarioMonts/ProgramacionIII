#ifndef DOUBLE_CELL_H
#define DOUBLE_CELL_H

class DoubleCell {
public:
    // Default constructor
    DoubleCell(); //Aqui estamos definiendo el constructor para que podamos usar la clase sin tener que asignar un valor. Es por eso que se llama Default.
    // Constructor with value
    explicit DoubleCell(double value); // Aqui estamos definiedno el constructor para que podamos usar la clase asignando un valor específico.
    // Copy constructor
    DoubleCell(const DoubleCell &other); // Aqui estamos indicando que esta clase podrá ser usada por copia. Es decir, que puede usarse por otras variables para ser copiado pero no tienen relación. Si la original se modifica, la copia no cambia.
    //Reference constructor
    DoubleCell(DoubleCell &&other) noexcept; // Aqui estamos indicando que esta clase podrá ser usada por referencia. Es decir, que puede usarse por otras variables para ser creferenciada y si tienen relación. Si la original se modifica, la referenciada también lo hace.
    // Destructor
    ~DoubleCell() = default; //  Indica que se hará un vaciado de memoria cuando sea necesario.

    // Assignment operator by copy
    DoubleCell &operator=(const DoubleCell &other); // Aquí le estoy diciendo a mi clase, como va a funcionar con el operador de = cuando sea por copia.
    // Assignment operator by reference
    DoubleCell &operator=(DoubleCell&& other) noexcept; // Aquí le estoy diciendo a mi clase, como va a funcionar con el operador de = cuando sea por referencia.

    // Assignment operator for double
    DoubleCell& operator=(double value); // Aquí estoy delimitando que solo puede trabajar con double values.

    // Arithmetic operators // Aquí estoy indicando que cada uno de los operadores mencionados pueden trabajar con double values
    DoubleCell operator +(const DoubleCell& other) const;
    DoubleCell operator +(const double other) const;
    DoubleCell operator -(const DoubleCell& other) const;
    DoubleCell operator -(const double other) const;
    DoubleCell operator *(const DoubleCell& other) const;
    DoubleCell operator *(const double other) const;
    DoubleCell operator /(const DoubleCell& other) const;
    DoubleCell operator /(const double other) const;

    // Setters
    void SetValue(double value); // Función para dar un valor.
    // Getters

    double GetValue() const; // Función para obtener un valor.


private:
    double Storedvalue; // Aquí defino el espacio de memoria que se reserva para el valor que va a usar mi clase.
};

#endif  // DOUBLE_CELL_H
