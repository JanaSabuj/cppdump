//Built by Sabuj Jana(greenindia) from Jadavpur University

#include <bits/stdc++.h>
using namespace std;
void fileio(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);freopen("error.txt", "w", stderr);}

int main() {
    fileio();
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
//    int t;cin>>t;cout<<t;cerr<<t;
int n;
cin>>n;

string arr[n];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }
//print all the subsets of a given array
    for(auto mask=0; mask<= pow(2,n)-1; mask++){
    
        for(int i=0; i<n; i++){
            if(mask & 1<<i){
                cout<<arr[n-i-1]<<",";
            }
        }
        cout<<endl;
    }

    return 0;
}
