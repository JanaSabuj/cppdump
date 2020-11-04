// @greenindia - SABUJ JANA
// janasabuj.github.io
#include <bits/stdc++.h>
using namespace std;
#define crap                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define int long long int
#define double long double
#define PI acos(-1)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define endl "\n"

void build(int v, int tl, int tr, int st[], int arr[]) {
    // [10, 20, 30, 40, 50, 60] [1, 6]

    if (tl == tr)
        st[v] = arr[tl];  // build base-level
    else {
        int tm = (tl + tr) / 2;  // build left,right & merge
        build(2 * v, tl, tm, st, arr);
        build(2 * v + 1, tm + 1, tr, st, arr);
        st[v] = st[v * 2] + st[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r, int st[], int arr[]) {
    if (r < l)
        return 0;  // invalid range

    // 3 cases
    if (r < tl or l > tr)
        return 0;  // no overlap
    else if (l == tl and r == tr) {
        return st[v];  // full overlap
    } else {
        int tm = (tl + tr) / 2;  // partial overlap
        return query(v * 2, tl, tm, l, min(r, tm), st, arr) +
               query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, st, arr);
    }
}

void update(int v, int tl, int tr, int pos, int x, int st[], int arr[]) {
    // 3 cases
    if (pos < tl or pos > tr)
        return;  // no overlap
    else if (pos == tl and pos == tr)
        st[v] = x;  // full overlap
    else {
        int tm = (tl + tr) / 2;  // partial overlap
        update(v * 2, tl, tm, pos, x, st, arr);
        update(v * 2 + 1, tm + 1, tr, pos, x, st, arr);
        st[v] = st[v * 2] + st[v * 2 + 1];
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
#endif
    crap;

    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    for (int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }

    // segtree - build
    int st[4 * n];
    build(1, 1, n, st, arr);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // updt
            int k, x;
            cin >> k >> x;
            update(1, 1, n, k, x, st, arr);
        } else {
            // range query
            int a, b;
            cin >> a >> b;

            cout << query(1, 1, n, a, b, st, arr) << endl;
        }
    }

    return 0;
}
// https://cses.fi/problemset/task/1648
