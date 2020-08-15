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
            sparse[i][j] = __gcd(sparse[i][j-1], sparse[i + (1 << (j - 1))][j-1]);
        }
    }
}

int query(int l, int r){
    int ans = 0;
    for(int j = k; j >= 0; j--){
        if((1 <<j) <= r - l + 1){
            ans = __gcd(ans, sparse[l][j]);
            l += (1 <<j);
        }
    }

    return ans;    
}

int main() {
                    // 0  1  2  3  4  5  6
    vector<int> arr = {2, 3, 60, 90, 50};
    int n = 7;

//     Index Ranges : {1, 3}, {2, 4}, {0, 2}
// Output: GCDs of given ranges are 3, 10, 1

    preprocess(arr, n);

    cout << query(1, 3) << endl;// 3
    cout << query(2, 4) << endl;// 10
    cout << query(0, 2) << endl;// 1 
    return 0;
}
