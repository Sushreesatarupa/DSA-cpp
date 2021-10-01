//topological sort ->DAG ...for every edge from u to v , u shold apperar before v
//bfs->indegree concept->reduce indgree by 1-->push the 0 indegree vertex to the queue
//kahns algo 

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[]  , int u , int v , vector<int>&indegree){
    adj[u].push_back(v);
    indegree[v]++;
}

vector<int> toposort(vector<int>adj[] , vector<int>&indegree , int V){
    vector<int>v;
    queue<int>q;
    for(int i =0 ; i<indegree.size() ; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        v.push_back(x);
        for(auto u : adj[x]){
            indegree[u]--;
            if(indegree[u]==0){
                q.push(u);
            }
        }
    }

    return v;


}
int main(){
    int V=5;
    vector<int>adj[5];
    vector<int>indegree(V , 0);
    addEdge(adj , 0 , 2 , indegree);
    addEdge(adj , 0 , 3 , indegree);
    addEdge(adj, 1 , 3 , indegree);
    addEdge(adj , 1, 4 , indegree);
    addEdge(adj , 2 , 3 , indegree);
    vector<int> v;
    v = toposort(adj , indegree , V);
    for(int x : v){
        cout<<x<<" ";
    }
    return 0;
}