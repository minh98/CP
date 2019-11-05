#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 400000;
struct it{
    ll lazy;
    ll val;
}its[maxn];

void down(int id){
    ll t = its[id].lazy;
    if(t==0)return;
    its[id*2].lazy = t;
    its[id*2].val = t;

    its[id*2+1].lazy = t;
    its[id*2+1].val = t;
    its[id].lazy = 0;
}

void update(int id,int l,int r,int u,int v,int val){
    if(v<l || u>r){
        return;
    }
    if(l>=u && r<=v){
        its[id].lazy = val;
        its[id].val = val;
        return;
    }
    down(id);
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    its[id].val = max(its[id*2].val,its[id*2+1].val);
}
ll get(int id,int l,int r,int u,int v){
    if(v<l || u> r){
        return -1e18;
    }
    if(l>=u && r<= v){
        return its[id].val;
    }
    down(id);
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void init(int id,int l,int r,int i,int val){
    if(i<l || i> r){
        return;
    }
    if(l == r){
        its[id].val = val;
        return;
    }
    int mid = (l+r)/2;
    init(id*2,l,mid,i,val);
    init(id*2+1,mid+1,r,i,val);
    its[id].val = max(its[id*2].val,its[id*2+1].val);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("data.inp","r",stdin);
    int n,m;cin>>n>>m;
    int h;
    for(int i=1;i<=n;i++){
        cin>>h;
        init(1,1,n,i,h);
    }

    int p, l;
    for(int i=0;i<m;i++){
        cin>>p>>l;  // tuong ung voi doan u,v = p,l-1
        if(l-1 >n) l = n+1; // neu truong hop l vuot qua n thi chi lay den l = n thoi 
        // cout<<p<<" "<<p+l-1<<endl;
        ll len = get(1,1,n,p,p+ l-1);
        cout<<len+1<<endl;
        
        update(1,1,n,p,p+ l-1,len+1);
        // cout<<get(1,1,n,p,p + l - 1)<<endl;
        // cout<<"------------"<<endl;
    }
    return 0;
}