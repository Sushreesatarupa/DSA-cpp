/*
cycle detection in directed graph from dfs
tc - o(n)
sc - o(n)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool checkCycle(ll node, vector<ll> adj[], ll vis[], ll dfsvis[]){
    vis[node] = 1;
    dfsvis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkCycle(it, adj, vis, dfsvis))
            return true;
        }
        else if(dfsvis[it])
        return true;
    }
    dfsvis[node] = 0;
    return false;
}

bool isCyclic(ll V, vector<ll> adj[]){

    ll vis[V+1];
    ll dfsvis[V+1];
    memset(vis, 0, sizeof vis);
    memset(dfsvis, 0, sizeof dfsvis);

    for(ll i=1; i<=V; i++){
        if(!vis[i]){
            if(checkCycle(i, adj, vis, dfsvis))
            return true;
        }
    }

    return false;

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

    cout<<isCyclic(V, adj);
    return 0;
}



/*
input -
9 10
1 2
2 3
3 4
3 6
4 5
6 5
7 2
7 8
8 9
9 7
*/
