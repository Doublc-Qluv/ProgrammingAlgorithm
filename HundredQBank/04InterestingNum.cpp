// 1. 它的数字只包含 0, 1, 2, 3，且这四个数字都出现过至少一次。
// 2. 所有的 0 都出现在所有的 1 之前，而所有的 2 都出现在所有的 3 之前。
// 3. 最高位数字不为 0。
// 计算恰好有 n 位的有趣的数的个数,输出答案除以 1000000007的余数。
// 输入只有一行，包括恰好一个正整数 n (4 ≤ n ≤ 1000)。
// 输出只有一行，包括恰好 n 位的整数中有趣的数的个数除以 1000000007 的余数。

#include<iostream>
using namespace std;
 
int main(){
	long mod=1000000007;
	int n,i,j;
	cin>>n;
	long long **status = new long long*[n+1];
	for(i=-1;++i<n+1;){
		status[i] = new long long[6];
		if(i==0){
			for(j=-1;++j<6;){
				status[0][j] = 0;
			}
		}
		else{
			status[i][0] = 1;
			status[i][1] = (status[i - 1][1] * 2 + status[i - 1][0]) % mod;
			status[i][2] = (status[i - 1][2] + status[i - 1][0]) % mod;
			status[i][3] = (status[i - 1][3] * 2 + status[i - 1][1]) % mod;
			status[i][4] = (status[i - 1][4] * 2 + status[i - 1][2] + status[i - 1][1]) % mod;
			status[i][5] = (status[i - 1][5] * 2 + status[i - 1][4] + status[i - 1][3]) % mod;
		}
/*		for(j=-1;++j<5;){
			cout<<status[i][j]<<" ";
		}
		cout<<status[i][j]<<endl;*/
	}
	cout<<status[n][5]<<endl;
	for(i=-1;++i<n+1;){
		delete[]status[i];
	}
	delete[]status;
	return 0;
}