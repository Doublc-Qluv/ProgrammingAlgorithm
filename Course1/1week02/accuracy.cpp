// 精度： double(float 一般运算到时候double) > long long > int > short > char
// 计算结果如果超出数据类型到精度，直接会被舍弃
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    unsigned int n1 = 0xffffffff;
    cout << n1 << endl; // 输出得4294967295
    unsigned int n2 = n1 + 3;
    cout << n2 << endl; // 溢出 得到2， 应该是0x100000002

    return 0;
}