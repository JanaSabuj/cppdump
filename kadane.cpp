typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}

void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}

void solve() {
	vi arr = {1, 2, 5, -10, 11, 1, -12, 40};

	int a = 0;
	int ans = INT_MIN;
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		a += arr[i];
		ans = max(ans, a);
		a = max(a, 0LL);
	}

	cout << "MAX SUM SUBARRAY IS " << ans << endl;
}

void solve2() {
	vi arr = {1, 2, 5, -10, 11, 1, -12, 40};

	int a = 0;
	int ans = INT_MIN;
	int n = arr.size();
	int s = 0, start = 0, end = 0;

	for (int i = 0; i < n; ++i) {
		a += arr[i];
		if (a > ans) {
			ans = a;
			start = s;
			end = i;
		}
		if (a < 0) {
			a = 0;
			s = i + 1;
		}
	}

	cout << "MAX SUM SUBARRAY IS " << ans << endl;
	cout << "Start and end is " << start << " " << end << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	solve();
	solve2();

	return 0;
}
