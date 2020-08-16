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

vi nsef(vi& arr){
    int n = arr.size();
    vi nse(n);

    stack<int> s;    
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() and arr[s.top()] >= arr[i])
            s.pop();
        
        if(s.empty())
            nse[i] = -1;
        else
            nse[i] = arr[s.top()];
        
        s.push(i);
    }

    return nse;
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

    cout << endl;
    vi nse = nsef(arr);
    for(auto x: nse){
        cout << x << " ";
    }
    return 0;
}
