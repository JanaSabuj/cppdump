#include <iostream>
using namespace std;
int main() {
    // cout<<"Hello World!";
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum=0,ans=0;
    int start=0,end=0,s=0;
    
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum<0)
            {sum=0;s=i+1;}
        if(sum>ans)
            {ans=sum; start=s; end=i;}
        
    }

    cout<<ans<<endl;
    cout<<start<<" "<<end<<endl;

}
