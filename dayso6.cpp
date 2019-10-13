#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int v(int i,int j,int k){
	return a[i] + a[j]*2 + a[k] * 3;
}
struct ff{
	int i=0,j=1,k=2;
	void update(int index){
		if( a[index] > a[k]){
			int kk = k; //luu k lai de so sanh j voi k
			k = index;
			
			if(a[j] < a[kk]){
				int jj = j; // luu j lai de so sanh i voi j
				j = kk;
				if(a[i] < a[jj]){
					i = jj;
				}
			}
		}
	}
	void show(){
		cout<<i<<" "<<j<<" "<<k<<"="<< v(i,j,k) <<endl;
	}
	void rt(){
		cout<<v(i,j,k);
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ff f;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n == 3){
        cout<< a[0] + a[1]*2 + a[2]*3;
        return 0;
    }
    for(int i = 3;i<n;i++){
    	f.update(i);
	}
	f.show();
    
    return 0;
}
/*
10
1 4 2 6 4 9 6 8 4 6
55*/
