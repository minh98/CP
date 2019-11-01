#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
struct ST{
    int val;
    int lazy;
    ST(int v, int l): val(v), lazy(l){
    }
    ST(): val(0), lazy(0){}
};
ST st[MAXN << 2];
void update(int root, int l, int r, int u, int v, int val){
    if(st[root].lazy > 0){
        st[root].val += st[root].lazy * (r-l+1);
        if(l != r){
            st[root<<1].lazy +=  st[root].lazy;
            st[root<<1^1].lazy += st[root].lazy;
        }
        st[root].lazy = 0;
    }
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        st[root].val += val * (r-l+1);
        if(l != r){
            st[root<<1].lazy += val;
            st[root<<1^1].lazy += val;
        }
        return;
    }
    int mid = (l+r) >> 1;
    update(root << 1, l, mid, u, v, val);
    update(root << 1^1, mid + 1, r, u, v, val);
    st[root].val = st[root<<1].val + st[root << 1^1].val;
}
int get(int root, int l, int r, int u, int v){
    if(st[root].lazy > 0){
        st[root].val += st[root].lazy * (r-l+1);
        if(l != r){
            st[root<<1].lazy +=  st[root].lazy;
            st[root<<1^1].lazy += st[root].lazy;
        }
        st[root].lazy = 0;
    }
    if(l > v || r < u) return 0;
    if(l >= u && r <= v){
        return st[root].val;
    }
    int mid = (l+r) >> 1;
    return get(root<<1,l,mid,u,v) + get(root<<1^1,mid + 1, r, u , v);
}
std::vector<int> queriesOnRectange(int n, int m, std::vector<std::vector<int>> q1, std::vector<std::vector<int>> q2)
{
    int r1,c1,r2,c2;
    vector<int> res(q2.size());
    for(int i = 0 ; i < q1.size(); ++i){
        r1 = q1[i][0];
        c1 = q1[i][1];
        r2 = q1[i][2];
        c2 = q1[i][3];
        update(1,1,n*m,r1*m + c1 + 1, r2 * m + c2 + 1, 1);
    }
    for(int i = 0; i < q2.size(); ++i){
        //cout << "get: " << i << " :\n";
        r1 = q2[i][0];
        c1 = q2[i][1];
        r2 = q2[i][2];
        c2 = q2[i][3];
        res[i] = 0;
        for(int j = r1; j <= r2; ++j){
            res[i] += get(1,1,n*m,j * m + c1 + 1, j * m + c2 + 1);
            //cout << " get from " << j * m + c1 + 1 << " to " << j * m + c2  + 1<< " : " << get(1,1,n*m,j * m + c1 + 1, j * m + c2 + 1) << endl;
        }
    }
    return res;
}
int main(){
    vector<vector<int>> queries1 = {{0, 1, 1, 2}, {1, 1, 2, 2}}, queries2 = {{0, 0, 1, 1}, {1, 1, 2, 3}};
    vector<int> r = queriesOnRectange(4,4,queries1,queries2);
    for(int i = 0; i < r.size(); ++i) cout << r[i] << ' ';
    return 0;
}
