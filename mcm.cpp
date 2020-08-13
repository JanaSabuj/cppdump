#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int>& arr, int i, int j){
    if(i >= j)
        return 0;
    
    int val = INT_MAX;
    for(int k = i; k < j; k++){
        val = min(val, mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    }

    return val;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    int n = arr.size();
    cout << mcm(arr, 1, n - 1);
    return 0;
}
