//as kahns algo wrks only on directed acyclic graph 
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[] , int u , int v , vector<int>&indegree){
    adj[u].push_back(v);
    indegree[v]++;
}

void isCycle(vector<int>adj[] , vector<int>&indegree , int V){
    queue<int>q;
    int count =0;
    for(int i =0 ; i<indegree.size() ; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        count++;
        for(auto u : adj[x]){
            indegree[u]--;
            if(indegree[u]==0){
                q.push(u);
            }
        }
    }
    if(count==V){
        cout<<"N0"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}

int main(){
    int V=4;
    vector<int>adj[V];
    vector<int>indegree(V , 0);
    addEdge(adj , 0 , 1 , indegree);
    addEdge(adj , 1 , 2 , indegree);
    addEdge(adj , 2 , 0 , indegree);
    addEdge(adj , 2 , 3 , indegree);
    isCycle(adj , indegree , V);
    vector<int>adj2[V];
    vector<int>indegree2(V , 0);
    addEdge(adj2 , 0 , 1 , indegree2);
    addEdge(adj2 , 1 , 2 , indegree2);
    addEdge(adj2 , 0 , 2 , indegree2);
    addEdge(adj2 , 2 , 3 , indegree2);
    isCycle(adj2 , indegree2 , V);
    return 0 ;
}