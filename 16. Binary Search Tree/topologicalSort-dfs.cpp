/*
topological sort implemented through dfs
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void findTopoSort(ll node, vector<ll> &vis, stack<ll> &st, vector<ll> adj[]){

    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

void topoSort(ll V, vector<ll> adj[]){
    stack<ll> st;
    vector<ll> vis(V+1, 0);
    for(ll i=0; i<V; i++){
        if(vis[i] == 0){
            findTopoSort(i, vis, st, adj);
        }
    }

    vector<ll> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    for(ll i=0; i<topo.size(); i++){
        cout<<topo[i]<<" ";
    }
}

int main(){
    ll V,E;
    cin>>V>>E;

    vector<ll> adj[V+1];

    for(ll i=0; i<E; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);

    }

    topoSort(V, adj);
}


/*
input -
0 indexed this is 
5 6
4 0
5 0
4 1
3 1
2 3
5 2
output-
4 2 3 1 0
*/
