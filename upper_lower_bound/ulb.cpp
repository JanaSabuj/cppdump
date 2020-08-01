#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	
	///////////0   1   2   3  	4  5   6  7
	vi arr = {10, 20, 20, 20, 30, 40, 40, 50};

	// first element greater or equal
	cout << lower_bound(arr.begin(), arr.end(), 20) - arr.begin() << endl;// 1
	cout << lower_bound(arr.begin(), arr.end(), 5) - arr.begin() << endl;// 0
	cout << lower_bound(arr.begin(), arr.end(), 55) - arr.begin() << endl;// 8

	// first element greater
	cout << upper_bound(arr.begin(), arr.end(), 40) - arr.begin() << endl;// 7
	cout << upper_bound(arr.begin(), arr.end(), 0) - arr.begin() << endl;// 0
	cout << upper_bound(arr.begin(), arr.end(), 55) - arr.begin() << endl;// 8
	
	if(binary_search(arr.begin(), arr.end(), 40))
		cout << "YES";// yes
	else
		cout << "NO";
		
	if(binary_search(arr.begin(), arr.end(), 41))
		cout << "YES";
	else
		cout << "NO";// no
	
	
 
	return 0;
}
