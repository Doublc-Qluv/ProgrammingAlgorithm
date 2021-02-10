#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Rule1//从大到小
{
    bool operator()(const int & a1,const int & a2) const{
        return a1>a2;
    }
};
struct Rule2//按个位数从小到大
{
    bool operator()(const int & a1,const int & a2) const{
        return a1%10 < a2%10;
    }
};

int main(){
    int a[] = {3,123,4325,653,125,43};
    int b[] = {3,5,1,-7,4,9,-6,8,10,4};
    int c[] = {53,125,43,-6,8,10,4,0};
    //用法1：简单用法，(first,last)从小到大
    sort(a,a+4);//只排序了前四项3,123,653,4325,125,43,
    for(int i = 0; i < 6;i++)
        cout << a[i]<<",";
    
    cout<<endl;
    //用法2：(first,last,comp)按照comp规则排序，此例子从大到小
    sort(b+3, b+7,greater<int>());//排序4到8项3,5,1,9,4,-6,-7,8,10,4,
    for(int i = 0; i < 10;i++)
        cout << b[i]<<",";
    

    cout<< endl;

    sort(c,c+8,Rule2());//按照个位数大小排序：-6,10,0,53,43,4,125,8,
    for(int i = 0; i < 8;i++)
        cout << c[i]<<",";
    return 0;
}