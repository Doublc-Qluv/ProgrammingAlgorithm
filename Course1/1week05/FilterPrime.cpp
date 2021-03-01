#include <iostream>
#include <cstdio>
using namespace std;
#define max_num 100000
char isPrime[max_num + 10];

int main(){
    for(int i = 2;i <= max_num; ++i){
        isPrime[i] = 1;//假设全部都是素数为1
    }
    for(int i = 2;i <= max_num; ++i){
        if(isPrime[i]){//素数的倍数是非素数,全部置为0
            for(int j = 2 * i; j <= max_num; j += i){
                isPrime[j]=0;
            }
        }
    }
    for(int i = 2; i <= max_num; ++i){
        if(isPrime[i])
            cout << i << " ";
    }
    return 0;
}