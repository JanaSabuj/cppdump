//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India 
// God is Great

 #include <bits/stdc++.h>
 using namespace std;
 string BIGADD(string& s1, string& s2){
	
	//s2 is always bigger
	//  s2
	//+ s1
	// ________
	//   s
	//-------------
	 
	 if(s1.length()>s2.length())
		swap(s1,s2);
		
	int n1=s1.length();
	int n2=s2.length();
	int diff=n2-n1;
	string ans="";
	int carry=0;
	for(int i=n1-1; i>=0; i--){
		
		int sum=(s1[i]-'0')+(s2[i+diff]-'0')+carry;
		ans+=(sum%10+'0');
		carry=sum/10;
		
	}
	
	 for(int i=n2-n1-1; i>=0; i--){
		 
		 int sum= (s2[i]-'0')+carry;
		 ans.push_back(sum%10+'0');
		 carry=sum/10;
		 
	 }
	 
	 if(carry)
		ans.push_back(carry+'0');
	
	reverse(ans.begin(),ans.end());
	 
	 //~ cout<<ans;
	 return ans;
	 
	 }
 
 
 
 int main() {
   	freopen("input.txt", "r", stdin);
   	//~ int t;cin>>t;cout<<t;cerr<<t;cout<<"Hello World"; 
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
                  
     
     string s1,s2;
     cin>>s1>>s2;
     
     cout<<BIGADD(s1,s2);
     
     
    return 0;
 }

