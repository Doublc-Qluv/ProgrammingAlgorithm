#include <iostream>
#include <cstdio>
using namespace std;
// 求平方根: 牛顿迭代法：xn+1 = (xn + a / xn)/2
double esp = 0.001; //控制精度
int main(){
    int a;
    double lastX;
    a = 3;
    // cin >> a ;
    if(a >= 0){
        double x = a / 2;
        lastX = x + 1 + esp; // 至少一次

        while(x - lastX > esp || lastX - x > esp){
            lastX = x;
            x = (x + a / x) / 2;
        }
        cout << x;
    }
    else{
        cout << "can not";
    }

    return 0;
}