#ifndef MYARRY_H
#define MYARRY_H

#include <iostream>

template<class T>
class MyArray{

public:

    //有参构造函数
    MyArray(int capacity){
        //std::cout << "构造函数" << std::endl;
        this->myCapacity = capacity;
        this->mySize = 0;
        this->pAddress = new T[this->myCapacity];
    }

    //拷贝构造函数
    MyArray(const MyArray& arr){
        //std::cout << "构造函数" << std::endl;
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

    //尾插法
    void push_back(const T & val){
        //判断容量是否等于大小
        if(this->myCapacity == this->mySize){
            return;
        }
        //在数组末尾插入数据
        this->pAddress[this->mySize] = val;
        //更新数组大小
        this->mySize++;
    }

    //尾删法
    void pop_back(){
        //让用户访问不到最后一个元素，即为尾删，逻辑删除
        if(this->mySize == 0){
            return;
        }
        this->mySize--;
    }
    
    //通过下标方式访问数组元素
    T & operator[] (int index){
        return this->pAddress[index];
    }

    const T & operator[] (int index) const {
        return this->pAddress[index];
    }

    //返回数组容量
    int getCapacity() const {
        return this->myCapacity;
    }

    //返回数组大小
    int getSize() const {
        return this->mySize;
    }

    //析构函数
    ~MyArray(){
		if (this->pAddress != NULL)
		{   
            //std::cout << "析构函数" << std::endl;
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