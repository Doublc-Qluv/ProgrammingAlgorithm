/* CCF201403-1 相反数 */
/*
根据题意，输入值得绝对值不大于1000，即输入整数x，满足-1000<=x<=1000。由于C/C++没有负数下标，
就令y=x+1000，这样就把x映射为y，满足0<=y<=2000。
这样，就可以通过一个标志数组来进行判断和标记，输入数后则进行标记。
*/
 
#include <iostream>
#include <cstring>
 
using namespace std;
 
const int N = 1000;
 
int main()
{
    freopen("./06OppositeNum.data","r",stdin);
    int valflag[N*2+1];
    int n, v, minus, sum=0;
 
    // 变量初始化：清零
    memset(valflag, 0, sizeof(valflag));
 
    // 输入数据，判断负值是否已经存在，统计，标记
    cin >> n;
    for(int i=0; i<n; i++) {
        // 输入数据
        cin >> v;
 
        // 值映射：从-1000<=v<=1000映射为0<=v'<=2000
        minus = N - v;  // 负值映射
        v += N;         // 正值映射
 
        // 判断负值是否已经存在
        if(valflag[minus] == 1)
            sum++;
 
        // 标记
        valflag[v] = 1;
    }
 
    // 输出结果
    cout << sum << endl;
 
    return 0;
}