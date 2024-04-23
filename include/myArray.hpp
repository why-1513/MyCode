#ifndef MYARRY_H
#define MYARRY_H

#include <iostream>

template<class T>
class MyArray{

public:

    //构造函数
    MyArray(int capacity){
        std::cout << "构造函数" << std::endl;
        this->myCapacity = capacity;
        this->mySize = 0;
        this->pAddress = new T[this->myCapacity];
    }

    //拷贝构造函数
    MyArray(const MyArray& arr){
        std::cout << "构造函数" << std::endl;
        this->myCapacity = arr.myCapacity;
        this->mySize = arr.mySize;

        //深拷贝
        this->pAddress = new T[arr.myCapacity];

        for (int i =0; i < this->mySize; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= 防止浅拷贝
    MyArray& operator=(const MyArray& arr){
        //先判断原来堆区是否有数据，如果有先释放
        if(this->pAddress != NULL){
            delete[] this->pAddress;
			this->pAddress = NULL;
			this->myCapacity = 0;
			this->mySize = 0;
        }

        //深拷贝
        this->myCapacity = arr.myCapacity;
        this->mySize = arr.mySize;
        this->pAddress = new T[arr.myCapacity];

        for (int i =0; i < this->mySize; i++){
            this->pAddress[i] = arr.pAddress[i];
        }      
    }

    //析构函数
    ~MyArray(){
		if (this->pAddress != NULL)
		{   
            std::cout << "析构函数" << std::endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->myCapacity = 0;
			this->mySize = 0;
		}
    }

private:

    T * pAddress; //指针指向堆区开辟的数组

    int myCapacity;
    int mySize;
    
};

#endif