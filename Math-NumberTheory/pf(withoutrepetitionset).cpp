 #include <bits/stdc++.h>
using namespace std;

set<int> pf(int n){

    set<int> f;
    for(int x=2; x*x<=n; x++){
            while(n%x==0){
                f.insert(x);
                n/=x;
            }
           
    }
     if(n>1) f.insert(n);//this means it is a prime
    return f;
}


int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;
    set<int> factors;
    factors=pf(n);

    for(auto it=factors.begin(); it!=factors.end(); it++){
        cout<<*it<<" ";
    }

    return 0;
}
