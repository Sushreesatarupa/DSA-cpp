#include<bits/stdc++.h>
#define pii pair<int,int>
#define INF 10000000
using namespace std;
vector<pii> adj[10001];
int n;
int dijkstra(int src,int dest)
{
  int dist[n+1];
  for(int i=0;i<n+1;i++)
    dist[i]=INF;
  priority_queue<pii,vector<pii>,greater<pii>> pq;
  pq.push({0,src});
  dist[src]=0;
  while(!pq.empty())
  {
    int x=pq.top().first;
    int y=pq.top().second;
    pq.pop();
    if(y==dest)
        return dist[dest];
    for(auto child: adj[y])
    {
       if(child.second+dist[y]<dist[child.first])
       {
         dist[child.first]=child.second+dist[y];
         pq.push({dist[child.first],child.first});
       }
    }
  }
  return dist[dest];
}

