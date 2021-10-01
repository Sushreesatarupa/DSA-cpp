#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define vec vector<int>
#define mp make_pair
#define inf 1e14
#define F first
#define S second
using namespace std;
vector<pii> adj[3005];
int d[3005],vis[3005];
int prims(int s,int n)
{
  for(int i=0;i<=n;i++)
    d[i]=inf; 
  d[s]=0;
  set<pii> q;
  q.insert({0,s});
  int wt=0,prev=0;
  while(!q.empty())
  {
    pii top=(*q.begin());
    q.erase(q.begin());
    int v=top.S;
    wt+=prev;
    vis[v]=1;
    for(auto it: adj[v]) 
    {
      int cost=it.S;
      int to=it.F; 
      if(!vis[to])
      {
        if(d[to]>cost)
        {
          q.erase({d[to],to});
          q.insert({cost,to});
          d[to]=cost;  
        }
      }
    }
    prev=top.F;
  }
  return wt+prev;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt=1;
  //cin>>tt;
  while(tt--)
  {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].pb({v,w});
      adj[v].pb({u,w});  
    }
    int s;
    cin>>s;
    cout<<prims(s,n);
  }
}

