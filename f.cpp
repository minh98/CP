#include  <bits/stdc++.h>
 
using namespace std;

int len(int h,int c,int n){
        return h*n + c+1;
}
 

std::vector<int> queriesOnRectange(int n, int m, std::vector<std::vector<int>> queries1, std::vector<std::vector<int>> queries2)
{
        int a[n*m + 1];
        memset(a,0,sizeof(a));
        for (int i=0;i<queries1.size();i++)
        {
            a[len(queries1[i][0],queries1[i][1],m) - 1] ++;
            a[len(queries1[i][2],queries1[i][3],m) - 1 + 1] --;
        }
        for(int i=1;i<=n*m;i++){
            a[i] = a[i-1] + a[i];
        }
        int b[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                b[i][j] = a[len(i,j,m)-1];
            }
        }




        //duyet queries2
        int tong;
        vector<int> results;
        for (int q2 = 0; q2 < queries2.size(); q2++) {
            tong = 0;
            for(int i=queries2[q2][0];i<=queries2[q2][2];i++){
                for(int j=queries2[q2][1];j<=queries2[q2][3];j++){
                    tong += b[i][j];
                }
            }
            results.push_back(tong);
        }

        return results;
}

int main()
{
    cout<<"haha";
    
    vector<int> n = queriesOnRectange(4,4,vector<vector<int>>{{0, 1, 1, 2},{1, 1, 2, 2}},vector<vector<int>>{{0, 0, 1, 1}, {1, 1, 2, 3}});
    for(int i = 0;i<n.size();i++){
        cout<<n[i]<<" ";
    }
    return 0;
}