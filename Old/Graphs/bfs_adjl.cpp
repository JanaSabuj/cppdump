 //Built by Sabuj Jana(greenindia) from Jadavpur University

#include <bits/stdc++.h>
using namespace std;
void fileio(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);freopen("error.txt", "w", stderr);}
vector<int> adj[100];
string color[100];
int dis[100];
int parent[100];
int nodes,edges;

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
        for(auto neigh : adj[x]){
                if(color[neigh]=="WHITE"){
                    q.push(neigh);
                    parent[neigh]=x;
                    dis[neigh]= dis[x]+1;
                }

        }
        // now change the color to black
        color[x]="BLACK";
    }

}

int main() {
    fileio();ios_base::sync_with_stdio(false);cin.tie(NULL);
//    int t;cin>>t;cout<<t;cerr<<t;
cin>>nodes>>edges;
//taking input of the adjacency list
for(int i=0; i<edges; i++){
    int n1,n2;
    cin>>n1>>n2;
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
}

bfs(0);

    return 0;
}
