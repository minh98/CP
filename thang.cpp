#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n;
	cin>>n;
	long long tong=0, min=0, vtmin=0, a[n],b[n];
	long long tam1=0;

	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	for(int i=0; i<n; i++){
		cin>>b[i];
	}

	min = b[0];
	for(int i=1;i<n;i++){
		if(b[i]< min)
		{
			min=b[i];
			vtmin=i;
		}
	}

	tam1 = b[0];
	int tam=0;

	for(int i=1; i<=vtmin; i++){
		if(b[i-1]<=b[i]){
			tam1 = b[i];
			tam = a[i] * tam1;
			tong += tam;
		}else{
			tam = a[i] * tam1;
			tong += tam;
		}
	}
	for(int i=vtmin; i<n; i++){
		tam = b[vtmin] * a[i];
		tong += tam;
	}
	cout<<tong;
	return 0;
}