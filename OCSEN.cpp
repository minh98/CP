#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("data.inp","r",stdin);
    double a,b,v;cin>>a>>b>>v;
    cout<< (ll)ceil((v-a) / (a-b)) +1;
    return 0;
}