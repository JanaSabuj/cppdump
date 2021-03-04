const int N = 1e5;
int parent[N];
int _size[N];

void make_set(int v) {
	parent[v] = v;
	_size[v] = 1;
}

// Path compression - O(log N)
int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

// Union by Size - O(alphaN)
// a big, b small
void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (_size[a] < _size[b])
			swap(a, b);
		parent[b] = a;
		_size[a] += _size[b];
	}
}


// int find_set(int v) {
// 	if (v == parent[v])
// 		return v;
// 	return find_set(parent[v]);
// }

// void union_sets(int a, int b) {
// 	a = find_set(a);
// 	b = find_set(b);
// 	if (a != b)
// 		parent[b] = a;
// }
