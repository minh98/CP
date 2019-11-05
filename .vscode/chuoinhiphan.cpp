#include<bits/stdc++.h>
using namespace std;
int b[20];

void sinh(int i,int n){
	if(i==n){
		for(int j=0;j<n;j++){
			cout<<b[j];
		}
		cout<<endl;

		return;
	}
	for(int j=0;j<2;j++){
		b[i] = j;
		sinh(i+1,n);
	}
}

int main(){
	int n;cin>>n;
	sinh(0,n);
}