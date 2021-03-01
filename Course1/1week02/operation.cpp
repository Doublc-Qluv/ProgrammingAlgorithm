#include <iostream>
#include <cstdio>
using namespace std;

int operation(){
    int n1 = 4, n2 = 5, n3;
    n3 = (n1 > n2);
    cout << n3 << ",";//n3=0
    n3 = (n1 < n2);
    cout << n3 << ",";//n3=1
    n3 = (n1 == 4);
    cout << n3 << ",";//n3=1
    n3 = (n1 != 4);
    cout << n3 << ",";//n3=0
    n3 = (n1 == 5);
    cout << n3 << endl;       //n3=0
    return 0;
}

int logic_operation(){
    int a=0, b=1;
    bool n = (a++) && (b++);//b++不被计算
    cout << a << "," << b << endl;// 1,1
    n = a++ && b++;
    cout << a << "," << b << endl;// 2，2
    n = a++ || b++; //b++ 不被计算
    cout << a << "," << b << endl;// 3，2
    return 0;
}

/*运算符的优先级
high
++ -- !
* / %
+ -
< <= > >= == !=
&& ||
= += -= *= /= %=
low
*/
int priority(){
    int a=1,b=1;
    int n1 = a++;
    int n2 = ++b;
    
    a=b=1;
    printf("a+++b = %d? %d,%d",a+++b,n1+1,1+n2);
    return 0;
}

int main(){
    operation();//运算基本操作
    logic_operation();//逻辑运算
    priority();//运算优先级
}