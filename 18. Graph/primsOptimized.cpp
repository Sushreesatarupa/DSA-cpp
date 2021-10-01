#include<bits/stdc++.h>
using namespace std;
int main(){
    int V, E;
    cin >> V >> E;
    vector<pair<int,int>> adj[V];
    int u,v, w;
    for(int i=0;i<E;i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int parent[V]={-1};
    int key[V]={INT_MAX};key[0]=0;
    bool mst[V]={false};

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int minind = pq.top().second;
        pq.pop();
        for(auto x: adj[minind]){
            if(mst[x.first]==false && x.second<key[x.first]){
                parent[x.first]=minind;
                key[x.first]=x.second;
                pq.push(make_pair(key[x.first], x.first));
            }
        }
    }
    
    for(int i=1;i<V;i++) cout << i <<" "<<parent[i]<<endl;
    
    return 0;
}