#include <iostream>
#include "myArray.hpp"

void test01(){
    MyArray<int>array1(10);
    std::cout << "test" << std::endl;
}

int main(){  
    test01();
    return 0;
}