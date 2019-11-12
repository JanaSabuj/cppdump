#include <iostream>
using namespace std; 
int arr[51];

int fib(int n){
    if(n<=1)
        return n;
    if(arr[n]!=0)
        return arr[n];
    else
    {
        arr[n]= fib(n-1)+ fib(n-2);
        return arr[n];
    }

}


int main() {
    // cout<<"Hello World!";
int n;
cin>>n;

cout<<fib(n)<<endl;
return 0;


}
