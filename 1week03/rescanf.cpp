#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;
int main(){//使用相对路径失败
    freopen("/Users/doublc.qluv/git_repo/ProgrammingAlgorithm/1week03/data.txt","r",stdin);
    int n, max = 0;
    while(cin >> n){
        if(n > max){
            max = n;
        }
    }
    cout << max <<endl;

    return 0;
}