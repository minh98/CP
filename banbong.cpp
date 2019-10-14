#include<iostream>
#include<vector>
#include<queue>
#define ll long long
using namespace std;

struct ob {
	int diemm = 0;
	int diemn = 0;
	vector<int> a;
	bool ndi = true;
};
int maxn = 0;
int maxm = 0;
vector<int> a;

void duyet(ob o) {
	if (o.a.empty()) {
		maxn = max(o.diemn, maxn);
		maxm = max(o.diemm, maxm);
		/*cout << o.diemm << " " << o.diemn <<" "<<o.diemm+o.diemn<< endl;
		getchar();*/
		return;
	}
	maxn = max(o.diemn, maxn);
	maxm = max(o.diemm, maxm);

	if (o.ndi == false) {
		//luot may di
		/*cout << "\nluot may\n";
		for (int i = 0; i < o.a.size(); i++) {
			cout << o.a[i] << " ";
		}cout << endl;*/

		if (o.a[0] >= o.a[o.a.size() - 1]) {
			/*cout << "\nmay chon:" << o.a[0] << endl;*/
			o.diemm += o.a[0];
			o.ndi = true;
			o.a.erase(o.a.begin());
			duyet(o);
		}
		else {
			/*cout << "\nmay chon:" << o.a[o.a.size() - 1] << endl;*/
			o.diemm += o.a[o.a.size() - 1];
			o.ndi = true;
			o.a.pop_back();
			duyet(o);
		}
	}
	else {
		//luot nguoi di
			ob o1 = o;
			ob o2 = o;
			/*cout << "\nluot nguoi\n";
			for (int i = 0; i < o1.a.size(); i++) {
				cout << o1.a[i] << " ";
			}cout << endl;
			cout << "\nnguoi chon:" << o1.a[0] << endl;*/
			o1.diemn += o1.a[0];
			o1.ndi = false;
			o1.a.erase(o1.a.begin());
			duyet(o1);

			//
			//cout << "\nluot nguoi\n";
			/*for (int i = 0; i < o2.a.size(); i++) {
				cout << o2.a[i] << " ";
			}cout << endl;
			cout << "\nnguoi chon:" << o2.a[o2.a.size() - 1] << endl;*/
			o2.diemn += o2.a[o2.a.size() - 1];
			o2.ndi = false;
			o2.a.pop_back();
			duyet(o2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//    freopen("data.inp","r",stdin);
	int n; cin >> n;
	int tong = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		tong += x;
		a.push_back(x);
	}
	/*cout << "tong:" << tong << endl;*/
	ob o;
	o.a = a;
	duyet(o);
	cout << maxn;
	return 0;
}
