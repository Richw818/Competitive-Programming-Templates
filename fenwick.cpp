#include <bits/stdc++.h>
using namespace std;

struct bit{
    const int MAXN = 200005;
    vector<int64_t> sum;
    bit(){
        sum.resize(MAXN);
    }
    void update(int i, int64_t v){
    	while(i < MAXN){
    		sum[i] += v;
    		i += i & (-i);
    	}
    }
    int64_t query(int i){
    	int64_t res = 0;
    	while(i){
    		res += sum[i];
    		i -= i & (-i);
    	}
    	return res;
    }
    int64_t query(int l, int r){
    	return query(r) - query(l-1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}
