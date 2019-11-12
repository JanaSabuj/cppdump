#include <bits/stdc++.h>
using namespace std;

set<int> divs(int n){
    set<int> s;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            if(n/i==i) s.insert(i);
            else{
                s.insert(i);
                s.insert(n/i);
            }
        }
    }

    return s;

}



int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;
    set<int> ans;
    ans=divs(n);
    for(auto it=ans.begin(); it!=ans.end(); it++){
        cout<<*it<<" ";
    }

    return 0;
}
