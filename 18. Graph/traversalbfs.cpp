#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[] , int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs( vector<int>adj[] , int V , int s){
    vector<bool>visited(V , 0);
    queue<int>q;
    visited[s]=1;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto u : adj[x]){
            if(visited[u]==0){
                q.push(u);
                visited[u]=1;
            }
        }
    }
    cout<<endl;


}

//bfs for graph having various connected components
void bfs3(vector<int>adj[] , int s , vector<bool>&visited){
    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto u : adj[x]){
            if(visited[u]==0){
                q.push(u);
                visited[u]=1;
            }
        }
    }

}

void bfs2(vector<int>adj[] , int V){
    int i  = 0;
    vector<bool>visited(V , 0);
    for(i = 0 ; i<V ; i++){
        if(visited[i]==0){
            bfs3(adj , i , visited);
        }
    }

}

int main(){
    int V = 4;
    vector<int>adj[V];
    addEdge(adj , 0 , 1);
    addEdge(adj , 0 , 2);
    addEdge(adj , 1 , 2);
    addEdge(adj , 1 , 3);
    bfs(adj , V , 0);
    bfs2(adj , V);

    return 0;
}