#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("data.inp","r",stdin);
    ll r,g,b,d;cin>>r>>g>>b>>d;
    stack<int> s;

    while(d!=1){
        ll m = d%3;
        if(m==0){
            s.push(1);
            d/=3;
        }else if(m==1){
            s.push(2);
            d--;
            d/=3;
        }else if(m==2){
            s.push(0);
            d+=2;
            d/=3;
        }
    }

    while(!s.empty()){
        int t = s.top();
        // cout<<t<<" ";
        s.pop();
        if(t==0){
            ll rg = r+g;
            ll gg = b;
            ll bb = g;
            r=rg;
            g=gg;
            b=bb;
        }else if(t==1){
            ll rr = b;
            ll gg = g+b;
            ll bb = r;
            r=rr;
            g=gg;
            b=bb;
        }else{
            ll rr = g;
            ll gg = r;
            ll bb = b+r;
            r=rr;
            g=gg;
            b=bb;
        }
    }

    cout<<r<<" "<<g<<" "<<b;
    
    return 0;
}