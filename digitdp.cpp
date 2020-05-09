// Find count of numbers not containing digit 3 upto x
int dp[10][2][2];

int G(int idx, int tight, int isThree, const string& str, const int& len) {
	if (idx == len) {
		if (isThree)
			return 1;
		else
			return 0;
	}

	if (dp[idx][tight][isThree] != -1)
		return dp[idx][tight][isThree];

	int res = 0;
	if (!tight) {
		for (int i = 0; i <= 9; i++) {
			if (i == 3)
				res += G(idx + 1, 0, 1, str, len);
			else
				res += G(idx + 1, 0, isThree, str, len);
		}
	} else {

		for (int i = 0; i <= (str[idx] - '0'); i++) {
			if (i == 3) {
				if (i == (str[idx] - '0'))
					res += G(idx + 1, 1, 1, str, len);
				else
					res += G(idx + 1, 0, 1, str, len);
			} else {
				if (i == (str[idx] - '0'))
					res += G(idx + 1, 1, isThree, str, len);
				else
					res += G(idx + 1, 0, isThree, str, len);
			}

		}
	}

	return dp[idx][tight][isThree] =  res;
}
void solve() {
	memset(dp, -1, sizeof(dp));
	string str;
	cin >> str;
	int len = str.length();
	cout << stoi(str) - G(0, 1, 0, str, len) << endl;
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
