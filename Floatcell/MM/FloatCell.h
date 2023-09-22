#ifndef MM_FLOATCELL_H
#define MM_FLOATCELL_H

class FloatCell {
public:
    explicit FloatCell(float newValue =0);
    FloatCell(const FloatCell &rhs);
    FloatCell(FloatCell &&rhs) noexcept;
    ~FloatCell() = default;

    FloatCell &operator=(const FloatCell &rhs);
    FloatCell &operator=(FloatCell &&rhs) noexcept;


    FloatCell &operator = (float rhs);

   [[nodiscard]] float getValue() const;
   void setValue(int newValue);

private:
    float storedValue;

};


#endif //MM_FLOATCELL_H
