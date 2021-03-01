#include <iostream>
#include <cstdio>
using namespace std;
 int main(){
     int a = 1,b=1,k;
     cin >> k;
     if(k == 1 || k == 2){
         cout << 1 << endl;
     }
     else{
         int sum;
         for (int i = 0; i < k-2; i++)
         {
             sum = a + b;
             a = b;
             b = sum;
         }
         cout << sum << endl;
     }
 }