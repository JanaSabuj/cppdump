#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi pgef(vi& arr){
    stack<int> s;
    int n = arr.size();    
    vi pge(n);

    // just reverse the loop
    for(int i = 0; i < n; i++){
        while(!s.empty() and s.top() <= arr[i])
            s.pop();
        
        if(s.empty())
            pge[i] = -1;
        else
            pge[i] = s.top();
        
        s.push(arr[i]);
    }

    return pge;

}

vi ngef(vi& arr){
    stack<int> s;
    int n = arr.size();
    vi nge(n);

    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() and arr[s.top()] <= arr[i])
            s.pop();
        
        if(s.empty())
            nge[i] = -1;
        else
            nge[i] = arr[s.top()];

        s.push(i);
    }

    return nge;

}
int main() {
    vector<int> arr = {1, 3, 5, 2, 4};
    vi nge = ngef(arr);
    vi pge = pgef(arr);

    for(auto x: arr)
        cout << x << " ";
    cout << endl;

    for(auto x: nge)
        cout << x << " ";
    cout << "\n";

    for(auto x: pge)
        cout << x << " ";
    return 0;
}
