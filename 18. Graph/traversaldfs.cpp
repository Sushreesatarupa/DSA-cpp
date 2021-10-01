#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[] , int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsrec(vector<int>adj[] , int s , vector<bool>&visited){
    if(visited[s]==false){
        cout<<s<<" ";
        visited[s]=1;
        for(auto x : adj[s]){
            if(visited[x]==0){
                dfsrec(adj , x , visited);

            }
        }
    }

}
void dfs(vector<int>adj[] , int s , int V){
    vector<bool>visited(V , 0);
    dfsrec(adj , s , visited);
    cout<<endl;
    
}

//dfs for graph having various connected components
void dfsrec2(vector<int>adj[] , int s , vector<bool>&visited){
    visited[s]=true;
    cout<<s<<" ";
    for(int u : adj[s]){
        if(visited[u]==false){
            dfsrec2(adj , u , visited);
        }
    }
}
void dfs3(vector<int>adj[] , int V){
    int i =0 ; 
    vector<bool>visited(V ,0);
    for(int i =0 ; i<V ; i++){
        if(visited[i]==false){
            dfsrec2(adj , i , visited);
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
    dfs(adj , 0 , V);
    dfs3(adj , V);

    return 0;
}