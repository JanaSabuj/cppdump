https://codeforces.com/contest/25/problem/D
//1. Make a edge b/w 2 nodes iff they are NOT in the same CC
// a  ----  b
if (find_set(a) != find_set(b))
			union_sets(a, b);
else {
		  // edge b/w a and b is redundant, dont construct it
}

//2. Count CC after the union_set funcs OR connect all isolated CCs
// Check if a node is connected to an arbitrary node, say 1
// if not connected to 1, ++CC
int cc = 1;
for (int i = 2; i <= n; ++i) {
		if (find_set(1) != find_set(i)) {
			// you can add an edge b/w 1 and i to join them      
			union_sets(1, i);// adding that edge
      
      cc++;
		}
}

https://acm.timus.ru/problem.aspx?space=1&num=1671
//3. To print the no of CCs after every deletion of an edge, first construct DSU for all 
// edges that will never be deleted. Then process the deleted edges in the reverse order, print the CCs and union that deleted edge's nodes

// 4. Timus - PARITY
// if parity of 1s in [l, r] is even, => parity [l-1] = [r] and ![l - 1] = ![r]
// if parity of 1s in [l. r] is odd, => parity [l - 1] = ![r] and [l - 1] = ![r]


https://www.spoj.com/problems/CLFLARR/
// In this problem, par[i] pts to the rightmost idx which must be colored by avoiding all already colored indxs.
// union(idx, idx + 1) concept

// To calculate the total no of ways to select 2 nodes fron N nodes, one from each CC, such that there is no path b/w them
// WAYS = NC2 - sum(S[i]C2) [i = 1 to k] 
// k connected components

https://www.spoj.com/problems/CONSEC/
Same concept as Q3. First apply the #s on the string, then make the dsu tree
After that, process all queries in reverse order and undo changes as you go on.
	
	
