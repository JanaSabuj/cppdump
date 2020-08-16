#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi ngef(vi& arr){
    stack<int> s;
    int n = arr.size();
    vi nge(n);

    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() and s.top() <= arr[i])
            s.pop();
        
        if(s.empty())
            nge[i] = -1;
        else
            nge[i] = s.top();

        s.push(arr[i]);
    }

    return nge;

}
int main() {
    vector<int> arr = {1, 3, 5, 2, 4};
    vi nge = ngef(arr);
    
    for(auto x: nge)
        cout << x << " ";
    return 0;
}
