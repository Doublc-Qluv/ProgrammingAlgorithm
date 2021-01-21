#include <iostream>
#include <cstdio>
using namespace std;

int factorial(int n){//阶乘
    if(n < 2){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
    
}

int fibonacci(int n){//斐波那契数列
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
    
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    cout << fibonacci(n) << endl;
    return 0;
}