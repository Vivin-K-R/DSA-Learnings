#include<queue>
#include<iostream>
#include<vector>
using namespace std;

vector<int>dijkstra(vector<vector<pair<int,int>>>& adj,int src){

    vector<int>dist(adj.size(),1e9);

    priority_queue<pair<int,int>,
                  vector<pair<int,int>>,
                  greater<pair<int,int>>> pq;

    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto it : adj[u]){
            int n  = it.first;
            int wt = it.second;

            if(d+wt < dist[n]){
                dist[n] = d+wt;
                pq.push({dist[n],n});
            }
        }
    }

    return dist;
}

int main() {
    int src = 0;

    vector<vector<pair<int,int>>> adj(5);
    adj[0] = {{1,4}, {2,8}};
    adj[1] = {{0,4}, {4,6}, {2,3}};
    adj[2] = {{0,8}, {3,2}, {1,3}};
    adj[3] = {{2,2}, {4,10}};
    adj[4] = {{1,6}, {3,10}};

    vector<int> result = dijkstra(adj, src);

    for (int d : result)
        cout << d << " ";
    cout << " ";

    return 0;
}
