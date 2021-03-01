#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;
int main(){
    freopen("./data.txt","r",stdin);
    int n, max = 0;
    while(cin >> n){
        if(n > max){
            max = n;
        }
    }
    cout << max <<endl;

    return 0;
}