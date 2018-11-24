﻿#include<iostream>
#include<windows.h>
using namespace std;
class Student
{
private:
	static int total;       //私有的静态数据成员
	int num;
	char name[20];
public:
	Student() { total++; }     //构造函数，每定义一个新对象，则total加1
	~Student() { total--; }    //析构函数，每一个对象生命期结束，则total减1
	Student(int n, char *p = "Wang");
	void GetName();
	int Getnum();
	static void Print();       //声明一个公有的静态成员函数
};
int Student::total = 0;             //静态数据成员的初始化
Student::Student(int n, char *p)  //带参构造函数，每定义一个新对象，则total加1
{
	num = n;
	strcpy_s(name, p);
	total++;
}
void Student::GetName()
{
	cout << name << endl;
}
int Student::Getnum()
{
	return num;
}
void Student::Print()              //定义该公有静态成员函数，此处不能再加static
{
	cout << "The number of all students: " << total << endl;
}
/*------------------------主函数-----------------------------*/
int main()
{
	Student::Print();                       //无对象时可用类名::静态成员函数名（）形式输出total
	Student *p = new Student(13);           //用指针申请动态空间并得到对象*p
	Student::Print();                       //用类名::静态成员函数名（）形式输出total
	p->Print();                             //用指针所指向的对象去访问静态成员函数名（）
	delete p;                              //通过指针删除动态对象，析构一次
	Student::Print();                      //用类名::静态成员函数名()输出total
	Student s[2];                          //定义两个对象，构造函数调用两次
	Student::Print();                          //这两行输出结果一定相同
	Student::Print();

	system("pause");
	return 0;
}