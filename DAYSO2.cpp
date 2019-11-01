#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("data.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    long long t3[n];
    long long t[n];
    t[0] = t[1] = 0;

    for(int i=2;i<n;i++){
        t3[i] = a[i] + a[i-1] + a[i-2];
    }
    t[2] = t3[2];
    long long lmax = -1e18;

    if(lmax<t[2])lmax=t[2];


    for(int i=3;i<n;i++){
        t[i] = max(t3[i],t3[i] + t[i-3]);
        if(lmax<t[i])lmax=t[i];
    }

    cout<<lmax;

    // for(int i=0;i<n;i++){
    //     cout<<sum[i]<<" ";
    // }
    return 0;
}