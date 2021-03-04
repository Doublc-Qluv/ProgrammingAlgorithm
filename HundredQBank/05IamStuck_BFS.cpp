#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <queue>

#define maxn 60
char mmap[maxn][maxn];
int vis[maxn][maxn]; //标记从起点出发
int vis1[maxn][maxn]; //标记从终点出发
int dy[4] = {0, 0, -1, 1}; //转向数组
int dx[4] = {1, -1, 0, 0};
int n, m;
int num[maxn][maxn][maxn][maxn];//记录一些路径
using namespace std;

struct Node{ //定义结构体 
    int x;
    int y;
    Node() {}
    Node(int _x, int _y) {
        x = _x;
        y = _y;
}
} node[maxn];
Node st, ed;

int check(Node a){//节点是否合法 

    if(a.x >= 0 && a.x < n && a.y >= 0 && a.y < m && mmap[a.x][a.y] !='#') {
        return 1;
    }
    return 0;
}

void get(char c, int& u, int& v){//判断当前可以走的方向 
    if(c == '-'){
        u = 2;
        v = 4;
    }
    else if(c == '|'){
        u = 0;
        v = 2;
    }
    else if(c == '.'){
        u = 0;
        v = 1;
    }
    else{
        u = 0;
        v = 4;
    }
}
queue<Node>que;
int bfs(){
    while(!que.empty()) {
        que.pop();
    }
    que.push(st); //从起点走
    vis[st.x][st.y] = 1;
    Node tmp, now;
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        int u, v;
        get(mmap[tmp.x][tmp.y], u, v);
        for(int i = u; i < v; i++){
            now.x = tmp.x + dx[i];
            now.y = tmp.y + dy[i];
            if(check(now)){
                num[tmp.x][tmp.y][now.x][now.y] = 1;
                if(!vis[now.x][now.y]) {
                    vis[now.x][now.y] = 1;
                    que.push(now);
                }
            }
        }
    }
    if(vis[ed.x][ed.y] == 0){
        puts("I'm stuck!");// 若未到达
        return 0;
    }
    que.push(ed); //从终点走
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            now.x = tmp.x + dx[i];
            now.y = tmp.y + dy[i];
            if(check(now) && vis1[now.x][now.y] == 0 && num[now.x][now.y][tmp.x][tmp.y]){
                vis1[now.x][now.y] = 1;
                que.push(now);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == 1 && vis1[i][j] == 0){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
int main(){
    freopen("./05IamStuck.data","r",stdin);
    scanf("%d %d", &n, &m);
    memset(vis, 0, sizeof(vis));
    memset(vis1, 0, sizeof(vis1));
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; i++){
        scanf("%s", mmap[i]);
        for(int j = 0; j < m; j++){
            if(mmap[i][j] == 'S'){
                st.x = i;
                st.y = j;
            }
            if(mmap[i][j] == 'T'){
                ed.x = i;
                ed.y = j;
            }
        }
    }
    bfs();
    return 0;
}