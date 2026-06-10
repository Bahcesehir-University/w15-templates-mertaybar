// ============================================================================
//  Lab: C++ Templates  (STUDENT VERSION)
//  Course: Object-Oriented Programming with C++
//  Single file only. No headers. C++17.
//
//  Complete every TODO. Do NOT rename the functions/classes/methods,
//  and do NOT change their signatures - the autograder depends on them.
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// ================================
// CLASS / TEMPLATE DEFINITIONS
// ================================

// ---- Group 1: Basic function template -------------------------------------
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// ---- Group 2: Function template with multiple type parameters --------------
template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

// ---- Group 3: Class template ----------------------------------------------
template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;

public:
    Pair(A first, B second) : first_(first), second_(second) {
    }

    A getFirst() const {
        return first_;
    }

    B getSecond() const {
        return second_;
    }

    void setFirst(A value) {
        first_ = value;
    }

    void setSecond(B value) {
        second_ = value;
    }

    void swapValues() {
        A temp = first_;
        first_ = second_;
        second_ = temp;
    }
};

// ---- Group 4: Generic container -------------------------------------------
template <typename T>
class Box {
private:
    std::vector<T> items_;

public:
    void add(const T& item) {
        items_.push_back(item);
    }

    int size() const {
        return static_cast<int>(items_.size());
    }

    T get(int index) const {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Invalid index");
        }

        return items_[index];
    }

    T total() const {
        T sum = T();

        for (const T& item : items_) {
            sum += item;
        }

        return sum;
    }
};

// ---- Group 5: Template specialization -------------------------------------
template <typename T>
int describe(const T& value) {
    return 1;
}

template <>
int describe<std::string>(const std::string& value) {
    return 2 + static_cast<int>(value.length());
}

// ---- Group 6: Non-type template parameter ---------------------------------
template <typename T, int N>
class FixedArray {
private:
    T data_[N];

public:
    FixedArray() {
        for (int i = 0; i < N; i++) {
            data_[i] = T();
        }
    }

    int capacity() const {
        return N;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Invalid index");
        }

        data_[index] = value;
    }

    T at(int index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Invalid index");
        }

        return data_[index];
    }
};

// ================================
// FUNCTION IMPLEMENTATIONS / main
// ================================

int main() {
    std::cout << "=== C++ Templates Lab ===\n";

    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << "\n";
    std::cout << "addValues(3, 2.5) = " << addValues(3, 2.5) << "\n";

    Pair<int, int> p(10, 20);
    std::cout << "Pair first: " << p.getFirst() << "\n";
    std::cout << "Pair second: " << p.getSecond() << "\n";
    p.swapValues();
    std::cout << "After swap first: " << p.getFirst() << "\n";
    std::cout << "After swap second: " << p.getSecond() << "\n";

    Box<int> box;
    box.add(5);
    box.add(10);
    box.add(15);
    std::cout << "Box size: " << box.size() << "\n";
    std::cout << "Box total: " << box.total() << "\n";

    std::cout << "describe(5): " << describe(5) << "\n";
    std::cout << "describe(std::string(\"hello\")): " << describe(std::string("hello")) << "\n";

    FixedArray<int, 3> arr;
    arr.set(0, 100);
    arr.set(1, 200);
    arr.set(2, 300);

    std::cout << "FixedArray capacity: " << arr.capacity() << "\n";
    std::cout << "arr.at(1): " << arr.at(1) << "\n";

    return 0;
}
