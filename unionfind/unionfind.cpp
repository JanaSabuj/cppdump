void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
}

// Path compression - O(log N)
int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

// Union by Size -
// a big, b small
void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
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
