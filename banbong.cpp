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
vector<int> a;

void duyet() {
	queue<ob> q;
	ob o;
	o.diemn = a[0];
	o.ndi = false;
	o.a = a;
	o.a.erase(o.a.begin());

	q.push(o);
	ob o2;
	o2.diemn = a[a.size() - 1];
	o2.ndi = false;
	o2.a = a;
	o2.a.erase(o2.a.begin() + o2.a.size()-1);
	q.push(o2);


	while (!q.empty()) {
		ob o = q.front();
		q.pop();
		maxn = max(o.diemn, maxn);
		//cout << maxn << " ";
		if (o.ndi == false) {
			//luot may di
			if (!o.a.empty()) {
				if (o.a[0] > o.a[o.a.size() - 1]) {
					o.diemm += o.a[0];
					o.ndi = true;
					o.a.erase(o.a.begin());
					q.push(o);
				}
				else {
					o.diemm += o.a[o.a.size() - 1];
					o.ndi = true;
					o.a.erase(o.a.begin() + o.a.size() - 1);
					q.push(o);
				}
				
			}

		}
		else {
			//luot nguoi di
			if (!o.a.empty()) {
				ob o1 = o;
				ob o2 = o;

				o1.diemn += o1.a[0];
				o1.ndi = false;
				o1.a.erase(o1.a.begin());
				q.push(o1);
				//
				o2.diemn = o2.a[o2.a.size() - 1];
				o2.ndi = false;
				o2.a.erase(o2.a.begin() + o2.a.size() - 1);
				q.push(o2);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//    freopen("data.inp","r",stdin);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.push_back(x);
	}
	duyet();
	cout << maxn;
	return 0;
}
