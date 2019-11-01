#include<bits/stdc++.h>
using namespace std;

std::vector<int> td(std::vector<int> b){
    std::vector<int> tdb;
    tdb.push_back((b[0] + b[2]) /2); 
    tdb.push_back((b[1] + b[3]) /2);
    return tdb;
}
double dis(std::vector<int> a, std::vector<int> b){
    return sqrt((b[0]-a[0])*(b[0]-a[0]) + (b[1]-a[1])*(b[1]-a[1]));
}

bool trong(int ax,int ay, std::vector<int> b){
    // std::vector<int> tdb = td(b);

    if(ay >= b[1] && ay <= b[3] && ax >= b[0] && ax <= b[2]){
        return true;
    }
    return false;
}

long long nonOverlappingArea(std::vector<int> a, std::vector<int> b)
{
    if(a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]){
        //trung
        return 0;
    }

    //

    if(trong(a[0],a[1],b) || trong(a[2],a[3],b) || trong(a[0],a[3],b) || trong(a[1],a[2],b) 
        || trong(b[0],b[1],a) || trong(b[2],b[3],a) || trong(b[0],b[3],a) || trong(b[1],b[2],a) 
    ){
        // 1 diem nam trong hinh con lai
        return 1;
    }else if((a[1]<b[1] && a[3] > b[3] && a[0] > b[0] && a[2] < b[2] ) || (b[1]<a[1] && b[3] > a[3] && b[0] > a[0] && b[2] < a[2] )){
        // 2 hinh cat nhau nhung khong co diem nao nam trong hinh kia
        long long dtde = ()
        return 2;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("data.inp","r",stdin);
    std::vector<int> a,b;
    a.push_back(1); a.push_back(1); a.push_back(4); a.push_back(2);
    b.push_back(2); b.push_back(0); b.push_back(3); b.push_back(4);
    cout<<nonOverlappingArea(a,b);
    return 0;
}