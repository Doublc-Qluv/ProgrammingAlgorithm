#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


void Func1(){
    static int n = 4;//静态变量只初始化一次
    cout << n << endl;
    ++n;
}

void Func2(){
    int n = 4;
    cout << n << endl;
    ++n;
}

int test1(){

    Func1();Func1();Func1();
    Func2();Func2();Func2();
}

//strtok实现，输出字符串被单个字符分割的部分
void UseStrtok(){
    char str[] = "- This, a sample string, OK.";
    char * p = strtok(str, " ,.-");
    while(p != NULL){
        cout << p << endl;
        p = strtok(NULL, " ,.-");
    }
}

char * Strtok(char * p, char * sep){
    static char * start;
    if(p){start = p;}//起点
    for(; *start && strchr(sep, *start); ++start);//跳过分隔符
    if(*start == 0){return NULL;}
    char * q = start;
    for(; *start && !strchr(sep, *start); ++start);//跳过非分隔符
    if(*start){
        *start = 0;
        ++start;
    }
    return q;
}

void UseSelfStrtok(){
    char str[] = "- This, a sample string, OK.";
    char * p = Strtok(str, (char *)" ,.-");//不加入(char *)这里会报了一个warning:
    //warning:deprecated conversion from string constant to 'char*' [-Wwrite-strings]
    while(p != NULL){
        cout << p << endl;
        p = Strtok(NULL, (char *)" ,.-");
    }
}

int main(){
    //test1();
    UseSelfStrtok();
    return 0;
}