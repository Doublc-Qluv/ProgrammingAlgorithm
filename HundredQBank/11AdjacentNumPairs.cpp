// 问题描述
// 给定 n 个不同的整数，问这些数中有多少对整数，它们的值正好相差 1。
// 输入格式
// 输入的第一行包含一个整数 n，表示给定整数的个数。
// 第二行包含所给定的 n 个整数。
// 输出格式
// 输出一个整数，表示值正好相差 1 的数对的个数。
// 样例输入
// 6
// 10 2 6 3 7 8
// 样例输出
// 3
// 样例说明
// 值正好相差 1 的数对包括(2, 3), (6, 7), (7, 8)。
// 评测用例规模与约定
// 1<=n<=1000，给定的整数为不超过 10000 的非负整数。

#include <iostream>

#include <cstdio>
using namespace std;
int main(){
    freopen("./11AdjacentNumPairs.data","r",stdin);
    int n,nums[1001];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    // for(int i=0;i<n;i++){
    //     cout << nums[i] << " ";
    // }
    int ans=0;
    for(int j=0;j<n-1;j++){
        if(nums[j]-nums[j+1] == -1){
            ans++;
        }
    }
    cout << ans;

}