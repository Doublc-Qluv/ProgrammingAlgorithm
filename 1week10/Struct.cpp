#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    unsigned ID;
    char szName[20];
    float fGPA;
};

struct StudentEx//结构体可以嵌套
{
    unsigned ID;
    char szName[20];
    float fGPA;
    Date birthday;
};

struct Employee//成员变量可以是本结构类型的指针
{
    string name;
    int age;
    int salary;
    Employee *next;
};


void visit(){
    // StudentEx stu;
    // cin >> stu.fGPA;
    // stu.ID = 12345;
    // strcpy(stu.szName, "Tom");
    // cout << stu.fGPA;
    // stu.birthday.year = 1994;
    // unsigned int * p = & stu.ID;
    StudentEx MyClass[50];
    StudentEx MyClass2[50] = {
        {1234,"Tom",3.78,{1984,12,28}},
        {1235,"Jack",3.25,{1985,12,23}},
        {1236,"Mary",4.00,{1984,12,21}},
        {1237,"Jone",2.78,{1985,2,28}}
    };
    StudentEx *pStu = MyClass;
    pStu->ID = 1267;//可以用: 指针->成员变量名
    (*pStu).fGPA = 3.2;//可以用: (*指针).成员变量名
    MyClass[2].birthday.year = 1986;
    int n = MyClass[2].birthday.month;
    // cin >> MyClass[0].szName;
    cout << "ID:" << pStu->ID << "\nfGPA:"<< (*pStu).fGPA << endl;
    cout << MyClass[2].birthday.year << endl;
}

int main(){
    visit();
}
