//
// Created by Dmitri on 13.03.2024.


#include "DynamicArray.h"

/*default constructor*/
DynamicArray::DynamicArray() {
    try {
        this->size = 1;
        this->arr = new int[this->size];
        arr[0] = 0;
        capacity = size * 3 / 2 + 1;
    } catch (const std::bad_alloc &e) {
        std::cerr << " Memory allocation failed: " << e.what() << "\n";
        throw std::bad_alloc();
    }
}

/*constructor by size*/
DynamicArray::DynamicArray(int size) {
    assert(size > 0 && "Size must be positive");

    try {
        this->size = size;
        arr = new int[this->size]{};
        capacity = size * 3 / 2 + 1;
        for (int i = 0; i < this->size; i++) {
            arr[i] = 0;
        }

    } catch (const std::bad_alloc &e) {
        std::cerr << " Memory allocation failed: " << e.what() << "\n";
        throw std::bad_alloc();
    }
}

/*constructor by size and number "n" */
DynamicArray::DynamicArray(int size, int num) {
    assert(size > 0 && "Size must be positive");

    try {
        this->size = size;
        arr = new int[this->size]{};
        capacity = size * 3 / 2 + 1;
        for (int i = 0; i < size; i++) {
            arr[i] = num;
        }

    } catch (const std::bad_alloc &e) {
        std::cerr << " Memory allocation failed: " << e.what() << "\n";
        throw std::bad_alloc();
    }
}

/*copy constructor*/
DynamicArray::DynamicArray(const DynamicArray &obj) {
    assert(&obj != nullptr && "Other array must exist");

    try {
        this->size = obj.size;
        this->arr = new int[this->size];
        capacity = size * 3 / 2 + 1;
        for (int i = 0; i < this->size; i++) {
            arr[i] = obj.arr[i];
        }

    } catch (const std::bad_alloc &e) {
        std::cerr << " Memory allocation failed: " << e.what() << "\n";
        throw std::bad_alloc();
    }

}

/*move constructor*/
DynamicArray::DynamicArray(DynamicArray &&obj) noexcept {
    assert(&obj != nullptr && "Other array must exist");

    this->size = obj.size;
    this->arr = obj.arr;
    this->capacity = obj.capacity;

    obj.arr = nullptr;
}

/*destructor*/
DynamicArray::~DynamicArray() {
    delete[] arr;
}


int &DynamicArray::operator[](int index) {
    return arr[index];
}

void DynamicArray::resize(int newSize) {
    assert(newSize > 0 && "Size must be positive");
    try {
        if (newSize == this->size) {
            return;
        }
        if (newSize > this->size) {
            int i = this->size;
            this->size = newSize;
            capacity = size * 3 / 2 + 1;
            for (i; i < newSize; i++) {
                arr[i] = 0;
            }
        }
    } catch (const std::bad_alloc &e) {
        std::cerr << " Memory allocation failed: " << e.what() << "\n";
        throw std::bad_alloc();
    }
}

DynamicArray &DynamicArray::operator=(DynamicArray &obj) {
    assert(&obj != nullptr && "Array most exist");

    try {
        if (this != &obj) {
            delete[] arr;
            size = obj.size;
            arr = new int[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = obj.arr[i];
            }
        }
    } catch (const std::bad_alloc &e) {
        std::cerr << " Memory allocation failed: " << e.what() << "\n";
        throw std::bad_alloc();
    }

    return *this;
}

DynamicArray &DynamicArray::operator=(DynamicArray &&obj) noexcept {
    assert(&obj != nullptr && "Array most exist");

    try {
        if (this != &obj) {
            delete[] arr;
            size = obj.size;
            arr = obj.arr;
            for (int i = 0; i < size; ++i) {
                arr[i] = obj.arr[i];
            }
            obj.arr = nullptr;
        }

    } catch (const std::bad_alloc &e) {
        std::cerr << " Memory allocation failed: " << e.what() << "\n";
        throw std::bad_alloc();
    }

    return *this;
}


bool DynamicArray::operator==(const DynamicArray &rhs) const {

    assert(this->size == rhs.getSize());

    for (int i = 0; i < this->size; i++) {
        if (this->arr[i] != rhs.getArr()[i]) {
            return false;
        }
    }

    return true;
}

bool DynamicArray::operator!=(const DynamicArray &rhs) const {
    return !(rhs == *this);
}

bool DynamicArray::operator<(const DynamicArray &rhs) const {
    if (this->size > rhs.getSize()) {
        return true;
    }
    if (this->size < rhs.getSize()) {
        return false;
    }
    for (int i = 0; i < this->size; i++) {
        if (this->arr[i] > rhs.getArr()[i]) {
            return false;
        }
        if (this->arr[i] < rhs.getArr()[i]) {
            return true;
        }
    }
    return false;
}

bool DynamicArray::operator>(const DynamicArray &rhs) const {
    return rhs < *this;
}

bool DynamicArray::operator<=(const DynamicArray &rhs) const {
    return !(rhs < *this);
}

bool DynamicArray::operator>=(const DynamicArray &rhs) const {
    return !(*this < rhs);
}

DynamicArray &DynamicArray::operator+(DynamicArray &rhs) {
    assert(&rhs != nullptr && "Other array should exist");
    try {
        DynamicArray result(size + rhs.size);

        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i];
        }

        for (int i = 0; i < rhs.size; ++i) {
            result.arr[size + i] = rhs.arr[i];
        }

        return result;
    }
    catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
}

int *DynamicArray::getArr() const {
    return arr;
}

int DynamicArray::getSize() const {
    return size;
}


