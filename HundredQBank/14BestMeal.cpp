// 问题描述
// 栋栋最近开了一家餐饮连锁店，提供外卖服务。随着连锁店越来越多，怎么合理的给客户送餐成
// 为了一个急需解决的问题。
// 栋栋的连锁店所在的区域可以看成是一个 n× n 的方格图（如下图所示），方格的格点上的位置上
// 可能包含栋栋的分店（绿色标注）或者客户（蓝色标注），有一些格点是不能经过的（红色标注）。
// 方格图中的线表示可以行走的道路，相邻两个格点的距离为 1。栋栋要送餐必须走可以行走的道
// 路，而且不能经过红色标注的点。
// 送餐的主要成本体现在路上所花的时间，每一份餐每走一个单位的距离需要花费 1 块钱。每个客
// 户的需求都可以由栋栋的任意分店配送，每个分店没有配送总量的限制。
// 现在你得到了栋栋的客户的需求，请问在最优的送餐方式下，送这些餐需要花费多大的成本。
// 输入格式
// 输入的第一行包含四个整数 n, m, k, d，分别表示方格图的大小、栋栋的分店数量、客户的
// 数量，以及不能经过的点的数量。
// 接下来 m 行，每行两个整数 xi, yi，表示栋栋的一个分店在方格图中的横坐标和纵坐标。
// 接下来 k 行，每行三个整数 xi, yi, ci，分别表示每个客户在方格图中的横坐标、纵坐标和
// 订餐的量。（注意，可能有多个客户在方格图中的同一个位置）
// 接下来 d 行，每行两个整数，分别表示每个不能经过的点的横坐标和纵坐标。
// 输出格式
// 输出一个整数，表示最优送餐方式下所需要花费的成本。
// 样例输入
// 10 2 3 3
// 1 1
// 8 8
// 1 5 1
// 2 3 3
// 6 7 2
// 1 2
// 2 2
// 6 8
// 样例输出
// 29
// 评测用例规模与约定
// 前 30%的评测用例满足： 1<=n <=20。
// 前 60%的评测用例满足： 1<=n<=100。
// 所有评测用例都满足： 1<=n<=1000， 1<=m, k, d<=n^2。可能有多个客户在同一个格点上。
// 每个客户的订餐量不超过 1000，每个客户所需要的餐都能被送到

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int N=1000+10;
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
struct node{
    int x,y;
    node(int a,int b){
        x=a;y=b;
    }
};
bool g[N][N];
int c[N][N],dist[N][N];
int main(){
    freopen("./14BestMeal.data","r",stdin);
    int n,m,k,d;
    int x,y;
    memset(g,false,sizeof(g));
    memset(c,0,sizeof(c));
    memset(dist,-1,sizeof(dist));
    queue<node> q;
    scanf("%d%d%d%d",&n,&m,&k,&d);
    while(m--){
        scanf("%d%d",&x,&y);
        q.push(node(x,y)); //分店入队
        dist[x][y]=0;
    }
    while(k--){
        scanf("%d%d",&x,&y);
        scanf("%d",&c[x][y]); //记录每个点送餐数量
    }
    while(d--){
        scanf("%d%d",&x,&y);
        g[x][y]=true; //标记不能走的点
    }
    long long ans=0; //这里需要开 long long
    while(!q.empty()){
        node u=q.front();
        q.pop();
        int ux=u.x,uy=u.y;
        ans+=(long long)dist[ux][uy]*c[ux][uy]; //计算每个点送餐花费
        for(int i=0;i<4;i++){
            int nx=ux+dx[i],ny=uy+dy[i];
            if(nx>n||nx<1||ny>n||ny<1||g[nx][ny]) continue;
            if(dist[nx][ny]!=-1) continue;
            q.push(node(nx,ny));
            dist[nx][ny]=dist[ux][uy]+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}