//数字代表高度，宽度定为1，组成直方图，找出指定直方图中最大的矩形并算出其面积
//第一行整数n，即数字数量 <=1000
//第二行为n个整数，其为第i个矩形的高度 <=10000

#include <iostream>
#include <stack>
using namespace std;

// #define N 1000


const int N = 1000;
int h[N+1];
int main(){
//    freopen("./03MaxRectangle.data","r",stdin);
    int n, ans=0, area, temp;
    // 输入数据
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> h[i];
    h[n] = 0;
    // 计算最大矩形面积
    stack<int> s;
    for(int i=0; i<=n; i++) {
        if (s.empty() || h[s.top()] < h[i])
            s.push(i);
        else {
            temp = s.top();
            s.pop(); //弹出
            area = h[temp] * (s.empty() ? i : i - s.top() - 1);
            if (area > ans)
            ans = area;
            --i;
        }
    }
    // 输出结果
    cout << ans << endl;

    return 0;
}