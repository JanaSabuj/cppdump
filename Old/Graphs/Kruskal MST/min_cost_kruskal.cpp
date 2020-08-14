#include<bits/stdc++.h>
using namespace std;

class MinCost{
    public:
        int find_min_cost(int n, vector<vector<int>>& edges, vector<vector<int>>& newEdges){
            vector<int> parent(n+1);
            vector<int> rank(n+1);
            int connected = 6;
            int min_cost = 0;
            for(int i=1;i<=n;i++){
                parent[i] = i;
                rank[i] = 0;
            }
            for(auto edge:edges){
                if(find_set(parent,edge[0]) != find_set(parent,edge[1]))
                    union_(parent,rank,edge[0],edge[1]), connected--;
            }
            sort(newEdges.begin(),newEdges.end(),
                [](vector<int>& p1, vector<int>& p2){
                    return p1[2]<p2[2];
                });
            for(auto edge:newEdges){
                if(find_set(parent,edge[0]) != find_set(parent,edge[1])){
                    union_(parent,rank,edge[0],edge[1]);
                    connected--;
                    min_cost += edge[2];
                }
                if(connected == 1)
                    break;
            }
            return (connected == 1) ? min_cost : -1;
    }
    int find_set(vector<int>& parent, int x){
        if(x != parent[x])
            parent[x] = find_set(parent,parent[x]);
        return parent[x];
    }

    void union_(vector<int>& parent, vector<int>& rank, int x, int y){
        int rootx = find_set(parent,x);
        int rooty = find_set(parent,y);
        if(rank[rootx] > rank[rooty])
            parent[rooty] = rootx;
        else
            parent[rootx] = rooty;
        if(rank[rootx] == rank[rooty])
            rank[rooty] = rank[rooty] + 1;
    }
};

typedef vector<int> vi; 
typedef pair<int,int> pii; 
class MinCost2{
    public:
    void initialize(vi& parent, vi& size, int n){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i] - 1;
        }
    }

    int find_set(int x, vi& parent){
        if(parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x], parent);            
    }

    void union_do(int x, int y, int& comps, vi& parent, vi& size){
        x = find_set(x, parent);
        y = find_set(y, parent);

        if(x == y)
            return;
        // join
        if(size[x] < size[y])
            swap(x,y);
        // a big 
        parent[y] = x;
        size[x] += size[y];
        comps--;
    }

   
        int find_min_cost(int n, vector<vector<int>>& edges, vector<vector<int>>& newEdges){
            vector<int> parent(n + 1);
            vi size(n + 1);

            initialize(parent, size, n);

            int comps = n;

            vector<pair<int, pii>> box;

            for(auto x: edges){
                union_do(x[0], x[1], comps, parent, size);
            }

            for(auto x: newEdges){
                box.push_back({x[2], {x[0], x[1]}});
            }

            if(comps == 1)
                return 0;

            sort(box.begin(), box.end());
            int cost = 0;
            for(auto x: box){
                int a = x.second.first;
                int b = x.second.second;

                if(find_set(a, parent) != find_set(b, parent)){
                    cost += x.first;
                    union_do(a, b, comps, parent, size);                      
                }

                if(comps == 1)
                    return cost;    
            }
            
            cout << comps << endl;
            return (comps == 1) ? cost : -1;

        }                      
};

int main() {
    MinCost minCost;
    int n = 6;
    vector<vector<int>> edges = {{1,4},{4,5},{2,3}};
    vector<vector<int>> newEdges = {{1,2,5},{1,3,10},{1,6,2},{5,6,5}};
    cout<<minCost.find_min_cost(n,edges,newEdges) << endl;

    MinCost2 mc;
    cout<<mc.find_min_cost(n,edges,newEdges) << endl;
    return 0;
}
