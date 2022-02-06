#include <bits/stdc++.h>
using namespace std;

struct node{
	int l = 0, r = 0;
	int64_t val = 0;
	node() {}
	node(int _l, int _r){
		l = _l, r = _r;
	}
};

struct segtree{
	const int MAXN = (1 << 18);
	vector<node> tree;
	segtree(){
		tree.resize(2 * MAXN + 5);
	}
	int64_t comb(int64_t a, int64_t b){
		return a + b;
	}
	void build(){
		for(int i = 0; i < MAXN; ++i)
			tree[i+MAXN] = node(i, i+1);
		for(int i = MAXN - 1; i > 0; --i){
			tree[i] = node(tree[2*i].l, tree[2*i+1].r);
		}
	}
	void update(int i, int64_t v){
		i += MAXN;
		tree[i].val = v;
		while(i > 1){
			i >>= 1;
			tree[i].val = comb(tree[2*i].val, tree[2*i+1].val);
		}
	}
	int64_t query(int v, int l, int r){
		if(l <= tree[v].l && tree[v].r <= r)
			return tree[v].val;
		if(tree[v].l >= r || tree[v].r <= l)
			return 0;
		return comb(query(2*v, l, r), query(2*v+1, l, r));
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}