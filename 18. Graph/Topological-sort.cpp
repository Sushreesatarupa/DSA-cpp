// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    for(int i=0; i<V; i++){
	        for(int j=0; j<adj[i].size(); j++){
	            int node=adj[i][j];
	            indegree[node]++;
	        }
	    }
	 
	    queue<int> qu;
	    for(int i=0; i<V; i++){
	        if(indegree[i]==0)
	            qu.push(i);
	    }
	    vector<int> topo;
	    while(!qu.empty()){
	        int node=qu.front();
	        qu.pop();
	        topo.push_back(node);
	        for(int j=0; j<adj[node].size(); j++){
	            int nbr=adj[node][j];
	            if(--indegree[nbr]==0)
	                qu.push(nbr);
	        }
	    }
	    return topo;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
