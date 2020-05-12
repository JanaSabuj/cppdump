#define int long long int
#define double long double
#define PI acos(-1)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi arr;
int len;
int dp[255][500];

int coin(int idx, int& store) {// store is ref variable for time optimisation
    if (store < 0)
        return 0;

    if (idx == len) {
        if (store == 0)
            return 1;
        else {
            return 0;
        }
    }

    if (dp[idx][store] != -1)
        return dp[idx][store];

    store -= arr[idx];// ref variable modified
    int A = coin(idx, store);
    store += arr[idx];// ref variable restored

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
    int store = n;
    memset(dp, -1, sizeof(dp));
    int ways = coin(0, store);// traverse from total change to 0 change

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
