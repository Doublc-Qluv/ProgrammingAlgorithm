#include <iostream>
#include <cstdio>
using namespace std;

void prime_1(int n){
    for(int i = 2; i <= n;i++){
        int k;
        for(k = 2; k < i;k++){
            if(i % k == 0)
                break;
        }
        if(k == i)
            cout << i << endl;
    }
}

void prime_2(int n){
    cout << "2" << endl;
    for(int i = 3; i <= n;i+=2){
        int k;
        for(k = 3; k < i;k+=2){
            if(i % k == 0)
                break;
            if(k * k >i)
                break;
        }
        if(k * k > i)
            cout << i << endl;
    }
}

int main(){
    int n;
//    n=7;
    cin >> n;//n>=2
    prime_1(n);
    cout << "-----" << endl;
    prime_2(n);
    return 0;
}