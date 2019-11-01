#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("data.inp","r",stdin);
    int N,M;
    cin>>N>>M;
    long long a[M+1];
    long long t[M+1][N+1];
    memset(t,0,sizeof(t));
    for(int i=1;i<=M;i++){
        cin>>a[i];
    }


    for(int i=1;i<=1;i++){
        for(int j=1;j<=N;j++){
            if(a[i] > j){
                t[i][j] = t[i-1][j];
            }else{
                //<=
                if(j%a[i] == 0){
                    t[i][j] = 1LL + t[i-1][j];
                }else{
                    t[i][j] = t[i][j-a[i]] + t[i-1][j];
                }
            }
        }
    }


    for(int i=2;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(a[i] > j){
                t[i][j] = t[i-1][j];
            }else{
                //<=
                if(a[i] == j){
                    t[i][j] = 1 + t[i][j-a[i]] + t[i-1][j];
                }else{
                    t[i][j] = t[i][j-a[i]] + t[i-1][j];

                }
                
            }
        }
    }
    // for(int i=0;i<=M;i++){
    //     for(int j=0;j<=N;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<t[M][N];
}