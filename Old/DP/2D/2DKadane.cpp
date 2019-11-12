//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India 
//God is Great 

// 4
// -1 -2 -3 -4
// -5 -6 -7 -8
// -9 -10 -11 -12
// -13 -14 -15 -16
// 5
// 1 -61 5126 612 6
// 41 6 7 2 -7
// 1 73 -62 678 1
// 7 -616136 61 -83 724
// -151 6247 872 2517 8135
// 4
// 0 -2 -7 0 
// 9 2 -6 2
// -4 1 -4  1
// -1 8  0 -2

// -1
// 18589
// 15

 #include <bits/stdc++.h>
 using namespace std;
 #define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 //cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
 #define endl "\n"
 #define int long long int 
 #define double long double
 const int INF=1e9+5;//billion
 #define pb push_back
 #define mp make_pair
 #define PI acos(-1)
 
 #define MAX 100007
   	 
 signed main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	freopen("error.txt", "w", stderr);
    crap;

    int n;
    cin>>n;
    int arr[n][n];
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	for(int j=0; j<n; j++){
    		cin>>arr[i][j];

    		  if(i>0) arr[i][j]+=arr[i-1][j];
    		  if(j>0) arr[i][j]+=arr[i][j-1];
    		  if(i>0 and j>0) arr[i][j]-= arr[i-1][j-1];
    		  // cout<<arr[i][j]<<" ";
    	}
    	// cout<<endl;
    }

     
int ans=LLONG_MIN,sum=0;
    for(int i=0; i<n; i++) 
    	for(int j=0; j<n; j++)
    		for(int k=i; k<n; k++)
    			for(int l=j; l<n; l++){

    				sum=arr[k][l];
    				if(i>0) sum-=arr[i-1][l];
    				if(j>0) sum-=arr[k][j-1];
    				if(i>0 and j>0) sum+=arr[i-1][j-1];
    				ans=max(ans,sum); 
 

    			}



    cout<<ans<<endl;
                  
     
    return 0;
    
 }

