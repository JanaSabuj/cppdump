#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int N = 1e5;
const int k = 16;

int sparse[N][k + 1];

void preprocess(vi& arr, int n){

    for(int i = 0; i < n; i++)
        sparse[i][0] = arr[i];
    
    // 2^j = 2^j-1 + 2^j-1
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++){
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j - 1))][j-1]);
        }
    }
}

int query(int l, int r){
    int ans = INT_MAX;
    for(int j = k; j >= 0; j--){
        if((1 <<j) <= r - l + 1){
            ans = min(ans, sparse[l][j]);
            l += (1 <<j);
        }
    }

    return ans;    
}


int rmq(int L, int R) {
	int j = log2(R - L + 1);
	return min(sparse[L][j], sparse[R - (1 << j) + 1][j]);
}


int main() {
                    // 0  1  2  3  4  5  6
    vector<int> arr = {2, 1, 5, 7, 8, 4, 5};
    int n = 7;

    preprocess(arr, n);

    cout << query(0, 2) << endl;
    cout << query(3, 5) << endl;
    cout << query(1, 6) << endl; 
    return 0;
}
