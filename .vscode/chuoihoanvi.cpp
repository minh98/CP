#include<bits/stdc++.h>
using namespace std;
int n;
int t[100];
int d[10];
int tong = 0;
void sinh(int index){
	if(index==n){
		for(int i=0;i<n;i++){
			cout<<t[i];
		}
		cout<<endl;
		tong++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(d[i] == 0){
			d[i] = 1;
			t[index] = i;
			sinh(index+1);
			d[i] = 0;
		}
	}
}
int main(){
	cin>>n;
	int m = n;
	memset(d,0,10);
	int gt = 1;
	for(int i=2;i<=m;i++){
		gt*= i;
	}
	cout<<gt<<endl;
	sinh(0);
//	cout<<tong;
}