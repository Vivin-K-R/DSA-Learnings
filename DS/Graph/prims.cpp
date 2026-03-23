#include<iostream>
#include<vector>
#include<queue>

int spanningTree(std::vector<std::vector<std::vector<int>>>& adj){

    std::priority_queue<
        std::pair<int,int>,
        std::vector<std::pair<int,int>>,
        std::greater<std::pair<int,int>>> pq;

    std::vector<bool> visited(adj.size(),false);

    int sum = 0;

    pq.push({0,0});

    while(!pq.empty()){

        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if(visited[node]) continue;

        visited[node] = true;

        sum += wt;

        for(auto &i : adj[node]){

            int adjNode = i[0];
            int edgeWeight = i[1];

            if(!visited[adjNode]){

                pq.push({edgeWeight,adjNode});
            }
        }
    }

    return sum;
}

int main(){

    int V = 3;

    std::vector<std::vector<std::vector<int>>> adj(V);

    adj[0].push_back({1,5});
    adj[1].push_back({0,5});

    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    adj[0].push_back({2,1});
    adj[2].push_back({0,1});

    std::cout<<spanningTree(adj);

    return 0;
}
