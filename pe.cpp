#include<bits/stdc++.h>
#include<iostream>
// #define PI  3.141592653589793
#define ll long long
using namespace std;

double PI = acos(-1.0);

int b1(int a, int b)
{
	return -b/a;
}

int b2(int a, int b, int c)
{
	int del = b * b - 4 * a * c;
	
	if(del == 0) return -b / (2 * a);
	
	float x1 = (-b + sqrt(del)) / (2 * a);
	float x2 = (-b - sqrt(del)) / (2 * a);
	
	if((int) x1 != x1) return x2;
	if((int) x2 != x2) return x1; 
	
	return x1 < x2 ? (int) x1 : (int) x2;
}

float pt3(float a,float b,float c,float d)
{
    float x1,x2,x3;
    float denta = b*b - 3*a*c;
    cout<<endl<<denta<<endl;
    float k = (9*a*b*c - 2*b*b*b - 27*a*a*d)/(2*sqrt(pow(abs(denta),3)));
    cout<<endl<<k<<endl;

    if(denta > 0){
        if(abs(k)<=1){
            //3 nghiem 
            x1 = ((2*sqrt(denta)*cos(acos(k)/3)) - b)/(a*3);
            x2 = ((2*sqrt(denta)*cos(acos(k)/3 - 2*PI/3)) - b)/(a*3);
            x3 = ((2*sqrt(denta)*cos(acos(k)/3 + 2*PI/3)) - b)/(a*3);
            if(ceil(x1) != floor(x1)) x1 = 1e18;
            if(ceil(x2) != floor(x2)) x2 = 1e18;
            if(ceil(x3) != floor(x3)) x3 = 1e18;
            return min(min(x1,x2),x3);
        }else{
            return ((sqrt(denta)*abs(k))/(3*a*k)) * (pow((abs(k) + sqrt(k*k -1)),1.0/3) + pow((abs(k) - sqrt(k*k -1)),1.0/3)) - b/(3*a);
        }
    }else if(denta == 0){
        if(pow(b,3) - 27*pow(a,2)*d == 0){
            return -b/(3*a);
        }else{
            return (-b + pow((pow(b,3)-27*pow(a,2)*d),1.0/3))/(3*a);
        }
    }else if(denta<0){
        cout<<"denta<0";
        cout<<endl<<(sqrt(abs(denta))/(3*a))<<endl;
        cout<<endl<<(pow(k+sqrt(k*k+1),1.0/3) + pow(k-sqrt(k*k+1),1.0/3))<<endl;
        cout<<endl<<b/(3*a)<<endl;
        return (sqrt(abs(denta))/(3*a)) * (pow(k+sqrt(k*k+1),1.0/3) + pow(k-sqrt(k*k+1),1.0/3)) - b/(3*a);
    }
}  //End of cub

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("data.inp","r",stdin);
    // cout<<endl<<pow(0,1.0/3);

    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        if(n==3){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<pt3(a,b,c,d);
            cout<<endl;
        }
        if(n==2){
            int a,b,c;
            cin>>a>>b>>c;
            cout<<b2(a,b,c);cout<<endl;
        }
        if(n==1){
            int a,b;
            cin>>a>>b;
            cout<<b1(a,b);cout<<endl;
        }
        // int a[n+1];
        // for(int j = 0;j<=n;j++){
        //     cin>>a[j];
        // }
    }
    // cout<<pt3(1,-3,3,-1);
    
    return 0;
}