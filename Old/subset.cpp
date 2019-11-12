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
                  
     char arr[4]={'a','b','c','d'};
     int n=4;
     //~ cout<<arr[0];
     for(int mask=0; mask<(1<<n); mask++){
		 
		 for(int j=0; j<n; j++){
			 //bitwise and &
			 if(mask & (1<<j))
				cout<<arr[j]<<" ";
									 
		 }
		 cout<<endl;
		 
	 }
     
      
    return 0;
 }

