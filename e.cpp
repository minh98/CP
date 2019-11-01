#include<bits/stdc++.h>
using namespace std;

int findTheLargestPrime(std::vector<int> digits)
{
    for(int l=1;l<digits.size();l++){
        std::vector<int> dg;
        for(int i=0;i<l;i++){
            for(int j=0;j<digits.size();j++){
                dg.push_back(digits[j]);
            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("data.inp","r",stdin);
    vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(4);
    cout<<findTheLargestPrime(a);


    return 0;
}