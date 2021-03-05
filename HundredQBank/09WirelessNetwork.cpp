// 问题描述
// 目前在一个很大的平面房间里有 n 个无线路由器,每个无线路由器都固定在某个点上。
// 任何两个无线路由器只要距离不超过 r 就能互相建立网络连接。
// 除此以外,另有 m 个可以摆放无线路由器的位置。你可以在这些位置中选择至多 k 个增设新的路由器。
// 你的目标是使得第 1 个路由器和第 2 个路由器之间的网络连接经过尽量少的中转路由器。
// 请问在最优方案下中转路由器的最少个数是多少?

// 输入格式
// 第一行包含四个正整数 n,m,k,r。 (2 ≤ n ≤ 100,1 ≤ k ≤ m ≤ 100, 1 ≤ r ≤ 108)。
// 接下来 n 行,每行包含两个整数 xi 和 yi,表示一个已经放置好的无线 路由器在 (xi, yi) 点
// 处。输入数据保证第 1 和第 2 个路由器在仅有这 n 个路由器的情况下已经可以互相连接(经过一系
// 列的中转路由器)。
// 接下来 m 行,每行包含两个整数 xi 和 yi,表示 (xi, yi) 点处可以增设 一个路由器。
// 输入中所有的坐标的绝对值不超过 108,保证输入中的坐标各不相同。

// 输出格式
// 输出只有一个数,即在指定的位置中增设 k 个路由器后,从第 1 个路 由器到第 2 个路由器最
// 少经过的中转路由器的个数。

// 样例输入
// 5 3 1 3
// 0 0
// 5 5
// 0 3
// 0 5
// 3 5
// 3 3
// 4 4
// 3 0

// 样例输出
// 2




// 算法采用SPFA为基础，在最短路径计算中，由于题目限制新增路由器数量为k。
// 因此算法将到达同一点的两个路径，如果这两条路径需要新增的路由器数量不同的话视为不同路径，在d,vis后面增加数组维数作为不同路径的区分。
// 也就是说d[1][2] d[1][4]都表示到点1的路径，但是这两条路径的新增路由器数量不同，一个为2，一个为4。
// 为什么需要这样？如果我们对每个节点只储存一个最小新增路由器数量的话，那对于下一个节点就无法计算了，因为我们不知道当前通过前一个节点的路径到底新增了多少路由器。
#include<algorithm>
#include<iostream>
#include<queue>
#include<string.h>

// n+m=200
#define NMMAX 210
#define INF 0x3f3f3f3f

typedef long long LL;

using namespace std;

int n,m,k,r;
struct Point{
    int x,y;
    Point(){}
    Point(int a, int b):x(a),y(b){}
}p[NMMAX];
Point curp, nextp;
// d[i][j]表示从源点到i节点，其中增加j个路由器的路径的最短路径
int d[NMMAX][NMMAX];
// vis[i][j]表示从源点到i节点，其中增加j个路由器的路径信息是否在栈中
int vis[NMMAX][NMMAX];
// 邻接矩阵
int G[NMMAX][NMMAX];

void spfa(Point start)
{
    // 此处队列中的结构体P意义不同，其x存储当前节点，y存储到当前节点增加的路由器个数
    queue<Point> q;
    // 初始化数据
    memset(d,INF,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[0][0]=0;
    vis[0][0]=1;
    q.push(start);

    while(!q.empty())
    {
        curp = q.front();
        q.pop();
        // 取值后将该节点置为非栈中
        vis[curp.x][curp.y] = 0;
        for(int i=0;i<n+m;++i)
            if(G[curp.x][i])
            {
                // 从当前节点curp到nextp节点的信息更新，如果此时nextp节点为新增，那么说明此路径变为从原点到nextp的路径且新路径新增路由器数为++nextp.y
                nextp.x = i;
                nextp.y = curp.y;
                // nextp 节点为新增路由器节点
                if(i>=n){
                    ++nextp.y;
                }
                // 首先保证到nextp节点的新增路由器数目小于k，否在无需再继续往下搜索
                // 其次判断原来已有d[nextp.x][nextp.y]的长度是否大于新路径长度，如果大于取小值。
                if( nextp.y<=k && d[nextp.x][nextp.y]>d[curp.x][curp.y]+1 )
                {
                    d[nextp.x][nextp.y] = d[curp.x][curp.y]+1;
                    // 如果当前节点未在栈中，压入栈。
                    // 个人觉得vis作用主要是防止同一节点多次在栈中会造成多次更新，因为我们修改的是P以外的数据d，所以只需要保证有一个nextp在栈中能够更新就行。
                    if(!vis[nextp.x][nextp.y])
                    {
                        vis[nextp.x][nextp.y] = 1;
                        q.push(nextp);
                    }
                }
            }
    }
}

int main()
{
    freopen("./09WirelessNetwork.data","r",stdin);
    cin>>n>>m>>k>>r;
    // 路由器点，放置点都认为是节点。 在这里结构体p存储的是坐标点。
    for(int i=0; i<n+m; ++i){
        cin>>p[i].x>>p[i].y;
    }
    for(int i=0; i<n+m; ++i)
        // j=i+1,题目明显关于图，首先把数据处理成图形式。
        for(int j=i+1; j<n+m; ++j){
            // 计算两点距离是否小于r
            LL dis = (LL)(p[i].x-p[j].x)*(p[i].x-p[j].x) + (LL)(p[i].y-p[j].y)*(p[i].y-p[j].y);
            if(dis <= (LL)r*r){
                G[i][j] = G[j][i] =1;
            }
        }
    spfa(Point(0,0));
    int cost = INF;
    for(int i=0;i<=k;i++){
        cost = min(cost, d[1][i]);
    }
    // 除掉目的地节点
    cout<<cost-1;
    return 0;
}



// https://blog.csdn.net/qq_16234613/article/details/52388890 algo
// https://blog.csdn.net/qq_16234613/article/details/77482417 code source