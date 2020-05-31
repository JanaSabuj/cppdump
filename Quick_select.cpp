int partition(vi& arr, int l, int r) {
	int pivot = arr[r];
	int i = l - 1;

	for (int j = l; j < r - l + 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[j], arr[i]);
		}
	}

	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void qsk(vi& arr, int l, int r, int k) {
	if (l < r) {
		int mid = partition(arr, l, r);
		int leftLen = mid - l + 1;
		if (leftLen == k)
			return;
		else if (leftLen > k)
			qsk(arr, l, mid - 1, k);
		else
			qsk(arr, mid + 1, r, k - leftLen);
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	vi arr = {11, 2, 1, 7, 3, 4};
	int k = 4;

	qsk(arr, 0, (int)arr.size() - 1, k);
	print1d(arr);


	return 0;
}
