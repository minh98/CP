/*
 * Created by: Son Dinh
 */
#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
 
int nprime[1000005];
 
int n;
ll res = 0,fen[300005];
int a[100005],f;
void sieve()
{
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i <= 1000000; ++i)
        if(!nprime[i])
        {
            for(int j = i * i; j <= 1000000; j += i)
                nprime[j] = 1;
        }
}
void upd(int val)
{
    val += n + 1;
    while(val <= n + n + 1)
    {
        fen[val]++;
        val += val & -val;
    }
}
ll get(int val)
{
    val += n + 1;
    int res = 0;
    while(val > 0)
    {
        res += fen[val];
        val -= val & -val;
    }
    return res;
}
int main()
{
    cin >> n;for(int i = 1; i <= n; ++i)cin >> a[i];
    sieve();
////
    upd(0);
    for(int ii=0;ii<n*4;ii++){
           cout<<fen[ii]<< " ";
       }cout<<endl;
       
    for(int i = 1; i <= n; ++i)
    {
        if(nprime[a[i]]) --f;
        else ++f;
        res += get(f);
        upd(f);
       // cout << "i: " << i << ' ' << res << endl;
       for(int ii=0;ii<n*4;ii++){
           cout<<fen[ii]<< " ";
       }cout<<endl;
    }
    cout << res;
    return 0;
}