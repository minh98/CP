#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("data.inp","r",stdin);
    int n,k;cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ak = a[k-1];
    a[k-1] = 0;
    while(ak>0){
        a[(k)%n] ++;
        ak --;
        k++;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    return 0;
}
