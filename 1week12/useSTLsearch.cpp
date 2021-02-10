#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

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

    sort(a,a+6);
    for(int i = 0; i < 6;i++)
        cout << a[i]<<",";
    cout<<endl;
    //binary_search(_ForwardIterator __first, _ForwardIterator __last,const _Tp& __val)
    cout <<"result:"<<binary_search(a,a+6,124)<<endl;
    cout <<"result:"<<binary_search(a,a+6,123)<<endl;
    cout <<"result:"<<binary_search(a,a+6,5,Rule2())<<endl;
    cout<<endl;
    //lower_bound(_ForwardIterator __first, _ForwardIterator __last,const _Tp& __val)
    //小于value下标最大的
    sort(b,b+10);
    for(int i = 0; i < 10;i++)
        cout << b[i]<<",";
    cout<<endl;
    int *p = lower_bound(b,b+10,9);
    cout << *p << "," << p-b << endl;
    cout<<endl;
    //upper_bound(_ForwardIterator __first, _ForwardIterator __last,const _Tp& __val)
    //大于value下标最小的
    p = upper_bound(b,b+10,5);
    cout << *p << endl;
    cout<<* upper_bound(b,b+10,9) << endl;
}