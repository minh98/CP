#include<bits/stdc++.h>
using namespace std;
bool danhdau[101][101];
char a[101][101];
queue< pair<int,int> > st;


void duyet(int i,int j){
    st.push({i,j});
    while(!st.empty()){
        pair<int,int> p = st.front(); st.pop();

        danhdau[p.first][p.second] = 1;

        if(danhdau[p.first-1][p.second] == false && a[p.first-1][p.second] == '#'){
            st.push({p.first-1,p.second});
        }
        if(danhdau[p.first][p.second-1] == false && a[p.first][p.second-1] == '#'){
            st.push({p.first,p.second-1});
        }
        if(danhdau[p.first][p.second+1] == false && a[p.first][p.second+1] == '#'){
            st.push({p.first,p.second+1});
        }
        if(danhdau[p.first+1][p.second] == false && a[p.first+1][p.second] == '#'){
            st.push({p.first+1,p.second});
        }
    }
    
}

int main(){
    memset(danhdau,false,sizeof(danhdau));
    int n,m;cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int lan = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == '#' && danhdau[i][j] == false){
                duyet(i,j);
                lan++;
            }
        }
    }

    cout<<lan;
}