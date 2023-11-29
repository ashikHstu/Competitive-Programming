#include <iostream>

class Parent {
public:
    Parent(int value) {
        std::cout << "Constructor of Parent class with value: " << value << std::endl;
    }
};

class Child : public Parent {
public:
    Child(int v) : Parent(v) {
        std::cout << "Constructor of Child class with value: " << v << std::endl;
    }
};

int main() {
    // Creating an object of the Child class
    Child childObj(42);

    return 0;
}
