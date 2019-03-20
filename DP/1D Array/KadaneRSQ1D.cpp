//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India 
//God is Great 
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
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	cin>>arr[i];
    }

    int ans=INT_MIN,sum=0,start=0,end=0,s=0,xstart=0,xend=0;
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	sum+=arr[i];
    	if(sum>ans){
    		ans=sum;
    		start=s;end=i;
    	}
    	if(sum<0){
    		sum=0;
    		s=i+1;
    	}
    	if(sum==ans){

    		xstart=s;
    		xend=i;
    		if(xend-xstart> end-start){
    			start=xstart;
    			end=xend;
    		}
    	}
    }

    cout<<ans<<endl;
    cout<<start<<" "<<end<<endl;
                  
     
    return 0;
    
 }

