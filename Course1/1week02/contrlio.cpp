#include <iostream>
#include <cstdio>

using namespace std;
int main(){
    int n,m; char c; float f;
    scanf("%d %c,%f:%d",&n,&c,&f,&m);//跳过非控制字符
    printf("%d,%c,%f,%d\n",n,c,f,m);
    printf("%5d,%c,%.4f,%05d",n,c,f,m);//%nd,用空格补齐到n；%0nd，用0补齐到n
    return 0;
}