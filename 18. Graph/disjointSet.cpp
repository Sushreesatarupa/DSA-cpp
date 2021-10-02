// disjoin set
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    int *parent, *rank;

public:
    DisjointSet(int n /* no. of nodes*/)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
            parent[i] = i, rank[i] = 0;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    int makeUnion(int node1, int node2)
    {
        int parent2 = findParent(node2);
        int parent1 = findParent(node1);

        if (rank[parent1] > rank[parent2])
        {
            parent[parent2] = parent1;
        }
        else if (rank[parent1] < rank[parent2])
        {
            parent[parent1] = parent2;
        }
        else
        {
            rank[parent1]++;
            parent[parent2] = parent1;
        }
    }
};

int main() {
    DisjointSet ds(5);
    ds.makeUnion(0,4);
    ds.makeUnion(0,1);
    ds.makeUnion(2,3);
    
    cout<<ds.findParent(2)<<" "<<ds.findParent(4)<<endl;

    ds.makeUnion(1,3);
    cout<<ds.findParent(2);

}
