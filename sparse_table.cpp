#include <bits/stdc++.h>
using namespace std;

struct sparse{
	int LOG = 0;
	vector<vector<int64_t>> up;
	vector<int> lg;
	sparse() {}
	int64_t comb(int64_t a, int64_t b){
		return min(a, b);
	}
	void build(vector<int64_t> &a){
		int n = a.size();
		lg.resize(n+1);
		int curr = 1;
		while(curr <= n){
			++LOG;
			curr <<= 1;
		}
		up.resize(LOG, vector<int64_t>(n));
		for(int i = 0; i < n; ++i)
			up[0][i] = a[i];
		for(int i = 1; i < LOG; ++i){
			for(int j = 0; j + (1 << i) <= n; ++j){
				up[i][j] = comb(up[i-1][j], up[i-1][j+(1<<(i-1))]);
			}
		}
		for(int i = 2; i <= n; ++i)
			lg[i] = lg[i/2] + 1;
	}
	int64_t query(int l, int r){
		int diff = r - l + 1;
		int mx_log = lg[diff];
		return comb(up[mx_log][l], up[mx_log][r-(1 << mx_log)+1]);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
}