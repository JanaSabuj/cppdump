#include <iostream>
#include <algorithm>
using namespace std;

int lcs(string X, string Y){
    int n = X.size();
    int m = Y.size();

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    // print
    int i = n, j = m;
    string ans = "";

    while(i > 0 and j > 0){
        if(X[i - 1] == Y[j - 1]){
            ans += X[i - 1];
            i--;
            j--;
        }else if(dp[i][j - 1] > dp[i - 1][j])
            j--;
        else
            i--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return dp[n][m];
}

int main() {
    cout << lcs("abacab", "cab") << endl;
    return 0;
}
