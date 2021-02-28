//n个数，找出出现次数最多的，数字最小的
#include <iostream>
using namespace std;

int main(){
    freopen("./01MostNum.data","r",stdin);
    int n,s,t;
    cin >> n;
    int a[10001]={};
    for(int i = 0; i < n;i++){
        cin >> s;
        a[s]++;
        if(a[s]>a[t]) t=s;
        if(a[s]==a[t]) t=(s<t? s:t);
    }
    cout << t <<endl;
    return 0;
}