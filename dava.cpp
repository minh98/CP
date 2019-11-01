//bai dao vang ntu
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    int a[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int sum[n-k+1][n];
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n-k+1;i++){
        for(int j=0;j<n;j++){
            for(int l = i;l< i+k;l++){
                sum[i][j] += a[l][j];
            }

            if(j>0)
            sum[i][j] += sum[i][j-1];
        }
    }

    int max = 0;

    for(int i=0;i<n-k+1;i++){
        for(int j=0;j<n-k+1;j++){
            if(j>0){
                int block = sum[i][j+k - 1] - sum[i][j-1];
                if(max<block)max=block;
            }else{
                int block = sum[i][j+k-1];
                if(max<block)max=block;
            }
        }
    }

    // for(int i=0;i<n-k+1;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<sum[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<max;
    return 0;
}