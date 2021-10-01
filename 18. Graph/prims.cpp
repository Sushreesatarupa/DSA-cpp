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

    for(int i=0;i<V-1;i++){
        int minind = 0;
        int minival = INT_MAX;
        for(int j=0;j<V;j++){
            if(key[j]<minival && mst[minind]==false){
                minind = j;
                minival = key[j];
            }
        }
        mst[minind]=true;

        for(auto x: adj[minind]){
            if(mst[x.first]==false && key[x.first] > x.second){
                parent[x.first]=minind;
                key[x.first]=x.second;
            }
        }
    }

    for(int i=1;i<V;i++){
        cout << i <<" "<<parent[i]<<endl;
    }
    return 0;
}