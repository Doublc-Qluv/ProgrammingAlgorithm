#include <iostream>
#include <cstdio>

using namespace std;

/*
Q1:n个整数，找出两个数之和为m
*/
void Q1try1(int a[], int m, int n){//复杂度O(n^2)
    for(int i = 0;i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            if(a[i] + a[j] == m)
                cout << a[i] << "+" << a[j] << endl;
                break;
        }
    }
}

void Q1try2(int a[], int m, int n){//O(nlogn)
    
    sort(a,a+n);//先排序O(nlogn)
    for(int i; i < n; i++){//二分查找m-a[i]
        int l=i;
        int r = n;
        while(l<=r){
            int mid = l +(r-i)/2;
            if(m-a[i] == a[mid]) cout<<a[i]<<"+"<<a[mid]<<endl;
            else if(m-a[i] > a[mid]) l = mid + 1;
            else r = mid - 1;
        }
    }
}

void Q1try3(int a[], int m, int n){//O(nlogn)
    sort(a,a+n);//先排序O(nlogn)
    int i = 0, j = n-1;

    do{
        if(a[i]+a[j]>m) --j;//大于m代表大的值偏大
        else if(a[i]+a[j]<m) ++i;//小于m代表小的值偏小
    } while (a[i]+a[j] == m);
    cout<<a[i]<<"+"<<a[j]<<endl;
    
}
