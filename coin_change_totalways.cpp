#define int long long int
#define double long double
#define PI acos(-1)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi arr;
int len, total;
int dp[255][500];

int coin(int idx, int& store) {
    if (store > total)
        return 0;

    if (idx == len) {
        if (store == total)
            return 1;
        else {
            return 0;
        }
    }

    if (dp[idx][store] != -1)
        return dp[idx][store];

    store += arr[idx];
    int A = coin(idx, store);
    store -= arr[idx];

    int B = coin(idx + 1, store);

    return dp[idx][store] = A + B;
}

void solve() {
    int n, m;
    cin >> n >> m;

    arr.assign(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    len = m;
    total = n;
    int store = 0;
    memset(dp, -1, sizeof(dp));
    int ways = coin(0, store);

    cout << ways << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
#endif
    crap;

    solve();

    return 0;
}
