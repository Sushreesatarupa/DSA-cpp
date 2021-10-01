#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int> >& adj,map<pair<int,int>,int>& C,int& source,int& n,int& m){
         const int inf = INT_MAX;
         //using min heap to obtain next lesser edge
         priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;

         //Initializing distance to infinity
         vector<int>dist(n+1,inf);
         q.push({0,source});
         vector<bool>visited(n+1,false);
         dist[source]=0;

         
         while(!q.empty()){
            auto z=q.top();
            q.pop();
            int y=z.first;
            int x=z.second;
            if(visited[x])continue;
            visited[x]=true;
            for(int i : adj[x]){
              if(!visited[i]){
              if(dist[i]>y+C[{x,i}]){
                dist[i]=y+C[{x,i}];
                q.push({dist[i],i});
              }
            }
            }
         }
         return dist;
}

int main(){
         int n,m;
         cin>>n>>m;
         //Adjacency List to store the graph
         vector<vector<int> >adj(n+1);

         //Map to store the edge lengths
         map<pair<int,int>,int>C;
         for(int i=0;i<m;i++){
          int x,y,cost;
          cin>>x>>y>>cost;
          if(x==y)continue;
          if(C.find({x,y})==C.end()){
            adj[x].push_back(y);
            C[{x,y}]=cost;
          }
          else{
            C[{x,y}]=min(C[{x,y}],cost);
          }
         }
         
         int source;
         cin>>source;

         vector<int>dist = dijkstra(adj,C,source,n,m);

         //Printing distance of all points from source
         for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
          cout<<endl;
}
