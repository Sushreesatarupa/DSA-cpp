#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u, v, w;
    edge(int a, int b, int c){
        u=a;v=b;w=c;
    }
};
bool sortbywt(struct edge a, struct edge b){
    return a.w < b.w;
}
int find(int u, vector<int> &parent){
    if(parent[u]==u)return u;
    return parent[u]=find(parent[u], parent);
}
void Union(int u, int v, vector<int> &rank, vector<int> &parent){
    int a = find(u, parent);
    int b = find(v, parent);
    
    if(rank[a]<rank[b]){
        parent[a]=b;
    }
    else if(rank[b]<rank[a]){
        parent[b]=a;
    }
    else {
        parent[b]=a;
        rank[a]++;
    }
}

int main(){
    int E,V;
    cin >> E >> V;
    
    vector<edge> edges;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back(edge(u,v,w));
    }
    vector<int> parent(V);
    vector<int> rank(V);
    for(int i=0;i<V;i++){
        parent[i]=i;
        rank[i]=0;
    }
    sort(edges.begin(), edges.end(), sortbywt);
    vector<edge> mst;
    int cost=0;
    for(edge x: edges){
        if(find(x.u, parent)!=find(x.v, parent)){
            mst.push_back(x);
            cost+=x.w;
            Union(x.u, x.v, rank, parent);
        }
    }
    cout <<"Minimum Spanning Tree:"<<endl;
    cout <<"Minimum cost: "<<cost<<endl;
    cout <<"V1 V2 WT:"<<endl;
    
    for(int i=0;i<mst.size();i++){
        cout <<mst[i].u<<" "<<mst[i].v<<" "<<mst[i].w<<endl;
    }
    return 0;
}