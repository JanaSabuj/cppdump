#include <bits/stdc++.h>
using namespace std;

vector<int> pf(int n){

    vector<int> f;
    for(int x=2; x*x<=n; x++){
            while(n%x==0){
                f.push_back(x);
                n/=x;
            }
           
    }
     if(n>1) f.push_back(n);
    return f;
}


int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;
    vector<int> factors;
    factors=pf(n);

    for(auto it=factors.begin(); it!=factors.end(); it++){
        cout<<*it<<" ";
    }

    return 0;
}
