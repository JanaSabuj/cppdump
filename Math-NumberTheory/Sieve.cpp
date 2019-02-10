  //Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India 
// God is Great

 #include <bits/stdc++.h>
 using namespace std;
 
 
 void sieveofera(int n){
		
		int sieve[n+7];
        memset(sieve,0,sizeof(sieve));// initialised with 0-initially all are primes
		sieve[1]=1;// 1 is not a prime so assigned 1
		for(int i=2; i*i<=n; i++){
			
				if(sieve[i]==0) // that is if the no is a prime
					{
							for(int j=i*i; j<=n; j+= (i)){
								
								//all multiples of prime are not prime
								sieve[j]=1;
							}
						
					}
		}
		 
		for(int i=1; i<=n; i++){
			
			if(sieve[i]==0) // if it is a prime
				cout<<i<<" ";
			
		}
	  
	 }
 
 int main() {
   	freopen("input.txt", "r", stdin);
   	//~ int t;cin>>t;cout<<t;cerr<<t;cout<<"Hello World"; 
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
                  
     
     int n;
     cin>>n;
     
    sieveofera(n);
        
	return 0;
 }

