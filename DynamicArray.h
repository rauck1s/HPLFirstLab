//
// Created by Dmitri on 13.03.2024.
//

#ifndef LAB1_DYNAMICARRAY_H
#define LAB1_DYNAMICARRAY_H

#include <iostream>
#include <cassert>
#include <ostream>

class DynamicArray {
private:

    int *arr;
    int size;
    int capacity;

public:
    DynamicArray();

    explicit DynamicArray(int size); //спросить про explicit, понятно что делает но не понятно надо ли нам

    DynamicArray(int size, int num);

    DynamicArray(const DynamicArray &obj);

    DynamicArray(DynamicArray&&obj) noexcept ;

    DynamicArray(const int* data, int size);

    ~DynamicArray();

    int &operator[](int index);

    void resize(int newSize);

    DynamicArray &operator=(DynamicArray& obj);

    DynamicArray &operator=(DynamicArray&& obj) noexcept ;

    bool operator==(const DynamicArray &rhs) const;

    bool operator!=(const DynamicArray &rhs) const;

    bool operator<(const DynamicArray &rhs) const;

    bool operator>(const DynamicArray &rhs) const;

    bool operator<=(const DynamicArray &rhs) const;

    bool operator>=(const DynamicArray &rhs) const;

    DynamicArray & operator+(DynamicArray &rhs);

    int *getArr() const;

    void setArr(int *arr);

    int getSize() const;

    void setSize(int size);
};


#endif //LAB1_DYNAMICARRAY_H
