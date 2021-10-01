#include<bits/stdc++.h>
#define int long long int
#define INF 10000000000000
#define pii pair<int,int>
using namespace std;
vector<pair<int,int>> adj[100001];
vector<int> dist,path;
void dijkstra(int n)
{
  priority_queue<int> pq;
  pq.push(1);
  dist[1]=0;
  while(!pq.empty())
  {
    int node=pq.top();
    pq.pop();
    for(auto child: adj[node])
    {
      if(dist[node]+child.second<dist[child.first])
      {
        path[child.first]=node;
        dist[child.first]=dist[node]+child.second;
        pq.push(child.first);
      }
    }
  }
}
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
  }
  dist.assign(n+1,INF);
  path.assign(n+1,0);
  dijkstra(n);
  if(dist[n]==INF)
  {
    cout<<"-1\n";return 0;
  }
  vector<int> v;
  int x=n;
  v.push_back(n);
  while(x!=1)
  {
    x=path[x];
    v.push_back(x);
  }
  for(int i=v.size()-1;i>=0;i--)
    cout<<v[i]<<" ";
}
