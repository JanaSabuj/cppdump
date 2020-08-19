#include <bits/stdc++.h>
using namespace std;

int dp[32][500];

void pre(vector<int>& arr){
    int n = arr.size();  
    // total no of set bits from 0 to n for bit i

    for(int i = 0; i < n; i++){
        // for each n numbers
        for(int bit = 0; bit < 32; bit++){
            if(arr[i] & (1 << bit))
                dp[i][bit] = (i - 1 >= 0 ? dp[i-1][bit]: 0) + 1;
            else
                dp[i][bit] = dp[i-1][bit];
        }
    }
}

int query(int l, int r){
    int ans = 0;

    for(int i = 0; i < 32; i++){        
        if(dp[r][i] - (l - 1 >= 0 ? dp[l-1][i]: 0) == r - l + 1)
            ans |= (1 << i);
    }

    return ans;
}

int main() {
    vector<int> arr = { 7, 5, 3, 5, 2, 3 }; 
    pre(arr);
    
    cout << query(2,2) << endl;    

    cout << (3) << endl;

    cout << (5 && (1 << 1)) << endl;
    return 0;
}
// AND - all the numbers from l,r must have the ith bit set -> 1
// OR - any number from l,r must have ith bit set -> 1
