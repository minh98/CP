#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 50000*4;
struct IT{
    int lazy;
    int val;
}its[MAXN];

void down(int id){
    //ham day gia tri lazy xuong cac con cua no
    int t = its[id].lazy;
    its[id*2].lazy += t;
    its[id*2].val += t;

    its[id*2+1].lazy += t;
    its[id*2+1].val += t;
    its[id].lazy = 0;
}
void update(int id,int l,int r,int u,int v,int val){
    //neu u,v nam ngoai doan l,r thi khong lam gi
    if(v<l || u>r){
        return;
    }
    //neu l,r nam trong u,v thi tien hanh update
    if(l>=u && r<= v){
        its[id].val += val;
        its[id].lazy += val;
        return;
    }
    int mid = (l+r)/2;
    //day gia tri lazy xuong cac con cua no
    down(id);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    its[id].val = max(its[id*2].val,its[id*2+1].val);
}
int get(int id,int l,int r,int u,int v){
    if(v<l || u>r){
        return -1e18;
    }
    if(l>=u && r<=v){
        return its[id].val;
    }
    down(id);
    int mid = (l + r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("data.inp","r",stdin);
    int n,m;cin>>n>>m;
    while(m--){
        int type = 0;cin>>type;
        if(type == 0){
            int u,v,val;cin>>u>>v>>val;
            update(1,1,n,u,v,val);
        }else{
            int u,v;cin>>u>>v;
            cout<<get(1,1,n,u,v)<<endl;
        }
    }
    
    return 0;
}