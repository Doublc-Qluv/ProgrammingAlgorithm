/*
z型扫描
对于一个4x4的矩阵
1 5 3 9
3 7 5 6
9 4 6 4
7 3 1 3

对其进行z字形扫描后得到一个长度为16的序列：
1 5 3 9 7 3 9 5 4 7 3 6 6 4 1 3
*/

#include <iostream>

using namespace std;

int main(){
    int i, j, k, n;
    int a[500][500];
    freopen("./16zScan.data","r",stdin);
    cin >> n;
    for(i=0;i<n;i++){//input matrix
        for(j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(k=0;k<2*n-1;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i+j==k){
                    if(k%2==0){
                        cout << a[j][i] ;//<< "," << i <<","<<j<<","<<k<<endl;
                    }
                    else{
                        cout << a[i][j] ;//<< "," << i <<","<<j<<","<<k<<endl;
                    }
                }
            }
        }
    }
    cout << endl;
    return 0; 
}