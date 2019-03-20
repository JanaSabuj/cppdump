//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India
//God is Great
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define endl "\n"
#define int long long int
#define double long double
const int INF = 1e9 + 5; //billion
#define pb push_back
#define mp make_pair
#define PI acos(-1)

#define MAX 100007

void bt(int arr[], int tree[], int s, int e, int tN) {

	if (s == e) {
		tree[tN] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	bt(arr, tree, s, mid, 2 * tN);
	bt(arr, tree, mid + 1, e, 2 * tN + 1);

	tree[tN] = tree[2 * tN] + tree[2 * tN + 1];


}

void ut(int arr[], int tree[], int s, int e, int tN, int idx, int val){


	if(s==e){
		arr[idx]=val;
		tree[tN]=val;
		return;
	}

	int mid=(s+e)/2;
	if(idx>mid){
		//right
		ut(arr,tree,mid+1,e,2*tN+1,idx,val);
	}else {
		//left
		ut(arr,tree,s,mid,2*tN,idx,val);
	}

	tree[tN]=tree[2*tN]+tree[2*tN+1];


}

int query(int tree[], int s,int e, int tN, int l, int r){


	//Completely outside
	if(s>r or e<l)
		return 0;

	//Completely inside
	if(s>=l and e<=r){
		return tree[tN];
	}

	//PArtially
	int mid=(s+e)/2;
	int ans1=query(tree,s,mid,2*tN,l,r);
	int ans2=query(tree,mid+1,e,2*tN+1,l,r);

	return ans1+ans2;

}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	crap;

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> arr[i];
	}

	int tree[4 * n];

	//buildtree karke le aaa
	bt(arr, tree, 0, n - 1, 1);
  
//update  
	int q;
	cin >> q;

	while (q--) {

		int idx, val;
		cin >> idx >> val;
		ut(arr, tree, 0, n - 1, 1, idx, val);

		 
	}

//query 
	int z;
	cin>>z;

	while(z--){
		int l,r;
		cin>>l>>r;
		cout<<query(tree,0,n-1,1,l,r)<<endl;
	}


	return 0;

}

