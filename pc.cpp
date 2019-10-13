#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("data.inp","r",stdin);
    int n;cin>>n;
    cin.ignore();
    string s[n];
    map<string,int> m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        m[s[i]] = -1;
    }
    for(int i=0;i<n;i++){
        m[s[i]] ++;
        // cout<<s[i]<<endl;
        if(m[s[i]] <= 0){
            cout<<"OK"<<endl;
        }else{
            cout<<s[i]<<m[s[i]]<<endl;
        }
    }
    return 0;
}