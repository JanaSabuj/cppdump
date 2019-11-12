#include <bits/stdc++.h>
using namespace std;

void KS(int KSWT, int n, int wt[], int val[])
{
    
    /// PREPARING THE 2D KNAPSACK K ARRAY 
    int K[n+1][KSWT+1];
    
    for (int i = 0; i <=n; i++) {
        /* code */
        for (int w = 0; w <=KSWT; w++) {
            /* code */
            
                    if(i==0| w==0)
                        K[i][w]=0;
                    else if(w>=wt[i-1])
                        K[i][w]= max(K[i-1][w], (val[i-1]+K[i-1][w-wt[i-1]]));
                    else
                        K[i][w]=K[i-1][w];
             
        }
    }
    
   ///ARRAY K HAS BEEN CREATED
    int res=K[n][KSWT];
    std::cout << res << std::endl; /// MAX OPTIMISED KNAPSACK VALUE WE GET AND PRINT
    
    
    
  /// IF WE WANNA PRINT THE 0-1 KNAPSACK ITEMS 
    int w=KSWT;
    
    for (int i = n; i > 0 && res>0; i--) {
        /* code */
        
                if(K[i][w]== K[i-1][w])
                    continue;
                
                else {
                         cout<< wt[i-1]<<" ";//THIS WEIGHT IS INCLUDED IN KNAPSACK SO PRINTED
                        
                        res=res-val[i-1];
                        w=w-wt[i-1];
                     
                }
         
    }
      
}
 
int main() {
 
int KSWT,n;
cin>>KSWT>>n;//// KSWT-wt of knapsack  n-no if items

int wt[n], val[n];/// wt array, val array

///wt-val input
for (int i = 0; i < n; i++) {
    /* code */
    cin>>wt[i];
    cin>>val[i];
     
}
 
 KS(KSWT,n, wt,val);
  
	return 0;
}