#include <bits/stdc++.h>
using namespace std;

struct matrix{
    int dim = 2;
    int64_t MOD = 1e9 + 7;
    vector<vector<int64_t>> a;
    matrix(){
        a.resize(dim, vector<int64_t>(dim, 0));
    }
    matrix(int _dim){
    	dim = _dim;
    	a.resize(dim, vector<int64_t>(dim, 0));
    }
    matrix operator*(matrix other){
    	assert(dim == other.dim);
        matrix res = matrix(dim);
        for(int i = 0; i < dim; ++i){
        	for(int j = 0; j < dim; ++j){
        		for(int k = 0; k < dim; ++k){
        			res.a[i][j] += a[i][k] * other.a[k][j];
        			res.a[i][j] %= MOD;
        		}
        	}
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}
