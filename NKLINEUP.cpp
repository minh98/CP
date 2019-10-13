#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int nmax = 50000;
const int qmax = 200000;
ll it[nmax*4];
ll it2[nmax*4];
ll a[nmax+1];

void build(int id,int l,int r){
    if(l==r){
        it[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    it[id] = max(it[id*2],it[id*2+1]);
}
void build2(int id,int l,int r){
    if(l==r){
        it2[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build2(id*2,l,mid);
    build2(id*2+1,mid+1,r);
    it2[id] = min(it2[id*2],it2[id*2+1]);
}
ll getMax(int id,int l,int r,int u,int v){
    if(u> r || v<l){
        //doan khong nam trong l,r
        return -1e18;
    }
    if(l>= u && r <= v){
        // doan l,r nam hoan toan trong u,v
        return it[id];
    }
    int mid = (l+r)/2;
    return max(getMax(id*2,l,mid,u,v),getMax(id*2+1,mid+1,r,u,v));
}
ll getMin(int id,int l,int r,int u,int v){
    if(u> r || v<l){
        //doan khong nam trong l,r
        return 1e18;
    }
    if(l>= u && r <= v){
        // doan l,r nam hoan toan trong u,v
        return it2[id];
    }
    int mid = (l+r)/2;
    return min(getMin(id*2,l,mid,u,v),getMin(id*2+1,mid+1,r,u,v));
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(it,0,sizeof(it));
    memset(it2,0,sizeof(it2));
    // for(int i=0;i<nmax*4;i++)it2[i] = 1e18;
    memset(a,0,sizeof(a));

    // freopen("data.inp","r",stdin);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    build2(1,1,n);
    // for(int i=1;i<=n*4;i++){
    //     cout<<it[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n*4;i++){
    //     cout<<it2[i]<<" ";
    // }cout<<endl;
    int i,j;
    while(q--){
        cin>>i>>j;
        ll maxx = getMax(1,1,n,i,j);
        ll minn = getMin(1,1,n,i,j);
        cout<<maxx-minn<<endl;
    }
    // cout<<getMax(1,1,n,3,6)<<endl;
    // cout<<getMin(1,1,n,3,6);

    return 0;
}