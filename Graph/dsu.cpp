struct dsu {
	vector<int> parent;
	vector<int> _size;

	// merge two sets having a&b as entities
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

	// find the set leader
	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	// check if same set/leader
	bool same_comp(int a, int b) {
		return find_set(a) == find_set(b);
	}

	void make_set(int v) {
		parent[v] = v;
		_size[v] = 1;
	}

	void _init(int n) {
		parent.assign(n, 0);
		_size.assign(n, 0);

		for (int i = 0; i < n; i++)
			make_set(i);
	}
};