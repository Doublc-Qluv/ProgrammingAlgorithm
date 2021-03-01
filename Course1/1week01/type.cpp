#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n1 = 1378;//十六进制0x562
    unsigned short n2;
    unsigned char c = 'a';
    //这俩需要改为无符号数，否则不同的编译器会有警告以及报错，应该是编译器或者什么导致的数据类型的范围有变化
    double d1 = 7.089;
    double d2;

    n2 = c+1;
    printf("c=%c,n2=%d\n",c,n2);//c=b,n2=98
    c = n1;/*n1=0x562,0x62被当作ascii赋值给了c*/
    printf("c=%c,n1=%d\n",c,n1);//c=b,n1=1378
    n1 = d1;
    printf("n1=%d\n",n1);//n1=7
    d2 = n1;
    printf("d2=%f\n",d2);//d2=7.000000



}
