/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
 #include <bits/stdc++.h>
 using namespace std;
 #define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 //cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
 #define dbg(x) cerr << #x << " = " << x << endl
 #define endl "\n"
 #define int long long int 
 #define double long double
 #define pb push_back
 #define mp make_pair
 #define PI acos(-1)
 
 const int INF=1e9+5;//billion
 #define MAX 100007
 string alpha="abcdefghijklmnopqrstuvwxyz";
//power (a^b)%m
 int power(int a,int b,int m){int ans=1;while(b){if(b&1)ans=(ans*a)%m;b/=2;a=(a*a)%m;}return ans;}

 //tree
 vector<int> adj[1000];
 int subtree[1000];

 void dfs(int s, int e){
 	cout<<s<<" ";
 	subtree[s]=1;

 	for(auto u: adj[s]){
 		//children
 		if(u!=e){
 			dfs(u,s);
 			subtree[s]+=subtree[u];
 		}
 	}
 }
   	 
 signed main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	freopen("error.txt", "w", stderr);
    crap;

    int n;
    cin>>n;

    int edge=n-1;
    memset(subtree,0,sizeof(0));

    while(edge--){
    	int x,y;
    	cin>>x>>y;

    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    dfs(1,0);
    cout<<endl;

    for(int i=1; i<=n; i++){
    	cout<<subtree[i]<<" ";
    }



                  
     
    return 0;   
 }

