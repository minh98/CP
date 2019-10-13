#include<bits/stdc++.h>
#define ll long long
using namespace std;

// string ts(int i){
//     string s;
//     stack<int> a;
//     if(i==0){
//         return "0";
//     }
//     while(i>0){
//         a.push()
//     }
    
// }

char res[11];

string a,b;

bool ise(string a,string s){
    if (a.find(s) != std::string::npos) {
        // std::cout << "found!" <<s<< '\n';
        return true;
    }
    return false;
}

bool run = true;

void check(int l){
    string s;
    for(int i=0;i<l;i++){
        s.push_back(res[i]);
    }
    if(!ise(a,s) && !ise(b,s)){
        // cout<<"kq:";
        cout<<s;
        run = false;
    }
    // ise(a,s);
    // ise(b,s);
    // cout<<a.find(0,s)<<endl;
    // cout<<b.find(0,s)<<endl;
    // if(a.find(s) == -1 && b.find(s) == -1){
    //     cout<<s<<endl;
    // }
    // int x;cin>>x;
}
void sinh(int index,int l){
    if(!run)return;
    if(index == l){
        check(l);
        return;
    }

    for(int i=0;i<2;i++){
        res[index] = i+'0';
        sinh(index+1,l);
    }
}


void reset(){
    for(int i=0;i<11;i++){
        res[i] = '0';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("data.inp","r",stdin);
    
    cin>>a>>b;
    // cout<<a<<endl<<b;
    for(int i=1;i<12;i++){
        if(!run)break;
        sinh(0,i);
        // cout<<endl<<"---------------\n";
        reset();
    }

    return 0;
}