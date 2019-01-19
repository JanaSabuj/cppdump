 //Built by Sabuj Jana(greenindia) from Jadavpur University

#include <bits/stdc++.h>
using namespace std;
void fileio(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);freopen("error.txt", "w", stderr);}
//all global array declarations
int adj[100][100];
int nodes,edges;
string color[100];
int dis[100];
int parent[100];

void bfs(int start){

for(int i=0; i<nodes; i++){

    color[i]="WHITE";
    dis[i]=INT_MIN;
    parent[i]=-1;

}

dis[start]=0;
parent[start]=-1;

queue<int> q;
q.push(start);

while (!q.empty()){
    int x;
    x=q.front();
    q.pop();
    //now we deal with this node
    color[x]="GRAY";
    cout<<x<<" ";

    // lets do some more work
    for(int i=0; i<nodes; i++){
        if(adj[x][i]==1){
            if(color[i]=="WHITE"){
                q.push(i);
                parent[i]=x;
                dis[i]= dis[x]+1;
            }
        }
    }
    // now change the color to black
    color[x]="BLACK";
}

}

int main() {
    fileio();ios_base::sync_with_stdio(false);cin.tie(nullptr);
//    int t;cin>>t;cout<<t;cerr<<t;

cin>>nodes>>edges;

for(int i=0; i<edges; i++){
    int n1,n2;
    cin>>n1>>n2;
    adj[n1][n2]=1;
    adj[n2][n1]=1;
}

 bfs(0);

cout<<endl<<dis[7];
    return 0;
}
