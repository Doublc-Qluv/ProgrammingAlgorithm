#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,m;
    n=3;m=8;
    // cin >> n >> m;
    int a = m + 1, b = n + 1;//a<b
    for (int i = n; i < m; ++i)
    {
        if(i > (a+b)/2 + 1)break;
        for(int j = i; j <= m; ++j){
            if(i + j > a + b)break;
            if(i * j % (i + j) == 0){
                if(i + j < a + b){
                    a = i;b = j;
                }
                else if(i + j == a + b && i < a){
                    a = i;b = j;
                }
            }
        }
    }
    if(a == m + 1){
        cout << "Nn solution";
    }
    else
        cout << "a=" << a << ", b=" << b << endl;
}