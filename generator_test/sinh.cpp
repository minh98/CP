#include <iostream>
#include <fstream>
using namespace std;
#define ll long long


// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    return l + rand() % (h - l + 1);
}

void generate(int itest,ofstream &inp)
{
    int maxx = 100000 / itest;

    int n = Rand(1,maxx);
    int m = Rand(1,maxx);
    inp<<n<<" "<<m<<"\n";
    for(int i=0;i<n;i++){
        inp<<Rand(1,1e9)<<" ";
    }inp<<"\n";
    for(int i=0;i<m;i++){
        int p = Rand(1,n-1);
        int l = Rand(1,1000);
        inp<<p<<" "<<l<<"\n";
    }

}
struct it{
    ll lazy;
    ll val;
};
class Solve{
    public:
        int maxn = 400000;
        it its[400000];

        void down(int id){
            ll t = its[id].lazy;
            if(t==0)return;
            its[id*2].lazy = t;
            its[id*2].val = t;

            its[id*2+1].lazy = t;
            its[id*2+1].val = t;
            its[id].lazy = 0;
        }

        void update(int id,int l,int r,int u,int v,int val){
            if(v<l || u>r){
                return;
            }
            if(l>=u && r<=v){
                its[id].lazy = val;
                its[id].val = val;
                return;
            }
            down(id);
            int mid = (l+r)/2;
            update(id*2,l,mid,u,v,val);
            update(id*2+1,mid+1,r,u,v,val);
            its[id].val = max(its[id*2].val,its[id*2+1].val);
        }
        ll get(int id,int l,int r,int u,int v){
            if(v<l || u> r){
                return -1e18;
            }
            if(l>=u && r<= v){
                return its[id].val;
            }
            down(id);
            int mid = (l+r)/2;
            return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
        }
        void init(int id,int l,int r,int i,int val){
            if(i<l || i> r){
                return;
            }
            if(l == r){
                its[id].val = val;
                return;
            }
            int mid = (l+r)/2;
            init(id*2,l,mid,i,val);
            init(id*2+1,mid+1,r,i,val);
            its[id].val = max(its[id*2].val,its[id*2+1].val);
        }
        int solve(ifstream &cin, ofstream &cout)
        {
            int n,m;cin>>n>>m;
            int h;
            for(int i=1;i<=n;i++){
                cin>>h;
                init(1,1,n,i,h);
            }

            int p, l;
            for(int i=0;i<m;i++){
                cin>>p>>l;  // tuong ung voi doan u,v = p,l-1
                if(l-1 >n) l = n+1; // neu truong hop l vuot qua n thi chi lay den l = n thoi 
                // cout<<p<<" "<<p+l-1<<endl;
                ll len = get(1,1,n,p,p+ l-1);
                cout<<len+1<<endl;
                
                update(1,1,n,p,p+ l-1,len+1);
                // cout<<get(1,1,n,p,p + l - 1)<<endl;
                // cout<<"------------"<<endl;
            }
            return 0;
        }
};

/// solve zone




/// end solve zone


void answer(ifstream &cin, ofstream &cout)
{
    Solve solve;
    solve.solve(cin,cout);
}
bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

int main()
{
    srand(time(NULL));
    // Tên chương trình
    const string NAME = "xephinh";
    // Số test kiểm tra

    int iTest = 1;
    while(is_file_exist((NAME + to_string(iTest) + ".inp").c_str())){
        iTest ++;
    }

        ofstream inp((NAME + to_string(iTest) + ".inp").c_str());
        // Code phần sinh test ở đây
        generate(iTest,inp);

        inp.close();

        ////////////////////////////////////////////////////////
        ofstream cout((NAME + to_string(iTest) + ".out").c_str());
        ifstream cin((NAME + to_string(iTest) + ".inp").c_str());
        // Code phần sinh đáp án ở đây
        answer(cin,cout);
        cin.close();
        cout.close();

    return 0;
}