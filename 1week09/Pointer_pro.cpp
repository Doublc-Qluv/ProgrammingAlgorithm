#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void Reverse(int * p,int size){//倒序输出一个数组
    for(int i = 0; i < size/2; ++i){
        int tmp = p[i];
        p[i] = p[size-1-i];
        p[size-1-i] = tmp;
    }
    //putout
    for(int i = 0;i < size; ++i){
        cout << *(p+i) << ",";
    }
    cout << endl;
}

void Pointertopointer(){//指向指针的指针
    int **pp;
    int *p;
    int n = 1234;
    p = &n;//p->n
    pp = &p;//pp->p
    cout << *(*pp) << endl;//输出n
}

void string_operate(){
    /*
    strchr:字符首次出现的位置
    strstr:子串首次出现的位置
    strcmp:比较
    stricmp:大小写无关的比较
    strncmp:前n个子串的比较
    strcpy:复制
    strcat:拼接
    strtok:连续调用可抽取被某字符分隔开的若干字串
    atoi:将字符串转换为整型数
    atof:将字符串转换为实数
    itoa:将整型数转换为任意进制写入进字符串
    */
}

void * myMemcpy(void * dest, const void * src, int n){
    //当原区域和目的区域重叠时，结果会出错
    char * pDest = (char *)dest;
    char * pSrc = (char *)src;
    for(int i = 0; i < n; ++i){
        *(pDest + i) = *(pSrc + i);//逐字节拷贝
    }
    return dest;
}

int main(){
    // int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // Reverse(a[1], 4);
    // Reverse(a[1], 6);//越界
    // Pointertopointer();

    // int a1[10];
    // int a2[10];
    // memset(a1,'a',10);
    // printf("src:%s\n",a1);
    // memcpy(a2, a1,10*sizeof(int));
    // printf("sys:%s\n",a2);
    // myMemcpy(a2, a1,10*sizeof(int));
    // printf("mym:%s\n",a2);
}