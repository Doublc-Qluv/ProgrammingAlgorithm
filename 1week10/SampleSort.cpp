#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
// #define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
/*
选择排序：
如果按照从小到大排序，找到最小的放在第一位
*/
void SelectionSort(int a[], int size){
    for(int i = 0; i < size - 1; i++){
        int tMin = i;
        for(int j = i+1; j < size; j++){
            if(a[j] < a[tMin])
                tMin = j;
        }

        //交换
        #ifndef SWAP
        int tmp = a[i];
        a[i] = a[tMin];
        a[tMin] = tmp;
        #endif
        //或者提前定义swap函数
        #ifdef SWAP
        SWAP(list[i], list[min], temp);
        #endif
    }
}

/*
插入排序：
初始状态为前有序后无序的两部分（a[0]是有序的），将无序的部分依次插入进有序的部分
*/
void InsertionSort(int a[], int size){
    for(int i = 1;i < size; ++i){//a[i]最左面无序的数，将其插入
        for(int j = 0;j < i; ++j){
            if(a[j] > a[i]){//将a[i]放在j的位置，原下标j到i-1都往后移动一位
                int tmp = a[i];
                for(int k = i; k > j; --k){
                    a[k] = a[k-1];
                }
                a[j] = tmp;
                break;
            }
        }
    }
}

/*
冒泡排序
*/

void BubbleSort(int a[], int size){
    for(int i = size-1; i > 0; --i){//将未排序部分最大值移动到i的位置
        for(int j = 0; j < i; ++j){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+i];
                a[j+1] = tmp;
            }
        }
    }
}

void bubbleSort(int a[], int size){//先排出小的
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+i];
                a[j+1] = tmp;
            }
        }
    }
}

int main(){
    int a[] = {3,123,4325,653,125,43};
    int b[] = {3,5,1,-7,4,9,-6,8,10,4};
    int size = sizeof(a)/sizeof(int);
    int len = sizeof(b)/sizeof(int);
    // SelectionSort(a,size);
    // InsertionSort(a,size);
    // BubbleSort(a,size);//报错，无法正确排序
    bubbleSort(b,len);
    for(int i = 0;i<len;i++)
        cout<< b[i] <<",";

    cout << endl << "run:" << (double)clock()/CLOCKS_PER_SEC << "s";
}