#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("data.inp","r",stdin);
    int n;cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int minn = b[0];
    int tong = 0;
    for(int i=0;i<n;i++){
        if(minn>b[i]){
            minn = b[i];
        }
        tong += a[i]*minn;
    }

    cout<<tong;

    return 0;
}