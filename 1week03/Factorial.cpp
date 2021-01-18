#include <iostream>
#include <cstdio>
using namespace std;

int Factorial_o2(int n){
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        int factorial = 1;
        for(int j = 1; j <= i ; ++j){
            factorial *= j;
        }
        sum += factorial;
    }
    return sum;
}

int Factorial_o(int n){
    int sum = 0;
    int factorial = 1;
    for(int i=1;i<n+1;++i){
        factorial *= i;
        sum += factorial;
    }
    return sum;
}


int main(){
    int n;
    cin >> n;
    cout << "O(n^2)-->" << Factorial_o2(n) << "\tO(n)-->" <<Factorial_o(n) << endl;
}