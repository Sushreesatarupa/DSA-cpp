// we are taking sum of all the edges

#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define vec vector<int>
#define mp make_pair             // DISJOINT SET UNION(DSU)
#define inf 1e10
#define F first
#define S second
using namespace std;
int parent[300001],rak[300001];
void make_set(int v)     // making a new set
{
  parent[v]=v;
  rak[v]=0;
}
int find_set(int v)  // finding the leader of the set containing v
{
  if(parent[v]==v)
    return v;
  else
    return parent[v]=find_set(parent[v]);
}
void union_set(int u,int v)   // DOING UNION BY RANK
{
  u=find_set(u);  // finding leader of the set containing u
  v=find_set(v);  // finding leader of the set containing v
  if(u!=v)
  {
    if(rak[u]<rak[v])
        swap(u,v);
    parent[v]=u;
    if(rak[u]==rak[v])
        rak[u]++;
  }
}
bool comp(pair<int,pii> a,pair<int,pii> b)
{
  if(a.F<b.F)
        return true;
  else if(a.F==b.F && a.S.F+a.S.S<b.S.F+b.S.S)
    return true;
  return false;
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
    vector<pair<int,pii>> edge;
    for(int i=1;i<=n;i++)
        make_set(i);
    for(int i=0;i<m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      edge.pb({w,{u,v}});
    }
    sort(edge.begin(),edge.end(),comp);
    int ans=0;
    ans+=edge[0].F;
    union_set(edge[0].S.F,edge[0].S.S);
    for(int i=1;i<edge.size();i++)
    {
      int x=find_set(edge[i].S.F);
      int y=find_set(edge[i].S.S);
      if(x!=y)
      {
        union_set(edge[i].S.F,edge[i].S.S);
        ans+=edge[i].F;
      }
    }
    cout<<ans<<"\n";
  }
}
