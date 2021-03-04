// 给定一个R行C列的地图，地图的每一个方格可能是'#', '+', '-', '|', '.', 'S', 'T'七个字符中的一个，分别表示如下意思：
// 　　'#': 任何时候玩家都不能移动到此方格；
// 　　'+': 当玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格；
// 　　'-': 当玩家到达这一方格后，下一步可以向左右两个方向相邻的一个非'#'方格移动一格；
// 　　'|': 当玩家到达这一方格后，下一步可以向上下两个方向相邻的一个非'#'方格移动一格；
// 　　'.': 当玩家到达这一方格后，下一步只能向下移动一格。如果下面相邻的方格为'#'，则玩家不能再移动；
// 　　'S': 玩家的初始位置，地图中只会有一个初始位置。玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格；
// 　　'T': 玩家的目标位置，地图中只会有一个目标位置。玩家到达这一方格后，可以选择完成任务，也可以选择不完成任务继续移动。如果继续移动下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格。
// 　　此外，玩家不能移动出地图。
// 　　请找出满足下面两个性质的方格个数：
// 　　1. 玩家可以从初始位置移动到此方格；
// 　　2. 玩家不可以从此方格移动到目标位置。
// 输入格式
// 　　输入的第一行包括两个整数R 和C，分别表示地图的行和列数。(1 ≤ R, C ≤ 50)。
// 　　接下来的R行每行都包含C个字符。它们表示地图的格子。地图上恰好有一个'S'和一个'T'。
// 输出格式
// 　　如果玩家在初始位置就已经不能到达终点了，就输出“I'm stuck!”（不含双引号）。否则的话，输出满足性质的方格的个数。
// 样例输入
// 5 5
// --+-+
// ..|#.
// ..|##
// S-+-T
// ####.
// 样例输出
// 2
// 样例说明
// 　　如果把满足性质的方格在地图上用'X'标记出来的话，地图如下所示：
// 　　--+-+
// 　　..|#X
// 　　..|##
// 　　S-+-T
// 　　####X

#include <iostream>
#include <cstring>

using namespace std;
 
const int N = 50;
const int DIRECTSIZE = 4;
struct _direct {
    int dr, dc;
} direct[DIRECTSIZE] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char grid[N][N+1];
int visited[N][N], visited2[N][N];
int R, C;
// 判断坐标是否合法或可移动到

inline bool islegal(int r, int c)
{
    if(0 <= r && r < R && 0 <= c && c < C && !visited[r][c] && grid[r][c] != '#')
        return true;
    else
        return false;
}

// 深度优先搜索
void dfs(int r, int c)
{
    int nextr, nextc;
    visited[r][c] = 1;
    if(grid[r][c] == '+' || grid[r][c] == 'S' || grid[r][c] == 'T') {
        for(int i=0; i<DIRECTSIZE; i++) {
            nextr = r + direct[i].dr;
            nextc = c + direct[i].dc;
            if(islegal(nextr, nextc))
                dfs(nextr, nextc);
        }
    } else if(grid[r][c] == '-') {
        for(int i=2; i<DIRECTSIZE; i++) {
            nextr = r + direct[i].dr;
            nextc = c + direct[i].dc;
            if(islegal(nextr, nextc))
                dfs(nextr, nextc);
        }
    } else if(grid[r][c] == '|') {
        for(int i=0; i<2; i++) {
            nextr = r + direct[i].dr;
            nextc = c + direct[i].dc;
            if(islegal(nextr, nextc))
                dfs(nextr, nextc);
        }
    } else if(grid[r][c] == '.') {
        nextr = r + direct[1].dr;
        nextc = c + direct[1].dc;
        if(islegal(nextr, nextc))
            dfs(nextr, nextc);
    }
}

int main(){
    freopen("./05IamStuck.data","r",stdin);
    int sr, sc, tr, tc;
    // 输入数据
    cin >> R >> C;
    for(int i=0; i<R; i++)
        cin >> grid[i];
    // 找到起点和终点坐标
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(grid[i][j] == 'S')
                sr = i, sc = j;
            else if(grid[i][j] == 'T')
                tr = i, tc = j;
    // bfs：标记从"S"点可以到达的点
    memset(visited, 0, sizeof(visited));
    dfs(sr, sc);
    memcpy(visited2, visited, sizeof(visited));
    if(visited2[tr][tc]) {
        int count = 0;
        // 统计"S"点可以到达、而不可到达"T"点的数量
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++) {
                if(visited2[i][j]) {    // "S"点可以到达的<i,j>点
                    // bfs：标记从<i,j>点开始可以到达的点，如果不能到达"T"点则计数
                    memset(visited, 0, sizeof(visited));
                    dfs(i, j);
                    if(!visited[tr][tc])
                        count++;
                }
            }
        // 输出结果
        cout << count << endl;
    } else
        // 从"S"点不可以到达"T"点
        cout << "I'm stuck!" << endl;
    
    return 0;
}