// 问题描述
// 有 N 个非零且各不相同的整数。请你编一个程序求出它们中有多少对相反数(a 和 -a 为一对相反数)。
// 输入格式
// 第一行包含一个正整数 N。 (1 ≤ N ≤ 500)。
// 第二行为 N 个用单个空格隔开的非零整数,每个数的绝对值不超过 1000,保证这些整数各不相同。
// 输出格式
// 只输出一个整数,即这 N 个数中包含多少对相反数。
// 样例输入
// 5
// 1 2 3 -1 -2
// 样例输出
// 2

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    freopen("./06OppositeNum.data","r",stdin);
    int n, ans=0;
    int h[501];
    // 输入数据
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> h[i];
    // sort(h,h+5);
    // for(int j=0; j<n; j++) cout << h[j] << " ";
    // cout << endl;
    for(int i=0;i< n-1; i++){
        for(int j=i;j<n;j++){
            if(h[i]+h[j]==0 && h[i]!=0){
                ans++;
                // cout << h[i] << " "<< h[j] << "  ans=" << ans <<endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}