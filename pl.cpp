#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,int> bp;

int GT(int num)
{
	if (num == 0) return 1;
	return num*GT(num-1);
}

int C(int a, int b)
{
	if(a > b) return 0;
	return GT(b)/GT(a)/GT(b-a);
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x);
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("data.inp","r",stdin);
    int n;cin>>n;
    int a[n];
    map<ll,int> maxn;


    for(int i=0;i<n;i++){
        cin>>a[i];
        bp[a[i]] = 0;
        maxn[a[i]] = 0;
    }

    sort(a,a+n);

    for(int i=0;i<n;i++){
        bp[a[i]] ++;
    }
    for(int i=0;i<n;i++){
        cout<<bp[a[i]] <<" ";
    }cout<<endl;

    ll tongvuong = 0;

    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int x=a[i];
            int y=a[j];
            ll tong = x*x+y*y;
            if(ceil(sqrt(tong)) == floor(sqrt(tong))){
                tongvuong += bp[sqrt(tong)];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            maxn[a[i]] ++;
        }
    }
        int tu = 0;

    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int x=a[i];
            int y=a[j];
            ll tong = x*x+y*y;
            // if(ceil(sqrt(tong)) == floor(sqrt(tong))){
            //     cout<<sqrt(tong)<<endl;
            //     tu += max(maxn[sqrt(tong)],maxn[a[j]]);
            // }

            for(int k = j+1;k<n;k++){
                if(a[k]*a[k] > tong && x+y<a[k]){
                    tu+=maxn[a[k]];
                }
            }

        }
    }
    

	int deu = 0;

	int dem = 1;
	for (int i = 0; i < n; i++) 
	{
		if(a[i] == a[i+1])
		{
			dem++;
		}
		else
		{
			deu += C(3,dem);
			dem  = 1;
		}
	}



    cout<<deu<<" "<<tongvuong<<" "<<tu<<endl;

    for(int i=0;i<n;i++){
        cout<<maxn[a[i]] <<" ";
    }cout<<endl;

    return 0;
}