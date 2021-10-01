#include <iostream>
#include<vector>
using namespace std;
#define MAX 9999
int print(int graph[50][50], int z) {
	for (int i = 0; i <= z; i++) {
		for (int j = 0; j <= z; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
int minVertex(vector<int>& dist, vector<bool>& mst, int n) {
	int mini = MAX;
	int v;
	for (int i = 0; i < n; i++) {
		if (mst[i] == false && dist[i] < mini) {
			v = i;
			mini = dist[i];
		}
	}
	return v;
}
int Dijktras(int graph[50][50], int n,int src) {
	vector<int>dist(n + 1, MAX);
	vector<bool>setmst(n + 1, false);
	vector<int>parent(n + 1);
	parent[src] = -1;
	dist[src] = 0;
	for (int i = 0; i <= n - 1; i++) {
		int m = minVertex(dist, setmst, n);
		setmst[m] = true;
		for (int j = 0; j <= n; j++) {
			if (setmst[j] == false && graph[m][j] != 0 && (dist[m]+graph[m][j]) < dist[j] && dist[m]!=MAX) {
				dist[j] = graph[m][j]+dist[m];
				parent[j] = m;
			}

		}
	}
	cout << "\nShortest pair from node: "<<src<<"\n\n";
	for (int i = 0; i <= n; i++) {
		if(parent[i]!=-1)
		cout << parent[i] << " -> " << i << " = " << graph[parent[i]][i] << "\n";
	}
	return 0;
}
int main()
{
	int graph[50][50], n, x, y, z = 0, u = 0, w, v = 0,src;
	memset(graph, 0, sizeof(graph));
	cout << "Enter number of paths: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Path , destination and weigth: ";
		cin >> x >> y >> w;
		graph[x][y] = w;
		graph[y][x] = w;
		z = max(z, x);
		u = max(u, y);
		v++;
	}
	cout << "Enter Source node: ";
	cin >> src;
	z = max(z, u);
	cout << "Adjacency matrix:\n\n";
	print(graph, z);
	Dijktras(graph, z,src);
	return 0;
}