#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int m = 20;
    for (int i = 1; i < m; i++)
    {
        if(i % 2)
            continue;//奇数
        cout << i << ",";
    }
    return 0;
}