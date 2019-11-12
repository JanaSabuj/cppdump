//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India 
// God is Great------------/////\\\\\\\--------------------------------
 #include <bits/stdc++.h>
 using namespace std;
 #define stfu ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 #define int long long int
 #define endl "\n"
 #define pb push_back
 #define mp make_pair
 
 

 #undef int
 int main() {
 #define int long long int
   	freopen("input.txt", "r", stdin);
   	//~ int t;cin>>t;cout<<t;cerr<<t;cout<<"Hello World"; 
	stfu;
                  
     int arr[3]={1,3,2};
     sort(arr,arr+3);
     do {
		 
		 cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<< endl;
		 
	 } while(next_permutation(arr,arr+3));
     //~ if(next_permutation(arr,arr+3))
     //~ cout<<arr[0]<<arr[1]<<arr[2]<<endl;
      
    return 0;
 }

