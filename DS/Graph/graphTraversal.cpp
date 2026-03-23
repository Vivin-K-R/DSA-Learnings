#include<iostream>
#include<vector>
#include<queue>

std::vector<int> BFS(std::vector<std::vector<int>>& adj){
    std::vector<bool>visited(adj.size(),false);
    std::queue<int>q;
    std::vector<int>res;

    visited[0] = true;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(auto it : adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return res;
}

void dfsHelper(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int v,std::vector<int>& res){
    visited[v]=true;
    res.push_back(v);

    for(int i : adj[v]){
        if(!visited[i]) dfsHelper(adj,visited,i,res);
    }

}
std::vector<int> DFS(std::vector<std::vector<int>>& adj){
    std::vector<bool>visited(adj.size(),false);
    std::vector<int>res;
    dfsHelper(adj,visited,0,res);

    return res;
}


void addEdge(std::vector<std::vector<int>>& adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int v = 5;
    std::vector<std::vector<int>>adj(v);

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    std::vector<int> res = BFS(adj);

    for(int i : res){
        std::cout<<i<<" ";
    }


}
