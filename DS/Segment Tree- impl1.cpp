 //Built by Sabuj Jana(greenindia) from Jadavpur University

#include <bits/stdc++.h>

using namespace std;

void fileio() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    freopen("error.txt" , "w" , stderr);
}

#define mx 100001
int arr[mx];
int tree[mx * 3];

void init(int node , int b , int e) {
    if (b == e) {
        tree[node] = arr[b];
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (e + b) / 2;
    init(left , b , mid);
    init(right , mid + 1 , e);
    tree[node] = tree[left] + tree[right];
}

int query(int node,int b,int e, int i,int j){
        if(i>e or j<b)
            return 0;
        if(b>=i and e<=j)
            return tree[node];
        int left=node*2;
        int right=node*2+1;
        int mid=(b+e)/2;
        int p1= query(left,b,mid,i,j);
        int p2= query(right,mid+1,e,i,j);
        return p1+p2;

}

void update(int node,int b,int e,int i,int x){
    if(b>i or e<i) return ;
    if(b>=i and e<=i){
        tree[node]=x;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[node]=tree[left]+tree[right];
}


int main() {
    fileio();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    int t;cin>>t;cout<<t;cerr<<t;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1 , 1 , n);

//    for(int i=1; i<=n+7; i++){
//        cout<<tree[i]<<" ";
//    }
    cout<<query(1,1,7,3,5)<<endl;
     update(1,1,7,4,6);
    cout<<query(1,1,7,3,5)<<endl;

    return 0;
}
