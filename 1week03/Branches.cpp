//输入数字，输出对应的星期，其他输出错误
//注意如果分支里面没有break，会继续运行下去
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    // n=1;
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    default:
        printf("Illegal number");
    }

    return 0;
}