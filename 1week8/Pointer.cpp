#include <iostream>
#include <cstdio>
using namespace std;

/*
指针：4/8 bit，内容代表一个内存地址。
运算：
    可以比较大小；
    同类型指针可以相减；
    指针加减一个整数结果是指针，指针可以自加自减；
    指针可以用“[]”进行运算，即数组名就是指向起始数组的一个指针;
    自由存取内存的数据;
作为参数：
    作为函数形参时，T *p等价于T p[]
*/
void compare(int * p1, int * p2){//比较大小
    if(p1<p2)cout<<"p1<p2"<<endl;
    else if(p1==p2)cout<<"p1=p2"<<endl;
    else cout<<"p1>p2"<<endl;
}

void subtract(int * p1, int * p2){//相减
    printf("p1=%d\tp2=%d\n",p1,p2);
    printf("p1-p2=%d",p1-p2);//100
    //p1-p2=(p1指向地址-p2指向地址)/sizeof(int)
}

void addsubint(int * p){//加减一个整数
    int n = 10;
    printf("n=%d\n",n);
    printf("p+n=%d\n",p + n);
    printf("p-n=%d\n",p - n);    
}

void before_a(){//读取并改变a之战前的一个字节的内容
    int a;
    char * p = (char *) &a;
    --p;
    printf("%c\n", *p);//运行可能出错，要确保a之前的内存可以被访问
    * p = 'A';
    printf("%c", *p);
}

void swap(int * p1, int * p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

    printf("p1=%d\np2=%d",*p1,* p2);
}

void Reverse(int * p,int size){//倒序输出一个数组,
    for(int i = 0; i < size/2; ++i){
        int tmp = p[i];
        p[i] = p[size-1-i];
        p[size-1-i] = tmp;
    }
    //putout
    for(int i = 0;i < size; ++i){
        cout << *(p+i) << ",";
    }
}

int main(){
    int * p1 = (int *)1000, *p2 = (int *)600;
    int m = 3,n = 4;
    int a[5] = {1, 2, 3, 4, 5};
    // compare(p1,p2);
    // subtract(p1,p2);
    // addsubint(p1);
    // before_a();
    // swap(&m, &n);
    Reverse(a,sizeof(a)/sizeof(int));
    return 0;
}