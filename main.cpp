#include "sqr.h" // everything starting with # is a command to preprocessor
#include "structs_simple.h"
#include <stddef.h> // if "" - looks in same directory, <> - looks also in global paths and -I
#include <iostream>
#include <vector>
#include <cstdint>
// namespae defines a space for particular funciton names
// so we can call functions from std like std::funcA
// and we can write our own funcA
using namespace std;
#include <array>
//#define DEBUG

// constant expr - at compile time, but can be used by non const too
constexpr double trippo(double x) {return x*x*x;}; 
// at compile time ONLY
consteval double trippo2(double x) {return x*x*x;}; 

int main()
{
    std::setlocale(LC_ALL, "Rus");
    #ifdef DEBUG
        cout << "DEBUGGING"<< endl;
    #endif

    // Pointer Просто хранит какой-то адрес
    char c = 'A';
    void* addr =  &c;
    cout <<"ref to c: "<< &c << endl;
    cout <<"pointer to c: "<< addr << endl;
    // Если указатель никуда не ссылается,
    // надо использовать nullptr
    void* invalid = nullptr;
    // Pointer vs ref
    //https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable

    // Размер указателя, например, 4 - это количество
    // байт необходимых для размещения адреса
    size_t size = sizeof(addr); // size == 4/8 (64bit is 8)
    cout << "Size of pointer: " << size<< endl;
    cout << "Size of a char: " << sizeof(c) << endl; //size of a char is 1
    // sizeof(int) = 4

    
    // Теперь мы говорим компилятору как
    // интерпретировать то, на что указывет
    // указатель
    char* charPtr = (char*) &c;
    cout << "charPtr: "<< charPtr << endl;

    // Разыменование - получение значения, находящегося
    // по указанному адресу
    char cc = *charPtr; // c == 1
    cout << "c: " << cc << endl;

    // & - взятие адреса, теперь в charPtrPtr находится
    // адрес charPtr
    char** charPtrPtr = &charPtr;

    int* intPtr = (int*) addr; // addr as int pointer
    int i = *intPtr; //deref addr (as int pointer)
    cout << "addr as int, i: " << i<< endl;

    int* i1 = intPtr;
    int* i2 = i1 + 2; //adding two times the size of int
    ptrdiff_t d1 = i2 - i1; // d1 == 2
    cout << "d1: " << d1 << endl;

    short* c1 = (short*) i1;
    char c11 = *c1;
    char c111 = *i1;
    int i111 = *i1;
    cout << "c111 : " << c111 << endl;
    cout << "i111 : " << i111 << endl; // same as i

    short* c2 = (short*) i2;
    char x = *c2;
    cout << "What is this? " << x << endl;

    ptrdiff_t d2 = c2 - c1; // d2 == 8 - we added 2*int = 8bytes = 8 chars
                            // if c1/c2 is short* then 8bytes = 8/2=4 shorts 
    cout << "d2: " << d2 << endl;

    //free(&x);
    // this is on heap: https://stackoverflow.com/questions/1598397/creating-array-of-objects-on-the-stack-and-heap
    int dt[10] = {5,2,3,4}; // dt is a pointer to the first element of the array
    cout << "dt: " << *dt << endl; // Note
    int z = dt[9];
    cout << "y: " << z << endl;
    
    // this is on stack (because of int*)
    int* data = new int[10]; // new keyword allocates on heap - and you MUST call delete
    int ii = data[15]; // Undefined behaviour?
    cout << "ii: " << ii << endl;


    int ar[20] = { 1, 2, 3 };
    int* j = ar;
    using array = int*; //array is just whenever we type int*
    array k = (array) j;
    cout << "k: " << *k << endl;

    i1 = ar;
    cout << "at i1 now: " << *i1 << endl;
    i1 = i1 + 2 ;//adding two times size of int
    cout << "at i1 now: " << *i1 << endl;
    // Capacity(size) of the array
    cout << "size of ar: " << sizeof(ar) / sizeof(ar[0]) << endl;

    int q = 100;
    int32_t* m = new int[q]; // heap - m is a pointer
    cout << "m: " << *m << endl;
    cout << "at: " << *ar << endl;

    std::array<int, 3> abc = {1,2,3};//#include array
    //abc.front();
    cout << "abc back: " << abc.back() << endl;

    using FPointer = int(*) (int myint);
    FPointer ptr = square;
    int res = ptr(10);
    cout << "res: " << res << endl;

    // https://stackoverflow.com/questions/37247695/const-cast-doesnt-change-the-value#:~:text=As%20for%20why%20it%20doesn,instead%20of%20reading%20the%20variable.
    int zz = 100;
    f(zz); // Note: if zz is const, since int, and const in f, i get's copied into x in f
    cout << "zz post f: " << zz << endl;
    addOne(zz);
    cout << "zz post addOne ref: " << zz << endl;
    addOne(&zz);
    cout << "zz post addOne ptr: " << zz << endl;   

     // lambda. auto - compiler can identify the type
    auto lessThen3 = [](int x) { return x < 3; };
    if (lessThen3(x)) { cout << "x is less than three! "<< endl; }
    /*
        [список_захвата](список_параметров) { тело_функции }
        [список_захвата](список_параметров) -> тип_возвращаемого_значения{ тело_функции }

        [] // без захвата переменных из внешней области видимости
        [=] // все переменные захватываются по значению
        [&] // все переменные захватываются по ссылке
        [x, y] // захват x и y по значению
        [&x, &y] // захват x и y по ссылке
        [in, &out] // захват in по значению, а out — по ссылке
        [=, &out1, &out2] // захват всех переменных по значению,
        // кроме out1 и out2, которые захватываются по ссылке
        [&, x, &y] // захват всех переменных по ссылке, кроме x,
        // которая захватывается по значению

    */

    std::vector<int> originalVector = {1, 2, 3, 4, 5};

    std::cout << "Original vector:";
    for (const int &element : originalVector) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    modifyVector(originalVector);

    // originalVector is modified
    std::cout << "Original vector after modifyVector:";
    for (const int &element : originalVector) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    auto record = fct(1);

    // value of constexpr is calculated at compile time by compiler
    constexpr double max1 = 1.4*trippo(17);

    std::cout << __cplusplus << std::endl;


    //bitwise - compares bit by bit, logical - simply single true or false

    // Unfortunately, conversions that lose information, narrowing conversions, such as double to int and
    // int to char, are allowed and implicitly applied when you use = (but not when you use {}).

        



    return 1;
}