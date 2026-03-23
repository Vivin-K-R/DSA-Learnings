#include<iostream>
#include<vector>
using namespace std;

vector<int> bellmanFord(int v,vector<vector<int>>& edges,int src){
    vector<int>dis(v,1e8);
    dis[src]=0;
    for(int i=0;i<v;i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dis[u] + wt < dis[v]){
                dis[v] = dis[u] + wt;
            }
        }
    }
    return dis;
}

int main() {
    
    // Number of vertices in the graph
    int V = 5;

    // Edge list representation: {source, destination, weight}
    vector<vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };

    // Define the source vertex
    int src = 0;

    // Run Bellman-Ford algorithm to get shortest paths from src
    vector<int> ans = bellmanFord(V, edges, src);

    // Output the shortest distances from src to all vertices
    for (int dist : ans) 
        cout << dist << " ";

    return 0; 
}
