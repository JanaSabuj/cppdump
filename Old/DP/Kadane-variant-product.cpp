#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n){

    int maxval=1,minval=1,ans=INT_MIN,prevMax;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            maxval=maxval*arr[i];
            minval=min(minval*arr[i],1);
        }

        else if(arr[i]==0){
            minval=1; 
            maxval=0;
        }
        else if(arr[i]<0){
            prevMax=maxval;
            maxval=minval*arr[i];
            minval=prevMax*arr[i];
        }

        ans=max(ans,maxval);
        if(maxval<=0)
            maxval=1;
    }

    return ans;
}

int main() {
    // cout<<"Hello World!";
    int n;cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<kadane(arr,n)<<endl;
    return 0;
}
