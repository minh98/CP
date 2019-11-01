#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int> t;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        t.push_back(temp);
    }
    sort(t.begin(),t.end(),greater<int>());
    int min=0;
    for(int i = 0;i<t.size();i++){
        int room = 0;
        room += t[i];
        for(int j=t.size()-1;j>i;j--){
            if(room + t[j] > 4){
                break;
            }else{
                room += t[j];
                t.erase(t.begin() + j);
            }
        }
        min++;
    }
    cout<<min;
}