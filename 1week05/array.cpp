#include <iostream>
#include <cstdio>
using namespace std;
#define NUM 10
int a[NUM];
int main(){
    freopen("/Users/doublc.qluv/git_repo/ProgrammingAlgorithm/1week05/num.txt","r",stdin);
    for(int i = 0;i < NUM;i++){
        cin >> a[i];
    }
    for(int i = NUM-1; i >= 0; i--){
        cout << a[i] << " ";
        
    }

    return 0;
}