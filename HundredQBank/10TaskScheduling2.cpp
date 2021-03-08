#include<iostream>
#include<string.h>
#include<cmath>
#define M 41
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define inf 1<<30
using namespace std;
int utime[M][4];
int c1, c2, com, g, sumtime;//c1 c2存两个独立cpu的时间（不是同时进行 com存同时进行的时间 g存gpu的时间
int n;
void slove(int k, int c1, int c2, int com, int g, int sum){
    if (k <= n)
        for (int i = 0; i < 4; i++)
            switch (i)
            {
            case 0://1*cpu
                c1 < c2 ? slove(k + 1, c1 + utime[k][i], c2, com, g, max(max(c1 + utime[k][i], c2) + com, g)) :
                    slove(k + 1, c1, c2 + utime[k][i], com, g, max(max(c1, c2 + utime[k][i]) + com, g));
                break;
            case 1://2*cpu
                slove(k + 1, c1, c2, com + utime[k][i], g, max(max(c1, c2) + com + utime[k][i], g));
                break;
            case 2:
                c1 < c2 ? slove(k + 1, c1 + utime[k][i], c2, com, g + utime[k][i], max(max(c1 + utime[k][i], c2) + com, g + utime[k][i])) :
                    slove(k + 1, c1, c2 + utime[k][i], com, g + utime[k][i], max(max(c1, c2 + utime[k][i]) + com, g + utime[k][i]));
                break;
            case  3:
                slove(k + 1, c1, c2, com + utime[k][i], g + utime[k][i], max(max(c1, c2) + com + utime[k][i], g + utime[k][i]));
                break;
            }
    else if (sumtime >sum)
            sumtime = sum;
}
int main()
{
    freopen("./10TaskScheduling.data","r",stdin);
    sumtime = inf;
    c1 = c2 = g = com = 0;//初始化
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++)
            cin >> utime[i][j];
    slove(1, 0, 0, 0, 0, 0);
    cout << sumtime << endl;
    return 0;
}

//回溯算法