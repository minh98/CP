#include<bits/stdc++.h>
using namespace std;
int N=101,M=101;
int c[101][101];
int mmax[101];

int findMax(int m){
    int ma = 0;
    for (int i = 0; i < N; i++)
    {
        if(ma< c[i][m]){
            ma = c[i][m];
        }
    }
    return ma;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>c[i][j];
        }
    }

    for(int i=0;i<M;i++){
        mmax[i] = findMax(i);
        cout<<mmax[i]<<" ";
    }

    return 0;
}
