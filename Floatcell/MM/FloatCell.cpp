#include "FloatCell.h"


FloatCell::FloatCell(float newValue) : storedValue(newValue) {}


FloatCell::FloatCell(const FloatCell &rhs) : storedValue(rhs.storedValue){}


FloatCell::FloatCell(FloatCell &&rhs) noexcept : storedValue(rhs.storedValue){
    rhs.storedValue = 0;
}

FloatCell &FloatCell::operator=(const FloatCell &rhs){
    if(this != &rhs) {
        storedValue = rhs.storedValue;
    }

    return *this;
}

FloatCell &FloatCell::operator=(FloatCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}




    FloatCell &FloatCell::operator=(float rhs) {
        storedValue = rhs;
        return *this;
    }



    float FloatCell ::getValue() const{
        return storedValue;
    }


    void FloatCell::setValue(int newValue) {
        storedValue = newValue;
    }
