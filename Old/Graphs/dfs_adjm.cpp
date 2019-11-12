 //Built by Sabuj Jana(greenindia) from Jadavpur University

#include <bits/stdc++.h>
using namespace std;
void fileio(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);freopen("error.txt", "w", stderr);}
int adj[100][100];
string color[100];
int nodes,edges;

void dfsVisit(int x){
    cout<<x<<" ";
    color[x]="GRAY";
    for(int i=0; i<nodes; i++){
        if(adj[x][i]==1){
            if(color[i]=="WHITE"){
                dfsVisit(i);
            }
        }
    }
    color[x]="BLACK";
}

void dfs(){
    for(int i=0; i<nodes; i++){
        color[i]="WHITE";
    }
    for(int i=0; i<nodes; i++){
        if(color[i]=="WHITE"){
            dfsVisit(i);
        }
    }

}


int main() {
    fileio();ios_base::sync_with_stdio(false);cin.tie(NULL);
//    int t;cin>>t;cout<<t;cerr<<t;
cin>>nodes>>edges;
for(int i=0; i<edges; i++){
    int n1,n2;
    cin>>n1>>n2;
    adj[n1][n2]=1;
    adj[n2][n1]=1;
}

dfs();

    return 0;
}
