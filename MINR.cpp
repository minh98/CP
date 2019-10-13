#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int nmaxIT = 400000;
int a[100001];
ll it[nmaxIT];

void build(int nut,int l,int r){
    if(l==r){
        it[nut] = a[l];
        return;
    }
    int mid = (l+r)/2;
    // build cay con tai,cay con phai
    build(nut*2,l,mid);
    build(nut*2+1,mid+1,r);
    it[nut] = min(it[nut*2],it[nut*2+1]);
    // cout<<endl<<"it["<<nut<<"]="<<it[nut]<<endl;
}
ll get(int nut,int l,int r,int u,int v){
    if(u>r || v<l){// u,v khong nam trong doan l,r
        // cout<<"\nu,v khong nam trong doan l,r\n";
        return 1e18;
    }
    if(u<=l && v>= r){
        // doan l,r nam hoan toan trong doan u,v
        //return nut goc hien tai
        return it[nut];
    }
    int mid = (l+r)/2;

    return min(get(nut*2,l,mid,u,v),get(nut*2+1,mid+1,r,u,v));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(it,0,sizeof(it));
    // freopen("data.inp","r",stdin);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    // for(int i=0;i<n*4;i++){
    //     cout<<it[i]<<" ";
    // }cout<<endl;
    int u,v;
    while(m--){
        cin>>u>>v;
        // cout<<u<<v<<endl;
        cout<<get(1,1,n,u,v)<<endl;
    }
    // cout<<get(1,1,n,4,6)<<endl;
    return 0;
}