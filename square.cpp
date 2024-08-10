#include <iostream>

int square(int value) {
    return value*value;
}

// function arg doesn't have to have a name
double sqr(double){
    return 2;
};

void f(const int& x) {
  int& y = const_cast<int&>(x);
  y+=1;
  std::cout << "Number after adding 1 with const_cast: " << y << std::endl;
}

void addOne(int &num) {
    num += 1;
}

void addOne(int *numPtr) {
    // Check if the pointer is valid (not nullptr)
    if (numPtr != nullptr) {
        // Increment the value at the memory location pointed to by numPtr
        (*numPtr) += 1;
    }
}

#include <vector>

void modifyVector(const std::vector<int> &vec) {
    // Using const_cast to remove the const qualifier temporarily
    std::vector<int> &mutableVec = const_cast<std::vector<int> &>(vec);

    // Now you can modify mutableVec safely
    for (int &element : mutableVec) {
        element += 1;
    }

    std::cout << "Vector after adding 1 to each element:";
    for (const int &element : mutableVec) {
        std::cout << " " << element;
    }
    std::cout << std::endl;
}