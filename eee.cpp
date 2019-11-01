#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

///

int t[20];
int d2[20];
int tong = 0;
int maxx = 0;

bool td = false;


bool isPrime(int n) {
    for (int i = 2; i < n; i++)
        if (n % i == 0) {
            // n chia hết cho số khác 1 và chính nó.
            return false;
        }
    return n > 1;
}

int toN(int n){
    int tong = 0;
    for(int i=0;i<n;i++){
        tong += pow(10,i) * t[n-1-i];
    }
    return tong;
}
void sinh2(int index,int n,std::vector<int> digits){
    if(td)return;
	if(index==n){

        int tn = toN(n);
        if(isPrime(tn)){
            td = true;
            if(maxx<tn)maxx=tn;
        }

		return;
	}
	for(int i=1;i<=digits.size();i++){
		if(d2[i] == 0){
			d2[i] = 1;
			t[index] = digits[i-1];
			sinh2(index+1,n,digits);
			d2[i] = 0;
		}
	}
}

int findTheLargestPrime(std::vector<int> digits)
{
    sort(digits.begin(),digits.end());
    reverse(digits.begin(),digits.end());
    for(int l=digits.size();l>0;l--){
        for(int i=0;i<20;i++){
            d2[i] = 0;
            t[i] = 0;
        }

        sinh2(0,l,digits);
    }
    if(maxx>0)
    return maxx;
    else
        return -1;
}



int main(){
    vector<int> a;
    //7, 2 , 2, 1, 6, 7, 8, 4
    // a.push_back(2);
    a.push_back(8);
    a.push_back(8);
    a.push_back(3);
    a.push_back(7);
    a.push_back(8);
    a.push_back(3);
    // a.push_back(4);
    cout<<findTheLargestPrime(a);
    // sinh2(0,a.size());
}

//1 2 3
t = 0 0 0
0 0 0
1 0   => 12 13 => 
20 21 23 31 32
300


