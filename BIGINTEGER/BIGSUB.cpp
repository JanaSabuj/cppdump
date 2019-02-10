//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India 
// God is Great

 #include <bits/stdc++.h>
 using namespace std;
 
 string BIGDIFF(string s1, string s2){
	 
	 //~ cout<<stoi(s1)-stoi(s2)<<endl;
	 //s2 must be bigger
	  if(stoi(s1)>stoi(s2))
		swap(s1,s2);
		
	int n1=s1.length();
	int n2=s2.length();
	int diff=n2-n1;
	int carry=0;
	string ans;
	for(int i=n1-1; i>=0; i--){
		
		int sub= (s2[i+diff]-'0')-(s1[i]-'0')-carry;
		if(sub<0)
			{
				sub=sub+10;
				carry=1;
			}
		else 
			carry=0;
			
		ans+=(sub+'0');
	}
	
	for(int i=n2-n1-1; i>=0; i--){
		
		if((s2[i]-'0')=='0' and carry){
			
			ans+='9';
			continue;
			
		}
		
		int sub= (s2[i]-'0')-carry;
		if (i>0 || sub>0) // remove preceding 0's 
            ans.push_back(sub+'0'); 
        carry = 0; 
  
    } 
  
    // reverse resultant string 
    reverse(ans.begin(), ans.end()); 
  
    return ans; 
} 
 
 
 
 int main() {
   	freopen("input.txt", "r", stdin);
   	//~ int t;cin>>t;cout<<t;cerr<<t;cout<<"Hello World"; 
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
                  
     
     string s1,s2;
     cin>>s1>>s2;
     
     cout<<BIGDIFF(s1,s2)<<endl;
     
    return 0;
 }

