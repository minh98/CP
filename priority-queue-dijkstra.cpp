#include<bits/stdc++.h>
using namespace std;
int n,a,b;
vector<pair<int,int>> vt[10000];
int d[10000];

void dijkstra(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,a});
    int u,du,v,uv;

    while(!pq.empty()){
        pair<int,int> top = pq.top(); pq.pop();
        u = top.second;
        du = top.first;
        if(du!=d[u])continue;
        for(int i=0;v = vt[u][i].second; i++){
            uv = vt[u][i].first;
            if(d[v] > du+uv){
                d[v] = du+uv;
                pq.push({d[v],v});
            }
        }
    }
}

int main(){
    freopen("data","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<10000;i++){
        d[i] = 999999;
    }

    cin>>n>>a>>b;
    int c;

    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>c;
            if(i!=j && c != 0){
                vt[i].push_back({c,j});
                vt[j].push_back({c,i});
            }
        }
    }
    for(int i=1;i<=n;i++){
        vt[i].push_back({0,0});
    }

    for(int i= 1;i<=n;i++){
        cout<<"vt["<<i<<"]=";
        for(int j=0;j<vt[i].size();j++){
            cout<<"("<<vt[i][j].first<<","<<vt[i][j].second<<"),";
        }cout<<endl;
    }

    d[a] = 0; // chay tu a den b nen d[a] -> d[a] se bang 0 

    dijkstra();

    for(int i=0;i<=n ;i++){
        cout<<d[i]<<" ";
    }cout<<endl;
    cout<<d[b];
    
    return 0;
}
