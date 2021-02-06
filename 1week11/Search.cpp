#include <iostream>
#include <cstdio>
using namespace std;

int Binarysearch(int a[], int size, int p){//O(logn)
    int L = 0; //区间的左端点
    int R = size - 1; //区间右端点
    while(L <= R){
        int mid = L+ (R - L) / 2;
        if(p == a[mid]) return mid;
        else if(p > a[mid]) L = mid + 1;//值大于中位，取右侧
        else R = mid - 1;//反之，取左侧
    }
    return -1;
}

int LowerBound(int a[],int size, int p){//查找比p小的下标最大的元素
    int L = 0; //区间的左端点
    int R = size - 1; //区间右端点
    int lastPosition = -1;
    while(L <= R){
        int mid = L+ (R - L) / 2;
        if(a[mid]>=p) R = mid - 1;
        else{
            lastPosition = mid;
            L = mid+1;
        }
    }
    return lastPosition;
}

double esp = 1e-6;
double func(double x){return x*x*x - 5*x*x + 10*x - 80;}

void SolvingEquations(){
    double root, x1 = 0, x2 = 100, y;
    root = x1 + (x2 - x1) / 2;
    int triedTims = 1;
    y = func(root);
    while(fabs(y) > esp){
        if(y>0) x2 = root;
        else x1 = root;
        root = x1 + (x2 - x1) / 2;
        y = func(root);
        triedTims ++;
    }

    printf("root = %.8f\n",root);
    printf("triedTims = %d\n",triedTims);
}

int main(){
    int a[] = {1,3,5,52,435,635,6784};
    int p1 = 630;
    int p2 = 5;
    int size = sizeof(a)/sizeof(int);
    // cout << Binarysearch(a,size,p2) << endl;
    // cout << LowerBound(a,size,p2) << endl;
    SolvingEquations();
}