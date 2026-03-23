#include<iostream>
#include<vector>


bool dfs(int u, std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int parent){
    visited[u]=true;

    for(int i : adj[u]){

        if(!visited[i]){
            if(dfs(i,adj,visited,u)) return false;
        }
        else if(i != parent){
            return true;
        }
    }

    return false;
}

bool isCyclic(std::vector<std::vector<int>>& adj){
    std::vector<bool>visited(adj.size(),false);

    for(int u=0;u<adj.size();u++){
        if(!visited[u]){
            if (dfs(u, adj, visited, -1)) return true;
        }
    }

    return false;
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

    std::cout<<std::boolalpha;
    std::cout<<isCyclic(adj);
} 
