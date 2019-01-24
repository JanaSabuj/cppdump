#include <iostream>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    if(n%2==0) return false;
    for(int x=3; x*x<=n; x+=2){
        if(n%x==0){
            return false;
        }
    }
    return true;
}

int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;
    if(isPrime(n))
        cout<<"YES IT IS A PRIME";
    else
        cout<<"NO IT IS NOT A PRIME";
        return 0;
}
