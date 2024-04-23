#include <iostream>
#include "myArray.hpp"
#include <string>

void printIntArray(const MyArray<int>& arr){
    for(int i = 0; i < arr.getSize(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void test01(){
    MyArray<int>array1(5);

    for(int i =0; i < 5; i++){
        array1.push_back(i);
    }

    std::cout << "array1输出:" << std::endl;
    printIntArray(array1);

	std::cout << "array1的大小：" << array1.getSize() << std::endl;
	std::cout << "array1的容量：" << array1.getCapacity() << std::endl;
    
	std::cout << "--------------------------" << std::endl;

	MyArray<int> array2(array1);
	array2.pop_back();
	std::cout << "array2打印输出：" << std::endl;
	printIntArray(array2);
	std::cout << "array2的大小：" << array2.getSize() << std::endl;
	std::cout << "array2的容量：" << array2.getCapacity() << std::endl;
    //MyArray array2 = array1;
    //MyArray<int>array2(array1);
}

//测试自定义数据类型
class Person {
public:
	Person() {} 
		Person(std::string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	std::string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		std::cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << std::endl;
	}

}

void test02()
{
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.push_back(p1);
	pArray.push_back(p2);
	pArray.push_back(p3);
	pArray.push_back(p4);
	pArray.push_back(p5);

	printPersonArray(pArray);

	std::cout << "pArray的大小：" << pArray.getSize() << std::endl;
	std::cout << "pArray的容量：" << pArray.getCapacity() << std::endl;

}

int main(){  
    //test01();
    test02();
    return 0;
}