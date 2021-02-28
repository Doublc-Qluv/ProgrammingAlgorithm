#include <iostream>
#include <cstdio>
using namespace std;


#define ROWS 8
#define LOWS 8

int a[ROWS][LOWS];
int b[ROWS][LOWS];
int c[ROWS][LOWS];

int main(){
    freopen("./matrix_in.txt","r",stdin);
    
    int m,n,p,q;
    //matrix a
    cin >> m >> n;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    //matrix b
    cin >> p >> q;
    for(int i = 0; i < p; ++i)
        for(int j = 0; j < q; ++j)
            cin >> b[i][j];

    //compete c
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < q; ++j){
            c[i][j] = 0;
            for(int k = 0;k < n; ++k){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    //out
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < q; ++j){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}