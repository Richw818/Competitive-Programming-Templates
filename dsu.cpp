#include <bits/stdc++.h>
using namespace std;

struct dsu{
	const int MAXN = 200005;
	vector<int> p, s;
	dsu(){
		p.resize(MAXN); s.resize(MAXN);
		iota(p.begin(), p.end(), 0);
		fill(s.begin(), s.end(), 1);
	}
	int find(int a){
		if(p[a] == a)
			return a;
		p[a] = find(p[a]);
		return p[a];
	}
	bool uni(int a, int b){
		int ap = find(a), bp = find(b);
		if(ap == bp)
			return 0;
		if(s[ap] > s[bp])
			swap(ap, bp);
		s[bp] += s[ap];
		p[ap] = bp;
		return 1;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}
