/*topological sort is for directed acyclic graph
linear ordering of vertices such that for every directed frm u to v , vertex u comes b4 vertex V in ordering
there can be more than one topological sorting order of one graph
recursion + stack data structure
*/

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[] , int u , int v){
    adj[u].push_back(v);
}

void toporec(vector<int>adj[] , int s , vector<bool>&visited , stack<int>&st ){
    visited[s]=true;
    for(auto x : adj[s]){
        if(visited[x]==false){
            toporec(adj , x , visited , st);
        }
    }
    st.push(s);
}
vector<int> toposort(vector<int>adj[] ,int V ){
    stack<int> st;
    vector<bool>visited(V, 0);
    for(int i =0 ; i< V ; i++){
        if(visited[i]==false){
            toporec(adj , i , visited , st);
        }
    }

    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main(){
    int V = 6;
    vector<int>adj[V];
    addEdge(adj , 5 , 0);
    addEdge(adj , 5 , 2);
    addEdge(adj ,2 , 3);
    addEdge(adj , 3, 1);
    addEdge(adj , 4 , 1);
    addEdge(adj , 4 , 0);
    vector<int> v;
    v = toposort(adj , V);
    for(auto it = v.begin() ; it!=v.end() ; it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    return 0;
}



