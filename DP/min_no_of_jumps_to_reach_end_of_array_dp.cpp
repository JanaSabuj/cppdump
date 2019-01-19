#include <bits/stdc++.h>
using namespace std;

int MJ(int arr[], int n){

int jumps[n], result[n];
for(int i=0; i<n; i++){
    jumps[i]=INT_MAX;
}
jumps[0]=0;

for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
        if(arr[j]+j>=i){
            if(jumps[j]+1<jumps[i]){
                result[i]=j;
                jumps[i]=jumps[j]+1;
            }
        }
    }
}



//to print the optimal path taken
int x=n-1;

vector<int> vec;
while(x!=0){
    // cout<<result[x]<<" ";
    vec.push_back(result[x]);
    x=result[x];
}
sort(vec.begin(), vec.end());// because backtracked descending paths are pushed back

for(auto it=vec.begin(); it!=vec.end(); it++){
    cout<<*it<<" ";
}
cout<<n-1<<" ";//print the final destination
cout<<endl;
return jumps[n-1];
 
}
 
int main() {
    // cout<<"Hello World!";

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
     
    int minjumps= MJ(arr, n);
    cout<<minjumps<<endl;
    return 0;

}
