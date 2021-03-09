#include<iostream>
using namespace std;
 
int a[10000]={0};
 
int main(){
    freopen("./11AdjacentNumPairs.data","r",stdin);
	int n,sum=0,x;
	cin>>n;
	while(n--){
		cin>>x;
		a[x]=1;
		if(x+1<10000 && a[x+1]){
			sum++;
		}
		if(x-1>=0 && a[x-1]){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}